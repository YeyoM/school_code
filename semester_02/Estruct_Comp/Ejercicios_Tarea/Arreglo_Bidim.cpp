/* Crea un array bidimensional que contenga 3 columnas y las 
filas que tú quieras, las dos primeras columnas tendrán 
números (generados aleatoriamente o introducidos por teclado) 
y en la 3 columna será el resultado de sumar el número de la
primera y segunda columna. Por último, desplegar o mostrar 
el array o arreglo de la siguiente forma: 

3 + 5 = 8
4 + 4 = 7

Reto: Piensa de qué forma puedes desplegar 
con un solo con un solo bucle (FOR).*/

// @utor Diego Emilio Moreno Sanchez

/*NOTA: Maestra, una disculpa por haber entregado los 
        ultimos dos ejercicios fuera de la hora de entrega, 
        la verdad no tengo ninguna justificacion pero le 
        agradeceria mucho si pudiera revisarlos, 
        de antemano gracias :)*/

#include <iostream>
#include <time.h>
using namespace std;

int filas;

int main() {
  srand(time(NULL));

  // inicializamos el arreglo
  cout << "Ingrese el numero de filas: ";
  cin >> filas;
  cout << endl;
  int sumas[filas][3];

  //generamos el arreglo con numeros aleatorios 
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j <= 2; j++) {
      // en caso de que sea el ultimo elemento j == 2, 
      // sumamos los dos anteriores
      if (j == 2) {
        sumas[i][j] = sumas[i][j - 2] + sumas[i][j - 1];
      } else { // caso contrario generamos un numero aleatorio
        sumas[i][j] = rand()%9+1;
      }
    }
  }

  // mostramos los resultados con un solo ciclo For
  for(int i = 0; i < filas; i++) {
    int j = 2;
    cout << sumas[i][j-2] << " + " << sumas[i][j-1] << " = " << sumas[i][j] <<endl;
  }



  return 0;
}