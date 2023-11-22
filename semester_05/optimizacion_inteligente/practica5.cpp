/*
* Universidad Autonoma de Aguascalientes
* Centro de Ciencias de Basicas
* Departamento de Ciencias de la Computacion
* Materia: Optimización Inteligente
* Diego Emilio Moreno Sánchez
* Profesor: Dr. en C. Luis Fernando Gutierrez Marfileño
* Practica 5: Implementar un programa utilizando la metaheuristica de Sistema de Colonias de Hormigas
* resuelva el problema de Job Shop.
*/

/**
 * Planteamiento del problema
 * 
 * Se tiene un conjunto de trabajos que deben ser procesados por un conjunto de máquinas.
 * Cada trabajo tiene un tiempo de procesamiento en cada máquina. 
 * 
 * El problema consiste en encontrar una secuencia de trabajos para cada máquina de tal 
 * forma que se minimice el tiempo total de procesamiento.
 * 
 * La tabla siguiente muestra los tiempos de procesamiento de cada trabajo en cada máquina.
 * 
 * Trabajo | Maquinas 
 * J1      | M1(3) | M2(3) | M3(3)
 * J2      | M3(2) | M3(3) | M1(4)
 * J3      | M2(3) | M2(3) | M2(2)
 * 
 * Jn    -> trabajo n
 * Mn(t) -> maquina n, tiempo t
 * 
 * Restricciones
 * 
 * 1. La secuencia en la que se realizan los trabajos en las máquinas debe permanecer 
 * siempre igual, por ejemplo, para el trabajo 1 (J1) se tiene que primero se realiza
 * en la máquina 1 (M1), después en la máquina 2 (M2) y finalmente en la máquina 3 (M3).
 * 
 * 2. Cada trabajo solo puede ser procesado por una máquina a la vez.
 * 
 * 3. Cada máquina solo puede procesar un trabajo a la vez. Esto tambien implica que
 * un trabajo no puede ser interrumpido, este tiene que terminar de procesarse para
 * que la máquina pueda procesar otro trabajo.
 * 
 * La solución al problema consiste en encontrar la secuencia de trabajos para cada máquina
 * que minimice el tiempo total de procesamiento.
 * 
 * Solución
 * 
 * Para resolver el problema se propone utilizar el algoritmo de colonia de hormigas.
 * 
 * El algoritmo de colonia de hormigas es un algoritmo probabilístico que se inspira en el
 * comportamiento de las hormigas para resolver problemas de optimización combinatoria.
 * 
 * El algoritmo de colonia de hormigas se basa en el comportamiento de las hormigas para
 * encontrar el camino más corto entre su colonia y una fuente de alimento.
 * 
 * Las hormigas se comunican entre si mediante feromonas, las cuales son sustancias químicas
 * que las hormigas dejan en el suelo para que otras hormigas puedan seguirlas.
 * 
 * Las hormigas prefieren seguir el camino con mayor cantidad de feromonas, por lo que
 * el camino más corto entre la colonia y la fuente de alimento es el que tiene mayor
 * cantidad de feromonas.
 * 
 * El algoritmo de colonia de hormigas se puede aplicar a problemas de optimización
 * combinatoria, como el problema de Job Shop.
 * 
 * Una solución al problema de Job Shop consiste en una secuencia de trabajos para cada
 * máquina. Por ejemplo, para el problema de Job Shop de la tabla anterior, una solución
 * sería la siguiente:
 * 
 * M1: J1(3), J2(4)
 * M2: J3(3), J1(3), J3(3), J3(2)
 * M3: J2(2), J1(3), J2(3)
 * 
 * Aqui hay una tabla que muestra en unidades de tiempo el tiempo de procesamiento de cada
 * trabajo en cada máquina:
 * 
 * unidades de tiempo -> | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 
 * maquina 1 (M1)(Jn) -> | 1 | 1 | 1 |   |   |   |   |   |   |    |    |    | 2  |  2 |  2 |  2 |
 * maquina 2 (M2)(Jn) -> | 3 | 3 | 3 | 1 | 1 | 1 | 3 | 3 | 3 |  3 |  3 |    |    |    |    |    |
 * maquina 3 (M3)(Jn) -> | 2 | 2 |   |   |   |   | 1 | 1 | 1 | 2  | 2  | 2  |    |    |    |    |
 * 
 * 
 * Por que espacios en blanco?
 * 
 * Por que para que una maquina pueda hacer un trabajo debe esperar a que ese mismo trabajo
 * se haya completado por las maquinas anteriores que se muestran en la tabla
 * 
 * Trabajo | Maquinas 
 * J1      | M1(3) | M2(3) | M3(3)
 * J2      | M3(2) | M3(3) | M1(4)
 * J3      | M2(3) | M2(3) | M2(2)
 * 
 * Por ejemplo, 
 * 1. para que la maquina 1 realice el trabajo 2, debe de espera a que la maquina
 *    3 termine de realizar el trabajo 2. 
 * 2. Y que al mismo tiempo no se este realizando el mismo
 *    trabajo en otra maquina.
 * 
 * Para la primera condicion tendremos una matriz 3 x 3 que nos indicara si un trabajo
 * ya fue realizado por una maquina. Los ceros indican que aun no se ha realizado el trabajo
 * y los unos indican que ya se realizo el trabajo.
 * 
 * { {1, 1, 0},
 *   {1, 1, 1},
 *   {1, 0, 0} }
 * 
 * Para la segunda condicion tendremos una tabla que sera el schedule de las maquinas, solamente
 * hay que verificar que no se este realizando el mismo trabajo en otra maquina, esto es verificar
 * que no haya el numero del trabajo en la columna donde se esta realizando el trabajo.
 * 
*/


#include <iostream>
#include <vector>

using namespace std;

struct Nodo {
  int id;
  int maquina;
  int trabajo;
  int tiempo; 
  // puede tener varios nodos siguientes
  vector<Nodo> siguientes;
  // coordenada en la matriz
  int x;
  int y;
  double feromona;
}; 


void menu(){
  cout << "----Menu----" << endl;
  cout << "1.- Ejecutar programa" << endl;
  cout << "2.- Salir" << endl;
  cout << "Opcion: ";
}

// funcion para recorrer el grafo en orden de los nodos
void recorrerGrafo(vector<Nodo> &grafo) {
  // recorremos el grafo
  for (int i = 0; i < grafo.size() - 1; i++) {
    cout << "Nodo " << grafo[i].id << endl;
    cout << "Maquina " << grafo[i].maquina << endl;
    cout << "Trabajo " << grafo[i].trabajo << endl;
    cout << "Tiempo " << grafo[i].tiempo << endl;
    cout << "Siguientes: " << endl ;
    for (int j = 0; j < grafo[i].siguientes.size(); j++) {
      cout << "Nodo " << grafo[i].siguientes[j].id << endl;
      cout << "Maquina " << grafo[i].siguientes[j].maquina << endl;
      cout << "Trabajo " << grafo[i].siguientes[j].trabajo << endl;
      cout << "Tiempo " << grafo[i].siguientes[j].tiempo << endl;
    }
    cout << endl;
  }
}

// funcion para calcular una solucion de la maquina n
void calcularSolucionMaquina(vector<Nodo> &grafo, vector<Nodo> &solucion, int maxTrabajos, int maquina) {
  // recorremos el grafo
  // la maquina 1 solo tiene que realizar 4 trabajos
  int trabajos_realizados = 0;
  Nodo nodo_actual = grafo[0];
  Nodo nodo_sig = grafo[0];
  while (trabajos_realizados != maxTrabajos) {
    // cout << "Nodo actual: " << nodo_actual.id << endl;
    // recorremos el grafo
    // recorremos los siguientes del nodo actual
    for (int i = 0; i < nodo_actual.siguientes.size(); i++) {
      if (nodo_actual.siguientes[i].maquina == maquina) {
        nodo_sig = grafo[nodo_actual.siguientes[i].id];
        solucion.push_back(nodo_sig);
        trabajos_realizados++;
        break;
      }
    } 
    // cout << nodo_sig.id << endl;
    nodo_actual = nodo_sig;    
    if (nodo_actual.id == 10 || nodo_actual.siguientes.size() == 0) {
      break;
    }
  }
}

void mostrarTrabajosRealizados(vector<vector<int>> &trabajosRealizados) {
  cout << "Trabajos realizados: " << endl;
  for (int i = 0; i < trabajosRealizados.size(); i++) {
    for (int j = 0; j < trabajosRealizados[i].size(); j++) {
      cout << trabajosRealizados[i][j] << " ";
    }
    cout << endl;
  }
}

int calcularMakespan(vector<vector<Nodo>> &solucion, vector<vector<int>> &trabajosRealizados, vector<vector<int>> &schedule) {
  int makespan = 0;

  int time_trabajo_1 = 0;
  int time_trabajo_2 = 0;
  int time_trabajo_3 = 0;

  int time_maquina_1 = 0;
  int time_maquina_2 = 0;
  int time_maquina_3 = 0;
  
  // El total de trabajos a realizar es igual a 9, 
  // por lo que hasta no completar los 9 trabajos no 
  // se termina la ejecucion de esta funcion
  int trabajos_realizados = 0;

  // recorremos las soluciones
  while (trabajos_realizados != 9) {
    // recorremos las maquinas
    for (int i = 0; i < solucion.size(); i++) {
      // recorremos los trabajos de la maquina
      for (int j = 0; j < solucion[i].size(); j++) {
        Nodo nodo_actual = solucion[i][j];
        // verificamos que el trabajo no se haya realizado
        if (trabajosRealizados[nodo_actual.x][nodo_actual.y] == 0) {
          // verificar que el trabajo ya se haya realizado por las maquinas anteriores (en caso de que las haya)
          // esto quiere decir que el trabajo ya se puede agregar al schedule
          bool trabajo_permitido = true;
          for (int k = 0; k < nodo_actual.y; k++) {
            if (trabajosRealizados[nodo_actual.x][k] == 0) {
              trabajo_permitido = false;
              break;
            }
          }
          // si el trabajo ya se puede agregar al schedule
          if (trabajo_permitido == true) {
            // marcar el trabajo como realizado
            trabajosRealizados[nodo_actual.x][nodo_actual.y] = 1;
            trabajos_realizados++;  
            mostrarTrabajosRealizados(trabajosRealizados); 
            switch (nodo_actual.trabajo) {
              case 1:
                switch (nodo_actual.maquina) {
                  case 1:
                    if (time_maquina_1 > time_trabajo_1) {
                      time_trabajo_1 = time_maquina_1;
                    } else if (time_maquina_1 < time_trabajo_1) {
                      time_maquina_1 = time_trabajo_1;
                    }
                    time_trabajo_1 += nodo_actual.tiempo;
                    time_maquina_1 += nodo_actual.tiempo;
                    break;
                  case 2:
                    if (time_maquina_2 > time_trabajo_1) {
                      time_trabajo_1 = time_maquina_2;
                    } else if (time_maquina_2 < time_trabajo_1) {
                      time_maquina_2 = time_trabajo_1;
                    }
                    time_trabajo_1 += nodo_actual.tiempo;
                    time_maquina_2 += nodo_actual.tiempo;
                    break;
                  case 3:
                    if (time_maquina_3 > time_trabajo_1) {
                      time_trabajo_1 = time_maquina_3;
                    } else if (time_maquina_3 < time_trabajo_1) {
                      time_maquina_3 = time_trabajo_1;
                    }
                    time_trabajo_1 += nodo_actual.tiempo;
                    time_maquina_3 += nodo_actual.tiempo;
                    break;
                }
                break;
              case 2:
              switch (nodo_actual.maquina) {
                  case 1:
                    if (time_maquina_1 > time_trabajo_2) {
                      time_trabajo_2 = time_maquina_1;
                    } else if (time_maquina_1 < time_trabajo_2) {
                      time_maquina_1 = time_trabajo_2;
                    }
                    time_trabajo_2 += nodo_actual.tiempo;
                    time_maquina_1 += nodo_actual.tiempo;
                    break;
                  case 2:
                    if (time_maquina_2 > time_trabajo_2) {
                      time_trabajo_2 = time_maquina_2;
                    } else if (time_maquina_2 < time_trabajo_2) {
                      time_maquina_2 = time_trabajo_2;
                    }
                    time_trabajo_2 += nodo_actual.tiempo;
                    time_maquina_2 += nodo_actual.tiempo;
                    break;
                  case 3:
                    if (time_maquina_3 > time_trabajo_2) {
                      time_trabajo_2 = time_maquina_3;
                    } else if (time_maquina_3 < time_trabajo_2) {
                      time_maquina_3 = time_trabajo_2;
                    }
                    time_trabajo_2 += nodo_actual.tiempo;
                    time_maquina_3 += nodo_actual.tiempo;
                    break;
                }
                break;
              case 3:
              switch (nodo_actual.maquina) {
                  case 1:
                    if (time_maquina_1 > time_trabajo_3) {
                      time_trabajo_3 = time_maquina_1;
                    } else if (time_maquina_1 < time_trabajo_3) {
                      time_maquina_1 = time_trabajo_3;
                    }
                    time_trabajo_3 += nodo_actual.tiempo;
                    time_maquina_1 += nodo_actual.tiempo;
                    break;
                  case 2:
                    if (time_maquina_2 > time_trabajo_3) {
                      time_trabajo_3 = time_maquina_2;
                    } else if (time_maquina_2 < time_trabajo_3) {
                      time_maquina_2 = time_trabajo_3;
                    }
                    time_trabajo_3 += nodo_actual.tiempo;
                    time_maquina_2 += nodo_actual.tiempo;
                    break;
                  case 3:
                    if (time_maquina_3 > time_trabajo_3) {
                      time_trabajo_3 = time_maquina_3;
                    } else if (time_maquina_3 < time_trabajo_3) {
                      time_maquina_3 = time_trabajo_3;
                    }
                    time_trabajo_3 += nodo_actual.tiempo;
                    time_maquina_3 += nodo_actual.tiempo;
                    break;
                }
                break;
            }

          }
        }
      }
    }
  }

  // El makespan es el tiempo de la maquina que mas tiempo tardo en realizar el ultimo trabajo
  if (time_maquina_1 > time_maquina_2 && time_maquina_1 > time_maquina_3) {
    makespan = time_maquina_1;
  } else if (time_maquina_2 > time_maquina_1 && time_maquina_2 > time_maquina_3) {
    makespan = time_maquina_2;
  } else if (time_maquina_3 > time_maquina_1 && time_maquina_3 > time_maquina_2) {
    makespan = time_maquina_3;
  }

  return makespan;
}

int main() {

  int opcion;

  // Inicializacion del grafo
  vector<Nodo> grafo;

  // Inicializacion de los nodos
  // Cabeza del grafo (colonia de hormigas)
  Nodo nodo0;
  nodo0.id = 0;
  nodo0.maquina = 0;
  nodo0.trabajo = 0;
  nodo0.tiempo = 0;
  nodo0.x = -1;
  nodo0.y = -1;
  nodo0.feromona = 0;

  Nodo nodo1;
  nodo1.id = 1;
  nodo1.maquina = 1;
  nodo1.trabajo = 1;
  nodo1.tiempo = 3;
  nodo1.x = 0;
  nodo1.y = 0;
  nodo1.feromona = 1;

  Nodo nodo2;
  nodo2.id = 2;
  nodo2.maquina = 2;
  nodo2.trabajo = 1;
  nodo2.tiempo = 3;
  nodo2.x = 0;
  nodo2.y = 1;
  nodo2.feromona = 1;

  Nodo nodo3;
  nodo3.id = 3;
  nodo3.maquina = 3;
  nodo3.trabajo = 1;
  nodo3.tiempo = 3;
  nodo3.x = 0;
  nodo3.y = 2;
  nodo3.feromona = 1;

  Nodo nodo4;
  nodo4.id = 4;
  nodo4.maquina = 3;
  nodo4.trabajo = 2;
  nodo4.tiempo = 2;
  nodo4.x = 1;
  nodo4.y = 0;
  nodo4.feromona = 1;

  Nodo nodo5;
  nodo5.id = 5;
  nodo5.maquina = 3;
  nodo5.trabajo = 2;
  nodo5.tiempo = 3;
  nodo5.x = 1;
  nodo5.y = 1;
  nodo5.feromona = 1;

  Nodo nodo6;
  nodo6.id = 6;
  nodo6.maquina = 1;
  nodo6.trabajo = 2;
  nodo6.tiempo = 4;
  nodo6.x = 1;
  nodo6.y = 2;
  nodo6.feromona = 1;

  Nodo nodo7;
  nodo7.id = 7;
  nodo7.maquina = 2;
  nodo7.trabajo = 3;
  nodo7.tiempo = 3;
  nodo7.x = 2;
  nodo7.y = 0;
  nodo7.feromona = 1;

  Nodo nodo8;
  nodo8.id = 8;
  nodo8.maquina = 2;
  nodo8.trabajo = 3;
  nodo8.tiempo = 3;
  nodo8.x = 2;
  nodo8.y = 1;
  nodo8.feromona = 1;

  Nodo nodo9;
  nodo9.id = 9;
  nodo9.maquina = 2;
  nodo9.trabajo = 3;
  nodo9.tiempo = 2;
  nodo9.x = 2;
  nodo9.y = 2;
  nodo9.feromona = 1;

  // Nodo final (Fuentes de alimento)
  Nodo nodo10;
  nodo10.id = 10;
  nodo10.maquina = 0;
  nodo10.trabajo = 0;
  nodo10.tiempo = 0;
  nodo10.x = -1;
  nodo10.y = -1;
  nodo10.feromona = 0;

  // Inicializacion de los nodos siguientes

  // Caminos iniciales
  nodo0.siguientes.push_back(nodo1);
  nodo0.siguientes.push_back(nodo4);
  nodo0.siguientes.push_back(nodo7);

  nodo1.siguientes.push_back(nodo2);
  nodo2.siguientes.push_back(nodo3);
  nodo3.siguientes.push_back(nodo10);

  nodo4.siguientes.push_back(nodo5);
  nodo5.siguientes.push_back(nodo6);
  nodo6.siguientes.push_back(nodo10);

  nodo7.siguientes.push_back(nodo8);
  nodo8.siguientes.push_back(nodo9);
  nodo9.siguientes.push_back(nodo10);

  // Caminos entrelazados
  nodo1.siguientes.push_back(nodo6);
  nodo6.siguientes.push_back(nodo1);

  nodo2.siguientes.push_back(nodo7);
  nodo7.siguientes.push_back(nodo2);

  nodo2.siguientes.push_back(nodo8);
  nodo8.siguientes.push_back(nodo2);

  nodo2.siguientes.push_back(nodo9);
  nodo9.siguientes.push_back(nodo2);

  nodo3.siguientes.push_back(nodo4);
  nodo4.siguientes.push_back(nodo3);

  nodo3.siguientes.push_back(nodo5);
  nodo5.siguientes.push_back(nodo3);

  // agregamos los nodos al grafo
  grafo.push_back(nodo0);
  grafo.push_back(nodo1);
  grafo.push_back(nodo2);
  grafo.push_back(nodo3);
  grafo.push_back(nodo4);
  grafo.push_back(nodo5);
  grafo.push_back(nodo6);
  grafo.push_back(nodo7);
  grafo.push_back(nodo8);
  grafo.push_back(nodo9);
  grafo.push_back(nodo10);

  // generamos la matriz de trabajos realizados, inicialmente todos los trabajos estan sin realizar (0)
  vector<vector<int>> trabajosRealizados;
  for (int i = 0; i < 3; i++) {
    vector<int> fila;
    for (int j = 0; j < 3; j++) {
      fila.push_back(0);
    }
    trabajosRealizados.push_back(fila);
  }

  // generamos el schedule de las maquinas, inicialmente todas las maquinas estan libres (0)
  vector<vector<int>> schedule;
  for (int i = 0; i < 3; i++) {
    vector<int> fila;
    for (int j = 0; j < 26; j++) {
      fila.push_back(0);
    }
    schedule.push_back(fila);
  }

  // Initializacion de variables
  double alfa = 1;  //Influencia en el rastro de feromonas
  double beta = 2;  //Influencia en la heuristica
  int rho     = 10; //Tasa de evaporacion
  int q       = 1;  //Feromona inicial
  int numAnts = 50; //Numero de hormigas

  do {
    menu();
    cin >> opcion;

    if (opcion == 1) {
      cout << "Ejecutando programa..." << endl;
      // recorrerGrafo(grafo);

      vector<Nodo> solucion1;
      calcularSolucionMaquina(grafo, solucion1, 2, 1);

      vector<Nodo> solucion2;
      calcularSolucionMaquina(grafo, solucion2, 4, 2);

      vector<Nodo> solucion3;
      calcularSolucionMaquina(grafo, solucion3, 3, 3);

      vector<vector<Nodo>> soluciones;
      soluciones.push_back(solucion1);
      soluciones.push_back(solucion2);
      soluciones.push_back(solucion3);

      // recorremos las soluciones
      for (int i = 0; i < soluciones.size(); i++) {
        cout << "Solucion maquina " << i + 1 << endl;
        for (int j = 0; j < soluciones[i].size(); j++) {
          cout << "Nodo " << soluciones[i][j].id << endl;
          cout << "Trabajo " << soluciones[i][j].trabajo << endl;
          cout << endl;
        }
      }

      // calculamos el makespan
      int makespan = calcularMakespan(soluciones, trabajosRealizados, schedule);
      cout << "Makespan: " << makespan << endl;
    }

    else if (opcion == 2) {
      cout << "Saliendo del programa..." << endl;
    }

    else {
      cout << "Opcion no valida" << endl;
    }

  } while (opcion != 2);

  return 0;
}