// @autor: Diego Emilio Moreno Sanchez, 22/10/21
// Examen Parcial 2 
// ID 264776
// Analisis
// Objetivo: Dados 8 numeros, mostrar los cuadrados de dichos numeros
//   		 y cual es el menor de esos 8 numeros junto con su posicion
// Datos de entrada: 8 numeros
// Datos de salida: los cuadrados de esos 8 numeros y el menor con su posicion
//////////////////////////////////////////////////////////////////////////////
#include <stdio.h>

// inicializamos las variables
int nums[8],
	nums2[8],
	men,
	pos,
	i;

int main() {
	for (i = 0; i <= 7; i++) { // guradamos el primer arreglo
		printf("Ingrese el num %d: ", i + 1);
		scanf("%d", &nums[i]);
		printf("\n");
	}
	men = nums[0];
	printf("Los numeros ingresados fueron: \n");
	for (i = 0; i <= 7; i++) { // mostramos el primer arreglo
		printf(" %d ", nums[i]);
		nums2[i] = nums[i] * nums[i]; // generamos el segundo arreglo
		if ( nums[i] < men ) { // buscamos el menor y su posicion
			men = nums[i];
			pos = i + 1;
		}
	}
	printf("\n");
	printf("Los cuadrados de los numeros son: \n");
	for (i = 0; i <= 7; i++) { // mostramos el segundo arreglo
		printf(" %d ", nums2[i]);
	}
	printf("\n");
	// mostramos el menor y su posicion
	printf("El numero menor es %d, en la posicion %d", men, pos);
	return 0;
}
