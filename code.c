// incluimos las librerias
#include <stdio.h>
#include <stdlib.h>

// Programa que obtiene el factorial de un numero dado

// Declaramos variables
int i; 
int n;
double factorial = 1;


int main() {
   // Resultado 2
   printf("El valor en bytes de un tipo short es: %lu\n", sizeof(short));
   // Resultado 4
   printf("El valor en bytes de un tipo short es: %i\n", sizeof(int));
   // Resultado 4
   printf("El valor en bytes de un tipo short es: %lu\n", sizeof(long));
   // Resultado 4
   printf("El valor en bytes de un tipo short es: %lu\n", sizeof(float));
   // Resultado 8
   printf("El valor en bytes de un tipo short es: %lu\n", sizeof(double));
   printf("Introduce un Valor: ");
   // SI sue guarda en una variable de tipo float con %lf, la ejecucion
   // se detiene sin siquiera entrar al bucle for, pero cuando la guardo
   // con %f, entra en un bucle infinito
   scanf("%f", & n);
   // Bucle for para obtener el factorial de n
   for (i = 1; i <= n; i++){
      factorial = factorial * i;
      // Mostramos el factorial de n
      printf("El factorial de %d es: %d\n", i, factorial);
   }
   system("pause");
}
