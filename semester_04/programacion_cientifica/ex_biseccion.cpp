// Programa que calcula la raiz de una funcion utilizando el metodo de la bisección
// Diego Emilio Moreno Sánchez
// Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño

// Funcion f(x) = x^3 + x^2 - 3x - 3
// Entradas: intervalo [a, b]
//           error



#include <iostream>
#include <math.h>
using namespace std;


int main() {

  float raiz;

  int a, b;

  cout << "Programa que calcula la raiz de una funcion utilizando el metodo grafico" << endl;
  cout << "Funcion f(x) = 4x^2 - 10" << endl;
  cout << "Entradas: intervalo [a, b]" << endl;
  cout << "Salidas: valor de la raiz de la funcion f(x) = 4x^2 - 10" << endl;

  cout << "Ingrese el valor de a: ";
  cin >> a;
  cout << "Ingrese el valor de b: ";
  cin >> b;

  float valores_x[b - a + 1];
  float valores_y[b - a + 1];
  int indice = 0;

  for (int i = a; i <= b; i++) {
    valores_x[indice] = (4 * pow(i, 2)) - 10;
    valores_y[indice] = i;
    cout << "f(" << valores_y[indice] << ") = " << valores_x[indice] << endl;
    indice++;
  }

  for (int i = 0; i < b - a + 1; i++) {
    if (valores_x[i] * valores_x[i + 1] < 0) {
      raiz = (valores_y[i] + valores_y[i + 1]) / 2;
      cout << "La raiz de la funcion es: " << raiz << endl;
    }
  }

  return 0;
}