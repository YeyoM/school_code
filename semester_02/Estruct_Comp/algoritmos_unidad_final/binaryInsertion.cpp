// Diego Emilio Moreno Sanchez ID: 264776

#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int low, int high) {
  if (high <= low)
    return (n > arr[low])? (low + 1): low;
    int mid = (low + high) / 2;
  if(n == arr[mid])
    return mid + 1;
  if(n > arr[mid])
    return binarySearch(arr, n, mid + 1, high);
  return binarySearch(arr, n, low, mid - 1);
}

void binaryInsertion(int arr[], int n) {
  int i, loc, j, k, selected;
  for (i = 1; i < n; i++) {
    j = i - 1;
    selected = arr[i];
    loc = binarySearch(arr, selected, 0, j);
    while (j >= loc) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j+1] = selected;
  }
}



int main() {

  int arr[] = {5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  binaryInsertion(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}