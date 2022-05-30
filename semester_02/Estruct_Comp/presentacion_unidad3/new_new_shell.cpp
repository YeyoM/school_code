  #include <iostream>
  #include <conio.h>

  using namespace std;

  int main(){
    int Arreglo[] = {4, 1, 10, 5, 2, 9, 6, 3, 7};

    int tam_arr = sizeof(Arreglo) / sizeof(Arreglo[0]);

    int i, j, incremento, aux;
    
    cout << "Arreglo original: " << endl;
    for(i = 0; i < tam_arr; i++) {
      cout << "\t" << Arreglo[i];
    }
    cout << endl;

    // write a code to sort an arrey usin shell sort
    while( incremento > 0 ) {
      for(i = incremento; i < tam_arr; i++) {
        aux = Arreglo[i];
        for(j = i; j >= incremento && Arreglo[j - incremento] > aux; j = j - incremento) {
          Arreglo[j] = Arreglo[j - incremento];
        }
        Arreglo[j] = aux;
      }
      incremento = incremento / 2;
    }

    cout << endl;
    cout << "elementos ordenados por metodo Shell sort" << endl;
    for(i = 0; i < tam_arr; i++) {
      cout << "\t" << Arreglo[i];
    }


    return 0;
  }

