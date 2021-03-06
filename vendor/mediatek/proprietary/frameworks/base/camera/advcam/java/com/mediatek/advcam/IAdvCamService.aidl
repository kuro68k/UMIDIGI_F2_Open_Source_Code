/*
 * Copyright (C) 2017 The Android Open Source Project
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

package com.mediatek.advcam;

import android.hardware.camera2.CaptureRequest;

/** @hide */
interface IAdvCamService
{
    /**
     * Keep up-to-date with vendor/mediatek/proprietary/frameworks/av/include/advcam/IAdvCamService.h
     * In Camera API2, app can not createCaptureSession with additional parameters, so that camera hal
     * may waste time to re-config after 1st request received.
     * App can send 1st request by this api before calling createCaptureSession related API.
     * Benefits :
     * (a) reduce time between camera hal receive 1st request and 1st frame output to display.
     * (b) camera hal can enable special turnkey feature by this api.
     */

    int setConfigureParam(int openId, in CaptureRequest request);
}
