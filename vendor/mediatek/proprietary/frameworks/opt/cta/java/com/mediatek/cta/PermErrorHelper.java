/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 *
 * MediaTek Inc. (C) 2017. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */

package com.mediatek.cta;

import android.content.Context;
import android.content.pm.PackageManager.NameNotFoundException;
import android.content.pm.PermissionInfo;
import android.text.TextUtils;
import android.util.Log;

final class PermErrorHelper {

    private static final String TAG = "PermErrorHelper";
    private static PermErrorHelper sInstance;
    private Context mContext;

    private static final String PATTERN_SECURITY_EXCEPTION = "SecurityException";
    private static final String PATTERN_PERMISSION_DENIAL = "Permission Denial";
    private static final String PATTERN_REQUIRES = " requires ";
    private static final String PATTERN_OR = " or ";

    static PermErrorHelper getInstance(Context context) {
        if (sInstance == null) {
            sInstance = new PermErrorHelper(context);
        }
        return sInstance;
    }

    private PermErrorHelper(Context context) {
        mContext = context;
    }

    String parsePermName(final int uid, final String packageName,
            final String exceptionMsg) {
        if (CtaPermsController.DEBUG) {
            Log.d(TAG, "parsePermName uid = " + uid + ", packageName = " +
                    packageName + ", exceptionMsg = " + exceptionMsg);
        }
        if (!CtaUtils.isCtaSupported()) {
            return null;
        }
        if (TextUtils.isEmpty(exceptionMsg)) {
            return null;
        }
        if (!exceptionMsg.contains(PATTERN_SECURITY_EXCEPTION) ||
                !exceptionMsg.contains(PATTERN_PERMISSION_DENIAL)) {
            return null;
        }

        int startIndex = exceptionMsg.indexOf(PATTERN_REQUIRES) +
                PATTERN_REQUIRES.length();
        String parseResult = exceptionMsg.substring(startIndex, exceptionMsg.length());
        String permName = "";
        if (parseResult.contains(PATTERN_OR)) {
            startIndex = parseResult.indexOf(PATTERN_OR) + PATTERN_OR.length();
            parseResult = parseResult.substring(startIndex, parseResult.length());
        }
        parseResult = parseResult.trim();
        if (CtaPermsController.DEBUG) {
            Log.d(TAG, "initMtkPermErrorDialog() parseResult = " + parseResult);
        }

        try {
            PermissionInfo info = mContext.getPackageManager().getPermissionInfo(parseResult, 0);
            if (info.protectionLevel == PermissionInfo.PROTECTION_DANGEROUS
                    && CtaUtils.isPlatformPermission(info.packageName, info.name)) {
                permName = info.name;
            } else if (info.protectionLevel ==
                (PermissionInfo.PROTECTION_SIGNATURE | PermissionInfo.PROTECTION_FLAG_PRIVILEGED)
                    && CtaUtils.isCtaOnlyPermission(info.name)) {
                permName = info.name;
            }
        } catch (NameNotFoundException e) {
            permName = "";
        }
        return permName;
    }
}
