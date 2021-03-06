/*
 * Copyright (C) 2015 The Android Open Source Project
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
 * limitations under the License
 */

package com.android.server.telecom;


import android.app.ActivityManager;
import android.bluetooth.BluetoothDevice;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.UserInfo;
import android.media.AudioDeviceInfo;
import android.media.AudioManager;
import android.media.IAudioService;
import android.os.Binder;
import android.os.Message;
import android.os.RemoteException;
import android.os.UserHandle;
import android.telecom.CallAudioState;
/// M: Using mtk log instead of AOSP log.
// import android.telecom.Log;
import android.telecom.Logging.Session;
import android.util.SparseArray;

import com.android.internal.annotations.VisibleForTesting;
import com.android.internal.os.SomeArgs;
import com.android.internal.util.IState;
import com.android.internal.util.IndentingPrintWriter;
import com.android.internal.util.State;
import com.android.internal.util.StateMachine;
import com.android.server.telecom.bluetooth.BluetoothRouteManager;

/// M: Mediatek import.
import com.mediatek.server.telecom.Log;

import java.util.Collection;
import java.util.HashMap;
import java.util.Objects;

/**
 * This class describes the available routes of a call as a state machine.
 * Transitions are caused solely by the commands sent as messages. Possible values for msg.what
 * are defined as event constants in this file.
 *
 * The eight states are all instances of the abstract base class, {@link AudioState}. Each state
 * is a combination of one of the four audio routes (earpiece, wired headset, bluetooth, and
 * speakerphone) and audio focus status (active or quiescent).
 *
 * Messages are processed first by the processMessage method in the base class, AudioState.
 * Any messages not completely handled by AudioState are further processed by the same method in
 * the route-specific abstract classes: {@link EarpieceRoute}, {@link HeadsetRoute},
 * {@link BluetoothRoute}, and {@link SpeakerRoute}. Finally, messages that are not handled at
 * this level are then processed by the classes corresponding to the state instances themselves.
 *
 * There are several variables carrying additional state. These include:
 * mAvailableRoutes: A bitmask describing which audio routes are available
 * mWasOnSpeaker: A boolean indicating whether we should switch to speakerphone after disconnecting
 *     from a wired headset
 * mIsMuted: a boolean indicating whether the audio is muted
 */
public class CallAudioRouteStateMachine extends StateMachine {

    public static class Factory {
        public CallAudioRouteStateMachine create(
                Context context,
                CallsManager callsManager,
                BluetoothRouteManager bluetoothManager,
                WiredHeadsetManager wiredHeadsetManager,
                StatusBarNotifier statusBarNotifier,
                CallAudioManager.AudioServiceFactory audioServiceFactory,
                int earpieceControl) {
            return new CallAudioRouteStateMachine(context,
                    callsManager,
                    bluetoothManager,
                    wiredHeadsetManager,
                    statusBarNotifier,
                    audioServiceFactory,
                    earpieceControl);
        }
    }
    /** Values for CallAudioRouteStateMachine constructor's earPieceRouting arg. */
    public static final int EARPIECE_FORCE_DISABLED = 0;
    public static final int EARPIECE_FORCE_ENABLED  = 1;
    public static final int EARPIECE_AUTO_DETECT    = 2;

    /** Direct the audio stream through the device's earpiece. */
    public static final int ROUTE_EARPIECE      = CallAudioState.ROUTE_EARPIECE;

    /** Direct the audio stream through Bluetooth. */
    public static final int ROUTE_BLUETOOTH     = CallAudioState.ROUTE_BLUETOOTH;

    /** Direct the audio stream through a wired headset. */
    public static final int ROUTE_WIRED_HEADSET = CallAudioState.ROUTE_WIRED_HEADSET;

    /** Direct the audio stream through the device's speakerphone. */
    public static final int ROUTE_SPEAKER       = CallAudioState.ROUTE_SPEAKER;

    /** Valid values for msg.what */
    public static final int CONNECT_WIRED_HEADSET = 1;
    public static final int DISCONNECT_WIRED_HEADSET = 2;
    public static final int CONNECT_DOCK = 5;
    public static final int DISCONNECT_DOCK = 6;
    public static final int BLUETOOTH_DEVICE_LIST_CHANGED = 7;
    public static final int BT_ACTIVE_DEVICE_PRESENT = 8;
    public static final int BT_ACTIVE_DEVICE_GONE = 9;

    public static final int SWITCH_EARPIECE = 1001;
    public static final int SWITCH_BLUETOOTH = 1002;
    public static final int SWITCH_HEADSET = 1003;
    public static final int SWITCH_SPEAKER = 1004;
    // Wired headset, earpiece, or speakerphone, in that order of precedence.
    public static final int SWITCH_BASELINE_ROUTE = 1005;

    // Messages denoting that the speakerphone was turned on/off. Used to update state when we
    // weren't the ones who turned it on/off
    public static final int SPEAKER_ON = 1006;
    public static final int SPEAKER_OFF = 1007;

    public static final int USER_SWITCH_EARPIECE = 1101;
    public static final int USER_SWITCH_BLUETOOTH = 1102;
    public static final int USER_SWITCH_HEADSET = 1103;
    public static final int USER_SWITCH_SPEAKER = 1104;
    public static final int USER_SWITCH_BASELINE_ROUTE = 1105;

    public static final int UPDATE_SYSTEM_AUDIO_ROUTE = 1201;

    // These three messages indicate state changes that come from BluetoothRouteManager.
    // They may be triggered by the BT stack doing something on its own or they may be sent after
    // we request that the BT stack do something. Any logic for these messages should take into
    // account the possibility that the event indicated has already been processed (i.e. handling
    // should be idempotent).
    public static final int BT_AUDIO_DISCONNECTED = 1301;
    public static final int BT_AUDIO_CONNECTED = 1302;
    public static final int BT_AUDIO_PENDING = 1303;

    public static final int MUTE_ON = 3001;
    public static final int MUTE_OFF = 3002;
    public static final int TOGGLE_MUTE = 3003;
    public static final int MUTE_EXTERNALLY_CHANGED = 3004;

    public static final int SWITCH_FOCUS = 4001;

    // Used in testing to execute verifications. Not compatible with subsessions.
    public static final int RUN_RUNNABLE = 9001;

    /** Valid values for mAudioFocusType */
    public static final int NO_FOCUS = 1;
    public static final int ACTIVE_FOCUS = 2;
    public static final int RINGING_FOCUS = 3;

    /** Valid values for the first argument for SWITCH_BASELINE_ROUTE */
    public static final int NO_INCLUDE_BLUETOOTH_IN_BASELINE = 0;
    public static final int INCLUDE_BLUETOOTH_IN_BASELINE = 1;

    @VisibleForTesting
    public static final SparseArray<String> AUDIO_ROUTE_TO_LOG_EVENT = new SparseArray<String>() {{
        put(CallAudioState.ROUTE_BLUETOOTH, LogUtils.Events.AUDIO_ROUTE_BT);
        put(CallAudioState.ROUTE_EARPIECE, LogUtils.Events.AUDIO_ROUTE_EARPIECE);
        put(CallAudioState.ROUTE_SPEAKER, LogUtils.Events.AUDIO_ROUTE_SPEAKER);
        put(CallAudioState.ROUTE_WIRED_HEADSET, LogUtils.Events.AUDIO_ROUTE_HEADSET);
    }};

    private static final SparseArray<String> MESSAGE_CODE_TO_NAME = new SparseArray<String>() {{
        put(CONNECT_WIRED_HEADSET, "CONNECT_WIRED_HEADSET");
        put(DISCONNECT_WIRED_HEADSET, "DISCONNECT_WIRED_HEADSET");
        put(CONNECT_DOCK, "CONNECT_DOCK");
        put(DISCONNECT_DOCK, "DISCONNECT_DOCK");
        put(BLUETOOTH_DEVICE_LIST_CHANGED, "BLUETOOTH_DEVICE_LIST_CHANGED");
        put(BT_ACTIVE_DEVICE_PRESENT, "BT_ACTIVE_DEVICE_PRESENT");
        put(BT_ACTIVE_DEVICE_GONE, "BT_ACTIVE_DEVICE_GONE");

        put(SWITCH_EARPIECE, "SWITCH_EARPIECE");
        put(SWITCH_BLUETOOTH, "SWITCH_BLUETOOTH");
        put(SWITCH_HEADSET, "SWITCH_HEADSET");
        put(SWITCH_SPEAKER, "SWITCH_SPEAKER");
        put(SWITCH_BASELINE_ROUTE, "SWITCH_BASELINE_ROUTE");
        put(SPEAKER_ON, "SPEAKER_ON");
        put(SPEAKER_OFF, "SPEAKER_OFF");

        put(USER_SWITCH_EARPIECE, "USER_SWITCH_EARPIECE");
        put(USER_SWITCH_BLUETOOTH, "USER_SWITCH_BLUETOOTH");
        put(USER_SWITCH_HEADSET, "USER_SWITCH_HEADSET");
        put(USER_SWITCH_SPEAKER, "USER_SWITCH_SPEAKER");
        put(USER_SWITCH_BASELINE_ROUTE, "USER_SWITCH_BASELINE_ROUTE");

        put(UPDATE_SYSTEM_AUDIO_ROUTE, "UPDATE_SYSTEM_AUDIO_ROUTE");

        put(BT_AUDIO_DISCONNECTED, "BT_AUDIO_DISCONNECTED");
        put(BT_AUDIO_CONNECTED, "BT_AUDIO_CONNECTED");
        put(BT_AUDIO_PENDING, "BT_AUDIO_PENDING");

        put(MUTE_ON, "MUTE_ON");
        put(MUTE_OFF, "MUTE_OFF");
        put(TOGGLE_MUTE, "TOGGLE_MUTE");
        put(MUTE_EXTERNALLY_CHANGED, "MUTE_EXTERNALLY_CHANGED");

        put(SWITCH_FOCUS, "SWITCH_FOCUS");

        put(RUN_RUNNABLE, "RUN_RUNNABLE");
    }};

    private static final String ACTIVE_EARPIECE_ROUTE_NAME = "ActiveEarpieceRoute";
    private static final String ACTIVE_BLUETOOTH_ROUTE_NAME = "ActiveBluetoothRoute";
    private static final String ACTIVE_SPEAKER_ROUTE_NAME = "ActiveSpeakerRoute";
    private static final String ACTIVE_HEADSET_ROUTE_NAME = "ActiveHeadsetRoute";
    private static final String RINGING_BLUETOOTH_ROUTE_NAME = "RingingBluetoothRoute";
    private static final String QUIESCENT_EARPIECE_ROUTE_NAME = "QuiescentEarpieceRoute";
    private static final String QUIESCENT_BLUETOOTH_ROUTE_NAME = "QuiescentBluetoothRoute";
    private static final String QUIESCENT_SPEAKER_ROUTE_NAME = "QuiescentSpeakerRoute";
    private static final String QUIESCENT_HEADSET_ROUTE_NAME = "QuiescentHeadsetRoute";

    public static final String NAME = CallAudioRouteStateMachine.class.getName();

    @Override
    protected void onPreHandleMessage(Message msg) {
        if (msg.obj != null && msg.obj instanceof SomeArgs) {
            Session session = (Session) ((SomeArgs) msg.obj).arg1;
            String messageCodeName = MESSAGE_CODE_TO_NAME.get(msg.what, "unknown");
            Log.continueSession(session, "CARSM.pM_" + messageCodeName);
            Log.i(this, "Message received: %s=%d, arg1=%d", messageCodeName, msg.what, msg.arg1);
        }
    }

    @Override
    protected void onPostHandleMessage(Message msg) {
        Log.endSession();
        if (msg.obj != null && msg.obj instanceof SomeArgs) {
            ((SomeArgs) msg.obj).recycle();
        }
    }

    abstract class AudioState extends State {
        @Override
        public void enter() {
            super.enter();
            Log.addEvent(mCallsManager.getForegroundCall(), LogUtils.Events.AUDIO_ROUTE,
                    "Entering state " + getName());
            if (isActive()) {
                Log.addEvent(mCallsManager.getForegroundCall(),
                        AUDIO_ROUTE_TO_LOG_EVENT.get(getRouteCode(), LogUtils.Events.AUDIO_ROUTE));
            }
        }

        @Override
        public void exit() {
            Log.addEvent(mCallsManager.getForegroundCall(), LogUtils.Events.AUDIO_ROUTE,
                    "Leaving state " + getName());
            super.exit();
        }

        @Override
        public boolean processMessage(Message msg) {
            int addedRoutes = 0;
            int removedRoutes = 0;
            boolean isHandled = NOT_HANDLED;

            Log.i(this, "Processing message %s",
                    MESSAGE_CODE_TO_NAME.get(msg.what, Integer.toString(msg.what)));
            switch (msg.what) {
                case CONNECT_WIRED_HEADSET:
                    Log.addEvent(mCallsManager.getForegroundCall(), LogUtils.Events.AUDIO_ROUTE,
                            "Wired headset connected");
                    removedRoutes |= ROUTE_EARPIECE;
                    addedRoutes |= ROUTE_WIRED_HEADSET;
                    break;
                case DISCONNECT_WIRED_HEADSET:
                    Log.addEvent(mCallsManager.getForegroundCall(), LogUtils.Events.AUDIO_ROUTE,
                            "Wired headset disconnected");
                    removedRoutes |= ROUTE_WIRED_HEADSET;
                    if (mDoesDeviceSupportEarpieceRoute) {
                        addedRoutes |= ROUTE_EARPIECE;
                    }
                    break;
                case BT_ACTIVE_DEVICE_PRESENT:
                    Log.addEvent(mCallsManager.getForegroundCall(), LogUtils.Events.AUDIO_ROUTE,
                            "Bluetooth active device present");
                    break;
                case BT_ACTIVE_DEVICE_GONE:
                    Log.addEvent(mCallsManager.getForegroundCall(), LogUtils.Events.AUDIO_ROUTE,
                            "Bluetooth active device gone");
                    break;
                case BLUETOOTH_DEVICE_LIST_CHANGED:
                    Log.addEvent(mCallsManager.getForegroundCall(), LogUtils.Events.AUDIO_ROUTE,
                            "Bluetooth device list changed");
                    Collection<BluetoothDevice> connectedDevices =
                            mBluetoothRouteManager.getConnectedDevices();
                    if (connectedDevices.size() > 0) {
                        addedRoutes |= ROUTE_BLUETOOTH;
                    } else {
                        removedRoutes |= ROUTE_BLUETOOTH;
                    }
                    isHandled = HANDLED;
                    break;
                case SWITCH_BASELINE_ROUTE:
                    sendInternalMessage(calculateBaselineRouteMessage(false,
                            msg.arg1 == INCLUDE_BLUETOOTH_IN_BASELINE));
                    return HANDLED;
                case USER_SWITCH_BASELINE_ROUTE:
                    sendInternalMessage(calculateBaselineRouteMessage(true,
                            msg.arg1 == INCLUDE_BLUETOOTH_IN_BASELINE));
                    return HANDLED;
                case USER_SWITCH_BLUETOOTH:
                    // If the user tries to switch to BT, reset the explicitly-switched-away flag.
                    mHasUserExplicitlyLeftBluetooth = false;
                    return NOT_HANDLED;
                case SWITCH_FOCUS:
                    // Perform BT hearing aid active device caching/restoration
                    if (mAudioFocusType != NO_FOCUS && msg.arg1 == NO_FOCUS) {
                        mBluetoothRouteManager.restoreHearingAidDevice();
                    } else if (mAudioFocusType == NO_FOCUS && msg.arg1 != NO_FOCUS) {
                        mBluetoothRouteManager.cacheHearingAidDevice();
                    }
                    mAudioFocusType = msg.arg1;
                    return NOT_HANDLED;
                default:
                    return NOT_HANDLED;
            }

            if (addedRoutes != 0 || removedRoutes != 0
                    || msg.what == BLUETOOTH_DEVICE_LIST_CHANGED) {
                mAvailableRoutes = modifyRoutes(mAvailableRoutes, removedRoutes, addedRoutes, true);
                mDeviceSupportedRoutes = modifyRoutes(mDeviceSupportedRoutes, removedRoutes,
                        addedRoutes, false);
                updateSystemAudioState();
            }

            return isHandled;
        }

        // Behavior will depend on whether the state is an active one or a quiescent one.
        abstract public void updateSystemAudioState();
        abstract public boolean isActive();
        abstract public int getRouteCode();
    }

    class ActiveEarpieceRoute extends EarpieceRoute {
        @Override
        public String getName() {
            return ACTIVE_EARPIECE_ROUTE_NAME;
        }

        @Override
        public boolean isActive() {
            return true;
        }

        @Override
        public void enter() {
            super.enter();
            setSpeakerphoneOn(false);
            CallAudioState newState = new CallAudioState(mIsMuted, ROUTE_EARPIECE,
                    mAvailableRoutes, null,
                    mBluetoothRouteManager.getConnectedDevices());
            setSystemAudioState(newState, true);
            updateInternalCallAudioState();
        }

        @Override
        public void updateSystemAudioState() {
            updateInternalCallAudioState();
            setSystemAudioState(mCurrentCallAudioState);
        }

        @Override
        public boolean processMessage(Message msg) {
            if (super.processMessage(msg) == HANDLED) {
                return HANDLED;
            }
            switch (msg.what) {
                case SWITCH_EARPIECE:
                case USER_SWITCH_EARPIECE:
                case SPEAKER_OFF:
                    // Nothing to do here
                    return HANDLED;
                case BT_AUDIO_CONNECTED:
                    transitionTo(mActiveBluetoothRoute);
                    return HANDLED;
                case SWITCH_BLUETOOTH:
                case USER_SWITCH_BLUETOOTH:
                    if ((mAvailableRoutes & ROUTE_BLUETOOTH) != 0) {
                        if (mAudioFocusType == ACTIVE_FOCUS
                                || mBluetoothRouteManager.isInbandRingingEnabled()) {
                            String address = (msg.obj instanceof SomeArgs) ?
                                    (String) ((SomeArgs) msg.obj).arg2 : null;
                            // Omit transition to ActiveBluetoothRoute
                            setBluetoothOn(address);
                        } else {
                            transitionTo(mRingingBluetoothRoute);
                        }
                    } else {
                        Log.w(this, "Ignoring switch to bluetooth command. Not available.");
                    }
                    return HANDLED;
                case SWITCH_HEADSET:
                case USER_SWITCH_HEADSET:
                    if ((mAvailableRoutes & ROUTE_WIRED_HEADSET) != 0) {
                        transitionTo(mActiveHeadsetRoute);
                    } else {
                        Log.w(this, "Ignoring switch to headset command. Not available.");
                    }
                    return HANDLED;
                case SWITCH_SPEAKER:
                case USER_SWITCH_SPEAKER:
                case SPEAKER_ON:
                    transitionTo(mActiveSpeakerRoute);
                    return HANDLED;
                case SWITCH_FOCUS:
                    if (msg.arg1 == NO_FOCUS) {
                        reinitialize();
                    }
                    return HANDLED;
                default:
                    return NOT_HANDLED;
            }
        }
    }

    class QuiescentEarpieceRoute extends EarpieceRoute {
        @Override
        public String getName() {
            return QUIESCENT_EARPIECE_ROUTE_NAME;
        }

        @Override
        public boolean isActive() {
            return false;
        }

        @Override
        public void enter() {
            super.enter();
            mHasUserExplicitlyLeftBluetooth = false;
            updateInternalCallAudioState();
        }

        @Override
        public void updateSystemAudioState() {
            updateInternalCallAudioState();
        }

        @Override
        public boolean processMessage(Message msg) {
            if (super.processMessage(msg) == HANDLED) {
                return HANDLED;
            }
            switch (msg.what) {
                case SWITCH_EARPIECE:
                case USER_SWITCH_EARPIECE:
                case SPEAKER_ON:
                    // Ignore speakerphone state changes outside of calls.
                case SPEAKER_OFF:
                    // Nothing to do here
                    return HANDLED;
                case BT_AUDIO_CONNECTED:
                    Log.w(this, "BT Audio came on in quiescent earpiece route.");
                    transitionTo(mActiveBluetoothRoute);
                    return HANDLED;
                case SWITCH_BLUETOOTH:
                case USER_SWITCH_BLUETOOTH:
                    if ((mAvailableRoutes & ROUTE_BLUETOOTH) != 0) {
                        transitionTo(mQuiescentBluetoothRoute);
                    } else {
                        Log.w(this, "Ignoring switch to bluetooth command. Not available.");
                    }
                    return HANDLED;
                case SWITCH_HEADSET:
                case USER_SWITCH_HEADSET:
                    if ((mAvailableRoutes & ROUTE_WIRED_HEADSET) != 0) {
                        transitionTo(mQuiescentHeadsetRoute);
                    } else {
                        Log.w(this, "Ignoring switch to headset command. Not available.");
                    }
                    return HANDLED;
                case SWITCH_SPEAKER:
                case USER_SWITCH_SPEAKER:
                    transitionTo(mQuiescentSpeakerRoute);
                    return HANDLED;
                case SWITCH_FOCUS:
                    if (msg.arg1 == ACTIVE_FOCUS || msg.arg1 == RINGING_FOCUS) {
                        transitionTo(mActiveEarpieceRoute);
                    }
                    return HANDLED;
                default:
                    return NOT_HANDLED;
            }
        }
    }

    abstract class EarpieceRoute extends AudioState {
        @Override
        public int getRouteCode() {
            return CallAudioState.ROUTE_EARPIECE;
        }

        @Override
        public boolean processMessage(Message msg) {
            if (super.processMessage(msg) == HANDLED) {
                return HANDLED;
            }
            switch (msg.what) {
                case CONNECT_WIRED_HEADSET:
                    sendInternalMessage(SWITCH_HEADSET);
                    return HANDLED;
                case BT_ACTIVE_DEVICE_PRESENT:
                    if (!mHasUserExplicitlyLeftBluetooth) {
                        sendInternalMessage(SWITCH_BLUETOOTH);
                    } else {
                        Log.i(this, "Not switching to BT route from earpiece because user has " +
                                "explicitly disconnected.");
                    }
                    return HANDLED;
                case BT_ACTIVE_DEVICE_GONE:
                    // No change in audio route required
                    return HANDLED;
                case DISCONNECT_WIRED_HEADSET:
                    Log.e(this, new IllegalStateException(),
                            "Wired headset should not go from connected to not when on " +
                            "earpiece");
                    return HANDLED;
                case BT_AUDIO_DISCONNECTED:
                    // This may be sent as a confirmation by the BT stack after switch off BT.
                    return HANDLED;
                case CONNECT_DOCK:
                    sendInternalMessage(SWITCH_SPEAKER);
                    return HANDLED;
                case DISCONNECT_DOCK:
                    // Nothing to do here
                    return HANDLED;
                default:
                    return NOT_HANDLED;
            }
        }
    }

    class ActiveHeadsetRoute extends HeadsetRoute {
        @Override
        public String getName() {
            return ACTIVE_HEADSET_ROUTE_NAME;
        }

        @Override
        public boolean isActive() {
            return true;
        }

        @Override
        public void enter() {
            super.enter();
            setSpeakerphoneOn(false);
            CallAudioState newState = new CallAudioState(mIsMuted, ROUTE_WIRED_HEADSET,
                    mAvailableRoutes, null, mBluetoothRouteManager.getConnectedDevices());
            setSystemAudioState(newState, true);
            updateInternalCallAudioState();
        }

        @Override
        public void updateSystemAudioState() {
            updateInternalCallAudioState();
            setSystemAudioState(mCurrentCallAudioState);
        }

        @Override
        public boolean processMessage(Message msg) {
            if (super.processMessage(msg) == HANDLED) {
                return HANDLED;
            }
            switch (msg.what) {
                case SWITCH_EARPIECE:
                case USER_SWITCH_EARPIECE:
                    if ((mAvailableRoutes & ROUTE_EARPIECE) != 0) {
                        transitionTo(mActiveEarpieceRoute);
                    } else {
                        Log.w(this, "Ignoring switch to earpiece command. Not available.");
                    }
                    return HANDLED;
                case BT_AUDIO_CONNECTED:
                    transitionTo(mActiveBluetoothRoute);
                    return HANDLED;
                case SWITCH_BLUETOOTH:
                case USER_SWITCH_BLUETOOTH:
                    if ((mAvailableRoutes & ROUTE_BLUETOOTH) != 0) {
                        if (mAudioFocusType == ACTIVE_FOCUS
                                || mBluetoothRouteManager.isInbandRingingEnabled()) {
                            String address = (msg.obj instanceof SomeArgs) ?
                                    (String) ((SomeArgs) msg.obj).arg2 : null;
                            // Omit transition to ActiveBluetoothRoute until actual connection.
                            setBluetoothOn(address);
                        } else {
                            transitionTo(mRingingBluetoothRoute);
                        }
                    } else {
                        Log.w(this, "Ignoring switch to bluetooth command. Not available.");
                    }
                    return HANDLED;
                case SWITCH_HEADSET:
                case USER_SWITCH_HEADSET:
                case SPEAKER_OFF:
                    // Nothing to do
                    return HANDLED;
                case SWITCH_SPEAKER:
                case USER_SWITCH_SPEAKER:
                case SPEAKER_ON:
                    transitionTo(mActiveSpeakerRoute);
                    return HANDLED;
                case SWITCH_FOCUS:
                    if (msg.arg1 == NO_FOCUS) {
                        reinitialize();
                    }
                    return HANDLED;
                default:
                    return NOT_HANDLED;
            }
        }
    }

    class QuiescentHeadsetRoute extends HeadsetRoute {
        @Override
        public String getName() {
            return QUIESCENT_HEADSET_ROUTE_NAME;
        }

        @Override
        public boolean isActive() {
            return false;
        }

        @Override
        public void enter() {
            super.enter();
            mHasUserExplicitlyLeftBluetooth = false;
            updateInternalCallAudioState();
        }

        @Override
        public void updateSystemAudioState() {
            updateInternalCallAudioState();
        }

        @Override
        public boolean processMessage(Message msg) {
            if (super.processMessage(msg) == HANDLED) {
                return HANDLED;
            }
            switch (msg.what) {
                case SWITCH_EARPIECE:
                case USER_SWITCH_EARPIECE:
                    if ((mAvailableRoutes & ROUTE_EARPIECE) != 0) {
                        transitionTo(mQuiescentEarpieceRoute);
                    } else {
                        Log.w(this, "Ignoring switch to earpiece command. Not available.");
                    }
                    return HANDLED;
                case BT_AUDIO_CONNECTED:
                    transitionTo(mActiveBluetoothRoute);
                    Log.w(this, "BT Audio came on in quiescent headset route.");
                    return HANDLED;
                case SWITCH_BLUETOOTH:
                case USER_SWITCH_BLUETOOTH:
                    if ((mAvailableRoutes & ROUTE_BLUETOOTH) != 0) {
                        transitionTo(mQuiescentBluetoothRoute);
                    } else {
                        Log.w(this, "Ignoring switch to bluetooth command. Not available.");
                    }
                    return HANDLED;
                case SWITCH_HEADSET:
                case USER_SWITCH_HEADSET:
                case SPEAKER_ON:
                    // Ignore speakerphone state changes outside of calls.
                case SPEAKER_OFF:
                    // Nothing to do
                    return HANDLED;
                case SWITCH_SPEAKER:
                case USER_SWITCH_SPEAKER:
                    transitionTo(mQuiescentSpeakerRoute);
                    return HANDLED;
                case SWITCH_FOCUS:
                    if (msg.arg1 == ACTIVE_FOCUS || msg.arg1 == RINGING_FOCUS) {
                        transitionTo(mActiveHeadsetRoute);
                    }
                    return HANDLED;
                default:
                    return NOT_HANDLED;
            }
        }
    }

    abstract class HeadsetRoute extends AudioState {
        @Override
        public int getRouteCode() {
            return CallAudioState.ROUTE_WIRED_HEADSET;
        }

        @Override
        public boolean processMessage(Message msg) {
            if (super.processMessage(msg) == HANDLED) {
                return HANDLED;
            }
            switch (msg.what) {
                case CONNECT_WIRED_HEADSET:
                    Log.e(this, new IllegalStateException(),
                            "Wired headset should already be connected.");
                    return HANDLED;
                case BT_ACTIVE_DEVICE_PRESENT:
                    if (!mHasUserExplicitlyLeftBluetooth) {
                        sendInternalMessage(SWITCH_BLUETOOTH);
                    } else {
                        Log.i(this, "Not switching to BT route from headset because user has " +
                                "explicitly disconnected.");
                    }
                    return HANDLED;
                case BT_ACTIVE_DEVICE_GONE:
                    // No change in audio route required
                    return HANDLED;
                case DISCONNECT_WIRED_HEADSET:
                    if (mWasOnSpeaker) {
                        sendInternalMessage(SWITCH_SPEAKER);
                    } else {
                        sendInternalMessage(SWITCH_BASELINE_ROUTE, INCLUDE_BLUETOOTH_IN_BASELINE);
                    }
                    return HANDLED;
                case BT_AUDIO_DISCONNECTED:
                    // This may be sent as a confirmation by the BT stack after switch off BT.
                    return HANDLED;
                case CONNECT_DOCK:
                    // Nothing to do here
                    return HANDLED;
                case DISCONNECT_DOCK:
                    // Nothing to do here
                    return HANDLED;
                default:
                    return NOT_HANDLED;
            }
        }
    }

    // Note: transitions to/from this class work a bit differently -- we delegate to
    // BluetoothRouteManager to manage all Bluetooth state, so instead of transitioning to one of
    // the bluetooth states immediately when there's an request to do so, we wait for
    // BluetoothRouteManager to report its state before we go into this state.
    class ActiveBluetoothRoute extends BluetoothRoute {
        @Override
        public String getName() {
            return ACTIVE_BLUETOOTH_ROUTE_NAME;
        }

        @Override
        public boolean isActive() {
            return true;
        }

        @Override
        public void enter() {
            super.enter();
            /// M: [ALPS03684081] Sound did not come from bluetooth after reconnect to bluetooth @{
            /// Issue scenario step by step:
            /// 1. Phone connect with bluetooth headset.
            /// 2. Switch audio route from bluetooth headset to earpiece in InCallUI.
            /// 3. Switch audio route from earpiece headset to bluetooth headset in InCallUI.
            /// 4. Disconnect bluetooth then connect bluetooth in settings, sound comes from
            ///     earpiece not bluetooth headset after bluetooth connect successfully.
            /// Root cause:
            /// In step 2, telecom update mHasUserExplicitlyLeftBluetooth to true, which mean it
            /// will not automaticallyconnect bluetooth audio after connect bluetooth.
            /// But in step 3, telecom has no update mHasUserExplicitlyLeftBluetooth to false.
            /// so  it will not automatically connect bluetooth audio in step 4.
            /// Solution:
            /// Reset mHasUserExplicitlyLeftBluetooth to false once enter BluetoothRoute.
            mHasUserExplicitlyLeftBluetooth = false;
            /// @}
            /// M: [ALPS03666862] Fix call audio timing issue. @{
            /// Issue scenario step by step:
            /// 1. Phone connect with bluetooth headset and wired headset at the same time.
            /// 2. Switch audio route from speaker to bluetooth headset in InCallUI.
            /// 3. In step2, sound comes from the wired headset for 1 second.
            /// Root cause:
            /// When switch audio route from speaker to bluetooth, telecom will turn off speaker
            /// then turn on bluetooth audio. However, because this is a two-action operation,
            /// audio native layer switches to the next default route immediately when speaker
            /// switched off (A wired headset priority is higher than bluetooth in AOSP).
            /// Solution:
            /// Telecom donot turn off speaker before turn on bluetooth audio, because audio native
            /// layer will turn off speaker before turn on bluetooth headset.
            // setSpeakerphoneOn(false);
            mStatusBarNotifier.notifySpeakerphone(false);
            /// @}
            CallAudioState newState = new CallAudioState(mIsMuted, ROUTE_BLUETOOTH,
                    mAvailableRoutes, mBluetoothRouteManager.getBluetoothAudioConnectedDevice(),
                    mBluetoothRouteManager.getConnectedDevices());
            setSystemAudioState(newState, true);
            updateInternalCallAudioState();
            // Do not send RINGER_MODE_CHANGE if no Bluetooth SCO audio device is available
            if (mBluetoothRouteManager.getBluetoothAudioConnectedDevice() != null) {
                mCallAudioManager.onRingerModeChange();
            }
        }

        @Override
        public void updateSystemAudioState() {
            updateInternalCallAudioState();
            setSystemAudioState(mCurrentCallAudioState);
        }

        @Override
        public void handleBtInitiatedDisconnect() {
            // There's special-case state transitioning here -- if BT tells us that
            // something got disconnected, we don't want to disconnect BT before
            // transitioning, since BT might be trying to connect another device in the
            // meantime.
            int command = calculateBaselineRouteMessage(false, false);
            switch (command) {
                case SWITCH_EARPIECE:
                    transitionTo(mActiveEarpieceRoute);
                    break;
                case SWITCH_HEADSET:
                    transitionTo(mActiveHeadsetRoute);
                    break;
                case SWITCH_SPEAKER:
                    transitionTo(mActiveSpeakerRoute);
                    break;
                default:
                    Log.w(this, "Got unexpected code " + command + " when processing a"
                            + " BT-initiated audio disconnect");
                    // Some fallback logic to make sure we make it off the bluetooth route.
                    super.handleBtInitiatedDisconnect();
                    break;
            }
        }

        @Override
        public boolean processMessage(Message msg) {
            if (super.processMessage(msg) == HANDLED) {
                return HANDLED;
            }
            switch (msg.what) {
                case USER_SWITCH_EARPIECE:
                    mHasUserExplicitlyLeftBluetooth = true;
                    // fall through
                case SWITCH_EARPIECE:
                    if ((mAvailableRoutes & ROUTE_EARPIECE) != 0) {
                        setBluetoothOff();
                        transitionTo(mActiveEarpieceRoute);
                    } else {
                        Log.w(this, "Ignoring switch to earpiece command. Not available.");
                    }
                    return HANDLED;
                case BT_AUDIO_CONNECTED:
                    // Send ringer mode change because we transit to ActiveBluetoothState even
                    // when HFP is connecting
                    mCallAudioManager.onRingerModeChange();
                    // Update the in-call app on the new active BT device in case that changed.
                    updateSystemAudioState();
                    return HANDLED;
                case SWITCH_BLUETOOTH:
                case USER_SWITCH_BLUETOOTH:
                    String address = (msg.obj instanceof SomeArgs) ?
                            (String) ((SomeArgs) msg.obj).arg2 : null;
                    setBluetoothOn(address);
                    return HANDLED;
                case USER_SWITCH_HEADSET:
                    mHasUserExplicitlyLeftBluetooth = true;
                    // fall through
                case SWITCH_HEADSET:
                    if ((mAvailableRoutes & ROUTE_WIRED_HEADSET) != 0) {
                        setBluetoothOff();
                        transitionTo(mActiveHeadsetRoute);
                    } else {
                        Log.w(this, "Ignoring switch to headset command. Not available.");
                    }
                    return HANDLED;
                case USER_SWITCH_SPEAKER:
                    mHasUserExplicitlyLeftBluetooth = true;
                    // fall through
                case SWITCH_SPEAKER:
                case SPEAKER_ON:
                    setBluetoothOff();
                    transitionTo(mActiveSpeakerRoute);
                    return HANDLED;
                case SPEAKER_OFF:
                    return HANDLED;
                case SWITCH_FOCUS:
                    if (msg.arg1 == NO_FOCUS) {
                        // Only disconnect SCO audio here instead of routing away from BT entirely.
                        mBluetoothRouteManager.disconnectSco();
                        reinitialize();
                    } else if (msg.arg1 == RINGING_FOCUS
                            && !mBluetoothRouteManager.isInbandRingingEnabled()) {
                        /// M: [ALPS04021833] Accept MT call, sound do not come from bluetooth @{
                        /// Issue scenario step by step:
                        /// 1. Phone connect with bluetooth headset.
                        /// 2. Make a MT call to DUT and accept it.
                        /// 3. Make another MT call to DUT and accept it. 1st MT call hung up.
                        /// 4. 2nd MT call enter active state but sound comes from earpiece not
                        /// bluetooth headset .
                        /// Root cause:
                        /// After step 3, call audio route state change from ActiveBluetoothRoute to
                        /// RingingBluetoothRoute, telecom will call setBluetoothOff() in this case.
                        /// In step 4, telecom call setBluetoothOn() but failed. Because bluetooth
                        /// module is proceessing turn off bluetooth belong to step 3 now, it return
                        /// bluetooth audio is on to telecom.
                        /// Solution:
                        /// Do not turn off bluetooth audio when ActiveBluetoothRoute switch to
                        /// RingingBluetoothRoute.
                        // setBluetoothOff();
                        Log.i(this, "Do not setBluetoothOff() when ActiveBluetoothRoute transition",
                                " to RingingBluetoothRoute");
                        /// @}
                        transitionTo(mRingingBluetoothRoute);
                    }
                    return HANDLED;
                case BT_AUDIO_DISCONNECTED:
                    handleBtInitiatedDisconnect();
                    return HANDLED;
                default:
                    return NOT_HANDLED;
            }
        }
    }

    // This state is only used when the device doesn't support in-band ring. If it does,
    // ActiveBluetoothRoute is used instead.
    class RingingBluetoothRoute extends BluetoothRoute {
        @Override
        public String getName() {
            return RINGING_BLUETOOTH_ROUTE_NAME;
        }

        @Override
        public boolean isActive() {
            /// M: Change return value to true. If request to setMute in RingingBluetoothRoute,
            /// operation will fail due to setMuteOn only update mute state if state is Active.
            /// ALPS03597365
            //return false;
            return true;
        }

        @Override
        public void enter() {
            super.enter();
            /// M: [ALPS03684081] Sound did not come from bluetooth after reconnect to bluetooth @{
            /// Issue scenario step by step:
            /// 1. Phone connect with bluetooth headset.
            /// 2. Switch audio route from bluetooth headset to earpiece in InCallUI.
            /// 3. Switch audio route from earpiece headset to bluetooth headset in InCallUI.
            /// 4. Disconnect bluetooth then connect bluetooth in settings, sound comes from
            ///     earpiece not bluetooth headset after bluetooth connect successfully.
            /// Root cause:
            /// In step 2, telecom update mHasUserExplicitlyLeftBluetooth to true, which mean it
            /// will not automaticallyconnect bluetooth audio after connect bluetooth.
            /// But in step 3, telecom has no update mHasUserExplicitlyLeftBluetooth to false.
            /// so  it will not automatically connect bluetooth audio in step 4.
            /// Solution:
            /// Reset mHasUserExplicitlyLeftBluetooth to false once enter BluetoothRoute.
            mHasUserExplicitlyLeftBluetooth = false;
            /// @}
            setSpeakerphoneOn(false);
            // Do not enable SCO audio here, since RING is being sent to the headset.
            CallAudioState newState = new CallAudioState(mIsMuted, ROUTE_BLUETOOTH,
                    mAvailableRoutes, mBluetoothRouteManager.getBluetoothAudioConnectedDevice(),
                    mBluetoothRouteManager.getConnectedDevices());
            setSystemAudioState(newState);
            updateInternalCallAudioState();
        }

        @Override
        public void updateSystemAudioState() {
            updateInternalCallAudioState();
            setSystemAudioState(mCurrentCallAudioState);
        }

        @Override
        public boolean processMessage(Message msg) {
            if (super.processMessage(msg) == HANDLED) {
                return HANDLED;
            }
            switch (msg.what) {
                case USER_SWITCH_EARPIECE:
                    mHasUserExplicitlyLeftBluetooth = true;
                    // fall through
                case SWITCH_EARPIECE:
                    if ((mAvailableRoutes & ROUTE_EARPIECE) != 0) {
                        transitionTo(mActiveEarpieceRoute);
                    } else {
                        Log.w(this, "Ignoring switch to earpiece command. Not available.");
                    }
                    return HANDLED;
                case BT_AUDIO_CONNECTED:
                    transitionTo(mActiveBluetoothRoute);
                    return HANDLED;
                case SWITCH_BLUETOOTH:
                case USER_SWITCH_BLUETOOTH:
                    // Nothing to do
                    return HANDLED;
                case USER_SWITCH_HEADSET:
                    mHasUserExplicitlyLeftBluetooth = true;
                    // fall through
                case SWITCH_HEADSET:
                    if ((mAvailableRoutes & ROUTE_WIRED_HEADSET) != 0) {
                        transitionTo(mActiveHeadsetRoute);
                    } else {
                        Log.w(this, "Ignoring switch to headset command. Not available.");
                    }
                    return HANDLED;
                case USER_SWITCH_SPEAKER:
                    mHasUserExplicitlyLeftBluetooth = true;
                    // fall through
                case SWITCH_SPEAKER:
                case SPEAKER_ON:
                    transitionTo(mActiveSpeakerRoute);
                    return HANDLED;
                case SPEAKER_OFF:
                    return HANDLED;
                case SWITCH_FOCUS:
                    if (msg.arg1 == NO_FOCUS) {
                        /// M: [ALPS04021833] Accept MT call, sound do not come from bluetooth @{
                        /// Ensure bluetooth audio is turn off.
                        setBluetoothOff();
                        /// @}
                        reinitialize();
                    } else if (msg.arg1 == ACTIVE_FOCUS) {
                        /// M: ALPS04650690, fix connect HFP audio error issue. @{
                        // Cause:
                        // 1. Phone connect BT device A then connect BT device B. In this step,
                        // telecom receive broadcast from HFP and set HfpActiveDeviceCache
                        // to B.
                        // 2. Incoming call, answer from A. In this step, HFP send broadcast to
                        // notify acitve device change to A then binder call telecom to answer
                        // call. But telecom maybe receive boradcast later than handle answer call.
                        // So HfpActiveDeviceCache still is B in call flow and telecom using B to
                        // connect HFP audio.
                        // 3. Finally, voice emit from B, but expect from A.
                        //
                        // Solution:
                        // Get active device from BluetoothHeadset directly and using it to connect
                        // audio.
                        setBluetoothOn(mBluetoothRouteManager.getCurrentActiveDeviceAddress());
                        /// @}
                    }
                    return HANDLED;
                case BT_AUDIO_DISCONNECTED:
                    // Ignore this -- audio disconnecting while ringing w/o in-band should not
                    // cause a route switch, since the device is still connected.
                    return HANDLED;
                default:
                    return NOT_HANDLED;
            }
        }
    }

    class QuiescentBluetoothRoute extends BluetoothRoute {
        @Override
        public String getName() {
            return QUIESCENT_BLUETOOTH_ROUTE_NAME;
        }

        @Override
        public boolean isActive() {
            return false;
        }

        @Override
        public void enter() {
            super.enter();
            mHasUserExplicitlyLeftBluetooth = false;
            updateInternalCallAudioState();
        }

        @Override
        public void updateSystemAudioState() {
            updateInternalCallAudioState();
        }

        @Override
        public boolean processMessage(Message msg) {
            if (super.processMessage(msg) == HANDLED) {
                return HANDLED;
            }
            switch (msg.what) {
                case SWITCH_EARPIECE:
                case USER_SWITCH_EARPIECE:
                    if ((mAvailableRoutes & ROUTE_EARPIECE) != 0) {
                        transitionTo(mQuiescentEarpieceRoute);
                    } else {
                        Log.w(this, "Ignoring switch to earpiece command. Not available.");
                    }
                    return HANDLED;
                case BT_AUDIO_CONNECTED:
                    transitionTo(mActiveBluetoothRoute);
                    return HANDLED;
                case SWITCH_BLUETOOTH:
                case USER_SWITCH_BLUETOOTH:
                case SPEAKER_ON:
                    // Ignore speakerphone state changes outside of calls.
                case SPEAKER_OFF:
                    // Nothing to do
                    return HANDLED;
                case SWITCH_HEADSET:
                case USER_SWITCH_HEADSET:
                    if ((mAvailableRoutes & ROUTE_WIRED_HEADSET) != 0) {
                        transitionTo(mQuiescentHeadsetRoute);
                    } else {
                        Log.w(this, "Ignoring switch to headset command. Not available.");
                    }
                    return HANDLED;
                case SWITCH_SPEAKER:
                case USER_SWITCH_SPEAKER:
                    transitionTo(mQuiescentSpeakerRoute);
                    return HANDLED;
                case SWITCH_FOCUS:
                    if (msg.arg1 == ACTIVE_FOCUS) {
                        setBluetoothOn(null);
                    } else if (msg.arg1 == RINGING_FOCUS) {
                        if (mBluetoothRouteManager.isInbandRingingEnabled()) {
                            setBluetoothOn(null);
                        } else {
                            transitionTo(mRingingBluetoothRoute);
                        }
                    }
                    return HANDLED;
                case BT_AUDIO_DISCONNECTED:
                    // Ignore this -- audio disconnecting while quiescent should not cause a
                    // route switch, since the device is still connected.
                    return HANDLED;
                default:
                    return NOT_HANDLED;
            }
        }
    }

    abstract class BluetoothRoute extends AudioState {
        @Override
        public int getRouteCode() {
            return CallAudioState.ROUTE_BLUETOOTH;
        }

        public void handleBtInitiatedDisconnect() {
            sendInternalMessage(SWITCH_BASELINE_ROUTE, NO_INCLUDE_BLUETOOTH_IN_BASELINE);
        }

        @Override
        public boolean processMessage(Message msg) {
            if (super.processMessage(msg) == HANDLED) {
                return HANDLED;
            }
            switch (msg.what) {
                case CONNECT_WIRED_HEADSET:
                    sendInternalMessage(SWITCH_HEADSET);
                    return HANDLED;
                case BT_ACTIVE_DEVICE_PRESENT:
                    Log.w(this, "Bluetooth active device should not"
                            + " have been null while we were in BT route.");
                    return HANDLED;
                case BT_ACTIVE_DEVICE_GONE:
                    handleBtInitiatedDisconnect();
                    mWasOnSpeaker = false;
                    return HANDLED;
                case DISCONNECT_WIRED_HEADSET:
                    // No change in audio route required
                    return HANDLED;
                case CONNECT_DOCK:
                    // Nothing to do here
                    return HANDLED;
                case DISCONNECT_DOCK:
                    // Nothing to do here
                    return HANDLED;
                default:
                    return NOT_HANDLED;
            }
        }
    }

    class ActiveSpeakerRoute extends SpeakerRoute {
        @Override
        public String getName() {
            return ACTIVE_SPEAKER_ROUTE_NAME;
        }

        @Override
        public boolean isActive() {
            return true;
        }

        @Override
        public void enter() {
            super.enter();
            mWasOnSpeaker = true;
            setSpeakerphoneOn(true);
            CallAudioState newState = new CallAudioState(mIsMuted, ROUTE_SPEAKER,
                    mAvailableRoutes, null, mBluetoothRouteManager.getConnectedDevices());
            setSystemAudioState(newState, true);
            updateInternalCallAudioState();
        }

        @Override
        public void updateSystemAudioState() {
            updateInternalCallAudioState();
            setSystemAudioState(mCurrentCallAudioState);
        }

        @Override
        public boolean processMessage(Message msg) {
            if (super.processMessage(msg) == HANDLED) {
                return HANDLED;
            }
            switch(msg.what) {
                case USER_SWITCH_EARPIECE:
                    mWasOnSpeaker = false;
                    // fall through
                case SWITCH_EARPIECE:
                    if ((mAvailableRoutes & ROUTE_EARPIECE) != 0) {
                        transitionTo(mActiveEarpieceRoute);
                    } else {
                        Log.w(this, "Ignoring switch to earpiece command. Not available.");
                    }
                    return HANDLED;
                case BT_AUDIO_CONNECTED:
                    transitionTo(mActiveBluetoothRoute);
                    return HANDLED;
                case USER_SWITCH_BLUETOOTH:
                    mWasOnSpeaker = false;
                    // fall through
                case SWITCH_BLUETOOTH:
                    String address = (msg.obj instanceof SomeArgs) ?
                            (String) ((SomeArgs) msg.obj).arg2 : null;
                    if ((mAvailableRoutes & ROUTE_BLUETOOTH) != 0) {
                        if (mAudioFocusType == ACTIVE_FOCUS
                                || mBluetoothRouteManager.isInbandRingingEnabled()) {
                            // Omit transition to ActiveBluetoothRoute
                            setBluetoothOn(address);
                        } else {
                            transitionTo(mRingingBluetoothRoute);
                        }
                    } else {
                        Log.w(this, "Ignoring switch to bluetooth command. Not available.");
                    }
                    return HANDLED;
                case USER_SWITCH_HEADSET:
                    mWasOnSpeaker = false;
                    // fall through
                case SWITCH_HEADSET:
                    if ((mAvailableRoutes & ROUTE_WIRED_HEADSET) != 0) {
                        transitionTo(mActiveHeadsetRoute);
                    } else {
                        Log.w(this, "Ignoring switch to headset command. Not available.");
                    }
                    return HANDLED;
                case SWITCH_SPEAKER:
                case USER_SWITCH_SPEAKER:
                    // Nothing to do
                    return HANDLED;
                case SPEAKER_ON:
                    // Expected, since we just transitioned here
                    return HANDLED;
                case SPEAKER_OFF:
                    sendInternalMessage(SWITCH_BASELINE_ROUTE, INCLUDE_BLUETOOTH_IN_BASELINE);
                    return HANDLED;
                case SWITCH_FOCUS:
                    if (msg.arg1 == NO_FOCUS) {
                        reinitialize();
                    }
                    return HANDLED;
                default:
                    return NOT_HANDLED;
            }
        }
    }

    class QuiescentSpeakerRoute extends SpeakerRoute {
        @Override
        public String getName() {
            return QUIESCENT_SPEAKER_ROUTE_NAME;
        }

        @Override
        public boolean isActive() {
            return false;
        }

        @Override
        public void enter() {
            super.enter();
            mHasUserExplicitlyLeftBluetooth = false;
            // Omit setting mWasOnSpeaker to true here, since this does not reflect a call
            // actually being on speakerphone.
            updateInternalCallAudioState();
        }

        @Override
        public void updateSystemAudioState() {
            updateInternalCallAudioState();
        }

        @Override
        public boolean processMessage(Message msg) {
            if (super.processMessage(msg) == HANDLED) {
                return HANDLED;
            }
            switch(msg.what) {
                case SWITCH_EARPIECE:
                case USER_SWITCH_EARPIECE:
                    if ((mAvailableRoutes & ROUTE_EARPIECE) != 0) {
                        transitionTo(mQuiescentEarpieceRoute);
                    } else {
                        Log.w(this, "Ignoring switch to earpiece command. Not available.");
                    }
                    return HANDLED;
                case BT_AUDIO_CONNECTED:
                    transitionTo(mActiveBluetoothRoute);
                    Log.w(this, "BT audio reported as connected while in quiescent speaker");
                    return HANDLED;
                case SWITCH_BLUETOOTH:
                case USER_SWITCH_BLUETOOTH:
                    if ((mAvailableRoutes & ROUTE_BLUETOOTH) != 0) {
                        transitionTo(mQuiescentBluetoothRoute);
                    } else {
                        Log.w(this, "Ignoring switch to bluetooth command. Not available.");
                    }
                    return HANDLED;
                case SWITCH_HEADSET:
                case USER_SWITCH_HEADSET:
                    if ((mAvailableRoutes & ROUTE_WIRED_HEADSET) != 0) {
                        transitionTo(mQuiescentHeadsetRoute);
                    } else {
                        Log.w(this, "Ignoring switch to headset command. Not available.");
                    }
                    return HANDLED;
                case SWITCH_SPEAKER:
                case USER_SWITCH_SPEAKER:
                case SPEAKER_ON:
                    // Nothing to do
                    return HANDLED;
                case SPEAKER_OFF:
                    sendInternalMessage(SWITCH_BASELINE_ROUTE, INCLUDE_BLUETOOTH_IN_BASELINE);
                    return HANDLED;
                case SWITCH_FOCUS:
                    if (msg.arg1 == ACTIVE_FOCUS || msg.arg1 == RINGING_FOCUS) {
                        transitionTo(mActiveSpeakerRoute);
                    }
                    return HANDLED;
                default:
                    return NOT_HANDLED;
            }
        }
    }

    abstract class SpeakerRoute extends AudioState {
        @Override
        public int getRouteCode() {
            return CallAudioState.ROUTE_SPEAKER;
        }

        @Override
        public boolean processMessage(Message msg) {
            if (super.processMessage(msg) == HANDLED) {
                return HANDLED;
            }
            switch (msg.what) {
                case CONNECT_WIRED_HEADSET:
                    sendInternalMessage(SWITCH_HEADSET);
                    return HANDLED;
                case BT_ACTIVE_DEVICE_PRESENT:
                    if (!mHasUserExplicitlyLeftBluetooth) {
                        sendInternalMessage(SWITCH_BLUETOOTH);
                    } else {
                        Log.i(this, "Not switching to BT route from speaker because user has " +
                                "explicitly disconnected.");
                    }
                    return HANDLED;
                case BT_ACTIVE_DEVICE_GONE:
                    // No change in audio route required
                    return HANDLED;
                case DISCONNECT_WIRED_HEADSET:
                    // No change in audio route required
                    return HANDLED;
                case BT_AUDIO_DISCONNECTED:
                    // This may be sent as a confirmation by the BT stack after switch off BT.
                    return HANDLED;
                case CONNECT_DOCK:
                    // Nothing to do here
                    return HANDLED;
                case DISCONNECT_DOCK:
                    sendInternalMessage(SWITCH_BASELINE_ROUTE, INCLUDE_BLUETOOTH_IN_BASELINE);
                    return HANDLED;
               default:
                    return NOT_HANDLED;
            }
        }
    }

    private final BroadcastReceiver mMuteChangeReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            Log.startSession("CARSM.mCR");
            if (AudioManager.ACTION_MICROPHONE_MUTE_CHANGED.equals(intent.getAction())) {
                if (mCallsManager.hasEmergencyCall()) {
                    Log.i(this, "Mute was externally changed when there's an emergency call. " +
                            "Forcing mute back off.");
                    sendInternalMessage(MUTE_OFF);
                } else {
                    sendInternalMessage(MUTE_EXTERNALLY_CHANGED);
                }
            } else {
                Log.w(this, "Received non-mute-change intent");
            }
        }
    };

    private final BroadcastReceiver mSpeakerPhoneChangeReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            Log.startSession("CARSM.mSPCR");
            try {
                if (AudioManager.ACTION_SPEAKERPHONE_STATE_CHANGED.equals(intent.getAction())) {
                    if (mAudioManager != null) {
                        if (mAudioManager.isSpeakerphoneOn()) {
                            sendInternalMessage(SPEAKER_ON);
                        } else {
                            sendInternalMessage(SPEAKER_OFF);
                        }
                    }
                } else {
                    Log.w(this, "Received non-speakerphone-change intent");
                }
            } finally {
                Log.endSession();
            }
        }
    };

    private final ActiveEarpieceRoute mActiveEarpieceRoute = new ActiveEarpieceRoute();
    private final ActiveHeadsetRoute mActiveHeadsetRoute = new ActiveHeadsetRoute();
    private final ActiveBluetoothRoute mActiveBluetoothRoute = new ActiveBluetoothRoute();
    private final ActiveSpeakerRoute mActiveSpeakerRoute = new ActiveSpeakerRoute();
    private final RingingBluetoothRoute mRingingBluetoothRoute = new RingingBluetoothRoute();
    private final QuiescentEarpieceRoute mQuiescentEarpieceRoute = new QuiescentEarpieceRoute();
    private final QuiescentHeadsetRoute mQuiescentHeadsetRoute = new QuiescentHeadsetRoute();
    private final QuiescentBluetoothRoute mQuiescentBluetoothRoute = new QuiescentBluetoothRoute();
    private final QuiescentSpeakerRoute mQuiescentSpeakerRoute = new QuiescentSpeakerRoute();

    /**
     * A few pieces of hidden state. Used to avoid exponential explosion of number of explicit
     * states
     */
    private int mDeviceSupportedRoutes;
    private int mAvailableRoutes;
    private int mAudioFocusType = NO_FOCUS;
    private boolean mWasOnSpeaker;
    private boolean mIsMuted;

    private final Context mContext;
    private final CallsManager mCallsManager;
    private final AudioManager mAudioManager;
    private final BluetoothRouteManager mBluetoothRouteManager;
    private final WiredHeadsetManager mWiredHeadsetManager;
    private final StatusBarNotifier mStatusBarNotifier;
    private final CallAudioManager.AudioServiceFactory mAudioServiceFactory;
    private final boolean mDoesDeviceSupportEarpieceRoute;
    private final TelecomSystem.SyncRoot mLock;
    private boolean mHasUserExplicitlyLeftBluetooth = false;

    private HashMap<String, Integer> mStateNameToRouteCode;
    private HashMap<Integer, AudioState> mRouteCodeToQuiescentState;

    // CallAudioState is used as an interface to communicate with many other system components.
    // No internal state transitions should depend on this variable.
    private CallAudioState mCurrentCallAudioState;
    private CallAudioState mLastKnownCallAudioState;

    private CallAudioManager mCallAudioManager;

    public CallAudioRouteStateMachine(
            Context context,
            CallsManager callsManager,
            BluetoothRouteManager bluetoothManager,
            WiredHeadsetManager wiredHeadsetManager,
            StatusBarNotifier statusBarNotifier,
            CallAudioManager.AudioServiceFactory audioServiceFactory,
            int earpieceControl) {
        super(NAME);
        addState(mActiveEarpieceRoute);
        addState(mActiveHeadsetRoute);
        addState(mActiveBluetoothRoute);
        addState(mActiveSpeakerRoute);
        addState(mRingingBluetoothRoute);
        addState(mQuiescentEarpieceRoute);
        addState(mQuiescentHeadsetRoute);
        addState(mQuiescentBluetoothRoute);
        addState(mQuiescentSpeakerRoute);

        mContext = context;
        mCallsManager = callsManager;
        mAudioManager = (AudioManager) mContext.getSystemService(Context.AUDIO_SERVICE);
        mBluetoothRouteManager = bluetoothManager;
        mWiredHeadsetManager = wiredHeadsetManager;
        mStatusBarNotifier = statusBarNotifier;
        mAudioServiceFactory = audioServiceFactory;
        switch (earpieceControl) {
            case EARPIECE_FORCE_DISABLED:
                mDoesDeviceSupportEarpieceRoute = false;
                break;
            case EARPIECE_FORCE_ENABLED:
                mDoesDeviceSupportEarpieceRoute = true;
                break;
            default:
                mDoesDeviceSupportEarpieceRoute = checkForEarpieceSupport();
        }
        mLock = callsManager.getLock();

        mStateNameToRouteCode = new HashMap<>(8);
        mStateNameToRouteCode.put(mQuiescentEarpieceRoute.getName(), ROUTE_EARPIECE);
        mStateNameToRouteCode.put(mQuiescentBluetoothRoute.getName(), ROUTE_BLUETOOTH);
        mStateNameToRouteCode.put(mQuiescentHeadsetRoute.getName(), ROUTE_WIRED_HEADSET);
        mStateNameToRouteCode.put(mQuiescentSpeakerRoute.getName(), ROUTE_SPEAKER);
        mStateNameToRouteCode.put(mRingingBluetoothRoute.getName(), ROUTE_BLUETOOTH);
        mStateNameToRouteCode.put(mActiveEarpieceRoute.getName(), ROUTE_EARPIECE);
        mStateNameToRouteCode.put(mActiveBluetoothRoute.getName(), ROUTE_BLUETOOTH);
        mStateNameToRouteCode.put(mActiveHeadsetRoute.getName(), ROUTE_WIRED_HEADSET);
        mStateNameToRouteCode.put(mActiveSpeakerRoute.getName(), ROUTE_SPEAKER);

        mRouteCodeToQuiescentState = new HashMap<>(4);
        mRouteCodeToQuiescentState.put(ROUTE_EARPIECE, mQuiescentEarpieceRoute);
        mRouteCodeToQuiescentState.put(ROUTE_BLUETOOTH, mQuiescentBluetoothRoute);
        mRouteCodeToQuiescentState.put(ROUTE_SPEAKER, mQuiescentSpeakerRoute);
        mRouteCodeToQuiescentState.put(ROUTE_WIRED_HEADSET, mQuiescentHeadsetRoute);
    }

    public void setCallAudioManager(CallAudioManager callAudioManager) {
        mCallAudioManager = callAudioManager;
    }

    /**
     * Initializes the state machine with info on initial audio route, supported audio routes,
     * and mute status.
     */
    public void initialize() {
        CallAudioState initState = getInitialAudioState();
        initialize(initState);
    }

    public void initialize(CallAudioState initState) {
        if ((initState.getRoute() & getCurrentCallSupportedRoutes()) == 0) {
            Log.e(this, new IllegalArgumentException(), "Route %d specified when supported call" +
                    " routes are: %d", initState.getRoute(), getCurrentCallSupportedRoutes());
        }

        mCurrentCallAudioState = initState;
        mLastKnownCallAudioState = initState;
        mDeviceSupportedRoutes = initState.getSupportedRouteMask();
        mAvailableRoutes = mDeviceSupportedRoutes & getCurrentCallSupportedRoutes();
        mIsMuted = initState.isMuted();
        mWasOnSpeaker = false;
        mContext.registerReceiver(mMuteChangeReceiver,
                new IntentFilter(AudioManager.ACTION_MICROPHONE_MUTE_CHANGED));
        mContext.registerReceiver(mSpeakerPhoneChangeReceiver,
                new IntentFilter(AudioManager.ACTION_SPEAKERPHONE_STATE_CHANGED));

        mStatusBarNotifier.notifyMute(initState.isMuted());
        mStatusBarNotifier.notifySpeakerphone(initState.getRoute() == CallAudioState.ROUTE_SPEAKER);
        setInitialState(mRouteCodeToQuiescentState.get(initState.getRoute()));
        start();
    }

    /**
     * Getter for the current CallAudioState object that the state machine is keeping track of.
     * Used for compatibility purposes.
     */
    public CallAudioState getCurrentCallAudioState() {
        return mCurrentCallAudioState;
    }

    public void sendMessageWithSessionInfo(int message, int arg) {
        sendMessageWithSessionInfo(message, arg, null);
    }

    public void sendMessageWithSessionInfo(int message) {
        sendMessageWithSessionInfo(message, 0, null);
    }

    public void sendMessageWithSessionInfo(int message, int arg, String data) {
        SomeArgs args = SomeArgs.obtain();
        args.arg1 = Log.createSubsession();
        args.arg2 = data;
        sendMessage(message, arg, 0, args);
    }

    /**
     * This is for state-independent changes in audio route (i.e. muting or runnables)
     * @param msg that couldn't be handled.
     */
    @Override
    protected void unhandledMessage(Message msg) {
        switch (msg.what) {
            case MUTE_ON:
                setMuteOn(true);
                updateSystemMuteState();
                return;
            case MUTE_OFF:
                setMuteOn(false);
                updateSystemMuteState();
                return;
            case MUTE_EXTERNALLY_CHANGED:
                mIsMuted = mAudioManager.isMicrophoneMute();
                if (isInActiveState()) {
                    updateSystemMuteState();
                }
                return;
            case TOGGLE_MUTE:
                if (mIsMuted) {
                    sendInternalMessage(MUTE_OFF);
                } else {
                    sendInternalMessage(MUTE_ON);
                }
                return;
            case UPDATE_SYSTEM_AUDIO_ROUTE:
                updateInternalCallAudioState();
                updateRouteForForegroundCall();
                resendSystemAudioState();
                /// M: ALPS03972502, fix issue speaker icon is not shown in status bar. @{
                /// Issue scenario step by step:
                /// 1. Make a MO call by SIM2 then turn on speaker.
                /// 2. Tap change SIM button, then SIM2 call will disconnect and new MO call will
                /// dial out by SIM1.
                /// 3. Sometimes, the speaker icon will disappear in status bar.
                /// Root cause:
                /// Change sim feature will remove current call(TC@1) and add new call(TC@2) ,
                /// but 'remove call' and 'add call' are not sequential, 'add call' may happend
                /// after 'remove call'. If remove TC@1 then add TC@2, issue will occur.
                /// 1. After step1, CurrentCallAudioState is speaker on, both InCallUI and status
                /// bar is showing speaker on.
                /// 2. After step2, TC@1 disconnect trigger play disconnect tone, then remove TC@1.
                /// 3. StatusBarNotifier receive TC@2 removed notification and find there is no any
                ///  call, remove speaker icon from status bar.
                /// 4. TC@2 is added.
                /// 5. When stateMachine receive TC@1 disconnect tone play done notification,
                /// because it has call now, cannot update CurrentCallAudioState to speaker off.
                /// So InCallUI still show speaker on but status bar treat speaker is off.
                /// Solution:
                /// Update mute and speaker state of status bar by CurrentCallAudioState when
                /// receive UPDATE_SYSTEM_AUDIO_ROUTE nofication to ensure the mute and
                /// speaker icon in statusBar is showing consistently with InCallUI.
                updateStatusBarAudioState();
                /// @}
                return;
            case RUN_RUNNABLE:
                java.lang.Runnable r = (java.lang.Runnable) msg.obj;
                r.run();
                return;
            default:
                Log.e(this, new IllegalStateException(), "Unexpected message code %d", msg.what);
        }
    }

    public void quitStateMachine() {
        quitNow();
    }

    public void dumpPendingMessages(IndentingPrintWriter pw) {
        getHandler().getLooper().dump(pw::println, "");
    }

    public boolean isHfpDeviceAvailable() {
        return mBluetoothRouteManager.isBluetoothAvailable();
    }

    private void setSpeakerphoneOn(boolean on) {
        Log.i(this, "turning speaker phone %s", on);
        mAudioManager.setSpeakerphoneOn(on);
        mStatusBarNotifier.notifySpeakerphone(on);
    }

    private void setBluetoothOn(String address) {
        if (mBluetoothRouteManager.isBluetoothAvailable()) {
            BluetoothDevice connectedDevice =
                    mBluetoothRouteManager.getBluetoothAudioConnectedDevice();
            /// M: ALPS04650690, fix connect HFP audio error issue. @{
               if (connectedDevice != null && (address == null || Objects.equals(address,
                       connectedDevice.getAddress()))) {
               /// @}

                // null means connect to any device, so don't bother reconnecting. Also, send a
                // message to ourselves telling us that BT audio is already connected.
                Log.i(this, "HFP audio already on. Skipping connecting.");
                sendInternalMessage(BT_AUDIO_CONNECTED);
                return;
            }
            if (connectedDevice == null || !Objects.equals(address, connectedDevice.getAddress())) {
                Log.i(this, "connecting bluetooth audio: %s", address);
                mBluetoothRouteManager.connectBluetoothAudio(address);
            }
        }
    }

    private void setBluetoothOff() {
        if (mBluetoothRouteManager.isBluetoothAvailable()) {
            if (mBluetoothRouteManager.isBluetoothAudioConnectedOrPending()) {
                Log.i(this, "disconnecting bluetooth audio");
                mBluetoothRouteManager.disconnectBluetoothAudio();
            }
        }
    }

    private void setMuteOn(boolean mute) {
        mIsMuted = mute;
        Log.addEvent(mCallsManager.getForegroundCall(), mute ?
                LogUtils.Events.MUTE : LogUtils.Events.UNMUTE);
        if (mute != mAudioManager.isMicrophoneMute() && isInActiveState()) {
            IAudioService audio = mAudioServiceFactory.getAudioService();
            Log.i(this, "changing microphone mute state to: %b [serviceIsNull=%b]",
                    mute, audio == null);
            if (audio != null) {
                try {
                    // We use the audio service directly here so that we can specify
                    // the current user. Telecom runs in the system_server process which
                    // may run as a separate user from the foreground user. If we
                    // used AudioManager directly, we would change mute for the system's
                    // user and not the current foreground, which we want to avoid.
                    audio.setMicrophoneMute(
                            mute, mContext.getOpPackageName(), getCurrentUserId());
                } catch (RemoteException e) {
                    Log.e(this, e, "Remote exception while toggling mute.");
                }
                // TODO: Check microphone state after attempting to set to ensure that
                // our state corroborates AudioManager's state.
            }
        }
    }

    private void updateSystemMuteState() {
        CallAudioState newCallAudioState = new CallAudioState(mIsMuted,
                mCurrentCallAudioState.getRoute(),
                mAvailableRoutes,
                mCurrentCallAudioState.getActiveBluetoothDevice(),
                mBluetoothRouteManager.getConnectedDevices());
        setSystemAudioState(newCallAudioState);
        updateInternalCallAudioState();
    }

    /**
     * Updates the CallAudioState object from current internal state. The result is used for
     * external communication only.
     */
    private void updateInternalCallAudioState() {
        IState currentState = getCurrentState();
        if (currentState == null) {
            Log.e(this, new IllegalStateException(), "Current state should never be null" +
                    " when updateInternalCallAudioState is called.");
            mCurrentCallAudioState = new CallAudioState(
                    mIsMuted, mCurrentCallAudioState.getRoute(), mAvailableRoutes,
                    mBluetoothRouteManager.getBluetoothAudioConnectedDevice(),
                    mBluetoothRouteManager.getConnectedDevices());
            return;
        }
        int currentRoute = mStateNameToRouteCode.get(currentState.getName());
        mCurrentCallAudioState = new CallAudioState(mIsMuted, currentRoute, mAvailableRoutes,
                mBluetoothRouteManager.getBluetoothAudioConnectedDevice(),
                mBluetoothRouteManager.getConnectedDevices());
    }

    private void setSystemAudioState(CallAudioState newCallAudioState) {
        setSystemAudioState(newCallAudioState, false);
    }

    private void resendSystemAudioState() {
        setSystemAudioState(mLastKnownCallAudioState, true);
    }

    private void setSystemAudioState(CallAudioState newCallAudioState, boolean force) {
        synchronized (mLock) {
            Log.i(this, "setSystemAudioState: changing from %s to %s", mLastKnownCallAudioState,
                    newCallAudioState);
            if (force || !newCallAudioState.equals(mLastKnownCallAudioState)) {
                mStatusBarNotifier.notifyMute(newCallAudioState.isMuted());
                mCallsManager.onCallAudioStateChanged(mLastKnownCallAudioState, newCallAudioState);
                updateAudioForForegroundCall(newCallAudioState);
                mLastKnownCallAudioState = newCallAudioState;
            }
        }
    }

    private void updateAudioForForegroundCall(CallAudioState newCallAudioState) {
        Call call = mCallsManager.getForegroundCall();
        if (call != null && call.getConnectionService() != null) {
            call.getConnectionService().onCallAudioStateChanged(call, newCallAudioState);
        }
    }

    private int calculateSupportedRoutes() {
        int routeMask = CallAudioState.ROUTE_SPEAKER;

        if (mWiredHeadsetManager.isPluggedIn()) {
            routeMask |= CallAudioState.ROUTE_WIRED_HEADSET;
        } else if (mDoesDeviceSupportEarpieceRoute){
            routeMask |= CallAudioState.ROUTE_EARPIECE;
        }

        if (mBluetoothRouteManager.isBluetoothAvailable()) {
            routeMask |=  CallAudioState.ROUTE_BLUETOOTH;
        }

        return routeMask;
    }

    private void sendInternalMessage(int messageCode) {
        sendInternalMessage(messageCode, 0);
    }

    private void sendInternalMessage(int messageCode, int arg1) {
        // Internal messages are messages which the state machine sends to itself in the
        // course of processing externally-sourced messages. We want to send these messages at
        // the front of the queue in order to make actions appear atomic to the user and to
        // prevent scenarios such as these:
        // 1. State machine handler thread is suspended for some reason.
        // 2. Headset gets connected (sends CONNECT_HEADSET).
        // 3. User switches to speakerphone in the UI (sends SWITCH_SPEAKER).
        // 4. State machine handler is un-suspended.
        // 5. State machine handler processes the CONNECT_HEADSET message and sends
        //    SWITCH_HEADSET at end of queue.
        // 6. State machine handler processes SWITCH_SPEAKER.
        // 7. State machine handler processes SWITCH_HEADSET.
        Session subsession = Log.createSubsession();
        if(subsession != null) {
            SomeArgs args = SomeArgs.obtain();
            args.arg1 = subsession;
            sendMessageAtFrontOfQueue(messageCode, arg1, 0, args);
        } else {
            sendMessageAtFrontOfQueue(messageCode, arg1);
        }
    }

    private CallAudioState getInitialAudioState() {
        int supportedRouteMask = calculateSupportedRoutes() & getCurrentCallSupportedRoutes();
        final int route;

        if ((supportedRouteMask & ROUTE_BLUETOOTH) != 0
                && mBluetoothRouteManager.hasBtActiveDevice()) {
            route = ROUTE_BLUETOOTH;
        } else if ((supportedRouteMask & ROUTE_WIRED_HEADSET) != 0) {
            route = ROUTE_WIRED_HEADSET;
        } else if ((supportedRouteMask & ROUTE_EARPIECE) != 0) {
            route = ROUTE_EARPIECE;
        } else {
            route = ROUTE_SPEAKER;
        }

        return new CallAudioState(false, route, supportedRouteMask, null,
                mBluetoothRouteManager.getConnectedDevices());
    }

    private int getCurrentUserId() {
        final long ident = Binder.clearCallingIdentity();
        try {
            UserInfo currentUser = ActivityManager.getService().getCurrentUser();
            return currentUser.id;
        } catch (RemoteException e) {
            // Activity manager not running, nothing we can do assume user 0.
        } finally {
            Binder.restoreCallingIdentity(ident);
        }
        return UserHandle.USER_OWNER;
    }

    public boolean isInActiveState() {
        AudioState currentState = (AudioState) getCurrentState();
        if (currentState == null) {
            Log.w(this, "Current state is null, assuming inactive state");
            return false;
        }
        return currentState.isActive();
    }

    private boolean checkForEarpieceSupport() {
        AudioDeviceInfo[] deviceList = mAudioManager.getDevices(AudioManager.GET_DEVICES_OUTPUTS);
        for (AudioDeviceInfo device: deviceList) {
            if (device.getType() == AudioDeviceInfo.TYPE_BUILTIN_EARPIECE) {
                return true;
            }
        }
        // No earpiece found
        return false;
    }

    private int calculateBaselineRouteMessage(boolean isExplicitUserRequest,
            boolean includeBluetooth) {
        boolean isSkipEarpiece = false;
        if (!isExplicitUserRequest) {
            synchronized (mLock) {
                // Check video calls to skip earpiece since the baseline for video
                // calls should be the speakerphone route
                isSkipEarpiece = mCallsManager.hasVideoCall();
            }
        }
        if ((mAvailableRoutes & ROUTE_BLUETOOTH) != 0
                && !mHasUserExplicitlyLeftBluetooth
                && includeBluetooth
                /// M: ALPS03945922, Cannot switch to bluetooth route if no HFP device @{
                && mBluetoothRouteManager.hasBtActiveDevice()) {
                /// @}
            return isExplicitUserRequest ? USER_SWITCH_BLUETOOTH : SWITCH_BLUETOOTH;
        } else if ((mAvailableRoutes & ROUTE_EARPIECE) != 0 && !isSkipEarpiece) {
            return isExplicitUserRequest ? USER_SWITCH_EARPIECE : SWITCH_EARPIECE;
        } else if ((mAvailableRoutes & ROUTE_WIRED_HEADSET) != 0) {
            return isExplicitUserRequest ? USER_SWITCH_HEADSET : SWITCH_HEADSET;
        } else {
            return isExplicitUserRequest ? USER_SWITCH_SPEAKER : SWITCH_SPEAKER;
        }
    }

    private void reinitialize() {
        CallAudioState initState = getInitialAudioState();
        mDeviceSupportedRoutes = initState.getSupportedRouteMask();
        mAvailableRoutes = mDeviceSupportedRoutes & getCurrentCallSupportedRoutes();
        mIsMuted = initState.isMuted();
        setSpeakerphoneOn(initState.getRoute() == CallAudioState.ROUTE_SPEAKER);
        setMuteOn(mIsMuted);
        mWasOnSpeaker = false;
        mHasUserExplicitlyLeftBluetooth = false;
        mLastKnownCallAudioState = initState;
        transitionTo(mRouteCodeToQuiescentState.get(initState.getRoute()));
    }

    private void updateRouteForForegroundCall() {
        mAvailableRoutes = mDeviceSupportedRoutes & getCurrentCallSupportedRoutes();

        CallAudioState currentState = getCurrentCallAudioState();

        // Move to baseline route in the case the current route is no longer available.
        if ((mAvailableRoutes & currentState.getRoute()) == 0) {
            sendInternalMessage(calculateBaselineRouteMessage(false, true));
        }
    }

    private int getCurrentCallSupportedRoutes() {
        int supportedRoutes = CallAudioState.ROUTE_ALL;

        /// M: ALPS04013079, fix NullPointerException here in CAT test. @{
        /// Cause:
        /// Seldom case, between "if (mCallsManager.getForegroundCall() != null)" and
        /// "supportedRoutes &= mCallsManager.getForegroundCall().getSupportedAudioRoutes()"
        ///  since the foreground call sate changed from ACTIVE to ON_HOLD, getForegroundCall()
        ///  will return null. finally cause NullPointerException.
        /// Solution:
        /// Add temporary variate to storage foreground call.
        // if (mCallsManager.getForegroundCall() != null) {
        //     supportedRoutes &= mCallsManager.getForegroundCall().getSupportedAudioRoutes();
        // }
        Call call = mCallsManager.getForegroundCall();
        if (call != null) {
            supportedRoutes &= call.getSupportedAudioRoutes();
        }
        /// @}

        return supportedRoutes;
    }

    private int modifyRoutes(int base, int remove, int add, boolean considerCurrentCall) {
        base &= ~remove;

        if (considerCurrentCall) {
            add &= getCurrentCallSupportedRoutes();
        }

        base |= add;

        return base;
    }

    /**
     * M: restore mute operation. @{
     * like hold cdma call, then unhold cdma call,
     * or Gsm/cdma call swap on SVLTE based mute is on
     *
     * NOTE: this method reference from super.setMuteOn()
     */
    public void restoreMuteOnWhenInCallMode() {
        if (mIsMuted && isInActiveState()) {
            IAudioService audio = mAudioServiceFactory.getAudioService();
            Log.i(this, "changing microphone mute state to: %b [serviceIsNull=%b]",
                    mIsMuted, audio == null);
            if (audio != null) {
                try {
                    // We use the audio service directly here so that we can specify
                    // the current user. Telecom runs in the system_server process which
                    // may run as a separate user from the foreground user. If we
                    // used AudioManager directly, we would change mute for the system's
                    // user and not the current foreground, which we want to avoid.
                    audio.setMicrophoneMute(
                            mIsMuted, mContext.getOpPackageName(), getCurrentUserId());

                } catch (RemoteException e) {
                    Log.e(this, e, "Remote exception while toggling mute.");
                }
                // TODO: Check microphone state after attempting to set to ensure that
                // our state corroborates AudioManager's state.
            }
        }
    }

    /**
     * M: ALPS03972502, fix issue speaker icon is not shown in status bar. @{
     * Update mute and speaker state of status bar by mCurrentCallAudioState, ensure
     * the mute and speaker icon in statusBar is showing consistently with InCallUI.
     */
    private void updateStatusBarAudioState() {
        boolean isMute = mCurrentCallAudioState.isMuted();
        boolean isSpeakerOn = (mCurrentCallAudioState.getRoute() == ROUTE_SPEAKER);

        if (mStatusBarNotifier.isStatusBarShowingMute() != isMute) {
            Log.i(this, "updateStatusBarAudioState, isMute : %b -> %b",
                    mStatusBarNotifier.isStatusBarShowingMute(), isMute);
            mStatusBarNotifier.notifyMute(isMute);
        }

        if (mStatusBarNotifier.isStatusBarShowingSpeaker() != isSpeakerOn) {
            Log.i(this, "updateStatusBarAudioState, isSpeakerOn : %b -> %b",
                    mStatusBarNotifier.isStatusBarShowingSpeaker(), isSpeakerOn);
            mStatusBarNotifier.notifySpeakerphone(isSpeakerOn);
        }
    }
}
