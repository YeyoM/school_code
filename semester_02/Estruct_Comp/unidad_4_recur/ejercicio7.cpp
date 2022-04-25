// Autores: Cesar Donnet Hernandez Gastelum
//          Diego Emilio Moreno Sanchez
//          Dante Alejandro Alegria Romero
// Se presenta la solución recursiva a encontrar el numero más 
// grande de un vector, implementar la lógica planteada en este 
// código en lenguaje C

#include <iostream>
using namespace std;

int mayor_num(int *vector, int iterador, int mayor) {
  if (iterador == 0) {
    return mayor;
  }
  else if (vector[iterador] > mayor) {
    return mayor_num(vector, iterador - 1, vector[iterador]);
  } 
  else {
    return mayor_num(vector, iterador - 1, mayor);
  }
}

int vector [5] = { 1, 30, 2, 5, 2 }; 
int iterador = 5;

int main() {
  cout << "El vector es: " << endl;
  for (int i = 0; i < 5; i++) {
    cout << vector[i] << endl;
  }
  cout << "El numero mayor es: " << mayor_num(vector, iterador, vector[iterador]);
  return 0;
}