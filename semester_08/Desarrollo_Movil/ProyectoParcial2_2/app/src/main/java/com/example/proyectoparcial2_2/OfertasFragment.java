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

public class OfertasFragment extends Fragment {

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_travel_list, container, false);

        RecyclerView recyclerView = view.findViewById(R.id.recyclerView);
        recyclerView.setLayoutManager(new LinearLayoutManager(getContext()));

        List<TravelItem> destinos = new ArrayList<>();

        // Agregar ofertas especiales al catálogo
        destinos.add(new TravelItem("Mediterranean Cruise - 25% OFF", "Visit 5 countries in a single trip: Spain, France, Italy, Malta, and Greece", 1299.99, R.drawable.oferta_crucero, "10 days / 9 nights"));
        destinos.add(new TravelItem("Disney World Orlando - FAMILY OFFER", "Complete package with tickets to all parks and accommodation within the resort", 1499.99, R.drawable.oferta_disney, "8 days / 7 nights"));
        destinos.add(new TravelItem("Riviera Maya, Mexico - 30% DISCOUNT", "All-inclusive resort on the best beaches of the Mexican Caribbean. Last spots available!", 899.99, R.drawable.oferta_riviera, "7 days / 6 nights"));
        destinos.add(new TravelItem("Lisbon, Portugal - 2 for 1", "Pay for one traveler, and the second goes free. Discover the Portuguese capital and its charming surroundings", 649.99, R.drawable.oferta_lisboa, "6 days / 5 nights"));


        TravelAdapter adapter = new TravelAdapter(getContext(), destinos);
        recyclerView.setAdapter(adapter);

        return view;
    }
}
