#include <iostream>
using namespace std;

/**
 * Algoritmo de Kruskal
 * @param matriz de adyacencia de un grafo ponderado
 * @return aristas que forman el arbol de expansion minimo y sus pesos
 * Referencia: S4.4- Algoritmo de Kruskal|UPV (https://www.youtube.com/watch?v=YHzllcQpEdA)
 * @autor: @YeyoM
 * 12/10/2022
 * Clase: Estructura Computacionales avanzadas
*/

/**
 * Procedimiento a seguir:
 * 1. Ordenar las aristas de menor a mayor
 * 2. Tomar la arista de menor peso
 * 3. Si la arista no forma un ciclo, se agrega al arbol de expansion minimo
 * 4. Si la arista forma un ciclo, se descarta
 * 5. Se repite el proceso hasta que el arbol de expansion minimo tenga n-1 aristas
*/

// Guardar los pesos de las artistas de menor a mayor
int pesos[25];
// Guardar las aristas de menor a mayor (sus indices en letras)
string aristas[25];
int iteradorPesos = 0;

// Array que almacena las aristas que forman el arbol de expansion minimo
string aristasArbolExpansionMinimo[6];
int iteradorArbolExpansionMinimo = 0; 

string visitados[10] = {"", "", "", "", "", "", "", "", "", ""};
int iteradorVisitados = 0;

int main() {

  int matriz[5][5] = {
    {0,  4,  9,  11, 5},
    {4,  0,  8,  0,  6},
    {9,  8,  0,  10, 0},
    {11, 0,  10, 0,  12},
    {5,  6, 0,  12, 0}
  };

  // Para optimizar podemos dejar la matriz en su forma triangular superior
  // y solo trabajar con la mitad de la matriz
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (i > j) {
        matriz[i][j] = 0;
      }
    }
  }

  // Guardar los pesos de las artistas de menor a mayor
  for (int i = 0; i < 5; i++) {
    for (int j = i; j < 5; j++) {
      if (matriz[i][j] != 0) {
        pesos[iteradorPesos] = matriz[i][j];
        string arista = "";
        arista += (char)(i + 65);
        arista += (char)(j + 65);
        aristas[iteradorPesos] = arista;
        iteradorPesos++;
      }
    }
  }

  // Mostrar los pesos de las aristas con sus indices
  // cout << "Pesos de las aristas: " << endl;
  // for (int i = 0; i < 36; i++) {
  //   if (pesos[i] != 0) {
  //     cout << aristas[i] << " = " << pesos[i] << endl;
  //   }
  // }

  // Ordenar los pesos de menor a mayor
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 25; j++) {
      if (pesos[i] < pesos[j]) {
        int aux = pesos[i];
        pesos[i] = pesos[j];
        pesos[j] = aux;
        string aux2 = aristas[i];
        aristas[i] = aristas[j];
        aristas[j] = aux2;
      }
    }
  }

  // Mostrar los pesos de las aristas con sus indices
  // cout << "Pesos de las aristas: " << endl;
  // for (int i = 0; i < 36; i++) {
  //   if (pesos[i] != 0) {
  //     cout << aristas[i] << " = " << pesos[i] << " " << i << endl;
  //   }
  // }

  for (int i = 0; i < 25; i++) {
    if (pesos[i] != 0) {
      iteradorPesos = i;
      break;
    }
  }

  while(iteradorArbolExpansionMinimo < 6 - 2) {
    // Tomar la arista de menor peso
    string arista = aristas[iteradorPesos];
    // Si la arista no forma un ciclo, se agrega al arbol de expansion minimo
    // Si la arista forma un ciclo, se descarta
    // Se repite el proceso hasta que el arbol de expansion minimo tenga n-1 aristas
    iteradorPesos++;

    // Si los nodos de la arista se encuentran en el array de visitados, 
    // no se agrega al arbol de expansion minimo, ya que forma un ciclo

    // Revisamos para el primer nodo
    bool estaVisitadoA = false;
    for (int i = 0; i < 6; i++) {
      if (visitados[i] == arista.substr(0, 1)) {
        estaVisitadoA = true;
      }
    }

    // Revisamos para el segundo nodo
    bool estaVisitadoB = false;
    for (int i = 0; i < 6; i++) {
      if (visitados[i] == arista.substr(1, 1)) {
        estaVisitadoB = true;
      }
    }

    // Si ninguno o solo uno de los nodos esta visitado, se agrega al arbol de expansion minimo
    if (!(estaVisitadoA && estaVisitadoB)) {
      aristasArbolExpansionMinimo[iteradorArbolExpansionMinimo] = arista;
      iteradorArbolExpansionMinimo++;
      visitados[iteradorVisitados] = arista.substr(0, 1);
      iteradorVisitados++;
      visitados[iteradorVisitados] = arista.substr(1, 1);
      iteradorVisitados++;
    }
  }

  // Mostrar el arbol de expansion minimo
  cout << "Arbol de expansion minimo: " << endl;
  for (int i = 0; i < 6 - 1; i++) {
    cout << aristasArbolExpansionMinimo[i] << endl;
  }

  return 0;
}