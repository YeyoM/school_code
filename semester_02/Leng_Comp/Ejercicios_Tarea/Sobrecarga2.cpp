//07/02/2022
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
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

class Empleado{
	private:
		string nombre;
		int id;
	public:
		Empleado(string, int);//constructor1
		Empleado(int);//constructor2
		~Empleado();//destructores
	  void trabajar(); 
	  void descansar();
};

Empleado::Empleado(string _nombre, int _id){
	nombre = _nombre;
	id = _id;
}
Empleado::Empleado(int _id){
	nombre = {"Anonimo"};
	id = _id;
}
Empleado::~Empleado(){
}

void Empleado::descansar(){
	cout<<"Soy "<<nombre<<" y mi id es "<<id<<" y estoy en mi descanso temporal\n";
}
void Empleado::trabajar(){
	cout<<"Soy "<<nombre<<" y mi id es "<<id<<" y estoy trabajando arduamente\n";
}

int main() {

	srand(time(NULL));
	
	string nombreParaTrabajador;

	int idParaTrabajador,
      posNombres,
      posApellidoP,
      posApellidoM;

	for(int m = 0; m < 9; m++) {
    posNombres    = rand() % 15;
    posApellidoP  = rand() % 15;
    posApellidoM  = rand() % 15;

    nombreParaTrabajador = 
      ( baseNombres[posNombres] +
        " " + 
        baseApellidosP[posApellidoP] +
        " " + 
        baseApellidosM[posApellidoM]
      );
    
    idParaTrabajador = 1 + rand()%9999;
	
	
	
	Empleado p1(nombreParaTrabajador, idParaTrabajador);
	Empleado p2(idParaTrabajador);
	p1.trabajar();
	cout<<"\n";
	p2.descansar();
	cout<<"\n";
	
}
	
	system("pause");
  return 0;
}















