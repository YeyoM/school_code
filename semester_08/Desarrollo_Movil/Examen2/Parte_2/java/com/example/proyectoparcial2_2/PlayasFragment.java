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

public class PlayasFragment extends Fragment {

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_travel_list, container, false);

        RecyclerView recyclerView = view.findViewById(R.id.recyclerView);
        recyclerView.setLayoutManager(new LinearLayoutManager(getContext()));

        List<TravelItem> destinos = new ArrayList<>();

        // Agregar destinos de playa al catálogo
        destinos.add(new TravelItem("Phuket, Thailand", "Fun, nature, and culture on Thailand's exotic beaches", 1199.99, R.drawable.playa_phuket, "9 days / 8 nights"));
        destinos.add(new TravelItem("Santorini, Greece", "Stunning volcanic beaches and spectacular views of the Aegean Sea", 1450.00, R.drawable.playa_santorini, "8 days / 7 nights"));
        destinos.add(new TravelItem("Maldives", "Exclusive overwater bungalows in the world's most romantic paradise", 2399.99, R.drawable.playa_maldivas, "6 days / 5 nights"));
        destinos.add(new TravelItem("Cancún, Mexico", "Beautiful white sand beaches and crystal-clear turquoise waters, perfect for relaxation and water sports", 1299.99, R.drawable.playa_cancun, "7 days / 6 nights"));
        destinos.add(new TravelItem("Bali, Indonesia", "A tropical paradise with exotic beaches, ancient temples, and a fascinating culture", 1599.99, R.drawable.playa_bali, "10 days / 9 nights"));


        TravelAdapter adapter = new TravelAdapter(getContext(), destinos);
        recyclerView.setAdapter(adapter);

        return view;
    }
}
