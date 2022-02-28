/*Elaborar un programa por medio de recorrido de la cadena con apuntadores para sustituir todos los espacios en blanco de una frase por un asterisco.*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;


int main(){
char cadena[100],*cadena4;
char *cadena2,cadena3[]={"*"},cadena5[]={" "};
cadena4=&cadena5[0];
cadena2=&cadena3[0];



	cout<<"Digite una cadena : ";
	cin.getline(cadena,100,'\n');
	int n=strlen(cadena);
	for(int i=0;i<n;i++){
		if(cadena[i] == *cadena4){
			cadena[i] =*cadena2;
		}
	}
	cout<<"La nueva cadena es: "<<cadena<<endl ;
	
	
	
	
	
	system("pause");
	return 0;
}
