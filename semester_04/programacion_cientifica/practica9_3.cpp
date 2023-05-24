/*
  Universidad Autonoma de Aguascalientes
  Centro de Ciencias Basicas
  Departamento de Ciencaas de la Computacion
  Programacion Cientifica	
  Diego Emilio Moreno Sánchez
  Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño

  Obtener el polinomio de interpolación usando la fórmula de 
  interpolación de Lagrange con la siguiente tabla de valores, 
  e interpolar en el punto x = −4.
  xk = {−6, 6, −1} yk= { 8, −16, −2}
*/
#include <iostream>
#include <cmath>

using namespace std;

  void menu() {
    cout << "1. Encontrar el polinomio de interpolación" << endl;
    cout << "2. Salir" << endl;
    cout << "Opcion: ";
  }  

int main() {

  int opcion = 0;

  float x[3] = {-6, 6, -1};
  float y[3] = {8, -16, -2};

  float L, acum;

  do {

    menu();
    cin >> opcion;

    if (opcion == 1) {

      int i = 0, j = 0;

      while (i < 3) {
        L = y[i];
        j = 0;
        while (j < 3) {
          if (i != j) {
            L = L * ((-4 - x[j]) / (x[i] - x[j]));
          }
          j++;
        }
        acum += L;
        i++;
      }

      cout << "El valor de la interpolacion es: " << acum << endl;

    } else if (opcion == 2) {
      cout << "Saliendo..." << endl;
    } else {
      cout << "Opcion invalida" << endl;
    }

  } while (opcion != 2);

  return 0;
}