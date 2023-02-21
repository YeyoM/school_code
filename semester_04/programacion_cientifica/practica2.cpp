// Universidad Autonoma de Aguascalientes
// Centro de Ciencias Basicas
// Departamento de Ciencaas de la Computacion
// Programacion Cientifica	
// Diego Emilio Moreno Sánchez
// Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño

// Progrma que calcula la raiz de una funcion utilizando el metodo de punto fijo
// funcion f(x) = e^-x - x

// Entradas: x0 (valor inicial), error (tolerancia)
// Salidas: valor de la raiz de la funcion f(x) = e^-x - x

// Explicación del método de punto fijo:

/*
  Para encontrar las raices de la funcion, tenemos...

  f(x) = 0, por lo tanto, e^-x - x = 0

  Para cambiar la ecuacion a la forma x = g(x), tenemos...

  x = g(x) = e^-x

  Por lo tanto, la ecuación de recurrencia es...

  x_(i+1) = e^-x_i
*/

#include <iostream>
#include <cmath>
using namespace std;

#define e 2.7182818284

double potencia(double base, double exp) {
  double pot = 1;
  for (int i = 1; i <= exp; i++) {
    pot *= base;
  }
  return pot;
}

void imprimir_menu() {
  cout << "Menu de opciones" << endl;
  cout << "Programa que calcula la raiz de una funcion utilizando el metodo de punto fijo" << endl;
  cout << "1. Calcular el valor de la raiz de la funcion f(x) = e^-x - x" << endl;
  cout << "2. Salir" << endl;
  cout << "Ingrese una opcion: ";
}

int main() {

  int opcion, contador = 1;

  double x0,
         error;

  do {

    imprimir_menu();
    cin >> opcion;

    if (opcion == 1) {

      cout << "Ingrese el valor inicial x0: ";
      cin >> x0;

      cout << "Ingrese el error (tolerancia): ";
      cin >> error;

      double x1 = exp(-x0);

      while (abs(x1 - x0) > error) {
        x0 = x1;
        x1 = exp(-x0);
        contador++;
      }

      cout << "La raiz de la funcion es: " << x1 << endl;
      cout << "Obtenido en " << contador << " iteraciones" << endl;
      cout << "Con un error de " << abs(x1 - x0) << endl << endl;
      
      contador = 0;

    } else if (opcion == 2) {
      cout << "Gracias por usar este programa" << endl;
    } else {
      cout << "Opcion no valida" << endl;
    }

  } while (opcion != 2);

  return 0;
}