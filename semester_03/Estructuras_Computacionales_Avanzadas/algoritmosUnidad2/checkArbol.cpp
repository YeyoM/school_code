#include <iostream>
using namespace std;

/**
 * Algoritmo que a partir de una matriz de adyacencia de un grafo no dirigido 
 * determina si es un arbol o no
 * @param matriz de adyacencia de un grafo no dirigido
 * @return true si es un arbol, false si no lo es
 * Referencia: Unidad 9: Arboles (definiciones y propiedades) (https://www.youtube.com/watch?v=r-rJePaU9wI)
 * @autor: @YeyoM
 * 13/10/2022
 * Clase: Estructura Computacionales avanzadas
*/

/**
 * Un grafo es un arbol si:
 * 1. si el grafo no tiene ciclos
 * 2. si el grafo es conexo
 * 3. el arbol tiene exactamente n-1 aristas (n -> numero de vertices)
*/

// Verificar cuantas aristas tiene el grafo
int contadorAristas = 0;

// Array que almacena los nodos visitados de un grafo
int visitados[5] = {0, 0, 0, 0, 0};
int iteradorVisitados = 0;

int main() {

  int matriz [5][5] = {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {1, 0, 0, 0, 1},
    {0, 0, 0, 1, 0}
  };

  for (int i = 0; i < 5; i++) {
    for (int j = i; j < 5; j++) {
      if (matriz[i][j] == 1) {
        contadorAristas++;
      }
      if (visitados[j] == 0 && matriz[i][j] == 1) {
        visitados[j] = 1;
        iteradorVisitados++;
      }
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (visitados[j] == 0 && matriz[i][j] == 1) {
        visitados[j] = 1;
        iteradorVisitados++;
      }
    }
  }

  // cout << "El grafo tiene " << contadorAristas << " aristas" << endl;
  // cout << "El grafo tiene " << iteradorVisitados << " nodos visitados" << endl;

  // if (iteradorVisitados == 5) {
  //   cout << "El grafo es conexo" << endl;
  // } else {
  //   cout << "El grafo no es conexo" << endl;
  // }

  if (contadorAristas == 5 - 1 && iteradorVisitados == 5) {
    cout << "El grafo es un arbol" << endl;
  } else {
    cout << "El grafo no es un arbol" << endl;
  }

  return 0;
}