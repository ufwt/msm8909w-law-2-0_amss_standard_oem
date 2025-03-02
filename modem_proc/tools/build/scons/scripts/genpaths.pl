#! perl
#
#=============================================================================
#
# AMSS incpaths.min include path generator for CoreBSP standalone build
#
# Description: 
# Create list of include paths from AMSS, external dependancies, needed
# to build CoreBSP standalone. Creates importable file of path definitions
# used by scons build system for external paths.
#   
# Copyright (c) 2009-2009 by Qualcomm Technologies, Incorporated.
# All Rights Reserved.
# QUALCOMM Proprietary/GTDR
#=============================================================================
#
#  $Header: //commercial/MPSS.JO.2.0.c1.4/Main/modem_proc/tools/build/scons/scripts/genpaths.pl#1 $
#  $DateTime: 2016/12/13 07:57:53 $
#  $Author: mplcsds1 $
#  $Change: 11985114 $
#                      EDIT HISTORY FOR FILE
#                      
#  This section contains comments describing changes made to the module.
#  Notice that changes are listed in reverse chronological order.
#  
# when       who     what, where, why
# --------   ---     ---------------------------------------------------------
# 05/04/09   cjb     Created
#
#=============================================================================

use strict;
use Getopt::Long;
use File::Spec;
use Env;
use Cwd;

use Env qw( @PATH );

my $minfile;
my $buildid;
my $makeflags;
my $usage;

sub genpaths($$$); 
sub fileToArray($);
sub checkArgs;
sub Usage();
sub main();

#run
main();

sub main()
{
   my %minfile;
   my %buildid;
   my %makeflags;

   checkArgs();

   genpaths($minfile,$buildid,$makeflags);
   exit(0);
}

sub checkArgs 
{
   GetOptions(
      "min=s"=>\$minfile,           # Min file to parse
      "buildid=s"=>\$buildid,       # buildid file to parse
      "makeflags=s"=>\$makeflags,   # makeflags passed in to parse
   );

   Usage() if $usage;
   if(!$minfile)
   {
      print "Missing required pararmeter -min <minfile>\n";
      Usage();
   }
   if(!$buildid)
   {
      print "Missing required pararmeter -buildid <buildid>\n";
      Usage();
   }
}

sub isWindoze() { 
   return $^O =~ /Win32/; 
}

sub add_paths(@)
{
   my @paths = @_;
   my $dir_sep = isWindoze() ? "\\" : "/";
   unshift @PATH, map{ s/[\/\\]+/${dir_sep}/go; $_ } @paths;
}

sub genusesflags($$) {
   my $buildid = shift(@_);
   my $mflags = shift(@_);
   
   my @filearr;
   my $makeCmd;
   my $oldpath;
   
	print "# USES Generation\n";
	
   if ($mflags) {
      print "# MFLAGS: " .$mflags. "\n";
	   @filearr = split(/ /, $mflags);
   } else {
      if ($^O eq "linux") {
         $makeCmd = 'sh linux_build '.$buildid. ' -m corebsp_uses -m -p';
      } else {
         if (-e '../../core/bsp/tools/incgen/make.exe') {
				 $oldpath = $ENV{PATH};
             add_paths("../../core/bsp/tools/incgen");
         } 
         $makeCmd = 'build.cmd '.$buildid. ' -m corebsp_uses -m -p';
      }
      @filearr = fileToArray($makeCmd);
      if ($^O eq "linux") {
      } else {
		   if (-e '../../core/bsp/tools/incgen/make.exe') {
			   $ENV{PATH} = $oldpath;
         }
      }
   }
   my $foundLine = 0;

   my @parts;
   my $varname;
   my $varvalue;
   my $usesflags;
   
   foreach my $line (@filearr)
   {
      #remove any preceding whitespace
      $line =~ s/^\s+//;
      if ($line =~ /^USES_/)
      {
         $line =~ s/\(/{/g;
         $line =~ s/\)/}/g;
         $line =~ s/\n//g;
         $line =~ s/\r//g;
         $line =~ s/:=/=/g;
         $line =~ s/\?=/=/g;
         
         @parts = split(/=/, $line);
         $varname = $parts[0];
         $varvalue = $parts[1];

         # cleanup varname
         $varname =~ s/^\s+//;
         $varname =~ s/export//g;
         $varname =~ s/EXPORT//g;
         $varname =~ s/define//g;
         $varname =~ s/\s//g;
         $varname =~ s/\n//g;
         $varname =~ s/\r//g;
         $varvalue =~ s/^\s+//;
         
         $usesflags .= " " .$varname ."=". $varvalue;
      }
   }

	print "# ==================================\n\n";
	
   return $usesflags;
}

sub genpaths($$$) {
   my $filename = shift(@_);
   my $build = shift(@_);
   my $mflags = shift(@_);

   my @filearr;
   my $usesflags;
   my $cygwinmake;
	my $makeCmd;
	my $oldpath;

   print "# Autogenerated file\n";

   $usesflags = genusesflags($buildid,$mflags);

   $usesflags =~ s/\n//g;
   $usesflags =~ s/\r//g;
   print "# Uses flags: " .$usesflags. "\n";
	
	# we need to ensure we use gnumake to run this step
	# this script has to be run from build/ms
	
   if ($^O eq "linux") {
   } else {	
	   if (-e '../../core/bsp/tools/incgen/make.exe') {
         $oldpath = $ENV{PATH};
         add_paths("../../core/bsp/tools/incgen");
         #$ENV{PATH} = '../../core/bsp/tools/incgen\;' .$ENV{PATH}. '\;';
	   } 
   }
   print "# Path: " .$ENV{PATH}. "\n";

	$makeCmd = 'make -f '.$filename. ' '. $usesflags .' . -p';
   print "# Command: " .$makeCmd. "\n";
   print "\n";
   
   my @filearr = fileToArray($makeCmd);
   if ($^O eq "linux") {
   } else {
      if (-e '../../core/bsp/tools/incgen/make.exe') {
	      $ENV{PATH} = $oldpath;
      }
	}  
   my $foundLine = 0;

   my @parts;
   my $varname;
   my $varvalue;

   print "def exists(env):\n";
   print "   return env.Detect('usesflags')\n";
   print "\n";
   print "def generate(env):\n";
   
   foreach my $line (@filearr)
   {
      #remove any preceding whitespace
      $line =~ s/^\s+//;
      if ($foundLine)
      {
         $line =~ s/\(/{/g;
         $line =~ s/\)/}/g;
         $line =~ s/\n//g;
         $line =~ s/:=/=/g;
         $line =~ s/\?=/=/g;
         
         @parts = split(/=/, $line);
         $varname = $parts[0];
         $varvalue = $parts[1];

         # cleanup varname
         $varname =~ s/^\s+//;
         $varname =~ s/export//g;
         $varname =~ s/EXPORT//g;
         $varname =~ s/define//g;
         $varname =~ s/\s//g;
         
         # cleanup varvalue
         $varvalue =~ s/^\s+//;
         
         
         $foundLine = 0;
			if ($varname =~ /^SRCROOT/)
			{
				next;
			}
			if ($varname =~ /^ROOT/)
			{
				next;
			}
         if ($varname =~ m/^[0-9]/)
         {
            # python variable can not start with a number
            print "   env.Replace(V_" .$varname ." = \"". $varvalue. "\")\n";
         } else {
            print "   env.Replace(" .$varname ." = \"". $varvalue. "\")\n";
         }
      }
      if ($line =~ /^# makefile \(from/)
      {
         $foundLine = 1;
      }
   }
   return;
}

sub fileToArray($)
{
   my $cmd = shift(@_);
   open IN, "$cmd|" || die "failed executing $cmd";
   my @arr = <IN>;
   close IN;
   return @arr;
}

sub trim($)
{
   my $str = shift(@_);
   $str =~ s/^\s+//s;
   $str =~ s/\s+$//s;
   return $str;
}

sub Usage()
{
   my $usage = <<END;
Usage: perl genpaths.pl -min <minfilename> -buildid <buildid>

Example:
cd build/ms
perl genpaths.pl -min incpaths.min -buildid SCTUUS > ../../core/bsp/build/data/incpathssctuus.py
END

   print $usage;
   exit;
}
