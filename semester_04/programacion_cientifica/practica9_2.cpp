/*
  Universidad Autonoma de Aguascalientes
  Centro de Ciencias Basicas
  Departamento de Ciencaas de la Computacion
  Programacion Cientifica	
  Diego Emilio Moreno Sánchez
  Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño

  Encontrar el polinomio de interpolación único para los valores: 
  (10, 0.1763), (20, 0.3640), (30, 0.5774) 
  e interpolar el valor para x = 21
*/

#include <iostream>
#include <cmath>

using namespace std;

void menu() {
  cout << "1. Encontrar el polinomio de interpolación" << endl;
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

float evaluarPolinomio(float* polinomio, float x) {
  float resultado = 0;

  for (int i = 0; i < 3; i++) {
    resultado += polinomio[i] * pow(x, i);
  }

  return resultado;
}

int main() {

  int opcion = 0;

  float x[3] = {10, 20, 30};
  float y[3] = {0.1763, 0.3640, 0.5774};

  float dependientes[3][3] = {
    {1, x[0], x[0] * x[0]},
    {1, x[1], x[1] * x[1]},
    {1, x[2], x[2] * x[2]}
  };

  float independientes[3] = {y[0], y[1], y[2]};

  do {

    menu();
    cin >> opcion;

      if (opcion == 1) {

        float* resultado = gaussJordan(dependientes, independientes);

        cout << "El polinomio de interpolacion es: " << endl;
        cout << "P(x) = ";
        cout << resultado[0] << " + ";
        cout << resultado[1] << "x + ";
        cout << resultado[2] << "x^2" << endl;

        cout << "El valor de P(21) es: " << evaluarPolinomio(resultado, 21) << endl;

      } else if (opcion == 2) {
        cout << "Saliendo..." << endl;
      } else {
        cout << "Opcion no valida" << endl;
      }
  } while (opcion != 2);

  return 0;
}