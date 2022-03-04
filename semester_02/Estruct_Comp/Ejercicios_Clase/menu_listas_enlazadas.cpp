// Autor: Diego Emilio Moreno Snachez @YeyoM

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo {
  int dato;               // guardamos el numero
  struct Nodo *siguiente; // apuntador al sig nodo
};

void insertarLista(Nodo *&lista, int n);
void mostrarPrimero(Nodo *lista);
void mostrarUltimo(Nodo *lista);
void mostrarSiguiente(Nodo *lista, int n);
void mostrarAnterior(Nodo *lista, int n);
void borrarLista(Nodo *&lista);
void checkIsVacia(Nodo *lista);

int n,
    opcion;
bool salir = false;


int main() {
  
  Nodo *lista;
  lista = NULL;
  
  int dato;

  // generamos la lista
  for (int i = 0; i < 5; i++) {
    dato = 1 + rand() % 10;
    insertarLista(lista, dato); 
  }

  Nodo *nodo_para_menu = new Nodo();
  nodo_para_menu = lista;

  do {
    cout << ".:Menu:." << endl;
    cout << "1. Imprimir el primer elemento" << endl;
    cout << "2. Imprimir el ultimo elemento" << endl;
    //si ingresamos ej el num 5, y tenemos la lista 1,5,7,9 -> regresa el 7
    cout << "3. Mostrar el siguiente elemento de..." << endl; 
    cout << "4. Mostrar el anterior elemento de..." << endl;
    cout << "5. Mostrar si la lista esta vacia" << endl;
    cout << "6. Borrar una lista completa" << endl;
    cout << "7. Salir" << endl;

    cout << "Ingrese una opcion valida: ";
    cin >> opcion;
    cout << endl;

    if (opcion == 1) {
      mostrarPrimero(lista);
    } else if (opcion == 2) {
      mostrarUltimo(lista);
    } else if (opcion == 3) {
      cout << "Ingrese el elemento: ";
      cin >> n;
      cout << endl;
      mostrarSiguiente(lista, n);
    } else if (opcion == 4) {
      cout << "Ingrese el elemento: ";
      cin >> n;
      cout << endl;
      mostrarAnterior(lista, n);
    } else if (opcion == 5) {
      checkIsVacia(lista);
    } else if (opcion == 6) {
      borrarLista(lista);
    } else if (opcion == 7) {
      salir = true;
    } else {
      cout << "Ingrese una opcion valida" << endl;
    } 

  } while(salir == false);

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

void mostrarPrimero(Nodo *lista){
  if(lista != NULL) {
    cout << "Primer elemento: " << lista -> dato << endl;
  } else  {
    cout << "La lista no contiene ningun elemento" << endl;
  }
}

void mostrarUltimo(Nodo *lista){
  if(lista != NULL) {
    Nodo *nodo_iterador = new Nodo();
    nodo_iterador = lista;
    while(nodo_iterador != NULL) {
      nodo_iterador = nodo_iterador -> siguiente;     // cambiamos al siguiente nodo
      if(nodo_iterador -> siguiente == NULL) {
        cout << "Ultimo elemento de la lista: " << nodo_iterador -> dato << endl;
        break;
      }
    }
  }
}

void mostrarSiguiente(Nodo *lista, int n) {
  bool encontrado = false;
  Nodo *actual = new Nodo();
  actual = lista;

  Nodo *nodo_siguiente = new Nodo();
  nodo_siguiente = actual;

  while(actual != NULL) {
    if (actual -> dato == n){ 
      encontrado = true;
      if(actual -> siguiente != NULL) {
        nodo_siguiente = actual -> siguiente;
        cout << "El nodo siguiente es: " << nodo_siguiente -> dato << endl;
      } else {
        cout << "El nodo siguiente es null" << endl;
      }
      break;
    };
    actual = actual -> siguiente;
  }

  if(encontrado == false) {
    cout << "El elemento no ha sido encontrado" << endl;
  }
}
void mostrarAnterior(Nodo *lista, int n) {
  bool encontrado = false;
  Nodo *actual = new Nodo();
  actual = lista;

  Nodo *nodo_siguiente = new Nodo();
  nodo_siguiente = actual;

  while(actual != NULL) {
    if (actual -> dato == n){ 
      encontrado = true;
      if(actual -> siguiente != NULL) {
        nodo_siguiente = actual -> siguiente;
        cout << "El nodo siguiente es: " << nodo_siguiente -> dato << endl;
      } else {
        cout << "El nodo siguiente es null" << endl;
      }
      break;
    };
    actual = actual -> siguiente;
  }

  if(encontrado == false) {
    cout << "El elemento no ha sido encontrado" << endl;
  }
}

void borrarLista(Nodo *&lista){
  Nodo *actual = new Nodo();
  actual = lista;

  Nodo *nodo_siguiente = new Nodo();
  nodo_siguiente = actual -> siguiente;

  // nos detendremos una vez que el apuntador
  // del nodo n apunte a -> NULL
  while(actual != NULL) {
    delete actual;
    actual = nodo_siguiente;
    if(actual != NULL) {
      nodo_siguiente = nodo_siguiente -> siguiente;
    }
  }
}

void checkIsVacia(Nodo *lista){
  if (lista == NULL) {
    cout << "La lista esta vacia" << endl;
  } else {
    cout << "La lista NO esta vacia" << endl;
  }
}
