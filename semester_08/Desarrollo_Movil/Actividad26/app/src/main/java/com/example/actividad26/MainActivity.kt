package com.example.actividad26


import android.os.Bundle
import android.widget.ArrayAdapter
import android.widget.Button
import android.widget.EditText
import android.widget.ListView
import androidx.activity.ComponentActivity
import com.example.actividad26.db.MyDbHelper
import com.example.actividad26.db.ToDoTable


class MainActivity : ComponentActivity() {
    private val todos = ArrayList<ToDo>()
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val todoAdapter = ArrayAdapter<ToDo>(
            this,
            android.R.layout.simple_list_item_1,
            android.R.id.text1,
            todos
        )
        val db=MyDbHelper(this).writableDatabase
        fun refreshTodoList(){
            val todoList=ToDoTable.getAllNodos(db)
            // Log.d("TODOS",todoList.toString())
            todos.clear()
            todos.addAll(todoList)
            todoAdapter.notifyDataSetChanged()
        }
        refreshTodoList()
        //set todoadapter in listView
        val etNewToDo = findViewById<EditText>(R.id.etNewToDo)
        val btnAddToDo = findViewById<Button>(R.id.btnAddToDo)
        val lvTools = findViewById<ListView>(R.id.lvTools)
        lvTools.adapter = todoAdapter
        btnAddToDo.setOnClickListener {
            val newToDo=ToDo(
                etNewToDo.text.toString(),
                false
            )
            ToDoTable.insertTodo(db,newToDo)
            refreshTodoList()
        }
    }
}