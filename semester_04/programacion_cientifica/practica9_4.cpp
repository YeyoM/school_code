/*
  Universidad Autonoma de Aguascalientes
  Centro de Ciencias Basicas
  Departamento de Ciencaas de la Computacion
  Programacion Cientifica	
  Diego Emilio Moreno Sánchez
  Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño

  4.	Calcular el polinomio de interpolación de Newton 
  para los siguientes datos:

  xk = {-2, -1, 2, 3} yk= {4, 1, 4, 9}
*/
#include <iostream>
#include <cmath>

using namespace std;

  void menu() {
    cout << "1. Encontrar el polinomio de interpolación de Newton" << endl;
    cout << "2. Salir" << endl;
    cout << "Opcion: ";
  }  

int main() {

  int opcion = 0;

  float x[4] = {-2, -1, 2, 3};
  float y[4] = {4, 1, 4, 9};

  float valor = 4;
  float acum = 0;

  do {

    menu();
    cin >> opcion;

    if (opcion == 1) {
      for (int i = 0; i < 4 - 1; i++) {
        for (int j = 4 - 1; j > i; j--) {
          y[j] = (y[j] - y[j - 1]) / (x[j] - x[j - i - 1]);
        }
      }

      for (int i = 4 - 1; i >= 0; i--) {
        float mult = 1;
        for (int j = 0; j < i; j++) {
          mult *= (valor - x[j]);
        }
        mult *= y[i];
        acum += mult;
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