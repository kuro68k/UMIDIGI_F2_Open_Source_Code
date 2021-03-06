package com.android.mail.utils;

import java.util.ArrayList;
import java.util.Map;

import android.app.Notification;
import android.app.PendingIntent;
import android.content.ContentUris;
import android.content.ContentValues;
import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.database.CursorWrapper;
import android.net.Uri;
import android.text.TextUtils;
import androidx.core.app.NotificationCompat;
import androidx.core.app.NotificationManagerCompat;
import androidx.collection.ArrayMap;

import com.android.mail.R;
import com.android.emailcommon.provider.Mailbox;
import com.android.mail.MailIntentService;
import com.android.mail.analytics.Analytics;
import com.android.mail.photo.ContactFetcher;
import com.android.mail.preferences.AccountPreferences;
import com.android.mail.preferences.FolderPreferences;
import com.android.mail.providers.Account;
import com.android.mail.providers.Conversation;
import com.android.mail.providers.Folder;
import com.android.mail.providers.UIProvider;
import com.android.mail.providers.UIProvider.FolderColumns;
import com.android.mail.utils.NotificationActionUtils.NotificationAction;
import com.android.mail.utils.NotificationUtils.NotificationBuilders;
import com.mediatek.email.extension.SendNotificationProxy;
import com.mediatek.mail.vip.VipMemberCache;
import com.mediatek.mail.vip.VipNotificationStyle;
import com.mediatek.mail.vip.VipPreferences;

public class VipNotificationUtils {
    public static final String LOG_TAG = "VipNotificationUtils";
    /** M: Use for VIP notification. @{ */
    public static final String VIP = "VIP";
    private static final String UIFOLDER = "uifolder";
    /** @} */

    public static int getVipNotificationId(final android.accounts.Account account,
            final Folder folder) {
        return (1 ^ account.hashCode() ^ folder.hashCode())
                | NotificationActionUtils.CHECK_VIP_MASK;
    }

    public static boolean isVipNotificationId(int notificationId) {
        return (notificationId & NotificationActionUtils.CHECK_VIP_MASK) > 0;
    }

    public static NotificationAction checkUndoNotifcation(Account account,
            Folder folder) {
        /// M: Folder will have common notification and Vip notification
        int vipNotificationId =
                getVipNotificationId(account.getAccountManagerAccount(), folder);
        /// M:only if neither of the folder's notifications in undo notificaiton can we show the notification
        return NotificationActionUtils.sUndoNotifications
                .get(vipNotificationId);
    }

    public static void cancelRemoveVipNotification(NotificationManagerCompat nm, Account account, Folder folder) {
        int notificationId = getVipNotificationId(account.getAccountManagerAccount(), folder);
        nm.cancel(notificationId);
        NotificationActionUtils.sUndoNotifications.remove(notificationId);
        NotificationActionUtils.sNotificationTimestamps.delete(notificationId);
    }

    public static void cancelVipNotification(NotificationManagerCompat nm,
            android.accounts.Account account, Folder folder) {
        nm.cancel(getVipNotificationId(account, folder));
    }

    public static boolean handleVipNotification(Context context, Account account,
            Folder folder, Cursor cursor, boolean getAttention,
            boolean ignoreUnobtrusiveSetting, int unseenCount, int unreadCount,
            long newMsgId, final ContactFetcher photoFetcher) {
        boolean notifyVip = VipPreferences.get(context).getVipNotification();
        if (notifyVip) {
            handleMsgNotification(context, account, folder, cursor, getAttention,
                    ignoreUnobtrusiveSetting, unseenCount, unreadCount,
                    newMsgId, photoFetcher);
            return true;
        } else {
            return false;
        }
    }

    /** M:VIP was enabled and we need process VIP Notification, too @{ */
    public static void handleMsgNotification(Context context, Account account, Folder folder,
            Cursor cursor, boolean getAttention, boolean ignoreUnobtrusiveSetting, int unseenCount,
            int unreadCount, long newMsgId, final ContactFetcher photoFetcher) {
        final NotificationManagerCompat nm = NotificationManagerCompat.from(context);
        final int notificationId = NotificationUtils.getNotificationId(
                account.getAccountManagerAccount(), folder);
        final int vipNotificationId = getVipNotificationId(
                account.getAccountManagerAccount(), folder);

        if (unseenCount == 0) {
            LogUtils.i(
                    LOG_TAG,
                    "handleMsgNotification - cancelling account %s / folder %s",
                    LogUtils.sanitizeName(LOG_TAG, account.getDisplayName()),
                    LogUtils.sanitizeName(LOG_TAG, folder.persistentId));
            nm.cancel(notificationId);
            nm.cancel(vipNotificationId);
            return;
        }

        long lastNotifiedMsgId = -1L;
        lastNotifiedMsgId = folder.lastNotifiedMsgKey;
        if (newMsgId > lastNotifiedMsgId) {
            ///M: new msgs has arrived, and update in DB
            ContentValues cv = new ContentValues();
            cv.put(FolderColumns.LAST_NOTIFIED_MESSAGE_KEY, newMsgId);
            context.getContentResolver().update(
                    ContentUris.withAppendedId(Mailbox.CONTENT_URI, folder.id),
                    cv, null, null);
        } else {
            ///M: we need to update the notification's data quietly
            ignoreUnobtrusiveSetting = false;
            LogUtils.d(LOG_TAG, "handleMsgNotification update the notification quietly");
        }

        VipFilterCursorWrapper filterVipCursor = new VipFilterCursorWrapper(
                cursor, VipFilterCursorWrapper.Filter_Mode.MOD_VIP);
        int newNonVipMessageCount = filterVipCursor
                .getCount(VipFilterCursorWrapper.Type_Count.TYPE_NON_VIP);
        int newVipMessageCount = filterVipCursor
                .getCount(VipFilterCursorWrapper.Type_Count.TYPE_VIP);
        LogUtils.d(LOG_TAG, "handleMsgNotification unseen msgs common %d, vip %d", newNonVipMessageCount, newVipMessageCount);
        if (newNonVipMessageCount <= 0) {
            nm.cancel(notificationId);
        } else {
            filterVipCursor.setMode(VipFilterCursorWrapper.Filter_Mode.MOD_NO_VIP);
            notifyNewMsg(context, account, folder, (Cursor) filterVipCursor,
                    notificationId, newMsgId, unreadCount,
                    newNonVipMessageCount, ignoreUnobtrusiveSetting,
                    getAttention, photoFetcher, false);
        }

        if (newVipMessageCount <= 0) {
            nm.cancel(vipNotificationId);
        } else {
            //M: Just get unread Vip Message to update the number later
            int vipUnreadMsg = VipMemberCache.getFolderVipMsgCount(context, folder.id, true);
            LogUtils.d(LOG_TAG, "handleMsgNotification vip unread msgs %d", vipUnreadMsg);
            filterVipCursor.setMode(VipFilterCursorWrapper.Filter_Mode.MOD_VIP);
            notifyNewMsg(context, account, folder, (Cursor) filterVipCursor,
                    vipNotificationId, newMsgId, vipUnreadMsg,
                    newVipMessageCount, ignoreUnobtrusiveSetting, getAttention,
                    photoFetcher, true);
        }
    }
    /** @} */

    /**
     * M: Get the id of the virtual mailbox,eg:vip.
     * @param accountId the account's id
     * @param tyep the mailbox's type
     */
    private static long getVirtualMailboxId(long accountId, int type) {
        return (accountId << 32) + type;
    }

    /**
     * M: Creates a URI string from a database ID (guaranteed to be unique).
     * @param type of the resource: uifolder, message, etc.
     * @param id the id of the resource.
     * @return uri string
     */
    public static String uiUriString(String type, long id) {
        return "content://" + UIProvider.EMAIL_PROVIDER_AUTHORITY + "/" + type
                + ((id == -1) ? "" : ("/" + id));
    }

    /** M: Create a URI. */
    public static Uri uiUri(String type, long id) {
        return Uri.parse(uiUriString(type, id));
    }

    ///M: porting VIP notification
    public static void notifyNewMsg(final Context context, final Account account,
            final Folder folder, final Cursor cursor, final int notificationId,
            final long newMsgId, final int unreadCount, final int unseenCount,
            boolean ignoreUnobtrusiveSetting, boolean getAttention,
            final ContactFetcher photoFetcher, boolean isVip) {

        // We now have all we need to create the notification and the pending intent
        PendingIntent clickIntent;
        CharSequence title = "";
        NotificationActionUtils.initEmailNotificationChannel(context, account.getEmailAddress(), account.getDisplayName());
        NotificationCompat.Builder notification;
        if (isVip) {
            notification = new NotificationCompat.Builder(context, NotificationActionUtils.NOTIFICATION_CHANNEL_VIP);

        } else {
            notification = new NotificationCompat.Builder(context, account.getEmailAddress());
        }

        NotificationCompat.WearableExtender wearableExtender = new NotificationCompat.WearableExtender();
        Map<Integer, NotificationBuilders> msgNotifications = new ArrayMap<Integer, NotificationBuilders>();
        /** M: Add for special provider. if this account is 189 account, set the notification small
         * icon to special 189 icon. @{ */
        int smallIcon = R.drawable.ic_notification_mail_24dp;
        if (SendNotificationProxy.getInstance(context).isShowSpecialNotificationIcon(
                account.getEmailAddress())) {
            smallIcon = R.drawable.external_stat_notify_special_provider;
        }
        /** @} */
        notification.setSmallIcon(smallIcon);
        notification.setTicker(account.getDisplayName());

        final long when;
        final long oldWhen =
                NotificationActionUtils.sNotificationTimestamps.get(notificationId);
        if (oldWhen != 0) {
            when = oldWhen;
        } else {
            when = System.currentTimeMillis();
        }

        notification.setWhen(when);

        // The timestamp is now stored in the notification, so we can remove it from here
        NotificationActionUtils.sNotificationTimestamps.delete(notificationId);

        // Dispatch a CLEAR_NEW_MAIL_NOTIFICATIONS intent if the user taps the "X" next to a
        // notification.  Also this intent gets fired when the user taps on a notification as
        // the AutoCancel flag has been set
        final Intent cancelNotificationIntent =
                new Intent(MailIntentService.ACTION_CLEAR_NEW_MAIL_NOTIFICATIONS);
        cancelNotificationIntent.setPackage(context.getPackageName());
        cancelNotificationIntent.setData(Utils.appendVersionQueryParameter(context,
                folder.folderUri.fullUri));
        cancelNotificationIntent.putExtra(Utils.EXTRA_ACCOUNT, account);
        cancelNotificationIntent.putExtra(Utils.EXTRA_FOLDER, folder);

        notification.setDeleteIntent(PendingIntent.getService(
                context, notificationId, cancelNotificationIntent, 0));

        // Ensure that the notification is cleared when the user selects it
        notification.setAutoCancel(true);

        boolean eventInfoConfigured = false;

        final boolean isInbox = folder.folderUri.equals(account.settings.defaultInbox);
        final FolderPreferences folderPreferences =
                new FolderPreferences(context, account.getEmailAddress(), folder, isInbox);

        if (isInbox) {
            final AccountPreferences accountPreferences =
                    new AccountPreferences(context, account.getEmailAddress());
            NotificationUtils.moveNotificationSetting(accountPreferences, folderPreferences);
        }

        /// M: keep Vip Settings' priority higher than account settings
        if (!isVip && !folderPreferences.areNotificationsEnabled()) {
            LogUtils.i(LOG_TAG, "Notifications are disabled for this folder; not notifying");
            // Don't notify
            return;
        }

        if (unreadCount > 0) {
            // How can I order this properly?
            ///M:repeat alert when mark unread flag on another device
            if (cursor.moveToNext()) {
                final Intent notificationIntent;

                // Launch directly to the conversation, if there is only 1 unseen conversation
                final boolean launchConversationMode = (unseenCount == 1);
                if (launchConversationMode) {
                    notificationIntent = createViewConversationIntent(
                            context, account,
                            (folder != null && folder.folderUri != null) ? folder.folderUri.fullUri
                                    : null, cursor);
                } else {
                    /**
                     * M: If VIP, enter VIP folder when clicking notification.
                     * Redirect the folder URI, according to the message
                     * type(such as VIP messages) @{
                     */
                    if (isVip) {
                        long accountId = Integer.parseInt(account.uri.getLastPathSegment());
                        long vipFolderId = getVirtualMailboxId(accountId, Mailbox.TYPE_VIP);
                        notificationIntent = createViewConversationIntent(
                                context, account, uiUri(UIFOLDER, vipFolderId),
                                null);
                    } else {
                        notificationIntent = createViewConversationIntent(
                                context, account,
                                (folder != null && folder.folderUri != null) ? folder.folderUri.fullUri
                                        : null, null);
                    }
                    /** @} */
                }

                Analytics.getInstance().sendEvent("notification_create",
                        launchConversationMode ? "conversation" : "conversation_list",
                        folder.getTypeDescription(), unseenCount);

                if (notificationIntent == null) {
                    LogUtils.e(LOG_TAG, "Null intent when building notification");
                    return;
                }

                // Amend the click intent with a hint that its source was a notification,
                // but remove the hint before it's used to generate notification action
                // intents. This prevents the following sequence:
                // 1. generate single notification
                // 2. user clicks reply, then completes Compose activity
                // 3. main activity launches, gets FROM_NOTIFICATION hint in intent
                notificationIntent.putExtra(Utils.EXTRA_FROM_NOTIFICATION, true);
                clickIntent = PendingIntent.getActivity(context, -1, notificationIntent,
                        PendingIntent.FLAG_UPDATE_CURRENT);
                notificationIntent.removeExtra(Utils.EXTRA_FROM_NOTIFICATION);

                title = NotificationUtils.configureLatestEventInfoFromConversation(context,
                        account, folderPreferences, notification, wearableExtender,
                        msgNotifications, notificationId, cursor, clickIntent, notificationIntent,
                        unreadCount, unseenCount, folder, when, photoFetcher, isVip);
                eventInfoConfigured = true;
            }
        }

        /**M: repeat alert when mark message unread on another device @{*/
        boolean vibrate = false;
        String ringtoneUri = null;
        if (isVip) {
            vibrate = VipPreferences.get(context).getVipVebarate();
            ringtoneUri = VipPreferences.get(context).getVipRingtone();
        } else {
            vibrate = folderPreferences.isNotificationVibrateEnabled();
            ringtoneUri = folderPreferences.getNotificationRingtoneUri();
        }
        if (newMsgId <= folder.lastNotifiedMsgKey) {
            vibrate = false;
            ringtoneUri = null;
        }
        /**@}*/
        final boolean notifyOnce = !folderPreferences.isEveryMessageNotificationEnabled();

        if (!ignoreUnobtrusiveSetting && notifyOnce) {
            // If the user has "unobtrusive notifications" enabled, only alert the first time
            // new mail is received in this account.  This is the default behavior.  See
            // bugs 2412348 and 2413490.
            notification.setOnlyAlertOnce(true);
        }

        LogUtils.i(LOG_TAG, "Account: %s vibrate: %s",
                LogUtils.sanitizeName(LOG_TAG, account.getDisplayName()),
                Boolean.toString(folderPreferences.isNotificationVibrateEnabled()));

        int defaults = 0;

        /*
         * We do not want to notify if this is coming back from an Undo notification, hence the
         * oldWhen check.
         */
        if (getAttention && oldWhen == 0) {
            final AccountPreferences accountPreferences =
                    new AccountPreferences(context,
                            /*M: should use account address to get preference not name*/
                            account.getEmailAddress());
            if (accountPreferences.areNotificationsEnabled()) {
                if (vibrate) {
                    defaults |= Notification.DEFAULT_VIBRATE;
                }

                notification.setSound(TextUtils.isEmpty(ringtoneUri) ? null
                        : Uri.parse(ringtoneUri));
                LogUtils.i(LOG_TAG, "New email in %s vibrateWhen: %s, playing notification: %s",
                        LogUtils.sanitizeName(LOG_TAG, account.getDisplayName()), vibrate, ringtoneUri);
            }
        }

        // TODO(skennedy) Why do we do any of the above if we're just going to bail here?
        if (eventInfoConfigured) {
            defaults |= Notification.DEFAULT_LIGHTS;
            notification.setDefaults(defaults);

            if (oldWhen != 0) {
                // We do not want to display the ticker again if we are re-displaying this
                // notification (like from an Undo notification)
                notification.setTicker(null);
            }

            notification.extend(wearableExtender);
            Notification notificationInstance = notification.build();
            if (isVip) {
                VipNotificationStyle vipNotificationStyle = new VipNotificationStyle();
                vipNotificationStyle.addVipTitle(title);
                vipNotificationStyle.updateVipIcon(context, notificationInstance);

            }

            NotificationManagerCompat nm = NotificationManagerCompat.from(context);
            nm.notify(notificationId, notificationInstance);
        } else {
            LogUtils.i(LOG_TAG, "event info not configured - not notifying");
        }
    }


    /**
     * @return an {@link Intent} which, if launched, will display the corresponding conversation
     */
    private static Intent createViewConversationIntent(final Context context, final Account account,
            final Uri folderUri, final Cursor cursor) {
        if (folderUri == null || account == null) {
            LogUtils.e(LOG_TAG, "createViewConversationIntent(): "
                    + "Null account or folder.  account: %s folder: %s", account, folderUri);
            return null;
        }

        final Intent intent;

        if (cursor == null) {
            intent = Utils.createViewFolderIntent(context, folderUri, account);
        } else {
            // A conversation cursor has been specified, so this intent is intended to be go
            // directly to the one new conversation

            // Get the Conversation object
            final Conversation conversation = new Conversation(cursor);
            intent = Utils.createViewConversationIntent(context, conversation,
                    folderUri, account);
        }

        return intent;
    }

    /// M: create undoable Vip Notification for VIP feature
    public static void createUndoVipNotification(final Context context,
            final NotificationAction notificationAction) {
        LogUtils.i(LOG_TAG, "createUndoNotification for %s",
                notificationAction.getNotificationActionType());

        final int notificationId = VipNotificationUtils.getVipNotificationId(
                notificationAction.getAccount().getAccountManagerAccount(),
                notificationAction.getFolder());

        final Notification notification =
                NotificationActionUtils.createUndoNotification(context, notificationAction, notificationId);

        final NotificationManagerCompat notificationManager = NotificationManagerCompat
                .from(context);
        notificationManager.notify(notificationId, notification);

        NotificationActionUtils.sUndoNotifications.put(notificationId, notificationAction);
        NotificationActionUtils.sNotificationTimestamps.put(notificationId, notificationAction.getWhen());
    }

    /** M: use for separating the message into two group @{ */
    private static class VipFilterCursorWrapper extends CursorWrapper {
        public static enum Filter_Mode {
            // default mode. Doesn't distinguish VIP from common notifications
            MOD_NORMAL,
            // Filter mode
            MOD_VIP,
            MOD_NO_VIP
        }
        public static enum Type_Count {
            TYPE_NON_VIP,
            TYPE_VIP
        }

        public VipFilterCursorWrapper(Cursor cursor, Filter_Mode mode) {
            super(cursor);
            mCursorMode = mode;
            mPos = -1;
            if (mode == Filter_Mode.MOD_VIP || mode == Filter_Mode.MOD_NO_VIP) {
                filterMessage();
            } else {
                mSize = cursor.getCount();
            }
        }

        public void filterMessage() {
            int i = 0;
            super.moveToPosition(-1);
            while (super.moveToNext()) {
                String fromList = super
                        .getString(UIProvider.CONVERSATION_SENDER_INFO_COLUMN);
                if (VipMemberCache.isVIP(fromList)) {
                    mVipListPos.add(i++);
                } else {
                    mNonVipListPos.add(i++);
                }
            }
            mIsFiltered = true;
            if (mCursorMode == Filter_Mode.MOD_VIP) {
                mSize = mVipListPos.size();
            } else if (mCursorMode == Filter_Mode.MOD_NO_VIP) {
                mSize = mNonVipListPos.size();
            } else {
                mSize = super.getCount();
            }
        }

        public VipFilterCursorWrapper setMode(Filter_Mode mode) {
            mPos = -1;
            mCursorMode = mode;
            if (!mIsFiltered
                    && (mode == Filter_Mode.MOD_VIP
                    || mode == Filter_Mode.MOD_NO_VIP)) {
                filterMessage();
            } else if (mode == Filter_Mode.MOD_VIP) {
                mSize = mVipListPos.size();
            } else if (mode == Filter_Mode.MOD_NO_VIP) {
                mSize = mNonVipListPos.size();
            } else if (mode == Filter_Mode.MOD_NORMAL) {
                mSize = super.getCount();
            }
            return this;
        }

        @Override
        public final int getCount() {
            return mSize;
        }

        public Filter_Mode getCursorMode() {
            return mCursorMode;
        }

        public final int getCount(Type_Count type) {
            if (type == Type_Count.TYPE_VIP) {
                return mVipListPos.size();
            } else if (type == Type_Count.TYPE_NON_VIP) {
                return mNonVipListPos.size();
            } else {
                return super.getCount();
            }
        }

        @Override
        public boolean moveToPosition(int pos) {
            boolean moved = false;
            if (pos >= mSize) {
                return false;
            } else if (pos < 0) {
                moved = super.moveToPosition(pos);
            } else {
                if (mCursorMode == Filter_Mode.MOD_VIP) {
                    moved = super.moveToPosition(mVipListPos.get(pos));
                } else if (mCursorMode == Filter_Mode.MOD_NO_VIP) {
                    moved = super.moveToPosition(mNonVipListPos.get(pos));
                } else {
                    moved = super.moveToPosition(pos);
                }
                if (moved) {
                    mPos = pos;
                }
            }
            return moved;
        }

        @Override
        public final boolean moveToNext() {
            return moveToPosition(mPos + 1);
        }

        @Override
        public final boolean moveToFirst() {
            return moveToPosition(0);
        }

        @Override
        public final boolean moveToPrevious() {
            return moveToPosition(mPos - 1);
        }

        public int mSize;
        private int mPos;
        private Filter_Mode mCursorMode;
        private boolean mIsFiltered;
        private ArrayList<Integer> mVipListPos = new ArrayList<Integer>();
        private ArrayList<Integer> mNonVipListPos = new ArrayList<Integer>();
    }
    /** @} */
}
