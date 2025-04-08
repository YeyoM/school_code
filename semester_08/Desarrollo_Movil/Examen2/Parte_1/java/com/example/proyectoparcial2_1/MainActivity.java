package com.example.proyectoparcial2_1;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentTransaction;

import android.os.Bundle;
import android.view.MenuItem;
import android.view.Menu;

import com.google.android.material.bottomnavigation.BottomNavigationView;
import com.google.android.material.navigation.NavigationBarView;

public class MainActivity extends AppCompatActivity {
    // Define constantes para los IDs
    private static final int ID_ENTRADAS = 1;
    private static final int ID_PLATOS = 2;
    private static final int ID_POSTRES = 3;
    private static final int ID_BEBIDAS = 4;

    private Toolbar toolbar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        getSupportActionBar().setTitle("Menú del Restaurante");

        BottomNavigationView bottomNav = findViewById(R.id.bottom_navigation);

        // Crear el menú programáticamente
        Menu menu = bottomNav.getMenu();
        menu.clear();
        menu.add(0, ID_ENTRADAS, 0, "Appetizers");
        menu.add(0, ID_PLATOS, 0, "Main Courses");
        menu.add(0, ID_POSTRES, 0, "Desserts");
        menu.add(0, ID_BEBIDAS, 0, "Beverages");

        // Configurar el listener
        bottomNav.setOnItemSelectedListener(item -> {
            Fragment selectedFragment = null;

            int itemId = item.getItemId();
            if (itemId == ID_ENTRADAS) {
                selectedFragment = new EntradasFragment();
                toolbar.setTitle("Appetizers");
            } else if (itemId == ID_PLATOS) {
                selectedFragment = new PlatosPrincipalesFragment();
                toolbar.setTitle("Main Courses");
            } else if (itemId == ID_POSTRES) {
                selectedFragment = new PostresFragment();
                toolbar.setTitle("Desserts");
            } else if (itemId == ID_BEBIDAS) {
                selectedFragment = new BebidasFragment();
                toolbar.setTitle("Beverages");
            }

            if (selectedFragment != null) {
                getSupportFragmentManager().beginTransaction()
                        .replace(R.id.fragment_container, selectedFragment)
                        .commit();
            }

            return true;
        });

        // Cargar fragment por defecto
        getSupportFragmentManager().beginTransaction()
                .replace(R.id.fragment_container, new EntradasFragment())
                .commit();
    }
}