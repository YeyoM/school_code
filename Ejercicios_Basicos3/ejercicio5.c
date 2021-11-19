#include <stdio.h>

char nombre1[20];
char nombre2[20];
int edad1 = 0,
    edad2 = 0;

int main() {
    printf("\nIngrese el nombre de la primer persona: ");
    fgets(nombre1, sizeof(nombre1), stdin);
    printf("\nIngrese el nombre de la segunda persona: ");
    fgets(nombre2, sizeof(nombre2), stdin);
    printf("\nIngrese la edad de la primer persona: ");
    scanf("%d", &edad1);
    printf("\nIngrese la edad de la segunda persona: ");
    scanf("%d", &edad2);
    if(edad1 > edad2) {
        puts(nombre1);
        printf(" es mayor que ");
        puts(nombre2);
    } 
    else if(edad1 < edad2){ 
        puts(nombre2);
        printf(" es mayor que ");
        puts(nombre1);
    }
    else {
        printf("Los dos tienen la misma edad");
    }
    return 0;
}