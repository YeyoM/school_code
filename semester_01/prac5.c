#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void menu();
void tabla3(int longi);
void tabla2(int longi);

bool salir = false;
int op = 0,
    longitud = 0;

int main() {
    do {
        menu();
        printf("Selecciona la opcion que deseas: ");
        scanf("%d", &op);
        switch (op) {
            case 1: 
                printf("\n");
                tabla3(2);
                printf("\n");
                break;
            case 2:
                printf("\n");
                tabla2(2);
                printf("\n");
                break;
            case 3:
                printf("\n");
                printf("Que tenga un lindo dia\n");
                salir = true;
                break;
            default:
                printf("Selecciona una opcion valida\n");
                break;
        }
    } while (salir == false);
    return 0;
}

void menu() {
    printf("1) Tabla de verdad de la conjuncion\n");
    printf("2) Tabla de verdad de la disyuncion\n");
    printf("3) Salir\n");
}

void tabla3(int longi) {
    int i = 0,
        j = 0,
        k = 0,
        res = 0;
        printf(" p q r | t\n");
        printf("===========\n");
    for (i = 0; i <= longi - 1; i++){
        for (j = 0; j <= longi - 1; j++){
            for (k = 0; k <= longi - 1; k++){
                res = i && j && k;
                printf(" %d %d %d | %d\n", i, j, k, res);
            }
            k = 0;
        }
        j = 0;
    }
}
void tabla2(int longi) {
    int i = 0,
        j = 0,
        res = 0;
    printf(" p q | t\n");
    printf("=========\n");
    for (i = 0; i <= longi - 1; i++){
        for (j = 0; j <= longi - 1; j++){
            res = i || j;
            printf(" %d %d | %d\n", i, j, res);
        }
        j = 0;
    }
}