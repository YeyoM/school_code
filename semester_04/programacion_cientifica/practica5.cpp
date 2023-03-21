// Autor: Diego Emilio Moreno Sánchez
// Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño

// Programa que encuentra una de una de las raíces de una 
// función utilizando el método de la regla Falsa

// Entradas: intervalo [a, b], error (tolerancia)
// Salidas: valor de una de las raíces de la función f(x) = e^-x – ln x.

#include <iostream>
#include <cmath>
#define max_iteraciones 10
using namespace std;

double f(double x) {
  return exp(-x) - log(x);
}

void menu() {
  cout << "Programa que encuentra una de una de las raices de una funcion utilizando el metodo de la regla falsa" << endl;
  cout << "Funcion f(x) = e^-x - ln x." << endl;
  cout << endl;
  cout << "1. Calcular la raiz" << endl;
  cout << "2. Salir" << endl;
}

int main() {

  double a, b, error, x_m, x_m_anterior = 0;
  int iterador = 0;
  int opcion;

  do {
    menu();
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    cout << endl;

    if (opcion == 1) {
      cout << "Ingrese el valor de a: ";
      cin >> a;
      cout << "Ingrese el valor de b: ";
      cin >> b;
      cout << "Ingrese el error (tolerancia): ";
      cin >> error;
      cout << endl;

      while (iterador < max_iteraciones) {
        x_m = b - (f(b) * (b - a)) / (f(b) - f(a));
        cout << "Iteracion " << iterador << ": " << x_m << endl;

        if (f(x_m) == 0 || abs(x_m - x_m_anterior) < error) {
          cout << "La raiz es: " << x_m << endl;
          break;
        }

        if (f(a) * f(x_m) < 0) {
          a = x_m;
        } else {
          b = x_m;
        }

        x_m_anterior = x_m;
        iterador++;
      }
    } else if (opcion == 2) {
      cout << "Saliendo..." << endl;
    } else {
      cout << "Opcion invalida" << endl;
    }
  } while(opcion != 2);

  return 0;
}