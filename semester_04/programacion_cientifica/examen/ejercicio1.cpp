// Universidad Autónoma de Aguascalientes
// Centro de Ciencias Básicas
// Departamento de Computación
// Diego Emilio Moreno Sánchez
// Dr. en C. Luis Fernando Gutiérrez Marfileño
// Programa que calcula el valor de e^5x para un valor de x 
// dado usando n términos de la serie de Taylor.

#include <iostream>
#include <cmath>
using namespace std;

void imprimir_menu() {
  cout << "Este programa calcula el valor de e^5x para un valor de x dado usando n terminos de la serie de Taylor." << endl;
  cout << "1. Calcular e^5x." << endl;
  cout << "2. Salir." << endl;
}

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

int main() {

  int contador = 0,
      val_x,
      num_term;

  double suma    = 0,
        termino = 1,
        error,
        aux;

  int opcion;

  do {
    imprimir_menu();
    cout << "Introduzca una opcion: ";
    cin >> opcion;

    if (opcion == 1) {
      cout << "Introduzca el valor de x (exponente): ";
      cin >> val_x;
 
      cout << "Introduzca el numero de terminos de la serie de Taylor: ";
      cin >> num_term;

      cout << "Introduzca el error de la serie de Taylor: ";
      cin >> error;
      
      double valor_real = exp(5 * val_x);

      while (contador <= num_term) {
        suma += termino;
        aux = val_x * 5;
        termino = pow(aux, contador) / factorial(contador);
        cout << pow(aux, contador) << endl;
        cout << factorial(contador) << endl;
        cout << "Termino: " << termino << endl;
        contador++;
      }

      cout << "El valor de e^5*" << val_x << " es: " << suma << endl;
      cout << "El valor real de e^5*" << val_x << " es: " << valor_real << endl;
      cout << "El error es: " << abs(valor_real - suma) << endl;
 
    } else if (opcion == 2) {
      cout << "Saliendo..." << endl;
    } else {
      cout << "Opción no válida." << endl;
    }
  } while (opcion != 2);

  return 0;
}