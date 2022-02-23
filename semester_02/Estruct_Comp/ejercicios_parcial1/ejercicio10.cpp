/*
  Ejercicio Apuntadores y Estructuras: En el Hospital “La Fraternidad” almacenan la siguiente
  información de sus N pacientes.
  Nombre y apellidos: Cadena de caracteres.
  Edad: Entero.
  Sexo: Carácter.
  Condición: Entero (Se refiere al estado de salud en que ingresa el paciente. Los valores
  que toma van de 1…5, y representan el máximo grado de gravedad.)
  Teléfono.
  Escribir un programa en C que genere lo siguiente:
  • El porcentaje de hombres y mujeres registrados en el hospital.
  • El número de paciente de cada una de las categorías de condición.
  • El nombre y teléfono de todos los pacientes que tuvieron una condición de ingreso
  de máxima gravedad (5).
  Consideraciones: Utilizar apuntadores a estructuras (con sintaxis abreviada -> ó con punto .)
*/

#include <iostream>
using namespace std;

struct paciente {
  string nombre;
  string apellido;
  int edad;
  char sexo;
  int condicion;
  string telefono;
};

int cantidad_pacientes;
string name;

int main() {

  cout << "Ingrese la cantidad de pacientes: ";
  cin >> cantidad_pacientes;
  cout << endl;

  struct paciente *paciente_apuntador;//[cantidad_pacientes];
  struct paciente pacientes[cantidad_pacientes];

  // aqui se asigna el apuntador al vector pacientes
  paciente_apuntador = pacientes;

  for (int i = 0; i < cantidad_pacientes; i++) {
    cout << "Ingrese el nombre del paciente " << i + 1 << ": ";
    // asi se puede guardar valores usando ->
    cin >> (paciente_apuntador + i) -> nombre;
    cout << endl;
    cout << "Ingrese el primer apellido del paciente " << i + 1 << ": ";
    cin >> (paciente_apuntador + i) -> apellido;
    cout << endl;
    cout << "Ingrese la edad del paciente " << i + 1 << ": ";
    cin >> (paciente_apuntador + i) -> edad;
    cout << endl;
    cout << "Ingrese el sexo del paciente " << i + 1 << " (F o M): ";
    cin >> (paciente_apuntador + i) -> sexo;
    cout << endl;
    cout << "Ingrese la condicion del paciente " << i + 1 << ", entre 1 y 5 (1 -> no tan grave, 5 -> lo mas grave): ";
    cin >> (paciente_apuntador + i) -> condicion;
    cout << endl;
    cout << "Ingrese el telefono del paciente " << i + 1 << ": ";
    cin >> (paciente_apuntador + i) -> telefono;
    cout << endl;
  }

  // estos dos muestran la direccion de memoria
  // cout << &pacientes[i].nombre << endl;
  // cout << (paciente_apuntador + i) << endl;

  // este muestra el valor al que apunta el puntero
  for (int i = 0; i < cantidad_pacientes; i++) {
    cout << (paciente_apuntador + i) -> nombre << endl;
    cout << (paciente_apuntador + i) -> apellido << endl;
    cout << (paciente_apuntador + i) -> edad << endl;
    cout << (paciente_apuntador + i) -> sexo << endl;
    cout << (paciente_apuntador + i) -> condicion << endl;
    cout << (paciente_apuntador + i) -> telefono << endl;
  }

  


  return 0;
}
