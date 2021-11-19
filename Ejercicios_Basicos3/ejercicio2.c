#include <stdio.h>

float radio = 0,                                // definimos radio result y pi
      result = 0,
      pi = 3.1416;

int main() {
    printf("Ingrese el radio del circulo: ");   // pedimos el radio
    scanf("%f", &radio);                        // leemos el radio
    result = pi * radio * radio;                // calculamos el area y guardamos en result
    printf("\nEl area es: %.2fcm2\n", result);  // imprimir el area
    return 0;
}