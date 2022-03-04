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
void mostrarMenores(Nodo *lista, int n);
void buscarDato(Nodo *lista, int n);
void borrarNodo(Nodo *&lista, int n);

int n;

int main() {
  
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

  cout << endl;

  cout << "Lista Ordenada: " << endl;
  mostrarLista(lista);

  cout << endl;

  cout << "Ingrese el elemento para buscar los elementos menores que el: ";
  cin >> n;
  mostrarMenores(lista, n);

  cout << endl;

  cout << "Ingrese el elemento a buscar: ";
  cin >> n;
  buscarDato(lista, n);

  borrarNodo(lista, 5);
  cout << endl;

  cout << "Lista Ordenada: " << endl;
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

/////////////////////////////////////////////////////////////////////////

void mostrarMenores(Nodo *lista, int n) {
  Nodo *actual = new Nodo();
  actual = lista;

  while(actual -> dato < n && actual != NULL) {
    cout << actual -> dato << endl;
    actual = actual -> siguiente;     
  }
}

void buscarDato(Nodo *lista, int n) {
  bool encontrado = false;
  Nodo *actual = new Nodo();
  actual = lista;

  while(actual != NULL) {
    if (actual -> dato == n){ 
      encontrado = true;
      cout << "Encontrado!!!" << endl;
      break;
    };
    actual = actual -> siguiente;
  }

  if(encontrado == false) {
    cout << "El elemento no ha sido encontrado" << endl;
  }

}

void borrarNodo(Nodo *&lista, int n) {
  if(lista != NULL) {
    Nodo *aux_borrar;
    Nodo *anterior = NULL;
    aux_borrar = lista;

    while((aux_borrar != NULL) && (aux_borrar -> dato != n)) {
      // recorremos todos a una posicion, anterior avanza una posicion
      anterior = aux_borrar;
      // y a su vez aux_borrar se va a la posicion siguiente
      aux_borrar = aux_borrar -> siguiente;
      // ojo que lista se queda igual
    }

    // CASO 1
    // recorrio toda la lista pero el dato no se encontro
    // y al final termino apuntando a NULL, por lo tanto
    if(aux_borrar == NULL) {
      cout << "El elemento no existe";
    }

    // CASO 2
    // en caso de que sea el primer elemento (no entra al while)
    else if((aux_borrar -> dato == n) && (anterior == NULL)) {
      // lista ya no va a apuntar al primer elemento
      // sino al siguiente (aux_borrar -> siguiente)
      lista = aux_borrar -> siguiente;
      // eliminamos aux_borrar
      delete aux_borrar;
    }

    // CASO 3
    // en caso de que el elemento a borrar no sea el primero
    // pero si exista
    else {
      anterior -> siguiente = aux_borrar -> siguiente;
      delete aux_borrar;
    }
  }
}

