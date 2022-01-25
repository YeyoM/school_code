// @autor: Diego Emilio Moreno Sanchez, Hector Alejandro Perez, Angel David Ortiz; ID: 264776; Fecha: 16 de noviembre de 2021
// Este programa genera un arreglo/vector aleatorio con numeros de 1 a 10, de tamaño que el usuario desee
// seguido de eso, se muestra al usuario el vector generado y el usuario puede cambiar cualquier elemento del arreglo/vector 
// dada la posicion del numero a cambiar y el nuevo valor

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h>

void remplazo(int vector[],int);

main(){
    srand(time(NULL));
    int vector[99];	
    int i,n;
    int rep;
    printf("Escribe el grado del vector\n");
    scanf("%d",&n);
    for ( i = 0; i < n; i++ ) {
        vector[i] = rand()%10+1;
    }
    do{
        printf("\nEl vector es: \n");
        for(i=0; i < n ; i++){
            printf("%d-", vector[i]);
        }
        printf("\nQuieres remplazar un valor? \n1.-si \n2.-no\n");  
        scanf("%d",&rep);
        while(rep != 1 && rep != 2){
        	printf("\nEsa no es un a opcion, escribe \n1.-si \n2.-no\n");
        	scanf("%d",&rep);
        }
        if(rep==1){
            remplazo(vector,n);
            printf("\nEl nuevo vector despues de pasar por la funcion es:\n");
            for(i=0; i < n ; i++){
                printf("%d-", vector[i]);
            }
            system("pause");
            system("cls");
        }
    } while(rep != 2);
    printf("\nGracias por usar el programa");
}

void remplazo(int vector[],int r){
	int pos,i;
	printf("\nEscriba la pocicion que quiere remplazar\t");
	scanf("%d",&pos);
	while(pos>r){
		printf("\nEsta posicion no existe, ngresa un numero entre el 1 y el %d\n",r);
		scanf("%d",&pos);
	}
	pos=pos-1;
	printf("\nEscribe por que numero lo quieres remplazar?\t");
	scanf("%d",&vector[pos]);
	printf("\nEl nuevo vector es:\n");
    for(i=0; i < r ; i++){
        printf("%d-", vector[i]);
    }
}
