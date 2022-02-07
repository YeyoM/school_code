/*Tarea 3
* 
* 
*
*/


#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
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
    void setName(string _nombre) {
  		nombre = _nombre;
  	}
  	void setID(int _id){
  		id = _id;
  	}
  	void displayInfo(){
  		cout << "Name : " << nombre << endl;
  		cout << "ID : " << id << endl;
  	}
};

string generarNombre(string nombre, string baseNombres[15], string baseApellidosP[15], string baseApellidosM[15]);

int generarID(int id);

int main()
{
    srand(time(NULL));
    string nombre;
    int id;

    Trabajador arreglo_trabajadores[10];

    for (int i = 0; i < 10; i++) {
      nombre = generarNombre(nombre, baseNombres, baseApellidosP, baseApellidosM);
      id = generarID(id);
      arreglo_trabajadores[i].setName(nombre);
      arreglo_trabajadores[i].setID(id);
    }

    arreglo_trabajadores[1].displayInfo();

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
