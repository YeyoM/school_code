package com.example.actividad3;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main_layout);
        Log.d("Activity_Lifecycle","onCreate invoked");
        Toast.makeText(MainActivity.this,"Created",Toast.LENGTH_SHORT).show();
    }
    @Override
    protected void onStart() {
        super.onStart();
        Log.d("Activity_Lifecycle","onStart invoked");
        Toast.makeText(MainActivity.this,"Start",Toast.LENGTH_SHORT).show();
    }
    @Override
    protected void onResume() {
        super.onResume();
        Log.d("Activity_Lifecycle","onResume invoked");
        Toast.makeText(MainActivity.this,"Resume",Toast.LENGTH_SHORT).show();
    }
    @Override
    protected void onPause() {
        super.onPause();
        Log.d("Activity_Lifecycle","onPause invoked");
        Toast.makeText(MainActivity.this,"Pause",Toast.LENGTH_SHORT).show();
    }
    @Override
    protected void onStop() {
        super.onStop();
        Log.d("Activity_Lifecycle","onStop invoked");
        Toast.makeText(MainActivity.this,"Stop",Toast.LENGTH_SHORT).show();
    }
    @Override
    protected void onRestart() {
        super.onRestart();
        Log.d("Activity_Lifecycle","onRestart invoked");
        Toast.makeText(MainActivity.this,"Restart",Toast.LENGTH_SHORT).show();
    }
    @Override
    protected void onDestroy() {
        super.onDestroy();
        Log.d("Activity_Lifecycle","onDestroy invoked");
        Toast.makeText(MainActivity.this,"Destroy",Toast.LENGTH_SHORT).show();
    }
}