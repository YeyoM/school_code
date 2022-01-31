// @utor: Diego Emilio Moreno Sanchez, ID: 264776
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arr[5],
    mayor,
    pos_may,
    dist;

int main() {
  srand(time(NULL));
  // Generamos el arreglo aleatorio
  for (int i = 0; i < 5; i++) {
    arr[i] = rand()%10+1;
    printf("%d, ", arr[i]);
  }

  // Para comparar, suponemos que el primer elemento es el mayor elemento
  mayor = arr[0];

  for (int i = 0; i < 5; i++) {
    // comparamos cada elemento del arreglo con el "mayor"
    if (arr[i] > mayor) {
      // si encontramos algun elemento mas grande que "mayor", se modifica con ese nuevo valor
      mayor = arr[i];
      // guardamos la posicion del arreglo para sacar la distancia a cada elemento
      pos_may = i;
    }
  }

  printf("\n");

  for (int i = 0; i < 5; i++) {
    // evaluamos, si la posicion del mayor es igual a i, ignoramos y pasamos al siguiente
    if (i != pos_may) {
      // checamos si es mayor o menor para no mostrar distancias negativas
      if (i < pos_may) {
        dist = pos_may - i;
        printf("%d -> %d casilla(s) de separacion\n", arr[i], dist);
      } else if (i > pos_may) {
        dist = i - pos_may;
        printf("%d -> %d casilla(s) de separacion\n", arr[i], dist);
      }
      dist = 0;
    }
  }

  // al final mostramos el mayor y su posicion para confirmar nuestrar respuestas
  printf("\n%d - %d", mayor, pos_may);
}