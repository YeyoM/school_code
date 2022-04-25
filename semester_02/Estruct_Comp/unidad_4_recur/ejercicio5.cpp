// Autores: Cesar Donnet Hernandez Gastelum
//          Diego Emilio Moreno Sanchez
//          Dante Alejandro Alegria Romero
// Función recursiva que retorna el máximo común divisor de dos números.

#include <iostream>
using namespace std;

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