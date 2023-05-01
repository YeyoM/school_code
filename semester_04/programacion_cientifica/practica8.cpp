// Universidad Autonoma de Aguascalientes
// Centro de Ciencias Basicas
// Departamento de Ciencaas de la Computacion
// Programacion Cientifica	
// Diego Emilio Moreno Sánchez
// Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño

// Programa que calcula la solución de un sistema de ecuaciones
// por medio del método de Gauss-Jordan

// Entradas: n (dimension del sistema), a (matriz de coeficientes),
//           b (vector de terminos independientes)

// Salidas: b (vector solucion) luego de aplicar Gauss-Jordan

#include <iostream>
#include <cmath>

using namespace std;

void menu() {
  cout << "Menu de opciones" << endl;
  cout << "1. Ejecutar el metodo de Gauss-Jordan" << endl;
  cout << "2. Salir" << endl;
}

int main() {

  int opcion, n;

  do {

    menu();
    cout << "Introduzca una opcion: ";
    cin >> opcion;

    if (opcion == 1) {

      cout << "Introduzca la dimension del sistema: ";
      cin >> n;

      double a[n][n], b[n];

      cout << "Introduzca los coeficientes del sistema: " << endl;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { 
          cout << "a[" << i << "][" << j << "]: ";
          cin >> a[i][j];
        }
      }

      cout << "Introduzca los terminos independientes: " << endl;
      for (int i = 0; i < n; i++) {
        cout << "b[" << i << "]: ";
        cin >> b[i];
      }

      // Imprimir el sistema
      cout << "El sistema es: " << endl;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { 
          cout << a[i][j] << " ";
        }
        cout << " = " << b[i] << endl;
      }
      cout << endl;

      // Algoritmo de Gauss-Jordan
      for (int i = 0; i < n; i++) {
        double pivote = a[i][i]; // Obtener el pivote

        // Dividir la fila[i] entre el pivote
        for (int j = 0; j < n; j++) {
          a[i][j] /= pivote;
        }
        b[i] /= pivote;

        // Eliminacion de Gauss
        for (int j = 0; j < n; j++) {
          if (i != j) { // Para no operar sobre la fila del pivote
            // Obtener el factor de eliminacion de Gauss
            // para la fila j (elemento que se encuentra debajo o arriba del pivote)
            double factor = a[j][i];
            // Recorrer la fila[j] y restarle el factor de eliminacion de Gauss por la fila[i] 
            for (int k = 0; k < n; k++) {
              a[j][k] -= factor * a[i][k];
            }
            b[j] -= factor * b[i];
          }
        }
      }

      cout << "La solucion del sistema es: " << endl;
      for (int i = 0; i < n; i++) {
        cout << "x[" << i << "]: " << b[i] << endl;
      }

    } else if (opcion == 2) {
      cout << "Saliendo..." << endl;
    } else {
      cout << "Opcion invalida" << endl;
    }

  } while (opcion != 2);

}