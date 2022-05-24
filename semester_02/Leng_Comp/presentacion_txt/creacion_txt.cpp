#include <iostream>
#include <stdlib.h>
#include <fstream>  //Libreria especifica para archivos
#include <string.h>
using namespace std;

//Funcion para escribir en un blog de notas
//Forma sencilla
void escribir() {
  // ofstream es para la escritura
  ofstream archivo; 
  string nombreArchivo, frase;
  cout << "Digite el nombre del archivo (termine con .txt): ";
  getline(cin, nombreArchivo);

  // ios::out si existe el archivo lo remplaza o si no existe lo crea
  archivo.open(nombreArchivo.c_str(), ios::out); 
  //.fail() fallo, manda un true o false, true = existe un error
  if (archivo.fail()) {   
    cout << "No se pudo abrir el archivo";
    exit(1); // sirve para salir del programa en caso de falla
  }
  cout << endl << "Digite el texto del archivo: ";
  getline(cin, frase);
  archivo << frase;   // tiene la misma funcion que cout y el cin
  archivo.close(); //cerrar el archivo
}

//lectura de archivos
void lectura() {
  string texto, nombreArchivo;
  ifstream archivo; // ifstream es para la lectura
  cout << "Que archivo desea abrir: "; getline(cin, nombreArchivo);
  archivo.open(nombreArchivo.c_str(), ios::in);
  if (archivo.fail()) {
    cout << "No se pudo abrir el archivo";
    exit(1);
  }
  while (!archivo.eof()) { //eof recorre todo el archivo
    getline(archivo, texto);
    cout << texto << endl;
  }
  archivo.close();
}

int main() {
  escribir();
  lectura();
  system("pause");
  return 0;
}
