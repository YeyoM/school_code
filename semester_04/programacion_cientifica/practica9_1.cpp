/*
  Universidad Autonoma de Aguascalientes
  Centro de Ciencias Basicas
  Departamento de Ciencaas de la Computacion
  Programacion Cientifica	
  Diego Emilio Moreno Sánchez
  Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño

  Calcular la función de regresión lineal para el siguiente 
  conjunto de datos:

  Cinco niños de 2, 3, 5, 7 y 8 años de edad pesan, 
  respectivamente, 14, 20, 32, 42 y 44 kilos.
  
  Hallar la ecuación de la recta de regresión de la edad sobre el peso.
  ¿Cuál sería el peso aproximado de un niño de seis años?
*/

#include <iostream>
#include <cmath>

using namespace std;

void menu() {
  cout << "1. Calcular la ecuacion de la recta de regresion y resolver el problema" << endl;
  cout << "2. Salir" << endl;
  cout << "Opcion: ";
}

int main() {

  int n = 5, opcion = 0;

  float edades[n] = {2, 3, 5, 7, 8};
  float pesos[n] = {14, 20, 32, 42, 44};

  float sum_x = 0,
        sum_y = 0,
        sum_xy = 0,
        sum_x2 = 0;

  do {

    menu();
    cin >> opcion;

      if (opcion == 1) {
        int i = 0;
        while (i <= n) {
          sum_x += edades[i];
          sum_y += pesos[i];
          sum_xy += edades[i] * pesos[i];
          sum_x2 += edades[i] * edades[i];
          i++;
        }
      
        float a1 = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
        float a0 = (sum_y - a1 * sum_x) / n;
      
        cout << "La ecuacion de la recta de regresion es: " << endl;
        cout << "y = " << a0 << " + " << a1 << "x" << endl;
      
        float x = 6;
        float y = a0 + a1 * x;
      
        cout << "El peso aproximado de un nino de 6 anios es: " << y << endl;
      } else if (opcion == 2) {
        cout << "Saliendo..." << endl;
      } else {
        cout << "Opcion no valida" << endl;
      }
  } while (opcion != 2);

  return 0;
}