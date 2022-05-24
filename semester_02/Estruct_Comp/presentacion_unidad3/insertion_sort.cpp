#include <iostream>
#include <conio.h>

using namespace std;

int main(){
	int numeros[] = {3,4,2,1,5}; //creacion de un arreglo con su asignacion de valores 
	int i,pos,aux;
	
	for(i=0;i<5;i++){ //inicio del for que revisara numero por numero
		pos = i;  // asignamos a pos el valor itirenante de i
		aux = numeros[i];// asignamos a aux el valor del primer numero del arreglo
		
		while((pos>0) && (numeros[pos-1] > aux)){ //mientras que pos sea mayor a 0 y el numero del arreglo en la posicion 0 sea mayor al de la posicion i 
			numeros[pos] = numeros[pos-1]; //intercambiamos de lugar
			pos--; //baja el valor de pos hasta que se deje de cumplir el while
		}
		numeros[pos] = aux; // se remplaza por el valor que estaba en la derecha 
	}
	
	cout<<"Orden Ascendente: ";  //se imprime de manera ascendente
	for(i = 0; i < 5; i++){
		cout << numeros[i] << " ";
	}
	
	cout<<"\nOrden Descendente: "; //se imprime de manera descendente 
	for(i = 4; i >= 0; i--){
		cout << numeros[i] << " ";
	}
	
	getch();
	return 0;
}
