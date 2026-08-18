#include <stdio.h>
#include <stdlib.h>

void printPyramid(int n, int espacios) {
  if (n <= 0)
      return;
  for (int i = 0; i < espacios; i++)
    printf(" ");
  for (int i = 0; i < 2 * n - 1; i++)
    printf("X");
  printf("\n");
  printPyramid(n - 1, espacios + 1);
  for (int i = 0; i < espacios; i++)
    printf(" ");
  for (int i = 0; i < 2 * n - 1; i++)
    printf("X");
  printf("\n");
}
int main(void) {
  long long int numeros, temp, elmayor, elmenor;
  // printf("Introduce la cantidad de numeros: ");
  scanf("%lld", &numeros);
  int espacios=numeros/2;
  for (int i = 0; i < (numeros+1)/2; i++) {
    for (int j = 0; j < espacios; j++) {
      printf(" ");
    }
    for (int j = 0; j < 2 * i + 1; j++) {
      printf("@");
    }
    printf("\n");
    espacios--;
  }
  espacios+=2;
  for (int i = 0; i < (numeros+1)/2-1; i++) {
    for (int j = 0; j < espacios; j++) {
      printf(" ");
    }
    for (int j = numeros-2*(i+1); j > 0; j--) {
      printf("@");
    }
    printf("\n");
    espacios++;
  }
  espacios=0;
  printf("---------\n");
  printPyramid(numeros,espacios);

  return 0;
}
