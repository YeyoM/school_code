// Función recursiva que retorna el resultado de la siguiente serie. 
// 1^1 + 2^2 + 3^3 + 4^4 + 5^5 + ... + n^n Ejemplo: n=3, la función retorna 32

#include <iostream>
#include <math.h>
using namespace std;

// Write a recursive function that returns the result of the following series:
// 1^1 + 2^2 + 3^3 + 4^4 + 5^5 + ... + n^n, Ejemplo: n=3, la función retorna 32
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