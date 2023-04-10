// Universidad Autonoma de Aguascalientes
// Centro de Ciencias Basicas
// Departamento de Ciencaas de la Computacion
// Programacion Cientifica
// Diego Emilio Moreno Sánchez
// Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño

/*
Universidad Autonoma de Aguascalientes
Centro de Ciencias Básicas
Departamento de Ciencias de la computación
Programación cientifica
Diego Emilio Moreno Sanchéz
Diego Emanuel Saucedo Ortega
Carlos Daniel Torres Macías

Se va a crear un programa que ejecute la evaluación
del método de la Regla de Cramer para el siguiente sistema
de ecuaciones lineales.

 2x1 – x2 + 6x3 = 77
-3x1 + 4x2 - 5x3 = -30
8x1 – 7x2 – 9x3 = -133

Se debe desplegar un menú para ejecutar el método y una opción
para salir del sistema.

Al seleccionar ejecutar el método el usuario debe proporcionar :
la dimensión del sistema y los coeficientes necesarios del sistema
Una vez realizada cualquier operación  debe regresar al menú principal.
Al salir debe detener el programa y luego regresar el control al sistema inicial.
*/

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
  int opcion;
  int n;
  float a[3][3], b[3], x[3], d, d1, d2, d3;
  do {
    cout << "1. Ejecutar el metodo de Cramer" << endl;
    cout << "2. Salir" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    switch (opcion) {
    case 1:
      cout << "Ingrese la dimension del sistema: ";
      cin >> n;
      cout << "Ingrese los coeficientes del sistema: " << endl;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          cout << "a[" << i << "][" << j << "]: ";
          cin >> a[i][j];
        }
      }
      cout << "Ingrese los terminos independientes: " << endl;
      for (int i = 0; i < n; i++) {
        cout << "b[" << i << "]: ";
        cin >> b[i];
      }
      d = a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[2][0] + a[0][2] * a[1][0] * a[2][1] - a[0][2] * a[1][1] * a[2][0] - a[0][1] * a[1][0] * a[2][2] - a[0][0] * a[1][2] * a[2][1];
      if (d == 0) {
        cout << "El sistema no tiene solución" << endl;
        break;
      }
      d1 = b[0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * b[2] + a[0][2] * b[1] * a[2][1] - a[0][2] * a[1][1] * b[2] - a[0][1] * b[1] * a[2][2] - b[0] * a[1][2] * a[2][1];
      d2 = a[0][0] * b[1] * a[2][2] + b[0] * a[1][2] * a[2][0] + a[0][2] * a[1][0] * b[2] - a[0][2] * b[1] * a[2][0] - b[0] * a[1][0] * a[2][2] - a[0][0] * a[1][2] * b[2];
      d3 = a[0][0] * a[1][1] * b[2] + a[0][1] * b[1] * a[2][0] + b[0] * a[1][0] * a[2][1] - b[0] * a[1][1] * a[2][0] - a[0][1] * a[1][0] * b[2] - a[0][0] * b[1] * a[2][1];
      x[0] = d1 / d;
      x[1] = d2 / d;
      x[2] = d3 / d;
      cout << "x1 = " << x[0] << endl;
      cout << "x2 = " << x[1] << endl;
      cout << "x3 = " << x[2] << endl;
      break;
    case 2:
      exit(0);
      break;
    default:
      cout << "Opcion no valida" << endl;
      break;
    }
  } while (opcion != 2);
  return 0;
}