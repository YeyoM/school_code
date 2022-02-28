/*Escribir un programa en el que se genere aleatoriamente un array de 20 números enteros. 
El array ha de quedar de tal forma que la suma de los 10 primeros elementos sea mayor que la suma de los 10 últimos elementos.
 Mostrar el array original y el array con la distribución indicada*/
 #include<iostream>
 #include<stdio.h>
 #include<stdlib.h>
 #include<time.h>
 using namespace std;
 
 int main(){
 	float vect[100];
 	int n;
 	srand(time(NULL));
 	cout<<"De cuantos espacios sera tu vector?: ";cin>>n;
 	system("cls");
 for(int i=0;i<n;i++){
 	vect[i]=rand() % 100;
}
int cont=0;
 cout<<"El vector generado es: "<<endl;
 for(int j=0;j<n;j++){
cout<<vect[j]<<"  ";}
 int aux;
 for(int i=1;i<n;i++){
 	for(int j=0;j<n;j++){
 		if(vect[j]< vect[j+1]){
 			aux=vect[j];
 			vect[j]=vect[j+1];
 			vect[j+1]=aux;}}}
 

 cout<<endl<<endl;
 cout<<"El nuevo vector es: "<<endl;
 for(int f=0;f<n;f++){
cout<<vect[f]<<"  ";}
if(cont == 10){
	cout<<endl;
}
 cont++;
 }
