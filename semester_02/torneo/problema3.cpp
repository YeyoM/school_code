#include <iostream>
using namespace std;

int arr[5];
int cuenta = 0;

int main () {

  for (int i = 0; i < 5; i++) {
    cin >> arr[i];
    if (arr[i] % 2 == 0) {
      cuenta++;
    }
  }

  cout << cuenta << " valores pares." << endl;

  return 0;
}