package com.example.actividad14;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;

import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {
    RecyclerView.LayoutManager layoutManager;
    RecyclerView recyclerView;
    List<DiziModel> diziListem;
    DiziAdapter adp;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initSet();
        diziler();

    }

    private void initSet() {
        recyclerView = findViewById(R.id.recyclerView);
        layoutManager = new LinearLayoutManager(this);

        recyclerView.setLayoutManager(layoutManager);
    }

    private void diziler() {

        diziListem = new ArrayList<>();

        DiziModel dizi1 = new DiziModel(R.drawable.breaking_bad, "Breaking Bad", "2008", "Netflix");
        DiziModel dizi2 = new DiziModel(R.drawable.the_simpson, "The Simpsons", "1989", "Disney Plus");
        DiziModel dizi3 = new DiziModel(R.drawable.the_idol, "The Idol", "2023", "blutv");
        DiziModel dizi4 = new DiziModel(R.drawable.in_space, "In Space with Markiplier", "YouTube Premium", "2022");
        diziListem.add(dizi1);
        diziListem.add(dizi2);
        diziListem.add(dizi3);
        diziListem.add(dizi4);

        adp = new DiziAdapter(this, diziListem);
        recyclerView.setAdapter(adp);

    }
}