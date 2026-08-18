#include <stdio.h>
#include <stdlib.h>
void capturar_elem(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("Introduce el elemento #%d", i+1);
    scanf("%d", &arr[i]);
  }
}
void BubbleSort(int arr[], int size) {
  int temp;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main(void) {
  int elementos;
  // printf("Introduce el número de elementos: \n");
  scanf("%d", &elementos);
  int numeros1[elementos];
  capturar_elem(numeros1, elementos);
  BubbleSort(numeros1, elementos);
  printf("%d", numeros1[(elementos - 1) / 2]);
  return 0;
}
