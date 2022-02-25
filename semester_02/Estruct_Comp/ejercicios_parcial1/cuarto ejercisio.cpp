/*Escribir una función que intercambie la fila i-ésima por la j-ésima de un array de dos dimensiones, m x n.*/
#include<iostream>
#include<stdio.h>
using namespace std;
void cambio(int vect[][100],int,int);
int main(){
	int fil,col;
	int vect[100][100];
	cout<<"Digita de cuantas filas va a ser tu matriz: ";cin>>fil;
	cout<<"\nDigita de cuentas columnas sera tu matriz: ";cin>>col;
	system("cls");
	for(int i=0;i<fil;i++){
	for(int j=0;j<col;j++){
	cout<<"Digita el valor para la posiciones ["<<i+1<<"]["<<j+1<<"]: ";cin>>vect[i][j];		
	}}
	system("cls");
	cambio(vect,fil,col);
	system("cls");
return 0;	
}
void cambio(int vect[][100],int fil, int col){
	int n,n1,aux;
	cout<<"\t\tEsta es tu matriz actual\n\n";
	for(int i=0;i<fil;i++){
		for(int j=0;j<col;j++){
			cout<<vect[i][j]<<"   ";
		
		}
		cout<<endl;
	}
	
	
	cout<<"Digita que fila del array deseas intercambiar: ";cin>>n;
	cout<<"Por cual fila deseas intercambir la fila "<<n<<" : ";cin>>n1;
		for(int j=0;j<col;j++){
			aux=vect[n][j];
			vect[n][j]=vect[n1][j];
			vect[n1][j]=aux;
		}
	cout<<"\t\tEsta es tu nueva matriz\n\n";
	for(int i=0;i<fil;i++){
		for(int j=0;j<col;j++){
			cout<<"\t"<<vect[i][j]<<"  ";
		
		}
		cout<<endl;
	}
	system("pause");
	
}
