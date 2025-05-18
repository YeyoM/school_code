package com.example.actividad26

data class ToDo(var task:String,var done:Boolean){
    override fun toString(): String {
        return this.task
    }
}