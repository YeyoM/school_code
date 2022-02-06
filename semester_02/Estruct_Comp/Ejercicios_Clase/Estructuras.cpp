#include <iostream>
#include <string.h>
using namespace std;

// Definimos el struct
struct Alumno {
  char    id[5];
  string  nombre;
  int     edad;
  char    direccion[60];
} alumno2 = {"0123", "Diego Moreno", 19, "Calle #numero"};

int main(){
  int i;
  // Podemos definir una estructura 
  struct Alumno alumno1;

  // Podemos definir un arreglo de estructuras
  struct Alumno arreglo_alumnos[5];
  strcpy(arreglo_alumnos[0].id, "1111");
  arreglo_alumnos[0].nombre = "Juan ";
  arreglo_alumnos[0].edad = 18;
  strcpy(arreglo_alumnos[0].direccion, "Otra calle #numero")
  
  // para acceder a los datos de los structs
  // se usa <nombre_struct>.<propiedad>

  cout << "Datos :" << endl;

  cout << alumno2.nombre << endl;
  cout << alumno2.edad << endl;
  cout << alumno2.id << endl;
  cout << alumno2.direccion << endl;

  // asignacion de datos
  alumno2.edad = 19;          // cualquier elemento
  strcpy(alumno2.id, "3210"); // elementos tipo char

  return 0;
}
