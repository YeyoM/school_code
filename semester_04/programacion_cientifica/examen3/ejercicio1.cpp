/*
 * Universidad Autónoma de Aguascalientes
 * Centro de Ciencias Básicas
 * Departamento de Ciencias de la Computación
 * Programación Científica Examen Paarcial 3 Ejercicio 1
 * Diego Emilio Moreno Sánchez
 * Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño
 * 
 * Problema: Encontrar el polinomio de interpolación único para los valores:
 * (8, 0.5), (18, 0.4), (28, 0.6) e interpolar el valor para x = 12
*/

#include <iostream>
#include <cmath>

using namespace std;

void menu() {
  cout << "Programa para encontrar el polinomio de interpolacion unico para los valores: " << endl;
  cout << "(8, 0.5), (18, 0.4), (28, 0.6) e interpolar el valor para x" << endl;
  cout << "1. Encontrar el polinomio de interpolacion" << endl;
  cout << "2. Salir" << endl;
  cout << "Opcion: ";
}

float* gaussJordan(float dependientes[3][3], float independientes[3]) {
  float pivote, factor;
  int i, j, k;

  for (i = 0; i < 3; i++) {
    pivote = dependientes[i][i];
    for (j = 0; j < 3; j++) {
      dependientes[i][j] = dependientes[i][j] / pivote;
    }

    independientes[i] = independientes[i] / pivote;

    for (k = 0; k < 3; k++) {
      if (k != i) {
        factor = dependientes[k][i];
        for (j = 0; j < 3; j++) {
          dependientes[k][j] = dependientes[k][j] - factor * dependientes[i][j];
        }
        independientes[k] = independientes[k] - factor * independientes[i];
      }
    }
  }
  return independientes;
}

int main() {

  int opcion;

  do {

    menu();
    cin >> opcion;

    if (opcion == 1) {

      float valor, resultado = 0;

      float x[3] = {8, 18, 28};
      float y[3] = {0.5, 0.4, 0.6};

      float dependientes[3][3] = {
        {1, x[0], x[0] * x[0]},
        {1, x[1], x[1] * x[1]},
        {1, x[2], x[2] * x[2]}
      };

      float independientes[3] = {
        y[0],
        y[1],
        y[2]
      };

      cout << "Ingrese el valor a interpolar: ";
      cin >> valor;

      float* polinomio_Interpolacion = gaussJordan(dependientes, independientes);

      cout << "El polinomio de interpolacion es: " << endl;
      cout << "P(x) = " <<polinomio_Interpolacion[0] << " + " << polinomio_Interpolacion[1] << "x + " << polinomio_Interpolacion[2] << "x^2" << endl; 

      for (int i = 0; i < 3; i++) {
        resultado += polinomio_Interpolacion[i] * pow(valor, i);
      }

      cout << "El valor interpolado es: " << resultado << endl;
      cout << endl;
      cout << endl;

    } else if (opcion == 2) {
      cout << "Saliendo..." << endl;
    } else {
      cout << "Opcion invalida" << endl;
    }

  } while (opcion != 2);

  return 0;
}