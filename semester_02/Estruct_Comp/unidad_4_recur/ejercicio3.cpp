// Autores: Cesar Donnet Hernandez Gastelum
//          Diego Emilio Moreno Sanchez
//          Dante Alejandro Alegria Romero
// Función recursiva que retorna el resultado de la siguiente serie. 
// 1^1 + 2^2 + 3^3 + 4^4 + 5^5 + ... + n^n Ejemplo: n=3, la función retorna 32

#include <iostream>
#include <math.h>
using namespace std;

int sum_series(int n) {
  if (n == 1) {
    return 1;
  } else {
    return pow(n, n) + sum_series(n - 1);
  }
}

int main() {
  int n;
  cout << "Ingresa un numero: ";
  cin >> n;
  cout << "El resultado de la serie es: " << sum_series(n);
  return 0;
}