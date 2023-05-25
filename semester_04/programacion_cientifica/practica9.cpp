/*
  Universidad Autonoma de Aguascalientes
  Centro de Ciencias Basicas
  Departamento de Ciencaas de la Computacion
  Programacion Cientifica	
  Diego Emilio Moreno Sánchez
  Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño

  Problemas:

  1. Calcular la función de regresión lineal para el siguiente 
  conjunto de datos:

  Cinco niños de 2, 3, 5, 7 y 8 años de edad pesan, 
  respectivamente, 14, 20, 32, 42 y 44 kilos.
  
  Hallar la ecuación de la recta de regresión de la edad sobre el peso.
  ¿Cuál sería el peso aproximado de un niño de seis años?

  2. Encontrar el polinomio de interpolación único para los valores: 
  (10, 0.1763), (20, 0.3640), (30, 0.5774) 
  e interpolar el valor para x = 21

  3. Obtener el polinomio de interpolación usando la fórmula de 
  interpolación de Lagrange con la siguiente tabla de valores, 
  e interpolar en el punto x = −4.
  xk = {−6, 6, −1} yk= { 8, −16, −2}

  4. Calcular el polinomio de interpolación de Newton 
  para los siguientes datos:

  xk = {-2, -1, 2, 3} yk= {4, 1, 4, 9}
*/
#include <iostream>
#include <cmath>

using namespace std;

void menu() {
  cout << "1. Calcular la ecuacion de la recta de regresion y resolver el problema 1" << endl;
  cout << "2. Encontrar el polinomio de interpolacion unico problema 2" << endl;
  cout << "3. Encontrar el polinomio de interpolaion de Lagrange" << endl;
  cout << "4. Encontrar el polinomio de interpolacion de Newton" << endl;
  cout << "5. Salir" << endl;
  cout << "Opcion: ";
}  

float* gaussJordan(float dependientes[3][3], float independientes[3]) {
  float pivote, factor;
  int i, j, k;

  for (i = 0; i < 3; i++) {
    pivote = dependientes[i][i];

    for (j = 0; j < 3; j++) {
      dependientes[i][j] = dependientes[i][j] / pivote;
    }

    independientes[i] = independientes[i] / pivote;

    for (k = 0; k < 3; k++) {
      if (k != i) {
        factor = dependientes[k][i];

        for (j = 0; j < 3; j++) {
          dependientes[k][j] = dependientes[k][j] - factor * dependientes[i][j];
        }

        independientes[k] = independientes[k] - factor * independientes[i];
      }
    }
  }

  return independientes;
}

float evaluarPolinomio(float* polinomio, float x) {
  float resultado = 0;

  for (int i = 0; i < 3; i++) {
    resultado += polinomio[i] * pow(x, i);
  }

  return resultado;
}

int main() {

  int opcion = 0;

  do {

    menu();
    cin >> opcion;

    if (opcion == 1) {
      int n = 5;
      float edades[n] = {2, 3, 5, 7, 8};
      float pesos[n] = {14, 20, 32, 42, 44};

      cout << "Edad\tPeso" << endl;
      for (int i = 0; i < n; i++) {
        cout << edades[i] << "\t" << pesos[i] << endl;
      }

      float sum_x = 0,
        sum_y = 0,
        sum_xy = 0,
        sum_x2 = 0;

      int i = 0;

      while (i <= n) {
        sum_x += edades[i];
        sum_y += pesos[i];
        sum_xy += edades[i] * pesos[i];
        sum_x2 += edades[i] * edades[i];
        i++;
      }

      float a1 = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
      float a0 = (sum_y - a1 * sum_x) / n;
      
      cout << "La ecuacion de la recta de regresion es: " << endl;
      cout << "y = " << a0 << " + " << a1 << "x" << endl;

      float x = 6;

      cout << "Ingrese el valor a estimar: " << endl;
      cin >> x;
      
      float y = a0 + a1 * x;
      
      cout << "El peso aproximado de un nino de " << x << " anios es: " << y << endl;

    } else if (opcion == 2) {
      float x[3] = {10, 20, 30};
      float y[3] = {0.1763, 0.3640, 0.5774};

      cout << "x\tf(x)" << endl;
      for (int i = 0; i < 3; i++) {
        cout << x[i] << "\t" << y[i] << endl;
      }
    
      float dependientes[3][3] = {
        {1, x[0], x[0] * x[0]},
        {1, x[1], x[1] * x[1]},
        {1, x[2], x[2] * x[2]}
      };

      float independientes[3] = {y[0], y[1], y[2]};
      float* resultado = gaussJordan(dependientes, independientes);

      cout << "El polinomio de interpolacion es: " << endl;
      cout << "P(x) = ";
      cout << resultado[0] << " + ";
      cout << resultado[1] << "x + ";
      cout << resultado[2] << "x^2" << endl;

      float valor = 0;
      cout << "Ingrese el valor a estimar: " << endl;
      cin >> valor;

      cout << "El valor de P("<< valor << ") es: " << evaluarPolinomio(resultado, valor) << endl;

    } else if (opcion == 3) {
      float x[3] = {-6, 6, -1};
      float y[3] = {8, -16, -2};

      cout << "x\tf(x)" << endl;
      for (int i = 0; i < 3; i++) {
        cout << x[i] << "\t" << y[i] << endl;
      }

      float L, acum;
      int i = 0, j = 0;

      float valor = 0;
      cout << "Ingrese el valor a estimar: " << endl;
      cin >> valor;

      while (i < 3) {
        L = y[i];
        j = 0;
        while (j < 3) {
          if (i != j) {
            L = L * ((valor - x[j]) / (x[i] - x[j]));
          }
          j++;
        }
        acum += L;
        i++;
      }

      cout << "El valor de la estimacion es: " << acum << endl;

    } else if (opcion == 4) {

      float x[4] = {-2, -1, 2, 3};
      float y[4] = {4, 1, 4, 9};

      // Imprimir la tabla
      cout << "x\tf(x)" << endl;
      for (int i = 0; i < 4; i++) {
        cout << x[i] << "\t" << y[i] << endl;
      }


      float valor = 4;

      cout << "Ingrese el valor a estimar: " << endl;
      cin >> valor;

      float acum = 0;

      for (int i = 0; i < 4 - 1; i++) {
        for (int j = 4 - 1; j > i; j--) {
          y[j] = (y[j] - y[j - 1]) / (x[j] - x[j - i - 1]);
        }
      }

      for (int i = 4 - 1; i >= 0; i--) {
        float mult = 1;
        for (int j = 0; j < i; j++) {
          mult *= (valor - x[j]);
        }
        mult *= y[i];
        acum += mult;
      }

      cout << "El valor de la interpolacion es: " << acum << endl;

    } else if (opcion == 5) {
      cout << "Saliendo..." << endl;
    } else {
      cout << "Opcion invalida" << endl;
    }

  } while (opcion != 5);

  return 0;
}