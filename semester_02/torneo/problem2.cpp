#include <iostream>
using namespace std;

int N,
    A,
    B;

int main () {

  cin >> N;

  cin >> A;

  cin >> B;

  if (N < (A + B)) {
    cout << "Tomorrow sera otro dia!" << endl;
  } else {
    cout << "Podemos hacerlo!" << endl;
  }

  return 0;
}
/*#include <iostream>
using namespace std;

int N,
    A,
    B;

int main () {

  cout << "time: ";
  cin >> N;
  cout << endl;

  cout << "gift a: ";
  cin >> A;
  cout << endl;

  cout << "gift b: ";
  cin >> B;
  cout << endl;

  if (N < (A + B)) {
    cout << "Tomorrow sera otro dia!" << endl;
  } else {
    cout << "Podemos hacerlo!" << endl;
  }


  return 0;
}*/