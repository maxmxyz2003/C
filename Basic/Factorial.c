#include <stdio.h>
#include <stdlib.h>
int fact(int i) {
  if (i == 1||i==0) 
    return i;
  return i * fact(i-1);
}
int main(void) {
  int numeros_fact;
  long int valorTemp;
  long long int factorialTemp;
  scanf("%d", &numeros_fact);
    for (int i = 0; i < numeros_fact; i++) {
      scanf("%ld", &valorTemp);
      if (valorTemp >= 1 && valorTemp < 20) {
        factorialTemp = 1;
        for (int j = 1; j <= valorTemp; j++) {
          factorialTemp *= j;
        }
      }
      printf("%lld \n", factorialTemp);
    }
    int numero1,res;
  scanf("%d", &numero1);
  res = fact(numero1);
  printf("%d", res);

  return 0;
}

