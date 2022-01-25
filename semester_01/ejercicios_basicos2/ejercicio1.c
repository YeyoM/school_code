#include <stdio.h>

int suma = 0;

int main(){
    //////////////////////////////// Bucle For
    for(int i=0; i <= 100; i++){
        if(i % 2 == 0){
            suma += i;
        }
    }
    printf("%i \n", suma);
    suma = 0;

    //////////////////////////////// Bucle do while
    int j = 0;
    do{
        if (j % 2 == 0){
            suma += j;
        }
        j++;
    } while (j < 101);
    printf("%i \n", suma);
    suma = 0;

    //////////////////////////////// Bucle while 
    int k = 0;
    while (k < 101){
        if (k % 2 == 0){
            suma += k;
        }
        k++;
    }
    printf("%i \n", suma);

    return 0;
}
