#include <iostream>

using namespace std;



void print(int[], int n);
void shell(int[], int n);

int main()
{
    int total;
    cout << "Enter total elements: " << endl;
    cin >> total;
    int num[total];
    for (int i = 0; i < total; i++)
    {
        cout << "Enter the element [ " << (i + 1) << " ] :" << endl;
        cin >> num[i];
    }
    shell(num, total);
}

void shell(int a[], int n)
{

    int ints, i, aux;
    bool band;
    ints = n; 
    while (ints > 1)   //si el numero de elementos es mayor a 1 entra //segunda entrada ints =5 entonces si entra
    {
        ints = (ints / 2); // dividimos el numero de elementos en 2 ejemplo numero de elementos = 10 , ints = 5 // ints = 2 ya que es entero y no se pone 2.5
        band = true; //se inicializa en true a band //band se vuelve a inicializar en true
        while (band == true) //si band es true que si lo es porque asi se inicializo entra //vuelve a entrar
        {
            band = false;  //se cambia a un valor falso para que solo entre 1 ves aqui
            i = 0; //inicializamos i en 0
            while ((i + ints) <= n)  //mientras i=0 + ints =5 sea menor a n que n=10 entra  //entra de nuevo ya que i=0 + ints=2
            {
            	cout<<i<<endl<<ints;
                if (a[i] > a[i + ints]) // si la primera posicion del arreglo es mayor a la posicion de la mitad del arreglo  
                {
                    aux = a[i]; //aux = la primera posicion del arreglo
                    a[i] = a[i + ints]; //la primera posicion del arreglo es remplazada por la posicion de la mitad del arreglo
                    a[i + ints] = aux; //la posicion de la mitad del arreglo es remplazada con la primera posicion del arreglo
                    band = true; //band se transforma a true si hace este procedimiento
                } 
                i++; //aumentan el contador de 0 a 1 y en incremneto
                print(a, n); //se envia a imprimir el arreglo a pero con la posicion n que iniciara en 0 a la hora de imprimir
            }
        }
    }
}

void print(int a[], int n)
{
    cout << "Elementos Ordenados: " << endl;

    for (int i = 0; i < n; i++)
        cout << "[ " << a[i] << " ]";
}