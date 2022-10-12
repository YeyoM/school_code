#include <iostream>
using namespace std;

/**
 * Algoritmo de Dijkstra
 * @param matriz de adyacencia de un grafo ponderado
 * @return array de distancias mínimas del nodo inicial a los demas nodos
 * Referencia: ALGORITMO DE DIJKSTRA por Hugo Torres (https://www.youtube.com/watch?v=UnsRfl6xw2o)
 * @autor: @YeyoM
 * 11/10/2022
 * Clase: Estructura Computacionales avanzadas
*/

/**
 * Procedimiento a seguir:
 * 1. Comenzar en el nodo inicial (0 o a)
 * 2. Cualquier distancia hacia nodos no adyacentes es infinita
 * 3. Tomar que para el primer paso estamos fuera del grafo, 
 *    por lo que, inicialmente, tomaremos como NO contiguos sus
 *    nodos inmediatos adyacentes
 * 4. En cada iteracion identificaremos las distancias hacia cada
 *    uno del resto de los nodos a partir de nuestro nodo de partida,
 *    acumulando el peso de la(s) ruta(s) que vayamos trazando
 * 5. Estas distancias seran etiquetadas inicialmente como temporales
 * 6. Haremos una comparacion entre todas las distancias de la iteracion
 *    misma y de la ruta inmediata anterior para identificar la mas corta
 * 7. Una vez identificada la distancia mas corta, la etiquetaremos como
 *    permanente y se agrega a la ruta de adyacentes
 * 8. Este ultimo nodo se convierte en el nodo de partida para la siguiente
*/

// Definimos las varibles globales

// Matriz para ir decidiendo que caminos tomar
int MatrizCaminosAcumulados[6][6];

// Matriz que almacena los nodos ya visitados
int permanentes[6] = {1, 0, 0, 0, 0, 0};

// Matriz que almacena las rutas mas cortas a cada nodo
string rutasAdyacentes[6] = {"a", "", "", "", "", ""};
int rutasAdyacentesInt[6] = {0, 0, 0, 0, 0, 0};
int contadorRutas = 1;

// Matriz que almacena las rutas temporales
string rutasTemporales[6] = {"", "", "", "", "", ""};

int temp[6] = {999, 999, 999, 999, 999, 999};

int minVal = 999;
int indiceMin = 0;

int main() {

  int matriz[6][6] = {
    {0,  10, 0,  0,  0,  9},
    {0,  0,  5,  8,  13, 0},
    {0,  0,  0,  4,  0,  3},
    {0,  0,  0,  0,  2,  5},
    {0,  0,  0,  0,  0,  15},
    {0,  0,  0,  0,  0,  0}
  };

  // Guardamos la primer fila de la matriz en la matriz de caminos acumulados
  for (int i = 0; i < 6; i++) {
    MatrizCaminosAcumulados[0][i] = matriz[0][i];
    if (matriz[0][i] != 0) {
      temp[i] = matriz[0][i];
      rutasTemporales[i] = rutasAdyacentes[contadorRutas - 1];
    }
  }  

  // 6 - 1 por que ya tenemos el nodo inicial (a o 0)
  for (int i = 0; i < 6 - 1; i++) {
    // recorrer la matriz de caminos acumulados
    for (int j = 0; j < 6; j++) {
      if (MatrizCaminosAcumulados[i][j] != 0 && permanentes[j] == 0) {
        temp[j] = MatrizCaminosAcumulados[i][j];
      }
      // onbtenemos el minimo de la matriz temporal
      for (int k = 0; k < 6; k++) {
        if (temp[k] < minVal && permanentes[k] == 0) {
          minVal = temp[k];
          indiceMin = k;
        }
      }
    }
    
    // marcamos el nodo como permanente
    permanentes[indiceMin] = 1;
    // agregamos la ruta al nodo adyacente
    rutasAdyacentes[contadorRutas] = rutasTemporales[indiceMin] + (char)(indiceMin + 97);
    rutasAdyacentesInt[contadorRutas] = temp[indiceMin] + rutasAdyacentesInt[contadorRutas - 1];
    contadorRutas++;
    // recorremos la matriz de caminos acumulados y la actualizamos
    for (int k = 0; k < 6; k++) {
      if (MatrizCaminosAcumulados[i][k] != 0 && permanentes[k] == 0) {
        MatrizCaminosAcumulados[i + 1][k] = MatrizCaminosAcumulados[i][k] + matriz[i + 1][k];
      }
      if (matriz[i + 1][k] != 0 && permanentes[k] == 0) {
        MatrizCaminosAcumulados[i + 1][k] = matriz[i + 1][k] + rutasAdyacentesInt[i];
      }
    }
    // actualizamos el array de rutas temporales
    rutasTemporales[indiceMin] = "";
    for (int k = 0; k < 6; k++) {
      if (MatrizCaminosAcumulados[i + 1][k] != 0 && rutasTemporales[k] == "") {
        rutasTemporales[k] = rutasAdyacentes[contadorRutas - 1];
      }
    }
    // reiniciamos las variables
    minVal = 999;
    indiceMin = 0;
    // imprimimos las rMatrizCaminosAcumulados
    for (int k = 0; k < 6; k++) {
      cout << MatrizCaminosAcumulados[i + 1][k] << " ";
    }
    cout << endl;
  }

  // Imprimimos las rutas
  for (int i = 0; i < 6; i++) {
    cout << rutasAdyacentes[i] << endl;
  }

  return 0;
}