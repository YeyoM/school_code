package com.example.actividad23.intents;

import android.content.Context;
import android.content.Intent;
import android.net.Uri;

/**
 * Provides factory methods to create intents to do some system tasks such as opening the market app, ...
 *
 * @author Vincent Prat @ MarvinLabs
 */
public class SystemIntents {

    /**
     * Intent that should open the app store of the device on the current application page
     *
     * @param context The context associated to the application
     * @return the intent
     */
    public static Intent newMarketForAppIntent(Context context) {
        String packageName = context.getApplicationContext().getPackageName();
        return newMarketForAppIntent(context, packageName);
    }

    /**
     * Intent that should open the app store of the device on the given application
     *
     * @param context     The context associated to the application
     * @param packageName The package name of the application to find on the market
     * @return the intent or null if no market is available for the intent
     */
    public static Intent newMarketForAppIntent(Context context, String packageName) {
        Intent intent = new Intent(Intent.ACTION_VIEW, Uri.parse("market://details?id=" + packageName));

        if (!IntentUtils.isIntentAvailable(context, intent)) {
            intent = new Intent(Intent.ACTION_VIEW, Uri.parse("amzn://apps/android?p=" + packageName));
        }

        if (!IntentUtils.isIntentAvailable(context, intent)) {
            intent = null;
        }

        if (intent != null) {
            intent.addFlags(Intent.FLAG_ACTIVITY_NO_HISTORY | Intent.FLAG_ACTIVITY_CLEAR_WHEN_TASK_RESET);
        }

        return intent;
    }

    /**
     * Intent that should open either the Google Play app or if not available, the web browser on the Google Play website
     *
     * @param context     The context associated to the application
     * @param packageName The package name of the application to find on the market
     * @return the intent for native application or an intent to redirect to the browser if google play is not installed
     */
    public static Intent newGooglePlayIntent(Context context, String packageName) {
        Intent intent = new Intent(Intent.ACTION_VIEW, Uri.parse("market://details?id=" + packageName));

        if (!IntentUtils.isIntentAvailable(context, intent)) {
            intent = MediaIntents.newOpenWebBrowserIntent("https://play.google.com/store/apps/details?id="
                    + packageName);
        }

        if (intent != null) {
            intent.addFlags(Intent.FLAG_ACTIVITY_NO_HISTORY | Intent.FLAG_ACTIVITY_CLEAR_WHEN_TASK_RESET);
        }

        return intent;
    }

    /**
     * Intent that should open either the Amazon store app or if not available, the web browser on the Amazon website
     *
     * @param context     The context associated to the application
     * @param packageName The package name of the application to find on the market
     * @return the intent for native application or an intent to redirect to the browser if google play is not installed
     */
    public static Intent newAmazonStoreIntent(Context context, String packageName) {
        Intent intent = new Intent(Intent.ACTION_VIEW, Uri.parse("amzn://apps/android?p=" + packageName));

        if (!IntentUtils.isIntentAvailable(context, intent)) {
            intent = MediaIntents.newOpenWebBrowserIntent("http://www.amazon.com/gp/mas/dl/android?p="
                    + packageName);
        }

        if (intent != null) {
            intent.addFlags(Intent.FLAG_ACTIVITY_NO_HISTORY | Intent.FLAG_ACTIVITY_CLEAR_WHEN_TASK_RESET);
        }

        return intent;
    }
}