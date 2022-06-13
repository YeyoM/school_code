// Diego Emilio Moreno Sanchez ID: 264776

#include <iostream>
using namespace std;

void directInsertion(int arr[], int n) {
  int i, j, aux;
  for (i = 1; i < n; i++) {
    j = i;
    aux = arr[i];
    while (j > 0 && arr[j - 1] > aux) {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = aux;
  }
}




int main() {

  int arr[] = {5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  directInsertion(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}