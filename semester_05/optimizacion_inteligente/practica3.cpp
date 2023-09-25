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
// 7. Reemplazar la poblacion
// 8. Repetir desde el paso 3 hasta que se cumpla una condicion de paro

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

  // imprimir tablero
  // cout << "Tablero: " << endl;
  // for (int i = 0; i < 8; i++) {
  //   for (int j = 0; j < 8 ; j++) {
  //     cout << tablero[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  // mostrar individuo
  for (int i = 0; i < 8; i++) {
    cout << individuo[i] << " ";
  }

  return fitness;
}


void seleccionarPadres(int generacion[50][8], int fitness[50]) {
  // Seleccionar los mejores 30 padres en base a su fitness
  // En este caso un mejor fitness es aquel con menor puntaje

  // Tomamos los 30 padres de menor fitness
  // Ordenar los arrays
  int temp_[8];

  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) {
      if (fitness[j] > fitness[i]) {
        int temp = fitness[i];
        fitness[i] = fitness[j];
        fitness[j] = temp;

        // for (int k = 0; k < 0; k++) {
        //   temp_[k] = generacion[i][k];
        // }
        // for (int k = 0; k < 0; k++) {
        //   generacion[i][k] = generacion[j][k];
        // }
        // for (int k = 0; k < 0; k++) {
        //   generacion[j][k] = temp_[k];
        // }
      } 
    }
  }

  for (int i = 0; i < 50; i++) {
    cout << fitness[i] << endl;
  }

  mostrarGeneracion(generacion);
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

  if (opcion == 1) {

    // Ejecutar algoritmo genetico
    int generacion[50][8]; // -> 50 individuos de 8 genes cada uno
    int fitness[50];

    // 1. Generar poblacion inicial
    generarPoblacionInicial(generacion);
    mostrarGeneracion(generacion);

    // Este individuo si es solucion
    // int individuo_prueba_1[8] = {2,5,7,1,3,0,6,4};
    // Este individuo no es solucion
    // int individuo_prueba_2[8] = {2,4,0,6,1,3,5,1};

    // int fitness_1 = calcularFitness(individuo_prueba_1);
    // int fitness_2 = calcularFitness(individuo_prueba_2);

    // scout << "Fitness 1: " << fitness_1 << endl;
    // scout << "Fitness 2: " << fitness_2 << endl;    

    // 2. Calcular fitness de cada individuo
    int padres[30];
    int max_indiv = 0; // -> Guardar el fitness mas grande de todos los elementos
    for (int i = 0; i < 50; i++) {
      cout << generacion[i] << " ";
      fitness[i] = calcularFitness(generacion[i]);
      cout << i << " - " << fitness[i] << endl;
    }

    // 3. Seleccionar a los padres
    // Se deben seleccionar los 25 individuos con un menor fitness
    seleccionarPadres(generacion, fitness);

    mostrarGeneracion(generacion);

  }

  else if (opcion == 2) {
    cout << "Saliendo del programa..." << endl;
  }

  else {
    cout << "Opcion invalida" << endl;
  }

  return 0;
}