/* @autores: Diego Emilio Moreno Sanchez,
             Hector Alejandro Perez, 
			 Angel David Ortiz;  
   
   Objetivos: Este programa simula el funcionamiento de un software enfocado a la administracion de trabajadores
              de una empresa, cada registro contiene el nombre del trabajador, su clave y su salario, en escencia 
              se trata de una aplicacion CRUD (Create, Read, Update, Delete) por sus siglas en inglés.
   
   Desarrollo: El programa permite modificar, crear, eliminar, y leer los registros creados.
               Para conseguir el efecto de una base de datos falsa, se utilizan 2 arreglos, uno para las claves de 
               tipo entero y otra para los salarios de tipo flotante, y por ultimo se utiliza una matriz de tipo char
               para almacenar los nombres de los trabajadores, primeramente en la ejecucion del programa entrando en el 
               main, nos encontramos las funciones que generan de manera totalmente aleatoria los nombres, claves y salarios.
               seguidamente, entramos al bucle principal de la aplicacion donde nos encontramos un menu con las diferentes
               opciones que el usuario puede ejecutar las cuales se basan en la metodologio CRUD. 
    
	Fecha: 8 de diciembre de 2021*/           

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

// declaracion de las funciones
void menu();
void generarNombres(char nombres[][50], const char baseNombres[][15], const char baseApellidosP[][15], const char baseApellidosM[][15]);
void generarClaves(int claves[]);
void generarSalarios(float salarios[]);
void mostrarTodosContactos();   
void buscarContactoPorNombre(); 
void buscarContactoPorClave();  
void ordenarContactosClave();   
void ordenarContactosNombre();  
void ordenarContactosSalario(); 
void insertarNuevoRegistro(int&, int claves[], float salarios[], char nombres[][50]);   
void eliminarRegistroClave(int&, int claves[], float salarios[], char nombres[][50]);   
void eliminarRegistroNombre(int&, int claves[], float salarios[], char nombres[][50]);  
void modificarRegistroClave(int modificarRegistro, int modificarRegistroPos, int claves[]);
void modificarRegistroNombre(int modificarRegistro, int modificarRegistroPos, char nombres[][50]);
void modificarRegistroSalario(int modificarRegistro, int modificarRegistroPos, float salarios[]);

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

// definicion de variables globales
int claves[20];             // 20 maximas claves
char nombres[20][50];       // 20 maximos nombres, con longitud de 50 cada uno
float salarios[20];         // 20 maximos salarios
int i, j, k;                // variables de iteracion
int opcion = 0,             // opcion ingresada por el usuario en el menu
    totalContactos = 9,     // lleva una cuenta para no exceder los limites de los arreglos
    modificarRegistro,      // almacena la clave del registro que vayamos a modificar
    modificarRegistroPos;   // almacena la posicion del registro que vayamos a modificar
bool salir = false,         // se utiliza en el menu para saber cuando salir
     encontrado = false,    // variable auxiliar para las funciones de buscar, modificar y eliminar
     volverMenu = false;    // variable que nos ayuda a saber cuando volver al menu principal

// main
int main() {
    system("cls");
    srand(time(NULL));
    // generamos los datos para la base de datos de los registros
    generarNombres(nombres, baseNombres, baseApellidosP, baseApellidosM);
    generarClaves(claves);
    generarSalarios(salarios);
    // ingresamos al bucle principal del programa (el menu)
    do {
        // mostramos el menu y pedimos que se digite una opcion
    	system("color F");
		printf("------------MENU DE REGISTROS------------\n");
        menu();
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        printf("\n");
        // utilizamos un switch para ejecutar las diferentes opciones
        switch (opcion) {
            // mostramos todos los registros
            case 1: 
                mostrarTodosContactos();
                break;
            // opcion para buscar un registro, ya sea por nombre o clave 
            case 2:
            	system("color E");
                printf("Desea buscar por\n1.- Nombre\n2.- Clave\n3.- Volver al menu\n");
                do {
                    printf("Ingrese la opcion: ");
                    scanf("%d", &opcion);
                    fflush(stdin);
                    if (opcion == 1) {
                        buscarContactoPorNombre(); 
                        fflush(stdin);
                        printf("Precione 3 para regresar al menu\n");
                    } else if (opcion == 2) {
                        buscarContactoPorClave();
                        fflush(stdin);
                        printf("Precione 3 para regresar al menu\n");
                    } else if (opcion == 3){
                        volverMenu = true;
                    } else {
                        printf("Digite una opcion valida\n");
                        fflush(stdin);
                    }
                } while (opcion < 1 || opcion > 3 || volverMenu == false);
                system("cls");
                break;
            // opcion para ordenar la lista de registros
            case 3:
                int ordenar;
            	printf("Como quiere ordenar la lista?\n");
            	printf("1.- Por clave \n2.- Por nombre \n3.- Por Sueldo\n4.- Volver al menu\n");
                printf("Ingrese la opcion: ");
            	scanf("%d", &ordenar);
            	while (ordenar != 1 && ordenar != 2 && ordenar != 3 && ordenar != 4) {
            		printf("Esa no es una opcion valida, ingresa 1, 2 o 3\n");
            		scanf("%d", &ordenar);
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
				} else if (ordenar == 4){
                	system("cls");
                    fflush(stdin);
				}
                break;
            // opcion para ingresar un nuevo registro
            case 4:
            	 system("color A");
                if (totalContactos >= 20) {
                    printf("La base de datos ha alcanzado su maxima capacidad\n");
                } else {
                    insertarNuevoRegistro(totalContactos, claves, salarios, nombres);
                }
                fflush(stdin);  
                break;
            // opcion para eliminar un registro      
            case 5:
            	system("color C");
                volverMenu = false;
                printf("Desea eliminar el registro por\n1.- Nombre\n2.- Clave\n3.- Volver al menu\n");
                do {
                    printf("Ingrese la opcion: ");
                    scanf("%d", &opcion);
                    fflush(stdin);
                    if (opcion == 1) {
                        eliminarRegistroNombre(totalContactos, claves, salarios, nombres);
                        printf("Precione 3 para regresar al menu\n");
                        fflush(stdin);
                    } else if (opcion == 2) {
                        eliminarRegistroClave(totalContactos, claves, salarios, nombres);
                        printf("Precione 3 para regresar al menu\n");
                        fflush(stdin);
                    } else if (opcion == 3) {
                        volverMenu = true;
                    } else {
                        printf("Digite una opcion valida\n");
                        fflush(stdin);
                    }
                } while (opcion < 1 || opcion > 3 || volverMenu == false);
                system("cls");
                break;
            // opcion para modificar un registro
            case 6:
            	system("color B");
                encontrado = false;
                volverMenu = false;
                do {
                    printf("Ingrese la clave del registro que desee modificar (digite '4' para volver al menu): ");
                    scanf("%d", &modificarRegistro);
                    printf("\n");
                    if (modificarRegistro == 4) {
                        volverMenu = true;
                        encontrado = true;
                    }
                    if (volverMenu == false) {
                        for (int i = 0; i < totalContactos; i++) {
                            if (modificarRegistro == claves[i]) {
                                modificarRegistroPos = i;
                                encontrado = true;
                            }
                        }
                        if (encontrado == false) {
                            printf("Registro no encontrado\n");
                        }
                    } 
                } while (encontrado == false);
                if (encontrado == true && volverMenu == false) {
                    do {
                        printf("Que desea modificar del registro?\n1.-Clave\n2.-Salario\n3.-Nombre\n");
                        printf("Ingrese la opcion: ");
                        scanf("%d", &opcion);
                        fflush(stdin);
                        if (opcion == 1) {
                            modificarRegistroClave(modificarRegistro, modificarRegistroPos, claves);
                            fflush(stdin);
                        } else if (opcion == 2) {
                            modificarRegistroSalario(modificarRegistro, modificarRegistroPos, salarios);
                            fflush(stdin);
                        } else if (opcion == 3) {
                            modificarRegistroNombre(modificarRegistro, modificarRegistroPos, nombres);
                            fflush(stdin);
                        } else {
                            printf("Digite una opcion valida\n");
                            fflush(stdin);
                        }
                    } while (opcion < 1 || opcion > 3);
                }
                system("cls");
                break;
            // opcion para salir del programa
            case 7:
                printf("\nGracias por usar este programa que tenga buen dia\n");
                salir = true;
                break;
            // en caso de que se digite una opcion incorrecta, se pedira otro numero
            default:
                system("cls");
                printf("Opcion incorrecta, ingresa una opcion valida...\n\n");
                break;
        }
        fflush(stdin);
    } while (salir == false);
    return 0;
}

// desarrollo de las funciones usadas en el programa

// funcion que uestra el menu principal
void menu() {
    printf("    1.- Mostrar todos los contactos\n");
    printf("    2.- Buscar un registro\n");
    printf("    3.- Ordenar los contactos\n");
    printf("    4.- Insertar un nuevo registro\n");
    printf("    5.- Eliminar un registro\n");
    printf("    6.- Modificar un registro\n");
    printf("    7.- Salir\n");
}

//Funcion que genera los nombres aleatoriamente
void generarNombres(char nombres[][50], const char baseNombres[][15], const char baseApellidosP[][15], const char baseApellidosM[][15]) {
    int posNombres,
        posApellidoP,
        posApellidoM;
    // primero con un arreglo generamos las posiciones que seleccionaremos para tomar los datos de las bases de datos falsas de manera aleatoria
    for (i = 0; i < 10; i++) {
        posNombres = rand()%15;
        posApellidoP = rand()%15;
        posApellidoM = rand()%15;
        //Se utiliza "sprintf" para unir las tres cadenas en una unica bueva
        sprintf(nombres[i], "%s %s %s", 
            baseNombres[posNombres], 
            baseApellidosP[posApellidoP], 
            baseApellidosM[posApellidoM]
        );
    }
}

//funcion para generar claves aleatorias
void generarClaves(int claves[]) {
    for (i = 0; i < 10; i++) {
        claves[i] = rand()%9000+1000;
    }
}

//funcion para generar salarios aleatorias
void generarSalarios(float salarios[]) {
    for (i = 0; i < 10; i++) {
        salarios[i]= (float)rand()/RAND_MAX * 100000;
    }
}

//Case1: Funcion que reune las tres funciones anteriores para mostrar los datos generados
void mostrarTodosContactos() {
    // en este caso es un bucle simple para mostrar todos los contactos
    system("cls");
    printf("  clave  |  salario  |  nombre  \n");
    printf("=======================================================\n");
    for (i = 0; i <= totalContactos; i++) {
        printf("  %d   |  %.2f |  %s\n", claves[i], salarios[i], nombres[i]);
    }
    printf("\n");
}

//Case2: Funcion para buscar contactos por nombre
void buscarContactoPorNombre() {
    char persona[50]; // guarda el nombre de la persona
    int contactosEncontrados[20]; // guarda la posicion de las personas encontradas
    int opcion = 0,
	    encontrados = 0, 
        pos = 0,
        val = 0;
    bool bien,
         encontrado;
    printf("\n");
    do {
    	bien = false;
        encontrado = false;
        printf("Ingrese el nombre de quien desee buscar el contacto: ");
        gets(persona);
        /* dentro de los siguientes bucles vamos analizando caracter por caracter
           ya que se pueden dar mas de una coincidencia se guardan las posiciones
           del arreglo en un arreglo llamado contactosEncontrados, tambien se usa una
           varible auxiliar llamada bien, para llevar la cuenta que todos y cada uno 
           de los caracteres coincidan y no solo algunos*/
        for(i = 0; i <= totalContactos + 1; i++) {
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
        /*Si se encontro una o mas coincidencias se imprimira cuales son esas
		coincidencias*/
        if (encontrado == true){
        	system("cls");
            printf("  clave  |  salario  |  nombre  \n");
            printf("=======================================================\n");
            for(i = 0; i < encontrados; i++) {
                pos = contactosEncontrados[i];
                printf("  %d   |  %.2f |  %s\n", claves[pos], salarios[pos], nombres[pos]);
            }
        }
        printf("\n");
        //Si no se encontro ese contacto, se pregunta si quiere buscar otro o salir
        if (encontrado == false) {
            printf("Contacto no encontrado, desea intentar nuevamente?\n1.-Si\n2.-No\n");
            printf("Ingrese la opcion: ");
            scanf("%d", &opcion);
            if ( opcion == 2 ) {
                encontrado = true;
            }
        }
        fflush(stdin);
    } while( encontrado == false);
    fflush(stdin);
    system("pause");
	system("cls");
}


//Case2: Funcion para buscar contactos por clave
void buscarContactoPorClave() {
    int buscarClave;
    // este es relativamente mas sencillo que el anterior, simplemente se buscar 
    // la clave ingresada, al solo haber una coincidencia se muestra en la misma ejecucion
    do {
        printf("\n");
        printf("Ingrese la clave de quien desee buscar el contacto: ");
        scanf("%i", &buscarClave);
        printf("\n");
        for (i = 0; i < totalContactos + 1; i++) {
            if (claves[i] == buscarClave) {
            	system("cls");
                printf("  clave  |  salario  |  nombre  \n");
                printf("=======================================================\n");
                printf("  %d   |  %.2f |  %s\n", claves[i], salarios[i], nombres[i]);
                encontrado = true;
            } 
        }
        printf("\n");
        //Si no se encontro ese contacto, se pregunta si quiere buscar otro o salir
        if (encontrado == false) {
            printf("Contacto no encontrado, desea intentar nuevamente?\n1.-Si\n2.-No\n");
            printf("Ingrese la opcion: ");
            scanf("%d", &opcion);
            if ( opcion == 2 ) {
                encontrado = true;
            }
        }
    } while( encontrado == false);
    system("pause");
    system("cls");
}

//Case3: Funcion para ordenar los contactos por clave
void ordenarContactosClave() {
    int i,
        j,
        aux;
	char aux3[70];
    // para ordenar los registros por su clave se hace de manera del menor al mayor
    // para esto se usa un algoritmo con variables auxiliares para ir intercambiando
    // valores
	for (i = 0; i < totalContactos + 1; i++) {
		for (j = i + 1; j < totalContactos + 1; j++) {
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
	/*Se limpia la pantalla y se imprime la lista ordenada 
	  segun la clave de menor a mayor*/
	system("cls");
    printf("  clave  |  salario  |  nombre  \n");
    printf("=======================================================\n");
    for (i = 0; i < totalContactos + 1; i++) {
        printf("  %d   |  %.2f |  %s\n", claves[i], salarios[i], nombres[i]);
    }
    printf("\n");
}

//Case3: Funcion para ordenar los contactos por nombre
void ordenarContactosNombre() {
    int i,
        j,
        aux;
	char temp[50];
	//For anidado que ordena de manera alfabetica
	for (i = 0; i < totalContactos + 1; i++) {
		for (j = i; j < totalContactos + 1; j++) {
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
	/*Se limpia la pantalla y se imprime la lista ordenada 
	  segun el nombre de manera alfabetica*/
	system("cls");
    printf("  clave  |  salario  |  nombre  \n");
    printf("=======================================================\n");
    for (i = 0; i < totalContactos + 1; i++) {
        printf("  %d   |  %.2f |  %s\n", claves[i], salarios[i], nombres[i]);
    }
    printf("\n");
}

//Case3: Funcion para ordenar los contactos por salario
void ordenarContactosSalario() {
    int i,
        j,
        aux;
	char aux3[50];
	//For anidado que ordena de menor a mayor
	for (i = 0; i < totalContactos + 1; i++) {
		for (j = i + 1; j < totalContactos + 1; j++) {
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
	/*Se limpia la pantalla y se imprime la lista ordenada 
	  segun el salario de menor a mayor*/
	system("cls");
    printf("  clave  |  salario  |  nombre  \n");
    printf("=======================================================\n");
    for (i = 0; i < totalContactos + 1; i++) {
        printf("  %d   |  %.2f |  %s\n", claves[i], salarios[i], nombres[i]);
    }
    printf("\n");
}

//Case4: Funcion para insertar un nuevo contacto al registro
void insertarNuevoRegistro(int& totalContactos, int claves[], float salarios[], char nombres[][50]) {
    int nuevaClave,
        pos = 0,
        val = 0,
        contactosEncontrados[20],
        encontrados = 0;
    float nuevoSalario;
    char nuevoNombre[50];
    bool claveInvalida,
         encontrado,
         nombreInvalido;
    printf("La clave debe estar compuesta por 4 digitos\n");    
     do {
    	claveInvalida = false;
        encontrado = false;
        nombreInvalido = false;
        // para la siguiente funcion, primero se busca que en el registro que no exista ni la clave ni el nombre
        printf("Ingrese la clave del nuevo trabajador(Ingrese 10000 para salir): ");
        scanf("%d", &nuevaClave);
		for (i = 0; i < totalContactos; i++) {
            if (claves[i] == nuevaClave) {
                printf("Esa clave ya existe, pertenece a:\n");
                 printf("  clave  |  salario  |  nombre  \n");
                printf("=======================================================\n");
                printf("  %d   |  %.2f |  %s\n", claves[i], salarios[i], nombres[i]);
                nombreInvalido = true;
            }
			if (nuevaClave == 1000){
				nombreInvalido = false;
			} 
        }
    }while (nuevaClave < 1000 || nuevaClave > 10000 || nombreInvalido == true);
    if(claveInvalida == false && nuevaClave < 9999){
        // en caso de que sea una clave valida, continuamos con el salario
        do {
            printf("\nIngrese el salario del nuevo trabajador: ");
            scanf("%f", &nuevoSalario);
        } while (nuevoSalario < 1000.0 || nuevoSalario > 99999.9);
        fflush(stdin);
        printf("\n");
        // ahora solo queda pedir el nombre y que este no coincida con alguno ya existente
        do{
            fflush(stdin);
            encontrado = false;
		    nombreInvalido = false;	
            int res = 0;
		    printf("Ingrese el nombre del nuevo trabajador: ");
            gets(nuevoNombre);
            for(i = 0; i <= totalContactos; i++) {
                res = strcmp(nuevoNombre, nombres[i]);
                if (res == 0) {
                    nombreInvalido = true;
                    encontrado = true;
                    contactosEncontrados[0] = i;
                }
            }
            printf("\n");
            if (encontrado == true){
            	printf("\nEse nombre(s) ya existe\n");
            }
            printf("\n");
        }while(encontrado == true);
        // en caso de completar toda la autenticacion por fin se guarda el nuevo registro
        if(nombreInvalido == false){
            totalContactos++; 
            claves[totalContactos] = nuevaClave;
            salarios[totalContactos] = nuevoSalario;
            strcpy(nombres[totalContactos], nuevoNombre);
        }
    }
    system("cls");
}

//Case5: Funcion para eliminar un contacto por clave
void eliminarRegistroClave(int& totalContactos, int claves[], float salarios[], char nombres[][50]) {
    int borrarClave;
    bool encontrado;
    do {
        // parecido a lo anterior, primero se pide la clave, y se verifica de que exista para asi eliminar dicho registro
        // obteniendo la posicion para elminar tambien el nombre y el salario
    	encontrado = false;
        printf("Ingrese la clave de quien desee elminar el registro: ");
        scanf("%d", &borrarClave);
        printf("\n");
        for (i = 0; i < totalContactos + 1; i++) {
            if (claves[i] == borrarClave) {
                // lo que hace el siguiente bucle es recorrer los elementos hacia arriba para no dejar huecos vacios
                for(j = i; j <= (totalContactos + 1); j++) {
                    if ( j == totalContactos + 1) {
                        claves[j] = claves[j];
                        salarios[j] = salarios[j];
                        strcpy(nombres[j], nombres[j]);
                    } else {
                        claves[j] = claves[j + 1];
                        salarios[j] = salarios[j + 1];
                        strcpy(nombres[j], nombres[j + 1]);
                    }
                }
                i--;
                totalContactos--;
                encontrado = true;
            } 
        }
    } while (encontrado == false);
    system("cls");
}

//Case5: Funcion para eliminar un contacto por nombre
void eliminarRegistroNombre(int& totalContactos, int claves[], float salarios[], char nombres[][50]) {
    char borrarNombre[50];
    bool encontrado;
    do {
        // parecido a lo anterior, primero se pide el nombre, y se verifica de que exista para asi eliminar dicho registro
        // obteniendo la posicion para elminar tambien la clave y el salario
    	encontrado = false;
        printf("Ingrese el nombre completo de quien desee elminar el registro: ");
        gets(borrarNombre);
        for (i = 0; i < totalContactos + 1; i++) {
            if (strcmp(nombres[i], borrarNombre) == 0) {
                // lo que hace el siguiente bucle es recorrer los elementos hacia arriba para no dejar huecos vacios
                for(j = i; j <= (totalContactos + 1); j++) {
                    if ( j == totalContactos + 1) {
                        claves[j] = claves[j];
                        salarios[j] = salarios[j];
                        strcpy(nombres[j], nombres[j]);
                    } else {
                        claves[j] = claves[j + 1];
                        salarios[j] = salarios[j + 1];
                        strcpy(nombres[j], nombres[j + 1]);
                    }
                }
                i--;
                totalContactos--;
                encontrado = true;
            } 
        }
    } while (encontrado == false);
    system("cls");
}

//Case6: Funcion para modificar la clave de un contacto
void modificarRegistroClave(int modificarRegistro, int modificarRegistroPos, int claves[]) {
    int nuevaClave;
    bool encontrado;
    do {
    	encontrado = false;
        // autenticamos que la clave exista, si la clave ya existe, no se modificara
        do {
            printf("\nIngrese la nueva clave (4 digitos): ");
            scanf("%d", &nuevaClave);
        } while (nuevaClave < 1000 || nuevaClave > 9999);
        for (i = 0; i < totalContactos + 1; i++) {
            if (claves[i] == nuevaClave) {
            	printf("Esa clave ya esta ocupada por:\n");
                printf("  clave  |  salario  |  nombre  \n");
                printf("=======================================================\n");
                printf("  %d   |  %.2f |  %s\n", claves[i], salarios[i], nombres[i]);
                encontrado = true;
            } 
        }
        printf("\n");
        // si la clave es valida, simplemente se modifica con el nuevo valor y listo
        if (encontrado == false) {
            printf("%d %d", modificarRegistroPos, nuevaClave);
            claves[modificarRegistroPos] = nuevaClave;
        }
    //Si la clave si existia no se modifica y se regresa a pedir la clave    
    } while( encontrado == true);
    system("pause");
    system("cls");
}

//Case6: Funcion para modificar el nombre de un contacto
void modificarRegistroNombre(int modificarRegistro, int modificarRegistroPos, char nombres[][50]) {
    int pos = 0,
        val = 0,
        contactosEncontrados[20],
        encontrados = 0;
    char nuevoNombre[50];
    bool encontrado,
         nombreInvalido;
    printf("Ingrese el nuevo nombre: ");
    gets(nuevoNombre);
    do{
    	encontrado = false,
        nombreInvalido = false;
        // igual que el metodo para buscar por nombre, se compara caracter con caracter
    for(i = 0; i <= totalContactos + 1; i++) {
            for (j = 0; j < strlen(nuevoNombre); j++) {
                if (nombres[i][j] == nuevoNombre[j]) {
                    if (j == strlen(nuevoNombre) - 1 && nombreInvalido == true) {
                        val = i;
                        contactosEncontrados[encontrados] = val;
                        encontrado = true;
                        encontrados++;
                    }
                    nombreInvalido = true;
                } 
				else {
                    nombreInvalido = false;
                }
            }
        if (nombreInvalido == true) {
        	printf("\nEse nombre ya existe, pertenece a:\n");
            printf("  clave  |  salario  |  nombre  \n");
            printf("=======================================================\n");
            for(i = 0; i < encontrados; i++) {
                pos = contactosEncontrados[i];
                printf("  %d   |  %.2f |  %s\n", claves[pos], salarios[pos], nombres[pos]);
            }
            printf("\nIngresa otro nombre\t");
            gets(nuevoNombre);
        }
        }
        // en caso de que el nombre sea valido se modifica y listo
        if(nombreInvalido == false){
         strcpy(nombres[modificarRegistroPos], nuevoNombre);
        }
    //Si el nombre si existia no se modifica y se regresa a pedir otro nombre     
    }while(nombreInvalido == true);
        system("cls");
    }

//Case6: Funcion para modificar el salario de un registro
void modificarRegistroSalario(int modificarRegistro, int modificarRegistroPos, float salarios[]) {
    float nuevoSalario;
    // se lee el nuevo salario y se modifica en caso de que sea valido
    do {
        printf("Ingrese el nuevo salario (10000.0 - 99999.99): ");
        scanf("%f", &nuevoSalario);
    } while (nuevoSalario < 10000.00 || nuevoSalario > 99999.99);
    salarios[modificarRegistroPos] = nuevoSalario;
}