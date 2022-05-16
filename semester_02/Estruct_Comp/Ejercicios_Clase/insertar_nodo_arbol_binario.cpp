#include <iostream>
using namespace std;

struct Nodo {
  int dato;
  struct Nodo *izq;
  struct Nodo *der;
};

void insertar(Nodo *&raiz, int dato) {
  if (raiz == NULL) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo -> dato = dato;
    nuevo_nodo -> izq = NULL;
    nuevo_nodo -> der = NULL;
  } else if (raiz -> dato == dato) {
    cout << "Error: el elemento ya existe" << endl;
  } else if (raiz -> dato > dato) {
    insertar(raiz -> izq, dato);
  } else {
    insertar(raiz -> der, dato);
  }
}

int main() {
  Nodo *raiz = NULL;
  insertar(raiz, 10);
  insertar(raiz, 5);
  insertar(raiz, 15);
  insertar(raiz, 20);
  insertar(raiz, 1);
  return 0;
}