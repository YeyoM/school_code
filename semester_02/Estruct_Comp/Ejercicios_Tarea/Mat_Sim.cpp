// @utor: Diego Emilio Moreno Sanchez, ID: 264776
// 03/02/22

// Programa que verifica si una matriz ingresada
// por el usuario es simetrica o no

#include <iostream>
using namespace std;

int n;
void insertarValores(int mat[][99], int);
void verificarSimetrica(int mat[][99], int);


int main(){
  cout << "Ingrese la longitud n de la matriz: ";
  cin >> n;
  cout << endl;
  // evitar problemas de compilacion
  int matriz[n][99];
  insertarValores(matriz, n);
  // mostrar la matriz para verificar
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << matriz[i][j] << ", ";
    }
      cout << endl;
  }
  verificarSimetrica(matriz, n);
  return 0;
}

void insertarValores(int mat[][99], int n) {
  int valor;
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << "Ingrese el valor de la posicion [" << i << "][" << j << "]: ";
      cin >> valor;
      mat[i][j] = valor;
      cout << endl;
      valor = 0;
    }
  }
}
void verificarSimetrica(int mat[][99], int n) {
  bool simetrica = true;
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if (mat[i][j] != mat[j][i]) {
        simetrica = false;
        break;
      }
    }
  }
  if (simetrica == true) {
    cout << "La matriz es simetrica";
  } else {
    cout << "La matriz no es simetrica";
  }

}


