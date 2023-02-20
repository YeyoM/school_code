// Autor: Diego Emilio Moreno Sánchez
// Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño

// Programa que encuentra una de las raices de la 
// función f(x) = x^2 - 4x + 2 utilizando el método de punto fijo

// Entradas: x0 (valor inicial), error (tolerancia)
// Salidas: valor de la raiz de la función f(x) = x^3 + 4x^2 - 10

// Explicación del método de punto fijo:

/*
  Para encontrar las raices de la funcion, tenemos...

  f(x) = 0, por lo tanto, x^3 + 4x^2 - 10 = 0

  Para cambiar la ecuacion a la forma x = g(x), tenemos...

  x = g(x) = sqrt(10 / x + 4)

  Por lo tanto, la ecuación de recurrencia es...

  x_(i+1) = sqrt(10 / x_i + 4)
*/

#include <iostream>
#include <math.h>
using namespace std;

int main() {

  cout << "Este programa encuentra una de las raices de la funcion f(x) = x^3 + 4x^2 - 10" << endl;

  double x0,
         error;

  int contador = 0;

  cout << "Ingrese el valor inicial x0: ";
  cin >> x0;

  cout << "Ingrese el error (tolerancia): ";
  cin >> error;

  double x1 = sqrt(10 / (x0 + 4));

  while (abs(x1 - x0) > error) {
    x0 = x1;
    x1 = sqrt(10 / (x0 + 4));
    contador++;
  }

  cout << "El numero de iteraciones es: " << contador << endl;

  cout << "La raiz de la funcion es: " << x1 << endl;

  return 0;
}