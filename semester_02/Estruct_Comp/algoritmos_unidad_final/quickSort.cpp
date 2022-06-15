#include <iostream>
using namespace std;

void quickSort(int *arr, int left, int right) {
  if (left < right) {
    int pivot = arr[left];
    int i = left + 1;
    int j = right;
    while (i <= j) {
      while (i <= right && arr[i] <= pivot) {
        i++;
      }
      while (j >= left && arr[j] > pivot) {
        j--;
      }
      if (i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    int temp = arr[left];
    arr[left] = arr[j];
    arr[j] = temp;
    quickSort(arr, left, j - 1);
    quickSort(arr, j + 1, right);
  }
}

int main() {
  int arr[] = {5, 2, 4, 6, 1, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  quickSort(arr, 0, n - 1);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}