#include <iostream>
using namespace std;

#define ROWS_TEST 10
#define COLS_TEST 10


/**
 * Posible solucion y planteamiento del problema
 * 
 * Para definir los limites de la isla tenemos que entender
 * que dos nodos son de una misma isla si en la matriz son
 * contiguos, es decir que se encuentre a sus alrededores
 * 
 * En base a este principio, podemos definir 8 posiciones
 * posibles para definir si un nodo es contiguo a otro
 * 
 * En forma de tabla se ve de la siguiente manera
 * 
 * (i-1, j-1) (i-1, j) (i-1, j+1) 
 * (i, j-1)   (i, j)   (i, j+1)
 * (i+1, j-1) (i+1, j) (i+1, j+1)
 * 
 * En base a lo anterior podemos recorrer la matriz y
 * verificar si un nodo es contiguo a otro, si es asi
 * entonces se suma 1 al contador de islas
 * 
 * Para evitar que se cuente una isla dos veces, se
 * debe marcar el nodo como visitado, para que no se
 * vuelva a contar
 * 
 * Para esto podemos crear una matriz de visitados
 * que indique si un nodo ya fue visitado o no (1 si o 0 no)
*/

bool existeVecinoNoVisitado(int matriz[][COLS_TEST], int visitados[][COLS_TEST], int i, int j);
void revisarVecinos(int matriz[][COLS_TEST], int visitados[][COLS_TEST], int i, int j);

int main() {

  int matriz[ROWS_TEST][COLS_TEST] = { 
    { 1, 0, 1, 0, 0, 0, 1, 1, 1, 1},
    { 0, 0, 1, 0, 1, 0, 1, 0, 0, 0},
    { 1, 1, 1, 1, 0, 0, 1, 0, 0, 0},
    { 1, 0, 0, 1, 0, 1, 0, 0, 0, 0},
    { 1, 1, 1, 1, 0, 0, 0, 1, 1, 1},
    { 0, 1, 0, 1, 0, 0, 1, 1, 1, 1},
    { 0, 0, 0, 0, 0, 1, 1, 1, 0, 0},
    { 0, 0, 0, 1, 0, 0, 1, 1, 1, 0},
    { 1, 0, 1, 0, 1, 0, 0, 1, 0, 0},
    { 1, 1, 1, 1, 0, 0, 0, 1, 1, 1}
  };

  int visitados[ROWS_TEST][COLS_TEST];

  // relleamos la matriz de visitados con 0
  for (int i = 0; i < ROWS_TEST; i++) {
    for (int j = 0; j < COLS_TEST; j++) {
      visitados[i][j] = 0;
    }
  }

  int islas = 0;

  // loop que recorre la matriz
  for (int i = 0; i < ROWS_TEST; i++) {
    for (int j = 0; j < COLS_TEST; j++) {
      // Revisamos que el nodo actual sea 1 y que no haya sido visitado
      if (matriz[i][j] == 1 && visitados[i][j] != true) {
        revisarVecinos(matriz, visitados, i, j);
        islas++;
      }
    }
  }

  cout << islas << endl;

  return 0;
}

bool existeVecinoNoVisitado(int matriz[][COLS_TEST], int visitados[][COLS_TEST], int i, int j) {
  if (i >= 0 && i < ROWS_TEST && j >= 0 && j < COLS_TEST) {
    if (matriz[i][j] == 1 && visitados[i][j] == 0) {
      return true;
    }
  }
  return false;
}

void revisarVecinos(int matriz[][COLS_TEST], int visitados[][COLS_TEST], int i, int j) {

  visitados[i][j] = 1;

  // revisar vecino superior izquierdo
  if (existeVecinoNoVisitado(matriz, visitados, i-1, j-1) == true) {
    revisarVecinos(matriz, visitados, i-1, j-1);
  }

  // revisar vecino superior
  if (existeVecinoNoVisitado(matriz, visitados, i-1, j) == true) {
    revisarVecinos(matriz, visitados, i-1, j);
  }

  // revisar vecino superior derecho
  if (existeVecinoNoVisitado(matriz, visitados, i-1, j+1) == true) {
    revisarVecinos(matriz, visitados, i-1, j+1);
  }

  // revisar vecino izquierdo
  if (existeVecinoNoVisitado(matriz, visitados, i, j-1) == true) {
    revisarVecinos(matriz, visitados, i, j-1);
  }

  // revisar vecino derecho
  if (existeVecinoNoVisitado(matriz, visitados, i, j+1) == true) {
    revisarVecinos(matriz, visitados, i, j+1);
  }

  // revisar vecino inferior izquierdo
  if (existeVecinoNoVisitado(matriz, visitados, i+1, j-1) == true) {
    revisarVecinos(matriz, visitados, i+1, j-1);
  }

  // revisar vecino inferior
  if (existeVecinoNoVisitado(matriz, visitados, i+1, j) == true) {
    revisarVecinos(matriz, visitados, i+1, j);
  }

  // revisar vecino inferior derecho
  if (existeVecinoNoVisitado(matriz, visitados, i+1, j+1) == true) {
    revisarVecinos(matriz, visitados, i+1, j+1);
  }

}