#include <iostream>
using namespace std;

struct Nodo {
  int dato;               // guardamos el numero
  struct Nodo *siguiente; // apuntador al sig nodo
};

int dato;

void insertarDato(Nodo *&start, Nodo *&end, int dato);
void eliminarDato(Nodo *&start, Nodo *&end, int dato);
bool estaEnGrafo(Nodo *&start, int dato);

int main() {

  // initialize the adjacency matrix
  int grafo[4][4] = {
      {0, 1, 0, 1},
      {0, 0, 0, 0},
      {1, 0, 0, 1},
      {0, 0, 0, 0},
  };

  // initialize the visited array
  int visited[4] = {0, 0, 0, 0};
  
  // get a random node of the graph
  int nodo = 0;

  // initialize queue
  Nodo *start;
  start = NULL;

  Nodo *end;
  end = NULL;
  
  // insert the random node in the queue
  insertarDato(start, end, dato);

  return 0;
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