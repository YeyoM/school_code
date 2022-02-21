#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){
  int *arreglo;
  int dimension_arreglo;
  int num;

  cout << "Ingrese la dimension del arreglo: ";
  cin >> dimension_arreglo;
  cout << endl;

  // solicitud del bloque de bytes asignados al arreglo
  
  arreglo = (int*)malloc(dimension_arreglo*sizeof(int));

  if (arreglo == NULL) {
    cout << "Oops! error al momento de asignar memoria al arreglo" << endl;
  } else {
    for (int i = 0; i < dimension_arreglo; i++){
      cout << "Ingrese el valor en la posicion " << i + 1 << ": ";
      cin >> num;
      *(arreglo + i) = num;
      cout << endl;
    }
    for (int i = 0; i < dimension_arreglo; i++){
      cout << *(arreglo + i) << ", ";
    }
  }

  free(arreglo);
  return 0;
}
