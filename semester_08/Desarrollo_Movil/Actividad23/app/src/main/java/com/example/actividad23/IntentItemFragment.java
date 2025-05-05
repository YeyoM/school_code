package com.example.actividad23;

import android.app.Activity;
import android.content.Intent;
import android.content.res.Resources;
import android.os.Bundle;
import android.os.Environment;
import androidx.fragment.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AbsListView;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListAdapter;
import android.widget.TextView;

import com.example.actividad23.intents.EmailIntents;
import com.example.actividad23.intents.GeoIntents;
import com.example.actividad23.intents.MediaIntents;
import com.example.actividad23.intents.PhoneIntents;
import com.example.actividad23.intents.ShareIntents;
import com.example.actividad23.intents.SystemIntents;

import java.util.ArrayList;
import java.util.List;
import android.content.Context;

/**
 * A fragment representing a list of Intents.
 */
public class IntentItemFragment extends Fragment implements AbsListView.OnItemClickListener {

    private OnFragmentInteractionListener mListener;
   // The fragment's ListView/GridView
    private AbsListView mListView;
    // The Adapter which will be used to populate the ListView/GridView with Views.
    private ListAdapter mAdapter;
    public static IntentItemFragment newInstance() {
        return new IntentItemFragment();
    }
    /**
     * Mandatory empty constructor for the fragment manager to instantiate the
     * fragment (e.g. upon screen orientation changes).
     */
    public IntentItemFragment() {
    }
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        final Resources res = getResources();
        final List<DemoItem> intents = new ArrayList<DemoItem>();

        // PhoneIntents
        intents.add(new DemoItem(res.getString(R.string.dialer),      PhoneIntents.newDialNumberIntent(null)));
        intents.add(new DemoItem(res.getString(R.string.call_number), PhoneIntents.newCallNumberIntent("+123456789")));
        intents.add(new DemoItem(res.getString(R.string.dial_number), PhoneIntents.newDialNumberIntent("+123456789")));
      //  intents.add(new DemoItem(res.getString(R.string.send_sms_to), PhoneIntents.newSmsIntent(getActivity(), "this is a test SMS", "+123456789")));
      //  intents.add(new DemoItem(res.getString(R.string.send_sms),     PhoneIntents.newSmsIntent(getActivity(), "this is a test SMS")));
       // intents.add(new DemoItem(res.getString(R.string.pick_contact), PhoneIntents.newPickContactIntent()));
       // intents.add(new DemoItem(res.getString(R.string.pick_contact_with_phone), PhoneIntents.newPickContactWithPhoneIntent()));

        // GeoIntents
        intents.add(new DemoItem(res.getString(R.string.map_of), GeoIntents.newMapsIntent("1 rue du louvre 75000 Paris", "Le Louvre, Paris")));
      //  intents.add(new DemoItem(res.getString(R.string.map_at), GeoIntents.newMapsIntent(43.481055f, -1.561959f, "Biarritz, France")));
        intents.add(new DemoItem(res.getString(R.string.navigate_to_address), GeoIntents.newNavigationIntent("1 rue du louvre 75000 Paris")));
        intents.add(new DemoItem(res.getString(R.string.navigate_to_location), GeoIntents.newNavigationIntent(43.481055f, -1.561959f)));
      //  intents.add(new DemoItem(res.getString(R.string.streetview_at_location), GeoIntents.newStreetViewIntent(43.481055f, -1.561959f)));

        // MediaIntents
   //     intents.add(new DemoItem(res.getString(R.string.play_image), MediaIntents.newPlayImageIntent("http://upload.wikimedia.org/wikipedia/commons/thumb/a/a9/Biarritz-Plage.JPG/1920px-Biarritz-Plage.JPG")));
   //     intents.add(new DemoItem(res.getString(R.string.play_audio), MediaIntents.newPlayAudioIntent("http://www.stephaniequinn.com/Music/Allegro%20from%20Duet%20in%20C%20Major.mp3")));
        intents.add(new DemoItem(res.getString(R.string.play_video), MediaIntents.newPlayVideoIntent("http://mirror.bigbuckbunny.de/peach/bigbuckbunny_movies/big_buck_bunny_480p_h264.mov")));
   //     intents.add(new DemoItem(res.getString(R.string.play_video_youtube), MediaIntents.newPlayYouTubeVideoIntent("b_yiWIXBI7o")));
        intents.add(new DemoItem(res.getString(R.string.browse_web), MediaIntents.newOpenWebBrowserIntent("http://vincentprat.info")));
        intents.add(new DemoItem(res.getString(R.string.take_pic),   MediaIntents.newTakePictureIntent(Environment.getExternalStorageDirectory().toString() + "/temp.jpg")));
        intents.add(new DemoItem(res.getString(R.string.select_pic), MediaIntents.newSelectPictureIntent()));

        // EmailIntents
        intents.add(new DemoItem(res.getString(R.string.email_to), EmailIntents.newEmailIntent("test@example.com", "My subject", "My content")));

        // ShareIntents
        intents.add(new DemoItem(res.getString(R.string.share), ShareIntents.newShareTextIntent("My subject", "My message", getString(R.string.share_dialog_title))));

        // SystemIntents
        intents.add(new DemoItem(res.getString(R.string.app_store), SystemIntents.newMarketForAppIntent(getActivity(), "fr.marvinlabs.coverartwallpaper")));

        mAdapter = new ArrayAdapter<DemoItem>(getActivity(), android.R.layout.simple_list_item_1, android.R.id.text1, intents);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_intentitem_list, container, false);

        // Set the adapter
        mListView = (AbsListView) view.findViewById(android.R.id.list);
        ((AdapterView<ListAdapter>) mListView).setAdapter(mAdapter);

        // Set OnItemClickListener so we can be notified on item clicks
        mListView.setOnItemClickListener(this);

        return view;
    }

    @Override
    public void onAttach(Context context) {
        super.onAttach(context);
        try {
            mListener = (OnFragmentInteractionListener) context;
        } catch (ClassCastException e) {
            throw new ClassCastException(context.toString()
                    + " must implement OnFragmentInteractionListener");
        }
    }

    @Override
    public void onDetach() {
        super.onDetach();
        mListener = null;
    }


    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
        if (null != mListener) {
            // Notify the active callbacks interface (the activity, if the
            // fragment is attached to one) that an item has been selected.
            mListener.onFragmentInteraction(((DemoItem) (mAdapter.getItem(position))).intent);
        }
    }

    /**
     * The default content for this Fragment has a TextView that is shown when
     * the list is empty. If you would like to change the text, call this method
     * to supply the text it should use.
     */
    public void setEmptyText(CharSequence emptyText) {
        View emptyView = mListView.getEmptyView();

        if (emptyText instanceof TextView) {
            ((TextView) emptyView).setText(emptyText);
        }
    }

    /**
     * This interface must be implemented by activities that contain this
     * fragment to allow an interaction in this fragment to be communicated
     * to the activity and potentially other fragments contained in that
     * activity.
     * <p/>
     * See the Android Training lesson <a href=
     * "http://developer.android.com/training/basics/fragments/communicating.html"
     * >Communicating with Other Fragments</a> for more information.
     */
    public interface OnFragmentInteractionListener {
        public void onFragmentInteraction(Intent intent);
    }

}