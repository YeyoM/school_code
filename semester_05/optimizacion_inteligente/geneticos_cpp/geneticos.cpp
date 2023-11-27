#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdlib> // For rand and srand
#include <ctime>   // For time

using namespace std;

/**
 * The function calculates the difference in hours between two given dates and times.
 *
 * @param hora_inicio The parameter "hora_inicio" represents the starting time in a 24-hour format.
 * @param dia_inicio The parameter "dia_inicio" represents the starting day of the time period for
 * which we want to calculate the number of hours.
 * @param hora_fin The parameter "hora_fin" represents the end time in a 24-hour format. For example,
 * if the end time is 3:30 PM, it would be represented as "15:30".
 * @param dia_fin The parameter "dia_fin" represents the day when the event or task ends.
 *
 * @return the total number of hours between the start and end times, taking into account the number of
 * days between the start and end days.
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

/**
 * The function "GenerarIndividuo" generates an individual schedule based on various constraints and
 * random selection of modules and parameters.
 * 
 * @param Modulo1 A vector of vectors of strings representing the different modules for each grade.
 * Each inner vector contains the available subjects for a specific grade.
 * @param Modulo2 The Modulo2 parameter is a vector of strings representing the modules for a specific
 * grade.
 * @param Modulo3 The Modulo3 parameter is a vector of strings representing the days of the week.
 * @param Modulo4 The parameter Modulo4 is a vector of strings representing the possible starting times
 * for a class.
 * @param Modulo5 The parameter Modulo5 is a vector of strings representing the available days for
 * scheduling classes. Each string in the vector represents a day of the week, such as "Monday",
 * "Tuesday", etc.
 * @param Modulo6 The parameter Modulo6 is a vector of strings representing the available time slots
 * for a class. Each string in the vector represents a specific time slot, such as "8:00-9:30" or
 * "10:00-11:30".
 * @param Modulo7 The parameter Modulo7 is a vector of strings representing the different types of
 * classrooms available.
 * @param Modulo8 The parameter Modulo8 is a vector of vectors of strings. It represents the different
 * options for a specific module or subject. Each inner vector represents a different option for that
 * module.
 * @param Modulo9 An integer representing the value of Modulo9.
 * 
 * @return a vector of strings, which represents an individual generated based on the given input
 * parameters and certain restrictions.
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
  int Dia_Inicio = rand() % 3;
  int Dia_Fin = rand() % 2;

  int Horas = CalcularHoras(Modulo4[Hora_Inicio], Modulo3[Dia_Inicio], Modulo6[Hora_Fin], Modulo5[Dia_Fin]);

  while (Horas > 5)
  {
    Hora_Inicio = rand() % 7;
    Hora_Fin = rand() % (7 - Hora_Inicio) + Hora_Inicio;
    Dia_Inicio = rand() % 3;
    Dia_Fin = rand() % 2;
    Horas = CalcularHoras(Modulo4[Hora_Inicio], Modulo3[Dia_Inicio], Modulo6[Hora_Fin], Modulo5[Dia_Fin]);
  }

  // RESTRICCIONES DE TIPOS DE AULAS Y AULAS
  // dar prioridad a aulas normales, luego labs y luego auditorios
  int Tipo_Aula = rand() % 10;

  if (Tipo_Aula < 6)
  {
    Tipo_Aula = 0;
  }
  else if (Tipo_Aula < 9)
  {
    Tipo_Aula = 1;
  }
  else
  {
    Tipo_Aula = 2;
  }

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

void calcularPosibleHorario(vector<vector<string>> &PosibleHorario, vector<vector<string>> &PoblacionInicial, unordered_map<string, int> &horas_registradas,
                            unordered_map<string, unordered_map<string, int>> &horario_aula_54_a, unordered_map<string, unordered_map<string, int>> &horario_aula_54_c,
                            unordered_map<string, unordered_map<string, int>> &horario_aula_54_f, unordered_map<string, unordered_map<string, int>> &horario_aula_54_g,
                            unordered_map<string, unordered_map<string, int>> &horario_aula_54_h, unordered_map<string, unordered_map<string, int>> &horario_aula_61_lab,
                            unordered_map<string, unordered_map<string, int>> &horario_aula_203_lab, unordered_map<string, unordered_map<string, int>> &horario_aula_204_lab,
                            unordered_map<string, unordered_map<string, int>> &horario_aula_1_aud, bool &solucion_encontrada)
{
  for (int i = 0; i < PoblacionInicial.size(); i++)
  {

    // Tomamos el individuo actual
    vector<string> Individuo = PoblacionInicial[i];

    // Vamos a hacer las validaciones de horario
    string Materia = Individuo[0];
    string Grupo = Individuo[1];
    string Dia_Inicio = Individuo[2];
    string Hora_Inicio = Individuo[3];
    string Dia_Fin = Individuo[4];
    string Hora_Fin = Individuo[5];
    string Tipo_Aula = Individuo[6];
    string Aula = Individuo[7];
    string ID_Individuo = Individuo[8];

    // Calculamos las horas que se van a registrar
    int Horas = CalcularHoras(Hora_Inicio, Dia_Inicio, Hora_Fin, Dia_Fin);

    // Validamos que no se exceda el limite de horas por materia
    if (Horas > 5) continue;

    // Comparar con las horas registradas
    if (horas_registradas[Materia] + Horas > 5) continue;
    
    cout << "Materia: " << Materia << endl;
    cout << "Horas actuales: " << horas_registradas[Materia] << endl;
    cout << "Horas a registrar: " << Horas << endl;


    // Obtener los dias que se van a registrar
    vector<string> DiasSemana = {"Lunes", "Martes", "Miércoles", "Jueves", "Viernes"};
    vector<string> Dias;
    int Dia_Inicio_Index = distance(DiasSemana.begin(), find(DiasSemana.begin(), DiasSemana.end(), Dia_Inicio));
    int Dia_Fin_Index = distance(DiasSemana.begin(), find(DiasSemana.begin(), DiasSemana.end(), Dia_Fin));
    for (int i = Dia_Inicio_Index; i <= Dia_Fin_Index; i++)
    {
      Dias.push_back(DiasSemana[i]);
    }

    // Obtener las horas que se van a registrar
    vector<string> HorasDia = {"7:00", "8:00", "9:00", "10:00", "11:00", "12:00", "13:00"};
    vector<string> HorasARegistrar;
    int Hora_Inicio_Index = distance(HorasDia.begin(), find(HorasDia.begin(), HorasDia.end(), Hora_Inicio));
    int Hora_Fin_Index = distance(HorasDia.begin(), find(HorasDia.begin(), HorasDia.end(), Hora_Fin));
    for (int i = Hora_Inicio_Index; i <= Hora_Fin_Index; i++)
    {
      HorasARegistrar.push_back(HorasDia[i]);
    }

    bool aula_disponible = false;

    // Validar que el aula este disponible
    if (Aula == "54 A") 
    {
      // verificar con las horas y dias
      for (int i = 0; i < Dias.size(); i++)
      {
        for (int j = 0; j < HorasARegistrar.size(); j++)
        {
          if (horario_aula_54_a[Dias[i]][HorasARegistrar[j]] == 0)
          {
            aula_disponible = true;
          }
          else
          {
            // si no esta disponible, no registrar las horas
            break;
          }
        }
      }  
      if (aula_disponible)
      {
        // registrar las horas
        for (int i = 0; i < Dias.size(); i++)
        {
          for (int j = 0; j < HorasARegistrar.size(); j++)
          {
            horario_aula_54_a[Dias[i]][HorasARegistrar[j]] = stoi(ID_Individuo);
          }
        }
        // registrar las horas en el mapa de horas registradas
        horas_registradas[Materia] += Horas;
      }
    }

    if (Aula == "54 C") 
    {
      // verificar con las horas y dias
      for (int i = 0; i < Dias.size(); i++)
      {
        for (int j = 0; j < HorasARegistrar.size(); j++)
        {
          if (horario_aula_54_c[Dias[i]][HorasARegistrar[j]] == 0)
          {
            aula_disponible = true;
          }
          else
          {
            // si no esta disponible, no registrar las horas
            break;
          }
        }
      }  
      if (aula_disponible)
      {
        // registrar las horas
        for (int i = 0; i < Dias.size(); i++)
        {
          for (int j = 0; j < HorasARegistrar.size(); j++)
          {
            horario_aula_54_c[Dias[i]][HorasARegistrar[j]] = stoi(ID_Individuo);
          }
        }
        // registrar las horas en el mapa de horas registradas
        horas_registradas[Materia] += Horas;
      }
    }

    if (Aula == "54 F") 
    {
      // verificar con las horas y dias
      for (int i = 0; i < Dias.size(); i++)
      {
        for (int j = 0; j < HorasARegistrar.size(); j++)
        {
          if (horario_aula_54_f[Dias[i]][HorasARegistrar[j]] == 0)
          {
            aula_disponible = true;
          }
          else
          {
            // si no esta disponible, no registrar las horas
            break;
          }
        }
      }  
      if (aula_disponible)
      {
        // registrar las horas
        for (int i = 0; i < Dias.size(); i++)
        {
          for (int j = 0; j < HorasARegistrar.size(); j++)
          {
            horario_aula_54_f[Dias[i]][HorasARegistrar[j]] = stoi(ID_Individuo);
          }
        }
        // registrar las horas en el mapa de horas registradas
        horas_registradas[Materia] += Horas;
      }
    }

    if (Aula == "54 G") 
    {
      // verificar con las horas y dias
      for (int i = 0; i < Dias.size(); i++)
      {
        for (int j = 0; j < HorasARegistrar.size(); j++)
        {
          if (horario_aula_54_g[Dias[i]][HorasARegistrar[j]] == 0)
          {
            aula_disponible = true;
          }
          else
          {
            // si no esta disponible, no registrar las horas
            break;
          }
        }
      }  
      if (aula_disponible)
      {
        // registrar las horas
        for (int i = 0; i < Dias.size(); i++)
        {
          for (int j = 0; j < HorasARegistrar.size(); j++)
          {
            horario_aula_54_g[Dias[i]][HorasARegistrar[j]] = stoi(ID_Individuo);
          }
        }
        // registrar las horas en el mapa de horas registradas
        horas_registradas[Materia] += Horas;
      }
    }

    if (Aula == "54 H") 
    {
      // verificar con las horas y dias
      for (int i = 0; i < Dias.size(); i++)
      {
        for (int j = 0; j < HorasARegistrar.size(); j++)
        {
          if (horario_aula_54_h[Dias[i]][HorasARegistrar[j]] == 0)
          {
            aula_disponible = true;
          }
          else
          {
            // si no esta disponible, no registrar las horas
            break;
          }
        }
      }  
      if (aula_disponible)
      {
        // registrar las horas
        for (int i = 0; i < Dias.size(); i++)
        {
          for (int j = 0; j < HorasARegistrar.size(); j++)
          {
            horario_aula_54_h[Dias[i]][HorasARegistrar[j]] = stoi(ID_Individuo);
          }
        }
        // registrar las horas en el mapa de horas registradas
        horas_registradas[Materia] += Horas;
      }
    }

    if (Aula == "61 LAB") 
    {
      // verificar con las horas y dias
      for (int i = 0; i < Dias.size(); i++)
      {
        for (int j = 0; j < HorasARegistrar.size(); j++)
        {
          if (horario_aula_61_lab[Dias[i]][HorasARegistrar[j]] == 0)
          {
            aula_disponible = true;
          }
          else
          {
            // si no esta disponible, no registrar las horas
            break;
          }
        }
      }  
      if (aula_disponible)
      {
        // registrar las horas
        for (int i = 0; i < Dias.size(); i++)
        {
          for (int j = 0; j < HorasARegistrar.size(); j++)
          {
            horario_aula_61_lab[Dias[i]][HorasARegistrar[j]] = stoi(ID_Individuo);
          }
        }
        // registrar las horas en el mapa de horas registradas
        horas_registradas[Materia] += Horas;
      }
    }

    if (Aula == "203 LAB") 
    {
      // verificar con las horas y dias
      for (int i = 0; i < Dias.size(); i++)
      {
        for (int j = 0; j < HorasARegistrar.size(); j++)
        {
          if (horario_aula_203_lab[Dias[i]][HorasARegistrar[j]] == 0)
          {
            aula_disponible = true;
          }
          else
          {
            // si no esta disponible, no registrar las horas
            break;
          }
        }
      }  
      if (aula_disponible)
      {
        // registrar las horas
        for (int i = 0; i < Dias.size(); i++)
        {
          for (int j = 0; j < HorasARegistrar.size(); j++)
          {
            horario_aula_203_lab[Dias[i]][HorasARegistrar[j]] = stoi(ID_Individuo);
          }
        }
        // registrar las horas en el mapa de horas registradas
        horas_registradas[Materia] += Horas;
      }
    }

    if (Aula == "204 LAB") 
    {
      // verificar con las horas y dias
      for (int i = 0; i < Dias.size(); i++)
      {
        for (int j = 0; j < HorasARegistrar.size(); j++)
        { 
          if (horario_aula_204_lab[Dias[i]][HorasARegistrar[j]] == 0)
          {
            aula_disponible = true;
          }
          else
          {
            // si no esta disponible, no registrar las horas
            break;
          }
        }
      }
      if (aula_disponible)
      {
        // registrar las horas
        for (int i = 0; i < Dias.size(); i++)
        { 
          for (int j = 0; j < HorasARegistrar.size(); j++)
          {
            horario_aula_204_lab[Dias[i]][HorasARegistrar[j]] = stoi(ID_Individuo);
          }
        }
        // registrar las horas en el mapa de horas registradas
        horas_registradas[Materia] += Horas; 
      }
    }

    if (Aula == "1 AUD") 
    {
      // verificar con las horas y dias
      for (int i = 0; i < Dias.size(); i++)
      { 
        for (int j = 0; j < HorasARegistrar.size(); j++)
        {
          if (horario_aula_1_aud[Dias[i]][HorasARegistrar[j]] == 0)
          { 
            aula_disponible = true;
          }
          else
          { 
            // si no esta disponible, no registrar las horas
            break;
          }
        }
      }
      if (aula_disponible)
      { 
        // registrar las horas
        for (int i = 0; i < Dias.size(); i++)
        { 
          for (int j = 0; j < HorasARegistrar.size(); j++)
          {
            horario_aula_1_aud[Dias[i]][HorasARegistrar[j]] = stoi(ID_Individuo);
          }
        }
        // registrar las horas en el mapa de horas registradas
        horas_registradas[Materia] += Horas; 
      }
    }

    // Si el aula no esta disponible, no registrar el individuo
    if (!aula_disponible) 
    {
      //! IMPORTANTE: Si el aula no esta disponible, no registrar el individuo
      //! EN CASO DE QUE EL INDIVIDUO SE REGISTRE, SE DEBE AGREGA A LA SIGUIENTE
      //! POBLACION, EN CASO DE QUE NO SE REGISTRE, SE DEBE GENERAR UN NUEVO
      //! INDIVIDUO A PARTIR DE MUTAR ESE INDIVIDUO
      cout << "Aula no disponible" << endl;
      continue;
    }
  
  }

  // Mostrar las horas registradas por materia
  for (auto const &x : horas_registradas)
  {
    cout << x.first << " => " << x.second << endl;
  }

  // Recorrer las horas registradas por materia
  for (auto const &x : horas_registradas)
  {
    if (x.second < 5)
    {
      solucion_encontrada = false;
      break;
    }
  }

  
}

void menu()
{
  cout << "1. Ejecutar" << endl;
  cout << "2. Salir" << endl;
}

int main()
{

  // Set up random number generation
  srand(static_cast<unsigned>(time(0)));

  // MODULOS ///////////////////////////////////////////////////////////////////////

  // Modulo1 => ID del curso/materia
  vector<vector<string>> Modulo1 = {
      {"LC1-1", "FEC-2", "CD-3", "AS-4", "CB-5"},
      {"LC3-6", "ECA-7", "IA-8", "AL-9", "EDP-10", "RB-11"},
      {"OI-12", "AU-13", "AID-14", "LI-15", "BD-17"},
      {"AU2-18", "DMD-19", "MH-20", "ESI-21", "PI-22", "LE-23", "RE1-24"},
      {"TSI-25", "SI1-26", "SW-27", "PA-28", "SIS-29", "MD-30"}};

  // Modulo2 => Grupo
  vector<string> Modulo2 = {"1a", "3a", "5a", "7a", "9a"};

  // Modulo3 => Dia de inicio del curso
  vector<string> Modulo3 = {"Lunes", "Martes", "Miércoles"};

  // Modulo4 => Hora de inicio del curso
  vector<string> Modulo4 = {"7:00", "8:00", "9:00", "10:00", "11:00", "12:00", "13:00"};

  // Modulo5 => Dia de fin del curso
  vector<string> Modulo5 = {"Jueves", "Viernes"};

  // Modulo6 => Hora de fin del curso
  vector<string> Modulo6 = {"8:00", "9:00", "10:00", "11:00", "12:00", "13:00", "14:00"};

  // Modulo7 => Tipo de aula
  vector<string> Modulo7 = {"Aula", "Lab", "Auditorio"};

  // Modulo8 => ID del aula
  vector<vector<string>> Modulo8 = {
      {"54 A", "54 C", "54 F", "54 G", "54 H"},
      {"61 LAB", "203 LAB", "204 LAB"},
      {"1 AUD"}};

  // Modulo9 => ID del individuo
  int Modulo9 = 0;

  /////////////////////////////////////////////////////////////////////////////

  // HORAS REGISTRADAS POR MATERIA ///////////////////////////////////////////

  unordered_map<string, int> horas_registradas = {
      {"LC1-1", 0},
      {"FEC-2", 0},
      {"CD-3", 0},
      {"AS-4", 0},
      {"CB-5", 0},
      {"LC3-6", 0},
      {"ECA-7", 0},
      {"IA-8", 0},
      {"AL-9", 0},
      {"EDP-10", 0},
      {"RB-11", 0},
      {"OI-12", 0},
      {"AU-13", 0},
      {"AID-14", 0},
      {"LI-15", 0},
      {"ED-16", 0},
      {"BD-17", 0},
      {"AU2-18", 0},
      {"DMD-19", 0},
      {"MH-20", 0},
      {"ESI-21", 0},
      {"PI-22", 0},
      {"LE-23", 0},
      {"RE1-24", 0},
      {"TSI-25", 0},
      {"SI1-26", 0},
      {"SW-27", 0},
      {"PA-28", 0},
      {"SIS-29", 0},
      {"MD-30", 0}};

  /////////////////////////////////////////////////////////////////////////////

  // HORARIOS REGISTRADOS POR SALON //////////////////////////////////////////

  // HORARIO DE AULA 54 A

  unordered_map<string, unordered_map<string, int>> horario_aula_54_a = {
      {"Lunes",     {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Martes",    {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Miércoles", {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Jueves",    {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Viernes",   {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}}};

  // HORARIO DE AULA 54 C

  unordered_map<string, unordered_map<string, int>> horario_aula_54_c = {
      {"Lunes",     {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Martes",    {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Miércoles", {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Jueves",    {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Viernes",   {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}}};

  // HORARIO DE AULA 54 F

  unordered_map<string, unordered_map<string, int>> horario_aula_54_f = {
      {"Lunes",     {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Martes",    {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Miércoles", {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Jueves",    {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Viernes",   {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}}};

  // HORARIO DE AULA 54 G

  unordered_map<string, unordered_map<string, int>> horario_aula_54_g = {
      {"Lunes",     {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Martes",    {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Miércoles", {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Jueves",    {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Viernes",   {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}}};

  // HORARIO DE AULA 54 H 

  unordered_map<string, unordered_map<string, int>> horario_aula_54_h = {
      {"Lunes",     {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Martes",    {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Miércoles", {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Jueves",    {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Viernes",   {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}}};

  // HORARIO DE AULA 61 LAB

  unordered_map<string, unordered_map<string, int>> horario_aula_61_lab = {
      {"Lunes",     {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Martes",    {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Miércoles", {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Jueves",    {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Viernes",   {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}}};

  // HORARIO DE AULA 203 LAB

  unordered_map<string, unordered_map<string, int>> horario_aula_203_lab = {
      {"Lunes",     {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Martes",    {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Miércoles", {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Jueves",    {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Viernes",   {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}}};

  // HORARIO DE AULA 204 LAB

  unordered_map<string, unordered_map<string, int>> horario_aula_204_lab = {
      {"Lunes",     {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Martes",    {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Miércoles", {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Jueves",    {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Viernes",   {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}}};

  // HORARIO DE AULA 1 AUD

  unordered_map<string, unordered_map<string, int>> horario_aula_1_aud = {
      {"Lunes",     {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Martes",    {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Miércoles", {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Jueves",    {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}},
      {"Viernes",   {{"7:00", 0}, {"8:00", 0}, {"9:00", 0}, {"10:00", 0}, {"11:00", 0}, {"12:00", 0}, {"13:00", 0}}}};

  /////////////////////////////////////////////////////////////////////////////

  // POBLACION INICIAL ////////////////////////////////////////////////////////

  vector<vector<string>> PoblacionInicial;

  /////////////////////////////////////////////////////////////////////////////

  // LOOP PRINCIPAL ///////////////////////////////////////////////////////////

  int opcion = 0;

  while (opcion != 2)
  {
    menu();
    cin >> opcion;

    switch (opcion)
    {
    case 1:
    {

      // Generamos la poblacion inicial
      for (int i = 0; i < 400; i++)
      {
        PoblacionInicial.push_back(GenerarIndividuo(Modulo1, Modulo2, Modulo3, Modulo4, Modulo5, Modulo6, Modulo7, Modulo8, Modulo9));
        Modulo9++;
      }

      // Mostramos la poblacion inicial
      for (int i = 0; i < PoblacionInicial.size(); i++)
      {
        cout << "Individuo " << i + 1 << ": ";
        for (int j = 0; j < PoblacionInicial[i].size(); j++)
        {
          cout << PoblacionInicial[i][j] << " ";
        }
        cout << endl;
      }

      int max_iteraciones = 100;
      bool solucion_encontrada = false;
      vector<vector<string>> PosibleHorario;

      // for (int i = 0; i < max_iteraciones; i++)
      // {

        // Calcular posible horario (AQUI MISMO SE MUTAN LOS INDIVIDUOS Y SE GENERA LA NUEVA POBLACION) 
        calcularPosibleHorario(PosibleHorario, PoblacionInicial, horas_registradas, horario_aula_54_a, horario_aula_54_c, horario_aula_54_f, horario_aula_54_g, horario_aula_54_h, horario_aula_61_lab, horario_aula_203_lab, horario_aula_204_lab, horario_aula_1_aud, solucion_encontrada);

        if (solucion_encontrada) 
        {
          cout << "Solucion encontrada" << endl;
        }
        else
        {
          cout << "Solucion no encontrada" << endl;
        }

      // }

      break;
    }
    case 2:
    {
      cout << "Saliendo..." << endl;
      break;
    }
    default:
    {
      cout << "Opcion invalida" << endl;
      break;
    }
    }
  }

  return 0;
}