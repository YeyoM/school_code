// Autor: Diego Emilio Moreno Sanchez @YeyoM
/*

  Se requiere capturar los datos de n estudiantes, 
  con la siguiente estructura:
  
  - Información de los estudiantes
  
  struct estudiante {    
    char nombre[50];
    char genero;
    float calificacion[2];       
  };

  El programa debe obtener las siguientes estadísticas:

  - Captura de los datos de los n estudiantes
  - Número de estudiantes con promedio aprobado
  - Número de estudiantes mujeres con promedio aprobado
  - Número de estudiantes hombres con promedio aprobado
  - Número de estudiantes donde la calificación 1 fue aprobada
  - Porcentaje de estudiantes hombres con promedio aprobado
  - Porcentaje de estudiantes mujeres con promedio reprobado
  - Calificación más alta de los promedios de hombres
  - Calificación más alta de los promedios de mujeres.
   
  Incluir  documentación definida para un programa formal
  
  Consideraciones:

  - El promedio de cada estudiante es del cálculo de sus dos 
    calificaciones
  - Realizar el recorrido de los elementos del arreglo de 
    estructuras por medio de apuntadores.
  - Realizar la distribución del código a través de  funciones 
    y/o procedimientos

*/

#include <iostream>

using namespace std;

struct estudiante {    
  char nombre[50];
  char genero;
  float calificacion[2];       
};

int numero_estudiantes = 0;

int main() {

  cout << "Ingrese el numero de estudiantes: ";
  cin >> numero_estudiantes;
  cout << endl;

  struct estudiante estudiantes[numero_estudiantes];
  struct estudiante *apuntador_estudiantes = estudiantes;

  float promedios_aprobados = 0,
        promedios_aprobados_mujeres = 0,
        promedios_aprobados_hombres = 0,
        promedios_reprobados_mujeres = 0,
        primer_calificacion_aprobada = 0,
        porcentaje_hombres_aprobados = 0,
        porcentaje_mujeres_reprobadas = 0,
        max_promedio_hombres = 0,
        max_promedio_mujeres = 0,
        promedios[numero_estudiantes];
  
  char fem    = 'F';
  char fem_c  = 'f';
  char mas    = 'M';
  char mas_c  = 'm';

  float total_hombres = 0, 
        total_mujeres = 0;

  for(int i = 0; i < numero_estudiantes; i++) {

    cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
    cin >> estudiantes[i].nombre;

    cout << "Ingrese el genero del estudiante " << i + 1 << " (M o F): ";
    cin >> estudiantes[i].genero;

    // calculamos el total de hombres y mujeres para calular porcentajes
    if (estudiantes[i].genero == fem || estudiantes[i].genero == fem_c) {
      total_mujeres++;
    } else if (estudiantes[i].genero == mas || estudiantes[i].genero == mas_c) {
      total_hombres++;
    }

    for (int j = 0; j < 2; j++) {

      cout << "Ingrese la calificacion " << j + 1 <<" del estudiante " << i + 1 << ": "; 
      cin >> estudiantes[i].calificacion[j];

      // checamos cuantos alumnos su calificacion 1 fue aprobada
      if (j == 0 && estudiantes[i].calificacion[j] > 6) {
        primer_calificacion_aprobada++;
      }

    }

    // calculamos todos los promedios
    promedios[i] = (estudiantes[i].calificacion[0] + estudiantes[i].calificacion[1]) / 2;
    
    // calculamos los promedios aprobados
    if (promedios[i] >= 6.0) {
      promedios_aprobados++;
      if (estudiantes[i].genero == fem || estudiantes[i].genero == fem_c) {
        promedios_aprobados_mujeres++;
        if(promedios[i] > max_promedio_mujeres) {
          max_promedio_mujeres = promedios[i];
        }
      } else if (estudiantes[i].genero == mas || estudiantes[i].genero == mas_c) {
        promedios_aprobados_hombres++;
        if(promedios[i] > max_promedio_hombres) {
          max_promedio_hombres = promedios[i];
        }
      }
    }

    // calculamos los promedios reprobados
    if (promedios[i] < 6.0) {
      if (estudiantes[i].genero == fem || estudiantes[i].genero == fem_c) {
        promedios_reprobados_mujeres++;
      }
    }
    
    cout << endl;

  }

  // calculamos porcentajes de hombres aprobados
  if (total_hombres != 0) {
    porcentaje_hombres_aprobados = (promedios_aprobados_hombres / total_hombres) * 100;
  } else {
    porcentaje_hombres_aprobados = 0;
  }

  // calculamos porcentajes de mujeres reprobadas
  if (total_mujeres != 0) {
    porcentaje_mujeres_reprobadas = (promedios_reprobados_mujeres / total_mujeres) * 100;
  } else {
    porcentaje_mujeres_reprobadas = 0;
  }

  cout << endl;

  // mostramos los datos ingresados con apuntadores
  cout << "Datos ingresados" << endl;
  cout << "--------------------------------------------------------------------------------------------" << endl;
  for(int i = 0; i < numero_estudiantes; i++) {
    cout << "Nombre:   " << (apuntador_estudiantes + i) -> nombre << endl;
    cout << "Genero:   " << estudiantes[i].genero << endl;
    cout << "Cal 1:    " << (apuntador_estudiantes + i) -> calificacion[0] << endl;
    cout << "Cal 2:    " << (apuntador_estudiantes + i) -> calificacion[1] << endl;
    cout << "Promedio: " << promedios[i] << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;
  }

  cout << endl;
  cout << endl;

  cout << "Estadisticas obtenidas" << endl;

  cout << "--------------------------------------------------------------------------------------------" << endl;
  cout << "Total de alumnos aprobados:                       " << promedios_aprobados << endl;
  cout << "Total de alumnos mujeres aprobadas:               " << promedios_aprobados_mujeres << endl;
  cout << "Total de alumnos hombres aprobados:               " << promedios_aprobados_hombres << endl;
  cout << "Maximo promedio de los hombres:                   " << max_promedio_hombres << endl;
  cout << "Maximo promedio de las mujeres:                   " << max_promedio_mujeres << endl;
  cout << "Porcentaje de Hombres Aprobados:                  " << porcentaje_hombres_aprobados << "%" << endl;
  cout << "Porcentaje de Mujeres Reprobadas:                 " << porcentaje_mujeres_reprobadas << "%" << endl;
  cout << "Numero de alumnos con la calificacion 1 aprobada: " << primer_calificacion_aprobada << endl;
  cout << "--------------------------------------------------------------------------------------------" << endl;

  return 0;
}
