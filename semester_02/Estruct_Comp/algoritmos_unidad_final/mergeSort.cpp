// Diego Emilio Moreno Sanchez ID: 264776

#include <iostream>
using namespace std;

void mergeSort(int arr1[], int n1, int arr2[], int n2, int arr3[]) {
  int i = 0, j = 0, k = 0, p;
  while (i < n1 && j < n2) {
    if (arr1[i] < arr2[j]) {
      arr3[k] = arr1[i];
      i++;
    } else {
      arr3[k] = arr2[j];
      j++;
    }
    k++;
  }
  if (i >= n1) {
    for (p = j; p < n2; p++) {
      arr3[k] = arr2[p];
      k++;
    }
  } else {
    for (p = i; p < n1; p++) {
      arr3[k] = arr1[p];
      k++;
    }
  }
}




int main() {

  int arr1[] = {2, 4, 6, 8, 10};
  int arr2[] = {1, 3, 5, 7, 9};
  int arr3[10];
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  mergeSort(arr1, n1, arr2, n2, arr3);
  for (int i = 0; i < n1 + n2; i++) {
    cout << arr3[i] << " ";
  }

  return 0;
}