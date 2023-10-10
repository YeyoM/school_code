/*
 * Universidad Autonoma de Aguascalientes
 * Centro de Ciencias Basicas
 * Departamento de Ciencias Computacionales
 * Optimizacion Inteligente
 * Diego Alberto Aranda Gonzalez (ID 262021)
 * Diego Emilio Moreno Sanchez (ID 264776)
 * Profesor: Dr. en C. Luis Fernando Gutierrez Marfileno
 */

/**
 * Practica 4: Implementar un programa que utilizando la
 * metaheuristica de Recocido Simulado
 * resuelva el problema del Agente Viajero.
 */

#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

void menu() {
  cout << "Programa que resuelve el problema del Agente Viajero utilizando la metaheuristica de Recocido Simulado" << endl;
  cout << "1. Iniciar Ejecucion" << endl;
  cout << "2. Salir" << endl;
  cout << "Ingrese una opcion: ";
}

/**
 * La funcion calcula la distancia entre dos ciudades utilizando sus coordenadas.
 *
 * @param ciudad1x El parametro "ciudad1x" representa la coordenada x de la primera ciudad.
 * @param ciudad1y El parametro "ciudad1y" representa la coordenada y de la primera ciudad.
 * @param ciudad2x El parametro "ciudad2x" representa la coordenada x de la segunda ciudad.
 * @param ciudad2y El parametro "ciudad2y" representa la coordenada y de la segunda ciudad.
 *
 * @return la distancia entre dos ciudades.
 */
int calcularDistancia(int ciudad1x, int ciudad1y, int ciudad2x, int ciudad2y) {
  return sqrt(pow((ciudad1x - ciudad2x), 2) + pow((ciudad1y - ciudad2y), 2));
}

/**
 * La funcion "enfriamiento" calcula la tasa de enfriamiento de un sistema basado en la temperatura
 * inicial, un factor constante y un factor de enfriamiento.
 *
 * @param t0 El parametro "t0" representa la temperatura inicial.
 * @param a El parametro "a" representa la tasa de enfriamiento inicial. Determina que tan rapido
 * disminuye la temperatura inicialmente.
 * @param k El parametro "k" representa la tasa de enfriamiento. Determina que tan rapido disminuye
 * la temperatura con el tiempo.
 *
 * @return el resultado del calculo, que es el valor de "a" multiplicado por "t0" dividido por la
 * suma de 1 y "k".
 */
float enfriamiento(float t0, float a, int k) {
  return a * (t0 / (1 + k));
}

/**
 * La funcion calcula el fitness de una solucion dada sumando las distancias entre ciudades.
 * @param solucion El parametro "solucion" es un arreglo de enteros que representa una solucion a un
 * problema. En este caso, representa una secuencia de ciudades a visitar.
 * @param ciudades El parametro "ciudades" es un arreglo 2D que representa las coordenadas de las
 * ciudades. Tiene 25 filas y 2 columnas. Cada fila representa una ciudad, y la primera columna
 * representa la coordenada x de la ciudad mientras que la segunda columna representa la coordenada y
 *
 * @return el valor de fitness, que es un flotante.
 */
float calcularFitness(int solucion[26], int ciudades[25][2]) {
  float fitness = 0;
  for (int i = 0; i < 26; i++) {
    // calcular la distancia entre las ciudades
    int distancia = calcularDistancia(ciudades[solucion[i] - 1][0], ciudades[solucion[i] - 1][1], ciudades[solucion[i + 1] - 1][0], ciudades[solucion[i + 1] - 1][1]);
    // sumar la distancia al fitness
    fitness += distancia;
  }
  return fitness;
}

// Funcion para mostrar solucion principal
void mostrarSolucion(int solucion[26]) {
  for (int i = 0; i < 26; i++) {
    cout << solucion[i] << " ";
  }
  cout << endl;
}

/**
 * Funcion para generar la poblacion inicial
 * @param poblacionInicial Un arreglo de tamaño 26 que representa la poblacion inicial. El primer y
 * ultimo elemento del arreglo se establecen en 1, y los elementos restantes se llenan con numeros del 2
 * al 25 en un orden aleatorio.
 * @param num El parametro "num" es un arreglo de enteros que contiene los numeros del 2 al 25.
 */
void generarPoblacionInicial(int poblacionInicial[26], int num[24]) {
  poblacionInicial[0] = 1;
  poblacionInicial[25] = 1;

  for (int i = 1; i < 25; i++) {
    int numAleatorio = rand() % 24;
    while (num[numAleatorio] == 0) {
      numAleatorio = rand() % 24;
    }
    poblacionInicial[i] = num[numAleatorio];
    num[numAleatorio] = 0;
  }
}

/**
 * La funcion genera una poblacion vecina por medio de intercambiar dos elementos de manera aleatoria
 * de la poblacion inicial
 *
 * @param poblacionInicial Un array de enteros que representan la poblacion inicial. Con longitud de
 * 26.
 * @param poblacionVecina Un array de enteros que representa la poblacion vecina, sirve para guardar
 * la nueva poblacion generada por la funcion
 */
void generarPoblacionVecina(int poblacionInicial[26], int poblacionVecina[26]) {
  for (int i = 0; i < 26; i++) {
    poblacionVecina[i] = poblacionInicial[i];
  }
  int num1 = 1 + rand() % 24;
  int num2 = 1 + rand() % 24;
  while (num1 == num2) {
    num2 = 1 + rand() % 24;
  }
  int aux = poblacionVecina[num1];
  poblacionVecina[num1] = poblacionVecina[num2];
  poblacionVecina[num2] = aux;
}

int main() {

  int opcion;

  // Poblacion Inicial
  int poblacionInicial[26];

  // Poblacion Vecina
  int poblacionVecina[26];

  // Arreglo con los numeros del 2 al 25
  int num[24];
  for (int i = 0; i < 24; i++) {
    num[i] = i + 2;
  }

  // arreglo de las coordenadas de las ciudades
  int ciudades[25][2] = {{5, 4}, {7, 4}, {5, 6}, {4, 3}, {3, 6}, {4, 5}, {2, 4}, {1, 3}, {1, 5}, {3, 2}, {6, 3}, {7, 7}, {6, 1}, {4, 1}, {1, 1}, {1, 7}, {4, 7}, {7, 2}, {9, 2}, {8, 5}, {10, 4}, {11, 1}, {10, 7}, {13, 6}, {12, 8}};

  // Temperatura Inicial
  float t0 = 1000;

  do {

    menu();
    cin >> opcion;

    if (opcion == 1) {

      cout << "Primera Poblacion: " << endl;

      // Generamos la poblacion inicial
      generarPoblacionInicial(poblacionInicial, num);
      mostrarSolucion(poblacionInicial);

      for (int i = 0; i < 2000; i++) {

        cout << "Iteracion: " << i << " ///////////////////////////////////// " << endl;
        cout << "Temperatura actual: " << t0 << endl;

        // Calculamos el fitness de la solucion actual
        float fitnessActual = calcularFitness(poblacionInicial, ciudades);
        cout << "Poblacion actual: " << endl;
        mostrarSolucion(poblacionInicial);
        cout << "Fitness actual: " << fitnessActual << endl;

        // Generamos una solucion vecina
        generarPoblacionVecina(poblacionInicial, poblacionVecina);

        // Calculamos el fitness de la solucion vecina
        float fitnessVecino = calcularFitness(poblacionVecina, ciudades);
        cout << "Poblacion vecina: " << endl;
        mostrarSolucion(poblacionVecina);
        cout << "Fitness vecino: " << fitnessVecino << endl;

        // Calculamos la diferencia de fitness
        float diferenciaFitness = fitnessVecino - fitnessActual;

        // Si la solucion vecina es mejor que la solucion actual
        if (diferenciaFitness < 0) {
          // La solucion vecina pasa a ser la solucion actual
          for (int j = 0; j < 26; j++) {
            poblacionInicial[j] = poblacionVecina[j];
          }
        }
        else {
          // Si la solucion vecina es peor que la solucion actual
          // Generamos un numero aleatorio entre 0 y 1
          float numAleatorio = (float)rand() / RAND_MAX;
          // cout << "Numero aleatorio: " << numAleatorio << endl;
          // Calculamos la probabilidad de aceptacion
          float probabilidadAceptacion = exp(-diferenciaFitness / t0);
          // cout << "Probabilidad de aceptacion: " << probabilidadAceptacion << endl;
          // Si el numero aleatorio es menor a la probabilidad de aceptacion
          if (numAleatorio <= probabilidadAceptacion) {
            // La solucion vecina pasa a ser la solucion actual
            for (int j = 0; j < 26; j++) {
              poblacionInicial[j] = poblacionVecina[j];
            }
          }
        }
        // Reducimos la temperatura
        t0 = enfriamiento(1000, 0.8, i);
      }
    }

    else if (opcion == 2) {
      cout << "Saliendo del programa..." << endl;
    }

    else {
      cout << "Opcion incorrecta, intente nuevamente!" << endl;
    }

  } while (opcion != 2);

  return 0;
}
