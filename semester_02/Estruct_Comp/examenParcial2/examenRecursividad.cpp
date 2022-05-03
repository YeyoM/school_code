// Alumno -> Diego Emilio Moreno Sanchez
// ID -> 264776
// Fecha ->02/05/2022
// Ejercicio 2 Examen Parcial 2

/*
  Explicacion del Ejercicio (recursividad)

  - Implemente un algoritmo, usando una función recursiva, que resuelva 
    la siguiente sumatoria:

    K (n, p) = p*1 + p*2 + p*3 + p*4 + … + p*n

  - El programa debe pedir al usuario que ingrese un número n, y un número p,
  - Luego debe calcular el valor de K(n, p) usando una función recursiva, 
  - Debe imprimir el resultado de K(n, p)

  Un resultado de este programa sería: 

  Ingresar n: 3 
  Ingresar p: 2 
  La salida sería:

  K(3,2)=2*1+2*2+2*3
  K(3,2)=2+4+6
  K(3,2)=12
*/

// Librerias ================================================================
#include <iostream>
using namespace std;

// Declaracion de funciones ==================================================
int K(int n, int p) {
  if (n == 1) {
    return p;
  } else {
    return (p * n) + K(n - 1, p);
  }
}

// Variables Globales ========================================================
int resultado;
int p;
int n;

// Main ======================================================================
int main() {
  cout << "Programa que calcula la sumatoria de una serie" << endl;
  cout << "Ingrese un numero n: ";
  cin >> n;
  cout << "Ingrese un numero p: ";
  cin >> p;
  resultado = K(n, p);
  cout << "El resultado es: " << resultado << endl;
  return 0;
}



