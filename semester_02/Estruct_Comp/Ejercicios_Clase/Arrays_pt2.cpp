// @utor: Diego Emilio Moreno Ssnchez

// Arreglos de diferenctes dimendiones

#include <iostream>
#include <string.h>
using namespace std;

// pasar un array como parametro de funciones
void suma_arreglo(int arr[]);

int main(){

  // Bidimensional
  int arr[2][3];

  ////////////////////////////////////////////////

  // Bidimensional con variables
  int fila = 2,
      columna = 6;

  string arrString[fila][columna];

  /////////////////////////////////////////////////

  // Tridimensional
  int arr3[3][2][3];

  /////////////////////////////////////////////////

  // Bidimensional Constante
  int arr4[2][2] = { {2, 3}, {3, 1} }

  // Tridimensional Constante
  int arr5[3][2][3] = {
    {
      {2, 3, 4}, 
      {3, 1, 7}
    }, {
      {2, 3, 5}, 
      {3, 1, 9}
    }, {
      {2, 3, 3}, 
      {3, 1, 7}
    }
  }

  // llamado a funcion con paso de parametro
  suma_arreglo(arr5);

  return 0;

}

// implementacion de la funcion
void suma_arreglo(int arr[]) {
  int suma,
      i;
  
  for(i = 0; i < 3; i++) {
    suma = suma + arr[i];
  }

  cout<<endl<<"La suma del arreglo: "<<suma;
}
