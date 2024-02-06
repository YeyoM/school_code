/**
 * Universidad Autonoma de Aguascalientes
 * Centro de Ciencias Basicas
 * Departamento de Ciencias de la Computacion
 * Programacion Cientifica	
 * Diego Emilio Moreno Sánchez (ID 264776)
 * Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño
 *
 * Se tiene una instancia del problema del agente viajero con 10 ciudades,
 * el objetivo es encontrar el menor recorrido, en el que, partiendo de una
 * ciudad se pase una vez por todas las demás y se regrese a la ciudad inicial.
 *
 * En este caso hay 10 (1 - 10) ciudades, y siempre se tiene que inicial por la ciudad 1
 * y la ciudad final tambien debe ser la 1.
 *
 * Las coordenadas de las ciudades son:
 *
 * 1  - (5, 4)
 * 2  - (7, 4)
 * 3  - (5, 6)
 * 4  - (4, 3)
 * 5  - (3, 6)
 * 6  - (4, 5)
 * 7  - (2, 4)
 * 8  - (1, 3)
 * 9  - (1, 5)
 * 10 - (3, 2)
*/

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <string>


using namespace std;

#define INVALID         -1
#define NUM_CIUDADES    10
#define NUM_HORMIGAS    5
#define FEROMONA        1
#define ALFA            1
#define BETA            2
#define MAX_ITERACIONES 150
#define EVAPORACION     0.5

struct hormiga {
	double distancia_recorrida;
	double fitness;
	int posicion;
	int camino[NUM_CIUDADES + 1];
};

int coordenadas_ciudades[NUM_CIUDADES][2] = {
  {5, 4},
  {7, 4},
  {5, 6},
  {4, 3},
  {3, 6},
  {4, 5},
  {2, 4},
  {1, 3},
  {1, 5},
  {3, 2}
};

hormiga hormigas[NUM_HORMIGAS];
double rastros_feromonas[NUM_CIUDADES][NUM_CIUDADES];
double distancia_ciudades[NUM_CIUDADES][NUM_CIUDADES];

double distancia_mas_corta = 1000000000;
double distancia_mas_larga = 0;

double mejor_fitness;
double peor_fitness;

int mejor_camino[NUM_CIUDADES + 1];
int peor_camino[NUM_CIUDADES + 1];

int distancia_mayor = INVALID;

void inicializar_distancias_ciudades();
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
void mostrar_camino(int indice_hormiga, int camino[NUM_CIUDADES + 1], double distancia);
string numero_a_string(double n);
void mostrar_resultado();

void menu() {
  cout << "Programa que resuelve el problema del agente viajero" << endl;
  cout << "1. Iniciar ejecucion con Colonia de Hormigas" << endl;
  cout << "2. Salir" << endl;
}

int main() {

  int opcion;
	int iteracion = 0;

  do {

    menu();
    cin >> opcion;

    if (opcion == 1) {
      // Ejecucion del programa
      srand(static_cast<unsigned>(time(0)));
      inicializar_distancias_ciudades();
      inicializar_camino_feromonas(false);
	    obtener_distancia_mayor();
      while (iteracion < MAX_ITERACIONES) {
	    	posible_solucion();
	    	revisar_distancia_mas_corta();
	    	calcular_fitness();
	    	evaporacion_feromonas();
	    	actualizar_feromonas();
	    	//for (int i = 0; i < NUM_HORMIGAS; i++) {
	    	//	mostrar_camino(i, hormigas[i].camino, hormigas[i].distancia_recorrida);
	    	//}
	    	iteracion++;
	    }

	    mostrar_resultado();
    }

    else if (opcion == 2) {
      cout << "Saliendo..." << endl;
    }

    else {
      cout << "Opcion invalida :(" << endl;
    }

  } while (opcion != 2);

  return 0;
}

void inicializar_distancias_ciudades() {
  for (int i = 0; i < NUM_CIUDADES; i++) {
    for (int j = 0; j < NUM_CIUDADES; j++) {
      if (i == j) {
        distancia_ciudades[i][j] = INVALID;
      } else {
        double distancia_ = sqrt(pow(coordenadas_ciudades[i][0] - coordenadas_ciudades[j][0], 2) + pow(coordenadas_ciudades[i][1] - coordenadas_ciudades[j][1], 2));
        distancia_ciudades[i][j] = distancia_;
      }
    }
  }
}


void inicializar_hormiga(int index) {
	hormigas[index].distancia_recorrida = 0;
	hormigas[index].fitness = 0;
	hormigas[index].posicion = 0;
	for (int j = 0; j < NUM_CIUDADES; j++) {
		hormigas[index].camino[j] = INVALID;
	}
	int ciudad_inicial = 0;
	hormigas[index].camino[0] = ciudad_inicial;
  hormigas[index].camino[NUM_CIUDADES + 1] = ciudad_inicial;
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
		double fitness = (double) hormigas[i].distancia_recorrida;
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
		double feromona_ = 0.5d / hormigas[i].fitness;
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

void mostrar_camino(int indice_hormiga, int camino[NUM_CIUDADES + 1], double distancia) {
	string temp = "Ruta tomada por la hormiga: ";
	for (unsigned int i = 0; i < NUM_CIUDADES + 1; i++) {
		temp += numero_a_string(camino[i] + 1);
		if ((i + 1) != NUM_CIUDADES + 1) {
			temp += " => ";
		}
	}
	temp += " | Distancia recorrida: " + numero_a_string(distancia) + "\n";
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