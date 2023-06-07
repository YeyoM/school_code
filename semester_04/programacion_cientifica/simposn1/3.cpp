/*
  Universidad Autonoma de Aguascalientes
  Centro de Ciencias Basicas
  Departamento de Ciencaas de la Computacion
  Programacion Cientifica	
  Diego Emilio Moreno Sanchez     ID: 264776
  Diego Emanuel Saucedo Ortega    ID: 261230
  Carlos Daniel Torres Macias     ID: 244543
  Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño

  Programa que calcula la integral de una funcion usando la regla de Simpson 1/3
  función: x * e^2x
*/

#include <iostream>
#include <cmath>

using namespace std;

void menu() {
  cout << "1. Calcular la integral de una funcion usando la regla de Simpson 1/3" << endl;
  cout << "2. Salir" << endl;
  cout << "Opcion: ";
}

float f(float x) {
  return x * exp(2 * x);
}

float f_4(float x) {
  return (16 * exp(2 * x) * (x + 2));
}

float f_error(float a, float b, float tolerancia) {
  return ((-1 / 180) * pow((b - a), 4) * f_4(tolerancia));
}

int main() {

  int opcion = 0;

  do {

    menu();
    cin >> opcion;

    if (opcion == 1) {

      float a, b, tolerancia;
      int max_iteraciones, n;

      cout << "Ingrese el valor de a: ";
      cin >> a;
      cout << "Ingrese el valor de b: ";
      cin >> b;

      cout << "Ingrese el valor de n (Numero de particiones): ";
      cin >> n;

      if (n % 2 != 0) {
        cout << "El valor de n debe ser par" << endl;
        continue;
      }

      cout << "Ingrese el valor de tolerancia: ";
      cin >> tolerancia;

      cout << "Ingrese el valor de maximo de iteraciones: ";
      cin >> max_iteraciones;

      float h = (b - a) / n;
      float sum_p = 0;      
      float sum_i = 0;

      for (int i = 1; i <= n - 1; i++) {
        if (i % 2 == 0){
          sum_p += f(a + (i * h));
        }
        else {
          sum_i += f(a + (i * h));
        }
      }

      float i_1 = (h / 3) * (f(a) + 4 * sum_i + 2 * sum_p + f(b));

      cout << "El valor de la integral es: " << i_1 << endl;
      cout << "El error es: " << f_error(a, b, tolerancia) << endl;

    } else if (opcion == 2) {
      cout << "Saliendo..." << endl;
    } else {
      cout << "Opcion invalida" << endl;
    }

  } while (opcion != 2);


  return 0;
}