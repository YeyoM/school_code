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

public class BebidasFragment extends Fragment {

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_menu_list, container, false);

        RecyclerView recyclerView = view.findViewById(R.id.recyclerView);
        recyclerView.setLayoutManager(new LinearLayoutManager(getContext()));

        List<MenuItem> bebidas = new ArrayList<>();

        // Agregar bebidas al menú
        bebidas.add(new MenuItem("Matcha Latte", "Smooth and creamy green tea latte made with finely ground matcha", 5.99, R.drawable.bebida_matcha_latte));
        bebidas.add(new MenuItem("Ramune", "Classic Japanese carbonated soft drink with a unique glass bottle design", 4.50, R.drawable.bebida_ramune));
        bebidas.add(new MenuItem("Sakura Tea", "Fragrant cherry blossom tea with a delicate floral taste", 6.25, R.drawable.bebida_sakura_tea));

        MenuAdapter adapter = new MenuAdapter(getContext(), bebidas);
        recyclerView.setAdapter(adapter);

        return view;
    }
}
