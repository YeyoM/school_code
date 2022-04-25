// Autores: Cesar Donnet Hernandez Gastelum
//          Diego Emilio Moreno Sanchez
//          Dante Alejandro Alegria Romero
// Función recursiva que recibe un número entero y retorna la sumatoria 
// de los dígitos que lo forman. Ejemplo: n=34219, la función regresa 19

#include <iostream>
using namespace std;

int sum_digits(int n) {
  if (n < 10) {
    return n;
  } else {
    return n % 10 + sum_digits(n / 10);
  }
}

int numero;

int main() {
  cout << "Ingresa un numero: ";
  cin >> numero;
  cout << "La suma de los digitos del numero " << numero << " es: " << sum_digits(numero);
  return 0;
}