#===============================================================================
#
# Copyright (c) 2014 Qualcomm Technologies, Inc. All Rights Reserved.
# Qualcomm Technologies Proprietary and Confidential.
#
#===============================================================================

"""
Created on May 29, 2014

@author: forrestm

Code for everything DataProvisioning related.

This module is meant to ease file management for its clients (everything under sectools is a potential client).
The general concept is a three tier directory system underneath some base path (specified in the config.xml).
The first tier specifies the Security Policy (Encryption, Signing, Validation, etc). The second specifies the
Security Policy Type (SSD, unified, CASS). The third level specifies the chipset name.

When you need your data, just do the following::

    data_prov = DataProvisioner()
    data = data_prov.query('Encryption','Unified','8994')
    data[0].files['l1.key']
    data[0].files['l2.key']
    data[0].files['l3.key']

Meta data files are a very easy feature to use. Their output can be found in the 'config' attribute of
ExternalDataProvObjects (which is what the query method returns). The structure is very similar to what
generateDS output. The structure is as follows:

<METACONFIG>
    <Tag1>value</Tag1>
    <Tag2>
        <Tag3>value3</Tag3>
    </Tag2>
    ...
</METACONFIG>

There may only be one root tag and it MUST be <METACONFIG>.

"""

import os
import pickle
import difflib
from collections import namedtuple
import xmltodict

from sectools.common.utils import c_path
from sectools.common.utils.c_logging import logger

# database handling defines
FILE_INTERFACE_STR = 'file_interface'
DATABASE_STR = 'database'
SECURITY_POLICY_STR = 'security_policy'
SECURITY_POLICY_TYPE_STR = 'security_policy_type'
DATA_PROV_ID_STR = 'data_prov_id'
BINARY_FILE_STR = 'binary_file'

_ExternalDataProvObject = namedtuple('ExternalDataProvObject', 'security_policy security_policy_type data_prov_id files config source path')

class ExternalDataProvObject(_ExternalDataProvObject):
    '''object returned by DataProvisioner.query. Has the following fields:
    security_policy - str
    security_policy_type - str
    data_prov_id - str
    config - object
    files - list(str)
    source - str
    path - str
    '''
    def __repr__(self):
        ret = ''
        ret += "{0}/{1}/{2} retrieved from {3}\n".format(self.security_policy, self.security_policy_type, self.data_prov_id, self.source)
        ret += "Files: {0}\n".format(repr(self.files))
        ret += "Path: {0}\n".format(self.path)
        return ret

DATA_PROV_LEVELS = [DATABASE_STR, SECURITY_POLICY_STR, SECURITY_POLICY_TYPE_STR, DATA_PROV_ID_STR, BINARY_FILE_STR]

def level_num_to_name(level):
    if level > len(DATA_PROV_LEVELS) or level < 0:
        raise RuntimeError("DataProvisioner: converting a bad level number")
    return DATA_PROV_LEVELS[level]



class DataProvisioner():
    '''DataProvisioning for binary files (certs,keys,etc) needed by different security policies'''

    # used for sharing state for Borg (singleton) pattern
    __shared_state = {}

    def __init__(self, data_prov_base=None):
        '''DataProvisioner constructor. DataProvisioner is a singleton. Takes parameter only when
        initializing the DataProvisioning database

        :param data_prov_base: path to the base folder system where all data provisioning files are
        :type data_prov_base: str
        '''

        self.__dict__ = self.__shared_state
        if data_prov_base is not None:
            # TODO: handle other sources (backend) here, decide how we should merge/handle the resulting databases
            handler = FileInterfaceHandler()
            self.database = handler.handle_recursive(c_path.join(data_prov_base, ''))
            self.verify()


    def _validate_query(self, security_policy, security_policy_type, data_prov_id):
        '''Validates the query to make sure the given params are in the database. Returns True
        if the query is valid, an error string otherwise. Should only be called internally.
        '''

        if security_policy is None:
            return True
        current_obj = self.database
        if security_policy not in current_obj.children.keys():
            return self._fuzzy_match(security_policy)

        if security_policy_type is None:
            return True
        current_obj = current_obj.children[security_policy]
        if security_policy_type not in current_obj.children.keys():
            return self._fuzzy_match(security_policy, security_policy_type)

        if data_prov_id is None:
            return True
        current_obj = current_obj.children[security_policy_type]
        if data_prov_id not in current_obj.children.keys():
            return self._fuzzy_match(security_policy, security_policy_type, data_prov_id)

        return True

    def _fuzzy_match(self, security_policy, security_policy_type=None, data_prov_id=None):
        ''' fuzzy match search term to try and suggest to the user the correct term. If not matches
        are found, then format a generic error string and return it. Should only be called by the validator.
        '''

        close_matches = None
        level = ''
        search_term = ''
        if data_prov_id is not None:
            possible_matches = self.database.children[security_policy].children[security_policy_type].children.keys()
            close_matches = difflib.get_close_matches(data_prov_id, possible_matches)
            level = DATA_PROV_ID_STR
            search_term = data_prov_id

        elif security_policy_type is not None:
            possible_matches = self.database.children[security_policy].children.keys()
            close_matches = difflib.get_close_matches(security_policy_type, possible_matches)
            level = SECURITY_POLICY_TYPE_STR
            search_term = security_policy_type

        elif security_policy is not None:
            possible_matches = self.database.children.keys()
            close_matches = difflib.get_close_matches(security_policy, possible_matches)
            level = SECURITY_POLICY_STR
            search_term = security_policy

        else:
            raise RuntimeError("fuzzy_match must be called with at least 1 actual parameter")

        ret_str = "DataProvisioner: query term {0} for {1} is not in the DataProvisioner database. ".format(search_term, level)
        if len(close_matches) > 0:
            ret_str += "Did you mean any of the following? {0} ".format(close_matches)

        return ret_str


    def query(self, security_policy=None, security_policy_type=None, data_prov_id=None):
        '''searches and returns the corresponding data object for the given search parameters.
        supports wildcard parameters by passing None as the wildcard parameter. Does not allow for
        more specific parameters to be specified if any less specific parameters are wildcard. For
        example::
            query("encryption",None,None)
        is valid::

            query("encryption",None,"8994")
        is not.

        Returns a list of corresponding ExternalDataProvObjects. The resulting ExternalDataProvObjects will
        vary in at least one of the four fields (security_policy, security_policy_type, data_prov_id, source).
        For 3 param queries the only field that will vary is source. Until multiple sources is implemented,
        3 param queries will always return a list of size one

        :param security_policy: the security policy to search for
        :type security_policy: str / None (for wildcards)
        :param security_policy_type: the security policy type to search for
        :type security_policy_type: str / None (for wildcards)
        :param data_prov_id: the data prov id to search for
        :type data_prov_id: str / None (for wildcards)
        :rtype: list(ExternalDataProvObject)
        :raises: KeyError,RuntimeError
        '''

        ret = self._validate_query(security_policy, security_policy_type, data_prov_id)
        if ret is not True:
            raise KeyError(ret)

        result_list = []

        if security_policy is None:
            for param in (security_policy_type, data_prov_id):
                if param is not None:
                    raise RuntimeError("DataProvisioner: {0} is not a wildcard, whereas security_policy is".format(param))
            for lvl1_name, lvl1_obj in self.database.children.items():
                for lvl2_name, lvl2_obj in lvl1_obj.children.items():
                    for lvl3_name, lvl3_obj in lvl2_obj.children.items():
                        result_list.append(lvl3_obj.to_external_representation(lvl1_name, lvl2_name, lvl3_name, FILE_INTERFACE_STR))

        elif security_policy_type is None:
            if data_prov_id is not None:
                raise RuntimeError("DataProvisioner: data_prov_id is not a wildcard, whereas security_policy is")
            lvl1_obj = self.database.children[security_policy]
            for lvl2_name, lvl2_obj in lvl1_obj.children.items():
                for lvl3_name, lvl3_obj in lvl2_obj.children.items():
                    result_list.append(lvl3_obj.to_external_representation(security_policy, lvl2_name, lvl3_name, FILE_INTERFACE_STR))

        elif data_prov_id is None:
            lvl2_obj = self.database.children[security_policy].children[security_policy_type]
            for lvl3_name, lvl3_obj in lvl2_obj.children.items():
                result_list.append(lvl3_obj.to_external_representation(security_policy, security_policy_type, lvl3_name, FILE_INTERFACE_STR))

        else:
            lvl3_obj = self.database.children[security_policy].children[security_policy_type].children[data_prov_id]
            result_list.append(lvl3_obj.to_external_representation(security_policy, security_policy_type, data_prov_id, FILE_INTERFACE_STR))

        # TODO: in the future, this is where we would get data from a different source (backend/server/whatever) and tack
        # the entries on to result_list

        return result_list

    def verify(self):
        '''verifies self.database is correct. Checks for type/bin file mismatch. bin files not
           in level 3. Lack of binfiles. Too many binfiles. Etc.Some things are implicitly verified
           by the file handler, like existence of files/folders and correct paths, since it
           can't create the database with bad paths

           :raises: RuntimeError
           '''

        if len(self.database.files) > 0:
            raise RuntimeError("DataProvisioner:  binary files {0} exist within security_policy level of Data Provisioning file structure").format(self.database.files)
        for lvl1_name, lvl1_obj in self.database.children.items():

            if len(lvl1_obj.files) > 0 :
                raise RuntimeError("DataProvisioner:  binary files {0} exists within security_policy_type level of Data Provisioning file structure").format(lvl1_obj.files)

            for lvl2_name, lvl2_obj in lvl1_obj.children.items():

                if len(lvl2_obj.files) > 0 :
                    raise RuntimeError("DataProvisioner:  binary files {0} exists within data_prov_id level of Data Provisioning file structure").format(lvl2_obj.files)

                for lvl3_name, lvl3_obj in lvl2_obj.children.items():

                    if len(lvl3_obj.files) == 0:
                        raise RuntimeError("DataProvisioner:  there are no binary files in data_prov_id of Data Provisioning file structure. {0}".format(lvl3_obj.path))

                    for file_name in lvl3_obj.files:
                        if c_path.validate_dir(file_name):
                            raise RuntimeError("DataProvisioner:  Directories are not allowed within the data_prov_id directory of the Data Provisioning file structure")

        logger.debug("DataProvisioner database verification passed")
        return True

    def dump_database(self):
        """pretty print the database that DataProvisioner holds"""
        self.database.dumpRecursive()

    # Database serialization is useful for debugging and testing purposes only
    def _pickle(self, dump_path):
        dump = open(dump_path, "wb+")
        pickle.dump(self.database, dump)

    def _unpickle(self, dump_path):
        dump = open(dump_path, "rb")
        return pickle.load(dump)

    def _pickles(self):
        return pickle.dumps(self.database)

    def _unpickles(self, pickle_data):
        return pickle.loads(pickle_data)

    def _unpickle_and_update_database(self, dump_path):
        self.database = self._unpickle(dump_path)
        return self.database

    def _unpickles_and_update_database(self, pickle_data):
        self.database = self._unpickles(pickle_data)
        return self.database

class DataProvObject():
    '''A data provisioning object that corresponds to a certain folder within the data provisioning directory structure'''


    def __init__(self, id, path):
        ''' DataProvObject constructor
        :param id: the ID of this DataProvObject. Normally the last folder in the path
        :type id: str
        :param path: absolute path to the directory this data prov object corresponds to
        :type path: str
        '''

        self.id = id
        self.path = path
        self.files = {}
        self.children = {}
        self.config = {}
    def compare_to(self, other):
        ''' compares this DataProvObject to a different DataProvObject. Ignores children
        returns True if id,path,params,and files are the same
        False otherwise

        :param other: the DataProvObject to be compared against
        :type other: DataProvObject
        :rtype: bool
        '''

        if self.id != other.id:
            return False
        if self.path != other.path:
            return False
        if self.files != other.files:
            return False
        if self.config != other.config:
            return False
        return True

    def compare_to_recursively(self, other):
        ''' compares this DataProvObject to another DataProvObject and compares all corresponding children
        True only if self and all descendants of self are equal to other and all descendants of other
        False otherwise

        :param other: the DataProvObject to be compared against
        :type other: DataProvObject
        :rtype: bool
        '''

        if self.compare_to(other) == False:
            return False
        if len(self.children) != len(other.children):
            return False
        for key in self.children.keys():
            if key not in other.children.keys():
                return False
            if self.children[key].compare_to_recursively(other.children[key]) == False:
                return False
        return True

    def dump_recursive(self):
        """ dumps a pretty printed version of the object and it's children. Returns formatted string

        :rtype: str
        """

        self.__ret_str = ''
        def dump_data_prov_object_and_children(data_prov_object, prefix=''):
            self.__ret_str += prefix + repr(data_prov_object) + "\n"
            if data_prov_object.children is None:
                return
            else:
                for key in data_prov_object.children.keys():
                    dump_data_prov_object_and_children(data_prov_object.children[key], prefix + '\t')

        dump_data_prov_object_and_children(self)
        return self.__ret_str

    def to_external_representation(self, security_policy, security_policy_type, data_prov_id, source):
        ''' converts the dataprov object to the external representation. Used only by the query method'''
        return ExternalDataProvObject(security_policy, security_policy_type, data_prov_id, self.files, self.config, source, self.path)

    def print_recursive(self):
        ''' prints database dump gotten from dumpRecursive'''
        print self.dumpRecursive()

    def __repr__(self):
        ret = "id: {0} ".format(self.id)
        if self.files is not None:
            if len(self.files) > 0:
                ret += "files: {0} ".format(self.files)
        ret += "path: {0} ".format(self.path)
        return ret

class FileInterfaceHandler():
    ''' discovers all data provisioning information and turns it into a database for DataProvisioning to use'''

    def __handle_recursive(self, data_prov_object, level, path):
        if level == 4:
            for item in os.listdir(path):
                if item.endswith(".xml"):
                    data_prov_object.config = self.handle_meta_config(c_path.join(path, item))
                elif c_path.validate_dir(c_path.join(path, item)):
                    raise RuntimeError("DataProvisioner:  found directory {0} in binary_file level of DataProvisioner. \
                    Directories are not allowed in the binary_file level".format(item))
                else:
                    try:
                        with open(c_path.join(path, item), "r") as data_file:
                            data_prov_object.files[item] = data_file.read()
                    except:
                        raise RuntimeError("DataProvisioner:  Can't open {0}".format(c_path.join(path, item)))
            return

        for item in os.listdir(path):
            if item.endswith(".xml"):
                pass  # configs at not the 4th level arent supported
                data_prov_object.config = self.handle_meta_config(c_path.join(path, item))
            elif c_path.validate_dir(c_path.join(path, item)) == False:
                raise RuntimeError("DataProvisioner:  found binary file {0} in level {1} of DataProvisioner. \
                Binary files are only allowed at the binary_file level".format(item, level_num_to_name(level)))
            child_data_prov_object = DataProvObject(item, c_path.join(path, item))
            data_prov_object.children[item] = child_data_prov_object
            self.__handle_recursive(child_data_prov_object, level + 1, c_path.join(path, item))

    def handle_recursive(self, data_prov_base):
        ''' Handles database creation and data discovery. Should only be called by the DataProvisioning constructor.
        Creates the database recursively, to facilitate for expansion later on if we add levels.

        :param data_prov_base: path to the base folder for the data provisioning directory structure
        :type data_prov_base: str
        :rtype: DataProvObject
        :raises: RuntimeError
        '''

        self.database = DataProvObject(DATABASE_STR, c_path.join(data_prov_base, ''))
        self.__handle_recursive(self.database, 1, data_prov_base)
        return self.database


    def handle_meta_config(self, PathToMetaConfigFile):
        ''' opens the meta config file, parses it using xml to dict, then converts the dict
        into a python object.
        '''

        conf_file = open(PathToMetaConfigFile, 'r')
        out_dict = xmltodict.parse(conf_file.read())
        config = DictToObject(out_dict)
        return config


class DictToObject:
    ''' class that converts a dictionary into a python object. Should only ever be called
    by the meta config handler.'''
    def wrap_recursive_data(self, value):
        if isinstance(value, (set, tuple, list)):
            return type(value)([self.wrap_recursive_data(val) for val in value])
        else:
            if isinstance(value, dict):
                return DictToObject(value)
            else:
                return value

    def __init__(self, data):
        for key, value in data.items():
            setattr(self, key, self.wrap_recursive_data(value))
            obj = getattr(self, key)
            if isinstance(obj, DictToObject):
                self.value = obj

def objwalk(parent_object, object, tab=''):
    ''' used to recursively traverse a python data structure created with DictToObject and pretty print it.
    Should only ever be called when debugging meta config objects.'''
    for var in vars(object):
        obj = getattr(object, var)
        print "{0}{1}: {2} ".format(tab, var, obj.__class__.__name__)
        if isinstance(obj, DictToObject):
            objwalk(object, obj, tab + '\t')
        elif isinstance(obj, list):
            for l in obj:
                print "{0}[".format(tab)
                objwalk(object, l, tab + '\t')
                print "{0}]".format(tab)
