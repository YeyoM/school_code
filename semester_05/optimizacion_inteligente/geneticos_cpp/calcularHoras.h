#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * La función calcula la diferencia en horas entre dos fechas y horas dadas.
 *
 * @param hora_inicio El parámetro "hora_inicio" representa la hora de inicio en un formato de 24 horas.
 * @param dia_inicio El parámetro "dia_inicio" representa el día de inicio del período de tiempo para
 * el cual queremos calcular el número de horas.
 * @param hora_fin El parámetro "hora_fin" representa la hora de finalización en formato de 24 horas.
 * Por ejemplo, si la hora de finalización es 3:30 PM, se representaría como "15:30".
 * @param dia_fin El parámetro "dia_fin" representa el día en que termina el evento o tarea.
 *
 * @return el número total de horas entre las horas de inicio y fin, teniendo en cuenta el número de
 * días entre los días de inicio y fin.
 */

int CalcularHoras(string hora_inicio, string dia_inicio, string hora_fin, string dia_fin)
{
  vector<string> dias = {"Lunes", "Martes", "Miércoles", "Jueves", "Viernes"};

  // Calculamos primero la diferencia de dias
  int diferencia_dias = distance(dias.begin(), find(dias.begin(), dias.end(), dia_fin)) -
                        distance(dias.begin(), find(dias.begin(), dias.end(), dia_inicio)) + 1;

  // Calculamos la diferencia de horas
  int hora_inicio_value = (hora_inicio.length() == 4) ? stoi(hora_inicio.substr(0, 1)) : stoi(hora_inicio.substr(0, 2));
  int hora_fin_value = (hora_fin.length() == 4) ? stoi(hora_fin.substr(0, 1)) : stoi(hora_fin.substr(0, 2));

  int diferencia_horas = hora_fin_value - hora_inicio_value;

  return diferencia_horas * diferencia_dias;
}