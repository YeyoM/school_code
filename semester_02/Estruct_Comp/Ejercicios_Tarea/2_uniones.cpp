#include <iostream>

using namespace std;

union Value {
    int entero;
    long double doble;
};

int main(){
  
  cout << endl;

  // Usos y buenas practicas, la union ayuda a ahorrar espacio
  Value valor = { 12 };

  cout << "Primer valor: " << valor.entero << endl;
  cout << "Bits ocupados: " << sizeof(valor.entero) << endl;

  cout << endl;


  valor.doble =  231232.25;

  cout << "Segundo valor: " << valor.doble << endl;
  cout << "Bits ocupados: " << sizeof(valor.doble) << endl;


  return 0;

}