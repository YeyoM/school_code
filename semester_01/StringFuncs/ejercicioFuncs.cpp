// @autor: Diego Emilio Moreno Sanchez, Hector Alejandro Perez, Angel David Ortiz; Fecha: 19 de noviembre de 2021
// Este programa indica si la palabra ingresada por el usuario es palindroma o no
// junto con esta, nos retorna otros datos sobre la palabra/frase ingresada

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

// funciones
void menu();
void op1(char cadena1[], char cadena2[]);
void op2(bool&);

// variables
bool salir = false;
int op, saber;
    char cadena1[30], // esta sera la original
         cadena2[30]; // esta sera la que sera convertida al reves
    char cadena3[99]=": ";// esta sera el acumulador de las palabras

int main() {
    printf("Este progrma revisara si una palabra es palimdroma\n");
    printf("\nSabes que es una palabra palindroma? 1.-Si 2.-No\n");
    scanf("%d",&saber);
    if(saber == 2){
    	printf("Una palabra palindroma es una palabra o frase que se lee igual en un sentido que en otro\n (por ejemplo; Ana, Anna, Otto)\n");
    	system("pause");
	}
    else if(saber == 1){
    	printf("Bien continua\n");
	}
    do {
        menu();
        printf("Ingrese una opcion: ");
        scanf("%d", &op);
        while(op != 1 && op != 2){
        	system("cls");
        	printf("Esa no es una opcion valida ingrese 1 o 2\n");
        	menu();
        	scanf("%d", &op);
		}
        if (op == 1) {
            printf("\nIngrese la palabra: ");
            scanf("%s", &cadena1);
            strlwr(cadena1);
            strcpy(cadena2, cadena1);
            op1(cadena1, cadena2);
	        strcat( cadena3, ", " );
	        strcat( cadena3, cadena1 );// aqui se uniran las palabras que cumplan las condiciones
	        printf( "Las palabras palindromas que lleva son %s.\n", cadena3 );

            system("pause");
			system("cls");
        } else if (op == 2) {
        	system("cls");
        	printf("Las palabras palindromas que ingreso fueron %s.\n", cadena3 );
            printf("Gracias vuelva pronto");
            system("pause");
            op2(salir);
        }
    } while ( salir == false );
    
    
    return 0;
}

//Funciones
void menu() {  
    printf("Que te gustaria hacer?\n");      
    printf("1.- Ingresar una palabra\n");
    printf("2.- Salir del programa\n");
}

void op1(char cadena1[], char cadena2[]) {
    int comp,
        larg;
    char cadena3[50];
    strrev(cadena1); // esta funcion invierte la cadena
    comp = strcmp(cadena1, cadena2);
    larg= strlen(cadena2);
    if(comp == 0){
        strupr(cadena2);
        sprintf( cadena3, "%s %s", cadena1, cadena2);
	    printf("Las palabras %s son palindromas\n", cadena3 );
		printf("La palabra \"%s\" tiene %i caracteres.\n\n", cadena2, larg);
    }
    else if (comp == -1){
        strupr(cadena2);
		printf("La palabra %s no es palimdroma\n", cadena2);
		printf("La palabra \"%s\" tiene %i caracteres.\n\n", cadena2, larg);
    }
}

void op2(bool& salir) {
    printf("Adios\n");
    salir = true;
}