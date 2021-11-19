#include <stdio.h>

int simb    = 0, // es el numero de simbolos 
    peso    = 0, // es el peso de la(s) cadedna(s) a buscar
    longi   = 3, // es la longitud de todas las cadenas
    totals  = 0, // son todas las cadenas encontradas con dicho peso
    i       = 0, // i, j, k son los indices por los que vamos a iterar
    j       = 0, // para generar las combinaciones
    k       = 0,
    suma    = 0,
    cont    = 0; // contador para obtener el numero total de cadenas posibles
int main() {
    printf("\nIngrese el numero de simbolos que desea utilizar(mayor a 0 y menor a 9): ");
    scanf("%d", &simb);
    printf("\nIngrese el peso de las cadenas a buscar: ");
    scanf("%d", &peso);
    printf("\nCadena Peso \n");
    for (i = 0; i <= simb - 1; i++){
        for (j = 0; j <= simb - 1; j++){
            for (k = 0; k <= simb - 1; k++){
                suma = i + j + k;
                printf(" %d%d%d     %d \n", i, j, k, suma);
                cont++;
                suma = 0;
                if ( i + j + k == peso) {
                    totals++;
                }
            }
            k = 0;
        }
        j = 0;
    }
    printf("\nEl numero de cadenas con peso %d son: %d, de las %d posibles", peso, totals, cont);
    return 0;
}

