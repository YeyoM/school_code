/*
  Diego Emilio Moreno Sanchez

  Escribir un programa con los siguientes puntos:

  - int lista[5];
  - int *p;
  - p=lista;

  - Llenar los valores enteros en el arreglo 
    a través del apuntador p

  - Mostrar la direcciones de memoria de cada 
    elemento del arreglo
*/

#include <iostream>

using namespace std;

int main() {

  int lista[5];
  int *p;
  p = lista;

  for (int i = 0; i < 5; i++) {
    cout << "Ingrese el valor en la posicion " << i + 1 << ": ";
    cin >> *(p + i);
    cout << endl;
  }

  for (int i = 0; i < 5; i++){
    cout << "Posicion: " << i + 1 << ". Valor: " << *(lista + i) << ". Direccion: " << (lista + i) << endl;
  }

  return 0;
} 
