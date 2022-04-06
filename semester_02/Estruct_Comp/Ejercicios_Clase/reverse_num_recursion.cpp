#include <iostream>
using namespace std;

void reverse_num(int num){
  if(num != 0){
    cout << num % 10;
    return reverse_num(num / 10);
  } else {
    return;
  }
}

int main() {
  int num;
  cout << "Ingresa un numero: ";
  cin >> num;
  cout << "El numero " << num << " al reves es: " ;
  reverse_num(num);
  return 0;
}