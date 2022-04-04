#include <iostream>
using namespace std;

void imprimir(int i);

int main() {
  imprimir(1);
  return 0;
}

void imprimir(int i) {
  if (i <= 10) {
    cout << endl << i << " Holaaaaaa";
    imprimir(i + 1);
  }
}
