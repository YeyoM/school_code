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
  cout << "Digite el nombre del archivo (termine con .txt)\n";
  cout << VERDE "> " NC;
  cin >> nombreArchivo;

  archivo.open(nombreArchivo.c_str(), ios::out); // ios::out si existe el archivo lo remplaza o si no existe lo crea

  if (archivo.fail()) {   //.fail() fallo, manda un true o false, true = existe un error
    cout << "No se pudo abrir el archivo";
    exit(1); // sirve para salir del programa en caso de falla
  }
  system("clear");
  cout << endl;
  cout << VERDE << nombreArchivo << NC; 
  cout << " | Para terminar de escirbir digite ` y de un enter\n";
  cout << "----------------------------------------------------------------------------\n";
  cout << VERDE "> " NC;
  cin.getline(frase2, 10000, '`');
  archivo << frase2;   // tiene la misma funcion que cout y el cin
  archivo.close(); //cerrar el archivo
  system("clear");
}

void eliminar() { //Funcion para eliminar cualquier archivo
  char eliminar[100];
  ifstream archivo;
  fflush(stdin);
  cout << "Nombre de archivo a eliminar (con su respectiva terminacion .txt)\n";
  cout << VERDE "> " NC;
  cin >> eliminar;
  string eliminar2;
  eliminar2 = eliminar;
  archivo.open(eliminar2.c_str(), ios::in);
  if (archivo.fail()) {
    cout << "No se encontro el archivo";
    exit(1);
  } else {
    remove(eliminar);
    cout << endl << "Archivo eliminado con exito!!\n";
	}
  system("pause");
  system("clear");
}

void editar_archivo_txt() {   //Funcion para editar un archivo de texto
	string nombreArchivo;
	char frase[10000];
	ifstream archivo;
	ofstream archivo2;
	cout << "Digite el nombre del archivo (termine con .txt)\n";
  cout << VERDE "> " NC;
	cin >> nombreArchivo;

	archivo.open(nombreArchivo.c_str(), ios::in);
	if (archivo.fail()) {
		cout << "No se pudo abrir el archivo";
		exit(1);
	}
	system("clear");
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
  system("clear");
}

//lectura de archivos
void lectura() {
    string  nombreArchivo, texto;
    ifstream archivo; // ifstream es para la lectura
    cout << "Que archivo desea abrir: (escriba el nombre del archivo seguido con .txt)\n";
    cout << VERDE "> " NC; 
    cin >> nombreArchivo;
    archivo.open(nombreArchivo.c_str(), ios::in);
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo\n";
        exit(1);
    }
    system("clear");
    cout << endl << VERDE << nombreArchivo << NC << " | \n";
    cout << "----------------------------------------------------------------------------\n";
    while (!archivo.eof()) { //eof recorre todo el archivo
      getline(archivo, texto);
      cout << texto << "\n\n\n";
    }
    cout << "----------------------------------------------------------------------------\n";
    archivo.close();
    system("pause");
    system("clear");
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
  system("clear");
	return 0;
} 