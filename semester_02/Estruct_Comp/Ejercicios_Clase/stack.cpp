#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo {
  int dato;               // guardamos el numero
  struct Nodo *siguiente; // apuntador al sig nodo
};

void insertarNodo(Nodo *&pila, int n);
void read_and_pop_one_only(Nodo *&pila);
void read_and_pop_all(Nodo *&pila);

int main() {

  Nodo *pila;
  pila = NULL;

  insertarNodo(pila, 5);
  insertarNodo(pila, 9);
  insertarNodo(pila, 3);
  insertarNodo(pila, 10);
  insertarNodo(pila, 7);

  read_and_pop_one_only(pila);
  read_and_pop_one_only(pila);

  read_and_pop_all(pila);

  if(pila == NULL) {
    cout << "Pila eliminada correctamente, NULL" << endl;
  }

  return 0;
}

void insertarNodo(Nodo *&pila, int n){
  // aqui creamos el nuevo nodo que vamos a agregar a la pila
  // y rellenamos el dato, con el numero que el usuario nos pase
  Nodo *nuevo_nodo = new Nodo();
  nuevo_nodo -> dato = n;
  // el nuevo nodo va a apuntar a pila, ya que los elementos
  // siempre se van apilando
  nuevo_nodo -> siguiente = pila;
  // ahora tenemos que asignar a pila el nuevo_nodo, este nuevo
  // nodo sera la cima (el punto de entrada de la estructura)
  // este nodo en su posicion siguiente ya tiene almacenado a
  // lo que antes era la cima (pila), asi, los nuevos elementos
  // simpre seran la cima
  pila = nuevo_nodo;

  // mostramos un mensaje para asegurarnos que se insertaron
  // de manera correcta
  cout << "Nodo " << nuevo_nodo -> dato << " ingresado correctamente" << endl;
}




void read_and_pop_all(Nodo *&pila) {
  // creamos el nodo que sera el que recorrera toda la pila para eliminarla
  Nodo *nodo_iterador = new Nodo();
  nodo_iterador = pila;
  // recorremos toda la pila
  while(nodo_iterador != NULL) {
    cout << "Borrando " << nodo_iterador -> dato << "..." << endl;
    // recorremos pila un lugar
    pila = pila -> siguiente;
    // y borramos el nodo al que apuntaba pila en un primer momento
    delete nodo_iterador;
    // ese nodo ahora vale lo que ahora vale pila, para poder seguir iterando
    nodo_iterador = pila;
  }

}

void read_and_pop_one_only(Nodo *&pila) {

  Nodo *nodo_auxiliar = new Nodo();
  nodo_auxiliar = pila;
  
  cout << "Borrando " << pila -> dato << "... (solo uno)." << endl;
  pila = pila -> siguiente;
  delete nodo_auxiliar;

}