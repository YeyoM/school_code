// @utor: Diego Emilio Moreno Sanchez, ID: 264776
// Tiempo de resolucion: 1.5hrs

// Breve explicacion sobre como desarrolle la solucion del problema
// Primeramente, la generacion del arreglo es bastante sencillo,
// despues de eso, decidi usar otros dos arreglos auxiliares, en los que
// se relacionan entre ellos por los indices, el primer arreglo muestra el
// numero que se repite y en el segundo las veces que se repite dicho numero.
// En el algoritmo se revisa cada elemento con los demas del arreglo, las veces
// que se encuentre a si mismo, son las veces que se repite, los problemas encontrados
// fueron que se estaban dando numeros repetidos, pero lo pude arreglar con una
// varialble de tipo booleana

// librerias
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// funciones
void generarArr(int long_arr, int arr[], int n_rep[], int v_rep[]);
void encontrarRepetidos(int arr[], int n_rep[], int v_rep[], int long_arr);

// variables iniciales
int long_arr = 0;
int arr[];    // arreglo inicial
int n_rep[];  // arreglo con los valores repetidos
int v_rep[];  // arreglo con las veces que se repite algun numero

// funcion principal
int main() {
  // generamos los arreglos
  srand(time(NULL));
  printf("Ingrese la longitud del arreglo: ");
  scanf("%d", &long_arr);
  int arr[long_arr];
  int n_rep[long_arr];
  int v_rep[long_arr];
  generarArr(long_arr, arr, n_rep, v_rep);
  // encontramos los numeros que se repitan
  encontrarRepetidos(arr, n_rep, v_rep, long_arr);
  return 0;
}

void generarArr(int long_arr, int arr[], int n_rep[], int v_rep[]) {
  // inicializamos los arreglos, el primero con numeros aleatorios y los siguientes con ceros
  for (int i = 0; i < long_arr; i++) {
    arr[i] = rand()%10+1;
    n_rep[i] = 0;
    v_rep[i] = 0;
  }
}

void encontrarRepetidos(int arr[], int n_rep[], int v_rep[], int long_arr) {
  int k = 1;    // contador para ver cuantas veces se repite cada num
  int l = 0;    // contador de la cantidad de numeros que se repiten
  bool encontrado = false;  // esta variable la utilizo para no repetir "encontrados"
  for(int i = 0; i < long_arr; i++) {
    for (int m = 0; m < l; m++) {
      // si el valor de "i" ya se encuentra en el arreglo de n_rep, no tenemos que volver
      // a agragarlo, ya que seria un valor repetido e incorrecto
      if (n_rep[m] == arr[i]) {
        encontrado = true;
      }
    }
    // luego ahora si que verificamos lo enterior, comparamos el valor en la posicion de i
    // con todos los demas en el arreglo, pero menos con el mismo, por eso el "if statement" 
    // de arr[i] == arr[j] && j != i, para que no sea el mismo
    for(int j = 0; j < long_arr; j++) {
      if (arr[i] == arr[j] && j != i) {
        if (encontrado == false) {
          // en caso de que todo se cumpla con normalidad, a k se le aumenta uno,
          // se guarda en la posicion [l] del arreglo de numeros repetidos el valor de arr[i]
          // y aumentamos el contados de cuantas veces se repite dicho numero con v_rep[l]
          k = k + 1;
          n_rep[l] = arr[i];
          v_rep[l] = k;
        }
      }
    }
    // antes de seguir con el siguiente valor de arr[i], seteamos todos los valores a como estaban al inicio
    l++;
    encontrado = false;
    k = 1;
  }

  // mostramos el arreglo original 
  printf("\nArreglo original\n");
  for (int i = 0; i < long_arr; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
  // mostramos los valores que encontramos con numeros repetidos
  for (int i = 0; i < long_arr; i++){
    // use el n_rep[i] == 0 ya que muchos elementos del arreglo son 0
    if (n_rep[i] != 0) {
      printf("El %d se encontro %d veces\n", n_rep[i], v_rep[i]);
    }
  }
}