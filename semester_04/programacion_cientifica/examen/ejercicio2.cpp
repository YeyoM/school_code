// Universidad Autónoma de Aguascalientes
// Centro de Ciencias Básicas
// Departamento de Computación
// Diego Emilio Moreno Sánchez
// Dr. en C. Luis Fernando Gutiérrez Marfileño

// Programa que encuentra una de las raices de la 
// función f(x) = 0.5sin(x) - x + 1 utilizando el método de punto fijo

// Entradas: x0 (valor inicial), error (tolerancia)
// Salidas: valor de la raiz de la función f(x) = 0.5sin(x) - x + 1 


#include <iostream>
#include <cmath>
using namespace std;

int main() {

  double x0,
         error;
  
  int contador = 0;

  cout << "Ingrese el valor inicial x0: ";
  cin >> x0;

  cout << "Ingrese el error (tolerancia): ";
  cin >> error;

  double x1 = asin((2*x0 - 2));
  cout << "x1: " << x1 << endl;

  double valor_real = 1.4987;

  while (abs(x1 - x0) > error) {
    x0 = x1;
    x1 = asin((2*x0 - 2));
    cout << "x1: " << x1 << endl;
    contador++;
  }

  cout << "La raiz de la funcion es: " << x1 << endl;

  return 0;
}