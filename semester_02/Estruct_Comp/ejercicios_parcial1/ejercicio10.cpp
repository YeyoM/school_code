/*
  Ejercicio Apuntadores y Estructuras: En el Hospital “La Fraternidad” 
  almacenan la siguiente información de sus N pacientes:
  - Nombre y apellidos: Cadena de caracteres.
  - Edad: Entero.
  - Sexo: Carácter.
  - Condición: Entero (Se refiere al estado de salud en que ingresa el 
    paciente. Los valores que toma van de 1…5, y representan el máximo 
    grado de gravedad.)
  - Teléfono.
  Escribir un programa en C que genere lo siguiente:
  • El porcentaje de hombres y mujeres registrados en el hospital.
  • El número de paciente de cada una de las categorías de condición.
  • El nombre y teléfono de todos los pacientes que tuvieron una 
    condición de ingreso de máxima gravedad (5).
  Consideraciones: Utilizar apuntadores a estructuras (con sintaxis 
  abreviada -> ó con punto .)
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

int cantidad_pacientes;   // para definir la dimension del arreglo

float porcentaje_m,
      porcentaje_f,
      cuenta_m,
      cuenta_f;

string name;

int main() {

  cout << "Ingrese la cantidad de pacientes: ";
  cin >> cantidad_pacientes;
  cout << endl;

  struct paciente *paciente_apuntador;
  struct paciente pacientes[cantidad_pacientes];

  int cuenta_condiciones[5];

  for (int i = 0; i < 5; i++) {
    cuenta_condiciones[i] = 0;
  }

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
    if ((paciente_apuntador + i) -> sexo == 'M' || (paciente_apuntador + i) -> sexo == 'm') {
      cuenta_m++;
    } else if ((paciente_apuntador + i) -> sexo == 'F' || (paciente_apuntador + i) -> sexo == 'f') {
      cuenta_f++;
    }
    cout << "Ingrese la condicion del paciente " << i + 1 << ", entre 1 y 5 (1 -> no tan grave, 5 -> lo mas grave): ";
    cin >> (paciente_apuntador + i) -> condicion;
    cout << endl;
    if ((paciente_apuntador + i) -> condicion == 1) {
      cuenta_condiciones[0] = cuenta_condiciones[0] + 1;
    } else if ((paciente_apuntador + i) -> condicion == 2) {
      cuenta_condiciones[1] = cuenta_condiciones[1] + 1;
    } else if ((paciente_apuntador + i) -> condicion == 3) {
      cuenta_condiciones[2] = cuenta_condiciones[2] + 1;
    } else if ((paciente_apuntador + i) -> condicion == 4) {
      cuenta_condiciones[3] = cuenta_condiciones[3] + 1;
    } else if ((paciente_apuntador + i) -> condicion == 5) {
      cuenta_condiciones[4] = cuenta_condiciones[4] + 1;
    }
    cout << "Ingrese el telefono del paciente " << i + 1 << ": ";
    cin >> (paciente_apuntador + i) -> telefono;
    cout << endl;
  }

  system("cls");

  if (cuenta_m != 0) {
    porcentaje_m = (cuenta_m / cantidad_pacientes) * 100;
  } else {
    porcentaje_m = 0;
  }

  if (cuenta_f != 0) {
    porcentaje_f = (cuenta_f / cantidad_pacientes) * 100;
  } else {
    porcentaje_f = 0;
  }

  cout << endl;
  cout << "-----------------------------------------------------------" << endl;
  cout << "Porcentaje de Pacientes con Sexo Masculino: " << porcentaje_m << "%" << endl;
  cout << "Porcentaje de Pacientes con Sexo Femenino:  " << porcentaje_f << "%" << endl;
  cout << "-----------------------------------------------------------" << endl;

  cout << endl;
  cout << "-----------------------------------------------------------" << endl;
  cout << "Pacientes con gravedad 1: " << cuenta_condiciones[0] << endl;
  cout << "Pacientes con gravedad 2: " << cuenta_condiciones[1] << endl;
  cout << "Pacientes con gravedad 3: " << cuenta_condiciones[2] << endl;
  cout << "Pacientes con gravedad 4: " << cuenta_condiciones[3] << endl;
  cout << "Pacientes con gravedad 5: " << cuenta_condiciones[4] << endl;
  cout << "-----------------------------------------------------------" << endl;

  cout << endl;
  cout << "-----------------------------------------------------------" << endl;
  cout << "Pacientes con gravedad nivel 5: " << endl;
  for (int i = 0; i < cantidad_pacientes; i++) {
    if ((paciente_apuntador + i) -> condicion == 5) {
      cout << "Nombre:   " << (paciente_apuntador + i) -> nombre   << endl;
      cout << "Telefono: " << (paciente_apuntador + i) -> telefono << endl;
    }
  }
  cout << "-----------------------------------------------------------" << endl;

  // este muestra el valor al que apunta el puntero
  cout << endl;
  cout << "-----------------------------------------------------------" << endl;
  cout << "Pacientes: " << endl;
  cout << endl;
  for (int i = 0; i < cantidad_pacientes; i++) {
    cout << "-----------------------------------------------------------" << endl;
    cout << "Nombre:    " << (paciente_apuntador + i) -> nombre    << endl;
    cout << "Apellido:  " << (paciente_apuntador + i) -> apellido  << endl;
    cout << "Edad:      " << (paciente_apuntador + i) -> edad      << endl;
    cout << "Sexo:      " << (paciente_apuntador + i) -> sexo      << endl;
    cout << "Condicion: " << (paciente_apuntador + i) -> condicion << endl;
    cout << "Telefono:  " << (paciente_apuntador + i) -> telefono  << endl;
    cout << "-----------------------------------------------------------" << endl;
  }
  cout << endl;
  cout << "-----------------------------------------------------------" << endl;

  return 0;
}
