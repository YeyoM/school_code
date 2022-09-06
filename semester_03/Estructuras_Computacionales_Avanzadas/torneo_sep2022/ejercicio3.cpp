/*
  Given the head of a singly linked list, reverse 
  the list, and return the reversed list.
  Constraints:
  ● The number of nodes in the list is the range [0, 5000].
  ● -5000 <= Node.val <= 5000
  ● Resolver mediante Listas enlazadas

  Ejemplo 1:
  Input: head = [1,2,3,4,5]
  Output: [5,4,3,2,1]

  Ejemplo 2:
  Input: head = [1,2]
  Output: [2,1]

  Ejemplo 3:
  Input: head = []
  Output: []

*/

#include <iostream>

using namespace std;

struct Nodo {
  int dato;               // guardamos el numero
  struct Nodo *siguiente; // apuntador al sig nodo
};

void insertarLista(Nodo *&lista, int n);
void invertirLista(Nodo *&lista);
void mostrarLista(Nodo *lista);

int main() {

  // inicializamos la lista enlazada
  Nodo *lista;
  lista = NULL;
  
  int dato;

  cin >> dato;
  insertarLista(lista, dato);
  cin >> dato;
  insertarLista(lista, dato);
  cin >> dato;
  insertarLista(lista, dato);
  cin >> dato;
  insertarLista(lista, dato);
  cin >> dato;
  insertarLista(lista, dato);

  mostrarLista(lista);
  invertirLista(lista);
  mostrarLista(lista);

  return 0;
}

void insertarLista(Nodo *&lista, int n){
  Nodo *nuevo_nodo = new Nodo();
  nuevo_nodo -> dato = n;

  Nodo *aux1 = lista;
  Nodo *aux2;

  // lo que hacemos aqui es preparar la lista
  // para insertar los elementos de forma ascendente 
  // si es el mayor, se insertará al último cuando 
  // aux1 == NULL, en caso de que se tenga que insertar
  // en otra posicion es cuando n sea menor al siguiente
  // y mayor al anterior
  while ((aux1 != NULL) && (aux1 -> dato < n)) {
    aux2 = aux1;
    aux1 = aux1 -> siguiente;
  }

  // cuando la lista es vacia
  if (lista == aux1) {
    lista = nuevo_nodo;
  } 
  // cuando la lista no está vacía
  else {
    aux2 -> siguiente = nuevo_nodo; 
  }

  // asignamos NULL al apuntador siguiente del ultimo nodo
  nuevo_nodo -> siguiente = aux1;

}

void invertirLista(Nodo *&lista) {
  // la idea para invertir la lista es que los apuntadores se inviertan
  // si tenemos 1 -> 2 -> 3 -> NULL, pasar a algo...
  // NULL <- 1 <- 2 <- 3 

  Nodo *actual = new Nodo();
  actual = lista;

  Nodo *anterior = new Nodo();
  Nodo *aux = new Nodo();

  while(actual != NULL) {
    aux = actual -> siguiente;
    actual -> siguiente = anterior;
    anterior = actual;
    actual = aux;
  }

  lista = anterior;

}


void mostrarLista(Nodo *lista) {
  Nodo *actual = new Nodo();
  actual = lista;

  // nos detendremos una vez que el apuntador
  // del nodo n apunte a NULL
  while(actual != NULL) {
    // esta condicional la puse por que al invertir la lista
    // al final me apunta a un cero y ya luego a NULL
    if (actual -> dato != 0) {
      cout << actual -> dato << " ";
    }
    actual = actual -> siguiente;     // cambiamos al siguiente nodo
  }
  cout << endl;
}