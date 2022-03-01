// Autor: Diego Emilio Moreno Snachez @YeyoM

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo {
  int dato;               // guardamos el numero
  struct Nodo *siguiente; // apuntador al sig nodo
};

void insertarLista(Nodo *&lista, int n);

void mostrarLista(Nodo *lista);

int main (){
  
  Nodo *lista;
  lista = NULL;
  
  int dato;

  cout << "Ingrese un dato: ";
  cin >> dato;
  insertarLista(lista, dato);

  cout << "Ingrese un dato: ";
  cin >> dato;
  insertarLista(lista, dato);

  cout << "Ingrese un dato: ";
  cin >> dato;
  insertarLista(lista, dato);
  
  cout << "Ingrese un dato: ";
  cin >> dato;
  insertarLista(lista, dato);

  mostrarLista(lista);

  return 0;
}

void insertarLista(Nodo *&lista, int n){
  Nodo *nuevo_nodo = new Nodo();
  nuevo_nodo -> dato = n;

  Nodo *aux1 = lista;
  Nodo *aux2;

  while((aux1 != NULL) && (aux1 -> dato < n)){
    aux2 = aux1;
    aux1 = aux1 -> siguiente;
  }

  if(lista == aux1){
    lista = nuevo_nodo;
  } else {
    aux2 -> siguiente = nuevo_nodo; 
  }

  nuevo_nodo -> siguiente = aux1;

  cout << "Elemento " << n << " ingresado correctamente" << endl;

}

void mostrarLista(Nodo *lista) {
  Nodo *actual = new Nodo();
  actual = lista;

  // nos detendremos una vez que el apuntador
  // del nodo n apunte a -> NULL
  while(actual != NULL) {
    cout << actual -> dato << endl;
    actual = actual -> siguiente;     // cambiamos al siguiente nodo
  }
}

