#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdlib> // For rand and srand
#include <ctime>   // For time

#include "calcularHoras.h"
#include "generarIndividuo.h"
#include "mutarIndividuo.h"
#include "calcularPosibleHorario.h"

using namespace std;

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
      {"OI-12", "AU-13", "AID-14", "LI-15", "ED-16", "BD-17"},
      {"AU2-18", "DMD-19", "MH-20", "ESI-21", "PI-22", "LE-23", "RE1-24"},
      {"TSI-25", "SI1-26", "SW-27", "PA-28", "SIS-29", "MD-30"}};

  // Modulo2 => Grupo
  vector<string> Modulo2 = {"1a", "3a", "5a", "7a", "9a"};

  // Modulo3 => Dia de inicio del curso
  vector<string> Modulo3 = {"Lunes", "Martes", "Miércoles", "Jueves", "Viernes"};

  // Modulo4 => Hora de inicio del curso
  vector<string> Modulo4 = {"7:00", "8:00", "9:00", "10:00", "11:00", "12:00", "13:00"};

  // Modulo5 => Dia de fin del curso
  vector<string> Modulo5 = {"Lunes", "Martes", "Miércoles", "Jueves", "Viernes"};

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

  // POBLACION INICIAL ////////////////////////////////////////////////////////

  vector<vector<string>> PoblacionInicial;
  vector<vector<string>> SiguintePoblacion;

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
      for (int i = 0; i < 450; i++)
      {
        PoblacionInicial.push_back(GenerarIndividuo(Modulo1, Modulo2, Modulo3, Modulo4, Modulo5, Modulo6, Modulo7, Modulo8, Modulo9));
        Modulo9++;
      }

      int max_iteraciones = 150;
      bool solucion_encontrada = false;
      vector<vector<string>> PosibleHorario;
      int horas_totales = 0;
      int horas_totales_anterior = 0;

      for (int i = 0; i < max_iteraciones; i++)
      {

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

        cout << "Iteracion " << i + 1 << endl;

        // Calcular posible horario (AQUI MISMO SE MUTAN LOS INDIVIDUOS Y SE GENERA LA NUEVA POBLACION) 
        calcularPosibleHorario(PosibleHorario, PoblacionInicial, horas_registradas, horario_aula_54_a, horario_aula_54_c, horario_aula_54_f, horario_aula_54_g, horario_aula_54_h, horario_aula_61_lab, horario_aula_203_lab, horario_aula_204_lab, horario_aula_1_aud, solucion_encontrada, SiguintePoblacion, Modulo1, Modulo2, Modulo3, Modulo4, Modulo5, Modulo6, Modulo7, Modulo8, horas_totales);

        if (solucion_encontrada) 
        {
          cout << endl;
          cout << "Solucion encontrada!!!" << endl;
          cout << endl;

          // Mostrar un Menu al usuario para insertar la solucion en la base de datos (horarios de aulas)
          // y mostrar el horario de clases
          int opcion_ = 0;

          do {
            
            cout << "Inspeccionar horarios (digite la opcion que desee)" << endl;
            cout << "1. Mostrar los horarios de todas las materias" << endl;
            cout << "2. Mostrar los horarios del aula 54 A" << endl;
            cout << "3. Mostrar los horarios del aula 54 C" << endl;
            cout << "4. Mostrar los horarios del aula 54 F" << endl;
            cout << "5. Mostrar los horarios del aula 54 G" << endl;
            cout << "6. Mostrar los horarios del aula 54 H" << endl;
            cout << "7. Mostrar los horarios del aula 61 LAB" << endl;
            cout << "8. Mostrar los horarios del aula 203 LAB" << endl;
            cout << "9. Mostrar los horarios del aula 204 LAB" << endl;
            cout << "10. Mostrar los horarios del aula 1 AUD" << endl;
            cout << "11. Limpiar la pantalla" << endl;
            cout << "12. Salir" << endl;

            cin >> opcion_;

            switch (opcion_)
            {
            case 1:
            {
              // Mostrar los horarios de todas las materias
              for (size_t i = 0; i < PosibleHorario.size(); i++)
              {
                cout << "ID: " << PosibleHorario[i][0] << " Grupo: " << PosibleHorario[i][1] << " Materia: " << PosibleHorario[i][2] << " Dia: " << PosibleHorario[i][3] << " Hora: " << PosibleHorario[i][4] << " Aula: " << PosibleHorario[i][5] << endl;
              }
              break;
            }
            case 2:
            {
              // Mostrar los horarios del aula 54 A
              for (auto const &x : horario_aula_54_a)
              {
                cout << x.first << " => ";
                for (auto const &y : x.second)
                {
                  cout << y.first << " => " << y.second << " ";
                }
                cout << endl;
              }
              break;
            }
            case 3:
            {
              // Mostrar los horarios del aula 54 C
              for (auto const &x : horario_aula_54_c)
              {
                cout << x.first << " => ";
                for (auto const &y : x.second)
                {
                  cout << y.first << " => " << y.second << " ";
                }
                cout << endl;
              }
              break;
            }
            case 4:
            {
              // Mostrar los horarios del aula 54 F
              for (auto const &x : horario_aula_54_f)
              {
                cout << x.first << " => ";
                for (auto const &y : x.second)
                {
                  cout << y.first << " => " << y.second << " ";
                }
                cout << endl;
              }
              break;
            }
            case 5:
            {
              // Mostrar los horarios del aula 54 G
              for (auto const &x : horario_aula_54_g)
              {
                cout << x.first << " => ";
                for (auto const &y : x.second)
                {
                  cout << y.first << " => " << y.second << " ";
                }
                cout << endl;
              }
              break;
            }
            case 6:
            {
              // Mostrar los horarios del aula 54 H
              for (auto const &x : horario_aula_54_h)
              {
                cout << x.first << " => ";
                for (auto const &y : x.second)
                {
                  cout << y.first << " => " << y.second << " ";
                }
                cout << endl;
              }
              break;
            }
            case 7:
            {
              // Mostrar los horarios del aula 61 LAB
              for (auto const &x : horario_aula_61_lab)
              {
                cout << x.first << " => ";
                for (auto const &y : x.second)
                {
                  cout << y.first << " => " << y.second << " ";
                }
                cout << endl;
              }
              break;
            }
            case 8:
            {
              // Mostrar los horarios del aula 203 LAB
              for (auto const &x : horario_aula_203_lab)
              {
                cout << x.first << " => ";
                for (auto const &y : x.second)
                {
                  cout << y.first << " => " << y.second << " ";
                }
                cout << endl;
              }
              break;
            }
            case 9:
            {
              // Mostrar los horarios del aula 204 LAB
              for (auto const &x : horario_aula_204_lab)
              {
                cout << x.first << " => ";
                for (auto const &y : x.second)
                {
                  cout << y.first << " => " << y.second << " ";
                }
                cout << endl;
              }
              break;
            }
            case 10:
            {
              // Mostrar los horarios del aula 1 AUD
              for (auto const &x : horario_aula_1_aud)
              {
                cout << x.first << " => ";
                for (auto const &y : x.second)
                {
                  cout << y.first << " => " << y.second << " ";
                }
                cout << endl;
              }
              break;
            }
            case 11:
            {
              // Limpiar la pantalla
              system("clear");
              break;
            }
            case 12:
            {
              // Salir
              cout << "Saliendo al menu principal" << endl;
              break;
            }
            default:
            {
              cout << "Opcion invalida" << endl;
              break;
            }
            }

          } while (opcion_ != 12);

          break;
        }

        // en caso de que se encuentre una mejor solucion (horas_totales > horas_totales_anterior), se debe actualizar la poblacion inicial
        if (horas_totales > horas_totales_anterior - 5)
        {
          // actualizar la poblacion inicial
          PoblacionInicial = SiguintePoblacion;
        }

        horas_totales_anterior = horas_totales;
        horas_totales = 0;

        // Limpiar la siguiente poblacion
        SiguintePoblacion.clear();
        cout << endl;

      }

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