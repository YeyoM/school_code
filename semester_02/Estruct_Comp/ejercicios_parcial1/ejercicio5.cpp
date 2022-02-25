/*Sea M una matriz de enteros de 5 filas X 5 columnas.
Realice un programa que permita:
a) Ingresar cada uno de los valores de la matriz.
b) Mostrar, para cada fila, la suma de sus valores de esa fila, y el menor valor almacenado
c) Mostrar, para cada columna, el promedio de sus valores y el mayor valor.
d) El mayor valor almacenado en toda la Matriz, indicando en que fila y columna se encuentra*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

void rellenado(int matriz[][100],int fil,int col,int gemela[][100]);
void menu(int gemela[][100],int fil,int col);
void sumafila(int gemela[][100],int fil,int col);
void sumacol(int gemela[][100],int fil,int col);
void nummayor(int gemela[][100],int fil,int col);
int main(){
	int matriz[100][100],fil,col,gemela[100][100];
	cout<<"De cuantas filas sera su matriz: ";cin>>fil;
	cout<<"\nDe cuantas columnas sera su matriz: ";cin>>col;
	system("cls");
	rellenado(matriz,fil,col,gemela);
	system("cls");
	menu(gemela,fil,col);
	system("pause");
	return 0;}
void rellenado(int matriz[][100],int fil, int col,int gemela[][100]){
	for(int i=0;i<fil;i++){
		for(int j=0;j<col;j++){
			cout<<"Digita el valor para la posicion["<<i<<"]["<<j<<"]: ";cin>>matriz[i][j];
			gemela[i][j]=matriz[i][j];}}}
void menu(int gemela[][100],int fil,int col){
int opc=1;
	while(opc>=1 && opc<=3){
	system("pause");
	system("cls");
	cout<<"\t\tMENU\n\n";int opc;
	cout<<"Su matriz actual\n";
	for(int i=0;i<fil;i++){
		for(int j=0;j<col;j++){
			cout<<gemela[i][j]<<"  ";}
		cout<<endl;}
	cout<<endl<<endl;
	cout<<"1.Mostrar por fila su sumas y el menor valor en ellas \n2.Mostrar por columna su sumas y el mayor de estas\n3.Mostrar el mayor numero en toda la matriz\n4.Salir\nRespuesta: ";cin>>opc;
	system("cls");
	switch(opc){
		case 1:
			sumafila(gemela,fil,col);break;
			case 2:
			sumacol(gemela,fil,col);
			break;
				case 3:
				nummayor(gemela,fil,col);break;
					case 4:break;
						cout<<"Saliendo...\n";break;
						default:
							cout<<"Esta opcion no existe..Saliendo\n";break;}}}
void sumafila(int gemela[][100],int fil,int col){
	int n,aux=0,aux2,men=0;
	cout<<"Que fila de la matriz quiere que sume y muestre su menor numero : ";cin>>n;
	for(int i=0;i<col;i++){
		aux+=gemela[n][i];
	}
	for(int i=0;i<col;i++){
		cout<<gemela[n][i]<<"  ";}
	for(int i=0;i<col;i++){
		aux2=gemela[n][i];
		if(aux2<men){
			men=aux2;}}
	cout<<"= "<<aux<<" su numero menor es: "<<men<<endl;}
void sumacol(int gemela[][100],int fil,int col){
	int n,aux=0,aux2,aux3,may;
	cout<<"Que fila de la matriz quiere que sume y muestre su menor numero : ";cin>>n;
	for(int i=0;i<fil;i++){
		aux+=gemela[i][n];
	}
		for(int i=0;i<fil;i++){
		cout<<gemela[i][n]<<"  ";}
		
	for(int i=0;i<fil;i++){
		aux2=gemela[i][n];
		if(aux2>may){
			may=aux2;}}
		aux/=col;
	cout<<"   promedio = "<<aux<<" su numero mayor  es: "<<may<<endl;
}
void nummayor(int gemela[][100],int fil,int col){
	int may=0,aux=0,contf=0,contc=0;
	for(int i=0;i<fil;i++){
		for (int j=0;j<col;j++){
			aux=gemela[i][j];
			if(aux>may){
				may=aux;}}}
for(int i=0;i<fil;i++){
		for (int j=0;j<col;j++){
		if(may==gemela[i][j]){
				cout<<"El numero mayor "<<may<<" fue encontrado en la posicion ["<<contf<<"]["<<contc<<"]\n";
			}else{
				contf++;
			}}
			contf=0;
			contc++;}}
