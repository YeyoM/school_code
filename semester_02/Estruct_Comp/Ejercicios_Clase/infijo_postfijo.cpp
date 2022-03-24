#include <iostream>
#include <cstring>
using namespace std;

struct Nodo {
  char caracter;          // guardamos el numero
  struct Nodo *siguiente; // apuntador al sig nodo
};


char expresion[30];
int longitud_expresion,
    cima_parentesis = -1,
    cima_expresion  = -1,
    prioridad_del_operador_expresion,
    prioridad_del_operador_pila;

void insertarNodo(Nodo *&pila, char caracter, int &cima);
void sacarNodo(Nodo *&pila, int &cima);
void vaciarPilaParentesisAbierto(Nodo *&pila, int &cima);
void vaciarPila(Nodo *&pila, int &cima);

int main() {

  Nodo *pila_verificar_parentesis;
  pila_verificar_parentesis = NULL;

  Nodo *pila_expresion;
  pila_expresion = NULL;

  cout << "Ingrese la expresion: " << endl;
  cin >> expresion;

  longitud_expresion = strlen(expresion);

  // aqui verificar que los parentesis esten correctos  

  // aqui recorrer la expresion y transformar
  for (int i = 0; i < longitud_expresion; i++) {
    // checamos si el caracter es '('
    if (expresion[i] == '(') {
      // ingresamos el parentesis a la pila
      insertarNodo(pila_expresion, expresion[i], cima_expresion);
    } else {
      if (expresion[i] == ')') {
        // vamos a sacar y mostrar los elementos de la pila
        // hasta que lleguemos al parentesis que lo abre
        vaciarPilaParentesisAbierto(pila_expresion, cima_expresion);
        // este ultimo es para sacar al parentesis que abre
        sacarNodo(pila_expresion, cima_expresion);
      } else {
        if ( // verificamos si el caracter es un operando
          expresion[i] != '+' && 
          expresion[i] != '-' && 
          expresion[i] != '/' && 
          expresion[i] != '*'
        ) {
          // ese solamente lo imprimimos
          cout << expresion[i];
        } else {
          if ( // verificamos si el caracter es un operador
            expresion[i] == '+' || 
            expresion[i] == '-' || 
            expresion[i] == '/' || 
            expresion[i] == '*'
          ) {
            // asignar la prioridad de los operadores para compararlos
            if(expresion[i] == '+') prioridad_del_operador_expresion = 1;
            if(expresion[i] == '-') prioridad_del_operador_expresion = 1;
            if(expresion[i] == '/') prioridad_del_operador_expresion = 10;
            if(expresion[i] == '*') prioridad_del_operador_expresion = 10;
            if (cima_expresion != -1) {
              if(pila_expresion -> caracter == '+') prioridad_del_operador_pila = 1;
              if(pila_expresion -> caracter == '-') prioridad_del_operador_pila = 1;
              if(pila_expresion -> caracter == '/') prioridad_del_operador_pila = 10;
              if(pila_expresion -> caracter == '*') prioridad_del_operador_pila = 10;
            } else {
              prioridad_del_operador_pila = 0;
            }
            // verificamos is la pila esta vacia o si el caracter de la cima
            // es un parentesis que abre
            if (cima_expresion == -1 || pila_expresion -> caracter == '(') {
              insertarNodo(pila_expresion, expresion[i], cima_expresion);
            } else {
              while(
                (cima_expresion != -1) && 
                (pila_expresion -> caracter != '(') &&
                (prioridad_del_operador_expresion <= prioridad_del_operador_pila)
              ) {
                sacarNodo(pila_expresion, cima_expresion);
                // volvemos a checar la prioridad del elemento de la cima
                if (cima_expresion != -1) {
                  if(pila_expresion -> caracter == '+') prioridad_del_operador_pila = 1;
                  if(pila_expresion -> caracter == '-') prioridad_del_operador_pila = 1;
                  if(pila_expresion -> caracter == '/') prioridad_del_operador_pila = 10;
                  if(pila_expresion -> caracter == '*') prioridad_del_operador_pila = 10;
                } else {
                  prioridad_del_operador_pila = 0;
                }
              }
              insertarNodo(pila_expresion, expresion[i], cima_expresion);
            }
          }
        }
      }
    }
  }

  if(cima_expresion != -1) {
    vaciarPila(pila_expresion, cima_expresion);
  }


  return 0;
}

void insertarNodo(Nodo *&pila, char caracter, int &cima) {
  // aqui creamos el nuevo nodo que vamos a agregar a la pila
  // y rellenamos el caracter, con el caracter que el programa pase
  Nodo *nuevo_nodo = new Nodo();
  nuevo_nodo -> caracter = caracter;
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
  // cout << "Nodo " << nuevo_nodo -> caracter << " ingresado correctamente" << endl;
}
void sacarNodo(Nodo *&pila, int &cima) {
  Nodo *nodo_auxiliar = new Nodo();
  nodo_auxiliar = pila;
  
  //cout << "Borrando " << pila -> caracter << "..." << endl;
  if(pila -> caracter != '(' || pila -> caracter != ')') {
    cout << pila -> caracter;
  }
  pila = pila -> siguiente;
  delete nodo_auxiliar;
  cima--;
}

void vaciarPilaParentesisAbierto(Nodo *&pila, int &cima) {
  Nodo *nodo_iterador = new Nodo();
  nodo_iterador = pila;

  while(nodo_iterador -> caracter != '(') {
    if(nodo_iterador -> caracter != '(' || nodo_iterador -> caracter != ')') {
      cout << nodo_iterador -> caracter;
    }
    //cout << "Borrando " << nodo_iterador -> caracter << "..." << endl;
    // recorremos pila un lugar
    pila = pila -> siguiente;
    // y borramos el nodo al que apuntaba pila en un primer momento
    delete nodo_iterador;
    // ese nodo ahora vale lo que ahora vale pila, para poder seguir iterando
    nodo_iterador = pila;
    cima--;
  }
}

void vaciarPila(Nodo *&pila, int &cima) {
  // creamos el nodo que sera el que recorrera toda la pila para eliminarla
  Nodo *nodo_iterador = new Nodo();
  nodo_iterador = pila;
  // recorremos toda la pila
  while(nodo_iterador != NULL) {
    //cout << "Borrando " << nodo_iterador -> caracter << "..." << endl;
    if(nodo_iterador -> caracter != '(' || nodo_iterador -> caracter != ')') {
      cout << nodo_iterador -> caracter;
    }
    // recorremos pila un lugar
    pila = pila -> siguiente;
    // y borramos el nodo al que apuntaba pila en un primer momento
    delete nodo_iterador;
    // ese nodo ahora vale lo que ahora vale pila, para poder seguir iterando
    nodo_iterador = pila;
    cima--;
  }
}