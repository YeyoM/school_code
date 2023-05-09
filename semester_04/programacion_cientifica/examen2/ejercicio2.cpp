// Universidad Autonoma de Aguascalientes
// Centro de Ciencias Básicas
// Departamento de Ciencias de la Computación
// Diego Emilio Moreno Sánchez
// Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño

/*
  Programa que calcula la solución para el siguiente sistema de ecuaciones:
  2x_1 + x_2 + 3x_3 = 1
  2x_1 + 6x_2 + 8x_3 = 3
  6x_1 + 8x_2 + 18x_3 = 5
*/

// entradas: matriz de coeficientes, vector de terminos independientes
// salidas: vector de soluciones (mismo vector de terminos independientes)

#include <iostream>
#include <cmath>

using namespace std;

void menu() {
  cout << "Programa que calcula la solucion de un sistema de ecuaciones (3x3) por el metodo de Gauss Jordan" << endl;
  cout << "Entradas: matriz de coeficientes, vector de terminos independientes" << endl;
  cout << "Salidas: vector de soluciones" << endl;
  cout << "1. Calcular la solucion del sistema" << endl;
  cout << "2. Salir" << endl;
}

int main() {

  int opcion, opcion2;

  do {

    menu();
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    if (opcion == 1) {

      float matriz_coeficientes[3][3] = {{2, 1, 3}, {2, 6, 8}, {6, 8, 18}}; // Aqui mismo guardaremos la matriz de coeficientes
      float vector_terminos_independientes[3] = {1, 3, 5}; // Aqui mismo guardaremos el vector de soluciones

      cout << endl;
      cout << "Si se desea resolver el siguiente sistema de ecuaciones:" << endl;
      cout << "2x_1 + x_2 + 3x_3 = 1" << endl;
      cout << "2x_1 + 6x_2 + 8x_3 = 3" << endl;
      cout << "6x_1 + 8x_2 + 18x_3 = 5" << endl;

      cout << endl;
      cout << "Ingrese 1, en caso contrario ingrese 0: ";
      cin >> opcion2;

      if (opcion2 == 1) {
        cout << "Se resolvera el sistema de ecuaciones anterior" << endl;
      } else {
        cout << "Se resolvera el sistema de ecuaciones que usted ingrese" << endl;
        // Pedimos los valores de la matriz de coeficientes
        cout << "Ingrese los valores de la matriz de COEFICIENTES" << endl;
        for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
            cout << "Posicion " << i + 1 << ", " << j + 1 << ": " ;
            cin >> matriz_coeficientes[i][j];
            cout << endl;
          }
        }

        // Pedimos los valores del vector de terminos independientes
        cout << "Ingrese los valores del vector de TERMINOS INDEPENDIENTES" << endl;
        for (int i = 0; i < 3; i++) {
          cout << "Fila " << i + 1 << ": ";
          cin >> vector_terminos_independientes[i];
          cout << endl;
        }
      }

      for (int i = 0; i < 3; i++) {

        // Encontramos el pivote
        float pivote = matriz_coeficientes[i][i];

        // Dividimos la fila entre el pivote
        for (int j = 0; j < 3; j++) {
          matriz_coeficientes[i][j] /= pivote;
        }
        // Tambien el termino independiente
        vector_terminos_independientes[i] /= pivote;

        // Hacemos ceros en la columna del pivote
        for (int j = 0; j < 3; j++) {
          // Comprobamos que no sea la fila del pivote
          if (i != j) {
            // Obtenemos el factor de eliminacion de cada fila 
            // (elemento en la misma columna que el pivote)
            float factor = matriz_coeficientes[j][i];
            // A cada elemento de la fila le restamos el factor multiplicado por el elemento de la fila del pivote
            for (int k = 0; k < 3; k++) {
              matriz_coeficientes[j][k] -= factor * matriz_coeficientes[i][k];
            }
            // Tambien en el vector de terminos independientes
            vector_terminos_independientes[j] -= factor * vector_terminos_independientes[i];
          }
        }
      }

      // Mostramos la solucion
      cout << "La solucion del sistema es: " << endl;
      for (int i = 0; i < 3; i++) {
        cout << "x_" << i + 1 << " = " << vector_terminos_independientes[i] << endl;
      }
      cout << endl;

    } else if (opcion == 2) {
      cout << "Gracias por usar el programa" << endl;
    } else {
      cout << "Opcion invalida" << endl;
    }

  } while (opcion != 2);

  return 0;
}