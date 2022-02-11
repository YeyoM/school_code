#include <iostream>
#include <string>

using namespace std;

class Animal {
  private:
    int edad;
  public:
    Animal(int);
    virtual void comer();
};

Animal::Animal(int _edad) {
  edad = _edad;
}

void Animal::comer() {
  cout << "Comiendo " << endl;
}

class Persona:public Animal {
  private:
    string nombre;
  public:
    Persona(int, string);
    void comer();
};

Persona::Persona(int _edad, string _nombre):Animal(_edad) {
  nombre = _nombre;
}

void Persona::comer() {
  Persona::comer();
  cout << " una hamburguesa" << endl;
}

class Perro:public Animal {
  private:
    string nombre;
    string raza;
  public:
    Perro(int, string, string); 
    void comer();
};

Perro::Perro(int _edad, string _nombre, string _raza):Animal(_edad) {
  nombre = _nombre;
  raza = _raza;
}

void Perro::comer() {
  Animal::comer();
  cout << " croquetas" << endl;
}

int main () {

  string mensaje =  "hola";

  cout << mensaje << endl;

  // El polimorfismo se trabaja con punteros
  Animal *seres[3];
  cout << mensaje << endl;


  seres[0] = new Persona(19, "Carlos");
  seres[1] = new Perro(2, "Firulais", "Chihuahua");
  seres[2] = new Persona(18, "Nombre");

  cout << mensaje << endl;


  seres[0] -> comer();
  seres[1] -> comer();
  seres[2] -> comer();

  cout << mensaje << endl;


  

  return 0;
}