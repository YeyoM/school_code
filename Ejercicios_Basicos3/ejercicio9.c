#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h> 

int main() {
    bool correct = false;
    char password[20];
    char passwordcorr[20] = "12345";
    int valor;
    do{
        printf("\nIngrese su password: ");
        fgets(password, sizeof(password), stdin);   // obtenemos el password ingresado por el usuario
        valor = strcmp(password, passwordcorr);     // con la func strcmp(), retorna 0 si los strings son iguales
        puts(password);                             // y retorna 1 si no son iguales
        if ( valor == 1 ) {
            printf("\nPassword incorrecto");
        } else {
            correct = true;                         // si son iguales ponemos correct = true para salir del bucle
        }
    } while ( correct == false );
    
    return 0;
}