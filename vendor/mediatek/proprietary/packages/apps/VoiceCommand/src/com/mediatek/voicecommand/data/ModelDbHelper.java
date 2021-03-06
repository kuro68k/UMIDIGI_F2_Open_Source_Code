/**
 * Copyright (C) 2014 The Android Open Source Project
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

package com.mediatek.voicecommand.data;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.hardware.soundtrigger.SoundTrigger;
import android.hardware.soundtrigger.SoundTrigger.Keyphrase;
import android.hardware.soundtrigger.SoundTrigger.KeyphraseSoundModel;
import android.text.TextUtils;

import com.mediatek.voicecommand.cfg.VoiceModelInfo;
import com.mediatek.voicecommand.util.Log;

import java.util.Arrays;
import java.util.List;
import java.util.Locale;
import java.util.UUID;

/**
 * Helper to manage the database of the sound models that have been registered on the device.
 *
 * @hide
 */
public class ModelDbHelper extends SQLiteOpenHelper {
    static final String TAG = "ModelDBHelper";
    static final boolean DBG = true;

    private static final String NAME = "keyphrase_model.db";
    private static final int VERSION = 1;

    public static interface SoundModelContract {
        public static final String TABLE = "sound_model";
        public static final String KEY_MODEL_UUID = "model_uuid";
        public static final String KEY_VENDOR_UUID = "vendor_uuid";
        public static final String KEY_KEYPHRASE_ID = "keyphrase_id";
        public static final String KEY_TYPE = "type";
        public static final String KEY_DATA = "data";
        public static final String KEY_RECOGNITION_MODES = "recognition_modes";
        public static final String KEY_LOCALE = "locale";
        public static final String KEY_HINT_TEXT = "hint_text";
        public static final String KEY_USERS = "users";
    }

    // Table Create Statement
    private static final String CREATE_TABLE_SOUND_MODEL = "CREATE TABLE "
            + SoundModelContract.TABLE + "("
            + SoundModelContract.KEY_MODEL_UUID + " TEXT,"
            + SoundModelContract.KEY_VENDOR_UUID + " TEXT,"
            + SoundModelContract.KEY_KEYPHRASE_ID + " INTEGER,"
            + SoundModelContract.KEY_TYPE + " INTEGER,"
            + SoundModelContract.KEY_DATA + " BLOB,"
            + SoundModelContract.KEY_RECOGNITION_MODES + " INTEGER,"
            + SoundModelContract.KEY_LOCALE + " TEXT,"
            + SoundModelContract.KEY_HINT_TEXT + " TEXT,"
            + SoundModelContract.KEY_USERS + " TEXT,"
            + "PRIMARY KEY (" + SoundModelContract.KEY_KEYPHRASE_ID + ","
                              + SoundModelContract.KEY_LOCALE + ","
                              + SoundModelContract.KEY_USERS + ")"
            + ")";

    public ModelDbHelper(Context context) {
        super(context, NAME, null, VERSION);
        if (DBG) {
            Log.w(TAG, "ModelDbHelper");
        }
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        // creating required tables
        db.execSQL(CREATE_TABLE_SOUND_MODEL);
        db.execSQL(CREATE_TABLE_VOICE_MODEL);
        if (DBG) {
            Log.w(TAG, "ModelDbHelper, onCreate=" + db.getPath());
        }
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        Log.i(TAG, "onUpgrade: oldVersion=" + oldVersion + " newVersion=" + newVersion);
    }

    /**
     * Updates the given keyphrase model, adds it, if it doesn't already exist.
     *
     * TODO: We only support one keyphrase currently.
     */
    public boolean updateKeyphraseSoundModel(KeyphraseSoundModel soundModel) {
        synchronized(this) {
            SQLiteDatabase db = getWritableDatabase();
            ContentValues values = new ContentValues();
            values.put(SoundModelContract.KEY_MODEL_UUID, soundModel.uuid.toString());
            if (soundModel.vendorUuid != null) {
                values.put(SoundModelContract.KEY_VENDOR_UUID, soundModel.vendorUuid.toString());
            }
            values.put(SoundModelContract.KEY_TYPE, SoundTrigger.SoundModel.TYPE_KEYPHRASE);
            values.put(SoundModelContract.KEY_DATA, soundModel.data);

            if (soundModel.keyphrases != null && soundModel.keyphrases.length == 1) {
                values.put(SoundModelContract.KEY_KEYPHRASE_ID, soundModel.keyphrases[0].id);
                values.put(SoundModelContract.KEY_RECOGNITION_MODES,
                        soundModel.keyphrases[0].recognitionModes);
                values.put(SoundModelContract.KEY_USERS,
                        getCommaSeparatedString(soundModel.keyphrases[0].users));
                values.put(SoundModelContract.KEY_LOCALE, soundModel.keyphrases[0].locale);
                values.put(SoundModelContract.KEY_HINT_TEXT, soundModel.keyphrases[0].text);
                try {
                    return db.insertWithOnConflict(SoundModelContract.TABLE, null, values,
                            SQLiteDatabase.CONFLICT_REPLACE) != -1;
                } finally {
                    db.close();
                }
            }
            return false;
        }
    }

    /**
     * Deletes the sound model and associated keyphrases.
     */
    public boolean deleteKeyphraseSoundModel(int keyphraseId, int userHandle, String bcp47Locale) {
        // Sanitize the locale to guard against SQL injection.
        bcp47Locale = Locale.forLanguageTag(bcp47Locale).toLanguageTag();
        synchronized(this) {
            KeyphraseSoundModel soundModel = getKeyphraseSoundModel(keyphraseId, userHandle,
                    bcp47Locale);
            if (soundModel == null) {
                return false;
            }

            // Delete all sound models for the given keyphrase and specified user.
            SQLiteDatabase db = getWritableDatabase();
            String soundModelClause = SoundModelContract.KEY_MODEL_UUID
                    + "='" + soundModel.uuid.toString() + "'";
            try {
                return db.delete(SoundModelContract.TABLE, soundModelClause, null) != 0;
            } finally {
                db.close();
            }
        }
    }

    /**
     * Returns a matching {@link KeyphraseSoundModel} for the keyphrase ID.
     * Returns null if a match isn't found.
     *
     * TODO: We only support one keyphrase currently.
     */
    public KeyphraseSoundModel getKeyphraseSoundModel(int keyphraseId, int userHandle,
            String locale) {
        // Sanitize the locale to guard against SQL injection.
        locale = Locale.forLanguageTag(locale).toLanguageTag();
        synchronized(this) {
            // Find the corresponding sound model ID for the keyphrase.
            String selectQuery = "SELECT  * FROM " + SoundModelContract.TABLE
                    + " WHERE " + SoundModelContract.KEY_KEYPHRASE_ID + "= '" + keyphraseId
                    + "' AND " + SoundModelContract.KEY_LOCALE + "='" + locale + "'";
            SQLiteDatabase db = getReadableDatabase();
            Cursor c = db.rawQuery(selectQuery, null);

            try {
                if (c.moveToFirst()) {
                    do {
                        int type = c.getInt(c.getColumnIndex(SoundModelContract.KEY_TYPE));
                        if (type != SoundTrigger.SoundModel.TYPE_KEYPHRASE) {
                            if (DBG) {
                                Log.w(TAG, "Ignoring SoundModel since it's type is incorrect");
                            }
                            continue;
                        }

                        String modelUuid = c.getString(
                                c.getColumnIndex(SoundModelContract.KEY_MODEL_UUID));
                        if (modelUuid == null) {
                            Log.w(TAG, "Ignoring SoundModel since it doesn't specify an ID");
                            continue;
                        }

                        String vendorUuidString = null;
                        int vendorUuidColumn = c.getColumnIndex(SoundModelContract.KEY_VENDOR_UUID);
                        if (vendorUuidColumn != -1) {
                            vendorUuidString = c.getString(vendorUuidColumn);
                        }
                        byte[] data = c.getBlob(c.getColumnIndex(SoundModelContract.KEY_DATA));
                        int recognitionModes = c.getInt(
                                c.getColumnIndex(SoundModelContract.KEY_RECOGNITION_MODES));
                        int[] users = getArrayForCommaSeparatedString(
                                c.getString(c.getColumnIndex(SoundModelContract.KEY_USERS)));
                        String modelLocale = c.getString(
                                c.getColumnIndex(SoundModelContract.KEY_LOCALE));
                        String text = c.getString(
                                c.getColumnIndex(SoundModelContract.KEY_HINT_TEXT));

                        // Only add keyphrases meant for the current user.
                        if (users == null) {
                            // No users present in the keyphrase.
                            Log.w(TAG, "Ignoring SoundModel since it doesn't specify users");
                            continue;
                        }

                        boolean isAvailableForCurrentUser = false;
                        for (int user : users) {
                            if (userHandle == user) {
                                isAvailableForCurrentUser = true;
                                break;
                            }
                        }
                        if (!isAvailableForCurrentUser) {
                            if (DBG) {
                                Log.w(TAG, "Ignoring SoundModel since user handles don't match");
                            }
                            continue;
                        } else {
                            if (DBG) Log.d(TAG, "Found a SoundModel for user: " + userHandle);
                        }

                        Keyphrase[] keyphrases = new Keyphrase[1];
                        keyphrases[0] = new Keyphrase(
                                keyphraseId, recognitionModes, modelLocale, text, users);
                        UUID vendorUuid = null;
                        if (vendorUuidString != null) {
                            vendorUuid = UUID.fromString(vendorUuidString);
                        }
                        KeyphraseSoundModel model = new KeyphraseSoundModel(
                                UUID.fromString(modelUuid), vendorUuid, data, keyphrases);
                        if (DBG) {
                            Log.d(TAG, "Found SoundModel for the given keyphrase/locale/user: "
                                    + model);
                        }
                        return model;
                    } while (c.moveToNext());
                }
                Log.w(TAG, "No SoundModel available for the given keyphrase");
            } finally {
                c.close();
                db.close();
            }
            return null;
        }
    }

    private static String getCommaSeparatedString(int[] users) {
        if (users == null) {
            return "";
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < users.length; i++) {
            if (i != 0) {
                sb.append(',');
            }
            sb.append(users[i]);
        }
        return sb.toString();
    }

    private static int[] getArrayForCommaSeparatedString(String text) {
        if (TextUtils.isEmpty(text)) {
            return null;
        }
        String[] usersStr = text.split(",");
        int[] users = new int[usersStr.length];
        for (int i = 0; i < usersStr.length; i++) {
            users[i] = Integer.parseInt(usersStr[i]);
        }
        return users;
    }

    private static class SoundModelRecord {
        public final String modelUuid;
        public final String vendorUuid;
        public final int keyphraseId;
        public final int type;
        public final byte[] data;
        public final int recognitionModes;
        public final String locale;
        public final String hintText;
        public final String users;

        public SoundModelRecord(int version, Cursor c) {
            modelUuid = c.getString(c.getColumnIndex(SoundModelContract.KEY_MODEL_UUID));
            vendorUuid = c.getString(c.getColumnIndex(SoundModelContract.KEY_VENDOR_UUID));
            keyphraseId = c.getInt(c.getColumnIndex(SoundModelContract.KEY_KEYPHRASE_ID));
            type = c.getInt(c.getColumnIndex(SoundModelContract.KEY_TYPE));
            data = c.getBlob(c.getColumnIndex(SoundModelContract.KEY_DATA));
            recognitionModes = c.getInt(c.getColumnIndex(SoundModelContract.KEY_RECOGNITION_MODES));
            locale = c.getString(c.getColumnIndex(SoundModelContract.KEY_LOCALE));
            hintText = c.getString(c.getColumnIndex(SoundModelContract.KEY_HINT_TEXT));
            users = c.getString(c.getColumnIndex(SoundModelContract.KEY_USERS));
        }

        private boolean V6PrimaryKeyMatches(SoundModelRecord record) {
          return keyphraseId == record.keyphraseId && stringComparisonHelper(locale, record.locale)
              && stringComparisonHelper(users, record.users);
        }

        // Returns true if this record is a) the only record with the same V6 primary key, or b) the
        // first record in the list of all records that have the same primary key and equal data.
        // It will return false if a) there are any records that have the same primary key and
        // different data, or b) there is a previous record in the list that has the same primary
        // key and data.
        // Note that 'this' object must be inside the list.
        public boolean ifViolatesV6PrimaryKeyIsFirstOfAnyDuplicates(
                List<SoundModelRecord> records) {
            // First pass - check to see if all the records that have the same primary key have
            // duplicated data.
            for (SoundModelRecord record : records) {
                if (this == record) {
                    continue;
                }
                // If we have different/missing data with the same primary key, then we should drop
                // everything.
                if (this.V6PrimaryKeyMatches(record) && !Arrays.equals(data, record.data)) {
                    return false;
                }
            }

            // We only want to return true for the first duplicated model.
            for (SoundModelRecord record : records) {
                if (this.V6PrimaryKeyMatches(record)) {
                    return this == record;
                }
            }
            return true;
        }

        public long writeToDatabase(int version, SQLiteDatabase db) {
            ContentValues values = new ContentValues();
            values.put(SoundModelContract.KEY_MODEL_UUID, modelUuid);
            values.put(SoundModelContract.KEY_VENDOR_UUID, vendorUuid);
            values.put(SoundModelContract.KEY_KEYPHRASE_ID, keyphraseId);
            values.put(SoundModelContract.KEY_TYPE, type);
            values.put(SoundModelContract.KEY_DATA, data);
            values.put(SoundModelContract.KEY_RECOGNITION_MODES, recognitionModes);
            values.put(SoundModelContract.KEY_LOCALE, locale);
            values.put(SoundModelContract.KEY_HINT_TEXT, hintText);
            values.put(SoundModelContract.KEY_USERS, users);

            return db.insertWithOnConflict(
                       SoundModelContract.TABLE, null, values, SQLiteDatabase.CONFLICT_REPLACE);
        }

        // Helper for checking string equality - including the case when they are null.
        static private boolean stringComparisonHelper(String a, String b) {
          if (a != null) {
            return a.equals(b);
          }
          return a == b;
        }
    }

    //====================================MTK enhance voice model=========================//

    public static interface VoiceModelContract {
        public static final String TABLE = "voice_model";
        public static final String KEY_PACKAGE_NAME = "package_name";
        public static final String KEY_LOCALE = "locale";
        public static final String KEY_FILE_NAME = "file_name";
        public static final String KEY_ABS_PATH = "abs_path";
        public static final String KEY_STAGE_NO = "stage_no";
        public static final String KEY_VERSION = "version";
        public static final String KEY_DEFAULT = "default_model";
        public static final String KEY_DATA = "data";
        public static final String KEY_HINT_TEXT = "hint_text";
    }

    // Table Create Statement
    private static final String CREATE_TABLE_VOICE_MODEL = "CREATE TABLE "
            + VoiceModelContract.TABLE + "("
            + VoiceModelContract.KEY_PACKAGE_NAME + " TEXT,"
            + VoiceModelContract.KEY_LOCALE + " TEXT,"
            + VoiceModelContract.KEY_FILE_NAME + " TEXT,"
            + VoiceModelContract.KEY_ABS_PATH + " TEXT,"
            + VoiceModelContract.KEY_STAGE_NO + " INTEGER,"
            + VoiceModelContract.KEY_VERSION + " INTEGER,"
            + VoiceModelContract.KEY_DEFAULT + " INTEGER,"
            + VoiceModelContract.KEY_DATA + " BLOB,"
            + VoiceModelContract.KEY_HINT_TEXT + " TEXT,"
            + "PRIMARY KEY (" + VoiceModelContract.KEY_FILE_NAME + ","
                              + VoiceModelContract.KEY_LOCALE + ","
                              + VoiceModelContract.KEY_ABS_PATH + ")"
            + ")";

    public boolean addVoiceModel(VoiceModelInfo info, boolean isNeedSaveData) {
        return updateVoiceModel(info, isNeedSaveData);
    }

    public boolean deleteVoiceModel(VoiceModelInfo info) {
        synchronized(this) {
            SQLiteDatabase db = getWritableDatabase();
            String modelClause = VoiceModelContract.KEY_FILE_NAME
                    + "='" + info.mFileName + "' AND " + VoiceModelContract.KEY_ABS_PATH
                    + "='" + info.mFolder + "'";
            try {
                return db.delete(VoiceModelContract.TABLE, modelClause, null) != 0;
            } finally {
                db.close();
            }
        }
    }

    public boolean updateVoiceModel(VoiceModelInfo info, boolean isNeedSaveData) {
        synchronized(this) {
            SQLiteDatabase db = getWritableDatabase();
            ContentValues values = new ContentValues();
            values.put(VoiceModelContract.KEY_PACKAGE_NAME, info.mPackageName);
            values.put(VoiceModelContract.KEY_LOCALE, info.mLocale);
            values.put(VoiceModelContract.KEY_FILE_NAME, info.mFileName);
            values.put(VoiceModelContract.KEY_ABS_PATH, info.getResPath());
            values.put(VoiceModelContract.KEY_STAGE_NO, info.mStageNo);
            values.put(VoiceModelContract.KEY_VERSION, info.mVersion);
            values.put(VoiceModelContract.KEY_DEFAULT, info.mDefault ? 1 : 0);
            if (isNeedSaveData) {
                values.put(VoiceModelContract.KEY_DATA, info.mData);
            }
            values.put(VoiceModelContract.KEY_HINT_TEXT, "");
            try {
                return db.insertWithOnConflict(VoiceModelContract.TABLE, null, values,
                        SQLiteDatabase.CONFLICT_REPLACE) != -1;
            } finally {
                db.close();
            }
        }
    }

    public boolean hasVoiceModelByLocale(int userHandler, String locale) {
        String selectQuery = "SELECT * FROM " + VoiceModelContract.TABLE
                + " WHERE " + VoiceModelContract.KEY_LOCALE + "='" + locale + "'";
        synchronized(this) {
            SQLiteDatabase db = getReadableDatabase();
            Cursor c = db.rawQuery(selectQuery, null);
            try {
                if (c.moveToFirst()) {
                    do {
                        int version = c.getInt(c.getColumnIndex(VoiceModelContract.KEY_VERSION));
                        if (version > 0) {
                            return true;
                        }
                    } while (c.moveToNext());
                }
            } finally {
                c.close();
                db.close();
            }
        }
        return false;
    }

    public int getVoiceModelVersion(VoiceModelInfo info) {
        String selectQuery = "SELECT * FROM " + VoiceModelContract.TABLE
                + " WHERE " + VoiceModelContract.KEY_FILE_NAME + "='" + info.mFileName
                + "' AND " + VoiceModelContract.KEY_ABS_PATH + "='" + info.getResPath()
                + "' AND " + VoiceModelContract.KEY_LOCALE + "='" + info.mLocale + "'";
        synchronized(this) {
            SQLiteDatabase db = getReadableDatabase();
            Cursor c = db.rawQuery(selectQuery, null);
            try {
                if (c.moveToFirst()) {
                    do {
                        int version = c.getInt(c.getColumnIndex(VoiceModelContract.KEY_VERSION));
                        return version;
                    } while (c.moveToNext());
                }
            } finally {
                c.close();
                db.close();
            }
        }
        return 0;
    }

    public byte[] getVoiceModelData(String locale, int stage) {
        String selectQuery = "SELECT  * FROM " + VoiceModelContract.TABLE
                + " WHERE " + VoiceModelContract.KEY_STAGE_NO + "='" + stage
                + "' AND " + VoiceModelContract.KEY_LOCALE + "='" + locale + "'";
        synchronized(this) {
            SQLiteDatabase db = getReadableDatabase();
            Cursor c = db.rawQuery(selectQuery, null);
            try {
                if (c.moveToFirst()) {
                    do {
                        byte[] data = c.getBlob(c.getColumnIndex(VoiceModelContract.KEY_DATA));
                        return data;
                    } while (c.moveToNext());
                }
            } finally {
                c.close();
                db.close();
            }
        }
        return null;
    }
}
