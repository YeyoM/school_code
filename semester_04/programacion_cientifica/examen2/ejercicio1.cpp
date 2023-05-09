// Universidad Autonoma de Aguascalientes
// Centro de Ciencias Básicas
// Departamento de Ciencias de la Computación
// Diego Emilio Moreno Sánchez
// Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño

// Programa que calcula la raíz de la función por el métodod de 
// bisección para la función f(x) = x^3 - 1.412x^2 + 0.098

// entradas: intervalo [a, b], error
#include <iostream>
#include <cmath>

using namespace std;

void menu() {
  cout << "Programa que calcula la raiz de la funcion f(x) = x^3 - 1.412x^2 + 0.098" << endl;
  cout << "Entradas: intervalo [a, b], error" << endl;
  cout << "Salidas: valor de la raiz de la funcion" << endl;
  cout << "1. Calcular el valor de la raiz" << endl;
  cout << "2. Salir" << endl;
  cout << endl;
}

int main() {

  int opcion;
  int iterador = 0;

  do {

    menu();
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    float a, b, error, medio, f_a, f_medio, medio_anterior = 0;

    if (opcion == 1) {
      cout << "Ingrese el valor de a: ";
      cin >> a;
      cout << "Ingrese el valor de b: ";
      cin >> b;
      cout << "Ingrese el error: ";
      cin >> error;

      do {
        medio = (a + b) / 2;

        // Revisamos si se alcanzo el error
        if (abs(medio - medio_anterior) <= error) {
          cout << "El valor de la raiz es: " << medio << endl;
          cout << "El numero de iteraciones es: " << iterador << endl;
          break;
        } 

        // Calculamos los valores de f(a) y f(medio)
        f_a = pow(a, 3) - 1.412 * pow(a, 2) + 0.098;
        f_medio = pow(medio, 3) - 1.412 * pow(medio, 2) + 0.098;

        // Revisamos en que intervalo se encuentra la raiz
        if (f_a * f_medio < 0) {
          b = medio;
          // cout << "La raiz se encuentra en el primer intervalo" << endl;
        } else if (f_a * f_medio > 0) {
          a = medio;
          // cout << "La raiz se encuentra en el segundo intervalo" << endl;
        } else {
          cout << "El valor de la raiz es: " << medio << endl;
          cout << "El numero de iteraciones es: " << iterador << endl;
          break;
        }

        // Actualizamos el valor de medio_anterior y medio
        medio_anterior = medio;
        medio = (a + b) / 2;
        iterador++;

        if (iterador == 100) break; // Por seguridad, para que no se haga un ciclo infinito

      } while (true); // Ya que no se conoce el numero de iteraciones, y dentro de las condicionales tenemos un break

      cout << endl;

    } else if (opcion == 2) {
      cout << "Gracias por utilizar el programa" << endl;
    } else {
      cout << "Opcion invalida, intentelo nuevamente" << endl;
    }

  } while (opcion != 2);
}