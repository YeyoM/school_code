/*Ejercicio Estructuras: El profesor de la asignatura de Estructura de Datos desea conocer el porcentaje de:
a) Cuáles son los alumnos de sexo Femenino y Masculino de su clase
b) Cuáles son los alumnos aprobados y reprobados, tomando en cuenta que la calificación mínima para aprobar es 7.0.
La información de los estudiantes (nombre, sexo, calificación) está almacenada en una variable de tipo struct llamada “estudiante”. El programa creará un array de estructuras con 
los datos de los N estudiantes como la que se muestra a continuación:*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

struct alumnos{
	char genero[1];
	int calificacion;
	char nombre[30];
		int n;
}vect[100];

void pedirdatos(){

	cout<<"Cuantos alumnos va a registrar: ";cin>>vect[0].n;
	fflush(stdin);
	for(int i=0;i<vect[0].n;i++){
	fflush(stdin);
	system("cls");
		cout<<"Digite el nombre del alumno #"<<i+1<<" : ";cin.getline(vect[i].nombre,30,'\n');
		cout<<"Digite a que genero pertenece el alumno "<<vect[i].nombre<<" (H o M): ";cin>>vect[i].genero;
		fflush(stdin);
		cout<<"Digite  su calificacion: ";cin>>vect[i].calificacion;
		fflush(stdin);}}




void comprobaciondedatos(){
	int contm=0,conth=0;
	for(int i=0;i< vect[0].n;i++){
		if(strcmp(vect[i].genero,"H")==0 || strcmp(vect[i].genero, "h")==0){
			conth++;}
		else{
			contm++;}}
	
	
	
	int contc=0,contf=0;
	for(int i=0;i<vect[0].n;i++){
		if(vect[i].calificacion>=70){
			contc++;
		}else{
			contf++;
		}}
		int prom=0;
		
		for(int i=0;i<vect[i].n;i++){
			cout<<"De los "<<vect[0].n<<" alumnos inscritos "<<contc<<" estan aprobados, lo que equivale al %"<<((contc*100)/vect[0].n)<<endl;
			cout<<"De los "<<vect[0].n<<" alumnos inscritos "<<contf<<" estan reprobados, lo que equivale al %"<<((contf*100)/vect[0].n)<<endl;
			cout<<"De los "<<vect[0].n<<" alumnos inscritos "<<conth<<" son hombres, lo que equivale al %"<<((conth*100)/vect[0].n)<<endl;
			cout<<"De los "<<vect[0].n<<" alumnos inscritos "<<contm<<" son mujeres, lo que equivale al %"<<((contm*100)/vect[0].n)<<endl;
		}

}
int main(){
pedirdatos();
system("cls");
comprobaciondedatos();	
	
	
	
	
	
	
	
	system("pause");
	return 0;
}
