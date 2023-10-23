/*
 * Universidad Autonoma de Aguascalientes
 * Centro de Ciencias Basicas
 * Departamento de Ciencias Computacionales
 * Optimizacion Inteligente
 * Diego Emilio Moreno Sanchez (ID 264776)
 * Profesor: Dr. en C. Luis Fernando Gutierrez Marfileno
 * 
 * Problema de programación de operaciones (scheduling)
*/

/*
Programar operaciones consiste en el proceso de organizar, 
elegir y dar tiempos al uso de recursos para llevar a cabo 
todas las actividades necesarias para producir las salidas 
deseadas en los tiempos deseados, satisfaciendo a la vez un 
gran número de restricciones de tiempo y relaciones entre 
las actividades y los recursos.

En este ejercicio se considera el problema de Flow-Shop, 
que se caracteriza por que todos las operaciones siguen la 
misma secuencia de producción; la idea es determinar la mejor 
secuencia de trabajos y para ello se podría numerar todas las 
secuencias posibles y elegir aquella que optimiza alguna 
medida de desempeño.

Por ejemplo para una programación de 23 trabajos 
implicaría analizar 23! = 2.59*1022

Se tiene la siguiente matriz de tiempos (cada valor dentro 
de la matriz señala el tiempo necesario para realizar el trabajo).

        Trabajo1 | Trabajo2 | Trabajo3 | Trabajo4
Máquina1    5         1           7         2
Máquina2    8         7           3         2
Máquina3    9         3           6         4

Una secuencia de trabajo para cada maquina se define por un 
vector como el siguiente:

[Trabajo2, Trabajo4, Trabajo1, Trabajo3]

Para generar nuevas soluciones se usa un intercambio o swap 
el cual consiste en seleccionar dos tareas cualesquiera de la 
secuencia e intercambiarlas entre si para obtener un nueva secuencia

* Solucion:  
* El objetivo es definir una matriz que minimice el tiempo 
* de operación de todos los trabajos sin que ninguna maquina 
* repita un trabajo.
*/

//! Los 4 trabajos se tienen que realizar, el problema es:
//! Que maquina realiza cada trabajo? Para que el tiempo sea minimo

/**
 * Procedimiento
 *  1. Generar una solución inicial en forma aleatoria
 *  2. Generar una siguiente solución mediante el intercambio aleatorio de trabajos para cada maquina
 *  3. Partir de una T0 de 1000o hasta una TF de 20o.
 *  4. Utiliza el criterio de Boltzman para el mecanismo de enfriamiento ().
 *  5. Determinar un máximo de 500 iteraciones
*/

/**
 * Desplegar de la 1ª solución y el tiempo requerido para su ejecución.
 * Desplegar la última solución y el tiempo requerido para su ejecución.
*/

#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

int tiempos[3][4] = {
  {5,1,7,2},
  {8,7,3,2},
  {9,3,6,4}
};

void menu() {
  cout << "Programa que resuleve el problema de programacion de operaciones" << endl;
  cout << "1. Iniciar Ejecucion problema de programacion de operaciones" << endl;
  cout << "2. Salir" << endl;
  cout << "Ingrese una opcion: ";
}

// Una solucion sera una combinacion de que maquina realiza cada trabajo (1 - 4)
// Nota. Todas las maquinas tienen que realizar al menos un trabajo
void generarSolucionInicial(int solucion[4]) {
  for (int i = 0; i < 4; i++) {
    solucion[i] = rand() % 3 + 1;
  }
}


// Para generar una solucion vecina se intercambian dos valores de la solucion actual
void generarSolucionVecina(int solucionActual[4], int solucionVecina[4]) {
  // Utilizamos swap
  for (int i = 0; i < 4; i++) {
    solucionVecina[i] = solucionActual[i];
  }
  int num1 = rand() % 4;
  int num2 = rand() % 4;
  while (num1 == num2) {
    num2 = rand() % 4;
  }
  int aux = solucionVecina[num1];
  solucionVecina[num1] = solucionVecina[num2];
  solucionVecina[num2] = aux;

}

// Mostrar la solucion con el tiempo total de ejecucion
void mostrarSolucion(int solucion[4], int tiempos[3][4], int horasTotales) {
  horasTotales = 0;
  for (int i = 0; i < 4; i++) {
    cout << "Trabajo " << i + 1 << " en maquina " << solucion[i] << " con tiempo " << tiempos[solucion[i] - 1][i] << endl;
    horasTotales += tiempos[solucion[i] - 1][i];
  }
  cout << "Tiempo total: " << horasTotales << " horas" << endl;
}

void calcularHorasTotales(int solucion[4], int tiempos[3][4], int horasTotales) {
  horasTotales = 0;
  for (int i = 0; i < 4; i++) {
    horasTotales += tiempos[solucion[i] - 1][i];
  }
}

float enfriamiento(float t0, float a, int k) {
  return a * (t0 / (1 + k));
}

int main() {

  int opcion;

  do {

    menu();
    cin >> opcion;

    if (opcion == 1) {

      // Solucion inicial
      int solucion[4];
      int horasTotales = 0;
      generarSolucionInicial(solucion);
      cout << "Solucion inicial: " << endl;
      mostrarSolucion(solucion, tiempos, horasTotales);

      float t0 = 1000;

      for (int i = 0; i < 500; i++) {
      
        int solucionVecina[4];
        generarSolucionVecina(solucion, solucionVecina);
        int horasTotalesVecina = 0;
        calcularHorasTotales(solucionVecina, tiempos, horasTotalesVecina);

        // Calcular la diferencia de tiempo entre la solucion actual y la solucion vecina
        int diferencia = horasTotalesVecina - horasTotales;

        // Si la diferencia es negativa, la solucion vecina es mejor que la solucion actual
        if (diferencia < 0) {
          for (int i = 0; i < 4; i++) {
            solucion[i] = solucionVecina[i];
          }
        } 
        // en caso contrario
        else {
          // numero aleatorio entre 0 y 1
          float numAleatorio = (float)rand() / RAND_MAX;
          float probabilidadAceptacion = exp(-diferencia / t0);
          if (numAleatorio <= probabilidadAceptacion) {
            for (int i = 0; i < 4; i++) {
              solucion[i] = solucionVecina[i];
            }
          }
        }
        t0 = enfriamiento(t0, 0.9, i);


      }

      // Mostrar ultima solucion
      cout << "Ultima solucion: " << endl;
      mostrarSolucion(solucion, tiempos, horasTotales);




    } else if (opcion == 2) {
      cout << "Saliendo..." << endl;
    } else {
      cout << "Opcion no valida" << endl;
    }

  } while (opcion != 2);

  return 0;
}