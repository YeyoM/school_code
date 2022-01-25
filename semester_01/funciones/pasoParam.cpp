// @autores: Hector Robles Perez, Angel David Ortiz Quiroz, Diego Emilio Moreno Sanchez
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <conio.h>
using namespace std;

// declaracion de funciones
void menu();
void retirar(float&, float&);
void ingresar(float&, float&);


int main(){
    // declaracion de variables
    float saldo=5000.00;
    bool salir = false;
    float retiro=0.0, 
          ingreso=0.0;
    int opcion;
    printf("Esta es tu cartera virtual\n");
    do {
        printf("Tu saldo actual es de $%.2f, que te gustaria hacer?\n",saldo);
        menu();
        printf("\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch (opcion){
            system("cls");
            case 1:
            	printf("Cuanto dinero quieres retirar? ");
                scanf("%f", &retiro);
                retirar(saldo, retiro);
                printf("Un retiro de $ %f fue realizado exitosamente\n", retiro);
                retiro = 0;
                break;
            case 2:
            	printf("Cuanto dinero quiere ingresar?\n");
            	scanf("%f", &ingreso);
                ingresar(saldo, ingreso);
                printf("Un abono de $%.2f fue realizado exitosamente\n",ingreso);
                ingreso = 0;
                break;
            case 3:
            	printf("Su saldo final es $%.2f, adios\n",saldo);
            	salir = true;
                break;
            default:
                printf("Ingrese una opcion valida\n");
                break;
           }
       } while ( salir == false );
    getch();
    return 0;
}

// funciones
void menu(){
    printf("Menu\n");
    printf("1.- Retirar dinero\n");
    printf("2.- Ingresar dinero\n");
    printf("3.- Salir\n");
}
void retirar(float& saldo, float& salida){
    saldo -= salida;
}
void ingresar(float& saldo, float& entrada){
	saldo += entrada;
}
