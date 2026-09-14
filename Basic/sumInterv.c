#include <stdio.h>
#include <stdlib.h>
int sumat(int i, int f);
int main(void) {
  int numero1, numero2, res;
  // printf("Introduce el numero: ");
  scanf("%d", &numero1);
  scanf("%d", &numero2);
  res = sumat(numero1, numero2);
  printf("%d", res);
}
int sumat(int i, int f) {
  if (i == f) {
    return i;
  }
  return f + sumat(i, f - 1);
}
