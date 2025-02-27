package com.example.actividad10;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

import androidx.fragment.app.ListFragment;


public class Fragment1 extends ListFragment {

    String[] code_name = {"Froyo", "GingerBread", "HoneyComb", "IceCream Sandwich", "JellyBean", "Kitkat", "Lollipop", "Marshmallow", "Nougat", "Oreo"};


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {

        View view = inflater.inflate(R.layout.fragment1, container, false);
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(inflater.getContext(), android.R.layout.simple_list_item_1, code_name);
        setListAdapter(adapter);
        return view;

    }

    @Override
    public void onListItemClick(ListView l, View v, int position, long id) {
        Toast.makeText(getActivity().getBaseContext(), code_name[position], Toast.LENGTH_SHORT).show();
    }
}
