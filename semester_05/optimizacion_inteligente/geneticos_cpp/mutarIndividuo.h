#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * La función muta un individuo seleccionando aleatoriamente un módulo para mutar y realizando cambios
 * en los elementos correspondientes del individuo.
 * 
 * @param Individuo Un vector de cadenas que representa una solución o cromosoma individual. Cada elemento
 * en el vector representa un aspecto específico del individuo, como la asignatura seleccionada, el grado,
 * el día de la semana, la hora de inicio, la hora de finalización, el tipo de aula y el aula seleccionada.
 * @param Modulo1 Modulo1 es un vector de vectores de cadenas que representa las diferentes asignaturas y
 * sus correspondientes grados. Cada vector interno representa un nivel de grado y cada cadena representa una
 * asignatura en ese nivel de grado.
 * @param Modulo2 El parámetro Modulo2 es un vector de cadenas que representa los diferentes grados para una
 * asignatura en particular. Cada elemento en el vector corresponde a un nivel de grado diferente.
 * @param Modulo3 El parámetro Modulo3 es un vector de cadenas que representa los días de la semana. Contiene
 * los nombres de los días en el orden en que se utilizan en el programa.
 * @param Modulo4 El parámetro Modulo4 es un vector de cadenas que representa los posibles horarios de inicio
 * para una clase.
 * @param Modulo5 El parámetro Modulo5 es un vector de cadenas que representa los días disponibles para
 * programar clases. Cada cadena en el vector representa un día de la semana, como "Lunes", "Martes",
 * etc.
 * @param Modulo6 El parámetro Modulo6 es un vector de cadenas que representa los valores posibles para la
 * hora de finalización de una clase.
 * @param Modulo7 El parámetro Modulo7 es un vector de cadenas que representa los diferentes tipos de aulas
 * disponibles. Cada cadena en el vector representa un tipo de aula, como "Aula normal", "Laboratorio" o
 * "Auditorio".
 * @param Modulo8 Modulo8 es un vector de vectores de cadenas. Representa las opciones disponibles para el tipo
 * de aula y el aula específica para la mutación. Cada vector interno representa un tipo diferente de aula, y
 * las cadenas dentro de cada vector interno representan las opciones disponibles.
 */

void mutarIndividuo(vector<string> &Individuo, const vector<vector<string>> &Modulo1, const vector<string> &Modulo2,
                    const vector<string> &Modulo3, const vector<string> &Modulo4,
                    const vector<string> &Modulo5, const vector<string> &Modulo6,
                    const vector<string> &Modulo7, const vector<vector<string>> &Modulo8)
{
  // Seleccionamos de manera aleatoria el modulo que se va a mutar
  int ModuloAMutar = rand() % 7;

  // Si el modulo a mutar es el 0, entonces mutamos la materia (tambien modificamos el grado)
  if (ModuloAMutar == 0 || ModuloAMutar == 1)
  {
    int Grado = rand() % 5;
    string Materia = Modulo1[Grado][rand() % Modulo1[Grado].size()];
    Individuo[0] = Materia;
    Individuo[1] = Modulo2[Grado];
  }

  // Si el modulo a mutar es el 2, entonces mutamos el dia de inicio, el dia de fin, la hora de inicio y la hora de fin, tal que en total no se excedan las 5 horas
  if (ModuloAMutar > 2 && ModuloAMutar < 5)
  {
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

    while (Horas > 4)
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

    Individuo[2] = Modulo3[Dia_Inicio];
    Individuo[3] = Modulo4[Hora_Inicio];
    Individuo[4] = Modulo5[Dia_Fin];
    Individuo[5] = Modulo6[Hora_Fin];
  }

  // Si el modulo a mutar es el 6, entonces mutamos el tipo de aula (tambien modificamos el aula)
  if (ModuloAMutar == 6 || ModuloAMutar == 7)
  {
    // dar prioridad a aulas normales, luego labs y luego auditorios
    int Tipo_Aula = rand() % 10;

    if      (Tipo_Aula < 6) Tipo_Aula = 0;
    else if (Tipo_Aula < 9) Tipo_Aula = 1;
    else                    Tipo_Aula = 2;

    Individuo[6] = Modulo7[Tipo_Aula];
    Individuo[7] = Modulo8[Tipo_Aula][rand() % Modulo8[Tipo_Aula].size()];
  }

}