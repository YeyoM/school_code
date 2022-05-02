// Alumno -> Diego Emilio Moreno Sanchez
// ID -> 264776
// Fecha ->02/05/2022
// Ejercicio 1 Examen Parcial 2

/*
  Explicacion del ejercicio (Trabajando con los vagones de un tren):

  - Los vagones del tren se identifican con numeros de 2 digitos
  - Aunque las pilas no se recorren, para efecto de pruebas y poder
    revisar, se pide la función imprimir tren, que es imprimir el 
    vector de 0 hasta la cima. La función imprimir la mandaras llamar 
    después de cada inserción y al finalizar el proceso de eliminación.
  - Controlar el programa con un menú de tres opciones: 
    1. Ingresar vagones 
    2 .Eliminar vagones 
    3. Salir
  - En la opción 1. 
    Programar que el ingreso de vagones sea automático, por cada vez 
    que entres a la opción 1, agrega 5 vagones, es decir debes hacer 
    5 push, cada vagón ingresado identifícalo con un numero aleatorio 
    entre 100 y 999. Es decir, No se ingresan datos por teclado. Antes 
    de salir de la opción 1 manda llamar a la función imprimir para 
    verificar que las inserciones se realizaron y que el ultimo dato 
    que se imprime corresponde al que esta en la cima de la pila.
    Considerar imprimir el mensaje “El tren tiene su máximo de vagones” 
    cuando la pila este llena.
  - En la opción 2. 
    Solo se elimina UN vagón cada vez que entras a la opción 2. 
    Considerar lo siguiente.
    -> Imprimir cuando sea el caso el mensaje de 
       “Ya no hay vagones que sacar”
    -> Pedir el número de vagón de eliminar, realizar el proceso para 
       sacar ese vagón, sabiendo que en una PILA solo puedes ver el dato 
       de la cima, si quieres ver lo que hay más abajo tienes que dar POP 
       hasta llegar al dato que buscas, NO hay otra forma. Al encontrar 
       el vagón deseado y sacarlo, deberás regresar todos los vagones que 
       tuviste que sacar hasta encontrar el que buscabas.
    -> IMPORTANTE Y OBLIGATORIO utilizar una pila auxiliar (vía auxiliar) 
       para colocar los vagones que tienes que sacar (pop) en lo que 
       encuentras el vagón buscado.
    -> Mostrar el tren después de cada eliminación, llamando a la función 
       imprimir.
  - En la opcion 3.
    Salir del programa.
*/
// Librerias =================================================================
#include <iostream>
#include <stdbool.h>  // -> Para usar bool
#include <stdio.h>    
#include <stdlib.h>
#include <time.h>     // -> Para usar numeros aleatorio
using namespace std;

// CONSTANTES ================================================================
#define TAM 15

// PROTOTIPOS ================================================================
void imprimirTren(int tren[], int cima);
void ingresarVagones(int tren[], int &cima);
void eliminarVagones(int tren[], int &cima);
void mostrarMenu();

// VARIABLES GLOBALES ========================================================
int tren[TAM];
int cima = -1;
int opcion;
bool salir = false;

// PROGRAMA PRINCIPAL ========================================================
int main() {
  do {
    mostrarMenu();
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    if (opcion == 1) {
      ingresarVagones(tren, cima);
    } else if (opcion == 2) {
      eliminarVagones(tren, cima);
    } else if (opcion == 3) {
      salir = true;
    } else {
      cout << "Opcion no valida" << endl;
    }
  } while (!salir);
  return 0;
}

// FUNCIONES ================================================================

void imprimirTren(int tren[], int cima) {
  cout << endl;
  cout << "Tren: ";
  /* Imprimiendo la pila de 0 hasta la cima */
  for (int i = 0; i <= cima; i++) {
    cout << "" << tren[i] << " ";
  }
  cout << endl << endl;
}

void ingresarVagones(int tren[], int &cima) {
  /* Checando que la pila pueda almacenar otros 5 vagones */
  if (cima >= 10) {
    cout << "Imposible ingresar otros 5 vagones" << endl;
  } else {
    int vagon;
    /* Generando 5 numeros aleatorios de 4 digitos e ingresandolos a la pila */
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
      vagon = rand() % 1000 + 100;
      cima++;
      tren[cima] = vagon;
    }
    /* Imprimiendo el tren */
    imprimirTren(tren, cima);
    /* Mostrando el mensaje en caso de que la pila este llena */
    if (cima == TAM - 1) {
      cout << "El tren tiene su maximo de vagones" << endl << endl;
    }
  }
}

void eliminarVagones(int tren[], int &cima) {
  /* Checando que la pila no este vacia */
  if (cima == -1) {
    cout << "Ya no hay vagones que sacar" << endl;
  } else {
    int vagon;
    cout << "Ingrese el numero de vagon a sacar: ";
    cin >> vagon;
    /* Declarando una pila auxiliar */
    int auxiliar[TAM];
    int auxiliarCima = -1;
    /* Buscando el vagon a eliminar */
    for (int i = cima; i >= 0; i--) {
      if (tren[i] != vagon) {
        /* Colocando los vagones en la pila auxiliar */
        auxiliarCima++;
        auxiliar[auxiliarCima] = tren[i];
        tren[i] = 0;
        cima--;
      } else {
        /* Eliminando el vagon */
        tren[i] = 0;
        cima--;
        break;
      }
    }
    /* Reemplazando los vagones de la pila original */
    for (int i = auxiliarCima; i >= 0; i--) {
      cima++;
      tren[cima] = auxiliar[i];
    }
    imprimirTren(tren, cima);
  }
}

void mostrarMenu() {
  cout << "1. Ingresar vagones" << endl;
  cout << "2. Eliminar vagones" << endl;
  cout << "3. Salir" << endl;
}