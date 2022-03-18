// autor: Diego Emilio Moreno Sanchez @YeyoM
// 18/03/22

#include <iostream>
#include <stdlib.h>

using namespace std;

void mostrarMenu();
void pila_push(int pila[], int dato, int &cima);
void pila_pop(int pila[], int &cima);
void mostrarPila(int pila[], int cima);

int main() {

  int MAX_SIZE = 10;
  int pila[MAX_SIZE];
  int cima = -1;

  int opcion_seleccionada;
  int dato_a_ingresar;
  bool salir = false;

  do {

    mostrarMenu();
    cout << "Ingrese una opcion valida: ";
    cin >> opcion_seleccionada;

    if (opcion_seleccionada == 1) {
      if (cima == (MAX_SIZE - 1)) {
        cout << "Stack Overflow (Pila llena)" << endl; 
      } else {
        cout << "Ingrese el elemento que desee ingresar: ";
        cin >> dato_a_ingresar;
        pila_push(pila, dato_a_ingresar, cima);
        cout << endl;
      }
    } else if (opcion_seleccionada == 2) {
      if (cima == -1) {
        cout << "Stack Underflow (Pila vacia)" << endl; 
      } else {
        pila_pop(pila, cima);
        cout << endl;
      }
    } else if (opcion_seleccionada == 3) {
      if (cima != -1) {
        mostrarPila(pila, cima);
        cout << endl;
      }
    } else if (opcion_seleccionada == 4) {
      cout << "Byeeee!" << endl;
      salir = true;
    } else {
      cout << "Ingrese una opcion valida!" << endl;
      cout << endl;
    }
  } while(salir != true);

  return 0;
}

void mostrarMenu() {
  cout << endl;
  cout << "Operaciones con Pilas" << endl;
  cout << "1. Insertar un elemento a la pila (PUSH)" << endl;
  cout << "2. Sacar un elemento de la pila (POP)" << endl;
  cout << "3. Mostrar los elementos de la pila" << endl;
  cout << "4. Salir del programa"<< endl;
  cout << endl;
}

void pila_push(int pila[], int dato, int &cima) {
  cima++;
  pila[cima] = dato;
  cout << "Dato ingresado correctamente" << endl;
  cout << endl;
}

void pila_pop(int pila[], int &cima) {
  cout << "Eliminando " << pila[cima] << "..." << endl;
  cima--;
  cout << endl;
}

void mostrarPila(int pila[], int cima) {
  cout << "La pila es..." << endl;
  for(int i = 0; i < cima + 1; i++) {
    cout << pila[i] << " ";
  }
  cout << endl;
}
