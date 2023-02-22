// Diego Emilio Moreno Sánchez
#include <iostream>
#include <stdlib.h>

using namespace std;

bool busquedaBinaria(int arr[], int tam, int valor) {
  int inicio = 0;
  int fin = tam - 1;
  int medio;
  while (inicio <= fin) {
    medio = (inicio + fin) / 2;
    if (arr[medio] == valor) {
      return true;
    } else if (arr[medio] < valor) {
      inicio = medio + 1;
    } else {
      fin = medio - 1;
    }
  }
  return false;
}

//Busqueda binaria
int main() {
  int arr[] = {5, 2, 4, 6, 1, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  bool encontrado = busquedaBinaria(arr, n, 5);
  cout << encontrado << endl;
  return 0;
}