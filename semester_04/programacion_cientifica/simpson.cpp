/*
  Universidad Autonoma de Aguascalientes
  Centro de Ciencias Basicas
  Departamento de Ciencaas de la Computacion
  Programacion Cientifica	
  Diego Emilio Moreno Sánchez
  Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño

  Programa que calcula la integral de una funcion usando la regla de Simpson 1/3
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
  return sin(x);
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

      float error = tolerancia + 1;

      float h = (b - a) / n;
      float m = (a + b) / 2;

      float i_0 = (h / 3) * (f(a) + (4 * f(m)) + f(b));
      float i_1 = 0;

      int contador = 0;

      while (error > tolerancia || contador < max_iteraciones) {
        h = (b - a) / n;
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

        i_1 = (h / 3) * (f(a) + 4 * sum_i + 2 * sum_p + f(b));
        error = abs(i_1 - i_0);
        i_0 = i_1;
        n *= 2;

        if (contador == max_iteraciones) {
          cout << "Se alcanzo el maximo de iteraciones" << endl;
          break;
        }

        if (error < tolerancia) {
          cout << "El valor de la integral es: " << i_1 << endl;
          break;
        }

        contador++;
      }


    } else if (opcion == 2) {
      cout << "Saliendo..." << endl;
    } else {
      cout << "Opcion invalida" << endl;
    }

  } while (opcion != 2);


  return 0;
}