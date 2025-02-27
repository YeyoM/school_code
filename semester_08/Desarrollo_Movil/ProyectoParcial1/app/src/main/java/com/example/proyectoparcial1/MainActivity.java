package com.example.proyectoparcial1;

import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    private EditText inputName;
    private Button btnCapitalize;
    private TextView resultView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        // Set the layout defined in activity_main.xml
        setContentView(R.layout.activity_main);

        // Link the UI elements to code
        inputName = findViewById(R.id.inputName);
        btnCapitalize = findViewById(R.id.btnCapitalize);
        resultView = findViewById(R.id.resultView);

        // Set the button click listener
        btnCapitalize.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String name = inputName.getText().toString();
                if (!TextUtils.isEmpty(name)) {
                    resultView.setText(capitalizeWords(name));
                }
            }
        });
    }

    // Helper method to capitalize the first letter of each word
    private String capitalizeWords(String str) {
        if (str == null || str.isEmpty()) return str;
        String[] words = str.split(" ");
        StringBuilder sb = new StringBuilder();
        for (String word : words) {
            if (!word.isEmpty()) {
                sb.append(Character.toUpperCase(word.charAt(0)));
                if (word.length() > 1) {
                    sb.append(word.substring(1).toLowerCase());
                }
                sb.append(" ");
            }
        }
        return sb.toString().trim();
    }
}

