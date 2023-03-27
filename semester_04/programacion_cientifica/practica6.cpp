// Universidad Autonoma de Aguascalientes
// Centro de Ciencias Basicas
// Departamento de Ciencaas de la Computacion
// Programacion Cientifica	
// Diego Emilio Moreno Sánchez
// Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño

// Programa que calcula una de las raices de
// la función f(x) = cosx - x

// Entradas: x_i (valor inicial de la raiz aproxmimada),
//           error (toleracia al error)

// Salidas: valor de la raiz de f(x)

#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159265358979323846
#define max_iteraciones 10

double grados_radianes(double grados) {
  return grados * PI / 180;
}

double radianes_grados(double radianes) {
  return radianes * 180 / PI;
}

void imprimir_menu() {
  cout << "Menu de opciones" << endl;
  cout << "1. Calcular la raiz de f(x) = cosx - x" << endl;
  cout << "2. Salir" << endl;
}

double f(double x) {
  return cos(x) - x;
}

double f_(double x) {
  return -sin(x) - 1;
} 

int main() {

  int opcion, iterador = 0;
  double x_i, x_m, error;

  do {
    
    imprimir_menu();
    cout << "Introduzca una opcion: ";
    cin >> opcion;

    if (opcion == 1) { 

      cout << "Digite el valor inicial de la raiz aproximada (en grados): ";
      cin >> x_i;
      cout << "Digite el valor de la tolerancia al error: ";
      cin >> error;

      x_i = grados_radianes(x_i);

      while(iterador <= max_iteraciones) {
        x_m = x_i - (f(x_i) / f_(x_i));
        cout << "Iteracion: " << iterador << endl;
        cout << "x_i: " << x_i << endl;
        cout << "x_m: " << x_m << endl;
        if (abs(x_m - x_i) <= error || f(x_m) == 0) {
          break;
        } else {
          iterador++;
          x_i = x_m;
        }
      }

      cout << "La raiz es: " << radianes_grados(x_m) << " grados, obtenida en " << iterador << " iteraciones" << endl;
    } 
    
    if (opcion == 2) {
      cout << "Gracias por usar el programa" << endl;
      break;
    } 
    
    if (opcion != 1 && opcion != 2) {
      cout << "Opcion no valida" << endl;
    }

  } while (opcion != 2);

  return 0;
}