#include <iostream>
using namespace std;

struct Nodo {
  int dato;
  struct Nodo *anterior;
  struct Nodo *siguiente;
};

void insertarNodo(Nodo *&lista, int n);
void mostrarLista(Nodo *lista);

int main(){

  Nodo *lista;
  lista = NULL;

  int dato;

  cout << "Ingrese un dato: ";
  cin >> dato;
  insertarNodo(lista, dato);

  cout << "Ingrese un dato: ";
  cin >> dato;
  insertarNodo(lista, dato);

  cout << "Ingrese un dato: ";
  cin >> dato;
  insertarNodo(lista, dato);
  
  cout << "Ingrese un dato: ";
  cin >> dato;
  insertarNodo(lista, dato);

  mostrarLista(lista);

  return 0;
}

void insertarNodo(Nodo *&lista, int n) {
  Nodo *nuevo_nodo = new Nodo();
  nuevo_nodo -> dato = n;

  Nodo *aux1 = lista;
  Nodo *aux2;

  // recorremos la lista mientras aux1 (iterador) sea diferente de null
  // y que el doto del nodo iterador sea menor al dato, esto nos deja
  // exactamente en la posicion donde hay que insertar el nodo
  while((aux1 != NULL) && (aux1 -> dato < n)){
    aux2 = aux1;
    aux1 = aux1 -> siguiente;
  }

  if(lista == aux1){
    lista = nuevo_nodo;
    lista -> anterior = NULL;
  } else {
    aux2 -> siguiente = nuevo_nodo; 
    nuevo_nodo -> anterior = aux2;
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