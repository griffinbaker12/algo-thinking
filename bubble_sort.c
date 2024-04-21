#include "common.h"

void bubble_sort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {       // Only need to iterate to n - 1
    for (int j = 0; j < n - i - 1; j++) { // Decrease the end each time
      if (arr[j] > arr[j + 1]) {          // Compare current item to the next
        int tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
}

void print_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);
  bubble_sort(arr, n);
  print_array(arr, n);
  return 0;
}
