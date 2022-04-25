// Autores: Cesar Donnet Hernandez Gastelum
//          Diego Emilio Moreno Sanchez
//          Dante Alejandro Alegria Romero
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

#include <iostream>
using namespace std;

float capital(int monto_inicial, int total_anios, float tasa_interes) {
  if (total_anios == 0) {
    return monto_inicial;
  } else {
    float monto_final = monto_inicial + (monto_inicial * tasa_interes);
    return capital(monto_final, total_anios - 1, tasa_interes);
  }
}

int main() {
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
  return 0;
}