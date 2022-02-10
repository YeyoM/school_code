#include <iostream>
#include <string.h>

using namespace std;

class Persona {
  private:
    string nombre;
    int edad;
  public:
    Persona(string, int);
    virtual void mostrar();
};

Persona::Persona(string _nombre, int _edad) {
  nombre = _nombre;
  edad = _edad;
}

void Persona::mostrar() {
  cout << "Nombre: " << nombre << endl;
  cout << "Edad: " << edad << endl;
}

class Alumno:public Persona {
  private:
    float nota;
  public:
    Alumno(string, int, float);
    void mostrar();
};

Alumno::Alumno(string _nombre, int _edad, float _nota):Persona(_nombre, _edad) {
  nota = _nota;
}

void Alumno::mostrar() {
  Persona::mostrar();
  cout << "Nota final: " << nota << endl;
}

class Profesor:public Persona {
  private:
    string materia;
  public:
    Profesor(string, int, string); 
    void mostrar();
};

Profesor::Profesor(string _nombre, int _edad, string _materia):Persona(_nombre, _edad) {
  materia = _materia;
}

void Profesor::mostrar() {
  Persona::mostrar();
  cout << "Materia: " << materia << endl;
}

int main () {

  // El polimorfismo se trabaja con punteros
  Persona *personas[3];

  personas[0] = new Alumno("Carlos", 19, 9);
  personas[1] = new Profesor("Raul", 29, "Clase 101");
  personas[2] = new Alumno("Nombre", 18, 9);

  personas[0] -> mostrar();
  personas[1] -> mostrar();
  personas[2] -> mostrar();

  return 0;
}