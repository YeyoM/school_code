// objetivo: estructura union
// febrero 2022
// elv

// declaracion de lbrerias
#include <iostream>

using namespace std;

struct alumno
{
  int id;
  string nombre;
  int edad;
  float colegiatura;
  int tipo; // alumno que es 1)Deportista 2) Becario
  float colegiatura_mensual_final;
  float colegiatura_anual_final;
};

union datos_complementarios
{
  char deporte[50];
  float porcentaje_beca;
};

void imprimirDatos(alumno alumnos[], datos_complementarios datos_comp_alum[], int num_alumnos);
void calcularColegiatura(alumno alumnos[], datos_complementarios datos_comp_alum[], int num_alumnos);
void ingresarDatos(alumno alumnos[], datos_complementarios datos_comp_alum[], int num_alumnos);

int num_alumnos;

int main() {
  cout << "Ingrese el numero de alumnos con los que vamos a trabajar: " << endl;
  cin >> num_alumnos;
  // declaracion de variables
  struct alumno alumnos[num_alumnos];
  union datos_complementarios datos_comp_alum[num_alumnos];
  // Captura los datos del alumno
  ingresarDatos(alumnos, datos_comp_alum, num_alumnos);

  // calcular colegiatura
  calcularColegiatura(alumnos, datos_comp_alum, num_alumnos);

  // imprime datos
  imprimirDatos(alumnos, datos_comp_alum, num_alumnos);

  return 0;
}

void imprimirDatos(alumno alumnos[], datos_complementarios datos_comp_alum[], int num_alumnos) {
  for (int i = 0; i < num_alumnos; i++) {
    cout << "\n\n----------- Datos del alumno -------------";
    cout << "\n ID del alumno " << i + 1 << ": ";
    cout << alumnos[i].id;
    cout << "\n Nombre del alumno " << i + 1 << ": ";
    cout << alumnos[i].nombre;
    cout << "\n Tipo del alumno ([1]Deportista [2] Becario): " << alumnos[i].tipo;
    if (alumnos[i].tipo == 1) {
      cout << "\n El nombre del deporte "
           << "del alumno es: " << datos_comp_alum[i].deporte;
    }
    else {
      cout << "\n El porcentaje de la beca "
           << "del alumno es: " << datos_comp_alum[i].porcentaje_beca << "%";
    }
    cout << "\n Total a pagar mensualmente: " << alumnos[i].colegiatura_mensual_final;
      fflush(stdin);
    cout << "\n Total a pagar anualmente: " << alumnos[i].colegiatura_anual_final;
      fflush(stdin);

  }
}

void calcularColegiatura(alumno alumnos[], datos_complementarios datos_comp_alum[], int num_alumnos) {
  for(int i = 0; i < num_alumnos; i++) {
    if (alumnos[i].tipo == 2) {
      alumnos[i].colegiatura_mensual_final = alumnos[i].colegiatura - (alumnos[i].colegiatura * (datos_comp_alum[i].porcentaje_beca * 0.01));
      fflush(stdin);
      alumnos[i].colegiatura_anual_final = alumnos[i].colegiatura_mensual_final * 12.0;
      fflush(stdin);
    } else if (alumnos[i].tipo == 1) {
      alumnos[i].colegiatura_mensual_final = alumnos[i].colegiatura;
      fflush(stdin);
      alumnos[i].colegiatura_anual_final = alumnos[i].colegiatura_mensual_final * 12.0;
      fflush(stdin);
    }
  }
}

void ingresarDatos(alumno alumnos[], datos_complementarios datos_comp_alum[], int num_alumnos) {
  for (int i = 0; i < num_alumnos; i++) {
    cout << "\n Datos del alumno\n";
    fflush(stdin);
    cout << "\n Dame el id del alumno " << i + 1 << ":  ";
    cin >> alumnos[i].id;
    fflush(stdin);
    cout << "\n Dame el nombre del alumno " << i + 1 << ":  ";
    getline(cin, alumnos[i].nombre);
    fflush(stdin);
    cout << "\n Ingresa la edad del alumno " << i + 1 << ":  ";
    cin >> alumnos[i].edad;
    fflush(stdin);
    cout << "\n Ingresa el monto a pagar de la colegiatura del alumno " << i + 1 << " (mensual): ";
    cin >> alumnos[i].colegiatura;
    fflush(stdin);
    cout << "\n tipo del alumno " << i + 1 << " ([1]Deportista [2]Becario) :  ";
    cin >> alumnos[i].tipo;
    fflush(stdin);
    if (alumnos[i].tipo == 1) {
      cout << "\n Dame el nombre del deporte "
           << "del alumno " << i + 1 << ":  ";
      cin >> datos_comp_alum[i].deporte;
      fflush(stdin);
    }
    else {
      cout << "\n Dame el porcentaje de la beca "
           << "del alumno " << i + 1 << ":  ";
      cin >> datos_comp_alum[i].porcentaje_beca;
      fflush(stdin);
    }
  }
}