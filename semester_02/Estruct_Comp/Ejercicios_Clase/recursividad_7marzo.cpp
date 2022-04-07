#include <iostream>
#include <string>

using namespace std;

string cambia(int n);//prototipo

int main(int argc, char** argv) {
  cout << cambia(10);
  return 0;
}

string cambia(int n){
  string dig;
  string bin;
  int res = n % 2;
  int coc = n / 2;
  if (res == 0) //condicion de apoyo para utilizar "0" o "1"
    dig = "0";
  else
    dig = "1";
  if (coc == 0) //condicion de paro
    bin = dig; //caso base
  else
    bin = cambia(coc) + dig;
  return bin;
}

