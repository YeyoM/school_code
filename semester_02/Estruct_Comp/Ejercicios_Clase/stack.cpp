#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo {
  int dato;               // guardamos el numero
  struct Nodo *siguiente; // apuntador al sig nodo
};

void menu();
void insertarNodo(Nodo *&pila, int n, int &cima);
void read_and_pop_one_only(Nodo *&pila, int &cima);
void read_and_pop_all(Nodo *&pila, int &cima);

int cima = -1;
int opcion_seleccionada,
    dato_a_ingresar;
bool salir = false;

int main() {

  Nodo *pila;
  pila = NULL;

  do {

    menu();
    cout << "Ingrese una opcion valida: ";
    cin >> opcion_seleccionada;
    if (opcion_seleccionada == 1) {
      cout << "Ingrese el elemento que desee ingresar: ";
      cin >> dato_a_ingresar;
      insertarNodo(pila, dato_a_ingresar, cima);
      cout << endl;
    } else if (opcion_seleccionada == 2) {
      if (cima == -1) {
        cout << "Stack Underflow (Pila vacia)" << endl; 
      } else {
        read_and_pop_one_only(pila, cima);
        cout << endl;
      }
    } else if (opcion_seleccionada == 3) {
      if (cima == -1) {
        cout << "Stack Underflow (Pila vacia)" << endl; 
      } else {
        read_and_pop_all(pila, cima);
        cout << endl;
      }
    } else if (opcion_seleccionada == 4) {
      if (cima == -1) {
        cout << "La pila esta vacia!" << endl;
      } else  {
        cout << "La pila no esta vacia!" << endl;
      }
    } else if (opcion_seleccionada == 5) {
      cout << "La pila tiene una longitud de " << cima + 1 << " nodos"<< endl;
    }else if (opcion_seleccionada == 6) {
      cout << "Byeeee!" << endl;
      salir = true;
    }else {
      cout << "Ingrese una opcion valida!" << endl;
      cout << endl;
    }
  } while (salir != true);

  return 0;
}

void menu() {
  cout << endl;
  cout << "Operaciones con Pilas" << endl;
  cout << "1. Insertar un elemento a la pila (PUSH)" << endl;
  cout << "2. Sacar un elemento de la pila (POP)" << endl;
  cout << "3. Mostrar y sacar todos los elementos de la pila (POP ALL)" << endl;
  cout << "4. Verificar si la pila esta vacia" << endl;
  cout << "5. Obtener la longitud de la pila" << endl;
  cout << "6. Salir del programa"<< endl;
  cout << endl;
}


void insertarNodo(Nodo *&pila, int n, int &cima){
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

  cima++;

  // mostramos un mensaje para asegurarnos que se insertaron
  // de manera correcta
  cout << "Nodo " << nuevo_nodo -> dato << " ingresado correctamente" << endl;
}




void read_and_pop_all(Nodo *&pila, int &cima) {
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
    cima--;
  }

}

void read_and_pop_one_only(Nodo *&pila, int &cima) {

  Nodo *nodo_auxiliar = new Nodo();
  nodo_auxiliar = pila;
  
  cout << "Borrando " << pila -> dato << "... (solo uno)." << endl;
  pila = pila -> siguiente;
  delete nodo_auxiliar;
  cima--;
}
