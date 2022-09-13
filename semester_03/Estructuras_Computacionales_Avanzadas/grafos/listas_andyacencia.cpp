#include <iostream>
using namespace std;

struct Nodo {
  int dato;
  struct Nodo *siguiente;
};

void insertarLista(Nodo *&lista, int n);
void mostrarLista(Nodo *lista);

int main() {

  // crear un arr de nodos y que cada elemento del arr
  // sea la cabeza de una lista enlazada donde conecte con 
  // los elementos que tenga conexion

  int dato,
      num_nodos;

  cout << "Ingrese el numero de nodos en el grafo: ";
  cin >> num_nodos;

  Nodo *listaAdyacente[num_nodos];

  for (int i = 0; i < num_nodos; i++) {

    // generamos la cabeza de cada lista 
    Nodo *lista;
    lista = NULL;
    
    insertarLista(lista, i);      

    for (int j = 0; j < num_nodos; j++) {
      cout << "Existe conexion de " << i << " -> " << j << ": ";
      cin >> dato;

      if (dato == 1) {
        insertarLista(lista, j);
      }

    }

    listaAdyacente[i] = lista;
  }

  for (int k = 0; k < num_nodos; k++) {
    mostrarLista(listaAdyacente[k]);
    cout << endl;
  }

  return 0;
}

void insertarLista(Nodo *&lista, int n) {
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
}

void mostrarLista(Nodo *lista) {
  Nodo *actual = new Nodo();
  actual = lista;

  // nos detendremos una vez que el apuntador
  // del nodo n apunte a -> NULL
  while(actual != NULL) {
    cout << actual -> dato;
    if (actual -> siguiente != NULL) {
      cout << " -> ";
    }
    actual = actual -> siguiente;     // cambiamos al siguiente nodo
  }
}