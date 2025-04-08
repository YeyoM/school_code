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

public class CiudadesFragment extends Fragment {

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_travel_list, container, false);

        RecyclerView recyclerView = view.findViewById(R.id.recyclerView);
        recyclerView.setLayoutManager(new LinearLayoutManager(getContext()));

        List<TravelItem> destinos = new ArrayList<>();

        // Agregar destinos de ciudades al catálogo
        destinos.add(new TravelItem("Rome, Italy", "The Eternal City with the Colosseum, the Vatican, and the best pizza in the world", 1199.99, R.drawable.ciudad_roma, "7 days / 6 nights"));
        destinos.add(new TravelItem("Barcelona, Spain", "Gaudí's modernism, urban beaches, and an incredible nightlife", 1099.99, R.drawable.ciudad_barcelona, "5 days / 4 nights"));
        destinos.add(new TravelItem("Cape Town, South Africa", "A spectacular city between mountains and oceans with a rich cultural diversity", 1499.99, R.drawable.ciudad_cabo, "9 days / 8 nights"));
        destinos.add(new TravelItem("New York, USA", "The Big Apple with its iconic skyscrapers, Broadway, and Central Park", 1599.99, R.drawable.ciudad_nueva_york, "6 days / 5 nights"));
        destinos.add(new TravelItem("Paris, France", "The city of love with the Eiffel Tower, the Louvre, and some of the world's best museums", 1299.99, R.drawable.ciudad_paris, "5 days / 4 nights"));
        destinos.add(new TravelItem("Tokyo, Japan", "A fascinating blend of tradition and technology, with ancient temples alongside futuristic skyscrapers", 1799.99, R.drawable.ciudad_tokyo, "8 days / 7 nights"));


        TravelAdapter adapter = new TravelAdapter(getContext(), destinos);
        recyclerView.setAdapter(adapter);

        return view;
    }
}
