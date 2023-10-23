/*
 * Universidad Autonoma de Aguascalientes
 * Centro de Ciencias Basicas
 * Departamento de Ciencias Computacionales
 * Optimizacion Inteligente
 * Diego Emilio Moreno Sanchez (ID 264776)
 * Profesor: Dr. en C. Luis Fernando Gutierrez Marfileno
 * 
 * Problema: ¿De cuántas formas se pueden colocar ocho 
 * torres en el tablero de ajedrez de manera que no se 
 * ataquen mutuamente?
*/

/**
 * Pasos para resolver el problema:
 * 
 * 1. Generar una solución inicial aleatoria de 50 individuos.
 * 2. Mediante la función de evaluación seleccionar a los 10 
 *    mejores individuos
 * 3. Para la siguiente población cada pareja de padres deberá 
 *    procrear diez hijos, los cuales integran la siguiente 
 *    generación con un punto de cruce a la mitad del cromosoma.
 * 4. Agregar una mutación de un individuo por generación, 
 *    el punto de mutación debe ser aleatorio.
 * 5. Determinar soluciones posibles considerando 10 poblaciones
*/

/**
 * Consideraciones:
 * La representación de los individuos se hará mediante un arreglo
 * de 8 elementos, donde cada elemento representa la posición de
 * una torre en el tablero de ajedrez. Ejemplo:
 * 
 * [2,4,0,6,1,3,5,1] (representacion valores de x) -> Individuo
 *
 * [0,0,1,0,0,0,0,0] -> 2
 * [0,0,0,0,1,0,0,0] -> 4
 * [1,0,0,0,0,0,0,0] -> 0
 * [0,0,0,0,0,0,1,0] -> 6
 * [0,1,0,0,0,0,0,0] -> 1
 * [0,0,0,1,0,0,0,0] -> 3
 * [0,0,0,0,0,1,0,0] -> 5
 * [0,1,0,0,0,0,0,0] -> 1
*/

/**
 * Mostrar:
 * 
 * a. De la 1ª población solo el primer cromosoma y su valor de fitness.
 * b. Solamente el primer cromosoma de la última población y además al 
 *    individuo mutado y sus valores de fitness.
*/

#include <iostream>

using namespace std;

void menu() {
  cout << "1. Iniciar Ejecucion problema de las torres" << endl;
  cout << "2. Salir" << endl;
  cout << "Ingrese una opcion: ";
}

// Funcion que genera una solucion inicial aleatoria
void generarPoblacionInicial (int generacion[50][8]) {
  // Generar numeros aleatorios entre 0 y 7
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 8; j++) {
      generacion[i][j] = rand() % 8;
    }
  }
}

// Funcion que muestra la poblacion
void mostrarGeneracion(int generacion[50][8]) {
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 8; j++) {
      cout << generacion[i][j] << " ";
    }
    cout << "- " << i;
    cout << endl;
  }
}

// Funcion que muestra la generacion y su fitness
void mostrarGeneracionFitness(int generacion[50][8], int fitness[50]) {
  for (int i = 0; i < 50; i++) {
    cout << i << " - ";
    for (int j = 0; j < 8; j++) {
      cout << generacion[i][j] << " ";
    }
    cout << " - " << fitness[i];
    cout << endl;
  }
}

// Funcion que calcula el fitness de un individuo
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
    // y toda la columna de la posicion de la torre
    // en el tablero
    for (int j = 0; j < 8; j++) {
      tablero[i][j]++;
      tablero[j][individuo[i]]++;
    }

    // Recorrer el tablero y sumar  los valores de 
    // las posiciones de las torres
    for (int i = 0; i < 8; i++) {
      fitness += tablero[i][individuo[i]]; 
    }

    // if (fitness == 0) {
    //   cout << "Solucion encontrada" << endl;
    //   // mostrar individuo
    //   for (int i = 0; i < 8; i++) {
    //     cout << individuo[i] << " ";
    //   }
    //   cout << endl;
    // }
  }

  return fitness;
}

// Funcion que selecciona a los 10 mejores individuos
void seleccionarPadres(int generacion[50][8], int fitness[50], int padres[10][8]) {
  // Ordenar los individuos de menor a mayor fitness
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) {
      if (fitness[i] < fitness[j]) {
        swap(fitness[i], fitness[j]);
        swap(generacion[i], generacion[j]);
      }
    }
  }

  // Mostrar los 10 individuos con menor fitness con su fitness (mejores)
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 8; j++) {
      padres[i][j] = generacion[i][j];
    }
  }
}

// Funcion para cruzar a los padres
void cruzarPadres(int padres[10][8], int nuevaGeneracion[50][8]) {

  for (int j = 0; j < 50; j += 10) {
    // Seleccionar dos padres aleatorios
    int padre1 = rand() % 10;
    int padre2 = rand() % 10;

    // El punto de cruce es la mitad del cromosoma
    int puntoCruce = 4;

    // Crear 10 hijos
    int hijos[10][8];

    // Copiar los genes de los padres a los hijos
    for (int i = 0; i < 8; i++) {
      // seleccionar entre padre1 y padre2 aleatoriamente
      hijos[0][i] = padres[padre1][i];
      hijos[1][i] = padres[padre2][i];
      hijos[2][i] = padres[padre1][i];
      hijos[3][i] = padres[padre2][i];
      hijos[4][i] = padres[padre1][i];
      hijos[5][i] = padres[padre2][i];
      hijos[6][i] = padres[padre1][i];
      hijos[7][i] = padres[padre2][i];
      hijos[8][i] = padres[padre1][i];
      hijos[9][i] = padres[padre2][i];
    }

    // Cruzar los genes de los padres en el punto de cruce
    for (int i = puntoCruce; i < 8; i++) {
      hijos[0][i] = padres[padre2][i];
      hijos[1][i] = padres[padre1][i];
      hijos[2][i] = padres[padre2][i];
      hijos[3][i] = padres[padre1][i];
      hijos[4][i] = padres[padre2][i];
      hijos[5][i] = padres[padre1][i];
      hijos[6][i] = padres[padre2][i];
      hijos[7][i] = padres[padre1][i];
      hijos[8][i] = padres[padre2][i];
      hijos[9][i] = padres[padre1][i];
    }

    // Agregar los hijos a la nueva generacion
    for (int i = 0; i < 8; i++) {
      nuevaGeneracion[j][i] = hijos[0][i];
      nuevaGeneracion[j+1][i] = hijos[1][i];
      nuevaGeneracion[j+2][i] = hijos[2][i];
      nuevaGeneracion[j+3][i] = hijos[3][i];
      nuevaGeneracion[j+4][i] = hijos[4][i];
      nuevaGeneracion[j+5][i] = hijos[5][i];
      nuevaGeneracion[j+6][i] = hijos[6][i];
      nuevaGeneracion[j+7][i] = hijos[7][i];
      nuevaGeneracion[j+8][i] = hijos[8][i];
      nuevaGeneracion[j+9][i] = hijos[9][i];
    }
  }
}

// Funcion para mutar a un individuo
void mutarIndividuoGeneracion(int generacion[50][8], int mutado) {
  // Seleccionar un gen aleatorio
  int gen = rand() % 8;

  // Cambiar el gen por un valor aleatorio
  generacion[mutado][gen] = rand() % 8;
}

int main() {

  int opcion;

  do {
    menu();
    cin >> opcion;

    if (opcion == 1) {

      int mutado = 0;

      // Generar una solucion inicial aleatoria de 50 individuos.
      int generacion[50][8];
      generarPoblacionInicial(generacion);

      // Mediante la función de evaluación seleccionar a los 10
      int fitness[50];

      // Calcular el fitness de cada individuo
      int acum_fitness = 0; 
      for (int i = 0; i < 50; i++) {
        fitness[i] = calcularFitness(generacion[i]);
        acum_fitness += fitness[i];
      }

      // Mostrar la poblacion y su fitness
      // mostrarGeneracionFitness(generacion, fitness);
      // cout << "Fitness acumulado: " << acum_fitness << endl;

      // Mostrando el primer cromosoma de la primera generacion 
      // y su fitness
      cout << "Primer cromosoma de la primera generacion: ";
      for (int i = 0; i < 8; i++) {
        cout << generacion[0][i] << " ";
      }
      cout << endl;
      cout << "Fitness: " << fitness[0] << endl;


      for (int i = 0; i < 50; i++) {

        // Seleccionar a los 10 mejores individuos
        int padres[10][8];
        seleccionarPadres(generacion, fitness, padres);

        // Cruzar los padres y agregar los hijos a una nueva generacion
        cruzarPadres(padres, generacion);

        // Agregar una mutación de un individuo por generación
        mutado = rand() % 50;
        mutarIndividuoGeneracion(generacion, mutado);

        // Calcular el fitness de cada individuo
        acum_fitness = 0;
        for (int i = 0; i < 50; i++) {
          fitness[i] = calcularFitness(generacion[i]);
          acum_fitness += fitness[i];
        }

        // Mostrar la poblacion y su fitness
        // mostrarGeneracionFitness(generacion, fitness);
        // cout << "Fitness acumulado: " << acum_fitness << endl;

      }

      // Mostrando el primer cromosoma de la ultima generacion
      // y su fitness
      cout << "Primer cromosoma de la ultima generacion: ";
      for (int i = 0; i < 8; i++) {
        cout << generacion[0][i] << " ";
      }
      cout << endl;
      cout << "Fitness: " << fitness[0] << endl;

      cout << "Nota, si el fitness es 8, se encontro una solucion!" << endl;

      // Mostrando el elmento mutado de la ultima generacion
      // y su fitness
      cout << "Elemento mutado de la ultima generacion: ";
      for (int i = 0; i < 8; i++) {
        cout << generacion[mutado][i] << " ";
      }
      cout << endl;
      cout << "Fitness: " << fitness[mutado] << endl;

      cout << "///////////////////////////////////////////////////////////////" << endl;

    } else if (opcion == 2) {
      cout << "Saliendo..." << endl;
    } else {
      cout << "Opcion invalida" << endl;
    }
  } while (opcion != 2);

  return 0;
}