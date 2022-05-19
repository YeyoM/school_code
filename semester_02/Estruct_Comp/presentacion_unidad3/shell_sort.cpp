#include<iostream>
#include<conio.h>

using namespace std;

int main(){
  int Arreglo[] = {5, 2, 9, 4, 1, 6};

  int tam_arr = sizeof(Arreglo) / sizeof(Arreglo[0]);
  cout << "Tamano del arreglo: " << tam_arr << endl;

  int i, j, incremento;
  
  for(i = 0; i < tam_arr; i++) {
      cout << "\t" << Arreglo[i];
    }
  cout << endl;

  // vamos a iterar en el arreglo de la siguiente manera:
  // tenemos el incremento que es el tam_arr / 2
  // ya que vamos a comparar los elementos de la siguiente manera:
  // Arreglo[i] con Arreglo[i + incremento], osea el primero con el de la mitad, y así
  // sucesivamente. Iremos haciendo el incremento cada vez mas pequeño con
  // incremento = incremento / 2, tan pequeño hasta que incremento sea 0.
  for (incremento = tam_arr/2; incremento > 0; incremento = incremento / 2) {
    // Ahora lo que haremos es recorrer el arreglo desde el incremento hasta el final
    // en la primera vuelta siempre será de la mitad en adelante, y así sucesivamente.
    for (i = incremento; i < tam_arr; i++) {
      // Guardamos el valor de la posicion i en una variable auxiliar
      int temp = Arreglo[i];
      // Ahora recorremos el arreglo desde la posicion i hasta que nos topemos con
      // algun valor en el que j sea mayor o igual que incremento y que sobre todo
      // el elemento del arreglo en la posicion de j - incremento sea mayor que temp.
      // iremos buscando y cada iteracion j sera j - incremento.
      for (j = i; j >= incremento && Arreglo[j - incremento] > temp; j = j - incremento) {
        // En caso de que se cumpla la condicion, guardamos el valor de la posicion j
        Arreglo[j] = Arreglo[j - incremento];
      }
      // Finalmente guardamos el valor de temp en la posicion j
      Arreglo[j] = temp;  
    }
  }

  cout << "elementos ordenados por metodo Shell sort" << endl;
  for(i = 0; i < tam_arr; i++) {
    cout << "\t" << Arreglo[i];
  }

  return 0;
}

