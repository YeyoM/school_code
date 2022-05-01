// ESTE ARCHIVO TIENE COMO PROPOSITO EL REPASO PARA EL 
// EXAMEN DE LA UNIDAD 2 DE LA MATERIA DE LENGUAJES
// AUTOR: DIEGO EMILIO MORENO SANCHEZ @YeyoM
// FECHA: 30/04/2022

// TIPOS DE DATOS ====================================
// string
// short
// int
// long
// char
// float
// double
// bool
// decimal

// ARREGLOS =========================================
/*
  -Un arreglo se inicializa de la siguiente manera:
  int[] arreglo = new int[10];

  -Para acceder al elemento de un arreglo:
  arreglo[0] = 10;

  -Para inicializar un arreglo de 2 dimensiones:
  int[,] arreglo = new int[10, 10];

  -Para acceder al elemento de un arreglo de 2 
  dimensiones:
  arreglo[0, 0] = 10;
*/

// POO ==============================================

// Una clase se declara de la siguiente manera:
/*
class NombreClase {
  -Atributos-
  public int atributo1;
  private string atributo2;
  protected bool atributo3;
  -Metodos-
  public void metodo1() {
      <Codigo>
  }
  public void metodo2() {
    <Codigo>
  }
  public void metodo3() {
    <Codigo>
  }
}
*/

// Para crear una clase:
/*
  - Ir al "Explorador de Soluciones" o 
    "Solution Explorer"
  - Dar click derecho en la carpeta del 
    Proyecto
  - Dar click en agregar o add
  - Seleccionar "nuevo elmento" o 
    "new item"
  - Seleccionar "clase" o "class"
*/

// Modificadores de acceso:
/*
  -public: accesible desde cualquier lugar
  -private: accesible solo desde la clase
  -protected: accesible desde la clase y 
    desde las clases que heredan de esta

  (En caso de que no se especifique el modificador
  de acceso, por defecto es pricate)
*/

// Atributos:
/*
  Un atributo o campo es un dato común 
  a todos los objetos de una determinada clase.
  Las variables declaradas dentro de una 
  clase son ejemplos de atributos o campos

  Ejemplo:

  class Persona {
    string nombre; -> atributo
    int edad;      -> atributo 
  }

*/

// Metodos:
/*
  Un método es un bloque de código que contiene 
  una serie de instrucciones para ejecutarse al 
  momento de ser invocados.
  Un método contiene:

  •	Modificador de Acceso (Determina su visibilidad: 
    public, private, protected, etc).
  •	Tipo de dato (Devuelto al finalizar su ejecución)
  •	Identificador (Nombre con el cual se invoca) 
  •	Parámetros (Cero o más variables que recibe el 
    método)

  Ejemplo:

  class Persona {

    string nombre; -> atributo
    int edad;      -> atributo 
    
    -Metodo 1 (Constructor)-
    public Persona(string _nombre, int _edad) {
      nombre = _nombre;
      edad = _edad;
    }

    -Metodo 2-
    public void mostrar() {
      Console.WriteLine("Nombre: " + nombre);
      Console.WriteLine("Edad: " + edad);
    }

  }

*/

// Constructores y Destructores:
/*
  Un constructor es una función especial, 
  que se pone en marcha cuando se crea un 
  objeto de una clase, y se suele usar para 
  dar algunos valores iniciales.

  Un constructor se declara usando el mismo 
  nombre que el de la clase, y sin ningún 
  tipo de retorno. 

  class Persona {

    string nombre; -> atributo
    int edad;      -> atributo 
    
    -Constructor-
    public Persona(string _nombre, int _edad) {
      nombre = _nombre;
      edad = _edad;
    }
  }

  Al igual que existen los "constructores", 
  también podemos crear un "destructor" para 
  una clase, que se encargue de liberar la 
  memoria que pudiéramos haber reservado en 
  nuestra clase.

  Un destructor se declara usando el mismo
  nombre que la clase, y sin ningún tipo de
  retorno.

  Ejemplo:

  class Persona {

    string nombre; -> atributo
    int edad;      -> atributo 
    
    -Constructor-
    public Persona(string _nombre, int _edad) {
      nombre = _nombre;
      edad = _edad;
    }

    -Destructor-
    ~Persona() {
      Console.WriteLine("Destruyendo objeto");
      <Codigo para liberar memoria>
    }
  }

*/

// GETTERS Y SETTERS =================================
/*
  Nos sirven para poder acceder o dar valores 
  a los atributos de las clases, y se utilizan
  de la siguiente manera:

  class Persona {
    protected string nombre; -> atributo (protected)

    -Metodo-
    public string Nombre {
      -GETTER-
      get {
        return nombre;
      }
      -SETTER-
      set {
        nombre = value;
      }
    }
  }

  En el programa Principal:

  Persona persona = new Persona();
  persona.Nombre = "Juan";
  Console.WriteLine("El nombre es: " + persona.Nombre);
*/

// Herencia ==========================================
/*
  Utilizada para crear clases que heredan de otras
  clases. Para poder acceder a los atributos y 
  métodos de la clase padre.
  Se declara de la siguiente manera:

  -Clase Padre-
  class Persona {
    protected string nombre; -> atributo (protected)
    protected int edad;      -> atributo (protected)

    -Metodo Constructor-
    public Persona(string _nombre, int _edad) {
      nombre = _nombre;
      edad = _edad;
    }

    -Metodo-
    public void MostrarDatos(){
      Console.WriteLine("Nombre: " + nombre);
      Console.WriteLine("Edad: " + edad);
    }
  }

  -Clase Hija-
  class Empleado : Persona {
    double sueldo;  -> atributo

    -Metodo Constructor-
    public Empleado(string _nombre, int _edad, double _sueldo) : base(_nombre, _edad) {
      nombre = _nombre;
      edad = _edad;
      sueldo = _sueldo;
    }

    -Metodo-
    public void MostrarSueldo() {
        Console.WriteLine("El sueldo de la persona " + nombre + " es de: $" + sueldo);
    }
  }

*/
