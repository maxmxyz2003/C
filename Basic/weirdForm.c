#include <math.h>
#include <stdio.h>
#include <stdlib.h>
float funcion_rara(float x, float y, float z);
int main(void) {
  float valorX, valorY, valorZ, result;
  scanf("%f %f %f", &valorX, &valorY, &valorZ);
  result = funcion_rara(valorX, valorY, valorZ);
  printf("%f", result);
}
float funcion_rara(float x, float y, float z) {
  return (pow(x, (1.2 * y)) - z + 5.7) / ((x + 2 * y + 3 * z) / (x * y));
}
