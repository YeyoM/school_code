//Programa de Hashing
#include <iostream>

using namespace std;

struct Alumno{
	char nombre[50];
	int calificacion;
	int estado = 0; //Para saber si el campo esta ocupado
	int clave;
};

//Funciones
int insertar(Alumno* A, Alumno* B,int,int);
int buscarHash(Alumno* A, int, int);

//Funcion main
int main(){
	int op=0,n,clave,x,i;
	do{
		cout<<"Dame la cantidad de alumnos"<<endl;
		cin>>n;
	}while(n<0);
	
	Alumno* A = new Alumno[n];
	Alumno* B = new Alumno[n];
	system("cls"); //Limpiar pantalla
	
	//Menu de opciones
	do{
		system("cls");
		cout<<"--Menu--"<<endl<<endl;
		cout<<"1)Insertar"<<endl;
		cout<<"2)Buscar"<<endl;
		cout<<"3)Salir"<<endl;
		cout<<"Elige una opcion: ";
		cin>>op;
		system("cls");
		switch(op){
			//Ingresar
			case 1:
				for(i=0;i<n;i++){
					cout<<"--Agregar Datos--"<<endl<<endl;
					fflush(stdin);
					cout<<"Dame el nombre: ";
					cin.getline(A[i].nombre, 50);
					cout<<"Dame la calificacion: ";
					cin>>A[i].calificacion;
					A[i].clave=insertar(A,B,i,n);
					cout<<"La clave sera: "<<A[i].clave<<endl;
				}
				system("pause");
				break;
			//Buscar
			case 2:
				cout<<"Introduce la clave que quieres buscar: ";
				fflush(stdin);
				cin>>clave;
				x=buscarHash(A,n,clave);
				if(x== -1){
					cout<<"Numero no econtrado"<<endl;
				}
				else{
					cout<<"Numero encontrado:"<<endl;
					cout<<"Nombre: "<<B[x].nombre<<endl;
					cout<<"Calificacion: "<<B[x].calificacion<<endl;
				}
				system("pause");
				break;
			//Salir
			case 3:
				cout<<"Saliendo..."<<endl;
				system("pause");
				break;
			//Opcion no valida
			default:
				cout<<"Opcion no valida"<<endl;
				system("pause");
				break;
		}
		
	}while(op!=3);
}

//Funcion insertar
int insertar(Alumno *A, Alumno *B, int i, int n){
	int j = (A[i].calificacion+1) % n;
	do{
		if(A[j].estado == 0){
			B[j]=A[j];
			A[j].estado = 1;
		}
		else{
			j++;
		}
	}while(j>n);
	return j;
}

int buscarHash(Alumno *A, int n, int clave){
	int j=0;
	while(j<n){
		if(A[j].clave == clave){
			return j;
		}
		else{
			j++;
		}
	}
	return -1;
}