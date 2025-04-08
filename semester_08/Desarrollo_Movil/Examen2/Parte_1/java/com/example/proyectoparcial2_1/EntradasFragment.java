package com.example.proyectoparcial2_1;


import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.example.proyectoparcial2_1.MenuAdapter;
import com.example.proyectoparcial2_1.MenuItem;

import java.util.ArrayList;
import java.util.List;

public class EntradasFragment extends Fragment {

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_menu_list, container, false);

        RecyclerView recyclerView = view.findViewById(R.id.recyclerView);
        recyclerView.setLayoutManager(new LinearLayoutManager(getContext()));

        List<MenuItem> entradas = new ArrayList<>();

        // Agregar items al menú (ejemplo)
        entradas.add(new MenuItem("Edamame", "Steamed young soybeans sprinkled with sea salt", 6.99, R.drawable.entradas_edamame));
        entradas.add(new MenuItem("Gyoza", "Pan-fried dumplings filled with pork and vegetables", 9.50, R.drawable.entradas_gyoza));
        entradas.add(new MenuItem("Takoyaki", "Savory octopus-filled dough balls topped with bonito flakes and sauce", 8.75, R.drawable.entradas_takoyaki));

        MenuAdapter adapter = new MenuAdapter(getContext(), entradas);
        recyclerView.setAdapter(adapter);

        return view;
    }
}