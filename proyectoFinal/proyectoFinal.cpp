// @autor: Diego Emilio Moreno Sanchez, Hector Alejandro Perez, Angel David Ortiz; Fecha: 19 de noviembre de 2021
// aqui va la explicacion del programa

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <locale.h>

// definicion de funciones
void menu();
void generarNombres(char nombres[][50], const char baseNombres[][15], const char baseApellidosP[][15], const char baseApellidosM[][15]);
void generarClaves(int claves[]);
void generarSalarios(float salarios[]);
void mostrarTodosContactos();   // listo
void buscarContactoPorNombre(); // iniciado
void buscarContactoPorClave();  // listo
void ordenarContactosClave();   // listo
void ordenarContactosNombre();  // listo
void ordenarContactosSalario(); // listo
void insertarNuevoRegistro();
void eliminarRegistroClave();
void eliminarRegistroNombre();
void modificarRegistroClave();
void modificarRegistroNombre();
void modificarRegistroSalario();


// definicion de constantes

// Base de datos falsa para la creacion de los nombres
const char baseNombres[15][15] = {  
    {"Juan"},
    {"Sofia"},
    {"Hector"},
    {"Angel"},
    {"Alejandro"},
    {"David"},
    {"Diego"},
    {"Maria"},
    {"Ximena"},
    {"Daniel"},
    {"Santiago"},
    {"Regina"},
    {"Valentina"},
    {"Alexis"},
    {"Axel"}
};
const char baseApellidosP[15][15] = {  
    {"Perez"},
    {"Rodriguez"},
    {"Sanchez"},
    {"Ramirez"},
    {"Cruz"},
    {"Flores"},
    {"Gomez"},
    {"Hernandez"},
    {"Garcia"},
    {"Martinez"},
    {"Lopez"},
    {"Gonzalez"},
    {"Campos"},
    {"Chavez"},
    {"Cruz"}
};
const char baseApellidosM[15][15] = {  
    {"Espinoza"},
    {"Gomez"},
    {"Guerrero"},
    {"Maldonado"},
    {"Ortiz"},
    {"Padilla"},
    {"Ramos"},
    {"Rios"},
    {"Ruiz"},
    {"Soto"},
    {"Vazquez"},
    {"Sanchez"},
    {"Sandoval"},
    {"Rojas"},
    {"Moreno"}
};

// definicion de variables
int claves[20];         // 20 maximas claves
char nombres[20][50];   // 20 maximos nombres, con longitud de 50 cada uno
float salarios[20];     // 20 maximos salarios
int i, j, k;            // variables de iteracion
bool salir = false,
     encontrado = false;
int opcion = 0;
int totalContactos = 10;

// main
int main() {
    setlocale(LC_ALL, "spanish");
    srand(time(NULL));
    generarNombres(nombres, baseNombres, baseApellidosP, baseApellidosM);
    generarClaves(claves);
    generarSalarios(salarios);
    do {
        menu();
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        printf("\n");
        switch (opcion) {
            case 1: 
                mostrarTodosContactos();
                break;
            case 2:
                printf("Desea buscar por\n1.- Nombre\n2.- Clave\n");
                do {
                    printf("Ingrese la opcion: ");
                    scanf("%d", &opcion);
                    fflush(stdin);
                    if (opcion == 1) {
                        buscarContactoPorNombre();
                        fflush(stdin);
                    } else if (opcion == 2) {
                        buscarContactoPorClave();
                        fflush(stdin);
                    } else {
                        printf("Digite una opcion valida\n");
                        fflush(stdin);
                    }
                } while (opcion < 1 || opcion > 2);
                break;
            case 3:
                int ordenar;
            	printf("Como quiere ordenar la lista?\n");
            	printf("1.-Por clave \n2.-Por nombre \n3.-Por Sueldo\n");
                printf("Ingrese la opcion: ");
            	scanf("%d", &ordenar);
            	while (ordenar != 1 && ordenar != 2 && ordenar != 3){
            		printf("Esa no es una opcion valida, ingresa 1, 2 o 3\n");
            		scanf("%d",&ordenar);
				}
				if (ordenar == 1){
            	    ordenarContactosClave();
                    fflush(stdin);
                } else if (ordenar == 2){
                	ordenarContactosNombre();
                    fflush(stdin);
                } else if (ordenar == 3){
                	ordenarContactosSalario();
                    fflush(stdin);
				}
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                salir = true;
                break;
            default:
                system("cls");
                printf("Opcion incorrecta");
                break;
        }
        fflush(stdin);
    } while (salir == false);
    return 0;
}

// desarrollo de funciones
void menu() {
    printf("1.- Mostrar todos los contactos\n");
    printf("2.- Buscar un registro\n");
    printf("3.- Ordenar los contactos\n");
    printf("4.- Insertar un nuevo registro\n");
    printf("5.- Eliminar un registro\n");
    printf("6.- Modificar un registro\n");
    printf("7.- Salir\n");
}
void generarNombres(char nombres[][50], const char baseNombres[][15], const char baseApellidosP[][15], const char baseApellidosM[][15]) {
    int posNombres,
        posApellidoP,
        posApellidoM;
    for (i = 0; i < 10; i++) {
        posNombres = rand()%15;
        posApellidoP = rand()%15;
        posApellidoM = rand()%15;
        sprintf(nombres[i], "%s %s %s", 
            baseNombres[posNombres], 
            baseApellidosP[posApellidoP], 
            baseApellidosM[posApellidoM]
        );
    }
}
void generarClaves(int claves[]) {
    for (i = 0; i < 10; i++) {
        claves[i] = rand()%9000+1000;
    }
}
void generarSalarios(float salarios[]) {
    for (i = 0; i < 10; i++) {
        salarios[i]= (float)rand()/RAND_MAX * 100000;
    }
}
void mostrarTodosContactos() {
    system("cls");
    printf("  clave  |  salario  |  nombre  \n");
    printf("=======================================================\n");
    for (i = 0; i < totalContactos; i++) {
        printf("  %d   |  %.2f |  %s\n", claves[i], salarios[i], nombres[i]);
    }
    printf("\n");
}
void buscarContactoPorNombre() {
    char persona[50]; // guarda el nombre de la persona
    int contactosEncontrados[20]; // guarda la posicion de las personas encontradas
    int encontrados = 0,
        pos = 0,
        val = 0;
    bool bien = false;
    encontrado = false;
    printf("\n");
    do {
        printf("Ingrese el nombre de quien desee buscar el contacto: ");
        gets(persona);
        for(i = 0; i < totalContactos; i++) {
            for (j = 0; j < strlen(persona); j++) {
                if (nombres[i][j] == persona[j]) {
                    if (j == strlen(persona) - 1 && bien == true) {
                        val = i;
                        contactosEncontrados[encontrados] = val;
                        encontrado = true;
                        encontrados++;
                    }
                    bien = true;
                } else {
                    bien = false;
                }
            }
        }
        printf("\n");
        if (encontrado == true) {
            printf("  clave  |  salario  |  nombre  \n");
            printf("=======================================================\n");
            for(i = 0; i < encontrados; i++) {
                pos = contactosEncontrados[i];
                printf("  %d   |  %.2f |  %s\n", claves[pos], salarios[pos], nombres[pos]);
            }
        }
        printf("\n\n");
    } while( encontrado == false);
    fflush(stdin);
}
void buscarContactoPorClave() {
    int buscarClave;
    do {
        printf("\n");
        printf("Ingrese la clave de quien desee buscar el contacto: ");
        scanf("%i", &buscarClave);
        printf("\n");
        for (i = 0; i < totalContactos; i++) {
            if (claves[i] == buscarClave) {
                printf("  clave  |  salario  |  nombre  \n");
                printf("=======================================================\n");
                printf("  %d   |  %.2f |  %s\n", claves[i], salarios[i], nombres[i]);
                encontrado = true;
            } 
        }
        printf("\n");
        if (encontrado == false) {
            printf("Contacto no encontrado, desea intentar nuevamente?\n1.-Si\n2.-No\n");
            printf("Ingrese la opcion: ");
            scanf("%d", &opcion);
            if ( opcion == 2 ) {
                encontrado = true;
            }
        }
        system("pause");
    } while( encontrado == false);
    system("cls");
}
void ordenarContactosClave() {
    int i,
        j,
        aux;
	char aux3[70];
	for (i = 0; i < totalContactos; i++) {
		for (j = i + 1; j < totalContactos; j++) {
			if (claves[i] > claves[j]) {
				aux = claves[i];
				claves[i] = claves[j];
				claves[j] = aux;
				aux = salarios[i];           
				salarios[i] = salarios[j];
				salarios[j] = aux;
				strcpy(aux3, nombres[i]);
				strcpy(nombres[i], nombres[j]);
				strcpy(nombres[j], aux3);
			}
		}
	}
	system("cls");
    printf("  clave  |  salario  |  nombre  \n");
    printf("=======================================================\n");
    for (i = 0; i < totalContactos; i++) {
        printf("  %d   |  %.2f |  %s\n", claves[i], salarios[i], nombres[i]);
    }
    printf("\n");
}
void ordenarContactosNombre() {
    int i,
        j,
        aux;
	char temp[50];
	for (i = 0; i < totalContactos; i++) {
		for (j = i; j < totalContactos; j++) {
			if (strcmp(nombres[i], nombres[j]) > 0) {
				strcpy(temp, nombres[i]);
				strcpy(nombres[i], nombres[j]);
				strcpy(nombres[j], temp);
				aux = salarios[i];           
				salarios[i] = salarios[j];
				salarios[j] = aux;
				aux = claves[i];
				claves[i] = claves[j];
				claves[j] = aux;
			}
		}
	}
	system("cls");
    printf("  clave  |  salario  |  nombre  \n");
    printf("=======================================================\n");
    for (i = 0; i < totalContactos; i++) {
        printf("  %d   |  %.2f |  %s\n", claves[i], salarios[i], nombres[i]);
    }
    printf("\n");
}
void ordenarContactosSalario() {
    int i,
        j,
        aux;
	char aux3[50];
	for (i = 0; i < totalContactos; i++) {
		for (j = i + 1; j < totalContactos; j++) {
			if(salarios[i] > salarios[j]) {
				aux = salarios[i];           
				salarios[i] = salarios[j];
				salarios[j] = aux;
				aux = claves[i];
				claves[i] = claves[j];
				claves[j] = aux;
				strcpy(aux3, nombres[i]);
				strcpy(nombres[i], nombres[j]);
				strcpy(nombres[j], aux3);
			}
		}
	}
	system("cls");
    printf("  clave  |  salario  |  nombre  \n");
    printf("=======================================================\n");
    for (i = 0; i < totalContactos; i++) {
        printf("  %d   |  %.2f |  %s\n", claves[i], salarios[i], nombres[i]);
    }
    printf("\n");
}
void insertarNuevoRegistro() {

}
void eliminarRegistroClave() {

}
void eliminarRegistroNombre() {

}
void modificarRegistroClave() {

}
void modificarRegistroNombre() {

}
void modificarRegistroSalario() {

}