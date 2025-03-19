package com.example.actividad16;


import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private ListView listView;
    private List<StarWarsCharacter> characterList;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Set title
        setTitle("Star Wars Characters");

        // Initialize ListView
        listView = findViewById(R.id.listView);

        // Prepare data
        prepareCharacterData();

        // Set adapter
        StarWarsAdapter adapter = new StarWarsAdapter();
        listView.setAdapter(adapter);

        // Set item click listener
        listView.setOnItemClickListener((parent, view, position, id) -> {
            StarWarsCharacter character = characterList.get(position);
            Toast.makeText(MainActivity.this,
                    character.getName() + " - " + character.getDescription(),
                    Toast.LENGTH_SHORT).show();
        });
    }

    // Prepare Star Wars character data
    private void prepareCharacterData() {
        characterList = new ArrayList<>();

        characterList.add(new StarWarsCharacter("Luke Skywalker", "Jedi Knight",
                "Tatooine farm boy who became a Jedi Master", R.drawable.ic_jedi));
        characterList.add(new StarWarsCharacter("Darth Vader", "Sith Lord",
                "Formerly Anakin Skywalker, fallen Jedi", R.drawable.ic_sith));
        characterList.add(new StarWarsCharacter("Princess Leia", "Resistance General",
                "Leader of the Rebellion and Resistance", R.drawable.ic_rebel));
        characterList.add(new StarWarsCharacter("Han Solo", "Smuggler",
                "Captain of the Millennium Falcon", R.drawable.ic_pilot));
        characterList.add(new StarWarsCharacter("Chewbacca", "Wookiee",
                "Co-pilot of the Millennium Falcon", R.drawable.ic_wookie));
        characterList.add(new StarWarsCharacter("R2-D2", "Astromech Droid",
                "Loyal droid with a history of saving the galaxy", R.drawable.ic_droid));
        characterList.add(new StarWarsCharacter("C-3PO", "Protocol Droid",
                "Fluent in over six million forms of communication", R.drawable.ic_droid));
        characterList.add(new StarWarsCharacter("Obi-Wan Kenobi", "Jedi Master",
                "Trained both Anakin and Luke Skywalker", R.drawable.ic_jedi));
        characterList.add(new StarWarsCharacter("Yoda", "Jedi Grand Master",
                "Wise and powerful Jedi who trained Luke", R.drawable.ic_jedi));
        characterList.add(new StarWarsCharacter("Emperor Palpatine", "Sith Emperor",
                "Dark Lord of the Sith who rules the Empire", R.drawable.ic_sith));
    }

    // Star Wars Character class
    private static class StarWarsCharacter {
        private String name;
        private String title;
        private String description;
        private int iconResId;

        public StarWarsCharacter(String name, String title, String description, int iconResId) {
            this.name = name;
            this.title = title;
            this.description = description;
            this.iconResId = iconResId;
        }

        public String getName() {
            return name;
        }

        public String getTitle() {
            return title;
        }

        public String getDescription() {
            return description;
        }

        public int getIconResId() {
            return iconResId;
        }
    }

    // Custom adapter using ViewHolder pattern
    private class StarWarsAdapter extends BaseAdapter {

        @Override
        public int getCount() {
            return characterList.size();
        }

        @Override
        public Object getItem(int position) {
            return characterList.get(position);
        }

        @Override
        public long getItemId(int position) {
            return position;
        }

        @Override
        public View getView(int position, View convertView, ViewGroup parent) {
            ViewHolder holder;

            if (convertView == null) {
                // Inflate layout for list item
                convertView = LayoutInflater.from(MainActivity.this)
                        .inflate(R.layout.list_item, parent, false);

                // Create ViewHolder
                holder = new ViewHolder();
                holder.iconView = convertView.findViewById(R.id.iconView);
                holder.nameView = convertView.findViewById(R.id.nameView);
                holder.titleView = convertView.findViewById(R.id.titleView);

                // Store the ViewHolder in the view tag
                convertView.setTag(holder);
            } else {
                // Retrieve ViewHolder from view tag
                holder = (ViewHolder) convertView.getTag();
            }

            // Get character data
            StarWarsCharacter character = characterList.get(position);

            // Set data to views
            holder.iconView.setImageResource(character.getIconResId());
            holder.nameView.setText(character.getName());
            holder.titleView.setText(character.getTitle());

            return convertView;
        }

        // ViewHolder class to cache view references
        private class ViewHolder {
            ImageView iconView;
            TextView nameView;
            TextView titleView;
        }
    }
}