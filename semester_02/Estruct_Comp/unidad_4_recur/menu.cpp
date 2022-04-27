// Autores: Cesar Donnet Hernandez Gastelum
//          Diego Emilio Moreno Sanchez
//          Dante Alejandro Alegria Romero
#include <iostream>
#include <stdbool.h>
#include <math.h>
using namespace std;

// Función recursiva que retorna cuantos dígitos forman un número. 
// Ejemplo: n=7896, la función regresa 4.
int num_digits(int n) {
  if (n < 10) {
    return 1;
  } else {
    return 1 + num_digits(n / 10);
  }
}

// Función recursiva que recibe un número entero y retorna la sumatoria 
// de los dígitos que lo forman. Ejemplo: n=34219, la función regresa 19
int sum_digits(int n) {
  if (n < 10) {
    return n;
  } else {
    return n % 10 + sum_digits(n / 10);
  }
}

// Función recursiva que retorna el resultado de la siguiente serie. 
// 1^1 + 2^2 + 3^3 + 4^4 + 5^5 + ... + n^n Ejemplo: n=3, la función retorna 32
int sum_series(int n) {
  if (n == 1) {
    return 1;
  } else {
    return pow(n, n) + sum_series(n - 1);
  }
}

// Función recursiva que recibe un numerador y un denominador y 
// retorna un entero con el resultado de la división, la cual se debe 
// hacer por restas sucesivas. a. 
// Ejemplo: n = 8, entonces 
// 8 - 2 = 6
// 6 - 2 = 4
// 4 - 2 = 2
// 2 - 2 = 0
// Como la resta se hizo 4 veces, entonces la función retorna un 4. 
// Esta función solo retorna la parte entera, no retorna decimales.
int division(int num, int den) {
  if (num < den) {
    return 0;
  } else {
    return 1 + division(num - den, den);
  }
}

// Función recursiva que retorna el máximo común divisor de dos números.
int mcd(int a, int b) {
  if (a == b) {
    return a;
  } else if (a > b) {
    return mcd(a - b, b);
  } else {
    return mcd(a, b - a);
  }
}

// Función recursiva que recibe el monto inicial de una inversión, 
// un total de años y una tasa de interés anual, la función retorna 
// el capital que se tendrá al paso de los años. 
// Ejemplo:  si monto inicial es 5000, total de años 3 y la tasa de 
//           interés es .10 entonces: 
//           Año 0 tiene 5000 
//           Año 1 tiene 5500 
//           Año 2 tiene 6050 
//           Año 3 tiene 6655 
// La función debe retornar 6655.
float capital(int monto_inicial, int total_anios, float tasa_interes) {
  if (total_anios == 0) {
    return monto_inicial;
  } else {
    float monto_final = monto_inicial + (monto_inicial * tasa_interes);
    return capital(monto_final, total_anios - 1, tasa_interes);
  }
}

// Se presenta la solución recursiva a encontrar el numero más 
// grande de un vector, implementar la lógica planteada en este 
// código en lenguaje C
int mayor_num(int *vector, int iterador, int mayor) {
  if (iterador == 0) {
    return mayor;
  }
  else if (vector[iterador] > mayor) {
    return mayor_num(vector, iterador - 1, vector[iterador]);
  } 
  else {
    return mayor_num(vector, iterador - 1, mayor);
  }
}

// Variables globales
bool salir = false;
int mayor = 0;


int main() {
  do {
    cout << endl;
    cout << "1. Numero de digitos" << endl;
    cout << "2. Suma de digitos" << endl;
    cout << "3. Suma de serie" << endl;
    cout << "4. Division" << endl;
    cout << "5. Maximo comun divisor" << endl;
    cout << "6. Capital" << endl;
    cout << "7. Mayor numero" << endl;
    cout << "8. Salir" << endl;
    cout << "Ingresa una opcion: ";
    int opcion;
    cin >> opcion;
    cout << endl;
    switch (opcion) {
      case 1:
        {
          cout << "Ingresa un numero: ";
          int num;
          cin >> num;
          cout << "El numero de digitos es: " << num_digits(num);
        }
        break;
      case 2:
        {
          cout << "Ingresa un numero: ";
          int num2;
          cin >> num2;
          cout << "La suma de los digitos es: " << sum_digits(num2);
        }
        break;
      case 3:
        {
          cout << "Ingresa un numero: ";
          int num3;
          cin >> num3;
          cout << "La suma de la serie es: " << sum_series(num3);
        }
        break;
      case 4:
        {
          cout << "Ingresa un numerador: ";
          int num4;
          cin >> num4;
          cout << "Ingresa un denominador: ";
          int den;
          cin >> den;
          cout << "La division es: " << division(num4, den);
        }
        break;
      case 5:
        {
          cout << "Ingresa dos numeros: ";
          int num5, num6;
          cin >> num5 >> num6;
          cout << "El maximo comun divisor es: " << mcd(num5, num6);
        }
        break;
      case 6:
        {
          float monto_inicial, tasa_interes, capital_final;
          int total_anios;
          cout << "Ingresa el monto inicial: ";
          cin >> monto_inicial;
          cout << "Ingresa el total de anios: ";
          cin >> total_anios;
          cout << "Ingresa la tasa de interes: ";
          cin >> tasa_interes;
          capital_final = capital(monto_inicial, total_anios, tasa_interes);
          cout << "El capital al final del tiempo planeado es: " << capital_final;
        }
        break;
      case 7:
        {
          cout << "Ingresa el numero de elementos del vector: ";
          int num7;
          cin >> num7;
          cout << "Ingresa el vector: ";
          int vector[num7];
          for (int i = 0; i < num7; i++) {
            cin >> vector[i];
          }
          cout << "El mayor numero del vector es: " << mayor_num(vector, num7, vector[0]);
        }
        break;
      case 8:
        salir = true;
        break;
      default:
        cout << "Opcion no valida" << endl;
        break;
    }
  } while (salir != true);
  return 0;
}