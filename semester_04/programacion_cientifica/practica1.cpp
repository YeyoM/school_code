// Universidad Autonoma de Aguascalientes
// Centro de Ciencias Basicas
// Departamento de Ciencaas de la Computacion
// Programacion Cientifica	
// Diego Emilio Moreno Sánchez
// Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño

// Programa que calcula el valor de tan(x) 
// para un valor de x, utilizando series de Taylor

// Entradas: x (grados), n (número de términos de la serie de Taylor)
// nota - el número de términos debe ser 2, 4 o 6

// Salidas: valor de tan(x) y valor de tan(x) calculado 
// con la función tan(x) (cmath)

#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159265358979323846

// Coeficientes de la serie de Taylor
// Referencia: http://www.maeckes.nl/Reeksen/tangens%20(basis)%20ES.html
double coeficientes[6] = {1, 2, 16, 272, 7936, 339968};

int factorial(int n) {
  int fact = 1;
  for (int i = 1; i <= n; i++) {
    fact *= i;
  }
  return fact;
}

double potencia(double base, double exp) {
  double pot = 1;
  for (int i = 1; i <= exp; i++) {
    pot *= base;
  }
  return pot;
}

double grados_radianes(double grados) {
  return grados * PI / 180;
}

void imprimir_menu() {
  cout << "Menu de opciones" << endl;
  cout << "1. Calcular el valor de tan(x) para un valor de x dado usando n terminos de la serie de Taylor." << endl;
  cout << "2. Salir" << endl;
}

int main() {

  double val_x,
         radianes,
         termino,
         val_tan;

  int num_term,
      opcion;

  do {
    
    imprimir_menu();
    cout << "Introduzca una opcion: ";
    cin >> opcion;

    if (opcion == 1) {
      cout << "Introduzca el valor de x (grados): ";
      cin >> val_x;

      cout << "Introduzca el numero de terminos de la serie de Taylor (2, 4 o 6): ";
      cin >> num_term;

      // Convertir a radianes
      radianes = grados_radianes(val_x);
      cout << "El valor de x en radianes es: " << radianes << endl;

      // Calcular valor de tan(x) con la serie de Taylor
      val_tan = 0;

      int contador = 1;

      for (int i = 0; i < num_term; i++) {
        termino = potencia(radianes, contador) * coeficientes[i] / factorial(contador);
        // cout << coeficientes[i] << "*" << radianes << "^" << contador << "/" << factorial(contador) << endl;
        // cout << "Termino " << i + 1 << ": " << termino << endl;
        val_tan += termino;
        contador += 2;
      }

      // Mostrar resultados
      cout << "El valor de tan(" << val_x << ") es: " << val_tan << endl;
      cout << "El valor de tan(" << val_x << ") calculado con la funcion tan(x) es: " << tan(radianes) << endl;
      cout << "El error cometido es: " << abs(val_tan - tan(radianes)) << endl;

      cout << endl;
      cout << "Ingrese 1 para volver al menu o 2 para salir: ";
      cin >> opcion; 

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