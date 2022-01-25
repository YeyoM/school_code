#include <stdio.h>

int num = 0;

int main() {
    do {
        printf("Ingrese un numero entre 1 y 10: ");
        scanf("%d", &num);
        switch (num){
            case 1:
                printf("i");
                break;
            case 2:
                printf("ii");
                break;
            case 3:
                printf("iii");
                break;
            case 4:
                printf("iv");
                break;
            case 5:
                printf("v");
                break;
            case 6:
                printf("vi");
                break;
            case 7:
                printf("vii");
                break;
            case 8:
                printf("viii");
                break;
            case 9:
                printf("ix");
                break;
            case 10:
                printf("x");
                break;
            default:
                printf("Ingrese un numero valido");
                break;
        }
    } while (num < 0 || num > 10);
    return 0;
}