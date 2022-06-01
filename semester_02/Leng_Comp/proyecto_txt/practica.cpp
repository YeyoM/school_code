// La practica consiste en añadir una nueva opcion para agregar un archivo
// el cual justo despues de que se guarde nos indique las palabras palindromas
// que existen en dicho archivo. Consideraciones: solo se puede escribir una 
// palabra por linea, no se puede escribir una palabra en varias lineas

#include <iostream>
#include <stdlib.h>
#include <fstream>  //Libreria especifica para archivos
#include <string.h>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define NC "\e[0m"
#define VERDE "\e[0;32m"
#define ROJO "\e[0;31m"


int igual = 0, 
    x = 0;

//Funcion para escribir en un blog de notas
//Forma sencilla

void reverseStr(string& str) {
  int n = str.length();
  for (int i = 0; i < n / 2; i++)
    swap(str[i], str[n - i - 1]);
}

void evaluar(string texto) {
	string reverse;
	reverse = texto;
	reverseStr(reverse);
  for(int i = 0; i < texto.length(); i++) {
    if(texto[i] == reverse[i]) {//evalua si cada letra es igual, la variable texto que es la que leyo del archivo y la variable reverse que es la copia de texto pero invertida
      igual++;
    }
  }
  if(texto.length() == igual) { //si el contador de las veces que fue igual es indentico al tama�o de letras de la palabra entonces si es palindroma
    x = 1;
  } else {
    x = 0;
	}
	igual = 0;  //reinciamos el contador;
 }

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
  cout << " | Para terminar de escirbir digite ` y de un enter\n";
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

void checarPalindromo() {
    string  nombreArchivo, texto;
    ifstream archivo; // ifstream es para la lectura
    cout << ".../proyecto_txt |" VERDE " PALINDROMAS " NC "| Ingrese un archivo\n";
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
	    evaluar(texto);
      if (x==1) {
        cout << VERDE << texto << NC << " es palindroma\n";
		  } else {
			  cout << ROJO << texto << NC << " no es palindroma\n";
		  }
		x = 0;
    }
    archivo.close();
    system("pause");
    system("cls");
}


int main() {
  system("cls");
  string opcion;
  while (opcion != "s") {
    cout << "Ingresa c para crear un archivo, e para editar un archivo, l para leer un archivo, d para eliminar un archivo, p para usar la funcion de revisar si una palabra es palindorma, y s para salir\n";
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
    } else if (opcion == "p") {
      checarPalindromo();
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
