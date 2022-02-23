#include <iostream>
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
  cout << fixed;
  cout << setprecision(2);
  cin >> n_players;
  for (int i = 0; i < n_players; i++)
  {
    fflush(stdin);
    cin.getline(nombre, 30, '\n');
    fflush(stdin);
    scanf("%)
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
  puntos_saque = (lau * 100) / aux;
  puntos_bloqueo = (lau1 * 100) / aux1;
  puntos_ataque = (lau2 * 100) / aux2;

  cout << "Puntos de saque: " << puntos_saque << " %." << endl;
  cout << "Puntos de bloqueo: " << puntos_bloqueo << " %." << endl;
  cout << "Puntos de ataque: " << puntos_ataque << " %." << endl;
}