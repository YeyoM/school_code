// Autor: Diego Emilio Moreno Snachez @YeyoM

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo {
  int dato;               // guardamos el numero
  struct Nodo *siguiente; // apuntador al sig nodo
};

int dato;

void insertarDato(Nodo *&start, Nodo *&end, int dato);
void eliminarDato(Nodo *&start, Nodo *&end, int dato);

int main() {
  Nodo *start;
  start = NULL;

  Nodo *end;
  end = NULL;

  cout << "Ingrese un dato: ";
  cin >> dato;
  insertarDato(stack, dato);

  cout << "Ingrese un dato: ";
  cin >> dato;
  insertarDato(stack, dato);


}

void insertarDato(Nodo *&start, Nodo *&end, int dato) {
  Nodo *nuevo_nodo = new Nodo;
  nuevo_nodo -> dato = dato;
  nuevo_nodo -> siguiente = NULL;

  if (start == NULL) {
    start = nuevo_nodo;
    end = nuevo_nodo;
  } else {
    end -> siguiente = nuevo_nodo;
    end = nuevo_nodo;
  }
}

void eliminarDato(Nodo *&start, Nodo *&end) {
  if (start == NULL) {
    cout << "La cola esta vacia" << endl;
  } else {
    Nodo *aux = start;
    cout << "Eliminando..." << aux -> dato << endl;
    start = start -> siguiente;
    delete aux;
  }
}