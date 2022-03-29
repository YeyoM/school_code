#include <iostream>
#include <stack>
using namespace std;

int main() {
  stack <int> mystack;

  mystack.push(0);
  mystack.push(1);
  mystack.push(2);
  mystack.push(3);
  mystack.push(4);


  cout << endl << "Stack: " << mystack.top() << endl;

  cout << endl << "Total de elementos: " << mystack.size() << endl;
  cout << endl << "Vaciando pila: ";

  while (!mystack.empty()) {
    cout << mystack.top() << " ";
    mystack.pop();
  }

  cout << endl;

  stack<char> mystack2;
  string cadena;
  char caracter;

  cout << endl << "Ingrese una cadena: ";
  getline(cin, cadena);
  for(int i = 0; i < cadena.length(); i++) {
    caracter = cadena[i];
    mystack2.push(caracter);
  }

  cout << endl << "Longitud de la cadena es: " << mystack2.size() << endl;
  cout << endl << "Al reves: ";

  while (!mystack2.empty()) {
    cout << mystack2.top() << " ";
    mystack2.pop();
  }

  return 0;
}