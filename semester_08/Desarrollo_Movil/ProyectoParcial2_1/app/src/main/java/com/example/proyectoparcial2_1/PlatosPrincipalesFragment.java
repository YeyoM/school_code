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

public class PlatosPrincipalesFragment extends Fragment {

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_menu_list, container, false);

        RecyclerView recyclerView = view.findViewById(R.id.recyclerView);
        recyclerView.setLayoutManager(new LinearLayoutManager(getContext()));

        List<MenuItem> platosPrincipales = new ArrayList<>();

        // Agregar platos principales al menú
        platosPrincipales.add(new MenuItem("Ramen", "Rich and flavorful noodle soup with pork, egg, and vegetables", 14.99, R.drawable.plato_ramen));
        platosPrincipales.add(new MenuItem("Katsu Curry", "Crispy breaded pork cutlet served with Japanese curry and rice", 16.50, R.drawable.plato_katsu_curry));
        platosPrincipales.add(new MenuItem("Unagi Don", "Grilled eel glazed with sweet soy sauce, served over rice", 19.75, R.drawable.plato_unagi_don));

        MenuAdapter adapter = new MenuAdapter(getContext(), platosPrincipales);
        recyclerView.setAdapter(adapter);

        return view;
    }
}
