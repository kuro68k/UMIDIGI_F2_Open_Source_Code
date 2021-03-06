/* //device/system/reference-ril/atchannel.h
**
** Copyright 2006, The Android Open Source Project
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef ATCHANNEL_H
#define ATCHANNEL_H 1

#ifdef __cplusplus
extern "C" {
#endif

/* define AT_DEBUG to send AT traffic to /tmp/radio-at.log" */
#define AT_DEBUG  1

#include <telephony/mtk_ril.h>

#ifdef HAVE_ANDROID_OS
#endif /* HAVE_ANDROID_OS */

#ifndef UNUSED
    #define UNUSED(x) (x)   // eliminate "warning: unused parameter"
#endif

#define NUM_ELEMS(x) (sizeof(x)/sizeof(x[0]))

#define MAX_AT_RESPONSE (8 * 1024)
#define VPUP_TIMEOUT_MSEC 15000LL /* MD3 +VPUP timeout*/
#define HANDSHAKE_RETRY_COUNT 8
#define HANDSHAKE_TIMEOUT_MSEC 250
#define ATCOMMAND_TIMEOUT_MSEC 10000LL
#define DEFAULT_RETRY_TIMES 30000LL  /* s */

#define MAX_ERR_COUNT   3 /* Timeout 3 times, will reset the cbp */

/* define USE_DATA_CHANNEL to send ATD#777 in DATA_CHANNEL */
#define USE_DATA_CHANNEL 1
#define DATA_CHANNEL_DEVICE "/dev/VIAUSBModem0"

#define PROPERTY_MODEM_EE "vendor.net.cdma.mdmstat"

#if AT_DEBUG
extern void  AT_DUMP(const char* prefix, const char*  buff, int  len);
#else
#define  AT_DUMP(prefix,buff,len)  do{}while(0)
#endif

#define AT_ERROR_GENERIC -1
#define AT_ERROR_COMMAND_PENDING -2
#define AT_ERROR_CHANNEL_CLOSED -3
#define AT_ERROR_TIMEOUT -4
#define AT_ERROR_INVALID_THREAD -5 /* AT commands may not be issued from
                                       reader thread (or unsolicited response
                                       callback */
#define AT_ERROR_INVALID_RESPONSE -6 /* eg an at_send_command_singleline that
                                        did not get back an intermediate
                                        response */

#define MAX_TIMEOUTSECS_TO_RECEIVE_HCMGSS 150000 /* the max timeout from excuting CMGS to receiving the HCMGSS/HCMGSF. ex.30000=30s */

#define FIRST_AT_CHANNEL 0

extern const struct RIL_Env *s_rilenv;
#define RIL_queryMyChannelId(a) s_rilenv->QueryMyChannelId(a)
extern int RIL_queryMyProxyIdByThread();
extern void waitMd3InitDone();

typedef enum {
    NO_RESULT,   /* no intermediate response expected */
    NUMERIC,     /* a single intermediate response starting with a 0-9 */
    SINGLELINE,  /* a single intermediate response starting with a prefix */
    MULTILINE,    /* multiple line intermediate response
                    starting with a prefix */
    /* atci start */
    RAW
    /* atci end */
} ATCommandType;

/** a singly-lined list of intermediate responses */
typedef struct ATLine  {
    struct ATLine *p_next;
    char *line;
} ATLine;

/** Free this with at_response_free() */
typedef struct {
    int success;              /* true if final response indicates
                                    success (eg "OK") */
    int ack;                  /* true if request ACK received */
    char *finalResponse;      /* eg OK, ERROR */
    const char *current_cmd;        /*AT command whom this response belong to*/
    ATLine  *p_intermediates; /* any intermediate responses */
} ATResponse;

/**
 * a user-provided unsolicited response handler function
 * this will be called from the reader thread, so do not block
 * "s" is the line, and "sms_pdu" is either NULL or the PDU response
 * for multi-line TS 27.005 SMS PDU responses (eg +CMT:)
 */
typedef void (*ATUnsolHandler)(const char *s, const char *sms_pdu);

// For multi channel support
typedef struct RILChannelCtx {
    const char* myName;
    RILChannelId id;
    pthread_t tid_reader;
    pthread_t tid_myProxy;
    int fd;
    ATUnsolHandler unsolHandler;
    int readCount;

    pthread_mutex_t commandmutex;
    pthread_cond_t commandcond;

    pthread_mutex_t* p_channelMutex;

    ATCommandType type;
    const char *responsePrefix;
    const char *smsPDU;
    ATResponse *p_response;

    int readerClosed;

    char *ATBufferCur;
    char ATBuffer[MAX_AT_RESPONSE+1];
    int pendingRequest;
} RILChannelCtx;

RILChannelCtx *getChannelCtxbyId(RILChannelId id);
RILChannelCtx *getDefaultChannelCtx();
RILChannelCtx *getRILChannelCtxFromToken(RIL_Token t);

typedef int (* RILAtSendHookCb)(
    const char *command, ATCommandType type,
    const char *responsePrefix,
    const char *smspdu,
    long long timeoutMsec,
    ATResponse **pp_outResponse,
    RILChannelCtx *p_channel,
    RIL_Token ackToken);

static int s_readerClosed;

void at_set_hook(RILAtSendHookCb hookCb);
int at_open_old(int fd, ATUnsolHandler h);
void at_close(RILChannelId channelId);

// For multi channel support
int at_open(int fd, ATUnsolHandler h, RILChannelCtx* p_channel);

/* This callback is invoked on the command thread.
   You should reset or handshake here to avoid getting out of sync */
void at_set_on_timeout(void (*onTimeout)(RILChannelId channelId));
/* This callback is invoked on the reader thread (like ATUnsolHandler)
   when the input stream closes before you call at_close
   (not when you call at_close())
   You should still call at_close()
   It may also be invoked immediately from the current thread if the read
   channel is already closed */
void at_set_on_reader_closed(void (*onClose)(RILChannelId channel_id));

int at_send_command_singleline_cw(const char *command,
                                const char *responsePrefix, const char * string,
                                 ATResponse **pp_outResponse, RILChannelCtx* p_channel);

int at_send_command_singleline_cw_ack(const char *command,
                                const char *responsePrefix, const char * string,
                                 ATResponse **pp_outResponse, RILChannelCtx* p_channel,
                                 RIL_Token ackToken);

int at_send_command_singleline (const char *command,
                                const char *responsePrefix,
                                 ATResponse **pp_outResponse, RILChannelCtx* p_channel);

int at_send_command_singleline_ack(const char *command,
                                const char *responsePrefix,
                                ATResponse **pp_outResponse,
                                RILChannelCtx* p_channel,
                                RIL_Token ackToken);

int at_send_command_numeric (const char *command,
                                 ATResponse **pp_outResponse, RILChannelCtx* p_channel);

int at_send_command_numeric_ack(const char *command,
                             ATResponse **pp_outResponse,
                             RILChannelCtx* p_channel,
                             RIL_Token ackToken);

int at_send_command_multiline (const char *command,
                                const char *responsePrefix,
                                 ATResponse **pp_outResponse, RILChannelCtx* p_channel);

int at_send_command_multiline_ack(const char *command,
                               const char *responsePrefix,
                               ATResponse **pp_outResponse,
                               RILChannelCtx* p_channel,
                               RIL_Token ackToken);

int at_handshake();

int at_send_command (const char *command, ATResponse **pp_outResponse, RILChannelCtx* p_channel);

int at_send_command_ack(const char *command, ATResponse **pp_outResponse,
                               RILChannelCtx* p_channel, RIL_Token ackToken);

int at_send_command_notimeout(const char *command, ATResponse **pp_outResponse, RILChannelCtx* p_channel);

int at_send_command_notimeout_ack(const char *command, ATResponse **pp_outResponse,
                               RILChannelCtx* p_channel, RIL_Token ackToken);


int at_send_command_with_specified_timeout (const char *command,long long timeoutMsec,ATResponse **pp_outResponse, RILChannelCtx* p_channel);
int at_send_command_with_specified_timeout_ack(const char *command, long long timeoutMsec,
                                ATResponse **pp_outResponse, RILChannelCtx* p_channel, RIL_Token ackToken);


int at_send_command_sms (const char *command, const char *pdu,
                            const char *responsePrefix,
                            ATResponse **pp_outResponse, RILChannelCtx* p_channel);

int at_send_command_sms_ack(const char *command, const char *pdu,
                            const char *responsePrefix,
                            ATResponse **pp_outResponse,
                            RILChannelCtx* p_channel,
                            RIL_Token ackToken);

int at_send_command_multiline_notimeout(const char *command, const char *responsePrefix,
        ATResponse **pp_outResponse, RILChannelCtx * p_channel);
int at_send_command_multiline_notimeout_ack(const char *command, const char *responsePrefix,
        ATResponse **pp_outResponse, RILChannelCtx * p_channel, RIL_Token ackToken);
int at_send_command_raw_ack(const char *command, ATResponse **pp_outResponse,
        RILChannelCtx *p_channel, RIL_Token ackToken);


void at_response_free(ATResponse *p_response);
RILChannelCtx *getChannelCtxbyProxy();

typedef enum {
    CME_ERROR_NON_CME = -1,
    CME_SUCCESS = 0,
    CME_SIM_NOT_INSERTED = 10,
    CME_SIM_FAILURE = 13,
    CME_SIM_BUSY = 14,
    CME_INCORRECT_PASSWORD = 16,
    CME_SIM_PUK2_REQUIRED = 18,
    // BT SIM Access Profile - START
    CME_BT_SAP_UIM_NOT_INSERTED = 10,
    CME_BT_SAP_UIM_ERROR_NO_REASON_DEFINED = 60,
    CME_BT_SAP_UIM_NOT_ACCESSIBLE = 61,
    CME_BT_SAP_UIM_ALREADY_POWERED_OFF = 62,
    CME_BT_SAP_UIM_ALREADY_POWERED_ON = 63,
    // BT SIM Access Profile - END
    CME_RADIO_NOT_ALLOWED_DURING_RAT_SWITCH = 350
} AT_CME_Error;

AT_CME_Error at_get_cme_error(const ATResponse *p_response);

extern int deactivedata_inprogress;

int isModemPoweredOff();

#ifdef __cplusplus
}
#endif

#endif /*ATCHANNEL_H*/
