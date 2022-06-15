#include <iostream>
using namespace std;

bool busquedaSecuencial(int arr[], int tam, int valor) {
  for (int i = 0; i < tam; i++) {
    if (arr[i] == valor) {
      return true;
    }
  }
  return false;
}

int main() {
  int arr[] = {5, 2, 4, 6, 1, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  bool encontrado = busquedaSecuencial(arr, n, 9);
  cout << encontrado << endl;
  return 0;    
}