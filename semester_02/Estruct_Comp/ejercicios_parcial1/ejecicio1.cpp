/*Definir un arreglo de cualquier tipo de dato y buscar un elemento dentro de un arreglo que nosotros le pedimos por teclado. 
Indicar las posiciones donde se encuentra. Si hay más de uno, indicar igualmente la posición.*/
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

//prototipo de la funcion a usar
void busqueda(int vector[],int n);



int main(){
	//declaracion de variables
	int n;
	int vector[100];
	system("title Primer ejercisio");
	//asignacion del tamaño del vector
	cout<<"Digite la cantidad de numeros que guardara: ";cin>>n;
	
	//rellenado del vector
	for(int i=0;i<n;i++){
		cout<<"Digite el numero para la posicion ["<<i+1<<"]: ";cin>>vector[i];
	}
	
	//llamado a la funcion que hara la localizacion del numero
	busqueda(vector,n);
	system("pause");
	return 0;
}

void busqueda(int vector[],int n){
	//declaracion de variables a necesitar
	int reg,cont=1;
	//asignacion del numero a buscar 
	cout<<"Digita el numero que quieres encontrar en el arreglo: ";cin>>reg;
	//busqueda e impresion del numero encontrado o si el numero no ha sido encontrado
	for(int i=0;i<n;i++){
		if(vector[i]==reg){
			cout<<"Se ha encontrado el numero "<<reg<<" en la posicion del arreglo "<<cont<<endl;
		}
		cont++;
			if(cont==(n)){
			cout<<"No se ha encontrado el numero "<<reg<<" en este arreglo\n";
		}
		}
	}


