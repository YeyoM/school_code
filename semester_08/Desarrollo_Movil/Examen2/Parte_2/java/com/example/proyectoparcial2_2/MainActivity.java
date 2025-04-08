package com.example.proyectoparcial2_2;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.fragment.app.Fragment;

import android.os.Bundle;
import android.view.Menu;

import com.google.android.material.bottomnavigation.BottomNavigationView;

import java.util.Objects;

public class MainActivity extends AppCompatActivity {
    // Define constantes para los IDs
    private static final int ID_PLAYAS = 1;
    private static final int ID_MONTANAS = 2;
    private static final int ID_CIUDADES = 3;
    private static final int ID_OFERTAS = 4;

    private Toolbar toolbar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        Objects.requireNonNull(getSupportActionBar()).setTitle("AirB&B");

        BottomNavigationView bottomNav = findViewById(R.id.bottom_navigation);

        // Crear el menú programáticamente
        Menu menu = bottomNav.getMenu();
        menu.clear();
        menu.add(0, ID_PLAYAS, 0, R.string.playas);
        menu.add(0, ID_MONTANAS, 0, R.string.monta_as);
        menu.add(0, ID_CIUDADES, 0, R.string.ciudades);
        menu.add(0, ID_OFERTAS, 0, R.string.ofertas);

        // Configurar el listener
        bottomNav.setOnItemSelectedListener(item -> {
            Fragment selectedFragment = null;

            int itemId = item.getItemId();
            if (itemId == ID_PLAYAS) {
                selectedFragment = new PlayasFragment();
                toolbar.setTitle("Beaches");
            } else if (itemId == ID_MONTANAS) {
                selectedFragment = new MontanasFragment();
                toolbar.setTitle("Mountains");
            } else if (itemId == ID_CIUDADES) {
                selectedFragment = new CiudadesFragment();
                toolbar.setTitle("Cities");
            } else if (itemId == ID_OFERTAS) {
                selectedFragment = new OfertasFragment();
                toolbar.setTitle("Sales");
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
                .replace(R.id.fragment_container, new PlayasFragment())
                .commit();
    }
}

