#include <iostream>

int main() {
    char infijo[100];
    char prefijo[100];
    char postfijo[100];
    char pila[100];
    int i = 0, j = 0, k = 0;
    printf("Ingrese una expresion infija: ");
    scanf("%s", infijo);
    while (infijo[i] != '\0') {
        if (infijo[i] == '(') {
            pila[j] = infijo[i];
            j++;
        } else if (infijo[i] == ')') {
            while (pila[j - 1] != '(') {
                postfijo[k] = pila[j - 1];
                k++;
                j--;
            }
            j--;
        } else if (infijo[i] == '+' || infijo[i] == '-' || infijo[i] == '*' || infijo[i] == '/') {
            while (pila[j - 1] != '(' && pila[j - 1] != '+' && pila[j - 1] != '-' && pila[j - 1] != '*' && pila[j - 1] != '/') {
                postfijo[k] = pila[j - 1];
                k++;
                j--;
            }
            pila[j] = infijo[i];
            j++;
        } else {
            postfijo[k] = infijo[i];
            k++;
        }
        i++;
    }
    while (j > 0) {
        postfijo[k] = pila[j - 1];
        k++;
        j--;
    }
    printf("\nExpresion infija: %s\n", infijo);
    printf("Expresion prefija: ");
    for (i = 0; i < k; i++) {
        printf("%c", postfijo[i]);
    }
    printf("\n");

  return 0;
}