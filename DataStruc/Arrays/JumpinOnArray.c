#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void capturar_ARR(long int arr[], long int n);
long int cuenta_pasos(long int arr[], long int n);

int main(void) {
  long int elementos, pasos;
  scanf("%ld", &elementos);
  long int arreglo[elementos];
  capturar_ARR(arreglo, elementos);
  pasos = cuenta_pasos(arreglo, elementos);
  printf("%ld", pasos);
}
void capturar_ARR(long int arr[], long int n) {
  for (long int i = 0; i < n; i++) {
    scanf("%ld", &arr[i]);
  }
}
long int cuenta_pasos(long int arr[], long int n) {
  long int i = 0, j,  pasos = 0;
  while (i < n-1) {
    i+= arr[i];
    pasos++;
  }
  return pasos;
}
