/*
Universidad Autonoma de Aguascalientes
Centro de Ciencias Basicas
Departamento de Ciencias de la Computacion
Programacion Cientifica	
Diego Emilio Moreno Sánchez (ID 264776)
*/

/*
Ejercicio 1, examen parcial 1.

Implementar un programa que utilizando el método de Newton resuelva
Minimizar la siguiente función utilizando el Método de Newton

f(x) = 5x^2 + 3x - 2

con un rango de -3 a 3 y un punto de inicio de -0.9 de preferencia
*/

#include <iostream>
#include <math.h>

using namespace std;

float f_x(float x) {
  return 5*pow(x,2) + 3*x - 2;
}

float f_x_prima(float x) {
  return 10*x + 3;
}

float f_x_segunda() {
  return 10;
}

void menu() {
  cout << "Programa que calcula el minimo de una funcion utilizando el metodo de Newton" << endl;
  cout << "f(x) = 5x^2 +3x - 2" << endl;
  cout << "1. Ejecutar el programa" << endl;
  cout << "2. Salir" << endl;
  cout << "Ingrese una opcion: ";
}

void tabla(int k, float x_k, float f_x, float f_x_prima, float f_x_segunda, float min_actual) {
  cout << k << "  |  " << x_k << "  |  " << f_x << "  |  " << f_x_prima << "  |  " << f_x_segunda << "  |  " << x_k - (f_x_prima/f_x_segunda) << "  |  " << min_actual << endl;
}

int main() {

   int opcion;

  do {

    menu();
    cin >> opcion;

    if (opcion == 1) {
      cout << "Ejecutando el programa..." << endl;

      cout << endl;

      float x_0;

      do {
        cout << "Ingrese el valor de x_0 en [-3,3] (Recomendado: -0.9): ";
        cin >> x_0;
      } while (x_0 < -3 || x_0 > 3);

      cout << endl;

      cout << "La primer derivada: f'(x) = 10x + 3" << endl;
      cout << "La segunda derivada: f''(x) = 10" << endl;

      cout << endl;

      float x_k = x_0;
      float error = 0.0001;

      int k = 1; // numero de iteraciones

      cout << "iter  |  x_k  |  f(x)  |  f'(x)  |  f''(x)  |  x_k+1  |  min_actual" << endl;
      cout << "--------------------------------------------------------------------" << endl;

      while (abs(f_x_prima(x_k)) > error) {
        float x_k1 = x_k - (f_x_prima(x_k)/f_x_segunda());
        tabla(k, x_k, f_x(x_k), f_x_prima(x_k), f_x_segunda(), f_x(x_k1));
        x_k = x_k1;
        k++;
      }

      cout << endl;

      cout << "------------------------------------------------" << endl;
      cout << "El valor de x_k es: " << x_k << endl;
      cout << "El minimo de la funcion es: " << f_x(x_k) << endl;
      cout << "------------------------------------------------" << endl;

      cout << endl;

    } else if (opcion == 2) {
      cout << "Saliendo del programa..." << endl;
      break;
    } else {
      cout << "Opcion no valida" << endl;
    }

  } while (opcion != 2);

  return 0;
}
