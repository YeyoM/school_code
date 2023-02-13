// Diego Emilio Moreno Sánchez
// Programa que calcula el valor de e^x para un valor de x 
// dado usando n términos de la serie de Taylor.

#include <iostream>
#include <cmath>
using namespace std;

int main() {

  int contador  = 1,
      val_x,
      num_term;

  float suma    = 0,
        termino = 1;

  cout << "Este programa calcula el valor de e^x para un valor de x dado usando n términos de la serie de Taylor." << endl;
  
  cout << "Introduzca el valor de x (exponente): ";
  cin >> val_x;

  cout << "Introduzca el número de terminos de la serie de Taylor: ";
  cin >> num_term;

  while (contador <= num_term) {
    suma += termino;
    termino = termino * val_x / contador;
    contador++;
  }

  cout << "El valor de e^" << val_x << " es: " << suma << endl;

  return 0;
}