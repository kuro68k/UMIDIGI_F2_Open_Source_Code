/*
 * Conditions Of Use
 *
 * This software was developed by employees of the National Institute of
 * Standards and Technology (NIST), an agency of the Federal Government.
 * Pursuant to title 15 Untied States Code Section 105, works of NIST
 * employees are not subject to copyright protection in the United States
 * and are considered to be in the public domain.  As a result, a formal
 * license is not needed to use the software.
 *
 * This software is provided by NIST as a service and is expressly
 * provided "AS IS."  NIST MAKES NO WARRANTY OF ANY KIND, EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTY OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, NON-INFRINGEMENT
 * AND DATA ACCURACY.  NIST does not warrant or make any representations
 * regarding the use of the software or the results thereof, including but
 * not limited to the correctness, accuracy, reliability or usefulness of
 * the software.
 *
 * Permission to use this software is contingent upon your acceptance
 * of the terms of this agreement
 *
 * .
 *
 */
/* This class is entirely derived from TCPMessageProcessor,
 *  by making some minor changes.
 *
 *               Daniel J. Martinez Manzano <dani@dif.um.es>
 * Acknowledgement: Jeff Keyser suggested that a
 * Stop mechanism be added to this. Niklas Uhrberg suggested that
 * a means to limit the number of simultaneous active connections
 * should be added. Mike Andrews suggested that the thread be
 * accessible so as to implement clean stop using Thread.join().
 *
 */

/******************************************************************************
 * Product of NIST/ITL Advanced Networking Technologies Division (ANTD).      *
 ******************************************************************************/
package gov2.nist.javax2.sip.stack;

import gov2.nist.core.HostPort;
import gov2.nist.javax2.sip.SipStackImpl;

import javax.net.ssl.SSLException;
import javax.net.ssl.SSLServerSocket;
import javax.net.ssl.SSLSocket;

import java.io.IOException;
import java.net.*;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Hashtable;
import java.util.Iterator;

/**
 * Sit in a loop waiting for incoming tls connections and start a new thread to handle each new
 * connection. This is the active object that creates new TLS MessageChannels (one for each new
 * accept socket).
 * 
 * @version 1.2 $Revision: 1.23 $ $Date: 2009/12/06 15:58:39 $
 * 
 * @author M. Ranganathan <br/>
 * 
 */
public class TLSMessageProcessor extends MessageProcessor {

    protected int nConnections;

    private boolean isRunning;

    private Hashtable<String, TLSMessageChannel> tlsMessageChannels;

    protected int useCount = 0;

    private ArrayList<TLSMessageChannel> incomingTlsMessageChannels;

    /**
     * Constructor.
     * 
     * @param ipAddress -- inet address where I am listening.
     * @param sipStack SIPStack structure.
     * @param port port where this message processor listens.
     */
    protected TLSMessageProcessor(InetAddress ipAddress, SIPTransactionStack sipStack, int port) {
        super(ipAddress, port, "tls",sipStack);
        this.sipStack = sipStack;
        this.tlsMessageChannels = new Hashtable<String, TLSMessageChannel>();
        this.incomingTlsMessageChannels = new ArrayList<TLSMessageChannel>();

    }

    /**
     * Start the processor.
     */
    public void start() throws IOException {
        Thread thread = new Thread(this);
        thread.setName("TLSMessageProcessorThread");
        // ISSUE 184
        thread.setPriority(Thread.MAX_PRIORITY);
        thread.setDaemon(true);

        this.isRunning = true;
        thread.start();

    }

    public void run() {
    }

    /**
     * Returns the stack.
     * 
     * @return my sip stack.
     */
    public SIPTransactionStack getSIPStack() {
        return sipStack;
    }

    /**
     * Stop the message processor. Feature suggested by Jeff Keyser.
     */
    public synchronized void stop() {
        if (!isRunning)
            return;

        isRunning = false;

        Collection en = tlsMessageChannels.values();
        for (Iterator it = en.iterator(); it.hasNext();) {
            TLSMessageChannel next = (TLSMessageChannel) it.next();
            next.close();
        }
        for (Iterator incomingMCIterator = incomingTlsMessageChannels.iterator(); incomingMCIterator
                .hasNext();) {
            TLSMessageChannel next = (TLSMessageChannel) incomingMCIterator.next();
            next.close();
        }
        this.notify();

    }

    protected synchronized void remove(TLSMessageChannel tlsMessageChannel) {

        String key = tlsMessageChannel.getKey();
        if (sipStack.isLoggingEnabled()) {
            sipStack.getStackLogger().logDebug(Thread.currentThread() + " removing " + key);
        }

        /** May have been removed already */
        if (tlsMessageChannels.get(key) == tlsMessageChannel)
            this.tlsMessageChannels.remove(key);
        
        incomingTlsMessageChannels.remove(tlsMessageChannel);
    }

    public synchronized MessageChannel createMessageChannel(HostPort targetHostPort)
            throws IOException {
        String key = MessageChannel.getKey(targetHostPort, "TLS");
        if (tlsMessageChannels.get(key) != null) {
            return (TLSMessageChannel) this.tlsMessageChannels.get(key);
        } else {
            TLSMessageChannel retval = new TLSMessageChannel(targetHostPort.getInetAddress(),
                    targetHostPort.getPort(), sipStack, this);
            this.tlsMessageChannels.put(key, retval);
            retval.isCached = true;
            if (sipStack.isLoggingEnabled()) {
                sipStack.getStackLogger().logDebug("key " + key);
                sipStack.getStackLogger().logDebug("Creating " + retval);
            }
            return retval;
        }
    }

    protected synchronized void cacheMessageChannel(TLSMessageChannel messageChannel) {
        String key = messageChannel.getKey();
        TLSMessageChannel currentChannel = (TLSMessageChannel) tlsMessageChannels.get(key);
        if (currentChannel != null) {
            if (sipStack.isLoggingEnabled())
                sipStack.getStackLogger().logDebug("Closing " + key);
            currentChannel.close();
        }
        if (sipStack.isLoggingEnabled())
            sipStack.getStackLogger().logDebug("Caching " + key);
        this.tlsMessageChannels.put(key, messageChannel);

    }

    public synchronized MessageChannel createMessageChannel(InetAddress host, int port)
            throws IOException {
        try {
            String key = MessageChannel.getKey(host, port, "TLS");
            if (tlsMessageChannels.get(key) != null) {
                return (TLSMessageChannel) this.tlsMessageChannels.get(key);
            } else {
                TLSMessageChannel retval = new TLSMessageChannel(host, port, sipStack, this);
                this.tlsMessageChannels.put(key, retval);
                retval.isCached = true;
                if (sipStack.isLoggingEnabled()) {
                    sipStack.getStackLogger().logDebug("key " + key);
                    sipStack.getStackLogger().logDebug("Creating " + retval);
                }
                return retval;
            }
        } catch (UnknownHostException ex) {
            throw new IOException(ex.getMessage());
        }
    }

    /**
     * TLS can handle an unlimited number of bytes.
     */
    public int getMaximumMessageSize() {
        return Integer.MAX_VALUE;
    }

    public boolean inUse() {
        return this.useCount != 0;
    }

    /**
     * Default target port for TLS
     */
    public int getDefaultTargetPort() {
        return 5061;
    }

    /**
     * TLS is a secure protocol.
     */
    public boolean isSecure() {
        return true;
    }
}
