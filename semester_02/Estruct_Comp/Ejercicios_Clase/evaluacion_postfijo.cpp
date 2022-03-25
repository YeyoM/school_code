#include <iostream>
#include <cstring>

using namespace std;

struct Nodo {
  char caracter;          // guardamos el numero
  struct Nodo *siguiente; // apuntador al sig nodo
};

char expresion[30];
char variables[30];
int valor_de_variables[30];

int longitud_expresion,
    caracter_a,
    caracter_b,
    valor_a,
    valor_b,
    num_variables,
    indice_variable,
    cima_expresion;

float resultado;

void insertarNodo(Nodo *&pila, char caracter, int &cima);
void sacarNodo(Nodo *&pila, int &cima);

int main() {

  Nodo *pila_expresion;
  pila_expresion = NULL;

  cout << "Ingrese el numero de variables: ";
  cin >> num_variables;

  for (int i = 0; i < num_variables; i++) {
    cout << "Ingrese el nombre de la variable " << i + 1 << ": ";
    cin >> variables[i];
    cout << "Ingrese el valor de la variable " << i + 1 << ": ";
    cin >> valor_de_variables[i];
  }

  cout << "Ingrese la expresion: ";
  cin >> expresion;
  
  longitud_expresion = strlen(expresion);

  for (int i = 0; i < longitud_expresion; i++) {
    if(expresion[i] != '*' && expresion[i] != '/' && expresion[i] != '+' && expresion[i] != '-') {
      insertarNodo(pila_expresion, expresion[i], cima_expresion);
    } else {
      caracter_a = pila_expresion->caracter;
      sacarNodo(pila_expresion, cima_expresion);
      caracter_b = pila_expresion->caracter;
      sacarNodo(pila_expresion, cima_expresion);
      for(int i = 0; i < num_variables; i++) {
        if(caracter_a == variables[i]) {
          valor_a = valor_de_variables[i];
        }
        if(caracter_b == variables[i]) {
          valor_b = valor_de_variables[i];
        }
      }
      switch(expresion[i]) {
        case '+':
          resultado = valor_a + valor_b;
          break;
        case '-':
          resultado = valor_a - valor_b;
          break;
        case '*':
          resultado = valor_a * valor_b;
          break;
        case '/':
          resultado = valor_a / valor_b;
          break;
      }
      insertarNodo(pila_expresion, resultado, cima_expresion);
      cout << "Resultado: " << resultado << endl;
    }
  }

}

void insertarNodo(Nodo *&pila, char caracter, int &cima) {
  Nodo *nuevo_nodo = new Nodo();
  nuevo_nodo -> caracter = caracter;
  nuevo_nodo -> siguiente = pila;
  pila = nuevo_nodo;
  cima++;
}

void sacarNodo(Nodo *&pila, int &cima) {
  Nodo *aux = pila;
  pila = pila -> siguiente;
  delete aux;
  cima--;
}