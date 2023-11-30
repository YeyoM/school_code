#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * La función "GenerarIndividuo" genera un horario individual basado en varias restricciones y
 * selección aleatoria de módulos y parámetros.
 * 
 * @param Modulo1 Un vector de vectores de cadenas que representa los diferentes módulos para cada grado.
 * Cada vector interno contiene las asignaturas disponibles para un grado específico.
 * @param Modulo2 El parámetro Modulo2 es un vector de cadenas que representa los módulos para un grado específico.
 * @param Modulo3 El parámetro Modulo3 es un vector de cadenas que representa los días de la semana.
 * @param Modulo4 El parámetro Modulo4 es un vector de cadenas que representa los posibles horarios de inicio
 * para una clase.
 * @param Modulo5 El parámetro Modulo5 es un vector de cadenas que representa los días disponibles para
 * programar clases. Cada cadena en el vector representa un día de la semana, como "Lunes", "Martes", etc.
 * @param Modulo6 El parámetro Modulo6 es un vector de cadenas que representa los horarios disponibles
 * para una clase. Cada cadena en el vector representa un intervalo de tiempo específico, como "8:00-9:30" o
 * "10:00-11:30".
 * @param Modulo7 El parámetro Modulo7 es un vector de cadenas que representa los diferentes tipos de
 * aulas disponibles.
 * @param Modulo8 El parámetro Modulo8 es un vector de vectores de cadenas. Representa las diferentes
 * opciones para un módulo o asignatura específica. Cada vector interno representa una opción diferente para ese
 * módulo.
 * @param Modulo9 Un entero que representa el valor de Modulo9.
 * 
 * @return un vector de cadenas, que representa un individuo generado en función de los parámetros de entrada
 * y ciertas restricciones.
*/
vector<string> GenerarIndividuo(const vector<vector<string>> &Modulo1, const vector<string> &Modulo2,
                                const vector<string> &Modulo3, const vector<string> &Modulo4,
                                const vector<string> &Modulo5, const vector<string> &Modulo6,
                                const vector<string> &Modulo7, const vector<vector<string>> &Modulo8,
                                int &Modulo9)
{

  // RESTRICCIONES DE MATERIAS Y SEMESTRES
  int Grado = rand() % 5;
  string Materia = Modulo1[Grado][rand() % Modulo1[Grado].size()];

  // RESTRICCIONES DE HORARIOS
  int Hora_Inicio = rand() % 7;
  int Hora_Fin = rand() % (7 - Hora_Inicio) + Hora_Inicio;

  // RESTRICCIONES DE HORAS CUMPLIDAS (max 5hrs por materia)
  int Dia_Inicio = rand() % 5;
  int Dia_Fin = rand() % 5;

  while (Dia_Inicio > Dia_Fin)
  {
    Dia_Inicio = rand() % 5;
    Dia_Fin = rand() % 5;
  }

  int Horas = CalcularHoras(Modulo4[Hora_Inicio], Modulo3[Dia_Inicio], Modulo6[Hora_Fin], Modulo5[Dia_Fin]);

  while (Horas > 5)
  {
    Hora_Inicio = rand() % 7;
    Hora_Fin = rand() % (7 - Hora_Inicio) + Hora_Inicio;
    Dia_Inicio = rand() % 5;
    Dia_Fin = rand() % 5;
    while (Dia_Inicio > Dia_Fin)
    {
      Dia_Inicio = rand() % 5;
      Dia_Fin = rand() % 5;
    }
    Horas = CalcularHoras(Modulo4[Hora_Inicio], Modulo3[Dia_Inicio], Modulo6[Hora_Fin], Modulo5[Dia_Fin]);
  }

  // RESTRICCIONES DE TIPOS DE AULAS Y AULAS
  // dar prioridad a aulas normales, luego labs y luego auditorios
  int Tipo_Aula = rand() % 10;

  if      (Tipo_Aula < 6) Tipo_Aula = 0;
  else if (Tipo_Aula < 9) Tipo_Aula = 1;
  else                    Tipo_Aula = 2;

  vector<string> Individuo = {
    Modulo1[Grado][rand() % Modulo1[Grado].size()],
    Modulo2[Grado],
    Modulo3[Dia_Inicio],
    Modulo4[Hora_Inicio],
    Modulo5[Dia_Fin],
    Modulo6[Hora_Fin],
    Modulo7[Tipo_Aula],
    Modulo8[Tipo_Aula][rand() % Modulo8[Tipo_Aula].size()],
    to_string(Modulo9)
  };

  return Individuo;
}
