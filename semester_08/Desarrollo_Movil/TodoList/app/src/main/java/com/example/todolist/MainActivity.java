package com.example.todolist;



import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    private ArrayList<String> todoItems;
    private ArrayAdapter<String> todoAdapter;
    private ListView listView;
    private EditText editText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        listView = findViewById(R.id.listView);
        editText = findViewById(R.id.editText);

        // Initialize the todo list
        todoItems = new ArrayList<>();

        // Load saved items if available
        loadItems();

        // Create and set the adapter
        todoAdapter = new ArrayAdapter<>(this, android.R.layout.simple_list_item_1, todoItems);
        listView.setAdapter(todoAdapter);
    }

    // Add button click handler
    public void addItem(View view) {
        String itemText = editText.getText().toString().trim();
        if (!itemText.isEmpty()) {
            todoItems.add(itemText);
            todoAdapter.notifyDataSetChanged();
            editText.setText("");
            saveItems();
            Toast.makeText(getApplicationContext(), "Todo item added", Toast.LENGTH_SHORT).show();
        } else {
            Toast.makeText(getApplicationContext(), "Please enter a todo item", Toast.LENGTH_SHORT).show();
        }
    }

    // Save items to a file
    private void saveItems() {
        try {
            File file = new File(getFilesDir(), "todo.dat");
            FileOutputStream fos = new FileOutputStream(file);
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            oos.writeObject(todoItems);
            oos.close();
            fos.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Load items from a file
    @SuppressWarnings("unchecked")
    private void loadItems() {
        try {
            File file = new File(getFilesDir(), "todo.dat");
            if (file.exists()) {
                FileInputStream fis = new FileInputStream(file);
                ObjectInputStream ois = new ObjectInputStream(fis);
                todoItems = (ArrayList<String>) ois.readObject();
                ois.close();
                fis.close();
            }
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}