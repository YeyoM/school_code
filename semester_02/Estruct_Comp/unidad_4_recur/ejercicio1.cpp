// Función recursiva que retorna cuantos dígitos forman un número. 
// Ejemplo: n=7896, la función regresa 4.

#include <iostream>
using namespace std;

// write a recursive function that returns the number of digits in a number
int num_digits(int n) {
  if (n < 10) {
    return 1;
  } else {
    return 1 + num_digits(n / 10);
  }
}

int numero;

int main() {
  cout << "Ingresa un numero: ";
  cin >> numero;
  cout << "El numero " << numero << " tiene " << num_digits(numero) << " digitos";
  return 0;
}