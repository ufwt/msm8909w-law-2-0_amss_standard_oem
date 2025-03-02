/**
 * Copyright (c) 2016 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 * Not a Contribution.
 * Apache license notifications and license are retained
 * for attribution purposes only.
 */

/*
 * Copyright (C) 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.qualcomm.qti.watchsettings.sound.search;

import android.content.Context;
import android.provider.SearchIndexableResource;

import java.util.Collections;
import java.util.List;

/**
 * A basic SearchIndexProvider that returns no data to index.
 */
public class SoundBaseSearchIndexProvider { 

    private static final List<String> EMPTY_LIST = Collections.<String>emptyList();

    public SoundBaseSearchIndexProvider() {
    }

}
