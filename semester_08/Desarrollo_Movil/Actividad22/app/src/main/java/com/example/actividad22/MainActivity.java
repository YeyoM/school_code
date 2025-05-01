package com.example.actividad22;


import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentTransaction;

import com.example.actividad22.fragments.CartFragment;
import com.example.actividad22.fragments.MenuFragment;
import com.example.actividad22.models.ShoppingCart;
import com.google.android.material.badge.BadgeDrawable;
import com.google.android.material.floatingactionbutton.FloatingActionButton;

public class MainActivity extends AppCompatActivity {

    private FloatingActionButton fab;
    private boolean isCartFragmentShown = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Configurar el FloatingActionButton
        fab = findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (isCartFragmentShown) {
                    // Volver al fragment de menú
                    loadFragment(new MenuFragment());
                    fab.setImageResource(R.drawable.ic_shopping_cart);
                    isCartFragmentShown = false;
                } else {
                    // Mostrar el fragment de carrito
                    loadFragment(new CartFragment());
                    fab.setImageResource(R.drawable.ic_menu);
                    isCartFragmentShown = true;
                }
            }
        });

        // Cargar el fragment de menú por defecto
        if (savedInstanceState == null) {
            loadFragment(new MenuFragment());
        }
    }

    private void loadFragment(Fragment fragment) {
        FragmentTransaction transaction = getSupportFragmentManager().beginTransaction();
        transaction.replace(R.id.fragment_container, fragment);
        transaction.commit();
    }

    @Override
    protected void onResume() {
        super.onResume();
        // Actualizar el FAB con la cantidad de elementos en el carrito
        updateCartBadge();
    }

    private void updateCartBadge() {
        int itemCount = ShoppingCart.getInstance().getItemCount();
        // Aquí podrías actualizar un badge en el FAB si lo deseas
        // Para simplicidad, usamos un Toast para mostrar la cantidad
        if (itemCount > 0 && !isCartFragmentShown) {
            Toast.makeText(this, "Cart: " + itemCount + " items", Toast.LENGTH_SHORT).show();
        }
    }
}