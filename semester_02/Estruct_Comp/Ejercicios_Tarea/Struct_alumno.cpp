/*
  Diego Emilio Moreno Snachez ID: 264776
  Tomando de referencia lo que hemos revisado y repasado del tema de 
  estructuras y arreglos. Realizar un programa en C, para capturar por 
  teclado los datos e imprimir los datos de n alumnos en un vector de estructuras.
*/

#include <iostream>
#include <string.h>

using namespace std;

struct alumno {
  string numeroIdentificacion;
  string nombre;
  int edad;
  int nota[2];
} alumnos[4];

int main() {

  for (int i = 0; i < 4; i++) {
    cout << "Ingrese el nombre del alumno " << i + 1 << ": ";
    cin >> alumnos[i].nombre;
    cout << endl;
    cout << "Ingrese el ID del alumno " << i + 1 << ": ";
    cin >> alumnos[i].numeroIdentificacion;
    cout << endl;
    cout << "Ingrese la edad del alumno" << i + 1 << ": ";
    cin >> alumnos[i].edad;
    cout << endl;
    for (int j = 0; j < 2; j++){
      cout << "Ingrese la nota " << j + 1 << " del alumno " << i + 1 << ": ";
      cin >> alumnos[i].nota[j];
      cout << endl;
    }
    fflush(stdin);
  }

  cout << "Datos de los alumnos registrados" << endl;
  cout << "--------------------------------------" <<endl;

  for (int i = 0; i < 4; i++) {
    cout << alumnos[i].nombre;
    cout << endl;
    cout << alumnos[i].numeroIdentificacion;
    cout << endl;
    cout << alumnos[i].edad;
    cout << endl;
    for (int j = 0; j < 2; j++){
      cout << alumnos[i].nota[j];
      cout << endl;
    }
    cout << "--------------------------------------" <<endl;

    fflush(stdin);
  }

  return 0;
}