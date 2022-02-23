#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int n;
    string Nombre;
    float m = 0, m1 = 0, tS = 0, tS1 = 0;
    float z = 0, z1 = 0, tB = 0, tB1 = 0;
    float l = 0, l1 = 0, tA = 0, tA1 = 0;

    cin>>n;

    for (int x = 0; x < n; x++){

        cin>>Nombre;

        cin>> m >> z >> l;
        do{
            cin>> m1 >> z1 >> l1;
        } while(m1 >= z && z1 >= z && l1 >= l);
        
        tS1 += m1; tB1 += z1; tA1 += l1;
        tS += m; tB += z; tA += l;
    }

   cout<<"Puntos de saque: "<<fixed<<setprecision(2)<<(tS1 / tS)*100<<" %."<<endl;
   cout<<"Puntos de bloqueo: "<<fixed<<setprecision(2)<<(tB1 / tB)*100<<" %."<<endl;
   cout<<"Puntos de ataque: "<<fixed<<setprecision(2)<<(tA1 / tA)*100<<" %."<<endl;
}


/*#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n_players;
  float aux = 0, aux1 = 0, aux2 = 0, lau = 0, lau1 = 0, lau2 = 0;
  float n[100], n1[100], n2[100];
  float l[100], l1[100], l2[100];
  char nombre[20];
  float puntos_saque = 0, puntos_bloqueo = 0, puntos_ataque = 0;
  cin >> n_players;
  for (int i = 0; i < n_players; i++)
  {
    fflush(stdin);
    cin.getline(nombre,30,'\n');
    fflush(stdin);
    cin >> n[i];
    cin >> n1[i];
    cin >> n2[i];
    cin >> l[i];
    cin >> l1[i];
    cin >> l2[i];
    aux += n[i];
    aux1 += n1[i];
    aux2 += n2[i];
    lau += l[i];
    lau1 += l1[i];
    lau2 += l2[i];
  }
  // puntos_saque = (lau * 100) / aux;
  // puntos_bloqueo = (lau1 * 100) / aux1;
  // puntos_ataque = (lau2 * 100) / aux2;
  system("cls");
  cout<<"Puntos de saque: "<<fixed<<setprecision(2)<< (lau / aux) * 100<<" %.";
   cout<<"Puntos de bloqueo: "<<fixed<<setprecision(2)<<(lau1 / aux1)*100<<" %.";
   cout<<"Puntos de ataque: "<<fixed<<setprecision(2)<<(lau2 / aux2) * 100<<" %.";
}*/