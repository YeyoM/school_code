/*
 * Universidad Autónoma de Aguascalientes
 * Centro de Ciencias Básicas
 * Departamento de Ciencias de la Computación
 * Programación Científica Examen Parcial 3 Ejercicio 2
 * Diego Emilio Moreno Sánchez
 * Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño
 * 
 * Problema: Encontrar la solución aproximada a la integral de:
 * 
 * cos^3(x) dx, evaluado en el intervalo [0, pi/2]
 * 
 * Aplicando la regla de los trapecios y tomando en cuenta cuatro subintervalos
*/
#include <iostream>
#include <cmath>

using namespace std;

void menu() {
  cout << "Programa para encontrar la solucion aproximada a la integral de: " << endl;
  cout << "cos^3(x) dx, evaluado en el intervalo [0, pi/2]" << endl;
  cout << "Aplicando la regla de los trapecios y tomando en cuenta cuatro subintervalos" << endl;
  cout << "1. Encontrar la solucion aproximada" << endl;
  cout << "2. Salir" << endl;
  cout << "Opcion: ";
}

float funcion(float x) {
  return pow(cos(x), 3);
}

int main() {

  int opcion;

  do {

    menu();
    cin >> opcion;

    if (opcion == 1) {

      int n = 4;
      float a = 0;
      float b = M_PI / 2;

      float h = (b - a) / n;

      float sumatoria = funcion(a);

      for (float i = a + h; i <= b; i += h) {
        sumatoria += 2 * funcion(i);
      }

      sumatoria *= h / 2;

      cout << "La solucion aproximada es: " << sumatoria << endl;
      cout << endl;

    } else if (opcion == 2) {
      cout << "Saliendo..." << endl;
    } else {
      cout << "Opcion invalida" << endl;
    }

  } while (opcion != 2);

  return 0;
}