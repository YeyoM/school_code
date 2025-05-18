package com.example.sqliteproject_;

import android.app.Activity;
import android.database.Cursor;
import android.os.Bundle;
import android.view.View;
import android.widget.*;

public class MainActivity extends Activity {

    private EditText subjectEditText;
    private EditText descEditText;
    private Button addBtn;
    private ListView listView;

    private DBManager dbManager;
    private SimpleCursorAdapter adapter;

    final String[] from = new String[] { DatabaseHelper._ID, DatabaseHelper.SUBJECT, DatabaseHelper.DESC };
    final int[] to = new int[] { R.id.id, R.id.title, R.id.desc };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        subjectEditText = findViewById(R.id.subject_edittext);
        descEditText = findViewById(R.id.desc_edittext);
        addBtn = findViewById(R.id.add_record);
        listView = findViewById(R.id.list_view);

        dbManager = new DBManager(this);
        dbManager.open();

        Cursor cursor = dbManager.fetch();
        adapter = new SimpleCursorAdapter(this, R.layout.activity_view_record, cursor, from, to, 0);
        adapter.notifyDataSetChanged();

        listView.setAdapter(adapter);

        addBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                final String name = subjectEditText.getText().toString();
                final String desc = descEditText.getText().toString();

                dbManager.insert(name, desc);
                Cursor cursor = dbManager.fetch();
                adapter.changeCursor(cursor);
            }
        });
    }
}

