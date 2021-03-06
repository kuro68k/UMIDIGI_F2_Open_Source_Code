// This source code is generated by UdpGeneratorTool, not recommend to modify it directly
package com.mediatek.lbs.em2.mnldinterface;

import com.mediatek.socket.base.SocketUtils.BaseBuffer;
import com.mediatek.socket.base.SocketUtils.Codable;

public enum DebugReqStatusCategory implements Codable {
    stopDebug,
    startDebug,
    end,
;

    public final static DebugReqStatusCategory _instance = DebugReqStatusCategory.stopDebug;

    @Override
    public void encode(BaseBuffer buff) {
        switch (this) {
        case stopDebug:
            buff.putInt(0);
            break;
        case startDebug:
            buff.putInt(1);
            break;
        case end:
            buff.putInt(2147483647);
            break;
        default:
            break;
        }
    }

    @Override
    public DebugReqStatusCategory decode(BaseBuffer buff) {
        int _type = buff.getInt();
        switch (_type) {
        case 0:
            return stopDebug;
        case 1:
            return startDebug;
        case 2147483647:
            return end;
        }
        return null;
    }

    @Override
    public DebugReqStatusCategory[] getArray(Codable[] data) {
        DebugReqStatusCategory[] _out = new DebugReqStatusCategory[data.length];
        for (int _i = 0; _i < data.length; _i++) {
            _out[_i] = (DebugReqStatusCategory) data[_i];
        }
        return _out;
    }

}
