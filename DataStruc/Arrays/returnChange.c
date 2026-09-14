#include <stdbool.h>
#include <stdio.h>
void reparte(int num, int arr_bill[], int size, int arr_res[]) {
  for (int i = 0; i < size; i++) {
    arr_res[i] = (num / arr_bill[i]);
    num /= arr_bill[i];
  }
}
int main(void) {
  int dinero;
  int arr[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  int arr_r[size];
  printf("Combien?\n");
  scanf("%d", &dinero);
  for (int i = 0; i < size; i++) {
    arr_r[i] = (dinero / arr[i]);
    dinero = dinero - arr[i] * arr_r[i];
  }
  for (int i = 0; i < size; i++) {
    // printf("%d: %d \n", arr[i], arr_r[i]);
    printf("%d: %d --\t", arr[i], arr_r[i]);
    
  }
  return 0;
}
