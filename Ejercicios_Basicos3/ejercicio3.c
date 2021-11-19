#include <stdio.h>

float pulg = 0,
      cm = 0;                                       // definimos las variables para los cm y las pulgadas

int main() {
    printf("Ingrese las pulgadas: ");
    scanf("%f", &pulg);
    cm = pulg * 2.54;                               // convertimos pulgadas a cm multiplicando por 2.54
    printf("\n%.2f pulgadas son: %.2fcm", pulg, cm);
    return 0; 
}

