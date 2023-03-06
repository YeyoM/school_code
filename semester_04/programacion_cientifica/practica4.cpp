// Universidad Autonoma de Aguascalientes
// Centro de Ciencias Basicas
// Departamento de Ciencaas de la Computacion
// Programacion Cientifica	
// Diego Emilio Moreno Sánchez
// Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño

// Programa que calcula una de las raices de la funcion f(x) = xsenx - 1
// utilizando el método de bisección

// entradas: intervalo [a, b], error
// salidas: valor de la raiz de la funcion f(x) = xsenx - 1


#include <iostream>
#include <cmath>
#define max_iteraciones 100
using namespace std;

void imprimir_menu() {
  cout << "Menu de opciones" << endl;
  cout << "Programa que calcula la raiz de una funcion utilizando el metodo de biseccion" << endl;
  cout << "Funcion f(x) = xsenx -1" << endl;
  cout << "Entradas: intervalo [a, b]" << endl;
  cout << "Salidas: valor de una de las raices" << endl;
  cout << "1. Calcular el valor de una de las raices" << endl;
  cout << "2. Salir" << endl;
  cout << endl;
  cout << "Ingrese una opcion: ";
}

double f(double x) {
  return x * sin(x) - 1;
}

int main() {

  int opcion;

  double a, 
         b, 
         medio, 
         error = 0.005, 
         f_a, 
         f_medio, 
         medio_anterior = 0;

  do {

    imprimir_menu();
    cin >> opcion;

    if (opcion == 1) {

      cout << "Ingrese el valor de a: ";
      cin >> a;
      cout << "Ingrese el valor de b: ";
      cin >> b;
      cout << "Ingrese el error: ";
      cin >> error;
      cout << endl;

      int iterador = 0;

      while (iterador <= max_iteraciones) {

        medio = (a + b) / 2;

        if (abs(medio - medio_anterior) <= error) {
          cout << "La raiz es: " << medio_anterior << endl;
          cout << "Numero de iteraciones: " << iterador << endl;
          break;
        }

        f_a = f(a); 
        f_medio = f(medio);

        if (f_a * f_medio < 0) {
          b = medio;
          cout << iterador <<". Raiz en el primer intervalo:  " << medio << endl;
        } else if (f_a * f_medio > 0) {
          a = medio;
          cout << iterador <<". Raiz en el segundo intervalo: " << medio <<endl;
        } else {
          cout << "La raiz es: " << medio << endl;
          cout << "Numero de iteraciones: " << iterador << endl;
          break;
        }

        medio_anterior = medio;
        iterador++;
      }

      cout << endl;
      cout << endl;

    } else if (opcion == 2) {
      cout << "Gracias por usar este programa" << endl;
    } else {
      cout << "Opcion no valida" << endl;
    }

  } while (opcion != 2);

  return 0;
}