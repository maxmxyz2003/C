#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int numero;
  // printf("Introduce el numero: ");
  scanf("%d", &numero);
  while (numero < 100) {
    if (numero % 2 == 0) {
      numero += 3;
    } else {
      numero *= 2;
    }
  }
  // printf("el numero es : ");
  printf("%d", numero);
  return 0;
}
