// autor: Diego Emilio Moreno Sanchez @YeyoM

#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int *arreglo;
  int dimension_arreglo;
  int num;

  cout << "Ingrese la dimension del arreglo: ";
  cin >> dimension_arreglo;
  cout << endl;
  
  arreglo = new int(dimension_arreglo);

  for (int i = 0; i < dimension_arreglo; i++){
    cout << "Ingrese el valor en la posicion " << i + 1 << ": ";
    cin >> num;
    *(arreglo + i) = num;
    cout << endl;
  }
  
  for (int i = 0; i < dimension_arreglo; i++){
    cout << *(arreglo + i) << ", ";
  }

  delete [] arreglo;
  
  return 0;
}