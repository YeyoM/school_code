// Función recursiva que retorna el máximo común divisor de dos números.

#include <iostream>
using namespace std;

// Write a recursive function that returns the greatest common divisor of two numbers
// Ejemplo: n=12, m=18, la función retorna 6
int mcd(int a, int b) {
  if (a == b) {
    return a;
  } else if (a > b) {
    return mcd(a - b, b);
  } else {
    return mcd(a, b - a);
  }
}

int main() {
  int a, b;
  cout << "Ingresa dos numeros: ";
  cin >> a >> b;
  cout << "El maximo comun divisor es: " << mcd(a, b);
  return 0;
}