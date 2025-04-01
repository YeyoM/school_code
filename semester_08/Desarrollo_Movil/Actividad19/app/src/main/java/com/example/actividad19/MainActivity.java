package com.example.actividad19;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;

import android.view.Menu;
import android.view.MenuItem;
import android.widget.FrameLayout;
import androidx.appcompat.widget.Toolbar;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

public class MainActivity extends AppCompatActivity {
    Toolbar toolbar;
    FrameLayout fragmentContainer;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar); // set toolbar as the action bar

        fragmentContainer = findViewById(R.id.fragment_container);
    }
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int itemId = item.getItemId();

        if (itemId == R.id.menu_fragment_one) {
            loadFragment(new FragmentOne());
            return true;
        } else if (itemId == R.id.menu_fragment_two) {
            loadFragment(new FragmentTwo());
            return true;
        } else if (itemId == R.id.menu_fragment_three) {
            loadFragment(new FragmentThree());
            return true;
        } else {
            return super.onOptionsItemSelected(item);
        }
    }

    private void loadFragment(Fragment fragment) {
        FragmentManager fragmentManager = getSupportFragmentManager();
        FragmentTransaction transaction = fragmentManager.beginTransaction();
        transaction.replace(R.id.fragment_container, fragment);
        transaction.addToBackStack(null);
        transaction.commit();
    }
}