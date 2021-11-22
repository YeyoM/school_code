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
void ordenarContactosClave();
void ordenarContactosNombre();
void ordenarContactosSalario();
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
    {"Pérez"},
    {"Rodríguez"},
    {"Sánchez"},
    {"Ramírez"},
    {"Cruz"},
    {"Flores"},
    {"Gómez"},
    {"Hernández"},
    {"García"},
    {"Martínez"},
    {"López"},
    {"González"},
    {"Campos"},
    {"Chávez"},
    {"Cruz"}
};
const char baseApellidosM[15][15] = {  
    {"Espinoza"},
    {"Gómez"},
    {"Guerrero"},
    {"Maldonado"},
    {"Ortiz"},
    {"Padilla"},
    {"Ramos"},
    {"Ríos"},
    {"Ruiz"},
    {"Soto"},
    {"Vázquez"},
    {"Sánchez"},
    {"Sandoval"},
    {"Rojas"},
    {"Muñoz"}
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
                    if (opcion == 1) {
                        buscarContactoPorNombre();
                    } else if (opcion == 2) {
                        buscarContactoPorClave();
                    } else {
                        printf("Digite una opcion valida\n");
                    }
                } while ( opcion < 1 || opcion > 2 );
                break;
            case 3:
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
    char persona[50];
    do {
        printf("Ingrese el nombre de quien desee buscar el contacto: ");
        gets(persona);
        // codigo aqui para buscar a la persona
    } while( encontrado == false);
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

}
void ordenarContactosNombre() {

}
void ordenarContactosSalario() {

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