package com.example.examenparcial1;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    private ListView listOptions;
    private String[] options = {"Capitalize Names", "Counter App"};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        listOptions = findViewById(R.id.listOptions);
        ArrayAdapter<String> adapter = new ArrayAdapter<>(this,
                android.R.layout.simple_list_item_1, options);
        listOptions.setAdapter(adapter);

        listOptions.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                if (position == 0) {
                    // Redirect to the Capitalize Names screen
                    startActivity(new Intent(MainActivity.this, NameCapitalizeActivity.class));
                } else if (position == 1) {
                    // Redirect to the Counter App screen
                    startActivity(new Intent(MainActivity.this, CounterActivity.class));
                }
            }
        });
    }
}