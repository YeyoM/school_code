package com.example.actividad23.intents;

import android.content.Intent;
import android.net.Uri;
import android.provider.MediaStore;

import java.io.File;

/**
 * Provides factory methods to create intents to view / open / ... medias
 *
 * @author Vincent Prat @ MarvinLabs
 */
public class MediaIntents {

    /**
     * Open the video player to play the given
     *
     * @param url The URL of the video to play.
     * @return the intent
     */
    public static Intent newPlayVideoIntent(String url) {
        Intent intent = new Intent(Intent.ACTION_VIEW);
        intent.setDataAndType(Uri.parse(url), "video/*");
        return intent;
    }

    /**
     * Creates an intent that will launch a browser (most probably as other apps may handle specific URLs, e.g. YouTube)
     * to view the provided URL.
     *
     * @param url the URL to open
     * @return the intent
     */
    public static Intent newOpenWebBrowserIntent(String url) {
        if (!url.startsWith("https://") && !url.startsWith("http://")) {
            url = "http://" + url;
        }
        Intent intent = new Intent(Intent.ACTION_VIEW, Uri.parse(url));
        return intent;
    }

    /**
     * Creates an intent that will launch the camera to take a picture that's saved to a temporary file so you can use
     * it directly without going through the gallery.
     *
     * @param tempFile the file that should be used to temporarily store the picture
     * @return the intent
     */
    public static Intent newTakePictureIntent(File tempFile) {
        Intent intent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
        intent.putExtra(MediaStore.EXTRA_OUTPUT, Uri.fromFile(tempFile));
        return intent;
    }

    /**
     * Creates an intent that will launch the camera to take a picture that's saved to a temporary file so you can use
     * it directly without going through the gallery.
     *
     * @param tempFile the file that should be used to temporarily store the picture
     * @return the intent
     */
    public static Intent newTakePictureIntent(String tempFile) {
        Intent intent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
        intent.putExtra(MediaStore.EXTRA_OUTPUT, Uri.fromFile(new File(tempFile)));
        return intent;
    }

    /**
     * Creates an intent that will launch the phone's picture gallery to select a picture from it.
     *
     * @return the intent
     */
    public static Intent newSelectPictureIntent() {
        Intent intent = new Intent(Intent.ACTION_PICK);
        intent.setType("image/*");
        return intent;
    }
}