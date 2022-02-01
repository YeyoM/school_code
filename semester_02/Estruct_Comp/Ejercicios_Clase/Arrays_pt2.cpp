// @utor: Diego Emilio Moreno Ssnchez

// Arreglos de diferenctes dimendiones

#include <iostream>
#include <string.h>
using namespace std;

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

}
