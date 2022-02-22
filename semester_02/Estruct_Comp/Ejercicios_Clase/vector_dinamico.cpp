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
        // verificamos si existen elementos repetidos
        if (j != i && *(arreglo + i) == *(arreglo + j)) {
          // en caso de que sea el ultimo elemento el repetido
          // simplemente "cortamos" el ultimo elemento
          if (j == dimension_arreglo - 1) {
            dimension_arreglo =  dimension_arreglo - 1;
            arreglo = (int*)realloc(arreglo, dimension_arreglo * sizeof(int));
            // el bloque de codigo comentado es para ver como se van eliminando
            for (int i = 0; i < dimension_arreglo; i++){
              cout << *(arreglo + i) << ", ";
            }
            cout << endl;
          } else {
            // caso contrario, recorremos todos los elementos
            // a una posicion adelante a partir de la posicion
            // del elemento que queremos eliminar y luego
            // redimensionamos el arreglo 
            pos_para_eliminar = j;
            for (int k = pos_para_eliminar; k < dimension_arreglo - 1; k++) {
              if (k >- pos_para_eliminar) {
                sig_pos = k + 1;
                *(arreglo + k) = *(arreglo + sig_pos);
              }
            }
            dimension_arreglo =  dimension_arreglo - 1;
            arreglo = (int*)realloc(arreglo, dimension_arreglo * sizeof(int));
            // el bloque de codigo comentado es para ver como se van eliminando
            for (int i = 0; i < dimension_arreglo; i++){
              cout << *(arreglo + i) << ", ";
            }
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
