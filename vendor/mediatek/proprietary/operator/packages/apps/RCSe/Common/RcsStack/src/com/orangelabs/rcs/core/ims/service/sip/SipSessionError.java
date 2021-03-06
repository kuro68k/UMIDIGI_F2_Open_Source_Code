/*******************************************************************************
 * Software Name : RCS IMS Stack
 *
 * Copyright (C) 2010-2016 Orange.
 * Copyright (C) 2015 Sony Mobile Communications Inc.
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
 *
 * NOTE: This file has been modified by Sony Mobile Communications Inc.
 * Modifications are licensed under the License.
 ******************************************************************************/

package com.orangelabs.rcs.core.ims.service.sip;

import com.orangelabs.rcs.core.ims.service.ImsServiceError;
import com.orangelabs.rcs.core.ims.service.ImsSessionBasedServiceError;


/**
 * SIP session error
 * 
 * @author jexa7410
 */
public class SipSessionError extends ImsSessionBasedServiceError {
    static final long serialVersionUID = 1L;

    /**
     * Media has failed (e.g. RTP or MSRP failure)
     */
    public final static int MEDIA_FAILED = SESSION_ERROR_CODES + 4;

    /**
     * Constructor
     * 
     * @param error Error
     */
    public SipSessionError(ImsServiceError error) {
        super(error.getErrorCode(), error.getMessage());
    }

    /**
     * Constructor
     * 
     * @param code Error code
     */
    public SipSessionError(int code) {
        super(code);
    }

    /**
     * Constructor
     * 
     * @param code Error code
     * @param msg Detail message
     */
    public SipSessionError(int code, String msg) {
        super(code, msg);
    }

    /**
     * Constructor
     * 
     * @param code Error code
     * @param cause the cause (which is saved for later retrieval by the Throwable.getCause()
     *            method). (A null value is permitted, and indicates that the cause is nonexistent
     *            or unknown.)
     */
    public SipSessionError(int code, Throwable cause) {
        super(code, cause);
    }
}
