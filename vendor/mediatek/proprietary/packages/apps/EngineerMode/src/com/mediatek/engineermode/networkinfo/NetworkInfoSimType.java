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
 * MediaTek Inc. (C) 2010. All rights reserved.
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

package com.mediatek.engineermode.networkinfo;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import com.mediatek.engineermode.ModemCategory;
import com.mediatek.engineermode.FeatureSupport;
import com.android.internal.telephony.PhoneConstants;
import com.mediatek.engineermode.R;

import java.util.ArrayList;

public class NetworkInfoSimType extends Activity implements OnItemClickListener {

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.dualtalk_networkinfo);
        ListView simTypeListView = (ListView) findViewById(R.id.ListView_dualtalk_networkinfo);

        ArrayList<String> items = new ArrayList<String>();
        items.add(getString(R.string.networkinfo_sim1));

        items.add(getString(R.string.networkinfo_sim2));

        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this,
                android.R.layout.simple_list_item_1, items);
        simTypeListView.setAdapter(adapter);
        simTypeListView.setOnItemClickListener(this);
    }

    /**
     * @see android.widget.AdapterView.OnItemClickListener#onItemClick(android.widget.AdapterView,
     *      android.view.View, int, long)
     * @param arg0
     *            the Adapter for parent
     * @param arg1
     *            the View to display
     * @param position
     *            the integer of item position
     * @param arg3
     *            the long of ignore
     */
    public void onItemClick(AdapterView<?> arg0, View arg1, int position, long arg3) {
        Intent intent = new Intent();
        int simType;
        switch (position) {
        case 0:
            if (FeatureSupport.is90Modem() || FeatureSupport.is3GOnlyModem()){
                intent.setClassName(this,
                        "com.mediatek.engineermode.networkinfo.NetworkInfo");
            }else{
                intent.setClassName(this,
                        "com.mediatek.engineermode.networkinfo.CdmaNetworkInfo");
            }
            simType = PhoneConstants.SIM_ID_1;
            intent.putExtra("mSimType", simType);

            break;
        case 1:
            if (FeatureSupport.is90Modem() || FeatureSupport.is3GOnlyModem()){
                intent.setClassName(this,
                        "com.mediatek.engineermode.networkinfo.NetworkInfo");
            }
            else{
                intent.setClassName(this,
                        "com.mediatek.engineermode.networkinfo.CdmaNetworkInfo");
            }
            simType = PhoneConstants.SIM_ID_2;
            intent.putExtra("mSimType", simType);
            break;
        default:
            break;
        }

        this.startActivity(intent);
    }
}
