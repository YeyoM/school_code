package com.example.actividad18;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;

import androidx.appcompat.widget.Toolbar;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.widget.Toast;


public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);


    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.main_activity_menu, menu);
        return super.onCreateOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {

        if (     item.getItemId() == R.id.action_add )  {
            action(R.string.action_add);
            return true;  }

        if (     item.getItemId() == R.id.action_edit )  {
            action(R.string.action_edit);
            return true;  }

        if (     item.getItemId() == R.id.action_settings )  {
            action(R.string.action_settings);
            return true;    }

        if (     item.getItemId() == R.id.action_help )  {
            action(R.string.action_help);
            return true;    }
        if (     item.getItemId() == R.id.action_about )  {
            action(R.string.action_about);
            return true;   }

        return super.onOptionsItemSelected(item);

    }

    private void action(int resid) {
        Toast.makeText(this, getText(resid), Toast.LENGTH_SHORT).show();
    }

}