#include <iostream>
#include <vector>
using namespace std;

/**
 * Algoritmo de emparejamiento maximo de vertices de un grafo
 * @param matriz Matriz de adyacencia del grafo (no necesariamente bipartito)
*/

#define nodos 8 

int main() {

  // (NODOS 0, 2, 4, 6 conjunto 1) 
  // (NODOS 1, 3, 5, 7 conjunto 2)

  int matriz[nodos][nodos] = {
    {0, 1, 0, 1, 0, 1, 0, 0},
    {1, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0},
  };

  return 0;
}