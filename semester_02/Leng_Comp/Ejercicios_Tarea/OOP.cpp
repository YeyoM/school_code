// @utores Cesar Donnet, Diego Moreno
// @fecha 16/02/2022

/*

  Ejercicio:

  Por parejas, construya un programa con POO en C++ que 
  obtenga el área y el perímetro de un Rectángulo, un 
  Cuadrado, un Circulo y un Triángulo. (Realice un menú 
  para que el usuario indique cuál figura desea y la 
  ultima opción que sea Salir del menú).

  No olvide que debe incluir todos o la mayoría de los 
  conceptos vistos en clases: clase, atributos, métodos, 
  método constructor, objeto (s), get, set, herencia, 
  polimorfismo.

*/  

#include <iostream>
using namespace std;

///////////////////////////////////////////////////////
// Clase Padre (Figura)
class Figura { 
  public:
    float lado1;
    Figura(float);
    virtual void mostrar();x
};

Figura::Figura(float _lado1) {
  lado1 = _lado1;
}

void Figura::mostrar() {
  cout << "Figura: ";
}

///////////////////////////////////////////////////////
// Clase Hija (Cuadrado)
class Cuadrado:public Figura {
  private:
    string nombre;
    float area;
  public:
    Cuadrado(float, string);
    void calcularArea();
    void mostrar();
};

Cuadrado::Cuadrado(float _lado, string _nombre):Figura(_lado) {
  nombre = _nombre;
}

void Cuadrado::mostrar() {
  Figura::mostrar();
  cout << nombre << endl;
  cout << "Longitud del lado: " << lado1 << "cm"<<endl;
}

void Cuadrado::calcularArea() {
  area = lado1 * lado1;
  cout << "Area: " << area << "cm2 "<< endl;
}
///////////////////////////////////////////////////////
// Clase Hija (Rectangulo)
class Rectangulo:public Figura {
  private:
    string nombre;
    float lado2;
    float area;
  public:
    Rectangulo(float, float, string);
    void calcularArea();
    void mostrar();
};

Rectangulo::Rectangulo(float _lado1, float _lado2, string _nombre):Figura(_lado1) {
  lado2 = _lado2;
  nombre = _nombre;
}

void Rectangulo::mostrar() {
  Figura::mostrar();
  cout << nombre << endl;
  cout << "Longitud de la base: " << lado1 << "cm" << endl;
  cout << "Longitud de la altura: " << lado2 << "cm" << endl;
}

void Rectangulo::calcularArea() {
  area = lado1 * lado2;
  cout << "Area: " << area << "cm2 "<< endl;
}

///////////////////////////////////////////////////////
// Clase Hija (Triangulo)

///////////////////////////////////////////////////////
// Clase Hija (Circulo)

///////////////////////////////////////////////////////


int main () {

  // variable para salir del bucle
  bool salir = false;
  
  // variable para el menu
  int opcion;

  // variables para la inicializacion de objetos
  float longitud_lado1, longitud_lado2;

  do {

    cout << "Bienvenido" << endl;
    cout << "1) Calcular area de un cuadrado" << endl;
    cout << "2) Calcular area de un rectangulo" << endl; 
    cout << "3) Calcular area de un triangulo" << endl; 
    cout << "4) Calcular area de un circulo" << endl; 
    cout << "5) Salir" << endl; 

    cout << "Ingrese una opcion valida: ";
    cin >> opcion; 
    cout << endl;

    if (opcion == 1) {
      // cuadrado
      cout << "Ingrese la longitud de los lados (cm): ";
      cin >> longitud_lado1;
      cout << endl;

      Cuadrado cuadrado(longitud_lado1, "Cuadrado");
      cuadrado.mostrar();
      cuadrado.calcularArea();

    } else if (opcion == 2) {
      // rectangulo
      cout << "Ingrese la longitud de la base: ";
      cin >> longitud_lado1; 
      cout << endl;

      cout << "Ingrese la longitud de la altura: ";
      cin >> longitud_lado2;
      cout << endl;

      Rectangulo rectangulo(longitud_lado1, longitud_lado2, "Rectangulo");
      rectangulo.mostrar();
      rectangulo.calcularArea();

    } else if (opcion == 3) {
      // triangulo

    } else if (opcion == 4) {
      // circulo
      
    } else if (opcion == 5) {
      // salir
      salir = true;
      cout << "Nos vemos!" << endl;
    } else {
      // default
      cout << "Digite una opcion valida" << endl;
    }

    cout << endl;
    longitud_lado1 = 0;
    longitud_lado2 = 0;

  } while( salir == false );

  return 0;
}