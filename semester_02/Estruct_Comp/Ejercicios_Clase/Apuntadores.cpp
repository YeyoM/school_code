#include <iostream>
#include <stdio.h>
using namespace std;



int main() {

  int* apuntador = nullptr;
  int entero = 15;
  apuntador = &entero;

  cout << "contenido del apuntador: " << *apuntador << endl;
  

  // referencia indirecta
  
  // manipulamos el apuntador *apuntador, y en consecuencia
  // se modifica el valor de la variable a la que apunta 
  // el *apuntador
  
  *apuntador = 20;
  cout << "Valor del entero: " << entero << endl;

  return 0;
}