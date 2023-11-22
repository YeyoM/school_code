/*
Universidad Autonoma de Aguascalientes
Centro de Ciencias de Basicas
Departamento de Ciencias de la Computacion
Materia: Optimización Inteligente
Diego Alberto Aranda Gonzalez
Diego Emilio Moreno Sánchez
Profesor: Dr. en C. Luis Fernando Gutierrez Marfileño
Practica 5: Implementar un programa utilizando la metaheuristica de Sistema de Colonias de Hormigas
resuelva el problema de Job Shop.
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <ctime>

using namespace std;
//Estructura para almacenar los trabajos

struct Trabajo{
  int id;
  vector<int> tiempo; //Peso
};

//Funcion para inicializar las feromonas
void inicializarFeromonas(int numTrabajos, int numMaquinas, vector<vector<double>> &feromonas){
  for(int i = 0; i < numTrabajos; i++){
    vector<double> aux;
    for(int j = 0; j < numMaquinas; j++){
      aux.push_back(1);
    }
    feromonas.push_back(aux);
  }
}

//Funcion para calcular la probabilidad de cada camino
void calcularProbabilidad(int numTrabajos, int numMaquinas, vector<vector<double>> &feromonas, vector<Trabajo> &Trabajo, vector<vector<double>> &probabilidad, double alfa, double beta){
  for(int i = 0; i < numTrabajos; i++){
    vector<double> aux;
    for(int j = 0; j < numMaquinas; j++){
      aux.push_back(pow(feromonas[i][j], alfa) * pow(Trabajo[i].tiempo[j], beta));
    }
    probabilidad.push_back(aux);
  }
}

//Funcion para seleccionar el siguiente trabajo
int seleccionarTrabajo(int numTrabajos, int numMaquinas, vector<vector<double>> &probabilidad){
  double suma = 0;
  vector<double> aux;
  for(int i = 0; i < numTrabajos; i++){
    for(int j = 0; j < numMaquinas; j++){
      suma += probabilidad[i][j];
    }
    aux.push_back(suma);
    suma = 0;
  }
  double aleatorio = rand() % 100;
  for(int i = 0; i < numTrabajos; i++){
    if(aleatorio <= aux[i]){
      return i;
    }
  }
  return 0;
}

//Funcion para calcular el makespan
int calcularMakespan(int numTrabajos, int numMaquinas, vector<vector<double>> &probabilidad, vector<Trabajo> &Trabajo, vector<int> &solucion){
  vector<int> maquinas(numMaquinas, 0);
  vector<int> aux(numMaquinas, 0);
  int trabajo = seleccionarTrabajo(numTrabajos, numMaquinas, probabilidad);
  int maquina = 0;
  int tiempo = 0;
  int makespan = 0;
  for(int i = 0; i < numTrabajos; i++){
    for(int j = 0; j < numMaquinas; j++){
      if(maquinas[j] < maquinas[maquina]){
        maquina = j;
      }
    }
    tiempo = maquinas[maquina];
    maquinas[maquina] += Trabajo[trabajo].tiempo[maquina];
    if(makespan < maquinas[maquina]){
      makespan = maquinas[maquina];
    }
    solucion.push_back(maquina);
    trabajo = seleccionarTrabajo(numTrabajos, numMaquinas, probabilidad);
    maquina = 0;
  }
  return makespan;
}

//Funcion para actualizar las feromonas
void actualizarFeromonas(int numTrabajos, int numMaquinas, vector<vector<double>> &feromonas, vector<Trabajo> &Trabajo, vector<int> &solucion, int makespan, int rho, int q){
  double delta = q / makespan;
  for(int i = 0; i < numTrabajos; i++){
    for(int j = 0; j < numMaquinas; j++){
      feromonas[i][j] = (1 - rho) * feromonas[i][j] + delta;
    }
  }
}

//Funcion para imprimir la solucion
void imprimirSolucion(int numTrabajos, int numMaquinas, vector<int> &solucion){
  cout << "Solucion: " << endl;
  for(int i = 0; i < numTrabajos; i++){
    cout << "Trabajo " << i + 1 << " en la maquina " << solucion[i] + 1 << endl;
  }
}


//Funcion Menu
void menu(){
  cout << "----Menu----" << endl;
  cout << "1.- Ejecutar programa" << endl;
  cout << "2.- Salir" << endl;
  cout << "Opcion: ";
}

int main(){
  int opcion;
  do{
    menu();
    cin >> opcion;
    if(opcion == 1){
        
        //Inicializamos los parametros
        int numTrabajos = 3;
        int numMaquinas = 3;

        vector<Trabajo> Trabajo{
          {1, {1, 2, 3}},
          {2, {1, 2, 3}},
          {3, {1, 2, 3}}
        };

        double alfa = 1; //Influencia en el rastro de feromonas
        double beta = 2; //Influencia en la heuristica
        int rho = 10; //Tasa de evaporacion
        int q = 1; //Feromona inicial
        int numAnts = 50; //Numero de hormigas

        //Inicializamos las feromonas

        vector<vector<double>> feromonas;
        inicializarFeromonas(numTrabajos, numMaquinas, feromonas);

        // mostrar las feromonas
        cout << "Feromonas: " << endl;
        for(int i = 0; i < numTrabajos; i++){
          for(int j = 0; j < numMaquinas; j++){
            cout << feromonas[i][j] << " ";
          }
          cout << endl;
        }

        //Inicializamos MakeSpan
        int makespan = 0;
        vector<int> solucion;

        //Ciclo principal del ACO
        for (int i = 0; i < numAnts; i++){
          vector<vector<int>> antSoluciones(numAnts);
          for (int ant = 0; ant < numAnts; ant++){
            vector<bool> visitados(numTrabajos, false);
            antSoluciones[ant].push_back(rand() % numTrabajos);
            for (int j = 0; j < numTrabajos; j++){
              int trabajoActual = antSoluciones[ant].back();
              visitados[trabajoActual] = true;

            }
          }

        }
      }
      else if(opcion == 2){
        cout << "Saliendo del programa..." << endl;
      }
      else{
        cout << "Opcion no valida" << endl;
      }
  }while(opcion != 2);
  return 0;
}