// @utor: Diego Emilio Moreno Sanchez, ID: 264776
// Tiempo de resolucion: 1.5hrs

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

int main() {
  // generamos el arreglo
  srand(time(NULL));
  printf("Ingrese la longitud del arreglo: ");
  scanf("%d", &long_arr);
  int arr[long_arr];
  int n_rep[long_arr];
  int v_rep[long_arr];
  generarArr(long_arr, arr, n_rep, v_rep);
  encontrarRepetidos(arr, n_rep, v_rep, long_arr);
  return 0;
}

void generarArr(int long_arr, int arr[], int n_rep[], int v_rep[]) {
  for (int i = 0; i < long_arr; i++) {
    arr[i] = rand()%10+1;
    n_rep[i] = 0;
    v_rep[i] = 0;
  }
}


void encontrarRepetidos(int arr[], int n_rep[], int v_rep[], int long_arr) {
  int k = 1;    // contador para ver cuantas veces se repite cada num
  int l = 0;    // contador de la cantidad de numeros que se repiten
  bool encontrado = false;
  for(int i = 0; i < long_arr; i++) {
    for (int m = 0; m < l; m++) {
      if (n_rep[m] == arr[i]) {
        encontrado = true;
      }
    }
    for(int j = 0; j < long_arr; j++) {
      if (arr[i] == arr[j] && j != i) {
        if (encontrado == false) {
          k = k + 1;
          printf("aqui\n");
          n_rep[l] = arr[i];
          v_rep[l] = k;
        }
      }
    }
    l++;
    encontrado = false;
    k = 1;
  }
  printf("\nArreglo original\n");
  for (int i = 0; i < long_arr; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  for (int i = 0; i < long_arr; i++){
    printf("\nArreglo de encontrados\n");
    printf("%d - %d veces\n", n_rep[i], v_rep[i]);
  }
  
}