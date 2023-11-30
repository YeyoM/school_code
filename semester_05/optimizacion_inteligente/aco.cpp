/**
 * Universidad Autonoma de Aguascalientes
 * Centro de Ciencias Basicas
 * Departamento de Ciencias de la Computacion
 * Programacion Cientifica	
 * Diego Emilio Moreno Sánchez (ID 264776)
 * Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño
 * 
 * Problema: Implementar el Algoritmo de Colonias de Hormigas para resolver el problema del viajero
 * 
 * Problema del viajero:
 * 
 * Se tiene un conjunto de ciudades y se desea encontrar el camino más corto que pase por todas las ciudades.
 * 
 * Solución:
 * 
 * Se implementa el algoritmo de colonias de hormigas para resolver el problema del viajero.
 * 
 * Algoritmo de Colonias de Hormigas:
 * 
 * 1. Inicializar las concentraciones de feromona en cada arista.
 * 2. Para cada hormiga:
 *   2.1. Inicializar la hormiga en una ciudad aleatoria. 
 *   2.2. Mientras la hormiga no haya visitado todas las ciudades:
 *        2.2.1. Calcular la probabilidad de transición a cada ciudad no visitada.
 *               La probabilidad de transición a una ciudad no visitada es proporcional
 *               a la concentración de feromona en la arista que conecta la ciudad actual 
 *               con la ciudad no visitada y a la visibilidad de la ciudad no visitada.
 *        2.2.2. Seleccionar la siguiente ciudad a visitar de acuerdo a la probabilidad 
 *               de transición.
 *        2.2.3. Mover la hormiga a la ciudad seleccionada. 
 *        2.2.4. Actualizar la distancia recorrida por la hormiga.
 * 3. Calcular la aptitud de cada hormiga.
 * 4. Evaporar las concentraciones de feromona en cada arista.
 * 5. Actualizar las concentraciones de feromona en cada arista.
 * 6. Si se cumple el criterio de paro, terminar. En caso contrario, regresar al paso 2.
 * 
 * Criterio de paro:
 * 
 * Se cumple el criterio de paro cuando se alcanza un número máximo de iteraciones.
 * 
 * Como se representa el problema:
 * 
 * Se representa el problema como un grafo completo, donde cada nodo representa una ciudad y cada arista
 * representa la distancia entre dos ciudades. Este grafo se representa como una matriz de adyacencia.
 * 
 * Como se representa la solución:
 * 
 * Se representa la solución como un arreglo de enteros, donde cada entero representa el índice de la ciudad
 * en el arreglo de ciudades. El arreglo de ciudades se representa como un arreglo de enteros, donde cada entero
 * representa el índice de la ciudad en el arreglo de ciudades.
 * 
*/

#include <iostream>
#include <cstdlib> 
#include <string> 
#include <sstream>
#include <math.h> 
#include <ctime>

using namespace std;

#define INVALID         -1
#define NUM_CIUDADES    14
#define NUM_HORMIGAS    30
#define FEROMONA        0.1
#define ALFA            1
#define BETA            2
#define MAX_ITERACIONES 50
#define EVAPORACION     0.5
#define POSITIVE_CONTS  0.75

struct hormiga {
	double distancia_recorrida;
	double fitness;
	int posicion;
	int camino[NUM_CIUDADES];
};

hormiga hormigas[NUM_HORMIGAS];

double rastros_feromonas[NUM_CIUDADES][NUM_CIUDADES];

int distancia_ciudades[NUM_CIUDADES][NUM_CIUDADES] = { 
  { INVALID, 11, 20, 27, 40, 43, 39, 28, 18, 10, 18, 30, 30, 32 }, 
  { 11, INVALID, 9, 16, 29, 32, 28, 19, 11, 4, 17, 23, 21, 24   }, 
  { 20, 9, INVALID, 7, 20, 22, 19, 15, 10, 11, 21, 21, 13, 18   }, 
  { 27, 16, 7, INVALID, 13, 16, 12, 13, 13, 18, 26, 21, 11, 17  },
	{ 40, 29, 20, 13, INVALID, 3, 2, 21, 25, 31, 38, 27, 16, 20   }, 
  { 43, 32, 22, 16, 3, INVALID, 4, 23, 28, 33, 41, 30, 17, 20   }, 
  { 39, 28, 19, 12, 2, 4, INVALID, 22, 25, 29, 38, 28, 13, 17   }, 
  { 28, 19, 15, 13, 21, 23, 22, INVALID, 9, 22, 18, 7, 25, 30   }, 
  { 18, 11, 10, 13, 25, 28, 25, 9, INVALID, 13, 12, 12, 23, 28  }, 
  { 10, 4, 11, 18, 31, 33, 29, 22, 13, INVALID, 20, 27, 20, 23  }, 
  { 18, 17, 21, 26, 38, 41, 38, 18, 12, 20, INVALID, 15, 35, 39 }, 
  { 30, 23, 21, 21, 27, 30, 28, 7, 12, 27, 15, INVALID, 31, 37  }, 
  { 30, 21, 13, 11, 16, 17, 13, 25, 23, 20, 35, 31, INVALID, 5  }, 
  { 32, 24, 18, 17, 20, 20, 17, 30, 28, 23, 39, 37, 5, INVALID  } 
};

int distancia_mas_corta = 1000000000;
int distancia_mas_larga = 0;

double mejor_fitness;
double peor_fitness;

int mejor_camino[NUM_CIUDADES];
int peor_camino[NUM_CIUDADES];

int distancia_mayor = INVALID;

void inicializar_hormiga(int index);
void inicializar_camino_feromonas(bool random);
void obtener_distancia_mayor();
bool revisar_visitado(int indice_hormiga, int posicion);
void posible_solucion();
void revisar_distancia_mas_corta();
void calcular_fitness();
void evaporacion_feromonas();
void actualizar_feromonas();

int numero_aleatorio(int from, int to);
void mostrar_camino(int indice_hormiga, int camino[NUM_CIUDADES], double distancia);
string numero_a_string(double n);
void mostrar_resultado();

int main() {
  srand(static_cast<unsigned>(time(0)));
	int iteracion = 0;

	inicializar_camino_feromonas(false);
	obtener_distancia_mayor();

	while (iteracion < MAX_ITERACIONES) {
		posible_solucion();
		revisar_distancia_mas_corta();
		calcular_fitness();
		evaporacion_feromonas();
		actualizar_feromonas();
		for (int i = 0; i < NUM_HORMIGAS; i++) {
			mostrar_camino(i, hormigas[i].camino, hormigas[i].distancia_recorrida);
		}
		iteracion++;
	}

	mostrar_resultado();

	return 0;
}

void inicializar_hormiga(int index) {
	hormigas[index].distancia_recorrida = 0;
	hormigas[index].fitness = 0;
	hormigas[index].posicion = 0;
	for (int j = 0; j < NUM_CIUDADES; j++) {
		hormigas[index].camino[j] = INVALID;
	}
  // Seleccionando una ciudad aleatoria para iniciar el camino a partir de esa ciudad
	int ciudad_aleatoria = numero_aleatorio(0, (NUM_CIUDADES - 1));
	hormigas[index].camino[0] = ciudad_aleatoria;
}

void inicializar_camino_feromonas(bool random) {
	for (int i = 0; i < NUM_CIUDADES; i++) {
		for (int j = 0; j < NUM_CIUDADES; j++) {
			if (i != j) {
				double feromona_aleatoria = (double) numero_aleatorio(0, 100) / 100.0;
				rastros_feromonas[i][j] = (random == true) ? feromona_aleatoria : FEROMONA;
			} else {
				rastros_feromonas[i][j] = INVALID;
			}
		}
	}
}

void obtener_distancia_mayor() {
	for (int i = 0; i < NUM_CIUDADES; i++) {
		for (int j = 0; j < NUM_CIUDADES; j++) {
			if (distancia_ciudades[i][j] > distancia_mayor) {
				distancia_mayor = distancia_ciudades[i][j];
			}
		}
	}
	distancia_mayor += 1;
}

bool revisar_visitado(int indice_hormiga, int posicion) {
	for (int i = 0; i < NUM_CIUDADES; i++) {
		if (hormigas[indice_hormiga].camino[i] == posicion) {
			return true;
		}
	}
	return false;
}

void posible_solucion() {

	for (int i = 0; i < NUM_HORMIGAS; i++) {
		inicializar_hormiga(i);

		while (hormigas[i].posicion < (NUM_CIUDADES - 1)) {
			int posicion = hormigas[i].posicion;

			double probabilidades[NUM_CIUDADES];

			double sumatoria = 0;
			for (int j = 0; j < NUM_CIUDADES; j++) {
				if (revisar_visitado(i, j) == false) {
					if (rastros_feromonas[posicion][j] >= 0 && distancia_ciudades[posicion][j] >= 0) {
						sumatoria += pow(rastros_feromonas[posicion][j], ALFA) * pow(distancia_mayor - distancia_ciudades[posicion][j], BETA);
					}
				}
			}

			for (int j = 0; j < NUM_CIUDADES; j++) {
				if (revisar_visitado(i, j) == false) {
					if (rastros_feromonas[posicion][j] >= 0 && distancia_ciudades[posicion][j] >= 0) {
						probabilidades[j] = (pow(rastros_feromonas[posicion][j], ALFA) * pow(distancia_mayor - distancia_ciudades[posicion][j], BETA)) / sumatoria;
					} else {
						probabilidades[j] = 0;
					}
				} else {
					probabilidades[j] = 0;
				}
			}

			double aleatorio = (double) numero_aleatorio(0, 100) / 100.0;
			double menor = 0;
			double mayor = 0;

			// Vamos a seleccionar el siguiente nodo
			for (int j = 0; j < NUM_CIUDADES; j++) {
        // siempre y cuando no se haya visitado
				if (revisar_visitado(i, j) == false) {
					mayor += probabilidades[j];
					if (aleatorio >= menor and aleatorio <= mayor) {
						hormigas[i].camino[posicion + 1] = j;
						hormigas[i].distancia_recorrida += distancia_ciudades[posicion][j];
						hormigas[i].posicion += 1;
						break;
					} else {
						menor = mayor;
					}
				}
			}
		}
	}
}

void revisar_distancia_mas_corta() {
	for (int i = 0; i < NUM_HORMIGAS; i++) {
		if (hormigas[i].distancia_recorrida < distancia_mas_corta) {
			distancia_mas_corta = hormigas[i].distancia_recorrida;
			for (int j = 0; j < NUM_CIUDADES; j++) {
				mejor_camino[j] = hormigas[i].camino[j];
			}
		} else if (hormigas[i].distancia_recorrida > distancia_mas_larga) {
			distancia_mas_larga = hormigas[i].distancia_recorrida;
			for (int j = 0; j < NUM_CIUDADES; j++) {
				peor_camino[j] = hormigas[i].camino[j];
			}
		}
	}
}

void calcular_fitness() {
	for (int i = 0; i < NUM_HORMIGAS; i++) {
		double fitness = (double) hormigas[i].distancia_recorrida / (double) distancia_mas_corta;
		if (fitness < mejor_fitness) {
			mejor_fitness = fitness;
		} else if (fitness > peor_fitness) {
			peor_fitness = fitness;
		}
		hormigas[i].fitness = fitness;
	}
}

void evaporacion_feromonas() {
	for (int i = 0; i < NUM_CIUDADES; i++) {
		for (int j = 0; j < NUM_CIUDADES; j++) {
			if (rastros_feromonas[i][j] != INVALID) {
				rastros_feromonas[i][j] = (1 - EVAPORACION) * rastros_feromonas[i][j];
			}
		}
	}
}

void actualizar_feromonas() {
	for (int i = 0; i < NUM_HORMIGAS; i++) {
		double feromona_ = POSITIVE_CONTS / hormigas[i].fitness;
		for (int j = 0; j < (NUM_CIUDADES - 1); j++) {
			int ciudad = hormigas[i].camino[j];
			int siguiente_ciudad = hormigas[i].camino[j + 1];
			if (rastros_feromonas[ciudad][siguiente_ciudad] != INVALID) {
				rastros_feromonas[ciudad][siguiente_ciudad] += feromona_;
			}
		}
	}
}

int numero_aleatorio(int from, int to) {
	return (from < to) ? (rand() % to) + from : 0;
}

void mostrar_camino(int indice_hormiga, int camino[NUM_CIUDADES], double distancia) {
	string temp = "Ruta tomada por la hormiga" + numero_a_string(indice_hormiga) + " : ";
	for (unsigned int i = 0; i < NUM_CIUDADES; i++) {
		temp += numero_a_string(camino[i]);
		if ((i + 1) != NUM_CIUDADES) {
			temp += ", ";
		}
	}
	temp += "Distancia recorrida: " + numero_a_string(distancia) + "\n";
	cout << temp << endl;
}

void mostrar_resultado() {
	cout << "Peor camino:" << endl;
	cout << "Pero fitness:" << peor_fitness << endl;
	mostrar_camino(0, peor_camino, distancia_mas_larga);

	cout << "Mejor Camino:" << endl;
	cout << "Mejor fitness:" << mejor_fitness << endl;
	mostrar_camino(0, mejor_camino, distancia_mas_corta);

}

string numero_a_string(double n) {
	stringstream out;
	out << n;
	return out.str();
}