// Programa que encuentra una solucion para el 
// problema de las 8 reinas por medio de 
// Algortimo Genetico

// Representacion del vector a tablero

// [2,4,0,6,1,3,5,1] (representacion valores de x)

// [0,0,1,0,0,0,0,0] -> 2
// [0,0,0,0,1,0,0,0] -> 4
// [1,0,0,0,0,0,0,0] -> 0
// [0,0,0,0,0,0,1,0] -> 6
// [0,1,0,0,0,0,0,0] -> 1
// [0,0,0,1,0,0,0,0] -> 3
// [0,0,0,0,0,1,0,0] -> 5
// [0,1,0,0,0,0,0,0] -> 1

// Pasos para el algoritmo genetico

// 1. Generar poblacion inicial
// 2. Evaluar la poblacion
// 3. Seleccionar los padres
// 4. Cruzar los padres
// 5. Mutar los hijos
// 6. Evaluar la poblacion
// 7. Repetir desde el paso 3 hasta que se cumpla una condicion de paro

#include <iostream>
#include <algorithm>

using namespace std;


// Funcion para generar numeros aleatorias
void generarPoblacionInicial (int generacion[50][8]) {
  // Generar numeros aleatorios entre 0 y 7
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 8; j++) {
      generacion[i][j] = rand() % 8;
    }
  }
}
  
// Funcion para mostrar la poblacion
void mostrarGeneracion(int generacion[50][8]) {
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 8; j++) {
      cout << generacion[i][j] << " ";
    }
    cout << i;
    cout << endl;
  }
}

int calcularFitness(int individuo[8]) {
  
  int fitness = 0;

  // tablero inicializado con -1's
  int tablero[8][8];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      tablero[i][j] = -1;
    }
  }

  // Recorrer el individuo
  for (int i = 0; i < 8; i++) {
    // Vamos a incrementar en uno las toda la fila
    // y toda la columna de la posicion de la reina
    // en el tablero
    for (int j = 0; j < 8; j++) {
      tablero[i][j]++;
      tablero[j][individuo[i]]++;
    }

    // Vamos a incrementar en uno las diagonales
    // de la posicion de la reina en el tablero

    // Diagonal superior derecha
    int k = i;
    int l = individuo[i];
    while (k >= 0 && l < 8) {
      if (k != i && l != individuo[i]) {
        tablero[k][l]++;
      }
      k--;
      l++;
    }

    // Diagonal superior izquierda
    k = i;
    l = individuo[i];
    while (k >= 0 && l >= 0) {
      if (k != i && l != individuo[i]) {
        tablero[k][l]++;
      }
      k--;
      l--;
    }


    // Diagonal inferior derecha
    k = i;
    l = individuo[i];
    while (k < 8 && l < 8) {
      if (k != i && l != individuo[i]) {
        tablero[k][l]++;
      }
      k++;
      l++;
    }

    // Diagonal inferior izquierda
    k = i;
    l = individuo[i];
    while (k < 8 && l >= 0) {
      if (k != i && l != individuo[i]) {
        tablero[k][l]++;
      }
      k++;
      l--;
    }
  }

  // Recorrer el tablero y sumar  los valores de 
  // las posiciones de las reinas 
  for (int i = 0; i < 8; i++) {
    fitness += tablero[i][individuo[i]]; 
  }

  if (fitness == 8) {
    cout << "Solucion encontrada" << endl;
    // mostrar individuo
    for (int i = 0; i < 8; i++) {
      cout << individuo[i] << " ";
    }
    cout << endl;
  }

  return fitness;
}


void seleccionarPadres(int generacion[50][8], int fitness[50], int padres[25][8]) {
  // Ordenar los individuos de menor a mayor fitness
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) {
      if (fitness[i] < fitness[j]) {
        swap(fitness[i], fitness[j]);
        swap(generacion[i], generacion[j]);
      }
    }
  }

  // Mostrar los 25 individuos con menor fitness con su fitness
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 8; j++) {
      // cout << generacion[i][j] << " ";
      padres[i][j] = generacion[i][j];
    }
    // cout << fitness[i] << " ";
    // cout << i;
    // cout << endl;
  }
}

void cruzarPadres(int padres[25][8], int nuevaGeneracion[50][8]) {

  for (int j = 0; j < 50; j += 2) {
    // Seleccionar dos padres aleatorios
    int padre1 = rand() % 25;
    int padre2 = rand() % 25;

    // Seleccionar un punto de cruce aleatorio
    int puntoCruce = rand() % 8;

    // Crear dos hijos
    int hijo1[8];
    int hijo2[8];

    // Copiar los genes de los padres a los hijos
    for (int i = 0; i < 8; i++) {
      hijo1[i] = padres[padre1][i];
      hijo2[i] = padres[padre2][i];
    }

    // Cruzar los genes de los padres en el punto de cruce
    for (int i = puntoCruce; i < 8; i++) {
      hijo1[i] = padres[padre2][i];
      hijo2[i] = padres[padre1][i];
    }

    // Agregar los hijos a la nueva generacion
    for (int i = 0; i < 8; i++) {
      nuevaGeneracion[j][i] = hijo1[i];
      nuevaGeneracion[j+1][i] = hijo2[i];
    }
  }
}

void mutarGeneracion(int generacion[50][8]) {
  for (int i = 0; i < 50; i++) {
    // Seleccionar un individuo aleatorio
    int individuo = rand() % 50;

    // Seleccionar un gen aleatorio
    int gen = rand() % 8;

    // Cambiar el valor del gen
    generacion[individuo][gen] = rand() % 8;
  }
}

void menu() {
  cout << "Programa que encuentra una solucion para el problema de las 8 reinas por medio de Algortimo Genetico" << endl;
  cout << "1. Iniciar Ejecucion" << endl;
  cout << "2. Salir" << endl;
  cout << "Ingrese una opcion: ";
}

int main() {
  
  int opcion;
  menu();
  cin >> opcion;

  // // Este individuo si es solucion
  // int individuo_prueba_1[8] = {2,5,7,1,3,0,6,4};
  // //Este individuo no es solucion
  // int individuo_prueba_2[8] = {2,4,0,6,1,3,5,1};
  // int fitness_1 = calcularFitness(individuo_prueba_1);
  
  // int fitness_2 = calcularFitness(individuo_prueba_2);
  // cout << "Fitness 1: " << fitness_1 << endl;
  // cout << "Fitness 2: " << fitness_2 << endl;  

  if (opcion == 1) {

    // Ejecutar algoritmo genetico
    int generacion[50][8]; // -> 50 individuos de 8 genes cada uno
    int fitness[50];

    // 1. Generar poblacion inicial
    generarPoblacionInicial(generacion);
    // mostrarGeneracion(generacion);

    // 2. Calcular fitness de cada individuo
    int fitness_acum;
    for (int i = 0; i < 50; i++) {
      fitness[i] = calcularFitness(generacion[i]);
      fitness_acum += fitness[i];
    }
    cout << "Puntuacion generacion: " << fitness_acum << endl;

    for (int i = 0; i < 50; i++) {

      // 3. Seleccionar a los padres
      // Se deben seleccionar los 25 individuos con un menor fitness
      int padres[25][8];
      seleccionarPadres(generacion, fitness, padres);

      // 4. Cruzar los padres y agregar los hijos a una nueva generacion
      cruzarPadres(padres, generacion);

      // 5. Mutar generacion
      mutarGeneracion(generacion);

      // 6. Evaluar la poblacion
      int fitness_acum = 0;
      for (int i = 0; i < 50; i++) {
        fitness[i] = calcularFitness(generacion[i]);
        fitness_acum += fitness[i];
      }
      cout << "Puntuacion generacion: " << fitness_acum << endl;
    }

  }

  else if (opcion == 2) {
    cout << "Saliendo del programa..." << endl;
  }

  else {
    cout << "Opcion invalida" << endl;
  }

  return 0;
}