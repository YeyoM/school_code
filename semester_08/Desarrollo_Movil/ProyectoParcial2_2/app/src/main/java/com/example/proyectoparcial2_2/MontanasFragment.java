package com.example.proyectoparcial2_2;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;

public class MontanasFragment extends Fragment {

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_travel_list, container, false);

        RecyclerView recyclerView = view.findViewById(R.id.recyclerView);
        recyclerView.setLayoutManager(new LinearLayoutManager(getContext()));

        List<TravelItem> destinos = new ArrayList<>();

        // Agregar destinos de montaña al catálogo
        destinos.add(new TravelItem("Rocky Mountains, Canada", "Pure adventure with crystal-clear lakes, endless forests, and abundant wildlife", 1599.99, R.drawable.montana_rocosas, "9 days / 8 nights"));
        destinos.add(new TravelItem("Himalayas, Nepal", "Hike to Everest Base Camp and experience Sherpa culture", 2099.99, R.drawable.montana_himalaya, "14 days / 13 nights"));
        destinos.add(new TravelItem("Dolomites, Italy", "Hiking through the breathtaking mountains of northern Italy with delicious cuisine", 1499.99, R.drawable.montana_dolomitas, "7 days / 6 nights"));
        destinos.add(new TravelItem("Swiss Alps", "Spectacular snow-capped mountains with charming villages and activities for all seasons", 1699.99, R.drawable.montana_alpes, "8 days / 7 nights"));
        destinos.add(new TravelItem("Torres del Paine, Chile", "One of the world's most stunning national parks with world-class trekking", 1850.00, R.drawable.montana_torres_paine, "10 days / 9 nights"));


        TravelAdapter adapter = new TravelAdapter(getContext(), destinos);
        recyclerView.setAdapter(adapter);

        return view;
    }
}
