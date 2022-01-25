#include <stdio.h>

#define pi 3.1416                               // definimos pi

float radio = 0,                                // definimos radio y result
      result = 0;

int main() {
    printf("Ingrese el radio del circulo: ");   // pedimos el radio
    scanf("%f", &radio);                        // leemos el radio
    result = pi * radio * radio;                // calculamos el area y guardamos en result
    printf("\nEl area es: %.2fcm2\n", result);  // imprimir el area
    return 0;
}