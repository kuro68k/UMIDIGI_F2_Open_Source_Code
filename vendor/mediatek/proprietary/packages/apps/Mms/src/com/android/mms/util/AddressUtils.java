/*
* Copyright (C) 2014 MediaTek Inc.
* Modification based on code covered by the mentioned copyright
* and/or permission notice(s).
*/
/*
 * Copyright (C) 2008 Esmertec AG.
 * Copyright (C) 2008 The Android Open Source Project
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
package com.android.mms.util;

import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SqliteWrapper;
import android.net.Uri;
import android.provider.Telephony.Mms;
import android.provider.Telephony.Mms.Addr;
import android.text.TextUtils;
import android.util.Log;

import com.android.i18n.phonenumbers.PhoneNumberUtil;
import com.android.mms.MmsApp;
import com.android.mms.R;
import com.google.android.mms.pdu.EncodedStringValue;
import com.mediatek.android.mms.pdu.MtkPduHeaders;
import com.mediatek.android.mms.pdu.MtkPduPersister;

public class AddressUtils {
    private static final String TAG = "AddressUtils";
    private static PhoneNumberUtil mPhoneNumberUtil;

    private AddressUtils() {
        // Forbidden being instantiated.
    }

    public static String getFrom(Context context, Uri uri) {
        String msgId = uri.getLastPathSegment();
        Uri.Builder builder = Mms.CONTENT_URI.buildUpon();

        builder.appendPath(msgId).appendPath("addr");

        Cursor cursor = SqliteWrapper.query(context, context.getContentResolver(),
                            builder.build(), new String[] {Addr.ADDRESS, Addr.CHARSET},
                            Addr.TYPE + "=" + MtkPduHeaders.FROM, null, null);

        if (cursor != null) {
            try {
                if (cursor.moveToFirst()) {
                    String from = cursor.getString(0);

                    if (!TextUtils.isEmpty(from)) {
                        byte[] bytes = MtkPduPersister.getBytes(from);
                        int charset = cursor.getInt(1);
                        return new EncodedStringValue(charset, bytes)
                                .getString();
                    } else { /// M: @{
                        Log.d(TAG, "getFrom EncodedStringValue1 is null");
                    }
                    /// @}
                }
            } finally {
                cursor.close();
            }
        }
        /// M: @{
        Log.d(TAG, "getFrom EncodedStringValue2 is null");
        /// @}
        return context.getString(R.string.hidden_sender_address);
    }

    /** google jb.mr1 patch
     * isPossiblePhoneNumberCanDoFileAccess does a more accurate test if the input is a
     * phone number, but it can do file access to load country prefixes and other info, so
     * it's not safe to call from the UI thread.
     * @param query the phone number to test
     * @return true if query looks like a valid phone number
     */
    public static boolean isPossiblePhoneNumberCanDoFileAccess(String query) {
        String currentCountry = MmsApp.getApplication().getCurrentCountryIso().toUpperCase();
        if (mPhoneNumberUtil == null) {
            mPhoneNumberUtil = PhoneNumberUtil.getInstance();
        }
        return mPhoneNumberUtil.isPossibleNumber(query, currentCountry);
    }

}
