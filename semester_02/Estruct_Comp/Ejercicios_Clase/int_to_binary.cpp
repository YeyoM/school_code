#include <iostream>
using namespace std;

int int_to_binary_recursion(int decimal);

int main() {
  int decimal, binary;
  cout << "Ingresa el numero: ";
  cin >> decimal;
  binary = int_to_binary_recursion(decimal);
  cout << "El numero en binario de  " << decimal << " es: " << binary << endl;
  cout << endl;
  return 0;
}

int int_to_binary_recursion(int decimal) {
  if(decimal != 0) {
    return (decimal % 2) + 10 * int_to_binary_recursion(decimal / 2);
  } else {
    return 0;
  }
}

