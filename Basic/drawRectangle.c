#include <stdio.h>
#include <stdlib.h>
int main(void) {
  long long int base, alt;
  printf("Base:\n");
  scanf("%lld", &base);
  printf("Altura:\n");
  scanf("%lld", &alt);
  for (int i = 0; i < alt; i++) {
    for (int j = 0; j < base; j++) {
      printf("@");
    }   
    printf("\n");
  }
  return 0;
}
