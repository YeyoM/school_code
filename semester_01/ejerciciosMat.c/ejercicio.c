// @autor Diego Emilio Moreno Sanchez, 25/10/21, ID: 264776
//----------------------------------------------------------------
#include <stdio.h>
#include <stdbool.h>

bool salir = false;
int opcion = 0;

int main() {
    printf(".:Menu:.\n");
    printf("1.-Matriz y suma total\n");
    printf("2.-Matriz y suma por filas\n");
    printf("3.-Matriz y suma por columna\n");
    printf("4.-Matriz por un escalar\n");
    printf("5.-Suma de dos matrices\n");
    printf("6.-Ordenar matriz de menor a mayor\n");
    printf("7.-Ordenar matriz de mayor a menor\n");
    printf("8.-Crear matriz identidad\n");
    printf("9.-Salir\n");
    do {
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);
        printf("\n");
        if      ( opcion == 1 ) {
            int mat[4][4];  // inicializamos la matriz
            int i = 0,      // inicializamos las variables de iteracion
                j = 0;
            int suma = 0;   // variable para guardar la suma
            for ( i = 0; i <= 3; i++ ){
                    for ( j = 0; j <= 3; j++ ) {
                        printf("\nIngrese el valor para [%d][%d]: ", i, j);
                        scanf("%d", &mat[i][j]);
                    }
                }
                printf("\n");
                // mostramos la matriz
                printf("La matriz ingresada es: \n");
                for ( i = 0; i <= 3; i++ ){
                    for ( j = 0; j <= 3; j++ ) {
                        printf(" %d ", mat[i][j]);
                        suma += mat[i][j];
                    }
                    printf("\n");
                }
                // mostramos la suma
                printf("\nLa suma de todos los elementos es: %d", suma);
        }
        else if ( opcion == 2 ) {
            int mat[4][4];  // inicializamos la matriz
            int sumas[4];   // inicializamos el arreglo de suamas
            int i = 0,      // inicializamos las variables de iteracion
                j = 0,
                acum = 0;   // inicializamos el acumulador
                // guardamos la matriz
            for ( i = 0; i <= 3; i++ ){
                for ( j = 0; j <= 3; j++ ) {
                    printf("\nIngrese el valor para [%d][%d]: ", i, j);
                    scanf("%d", &mat[i][j]);
                    acum += mat[i][j];  // vamos acumulando por fila
                }
                sumas[i] = acum;        // guardamos en el arreglo
                acum = 0;               // devolvemos a 0, e iniciamos de nuevo
            } 
            printf("\n");
            // mostramos la matriz
            printf("La matriz ingresada es: \n");
            for ( i = 0; i <= 3; i++ ){
                for ( j = 0; j <= 3; j++ ) {
                    printf(" %d ", mat[i][j]);
                }
                printf("\tsuma = %d", sumas[i]);    // mostramos la suma de c/ fila
                printf("\n");
            }
            printf("\n");
        }
        else if ( opcion == 3 ) {
        int mat[4][4];  // inicializamos la matriz
        int sumas[4];   // inicializamos el arreglo de suamas
        int i = 0,      // inicializamos las variables de iteracion
            j = 0,
            acum = 0;   // inicializamos el acumulador
        // guardamos la matriz
        for ( i = 0; i <= 3; i++ ){
            for ( j = 0; j <= 3; j++ ) {
                printf("\nIngrese el valor para [%d][%d]: ", i, j);
                scanf("%d", &mat[i][j]);
            }
        }
        // recorremos la matriz por columnas para ir obteniendo las sumas
        for ( i = 0; i <= 3; i++ ){
            for ( j = 0; j <= 3; j++ ) {
                acum += mat[j][i];
            }
            sumas[i] = acum;
            acum = 0;
        }
        printf("\n");
        // mostramos la matriz original
        printf("La matriz ingresada es: \n");
        for ( i = 0; i <= 3; i++ ){
            for ( j = 0; j <= 3; j++ ) {
                printf(" %d ", mat[i][j]);
            }
            printf("\n");
        }
        // mostramos las sumas por columnas
        for ( i = 0; i <= 3; i++ ){
            printf("\nLa suma de la columna %d = %d", i, sumas[i]);
        }
        printf("\n");
        }
        else if ( opcion == 4 ) {
            int n,      // n definira el tamaño de la matriz 
                esc,    // producto escalar
                i = 0,  // variables de iteracion
                j = 0;
            // generamos las matrices
            printf("Ingrese el num de filas y columnas de la matriz: ");
            scanf("%d", &n);
            int mat[n][n];      // matriz original
            int mat2[n][n];     // matriz nueva
            printf("\n");
            // guardamos el producto escalar
            printf("Ingrese el producto escalar: ");
            scanf("%d", &esc);
            printf("\n");
            // guardamos la matriz n*n
            for ( i = 0; i < n; i++ ) {
                for ( j = 0; j < n; j++ ) {
                    printf("\nIngrese el valor para [%d][%d]: ", i, j);
                    // vamos generando la nueva matriz
                    scanf("%d", &mat[i][j]);        
                    mat2[i][j] = mat[i][j] * esc;
                }
            }
            printf("\n");
            // mostramos las matrices
            for ( i = 0; i < n; i++ ) {
                for ( j = 0; j < n; j++ ) {
                    printf(" %d ", mat[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            for ( i = 0; i < n; i++ ) {
                for ( j = 0; j < n; j++ ) {
                    printf(" %d ", mat2[i][j]);
                }
                printf("\n");
            }
        }
        else if ( opcion == 5 ) {
            int n,      // n definira el tamaño de la matriz 
                j, 
                i;      // variables de iteracion
            // generamos las matrices
            printf("Ingrese el num de filas y columnas de la matriz: ");
            scanf("%d", &n);
            int mat1[n][n]; 
            int mat2[n][n];
            int mat3[n][n];     // aqui se guardara el resultado
            // guardamos la primera matriz
            printf("\nPrimera matriz: ");
            for ( i = 0; i < n; i++ ) {
                for ( j = 0; j < n; j++ ) {
                    printf("\nIngrese el valor para [%d][%d]: ", i, j);
                    scanf("%d", &mat1[i][j]);
                }
            }
            // guardamos la segunda matriz
            printf("\nSegunda matriz: ");
            for ( i = 0; i < n; i++ ) {
                for ( j = 0; j < n; j++ ) {
                    printf("\nIngrese el valor para [%d][%d]: ", i, j);
                    scanf("%d", &mat2[i][j]);
                    // sumamos las matrices
                    mat3[i][j] = mat1[i][j] + mat2[i][j];
                }
            }
            // mostramos la matriz resultante
            printf("\nMatriz resultante: ");
            printf("\n");
            for ( i = 0; i < n; i++ ) {
                for ( j = 0; j < n; j++ ) {
                    printf(" %d ", mat3[i][j]);
                }
                printf("\n");
            }
        }
        else if ( opcion == 6 ) {
            int n,      // n definira el tamaño de la matriz 
                j,      // variables de iteracion
                i,
                k = 0,
                res,    // tamaño de n*n
                temp;   // variable temporal para acomodar los numeros
            // generamos las matrices
            printf("Ingrese el num de filas y columnas de la matriz: ");
            scanf("%d", &n);
            int mat1[n][n];
            int mat2[n][n];
            res = n * n;
            // generamos un arreglo para guardar la matriz y asi acomodar
            int arr[res];
            // guardamos la mirmera matriz
            printf("\nPrimera matriz: ");
            for ( i = 0; i < n; i++ ) {
                for ( j = 0; j < n; j++ ) {
                    printf("\nIngrese el valor para [%d][%d]: ", i, j);
                    scanf("%d", &mat1[i][j]);
                }
            }
            // convertimos a arreglo
            for ( i = 0; i < n; i++ ) {
                for ( j = 0; j < n; j++ ) {
                    arr[k] = mat1[i][j];
                    k++;
                }
            }
            // acomodamos
            for (int i = 0; i <= res; i++){
                for (int j = i + 1; j <= res; j++) {  
                    if(arr[i] > arr[j]) {   
                        temp = arr[i];  
                        arr[i] = arr[j];    
                        arr[j] = temp;    
                    } 
                }
            }
            k = 0;
            // volvemos a convertir a matriz
            for ( i = 0; i < n; i++ ) {
                for ( j = 0; j < n; j++ ) {
                    mat1[i][j] = arr[k];
                    k++;
                }
            }
            // mostramos la matriz resultante
            printf("\nLa matriz resultante es: \n");
            for ( i = 0; i < n; i++ ) {
                for ( j = 0; j < n; j++ ) {
                    printf(" %d ", mat1[i][j]);
                }
                printf("\n");
            }
        }
        else if ( opcion == 7 ) {
            int n,      // n definira el tamaño de la matriz 
                j,      // variables de iteracion
                i,
                k = 0,
                res,    // tamaño de n*n
                temp;   // variable temporal para acomodar los numeros
            // generamos las matrices
            printf("Ingrese el num de filas y columnas de la matriz: ");
            scanf("%d", &n);
            int mat1[n][n];
            int mat2[n][n];
            res = n * n;
            // generamos un arreglo para guardar la matriz y asi acomodar
            int arr[res];
            // guardamos la mirmera matriz
            printf("\nPrimera matriz: ");
            for ( i = 0; i < n; i++ ) {
                for ( j = 0; j < n; j++ ) {
                    printf("\nIngrese el valor para [%d][%d]: ", i, j);
                    scanf("%d", &mat1[i][j]);
                }
            }
            // convertimos a arreglo
            for ( i = 0; i < n; i++ ) {
                for ( j = 0; j < n; j++ ) {
                    arr[k] = mat1[i][j];
                    k++;
                }
            }
            // acomodamos
            for (int i = 0; i < res; i++){
                for (int j = i + 1; j < res; j++) {  
                    if(arr[i] < arr[j]) {   
                        temp = arr[i];  
                        arr[i] = arr[j];    
                        arr[j] = temp;    
                    } 
                }
            }
            k = 0;
            // volvemos a convertir a matriz
            for ( i = 0; i < n; i++ ) {
                for ( j = 0; j < n; j++ ) {
                    mat1[i][j] = arr[k];
                    k++;
                }
            }
            // mostramos la matriz resultante
            printf("\nLa matriz resultante es: \n");
            for ( i = 0; i < n; i++ ) {
                for ( j = 0; j < n; j++ ) {
                    printf(" %d ", mat1[i][j]);
                }
                printf("\n");
            }
        }
        else if ( opcion == 8 ) {
            int n,      // n definira el tamaño de la matriz 
                j,      // variables de iteracion
                i;
            // generamos la matriz
            printf("Ingrese el num de filas y columnas de la matriz: ");
            scanf("%d", &n);
            int mat1[n][n];
            for ( i = 0; i < n; i++ ) {
                for ( j = 0; j < n; j++ ) {
                    if (i == j) {
                        mat1[i][j] = 1;
                    } else {
                        mat1[i][j] = 0;
                    }
                }
            }
            // mostramos la matriz
            printf("\nLa matriz resultante: \n");
            for ( i = 0; i < n; i++ ) {
                for ( j = 0; j < n; j++ ) {
                    printf(" %d ", mat1[i][j]);
                }
                printf("\n");
            }
        }
        else if ( opcion == 9 ) {
            printf("\nGracias por usar este programa");
            salir = true;
        } else printf("\nOpcion incorrecta\n");
    } while (salir == false);
    return 0;
}