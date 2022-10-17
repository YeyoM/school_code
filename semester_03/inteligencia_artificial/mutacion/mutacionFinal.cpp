/**
 * Algoritmo de cruzamiento de bits
 * 
 * Inteligencia Artificial UAA
 * 
 * Autores:
 * - Dante Alejandro alegría Romero      
 * - Diego Alberto Aranda                        
 * - Andrea Margarita Balandran Felix  
 * - María Yoselin García Medina                
 * - Moreno Sánchez Diego Emilio @YeyoM        
 * 
 * Fecha: 10/10/2022
 * 
*/

// Librerias
#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <iterator>
#include <cstring>
using namespace std;

/**
 * Función para contar el número de veces que aparece un caracter en una cadena
 * @param c Caracter a contar
 * @param str Cadena a buscar
 * @return El número de veces que aparece el caracter c en la cadena str
*/
size_t countOccurrences(char c, string &str) {
  size_t count = 0;
  for (char i : str) {
    if (i == c) {
      count++;
    }
  }
  return count;
}

/**
 * Función para generar un número aleatorio entre un rango
 * @param minimo El número mínimo que se desea generar
 * @param maximo El número máximo que se desea generar
*/
int aleatorioEnRango(int minimo, int maximo) {
  return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

/**
 * Función para generar una cadena aleatoria
 * @param longitud La longitud de la cadena a generar
 * @param destino La cadena donde se almacenará la cadena aleatoria
*/
int cadenaAleatoria(int longitud, char *destino) {
  char muestra[] = "01";
  for (int x = 0; x < longitud; x++) {
    int indiceAleatorio = aleatorioEnRango(0, (int) strlen(muestra) - 1);
    destino[x] = muestra[indiceAleatorio];
  }
}

/**
 * Función para obtener el número mayor de ceros en un arreglo
 * @param arr El arreglo de números
 * @param n El número de elementos en el arreglo
 * @return El número mayor de ceros en el arreglo
*/
int largestAmountCeros(int arr[], int n) {
  int i;
  int max = arr[0];
  for (i = 0; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

bool existsInArray(int arr[], int n, int x) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == x) {
      return true;
    }
  }
  return false;
}

int getRandomIndex(int arr[], int n) {
  int index = aleatorioEnRango(0, n - 1);
  while (existsInArray(arr, n, index)) {
    index = aleatorioEnRango(0, n - 1);
  }
  return index;
}

string generateChildren(string &parent1, string &parent2) {
  int index = aleatorioEnRango(0, parent1.length() - 1);
  string child = parent1.substr(0, index) + parent2.substr(index, 9);
  return child;
}

bool compareChildrenParents(string &child, string &parent) {
  int cerosHijo = countOccurrences('0', child);
  int cerosPadre = countOccurrences('0', parent);
  return cerosHijo > cerosPadre;
}

int getIndividuosConDiezCeros(string individuos[], int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (countOccurrences('0', individuos[i]) == 10) {
      count++;
    }
  }
  return count;
}

void mostrarGeneracion(string individuos[], int n) {
  for (int i = 0; i < n; i++) {
    cout << individuos[i] << endl;
  }
}

int main() {

  srand(time(NULL));
  
  /* Definiendo la longitud de la cadena a generar. */
  #define LONGITUD_DESEADA 10
  
  /* Definiendo el número de individuos a generar. */
  #define NUMERO_DE_CADENAS 125

  /* Inicializando el generador de números aleatorios con el ID del proceso del programa. */
  srand(getpid());

  char auxiliar = '0';

  /* Definiendo el arreglo de cadenas. */
  string binarios1[NUMERO_DE_CADENAS][NUMERO_DE_CADENAS];

  /* Definiendo el arreglo de cadenas. (copia) */
  string binariosCopy1[NUMERO_DE_CADENAS][NUMERO_DE_CADENAS];

  /* Definiendo el arreglo de chars para cuando generamos las cadenas */
  char destino[LONGITUD_DESEADA + 1] = "";

  /* Definiendo el arreglo de números para guardar el número de ceros en cada cadena. */
  int ceros[LONGITUD_DESEADA + 1];

  /* Cuenta de el numero de individuos con todos ceros en la generacion */
  int individuosCeros = 0;

  int suma = 0;
  int cerosIndividuo = 0;

  for (int k = 0; k < NUMERO_DE_CADENAS; k++) {
    
    cout << "--------------------------" << endl;
	  cout << "Generacion " << k + 1 << endl;
	  cout << "--------------------------" << endl;

    /* Generando las cadenas aleatorias. (solo en generacion 1)*/
    if (k == 0) {
      for (int i = 0; i < 10; i++) {
        cadenaAleatoria(LONGITUD_DESEADA, destino);
        binarios1[k][i] = destino;
        binariosCopy1[k][i] = binarios1[k][i];
        ceros[i] = countOccurrences(auxiliar, binarios1[k][i]);
      }
    } else {

      // Seleccionamos 6 elementos al azar de la generacion anterior
      int indicesAleatorios[6];
      for (int i = 0; i < 6; i++) {
        int indiceAleatorio = getRandomIndex(indicesAleatorios, 10);
        indicesAleatorios[i] = indiceAleatorio;
      }

      // Cruzamos los 6 elementos seleccionados
      for (int i = 0; i < 6; i++) {
        string nuevaCadena = generateChildren(binarios1[k-1][indicesAleatorios[i]], binarios1[k-1][indicesAleatorios[6-i]]);
        if (compareChildrenParents(nuevaCadena, binarios1[k-1][indicesAleatorios[i]])) {
          binarios1[k][i] = nuevaCadena;
        } else {
          binarios1[k][i] = binarios1[k-1][indicesAleatorios[i]];
        }
        binariosCopy1[k][i] = binarios1[k][i];
        ceros[i] = countOccurrences(auxiliar, binarios1[k][i]);
      }

      // Seleccionamos 4 elementos restantes
      int indicesNoAleatorios[4];
      int noSeleccionados = 0;
      int iterador2 = 0;

      // Ingresar los 4 elementos que no se seleccionaron
      for (int j = 0; j < 10; j++) {
        bool exists = existsInArray(indicesAleatorios, 10, j);
        if (!exists) {
          indicesNoAleatorios[iterador2] = j;
          iterador2++;
          noSeleccionados++;
        }
      }

      // Ingresamos los 4 elementos restantes
      for (int i = 6; i < 10; i++) {
        binarios1[k][i] = binarios1[k-1][indicesNoAleatorios[i-6]];
        binariosCopy1[k][i] = binarios1[k][i];
        ceros[i] = countOccurrences(auxiliar, binarios1[k][i]);
      }

      // Ordenando
      for (int i = 0; i < 10; i++) {
        int max_ceros = largestAmountCeros(ceros, 10);
        int index = 0;
        for (int j = 0; j < 10; j++) {
          if (ceros[j] == max_ceros) {
            index = j;
            break;
          }
        }
        binarios1[k][i] = binariosCopy1[k][index];
        ceros[index] = -1;
      }

      // Ordenando las copias 
      for (int i = 0; i < 10; i++) {
        binariosCopy1[k][i] = binarios1[k][i];
      }

      // contamos cuantos individuos de la generacion tienen 10 ceros
      individuosCeros = getIndividuosConDiezCeros(binarios1[k], 10);

      if (individuosCeros < 8) {
        // Seleccionamos 2 elementos al azar de la generacion anterior (los ultimos 5)
        int indicesParaMutacion[2];
        int seleccionados = 0;
        int iterador = 0;
        int indiceParaMutacion;

        while(seleccionados < 2) {
          // en caso de que haya mas de cinco elementos con diez ceros
          // solo tomamos lo elelemntos que aun no tienen 10 ceros
          if (individuosCeros >= 5) {
            indiceParaMutacion = aleatorioEnRango(individuosCeros, 9);
          } else {
            indiceParaMutacion = aleatorioEnRango(5, 9);
          }
          bool exists = existsInArray(indicesParaMutacion, 2, indiceParaMutacion);
          if (!exists) {
            indicesParaMutacion[iterador] = indiceParaMutacion;
            iterador++;
            seleccionados++;
          }
        }

        // Mutamos los 2 elementos seleccionados
        for (int i = 0; i < 10; i++) {
          int numBits = aleatorioEnRango(1, 4);
          if (i == indicesParaMutacion[0] || i == indicesParaMutacion[1]) {
            for (int j = 0; j < numBits; j++) {
              int indiceBit = aleatorioEnRango(0, 9);
              if (binarios1[k][i][indiceBit] == '0') {
                binarios1[k][i][indiceBit] = '1';
                binariosCopy1[k][i][indiceBit] = '1';
              } else {
                binarios1[k][i][indiceBit] = '0';
                binariosCopy1[k][i][indiceBit] = '0';
              }
            }
          }
        }

        // Contando los 0's de cada cadena
        for (int i = 0; i < 10; i++) {
          ceros[i] = countOccurrences(auxiliar, binarios1[k][i]);
        }       
      }
    }

    // Ordenando
    for (int i = 0; i < 10; i++) {
      // Obtenemos la cadena con mas 0's
      int max_ceros = largestAmountCeros(ceros, 10);
      // Obtenemos el indice de la cadena con mas 0's
      int index = 0;
      for (int j = 0; j < 10; j++) {
        if (ceros[j] == max_ceros) {
          index = j;
          break;
        }
      }
      // Guardamos la cadena con mas 0's en el arreglo original
      // usando el indice de la cadena con mas 0's y el arreglo de copias
      binarios1[k][i] = binariosCopy1[k][index];
      ceros[index] = -1;
    }  

    // Imprimimos la generacion
    for (int i = 0; i < 10; i++) {
      cout << i + 1 << ":" << binarios1[k][i] << ":";
      cerosIndividuo = countOccurrences(auxiliar, binarios1[k][i]);
      suma += cerosIndividuo;
      cout << cerosIndividuo << endl;
    }
    cout << "Suma de 0's: " << suma << endl;

    if (suma == 100) {
      cout << "Se encontraron 10 individuos con 10 ceros" << endl;
      return 0;
    }

    suma = 0;
  }

  return 0;
}
