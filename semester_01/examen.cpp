#include <stdio.h>

#define FILAS 3

#define COLUMNAS 4

 main()

{

  int a, b = 0, c = 999;

  int arreglo[FILAS][COLUMNAS]= {1,2,3,4,5,6,7,8,9,0};

 

  for(a=0; a < FILAS; a++)

     for(b=0; b < COLUMNAS; b++)

            if ( arreglo[a][b] < c )

                        c = arreglo[a][b];

  printf("%d", c);       

}