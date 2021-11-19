#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int part = 0;
int i = 0,
    ganador,
    boletoganador;

int main() {
    printf("Ingrese el numero de participantes: ");
    scanf("%d", &part);
    printf("\n");
    int partArr[part];
    srand(time(NULL));
    for (i = 0; i < part; i++) {
        partArr[i] = rand()%part;
    }
    ganador = rand()%part;
    printf("Los boletos generados fueron: ");
    printf("\n");
    for (i = 0; i < part; i++) {
        printf("%d, ", partArr[i]);
    }
    printf("\n");
    printf("El ganador es el boleto: %i, posicion: %i", partArr[ganador], ganador);
    printf("\n");
    return 0;
}