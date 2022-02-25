/*Implementar en funciones o procedimientos, que te permitan leer el nombre y los dos apellidos de una persona (en tres cadenas de caracteres diferentes) y unirlo en una única cadena.*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;



void unirdatos(string nombre ,string apellidop ,string apellidom);

int main(){
	string nombre,apellidop,apellidom;

cout<<"Digite su nombre: ";getline(cin,nombre);
cout<<"Digite su apellido paterno: ";getline(cin,apellidop);
cout<<"Digite su apellido materno: ";getline(cin,apellidom);
unirdatos(nombre,apellidop,apellidom);
system("pause");
return 0;
}


void unirdatos(string nombre, string apellidop, string apellidom){
	string cadena;
	cadena= nombre  + " " +  apellidop +" "+ apellidom;
	
	
	cout<<"Tu nombre es: "<<cadena<<endl;
	
}
