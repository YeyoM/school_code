#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * La función "calcularPosibleHorario" procesa una población inicial dada de horarios para generar
 * un posible horario basado en restricciones específicas y la disponibilidad de aulas. Considera
 * varios parámetros y actualiza las estructuras de datos del horario en consecuencia.
 * 
 * @param PosibleHorario Un vector de vectores de cadenas que representa el posible horario resultante.
 * Cada vector interno corresponde a un horario individual y contiene detalles como asignatura, grado,
 * días, horas, tipo de aula y aula seleccionada.
 * @param PoblacionInicial Un vector de vectores de cadenas que representa la población inicial de horarios.
 * Cada vector interno contiene detalles de un horario individual, similar a PosibleHorario.
 * @param horas_registradas Un unordered_map<string, int> que almacena las horas totales registradas para cada asignatura.
 * @param horario_aula_54_a, horario_aula_54_c, horario_aula_54_f, horario_aula_54_g, horario_aula_54_h,
 * horario_aula_61_lab, horario_aula_203_lab, horario_aula_204_lab, horario_aula_1_aud:
 * Unordered_maps que almacenan la disponibilidad de horarios para diferentes aulas y sus respectivas horas.
 * @param solucion_encontrada Una variable booleana que indica si se ha encontrado una solución.
 * @param SiguintePoblacion Un vector de vectores de cadenas que representa la próxima población de horarios.
 * @param Modulo1, Modulo2, Modulo3, Modulo4, Modulo5, Modulo6, Modulo7, Modulo8:
 * Varios parámetros que representan los grados de las asignaturas, los módulos de las asignaturas, los días de la semana,
 * las horas de inicio, los días disponibles, las franjas horarias disponibles, los tipos de aulas y las opciones para cada módulo, respectivamente.
 * @param horas_totales Un entero que representa las horas totales programadas en el horario generado.
 */
void calcularPosibleHorario(vector<vector<string>> &PosibleHorario, vector<vector<string>> &PoblacionInicial, unordered_map<string, int> &horas_registradas,
                            unordered_map<string, unordered_map<string, int>> &horario_aula_54_a, unordered_map<string, unordered_map<string, int>> &horario_aula_54_c,
                            unordered_map<string, unordered_map<string, int>> &horario_aula_54_f, unordered_map<string, unordered_map<string, int>> &horario_aula_54_g,
                            unordered_map<string, unordered_map<string, int>> &horario_aula_54_h, unordered_map<string, unordered_map<string, int>> &horario_aula_61_lab,
                            unordered_map<string, unordered_map<string, int>> &horario_aula_203_lab, unordered_map<string, unordered_map<string, int>> &horario_aula_204_lab,
                            unordered_map<string, unordered_map<string, int>> &horario_aula_1_aud, bool &solucion_encontrada, vector<vector<string>> &SiguintePoblacion, const vector<vector<string>> &Modulo1,
                            const vector<string> &Modulo2, const vector<string> &Modulo3, const vector<string> &Modulo4, const vector<string> &Modulo5, const vector<string> &Modulo6,
                            const vector<string> &Modulo7, const vector<vector<string>> &Modulo8, int &horas_totales)
{

  vector<vector<string>> IndividuosNoRegistrados;
  vector<vector<string>> IndividuosRegistrados;
  
  for (size_t i = 0; i < PoblacionInicial.size(); i++)
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
    if (horas_registradas[Materia] + Horas > 5)
    {
      // Mutar al individuo 
      mutarIndividuo(Individuo, Modulo1, Modulo2, Modulo3, Modulo4, Modulo5, Modulo6, Modulo7, Modulo8);

      // agregar el individuo mutado a la siguiente poblacion
      IndividuosNoRegistrados.push_back(Individuo);

      continue;
    }


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
      for (size_t i = 0; i < Dias.size(); i++)
      {
        for (size_t j = 0; j < HorasARegistrar.size() - 1; j++)
        {
          if (horario_aula_54_a[Dias[i]][HorasARegistrar[j]] == 0)
          {
            aula_disponible = true;
          }
          else
          {
            // si no esta disponible, no registrar las horas
            aula_disponible = false;
            break;
          }
        }
      }  
      if (aula_disponible)
      {
        // registrar las horas
        for (size_t i = 0; i < Dias.size(); i++)
        {
          for (size_t j = 0; j < HorasARegistrar.size() - 1; j++)
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
      for (size_t i = 0; i < Dias.size(); i++)
      {
        for (size_t j = 0; j < HorasARegistrar.size() - 1; j++)
        {
          if (horario_aula_54_c[Dias[i]][HorasARegistrar[j]] == 0)
          {
            aula_disponible = true;
          }
          else
          {
            // si no esta disponible, no registrar las horas
            aula_disponible = false;
            break;
          }
        }
      }  
      if (aula_disponible)
      {
        // registrar las horas
        for (size_t i = 0; i < Dias.size(); i++)
        {
          for (size_t j = 0; j < HorasARegistrar.size() - 1; j++)
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
      for (size_t i = 0; i < Dias.size(); i++)
      {
        for (size_t j = 0; j < HorasARegistrar.size() - 1; j++)
        {
          if (horario_aula_54_f[Dias[i]][HorasARegistrar[j]] == 0)
          {
            aula_disponible = true;
          }
          else
          {
            // si no esta disponible, no registrar las horas
            aula_disponible = false;
            break;
          }
        }
      }  
      if (aula_disponible)
      {
        // registrar las horas
        for (size_t i = 0; i < Dias.size(); i++)
        {
          for (size_t j = 0; j < HorasARegistrar.size() - 1; j++)
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
      for (size_t i = 0; i < Dias.size(); i++)
      {
        for (size_t j = 0; j < HorasARegistrar.size() - 1; j++)
        {
          if (horario_aula_54_g[Dias[i]][HorasARegistrar[j]] == 0)
          {
            aula_disponible = true;
          }
          else
          {
            // si no esta disponible, no registrar las horas
            aula_disponible = false;
            break;
          }
        }
      }  
      if (aula_disponible)
      {
        // registrar las horas
        for (size_t i = 0; i < Dias.size(); i++)
        {
          for (size_t j = 0; j < HorasARegistrar.size() - 1; j++)
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
      for (size_t i = 0; i < Dias.size(); i++)
      {
        for (size_t j = 0; j < HorasARegistrar.size() - 1; j++)
        {
          if (horario_aula_54_h[Dias[i]][HorasARegistrar[j]] == 0)
          {
            aula_disponible = true;
          }
          else
          {
            // si no esta disponible, no registrar las horas
            aula_disponible = false;
            break;
          }
        }
      }  
      if (aula_disponible)
      {
        // registrar las horas
        for (size_t i = 0; i < Dias.size(); i++)
        {
          for (size_t j = 0; j < HorasARegistrar.size() - 1; j++)
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
      for (size_t i = 0; i < Dias.size(); i++)
      {
        for (size_t j = 0; j < HorasARegistrar.size() - 1; j++)
        {
          if (horario_aula_61_lab[Dias[i]][HorasARegistrar[j]] == 0)
          {
            aula_disponible = true;
          }
          else
          {
            // si no esta disponible, no registrar las horas
            aula_disponible = false;
            break;
          }
        }
      }  
      if (aula_disponible)
      {
        // registrar las horas
        for (size_t i = 0; i < Dias.size(); i++)
        {
          for (size_t j = 0; j < HorasARegistrar.size() - 1; j++)
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
      for (size_t i = 0; i < Dias.size(); i++)
      {
        for (size_t j = 0; j < HorasARegistrar.size() - 1; j++)
        {
          if (horario_aula_203_lab[Dias[i]][HorasARegistrar[j]] == 0)
          {
            aula_disponible = true;
          }
          else
          {
            // si no esta disponible, no registrar las horas
            aula_disponible = false;
            break;
          }
        }
      }  
      if (aula_disponible)
      {
        // registrar las horas
        for (size_t i = 0; i < Dias.size(); i++)
        {
          for (size_t j = 0; j < HorasARegistrar.size() - 1; j++)
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
      for (size_t i = 0; i < Dias.size(); i++)
      {
        for (size_t j = 0; j < HorasARegistrar.size() - 1; j++)
        { 
          if (horario_aula_204_lab[Dias[i]][HorasARegistrar[j]] == 0)
          {
            aula_disponible = true;
          }
          else
          {
            // si no esta disponible, no registrar las horas
            aula_disponible = false;
            break;
          }
        }
      }
      if (aula_disponible)
      {
        // registrar las horas
        for (size_t i = 0; i < Dias.size(); i++)
        { 
          for (size_t j = 0; j < HorasARegistrar.size() - 1; j++)
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
      for (size_t i = 0; i < Dias.size(); i++)
      { 
        for (size_t j = 0; j < HorasARegistrar.size() - 1; j++)
        {
          if (horario_aula_1_aud[Dias[i]][HorasARegistrar[j]] == 0)
          { 
            aula_disponible = true;
          }
          else
          { 
            // si no esta disponible, no registrar las horas
            aula_disponible = false;
            break;
          }
        }
      }
      if (aula_disponible)
      { 
        // registrar las horas
        for (size_t i = 0; i < Dias.size(); i++)
        { 
          for (size_t j = 0; j < HorasARegistrar.size() - 1; j++)
          {
            horario_aula_1_aud[Dias[i]][HorasARegistrar[j]] = stoi(ID_Individuo);
          }
        }
        // registrar las horas en el mapa de horas registradas
        horas_registradas[Materia] += Horas; 
      }
    }


    if (aula_disponible)
    {
      // registrar el individuo
      PosibleHorario.push_back(Individuo);
      IndividuosRegistrados.push_back(Individuo);
    }

    // Si el aula no esta disponible, no registrar el individuo
    if (!aula_disponible) 
    {
      //! IMPORTANTE: Si el aula no esta disponible, no registrar el individuo
      //! EN CASO DE QUE EL INDIVIDUO SE REGISTRE, SE DEBE AGREGA A LA SIGUIENTE
      //! POBLACION, EN CASO DE QUE NO SE REGISTRE, SE DEBE GENERAR UN NUEVO
      //! INDIVIDUO A PARTIR DE MUTAR ESE INDIVIDUO

      if (IndividuosRegistrados.size() > 0)
      {
        // Tomamos un elemento al azar de los elementos registrados y lo cruzamos con el individuo actual, 
        // luego mutamos el individuo resultante y lo agregamos al vector de individuos no registrados

        int index_individuo_cruzado = rand() % IndividuosRegistrados.size();

        vector<string> IndividuoCruzado = IndividuosRegistrados[index_individuo_cruzado];
        IndividuoCruzado[0] = Individuo[0];
        IndividuoCruzado[1] = Individuo[1];

        // mutar el individuo cruzado
        mutarIndividuo(IndividuoCruzado, Modulo1, Modulo2, Modulo3, Modulo4, Modulo5, Modulo6, Modulo7, Modulo8);

        // agregar el individuo mutado a la siguiente poblacion
        IndividuosNoRegistrados.push_back(IndividuoCruzado);
      }

      else 
      {
        // mutar el individuo
        mutarIndividuo(Individuo, Modulo1, Modulo2, Modulo3, Modulo4, Modulo5, Modulo6, Modulo7, Modulo8);

        // agregar el individuo mutado a la siguiente poblacion
        IndividuosNoRegistrados.push_back(Individuo);
      }

    }
  
  }

  // cout << "Individuos registrados: " << IndividuosRegistrados.size() << endl;
  // cout << "Individuos no registrados: " << IndividuosNoRegistrados.size() << endl;

  // Agregar los individuos registrados a la siguiente poblacion
  for (size_t i = 0; i < IndividuosRegistrados.size(); i++)
  {
    SiguintePoblacion.push_back(IndividuosRegistrados[i]);
  }

    // Agregar los individuos no registrados a la siguiente poblacion
  for (size_t i = 0; i < IndividuosNoRegistrados.size(); i++)
  {
    SiguintePoblacion.push_back(IndividuosNoRegistrados[i]);
  }

  // mutamos 5 individuos de la siguiente poblacion
  for (size_t i = 0; i < 50; i++)
  {
    int index = rand() % SiguintePoblacion.size();
    mutarIndividuo(SiguintePoblacion[index], Modulo1, Modulo2, Modulo3, Modulo4, Modulo5, Modulo6, Modulo7, Modulo8);
  }

  random_shuffle(SiguintePoblacion.begin(), SiguintePoblacion.end());

  // Mostrar las horas registradas por materia y calcular las horas totales
  for (auto const &x : horas_registradas)
  {
    // cout << x.first << " => " << x.second << endl;
    horas_totales += x.second;
  }

  cout << "Horas totales: " << horas_totales << endl;

  // Recorrer las horas registradas por materia
  for (auto const &x : horas_registradas)
  {
    if (x.second < 5)
    {
      solucion_encontrada = false;
      break;
    }
  }

  if (horas_totales == 150)
  {
    solucion_encontrada = true;
  }
  
}