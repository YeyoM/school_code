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
    virtual void mostrar();
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
    float perimetro;
  public:
    Cuadrado(float, string);
    ~Cuadrado();
    void mostrar();
    void calcularArea();
    void calcularPerimetro();
};

Cuadrado::Cuadrado(float _lado, string _nombre):Figura(_lado) {
  nombre = _nombre;
}

Cuadrado::~Cuadrado() {}

void Cuadrado::mostrar() {
  Figura::mostrar();
  cout << nombre << endl;
  cout << "Longitud del lado: " << lado1 << "cm"<<endl;
}

void Cuadrado::calcularArea() {
  area = lado1 * lado1;
  cout << "Area: " << area << "cm2 "<< endl;
}

void Cuadrado::calcularPerimetro() {
  perimetro = lado1 * 4;
  cout << "Perimetro: " << perimetro << "cm "<< endl;
}
///////////////////////////////////////////////////////
// Clase Hija (Rectangulo)
class Rectangulo:public Figura {
  private:
    string nombre;
    float lado2;
    float area;
    float perimetro;
  public:
    Rectangulo(float, float, string);
    ~Rectangulo();
    void mostrar();
    void calcularArea();
    void calcularPerimetro();
};

Rectangulo::Rectangulo(float _lado1, float _lado2, string _nombre):Figura(_lado1) {
  lado2 = _lado2;
  nombre = _nombre;
}

Rectangulo::~Rectangulo() {}

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

void Rectangulo::calcularPerimetro() {
  perimetro = (lado1 * 2) + (lado2 * 2);
  cout << "Perimetro: " << perimetro << "cm "<< endl;
}

///////////////////////////////////////////////////////
// Clase Hija (Triangulo)
class Triangulo:public Figura {
  private:
    string nombre;
    float lado2;
    float lado3;
    float lado4;
    float area;
    float perimetro;
  public:
    Triangulo(float, float, float, float, string);
    ~Triangulo();
    void mostrar();
    void calcularArea();
    void calcularPerimetro();
};

Triangulo::Triangulo(float _lado1, float _lado2, float _lado3, float _lado4, string _nombre):Figura(_lado1) {
  lado2 = _lado2;
  lado3 = _lado3;
  lado4 = _lado4;
  nombre = _nombre;
}

Triangulo::~Triangulo() {}

void Triangulo::mostrar() {
  Figura::mostrar();
  cout << nombre << endl;
  cout << "Longitud de la base: " << lado1 << "cm" << endl;
  cout << "Longitud de la altura: " << lado2 << "cm" << endl;
}

void Triangulo::calcularArea() {
  area = (lado1 * lado2) / 2;
  cout << "Area: " << area << "cm2 "<< endl;
}

void Triangulo::calcularPerimetro() {
  perimetro = lado1 + lado3 + lado4;
  cout << "Perimetro: " << perimetro << "cm "<< endl;
}
///////////////////////////////////////////////////////
// Clase Circulo
class Circulo {
	private:
    string nombre;
		float radio;
    float area;
    float perimetro;
	public:
		Circulo(float, string);
		~Circulo();
    void mostrar();
		void calcularArea();
    void calcularPerimetro();
};

Circulo::Circulo(float _radio, string _nombre) {
	radio = _radio;
  nombre = _nombre;
}

Circulo::~Circulo() {}

void Circulo::mostrar() {
  cout << "Figura: " << nombre << endl;
}

void Circulo::calcularArea() {
	area = ((3.1416 * radio) * radio);
	cout << "Area: " << area << "cm2" << endl;
}

void Circulo::calcularPerimetro() {
	perimetro = ((2 * 3.1416) * radio);
	cout << "Perimetro: " << perimetro << "cm" << endl;
}
///////////////////////////////////////////////////////


int main () {

  // variable para salir del bucle
  bool salir = false;
  
  // variable para el menu
  int opcion;

  // variables para la inicializacion de objetos
  float longitud_lado1,   // bases
        longitud_lado2,   // alturas
        longitud_lado3,   // lados restantes para calculo 
        longitud_lado4;   // de perimetro de triangulo

  do {

    system("cls");
    cout << endl;

    cout << "Bienvenido" << endl;
    cout << "1) Calcular area y perimetro de un cuadrado" << endl;
    cout << "2) Calcular area y perimetro de un rectangulo" << endl; 
    cout << "3) Calcular area y perimetro de un triangulo" << endl; 
    cout << "4) Calcular area y perimetro de un circulo" << endl; 
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
      cuadrado.calcularPerimetro();

      cout << endl;
      system("pause");

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
      rectangulo.calcularPerimetro();

      cout << endl;
      system("pause");

    } else if (opcion == 3) {
      // triangulo
      cout << "Ingrese la longitud de la base: ";
      cin >> longitud_lado1;
      cout << endl;

      cout << "Ingrese la longitud de la altura: ";
      cin >> longitud_lado2;
      cout << endl;

      cout << "Ingrese la longitud de los lados restantes para calcular el perimetro" << endl;
      cout << "Primer lado: ";
      cin >> longitud_lado3;
      cout << endl;
      cout << "Segundo lado: ";
      cin >> longitud_lado4;
      cout << endl;

      Triangulo triangulo(longitud_lado1, longitud_lado2, longitud_lado3, longitud_lado4, "Triangulo");
      triangulo.mostrar();
      triangulo.calcularArea();
      triangulo.calcularPerimetro();

      cout << endl;
      system("pause");

    } else if (opcion == 4) {
      // circulo
      cout << "Ingrese la longitud del radio del circulo: ";
      cin >> longitud_lado1;
      cout << endl;

      Circulo circulo(longitud_lado1, "Circulo");
      circulo.mostrar();
      circulo.calcularArea();
      circulo.calcularPerimetro();

      cout << endl;
      system("pause");
      
    } else if (opcion == 5) {
      // salir
      salir = true;
      cout << "Nos vemos!" << endl;
      cout << '' << endl;
    } else {
      // default
      cout << "Digite una opcion valida" << endl;
      cout << endl;
      system("pause");
    }

    cout << endl;
    longitud_lado1 = 0;
    longitud_lado2 = 0;

  } while( salir == false );

  system("pause");

  return 0;
}