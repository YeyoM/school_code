// Universidad Autonoma de Aguascalientes
// Centro de Ciencias Basicas
// Departamento de Ciencaas de la Computacion
// Programacion Cientifica	
// Diego Emilio Moreno Sánchez
// Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño

// Programa que calcula la raiz de una funcion utilizando el metodo grafico
// Funcion f(x) = x^3 + 2x^2 + 3x - 5
// Entradas: intervalo [a, b]

#include <iostream>
#include <cmath>
#define raiz_real 0.8945582428
using namespace std;

void imprimir_menu() {
  cout << "Menu de opciones" << endl;
  cout << "Programa que calcula la raiz de una funcion utilizando el metodo grafico" << endl;
  cout << "Funcion f(x) = x^3 + 2x^2 + 3x - 5" << endl;
  cout << "Entradas: intervalo [a, b]" << endl;
  cout << "Salidas: valor de la raiz de la funcion f(x) = x^3 + 2x^2 + 3x - 5" << endl;
  cout << "1. Calcular el valor de la raiz de la funcion f(x) = x^3 + 2x^2 + 3x - 5" << endl;
  cout << "2. Salir" << endl;
  cout << endl;
  cout << "Ingrese una opcion: ";
}

int main() {

  int opcion;
  float raiz;
  int a, b;

  do {

    imprimir_menu();
    cin >> opcion;

    if (opcion == 1) {

      cout << "Ingrese el valor de a: ";
      cin >> a;
      cout << "Ingrese el valor de b: ";
      cin >> b;

      float valores_x[(b - a + 1) * 10];
      float valores_y[(b - a + 1) * 10];
      int indice = 0;

      for (double i = a; i <= b; i = i + 0.1) {
        valores_x[indice] = pow(i, 3) + 2 * pow(i, 2) + 3 * i - 5 ;
        valores_y[indice] = i;
        cout << "f(" << valores_y[indice] << ") = " << valores_x[indice] << endl;
        indice++;
      }

      for (int i = 0; i < (b - a + 1) * 10; i++) {
        if (valores_x[i] * valores_x[i + 1] < 0) {
          raiz = (valores_y[i] + valores_y[i + 1]) / 2;
          cout << "La raiz de la funcion es: " << raiz << endl;
        }
      }

      cout << "La raiz real de la funcion es: " << raiz_real << endl;
      cout << "El error cometido es: " << abs(raiz - raiz_real) << endl;

    } else if (opcion == 2) {
      cout << "Gracias por usar este programa" << endl;
    } else {
      cout << "Opcion no valida" << endl;
    }

  } while (opcion != 2);

  return 0;
}