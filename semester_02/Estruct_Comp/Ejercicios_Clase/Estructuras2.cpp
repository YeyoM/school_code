#include <iostream>
#include <string.h>

using namespace std;

// la siguiente estructura la podemos
// reutilizar en otras estructuras
struct info_dir {
  string direccion;
  string ciudad;
  string provincia;
  long int codigo_postal;
};

struct empleados {
  string nombre;
  struct info_dir domicilio_emp;
  double salario;
};

struct clientes {
  string nombre;
  struct info_dir domicilio_cli;
  double saldo;
};

int main() {
  struct empleados empleado1, empleado2;

  // asignacion de valores
  empleado1.nombre = "Diego Moreno";
  empleado1.salario = 20000;

  empleado1.domicilio_emp.ciudad = "Ciudad";
  empleado1.domicilio_emp.codigo_postal = 12233;
  empleado1.domicilio_emp.direccion = "Calle #num";
  empleado1.domicilio_emp.provincia = "Provincia 27";

  // imprimir algunos valores
  cout << empleado1.nombre << endl;
  cout << empleado1.salario <<endl;

  return 0;
}
