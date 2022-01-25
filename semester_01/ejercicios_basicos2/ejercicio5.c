#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool salir = false;
int opcion = 0;

int main(){
    printf(".:Menu:. \n");
    printf("1. Matematicas\n");
    printf("2. Espa%col\n", 164);
    printf("3. Historia\n");
    printf("4. Salir\n");
    do {
        printf("Ingrese una opcion valida:\n");
        scanf("%d", &opcion);
        switch(opcion) {
            case 1: 
                printf("Matematicas\n");
                break;
            case 2: 
                printf("Espa%col\n", 164);
                break;
            case 3: 
                printf("Historia\n");
                break;
            case 4: 
                salir = true;
                printf("Saliendo\n");
                break;
            default:
                printf("Intente de nuevo\n");
                break;
        }
    } while ( salir == false );
    
    return 0;
}