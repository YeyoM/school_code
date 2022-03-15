#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo {
  int dato;               // guardamos el numero
  struct Nodo *siguiente; // apuntador al sig nodo
};

void insertarNodo(Nodo *&pila, int n);

int main() {

  Nodo *pila;
  pila = NULL;

  insertarNodo(pila, 5);
  insertarNodo(pila, 9);
  insertarNodo(pila, 3);

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
