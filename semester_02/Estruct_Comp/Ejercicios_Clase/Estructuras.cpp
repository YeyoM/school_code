#include <iostream>
#include <string.h>
using namespace std;

// Definimos el struct
struct Alumno {
  char    id[5];
  string  nombre;
  int     edad;
  char    direccion[60];
};

int main(){
  int i;
  // Podemos definir una estructura 
  struct Alumno alumno1;
  struct Alumno arreglo_alumnos[5];
  
  // para acceder a los datos de los structs
  // se usa <nombre_struct>.<propiedad>

  return 0;
}
