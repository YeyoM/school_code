/*
  objetivo: Algoritmo para el manejo de Colas Circulares
  El problema de las colas simples se da cuando en el momento de eliminar un dato se conserva
  la posición vacía, y al seguir ingresando datos, puede presentarse el caso en que el vector no
  permita el ingreso de más datos, aun y cuando existan lugares todavía, lo anterior ocurre cuando
  el índice de inserción está en la última casilla disponible del vector, porque lo considera como
  vector lleno, esto difinalculta la utilización de colas para el programador.
  La solución al problema de colas simples es utilizar colas circulares. 
  fecha: Marzo-2022
  elaboró: ELV 
*/

#include <iostream>
#include <stdbool.h>
using namespace std;

int main(){
  int size = 5;
  int cola[size];
  int start = -1;
  int end = -1;
  int option, data;
  bool salir = false;

  do {
    cout << "1. Insertar dato" << endl;
    cout << "2. Eliminar dato" << endl;
    cout << "3. Salir" << endl;
    cout << "Ingresa una opcion: ";
    cin >> option;
    cout << endl;
    if(option == 1) {
      if((end == size - 1 && start == 0) || (end + 1 == start)) {
        cout << "Cola llena" << endl;
      } else {
        cout << "Ingrese el dato: ";
        cin >> data;
        cout << endl;
        if(end == size - 1) {
          end = 0;
        } else {
          end = end + 1;
        } 
        cola[end] = data;
        if(end == 0 && start == -1) {
          start = 0;
        }
      }
    } else if(option == 2) {
      if(start == -1) {
        cout << "Cola vacía" << endl;
      } else {
        cout << "Dato eliminado: " << cola[start] << endl;
        if(start == end) {
          start = -1;
          end = -1;
        } else {
          if(start == size - 1) {
            start = 0;
          } else {
            start = start + 1;
          }
        }
      }
    } else if(option == 3) {
      salir = true;
      cout << "Saliendo..." << endl;
    } else {
      cout << "Opción inválida" << endl;
    }
  } while(salir != true);

  return 0;
}

