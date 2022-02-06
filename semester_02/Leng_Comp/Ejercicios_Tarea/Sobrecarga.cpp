/*Tarea 3
* 
* 
*
*/


#include <iostream>
#include<stdlib.h>
#include <string.h>
#include<time.h>
using namespace std;
string baseNombres[15] = {  
    "Juan",
    "Sofia",
    "Hector",
    "Angel",
    "Alejandro",
    "David",
    "Diego",
    "Maria",
    "Ximena",
    "Daniel",
    "Santiago",
    "Regina",
    "Valentina",
    "Alexis",
    "Axel"
};
string baseApellidosP[15] = {  
    "Perez",
    "Rodriguez",
    "Sanchez",
    "Ramirez",
    "Cruz",
    "Flores",
    "Gomez",
    "Hernandez",
    "Garcia",
    "Martinez",
    "Lopez",
    "Gonzalez",
    "Campos",
    "Chavez",
    "Cruz"
};
string baseApellidosM[15] = {  
    "Espinoza",
    "Gomez",
    "Guerrero",
    "Maldonado",
    "Ortiz",
    "Padilla",
    "Ramos",
    "Rios",
    "Ruiz",
    "Soto",
    "Vazquez",
    "Sanchez",
    "Sandoval",
    "Rojas",
    "Moreno"
};

class Trabajador {
private:
    string nombre;
    int id;
  
public:
  Trabajador(int, string);
  Trabajador() = default;
  void Mostrardatos();
 
};
Trabajador::Trabajador(int _id, string _nombre) {
    id = _id;
    nombre.assign(_nombre);
}

void Trabajador::Mostrardatos() {
  printf("%s\n", nombre.c_str());
  printf("%d\n", id);
}



string generarNombre(string nombre, string baseNombres[15], string baseApellidosP[15], string baseApellidosM[15]);

int generarID(int id);

int main()
{
    srand(time(NULL));
    string nombre;
    int id;
    nombre = generarNombre(nombre, baseNombres, baseApellidosP, baseApellidosM);
    id = generarID(id);
    Trabajador trab(id, nombre);
    trab.Mostrardatos();

    for (int i = 0; i < 10; i++) {
      generarDatos(idParaTrabajador, nombreParaTrabajador, baseNombres, baseApellidosP, baseApellidosM);
      arreglo_trabajadores[i] = Trabajador t1(idParaTrabajador, nombreParaTrabajador[50]);
      arreglo_trabajadores[i].Mostrardatos();
    }

  return 0;
}

int generarID(int id) {
  id = 1000 + rand() % 9999;
  return id;
}

string generarNombre(string nombre, string baseNombres[15], string baseApellidosP[15], string baseApellidosM[15]) {
  int posNombres = 0,
      posApellidoP = 0,
      posApellidoM = 0;

  posNombres = rand()%15;
  posApellidoP = rand()%15;
  posApellidoM = rand()%15;

  nombre.assign(baseNombres[posNombres]);

  return nombre;
}
