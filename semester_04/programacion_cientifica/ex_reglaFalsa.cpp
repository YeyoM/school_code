// Autor: Diego Emilio Moreno Sánchez
// Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño

// Programa que encuentra una de una de las raíces de una 
// función utilizando el método de la regla Falsa

// Entradas: intervalo [a, b], error (tolerancia)
// Salidas: valor de una de las raíces de la función f(x) = x^3 + x^2 - 3x - 3 = 0

#include <iostream>
#include <cmath>
#define max_iteraciones 100
using namespace std;

double f(double x) {
  return pow(x, 3) + pow(x, 2) - 3 * x - 3;
}

int main() {

  double a, b, error, x_m, x_m_anterior = 0;
  int iterador = 0;

  cout << "Programa que encuentra una de una de las raices de una funcion utilizando el metodo de la regla falsa" << endl;
  cout << "Funcion f(x) = x^3 + x^2 - 3x - 3 = 0" << endl;
  cout << "Entradas: intervalo [a, b], error (tolerancia)" << endl;
  cout << "Salidas: valor de una de las raices de la funcion f(x) = x^3 + x^2 - 3x - 3 = 0" << endl;
  cout << endl;

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

  return 0;
}