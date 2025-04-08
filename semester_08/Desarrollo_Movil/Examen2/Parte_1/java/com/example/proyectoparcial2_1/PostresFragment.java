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

import java.util.ArrayList;
import java.util.List;

public class PostresFragment extends Fragment {

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_menu_list, container, false);

        RecyclerView recyclerView = view.findViewById(R.id.recyclerView);
        recyclerView.setLayoutManager(new LinearLayoutManager(getContext()));

        List<MenuItem> postres = new ArrayList<>();

        // Agregar postres al menú
        postres.add(new MenuItem("Mochi", "Chewy rice cake filled with sweet red bean paste or ice cream", 5.99, R.drawable.dessert_mochi));
        postres.add(new MenuItem("Dorayaki", "Fluffy pancake sandwich filled with sweet red bean paste", 6.50, R.drawable.dessert_doroyaki));
        postres.add(new MenuItem("Matcha Parfait", "Layered dessert with matcha ice cream, jelly, and sweet toppings", 8.75, R.drawable.dessert_matcha_parfait));
        postres.add(new MenuItem("Taiyaki", "Fish-shaped pastry filled with custard, chocolate, or red bean paste", 7.25, R.drawable.dessert_taiyaki));


        MenuAdapter adapter = new MenuAdapter(getContext(), postres);
        recyclerView.setAdapter(adapter);

        return view;
    }
}
