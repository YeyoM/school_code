#include <iostream>
#include <stdlib.h>
#include <fstream>  //Libreria especifica para archivos
#include <string.h>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define NC "\e[0m"
#define VERDE "\e[0;32m"

//Funcion para escribir en un blog de notas
//Forma sencilla

void escribir() {
  ofstream archivo; // ofstream es para la escritura
  string nombreArchivo, frase;
  char frase2[10000];
  cin.ignore();
  cout << ".../proyecto_txt |" VERDE " CREAR " NC "| Ingrese un nombre\n";
  cout << "----------------------------------------------------------------------------\n";
  cout << VERDE "> " NC;
  cin >> nombreArchivo;

  archivo.open(nombreArchivo.c_str(), ios::out); // ios::out si existe el archivo lo remplaza o si no existe lo crea

  if (archivo.fail()) {   //.fail() fallo, manda un true o false, true = existe un error
    cout << "No se pudo abrir el archivo";
    exit(1); // sirve para salir del programa en caso de falla
  }
  system("cls");
  cout << endl;
  cout << VERDE << nombreArchivo << NC; 
  cout << " | Para terminar de escribir digite ` y de un enter\n";
  cout << "----------------------------------------------------------------------------\n";
  cout << VERDE "> " NC;
  cin.getline(frase2, 10000, '`');
  archivo << frase2;   // tiene la misma funcion que cout y el cin
  archivo.close(); //cerrar el archivo
  system("cls");
}

void eliminar() { //Funcion para eliminar cualquier archivo
  char eliminar[100];
  ifstream archivo;
  fflush(stdin);
  cout << ".../proyecto_txt |" VERDE " ELIMINAR " NC "| Ingrese un archivo\n";
  cout << "----------------------------------------------------------------------------\n";
  char archivos = system("dir /b ?????????.txt");
  cout << archivos << endl;
  cout << "----------------------------------------------------------------------------\n";
  cout << VERDE "> " NC;
  cin >> eliminar;
  string eliminar2;
  eliminar2 = eliminar;
  archivo.open(eliminar2.c_str(), ios::in);
  if (archivo.fail()) {
    cout << "No se encontro el archivo";
    exit(1);
  } else {
    archivo.close();
    remove(eliminar);
    cout << endl << "Archivo eliminado con exito!!\n";
	}
  system("pause");
  system("cls");
}

void editar_archivo_txt() {   //Funcion para editar un archivo de texto
	string nombreArchivo;
	char frase[10000];
	ifstream archivo;
	ofstream archivo2;
	cout << ".../proyecto_txt |" VERDE " EDITAR " NC "| Ingrese un archivo\n";
  cout << "----------------------------------------------------------------------------\n";
  char archivos = system("dir /b ?????????.txt");
  cout << archivos << endl;
  cout << "----------------------------------------------------------------------------\n";
  cout << VERDE "> " NC;
	cin >> nombreArchivo;
	archivo.open(nombreArchivo.c_str(), ios::in);
	if (archivo.fail()) {
		cout << "No se pudo abrir el archivo";
		exit(1);
	}
	system("cls");
  cout << endl;
  cout << VERDE << nombreArchivo << NC; 
  cout << " | Para terminar de escirbir digite ` y de un enter\n";
  cout << "----------------------------------------------------------------------------\n";
  cout << VERDE "> " NC; 
  cin.getline(frase, 10000, '`');
	archivo2.open(nombreArchivo.c_str(), ios::out);
	if (archivo2.fail()) {
		cout << "No se pudo abrir el archivo";
		exit(1);
	}
	archivo2 << frase;
	archivo.close();
	archivo2.close();
  system("cls");
}

//lectura de archivos
void lectura() {
    string  nombreArchivo, texto;
    ifstream archivo; // ifstream es para la lectura
    cout << ".../proyecto_txt |" VERDE " LEER " NC "| Ingrese un archivo\n";
    cout << "----------------------------------------------------------------------------\n";
    char archivos = system("dir /b ?????????.txt");
    cout << archivos << endl;
    cout << "----------------------------------------------------------------------------\n";
    cout << VERDE "> " NC; 
    cin >> nombreArchivo;
    archivo.open(nombreArchivo.c_str(), ios::in);
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo\n";
        exit(1);
    }
    system("cls");
    cout << endl << VERDE << nombreArchivo << NC << " | \n";
    cout << "----------------------------------------------------------------------------\n";
    while (!archivo.eof()) { //eof recorre todo el archivo
      getline(archivo, texto);
      cout << texto << endl;
    }
    cout << endl;
    cout << "----------------------------------------------------------------------------\n";
    archivo.close();
    system("pause");
    system("cls");
}


int main() {
  system("cls");
  string opcion;
  while (opcion != "s") {
    cout << "Ingresa c para crear un archivo, e para editar un archivo, l para leer un archivo, d para eliminar un archivo, y s para salir\n";
    cout << VERDE "> " NC;
    cin >> opcion;
    system("cls");
    if (opcion == "c") {
      escribir();
    } else if (opcion == "e") {
      editar_archivo_txt();
    } else if (opcion == "l") {
      lectura();
    } else if (opcion == "d") {
      eliminar();
    } else if (opcion == "s") {
      cout << "Saliendo del programa\n";
    } else {
      cout << "Opcion no valida\n";
    }
  }
  system("pause");
  system("cls");
	return 0;
} 
