/*
  Realizar 2 problemas que ustedes investiguen por su cuenta, donde utilicen para su solución
  el uso de memoria dinámica. (11-12)

  1) Dados 3 arreglos desarrolla un algoritmo para juntarlos en uno usando
     memoria dinamica (no usar funciones como copy, concat, o similares)
  2) Dado un arreglo de numeros, descarta los negativos y solo deja a los
     positivos
*/

//////////////////////////////////////////////////////////////////////////////////////

// ejercicio 1
#include <iostream>
using namespace std;



int main() {

  int *arreglo_1,
      *arreglo_2,
      *arreglo_3,
      *arreglo_4;

  int dimension_arreglo_1,
      dimension_arreglo_2,
      dimension_arreglo_3,
      dimension_arreglo_4;

  int num;

  int aux;

  cout << "Ingrese la dimension del arreglo 1: ";
  cin >> dimension_arreglo_1;
  cout << endl;
  cout << "Ingrese la dimension del arreglo 2: ";
  cin >> dimension_arreglo_2;
  cout << endl;
  cout << "Ingrese la dimension del arreglo 3: ";
  cin >> dimension_arreglo_3;
  cout << endl;

  dimension_arreglo_4 = dimension_arreglo_1 + dimension_arreglo_2 + dimension_arreglo_3;
  
  arreglo_1 = (int*)malloc(dimension_arreglo_1*sizeof(int));
  arreglo_2 = (int*)malloc(dimension_arreglo_2*sizeof(int));
  arreglo_3 = (int*)malloc(dimension_arreglo_3*sizeof(int));
  arreglo_4 = (int*)malloc(dimension_arreglo_4*sizeof(int));


  if (arreglo_1 == NULL || arreglo_2 == NULL || arreglo_3 == NULL || arreglo_4 == NULL) {
    cout << "Oops! error al momento de asignar memoria al arreglo" << endl;
  } else {
    // ingresamos el arreglo
    for (int i = 0; i < dimension_arreglo_1; i++) {
      cout << "Ingrese el valor en la posicion " << i + 1 << ": ";
      cin >> num;
      *(arreglo_1 + i) = num;
      cout << endl;
    }
    for (int i = 0; i < dimension_arreglo_2; i++) {
      cout << "Ingrese el valor en la posicion " << i + 1 << ": ";
      cin >> num;
      *(arreglo_2 + i) = num;
      cout << endl;
    }
    for (int i = 0; i < dimension_arreglo_3; i++) {
      cout << "Ingrese el valor en la posicion " << i + 1 << ": ";
      cin >> num;
      *(arreglo_3 + i) = num;
      cout << endl;
    }

    for (int i = 0; i < dimension_arreglo_4; i++) {
      if (i >= 0 && i < dimension_arreglo_1) {
        *(arreglo_4 + i) = *(arreglo_1 + i);
      } else if (i >= dimension_arreglo_1 && i < dimension_arreglo_1 + dimension_arreglo_2) {
        aux = i - dimension_arreglo_1;
        *(arreglo_4 + i) = *(arreglo_2 + aux);
      } else if (i >= dimension_arreglo_3) {
        aux = i - dimension_arreglo_1 - dimension_arreglo_3;
        *(arreglo_4 + i) = *(arreglo_3 + aux);
      }
    }

  }

  cout << "Arreglo 1: " << endl;
  for (int i = 0; i < dimension_arreglo_1; i++){
    cout << *(arreglo_1 + i) << ", ";
  }
  cout << endl;
  cout << "Arreglo 2: " << endl;
  for (int i = 0; i < dimension_arreglo_2; i++){
    cout << *(arreglo_2 + i) << ", ";
  }
  cout << endl;
  cout << "Arreglo 3: " << endl;
  for (int i = 0; i < dimension_arreglo_3; i++){
    cout << *(arreglo_3 + i) << ", ";
  }
  cout << endl;
  cout << "Arreglo 4: " << endl;
  for (int i = 0; i < dimension_arreglo_4; i++){
    cout << *(arreglo_4 + i) << ", ";
  }
  cout << endl;

  free(arreglo_1);
  free(arreglo_2);
  free(arreglo_3);
  free(arreglo_4);

  return 0;
}


//////////////////////////////////////////////////////////////////////////////////////

//ejercicio 2

/*
#include <iostream>
using namespace std;


int main() {

  int *arreglo;
  int dimension_arreglo;
  int num;
  int pos_para_eliminar, sig_pos;

  cout << "Ingrese la dimension del arreglo: ";
  cin >> dimension_arreglo;
  cout << endl;
  
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

    for (int i = 0; i < dimension_arreglo; i++) {
      if (*(arreglo + i) < 0) {
        pos_para_eliminar = i;
        for (int j = pos_para_eliminar; j < dimension_arreglo - 1; j++) {
          if (j >- pos_para_eliminar) {
            sig_pos = j + 1;
            *(arreglo + j) = *(arreglo + sig_pos);
          }
        }
        dimension_arreglo =  dimension_arreglo - 1;
        i--;
      }
    }
  }

  arreglo = (int*)realloc(arreglo, dimension_arreglo * sizeof(int));

  for (int i = 0; i < dimension_arreglo; i++){
    cout << *(arreglo + i) << ", ";
  }

  free(arreglo);

  return 0;
}
*/