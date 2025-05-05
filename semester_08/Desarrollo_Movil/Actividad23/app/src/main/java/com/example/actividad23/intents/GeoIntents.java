package com.example.actividad23.intents;

import android.content.Intent;
import android.net.Uri;

/**
 * Provides factory methods to create intents to work with geographical data (search locations for instance)
 *
 * @author Vincent Prat @ MarvinLabs
 */
public class GeoIntents {

    /**
     * Intent that should allow opening a map showing the given address (if it exists)
     *
     * @param address    The address to search
     * @param placeTitle The title to show on the marker
     * @return the intent
     */
    public static Intent newMapsIntent(String address, String placeTitle) {
        StringBuilder sb = new StringBuilder();
        sb.append("geo:0,0?q=");

        String addressEncoded = Uri.encode(address);
        sb.append(addressEncoded);

        // pass text for the info window
        String titleEncoded = Uri.encode(" (" + placeTitle + ")");
        sb.append(titleEncoded);

        return new Intent(Intent.ACTION_VIEW, Uri.parse(sb.toString()));
    }

    /**
     * Intent that should allow opening a map showing the given location (if it exists)
     *
     * @param latitude  The latitude of the center of the map
     * @param longitude The longitude of the center of the map
     * @return the intent
     */
    public static Intent newMapsIntent(float latitude, float longitude) {
        StringBuilder sb = new StringBuilder();
        sb.append("geo:");

        sb.append(latitude);
        sb.append(",");
        sb.append(longitude);

        return new Intent(Intent.ACTION_VIEW, Uri.parse(sb.toString()));
    }

    /**
     * Intent that should allow opening a map showing the given address (if it exists)
     *
     * @param address    The address to search
     * @param placeTitle The title to show on the marker
     * @return the intent
     */
    public static Intent newNavigationIntent(String address) {
        StringBuilder sb = new StringBuilder();
        sb.append("google.navigation:q=");

        String addressEncoded = Uri.encode(address);
        sb.append(addressEncoded);

        return new Intent(Intent.ACTION_VIEW, Uri.parse(sb.toString()));
    }

    /**
     * Intent that should allow opening a map showing the given location (if it exists)
     *
     * @param latitude  The latitude of the center of the map
     * @param longitude The longitude of the center of the map
     * @return the intent
     */
    public static Intent newNavigationIntent(float latitude, float longitude) {
        StringBuilder sb = new StringBuilder();
        sb.append("google.navigation:q=");

        sb.append(latitude);
        sb.append(",");
        sb.append(longitude);

        return new Intent(Intent.ACTION_VIEW, Uri.parse(sb.toString()));
    }
}