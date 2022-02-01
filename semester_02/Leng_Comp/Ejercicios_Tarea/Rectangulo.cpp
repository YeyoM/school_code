#include <iostream>
using namespace std;

class Cuadrilatero {
  private:
    int lado1;
    int lado2;
  
  public:
    Cuadrilatero(int, int);
    int calcularArea();
    int calcularPerimetro();

};

Cuadrilatero::Cuadrilatero(int _lado1, int _lado2) {
  lado1 = _lado1;
  lado2 = _lado2;
}

int Cuadrilatero::calcularArea() {
  int area = 0;
  area = lado1 * lado2;
  return area;
}

int Cuadrilatero::calcularPerimetro() {
  int perimetro = 0;
  perimetro = ( lado1 * 2 ) + ( lado2 * 2);
  return perimetro;
}

int main() {
  int lado1, lado2;
  cout<<"Ingrese el lado 1: ";
  cin >>lado1;
  cout<<endl;
  cout<<"Ingrese el lado 2: ";
  cin >>lado2;
  Cuadrilatero rectangulo(lado1, lado2);
  int area = rectangulo.calcularArea();
  int perimetro = rectangulo.calcularPerimetro();
  cout<<"Area: "<<area;
  cout<<endl;
  cout<<"Perimetro: "<<perimetro;
  return 0;
}