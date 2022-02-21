// autor Diego Emilio Moreno Sanchez @YeyoM
/*
  Dado un vector, realizar un algoritmo
  que permita seleccionar solo los datos 
  que no se repitan y generar una nueva
  definicion del vector
*/

#include <iostream>
#include <stdio.h>

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
    // ingresamos el arreglo
    for (int i = 0; i < dimension_arreglo; i++){
      cout << "Ingrese el valor en la posicion " << i + 1 << ": ";
      cin >> num;
      *(arreglo + i) = num;
      cout << endl;
    }

    // modificamos el arreglo

    int pos_para_eliminar, sig_pos;

    for (int i = 0; i < dimension_arreglo; i++){
      for (int j = 0; j < dimension_arreglo; j++){
        if (j != i && *(arreglo + i) == *(arreglo + j)) {
          if(j == dimension_arreglo - 1) {
            dimension_arreglo =  dimension_arreglo - 1;
            arreglo = (int*)realloc(arreglo, dimension_arreglo * sizeof(int));
            for (int i = 0; i < dimension_arreglo; i++){
              cout << *(arreglo + i) << ", ";
            }
            cout << "i: " << i << ", j: " << j << endl;
            cout << endl;
          } else {
            pos_para_eliminar = j;
            for (int k = pos_para_eliminar; k < dimension_arreglo - 1; k++) {
              if (k >- pos_para_eliminar) {
                sig_pos = k + 1;
                *(arreglo + k) = *(arreglo + sig_pos);
              }
            }
            dimension_arreglo =  dimension_arreglo - 1;
            arreglo = (int*)realloc(arreglo, dimension_arreglo * sizeof(int));
            for (int i = 0; i < dimension_arreglo; i++){
              cout << *(arreglo + i) << ", ";
            }
            cout << "i: " << i << ", j: " << j << endl;
            cout << endl;
          }
          j--;
        }
      }
    }
  }

  for (int i = 0; i < dimension_arreglo; i++){
    cout << *(arreglo + i) << ", ";
  }

  free(arreglo);
  return 0;
}