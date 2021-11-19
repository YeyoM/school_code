#include <stdio.h>

int sumaPares = 0,
    sumaImpares = 0;

int main(){
    //////////////////////////////// Bucle For
    for(int i=100; i <= 400; i++){
        if( i % 2 == 0 ){
            sumaPares += i;
        } if ( i % 2 != 0 ) {
            sumaImpares += i;
        }
        
    }
    printf("Suma de los pares: %i \n", sumaPares);
    printf("Suma de los impares: %i \n", sumaImpares);
    sumaPares = 0;
    sumaImpares = 0;

    //////////////////////////////// Bucle do while
    int j = 100;
    do{
        if( j % 2 == 0 ){
            sumaPares += j;
        } if ( j % 2 != 0 ) {
            sumaImpares += j;
        }
        j++;
    } while (j < 401);
    printf("Suma de los pares: %i \n", sumaPares);
    printf("Suma de los impares: %i \n", sumaImpares);
    sumaPares = 0;
    sumaImpares = 0;

    //////////////////////////////// Bucle while 
    int k = 100;
    while (k < 401){
        if( k % 2 == 0 ){
            sumaPares += k;
        } if ( k % 2 != 0 ) {
            sumaImpares += k;
        }
        k++;
    }
    printf("Suma de los pares: %i \n", sumaPares);
    printf("Suma de los impares: %i \n", sumaImpares);

    return 0;
}
