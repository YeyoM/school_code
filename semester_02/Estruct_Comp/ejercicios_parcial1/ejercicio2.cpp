/*Leer una frase y determinar qu� caracteres se encuentran repetidos, y cu�ntas eces aparece repetido cvada car�cter. 
Utilizar un vector con los caracteres que van apareciendo y otro correspondiente a la misma posici�n con el n�mero de repeticiones*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;



int main(){
char frase[100],caracter;
int cont,n;
cout<<"Digita una frase: ";cin.getline(frase,100,'\n');
n = strlen(frase);

for(int i=0;i<n;i++){
	caracter=frase[i];
	for(int j=0;j<n;j++){
		if(caracter==frase[j]){
			cont++;
		}}
if(cont>0){
	cout<<"El caracter ["<<caracter<<"] ha sido encontrado "<<cont<<" veces\n";
}
cont=0;
}
	return 0;
}

