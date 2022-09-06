/*

  autor: Diego Emilio Moreno Sánchez ID: 264776

  Problema 1:
  Dada una variable con signo (positivo o negativo) x de 32 bits, 
  retorna x con sus dígitos invertidos. Si al invertir el valor 
  de x se reduce el valor de la variable de 32 bits a un rango
  de [-2^31, (2^31)-1], entonces retorna 0.
  Restricción:
  ● Resolverlo mediante la implementación de Strings
  ● Asume que el entorno no te permite guardar valores 
    de 64 bits (con o sin signos).

  Ejemplo 1:
  x= 123
  Resultado = 321

  Ejemplo 2:
  x= -321
  Resultado = -123

  Ejemplo 3:
  x= 120
  Resultado = 021 —> 21

*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

  int x;
  std::cin >> x;

  if (x < 0) {
    std::cout << "-";
  }

  string s = to_string(x);
  if (x < 0) {
    s.erase(0, 1);
  }
  reverse(s.begin(), s.end());

  while (s[0] == '0') {
    s.erase(0, 1);
  }

  std::cout << s << std::endl;

  return 0;
}