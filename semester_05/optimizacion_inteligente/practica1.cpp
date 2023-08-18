/*
Universidad Autonoma de Aguascalientes
Centro de Ciencias Basicas
Departamento de Ciencias de la Computacion
Programacion Cientifica	
Diego Alberto Aranda Gonzalez (ID 262021)
Diego Emilio Moreno Sánchez (ID 264776)
Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño
*/

/*
Practica 1: Implementar un programa que utilizando el método de Newton resuelva
un problema de optimización unidimensional no restringida. 

Minimizar la siguiente función utilizando el Método de Newton

f(x) = 2x^2 + 16/x
*/

#include <iostream>
#include <math.h>

using namespace std;

float f_x(float x) {
  return 2*pow(x,2) + 16/x;
}

float f_x_prima(float x) {
  return 4*x - 16/pow(x,2);
}

float f_x_segunda(float x) {
  return 4 + 32/pow(x,3);
}

void menu() {
  cout << "Programa que calcula el minimo de una funcion utilizando el metodo de Newton" << endl;
  cout << "f(x) = 2x^2 + 16/x" << endl;
  cout << "1. Ejecutar el programa" << endl;
  cout << "2. Salir" << endl;
  cout << "Ingrese una opcion: ";
}
string space(int tam, int valor){
  int espacio = 0;
  string texto = "";
  espacio = valor - tam;
  for (int i = 0; i < espacio; i++){
    texto += " ";
  }
  return texto;
}

void tabla(int k, float x_k, float f_x, float f_x_prima, float f_x_segunda){
  cout << space(13, to_string(k).length()) << "k|" << space(5, to_string(x_k).length()) << "x_k|" << space(5, to_string(f_x).length()) << "f(x)|" << space(5, to_string(f_x_prima).length()) << "f'(x)|" << space(5, to_string(f_x_segunda).length()) << "f''(x)|" << space(5, to_string(x_k).length()) << "x_k+1" << endl;
  cout << "------------------------------------------------" << endl;
  cout << space(13, to_string(k).length()) << k << "|" << space(5, to_string(x_k).length()) << x_k << "|" << space(5, to_string(f_x).length()) << f_x << "|" << space(5, to_string(f_x_prima).length()) << f_x_prima << "|" << space(5, to_string(f_x_segunda).length()) << f_x_segunda << "|" << space(5, to_string(x_k).length()) << x_k - (f_x_prima/f_x_segunda) << endl;
  cout << endl;
}

int main (){

  int opcion;

  do {

    menu();
    cin >> opcion;

    if (opcion == 1) {
      cout << "Ejecutando el programa..." << endl;

      float x_0;
      cout << "Ingrese el valor de x_0: ";
      cin >> x_0;

      float x_k = x_0;
      float error = 0.0001;

      int k = 1; // numero de iteraciones

      while (abs(f_x_prima(x_k)) > error) {
        float x_k1 = x_k - (f_x_prima(x_k)/f_x_segunda(x_k));
        tabla(k, x_k, f_x(x_k), f_x_prima(x_k), f_x_segunda(x_k));
        x_k = x_k1;
        k++;
      }

      cout << endl;

      cout << "------------------------------------------------" << endl;
      cout << "El valor de x_k es: " << x_k << endl;
      cout << "El minimo de la funcion es: " << f_x(x_k) << endl;
      cout << "------------------------------------------------" << endl;

      cout << endl;

    } else if (opcion == 2) {
      cout << "Saliendo del programa..." << endl;
      break;
    } else {
      cout << "Opcion no valida" << endl;
    }

  } while (opcion != 2);
  
  return 0;
}