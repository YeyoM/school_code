//objetivo: estructura union
//febrero 2022
//elv

//declaracion de lbrerias
#include <iostream>

using namespace std;

struct alumno
{
    int   id;
    string nombre;
    int tipo;//alumno que es 1)Deportista 2) Becario
};

union datos_complementarios {
	char  deporte[50];
	int   porcentaje_beca;
	
};

int main()
{
//declaracion de variables
 struct alumno alumnos[2];
 union datos_complementarios datos_comp_alum[2];
 int i;
 //Captura los datos del alumno
 for(i=0;  i<2; i++)
 {
 
  cout<<"\n Datos del alumno";
  fflush(stdin);
  cout<<"\n Dame el id del alumno "<<i+1<<":";
  cin>>alumnos[i].id;
  fflush(stdin);
  cout<<"\n Dame el nombre del alumno "<<i+1<<":";
  getline(cin,alumnos[i].nombre);
  fflush(stdin);
  cout<<"\n tipo del alumno: "<<i+1<< " [1]Deportista [2] Becario :";
  cin>>alumnos[i].tipo;
  fflush(stdin);
  if (alumnos[i].tipo==1)
      {
	  
      
	  cout<<"\n Dame el nombre del deporte "<<"del alumno:"<<i+1<<":"; 
      cin>>datos_comp_alum[i].deporte;
      fflush(stdin);
     }
  else
     {
      
      cout<<"\n Dame el porcentaje de la beca "<<"del alumno:"<<i+1<<":"; 
      cin>>datos_comp_alum[i].porcentaje_beca;
      fflush(stdin);
     }
 }
 
//imprime datos

 for(i=0;  i<2; i++)
 {
  
  cout<<"\n\n----------- Datos del alumno";
  cout<<"\n id del alumno "<<i+1<<":";
  cout<<alumnos[i].id;
  cout<<"\n nombre del alumno "<<i+1<<":";
  cout<<alumnos[i].nombre;
  cout<<"\n tipo del alumno: "<<i+1<< " [1]Deportista [2] Becario"<<alumnos[i].tipo;
  if (alumnos[i].tipo==1)
      {
	  cout<<"\n el nombre del deporte "<<"del alumno:"<<i+1<<" es:"<<datos_comp_alum[i].deporte;
     }
  else
     {
      cout<<"\n el porcentaje de la beca "<<"del alumno:"<<i+1<<" es"<<datos_comp_alum[i].porcentaje_beca;
     }
 }
return 0;
}
