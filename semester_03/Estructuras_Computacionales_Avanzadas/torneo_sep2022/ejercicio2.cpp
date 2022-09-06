/*

  autor: Diego Emilio Moreno Sánchez ID: 264776

  Problema 2:
  Una frase es palíndromo si, después de convertir todas 
  sus letras mayúsculas en minúsculas y removiendo todos 
  los caracteres no alphanumericos, puede ser leído de la
  misma manera de izquierda a derecha como de derecha a 
  izquierda. Los caracteres alphanumericos incluye letras y 
  números.

  Dada un string s, retorna verdadero si es palíndromo, 
  de no ser así retornará falso.

  Restricción:
  ● La longitud del string “s” debe ser entre 1 y (2*10^5).
  ● Resolverlo mediante la implementación de Strings

  Ejemplo:
  Entrada:
  s= “A man, a plan a canal: Panama”
  Output:
  Verdadero
  Explicación:
  “amanaplanacanalpanama” es palíndromo

*/

#include <iostream>
#include <ctype.h>
#include <string>
#include <algorithm>

using namespace std;

int main() {

  string s;
  getline(cin, s);

  string s2 = "";

  for (int i = 0; i < s.length(); i++) {
    if (isalnum(s[i])) {
      s[i] = tolower(s[i]);
    } else {
      s.erase(i, 1);
      i--;
    }
  }

  s2 = s;
  reverse(s.begin(), s.end());

  if (s == s2) {
    cout << "Verdadero" << endl;
  } else {
    cout << "Falso" << endl;
  }

  return 0;
}