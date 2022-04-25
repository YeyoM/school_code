// Autores: Cesar Donnet Hernandez Gastelum
//          Diego Emilio Moreno Sanchez
//          Dante Alejandro Alegria Romero
// Función recursiva que recibe un numerador y un denominador y 
// retorna un entero con el resultado de la división, la cual se debe 
// hacer por restas sucesivas. a. 
// Ejemplo: n = 8, entonces 
// 8 - 2 = 6
// 6 - 2 = 4
// 4 - 2 = 2
// 2 - 2 = 0
// Como la resta se hizo 4 veces, entonces la función retorna un 4. 
// Esta función solo retorna la parte entera, no retorna decimales.

#include <iostream>
using namespace std;

int division(int num, int den) {
  if (num < den) {
    return 0;
  } else {
    return 1 + division(num - den, den);
  }
}

int main() {
  int numerador, denominador;
  cout << "Ingresa el numerador: ";
  cin >> numerador;
  cout << "Ingresa el denominador: ";
  cin >> denominador;
  cout << "El resultado de la division es: " << division(numerador, denominador); 
  return 0;
}