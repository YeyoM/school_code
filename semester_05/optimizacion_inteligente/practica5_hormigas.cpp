/*
* Universidad Autonoma de Aguascalientes
* Centro de Ciencias de Basicas
* Departamento de Ciencias de la Computacion
* Materia: Optimización Inteligente
* Diego Alberto Aranda Gonzalez
* Diego Emilio Moreno Sánchez
* Profesor: Dr. en C. Luis Fernando Gutierrez Marfileño
* Practica 5: Implementar un programa utilizando la metaheuristica de Sistema de Colonias de Hormigas
* Resuelva el problema de Job Shop.
*/

#include <iostream>
#include <math.h>
using namespace std;

// Funcion para eliminar el trabajo que se acaba de realizar
void EliminarTrabajo(int trabajos[3][3], int trabajo) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (trabajos[i][j] == trabajo) {
        trabajos[i][j] = 9;
      }
    }
  }
}

// Probabilidad de elegir un siguiente trabajo
// En el caso del algorithmo de hormigas, la probabilidad de elegir un trabajo es
// la probabilidad de elegir un camino u otro
float CalcularProbabilidad(int feromona, int tiempo, int SumaFeromonas) {
  float probabilidad = 0;
  probabilidad = (feromona * pow(1.0f / tiempo, 2)) / (SumaFeromonas * pow(1.0f / tiempo, 2));
  return probabilidad;
}

// Funcion para calcular la sumatoria de las feromonas y asi poder calcular la probabilidad
int SumaFeromonas(int Feromonas[3][3]) {
  int sumatoria = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      sumatoria += Feromonas[i][j];
    }
  }
  return sumatoria;
}

// Funcion para buscar el camino con mayor probabilidad
int BuscarCamino(int trabajos[3][3], int tiempos[3][3], int TrabajoActual, int CaminoActual[3][3], int Feromonas[3][3], bool esUtlimo = false) {
  float mayor = 0.1;
    
  int caminos[3][3] = { {0, 0, 0},
                        {0, 0, 0},
                        {0, 0, 0} };

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (trabajos[i][j] != TrabajoActual && trabajos[i][j] != 9 ) {
        caminos[i][j] = 1;
      }
    }
  } 
    
  int Cono = 0;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (caminos[i][j] == 1) {
        Cono++;
      }
    }
  }

  if (Cono == 0) {
    //agregamos caminos posibles 
    caminos[0][0] = 1;
    caminos[1][1] = 1;
  }

  float probabilidad[3][3] = { {0, 0, 0},
                               {0, 0, 0},
                               {0, 0, 0} };
                              
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (caminos[i][j] == 1) {
        probabilidad[i][j] = CalcularProbabilidad(Feromonas[i][j], tiempos[i][j], SumaFeromonas(CaminoActual));
        if (probabilidad[i][j] > mayor) {
          probabilidad[i][j] = mayor+.1;
          mayor = probabilidad[i][j];
        }
      }
    }
  }

  int conteo = 0;
  while (conteo < 4) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (probabilidad[i][j] == mayor) {
          CaminoActual[i][j] = 1;
          conteo++;
        }
      }
    }
  }

  //Imprimo el camino actual
  if (esUtlimo) {
    cout << "Resultado: " << endl;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
          cout << CaminoActual[i][j] << " ";
      }
      cout<<endl;
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (CaminoActual[i][j] == 1) {
        TrabajoActual = trabajos[i][j];
      }
    }
  }

  // cout << "Trabajo Actual " << TrabajoActual << endl;

  //retorno el trabajo actual
  return TrabajoActual;
}

// Funcion para actualizar la matriz de feromonas
void ActualizarFeromonas(int Feromonas[3][3], int camino[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (camino[i][j] == 1) {
        Feromonas[i][j] = (1.1 * Feromonas[i][j]);
      }
    }
  }
}

int EjecutarColoniaHormigas(int trabajos[3][3], int tiempos[3][3], int Feromonas[3][3], bool esUltimo = false) {

  // inicializamos un camino vacio
  int camino[3][3] = { {0, 0, 0},
                       {0, 0, 0},
                       {0, 0, 0} };

  int random = rand() % 2;
  int trabajoActual = trabajos[random][0];
  camino[random][0] = 1;

  EliminarTrabajo(trabajos, trabajoActual);

  trabajoActual = BuscarCamino(trabajos, tiempos, trabajoActual, camino, Feromonas);

  if (esUltimo) {
    BuscarCamino(trabajos, tiempos, trabajoActual, camino, Feromonas, true);
  } else {
    BuscarCamino(trabajos, tiempos, trabajoActual, camino, Feromonas);
  }

  ActualizarFeromonas(Feromonas, camino);

  int costeTiempo = 0;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (camino[i][j] == 1) {
        costeTiempo += tiempos[i][j];
      }
    }
  }

  return costeTiempo;
}

//Funcion Menu
void menu(){
  cout << "----Menu----" << endl;
  cout << "1.- Ejecutar programa" << endl;
  cout << "2.- Salir" << endl;
  cout << "Opcion: ";
}


int main() {

  srand(time(NULL));
  int opcion;

  do {

    menu();
    cin >> opcion;

    if (opcion == 1) {

      int costeMinimo = 999;

      int trabajos[3][3]  = { {1, 2, 3},
                              {3, 1, 9},
                              {9, 2, 1} };

      int tiempos[3][3]   = { {3, 4, 3},
                              {3, 3, 9},
                              {9, 3, 2} };

      int Feromonas[3][3] = { {1, 1, 1},
                              {1, 1, 1},
                              {1, 1, 1} };


      for (int i = 0; i < 50; i++) {
        int coste;
        if (i == 49) {
          coste = EjecutarColoniaHormigas(trabajos, tiempos, Feromonas, true);
        } else {
          coste = EjecutarColoniaHormigas(trabajos, tiempos, Feromonas);
        }
        if (coste < costeMinimo) {
          costeMinimo = coste;
        }
      }

      cout<<"Coste minimo: "<<costeMinimo<<endl;

    }

    else if (opcion == 2) {
      cout << "Saliendo..." << endl;
    }

    else {
      cout << "Opcion no valida" << endl;
    }

  } while (opcion != 2);

  return 0;
}