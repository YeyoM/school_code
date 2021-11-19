// @autor: Diego Emilio Moreno Sanchez, Hector Alejandro Perez, Angel David Ortiz; ID: 264776; Fecha: 16 de noviembre de 2021
// Este programa genera una matriz aleatorio con numeros de 1 a 10, de tamaño que el usuario desee nxn
// seguido de eso, se muestra al usuario la matriz generada y el usuario puede cambiar cualquier elemento de la matriz
// dada la posicion del numero a cambiar en filas y columnas, y el nuevo valor

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h>

void remplazo(int matriz[][99],int);

main(){
    srand(time(NULL));
    int matriz[99][99];	
    int i, j, n, f, c;
    int rep;
    printf("Escribe el grado de la matriz cuadrada\n");
    scanf("%d",&n);
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++) {
            matriz[i][j] = rand()%10+1;
        }
    }
    do{
        printf("\nLa matriz es: \n");
        for(i = 0; i < n ; i++){
            for ( j = 0; j < n; j++ ) {
                printf("%d  ", matriz[i][j]);
            }
            printf("\n");
        }
        printf("\nQuieres remplazar un valor? \n1.-si \n2.-no\n");  
        scanf("%d",&rep);
        while(rep != 1 && rep != 2){
        	printf("\nEsa no es un a opcion, escribe \n1.-si \n2.-no\n");
        	scanf("%d",&rep);
        }
        if(rep==1){
            remplazo(matriz, n);
            printf("\nLa nueva matriz despues de pasar por la funcion es:\n");
            for(i=0; i < n ; i++){
                for ( j = 0; j < n; j++ ) {
                    printf("%d  ", matriz[i][j]);
                }
                printf("\n");
            }
            system("pause");
            system("cls");
        }
    } while(rep != 2);
    printf("\nGracias por usar el programa!");
}

void remplazo(int matriz[][99], int r){
	int pos, i, j, f, c;
	printf("\nEscriba la pocicion que desees remplazar (fila)\t");
	scanf("%d", &f);
    printf("\nEscriba la pocicion que desees remplazar (columna)\t");
	scanf("%d", &c);
	while(f > r || c > r){
		printf("\nEsta posicion no existe, ngresa un numero entre el 1 y el %d\n",r);
		printf("\nEscriba la pocicion que desees remplazar (fila)\t");
	    scanf("%d", &f);
        printf("\nEscriba la pocicion que desees remplazar (columna)\t");
	    scanf("%d", &c);
	}
	f = f - 1;
    c = c - 1;
	printf("\nEscribe por que numero lo quieres remplazar?\t");
	scanf("%d", &matriz[f][c]);
	printf("\nEl nuevo vector es:\n");
    for(i=0; i < r ; i++){
        for ( j = 0; j < r; j++ ) {
            printf("%d  ", matriz[i][j]);
        }
        printf("\n");
    }
}
