package javax2.sip.message;

import java.text.ParseException;
import java.util.List;

import gov2.nist.javax2.sip.header.RequestLine;

import javax2.sip.address.URI;
import javax2.sip.header.CSeqHeader;
import javax2.sip.header.CallIdHeader;
import javax2.sip.header.ContentTypeHeader;
import javax2.sip.header.FromHeader;
import javax2.sip.header.MaxForwardsHeader;
import javax2.sip.header.ServerHeader;
import javax2.sip.header.ToHeader;
import javax2.sip.header.UserAgentHeader;

public interface MessageFactory {
    Request createRequest(URI requestURI, String method, CallIdHeader callId,
            CSeqHeader cSeq, FromHeader from, ToHeader to, List via,
            MaxForwardsHeader maxForwards, ContentTypeHeader contentType,
            Object content) throws ParseException;

    Request createRequest(URI requestURI, String method, CallIdHeader callId,
            CSeqHeader cSeq, FromHeader from, ToHeader to, List via,
            MaxForwardsHeader maxForwards, ContentTypeHeader contentType,
            byte[] content) throws ParseException;

    Request createRequest(URI requestURI, String method, CallIdHeader callId,
            CSeqHeader cSeq, FromHeader from, ToHeader to, List via,
            MaxForwardsHeader maxForwards) throws ParseException;

    Request createRequest(RequestLine reqLine, String method, CallIdHeader callId,
            CSeqHeader cSeq, FromHeader from, ToHeader to, List via,
            MaxForwardsHeader maxForwards) throws ParseException;

    Request createRequest(String request) throws ParseException;

    Response createResponse(int statusCode, CallIdHeader callId,
            CSeqHeader cSeq, FromHeader from, ToHeader to, List via,
            MaxForwardsHeader maxForwards, ContentTypeHeader contentType,
            Object content) throws ParseException;

    Response createResponse(int statusCode, CallIdHeader callId,
            CSeqHeader cSeq, FromHeader from, ToHeader to, List via,
            MaxForwardsHeader maxForwards, ContentTypeHeader contentType,
            byte[] content) throws ParseException;

    Response createResponse(int statusCode, CallIdHeader callId,
            CSeqHeader cSeq, FromHeader from, ToHeader to, List via,
            MaxForwardsHeader maxForwards) throws ParseException;

    Response createResponse(int statusCode, Request request,
            ContentTypeHeader contentType, Object content)
            throws ParseException;

    Response createResponse(int statusCode, Request request,
            ContentTypeHeader contentType, byte[] content)
            throws ParseException;

    Response createResponse(int statusCode, Request request)
            throws ParseException;

    Response createResponse(String response) throws ParseException;

    void setDefaultContentEncodingCharset(String defaultContentEncodingCharset)
            throws NullPointerException, IllegalArgumentException;
    void setDefaultServerHeader(ServerHeader defaultServerHeader);
    void setDefaultUserAgentHeader(UserAgentHeader defaultUserAgentHeader);
}

