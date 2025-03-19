package com.example.actividad17;


import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.cardview.widget.CardView;

import com.google.android.material.floatingactionbutton.FloatingActionButton;

public class MainActivity extends AppCompatActivity {

    private TextView cityNameTextView;
    private TextView temperatureTextView;
    private TextView weatherDescriptionTextView;
    private TextView humidityTextView;
    private TextView windSpeedTextView;
    private FloatingActionButton refreshButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Initialize views
        cityNameTextView = findViewById(R.id.cityNameTextView);
        temperatureTextView = findViewById(R.id.temperatureTextView);
        weatherDescriptionTextView = findViewById(R.id.weatherDescriptionTextView);
        humidityTextView = findViewById(R.id.humidityTextView);
        windSpeedTextView = findViewById(R.id.windSpeedTextView);
        refreshButton = findViewById(R.id.refreshButton);

        // Set click listener for refresh button
        refreshButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(MainActivity.this, "Actualizando el clima...", Toast.LENGTH_SHORT).show();
                // Simulate refresh animation
            }
        });

        // Set click listeners for weather cards
        CardView forecastCard1 = findViewById(R.id.forecastCard1);
        CardView forecastCard2 = findViewById(R.id.forecastCard2);
        CardView forecastCard3 = findViewById(R.id.forecastCard3);

        View.OnClickListener cardClickListener = new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int cardId = v.getId();
                String message = "";

                if (cardId == R.id.forecastCard1) {
                    message = "Pronóstico para mañana";
                } else if (cardId == R.id.forecastCard2) {
                    message = "Pronóstico para pasado mañana";
                } else if (cardId == R.id.forecastCard3) {
                    message = "Pronóstico para dentro de 3 días";
                }

                Toast.makeText(MainActivity.this, message, Toast.LENGTH_SHORT).show();
            }
        };

        forecastCard1.setOnClickListener(cardClickListener);
        forecastCard2.setOnClickListener(cardClickListener);
        forecastCard3.setOnClickListener(cardClickListener);
    }
}