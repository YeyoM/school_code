package com.example.actividad22.fragments;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.example.actividad22.R;
import com.example.actividad22.adapters.MenuAdapter;
import com.example.actividad22.models.MenuItem;

import java.util.ArrayList;
import java.util.List;

public class MenuFragment extends Fragment {

    private List<MenuItem> menuItems;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_menu, container, false);

        RecyclerView recyclerView = view.findViewById(R.id.recycler_view);
        recyclerView.setLayoutManager(new LinearLayoutManager(getContext()));

        // Inicializar y cargar los datos del menú
        initMenuData();

        // Configurar el adaptador
        MenuAdapter adapter = new MenuAdapter(menuItems);
        recyclerView.setAdapter(adapter);

        return view;
    }

    // Método para inicializar los datos del menú (ejemplos)
    private void initMenuData() {
        menuItems = new ArrayList<>();

        // Añadir elementos de ejemplo al menú
        menuItems.add(new MenuItem(1, "Wireless Earbuds", "Bluetooth 5.0 headphones with charging case", 29.99, R.drawable.ic_earbuds));
        menuItems.add(new MenuItem(2, "Smart LED TV 50\"", "4K Ultra HD with built-in streaming apps", 379.99, R.drawable.ic_tv));
        menuItems.add(new MenuItem(3, "Laptop Backpack", "Water-resistant, fits 15.6\" laptops, with USB charging port", 39.99, R.drawable.ic_backpack));
        menuItems.add(new MenuItem(4, "Mechanical Keyboard", "RGB backlit gaming keyboard with blue switches", 59.99, R.drawable.ic_keyboard));
        menuItems.add(new MenuItem(5, "External Hard Drive 2TB", "Portable USB 3.0 external storage", 64.99, R.drawable.ic_harddrive));
    }
}
