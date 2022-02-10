/*
  Diego Emilio Moreno Snachez ID: 264776
  Realizar un programa en c para capturar los datos de n 
  clientes que contenga una estructura como la presentada en
   la siguiente figura, obtener el cliente más antiguo y el de
    más reciente registro en la empresa (hacer el cálculo de 
    acuerdo con el año de registro)
*/
#include <iostream>
#include <string.h>

using namespace std;

struct fecha {
  int dia;
  int mes;
  int anio;
};
struct cliente {
  string nombre;
  string apellidos;
  int edad;
  struct fecha fecha_registro;
} clientes[3];

int main() {

  for (int i = 0; i < 3; i++) {
    cout << "Ingrese el nombre del cliente " << i + 1 << ": ";
    cin >> clientes[i].nombre;
    cout << endl;
    cout << "Ingrese el apellido del cliente " << i + 1 << ": ";
    cin >> clientes[i].apellidos;
    cout << endl;
    cout << "Ingrese la edad del cliente " << i + 1 << ": ";
    cin >> clientes[i].edad;
    cout << endl;
    cout << "Ingrese el dia del nacimiento del cliente " << i + 1 << ": ";
    cin >> clientes[i].fecha_registro.dia;
    cout << endl;
    cout << "Ingrese el mes de nacimiento del cliente " << i + 1 << ": ";
    cin >> clientes[i].fecha_registro.mes;
    cout << endl;
    cout << "Ingrese el anio de nacimiento del cliente " << i + 1 << ": ";
    cin >> clientes[i].fecha_registro.anio;
    cout << endl;
    fflush(stdin);
  }

  int posicionClienteMayor = 0, 
      posicionClienteMenor = 0;

  for (int i = 0; i < 3; i++) {
    
    if (clientes[i].fecha_registro.anio > clientes[posicionClienteMayor].fecha_registro.anio) {
      posicionClienteMenor = i;
    }
    if (clientes[i].fecha_registro.anio == clientes[posicionClienteMayor].fecha_registro.anio) {
      if (clientes[i].fecha_registro.mes > clientes[posicionClienteMayor].fecha_registro.mes) {
        posicionClienteMenor = i;
      }
      if (clientes[i].fecha_registro.mes == clientes[posicionClienteMayor].fecha_registro.mes) {
        if (clientes[i].fecha_registro.dia > clientes[posicionClienteMayor].fecha_registro.dia) {
          posicionClienteMenor = i;
        }
        if (clientes[i].fecha_registro.dia == clientes[posicionClienteMayor].fecha_registro.dia) {

        }
        if (clientes[i].fecha_registro.dia < clientes[posicionClienteMayor].fecha_registro.dia) {
          posicionClienteMayor = i;
        }
      }
      if (clientes[i].fecha_registro.mes < clientes[posicionClienteMayor].fecha_registro.mes) {
        posicionClienteMayor = i;
      }
    }
    if (clientes[i].fecha_registro.anio < clientes[posicionClienteMayor].fecha_registro.anio) {
      posicionClienteMayor = i;
    }
    fflush(stdin);
  }

  cout << "El cliente mas joven es: " << clientes[posicionClienteMenor].nombre << endl;
  cout << "El cliente mas antiguo es: " << clientes[posicionClienteMayor].nombre << endl;

  return 0;
}