/*
Universidad Autonoma de Aguascalientes
Centro de Ciencias Basicas
Departamento de Ciencias de la Computacion
Programacion Cientifica	
Diego Alberto Aranda Gonzalez (ID 262021)
Diego Emilio Moreno Sánchez (ID 264776)
Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño

Practica 2: Minimizar la siguiente función utilizando el Método de Búsqueda Aleatoria
f(x) = -(x2 + 47)sen(√|x2+x1/2+47|) - x1sen(√|x1 - (x2 + 47)|)
*/

#include <iostream>
#include <cmath>
using namespace std;

//Funcion para generar numeros aleatorias
double random(double min, double max){
  return (double)rand() / RAND_MAX * (max - min) + min;
}

double f(double x1, double x2) {
  return -(x2 + 47) * sin(sqrt(abs(x2 + x1 / 2 + 47))) - x1 * sin(sqrt(abs(x1 - (x2 + 47))));
}

void menu() {
  cout << "Programa que calcula el minimo de la funcion f(x) = -(x2 + 47)sen(√|x2+x1/2+47|) - x1sen(√|x1 - (x2 + 47)|) por el metodo de busqueda aleatoria" << endl;
  cout << "1. Calular el minimo" << endl;
  cout << "2. Salir" << endl;
  cout << "Ingrese una opcion: ";
}

void tabla(int i, double x1, double x2, double fx, double min_actual){
  cout << "No.Iteracion  " << " x1 " << " x2 " << " f(x) " << " Min Actual "<< endl;
  cout << "-----------------------------------------" << endl;
  cout << i << "  " << x1 << "  " << x2 << "  " << fx << "  " << min_actual << endl;
  cout << endl;
}

int main() {

  int opcion;

  do {

    menu();
    cin >> opcion;

    if (opcion == 1) {
      // Ejecucion de Busqueda Aleatoria

      // Inicializacion de variables
      double x1 = random(-512, 512);
      double x2 = random(-512, 512);

      double fx = f(x1, x2);

      double min_actual = fx;

      tabla(0, x1, x2, fx, min_actual);

      double xi = 0;
      double yi = 0;

      double fx1 = 0;

      // Ciclo para iteraciones
      for (int i = 0; i < 10000; i++) {
        xi = random(-512, 512);
        yi = random(-512, 512);

        fx1 = f(xi, yi);

        // Generacion de tabla
        tabla(i, xi, yi, fx1, min_actual);

        if (fx1 < fx) {
          x1 = xi;
          x2 = yi;
          fx = fx1;
        }

        if (fx < min_actual) {
          min_actual = fx;
        }
      }

      cout << "El minimo de la funcion es: " << fx << endl;
      cout << "Con x1 = " << x1 << " y x2 = " << x2 << endl;
      cout << endl;
      
    } else if (opcion == 2) {
      cout << "Saliendo del programa..." << endl;
    } else {
      cout << "Opcion no valida" << endl;
    }
    
  } while (opcion != 2);
  
  return 0;
}