package com.example.actividad26.db

import android.content.ContentValues
import android.database.sqlite.SQLiteDatabase
import com.example.actividad26.ToDo


object ToDoTable{
    val TABLE_NAME="todos"

    object Columns{
        val ID ="id"
        val TASK ="task"
        val DONE="done"
    }
    val CMD_CREATE_TABLE ="""
        CREATE TABLE IF NOT EXISTS $TABLE_NAME
        (
        ${Columns.ID} INTEGER PRIMARY KEY AUTOINCREMENT,
        ${Columns.TASK} TEXt,
        ${Columns.DONE} BOOLEAN
         ); 
    """.trimIndent()
    fun insertTodo(db:SQLiteDatabase,toDo: ToDo){

        val row= ContentValues()
        row.put(Columns.TASK,toDo.task)
        row.put(Columns.DONE,toDo.done)

        db.insert(TABLE_NAME,null,row)
    }
    fun getAllNodos(db:SQLiteDatabase ):ArrayList<ToDo>{
        val todos = ArrayList<ToDo>()
        //read information from database
        val c= db.query(
            TABLE_NAME,
            arrayOf(Columns.ID,Columns.TASK,Columns.DONE),
            null,null,null,null,null
        )
        //while we can go to the next row
        while(c.moveToNext())
        {
            val todo=ToDo(
                c.getString(1),
                c.getInt(2) ==1
            )
            todos.add(todo)
        }
        return todos
    }
}