#include <iostream>
#include <math.h>
using namespace std;

/*
Benemerita Universidad Autonoma de Aguascalientes
Ing. En Computacion Inteligente
Estructuras Computacionales Avanzadas

    Diego Emilio Moreno Sanchez     ID: 264776
    Diego Emanuel Saucedo Ortega    ID: 261230
    Carlos Daniel Torres Macias     ID: 244543

Profesor: Mr. en C. Luis Fernando Gutierrez Marfileño

---->PROGRAMA
    Implementa la regla de trapecios por segmentos multiples para el calculo de
    integrales
*/

#define N 3

float fx(float x){
    return 1 / cos(x);
}

void TSM(){
    float a, b;
    cout << "\n\t\tIngrese limite inferior de la integral: "; 
    cin >> a;
    cout << "\n\t\tIngrese limite superior de la integral: "; 
    cin >> b;

    float h = (b - a)/ N;

    float sum = fx(a);

    for (float i = a + h; i < b; i += h){
        sum += 2 * fx(i);
    }

    sum += fx(b);
    sum *= h / 2;

    cout << " El resultado de la integral es: " << sum << endl;
}

int main(){

  int op;

  do {
    
      cout << "----Es un secreto, tu mirada y la mia un presentimiento----\n";
      cout << "\n\t1.Integral sec(x) por regla de trapecios multiples\n\t2.Salir";
      cout << "\n\tSeleccion--->"; cin >> op;
      
      if(op == 1){ 
        TSM(); 
      }
      
      system("pause");
      system("cls");

  } while(op != 2);
}