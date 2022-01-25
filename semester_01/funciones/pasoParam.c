#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// declaracion de funciones
void menu();
float ret(float &saldo, float &salida);
float ing(float &saldo, float &entrada);

// declaracion de variables
float saldo=5000.00;
bool salir = false;
float retiro=0.0, 
      ingreso=0.0;
int opcion;

int main(){
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
        	printf("Cuanto dinero quieres retirar? \n");
            scanf("%f", &retiro);
            ret(saldo, retiro);
            printf("Un retiro de $ %f fue realizado exitosamente\n", retiro);
            saldo = saldo - retiro;
            retiro = 0;
            system("cls");
            break;
        case 2:
        	printf("Cuanto dinero quiere ingresar?\n");
            ing(saldo, ingreso);
            printf("Un abono de $%.2f fue realizado exitosamente\n",ingreso);
            saldo = saldo + ingreso;
            ingreso = 0;
            system("cls");
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
    return 0;
}

// funciones
void menu(){
    printf("Menu de compra \n");
    printf("1.- Retirar dinero");
    printf("2.- Ingresar dinero");
    printf("3.- Salir");
}
void ret(float *saldo, float *salida){
    scanf("%f",&salida);
    while(saldo < salida){
        printf("No cuentas con esa cantidad, inteta retirar una cantidad mas chuca\n");
        scanf("%f", &salida);
    }
    if(salida == 0){
        printf("Vaya un retiro de $0, supongo que te equivocaste de operacion");
    printf("%.2f",salida);
}
void ing(float *saldo, float *entrada){
    scanf("%f",&entrada);
    while(entrada < 0){
        printf("No puedes ingresar dinero negativo, ingresa otro valor\n");
        scanf("%f", &entrada);
    }
    if(entrada == 0){
        printf("Vaya una entrada de $0, supongo que te equivocaste de operacion");
    }    
    printf("%.2f", entrada);
}