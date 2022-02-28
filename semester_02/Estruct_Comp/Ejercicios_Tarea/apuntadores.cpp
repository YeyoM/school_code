// Diego Emilio Moreno Sanchez ID 264776 15/02/22

#include <iostream>
using namespace std;

int main() {

  float numero1 = 7.3,
        numero2;

  float* fPtr = nullptr;

  fPtr = &numero1;

  cout << "Valor a la que apunta fPtr: " << *fPtr << endl;

  numero2 = *fPtr;

  cout << "Valor de la variable numero2: " << numero2 << endl;

  cout << "Direccion de numero1: " << &numero1 << endl;

  cout << "Direccion de fPtr: " << &fPtr <<endl;

  // la direccion: no es la misma

  ///////////////////////////////////////////////
  ///////////////////////////////////////////////
  /*
    Revisando los fragmentos de codigo:

    1)  int a = 10;
        int *ptri = NULL;
        double x = 5.0;
        double *ptrf = NULL;
        ptri = &a;
        ptrf = &x;

    2)  char *ptr;
        *ptr = 'a';

        El error en este ejercicio 2, es que
        asigna mal el valor, aunque este codigo
        compila; al momento de ejecucion tira un
        segmentation fault
    
    3)  int *aptre;
        char *aptrc;
        int e = 5;
        aptre = &e;
        aptrc = aptre;

        El error en esta parte es que no se
        puede asignar entre un apuntador entero
        y un apuntador char

  */
  ///////////////////////////////////////////////
  ///////////////////////////////////////////////

  return 0;
}
