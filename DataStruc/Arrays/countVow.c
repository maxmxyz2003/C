#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 01001101 01010101 01000011 01001000 01000001
/* 01000011 01001111 01001101 01010000 01010101*/
int contarVoc(char cad[]) {
  int cont = 0;
  char copia[50];
  strcpy(copia, cad);
  for(int i = 0; i < strlen(cad); i++) {
    if (cad[i] == 'a' || cad[i] == 'e' || cad[i] == 'i' || cad[i] == 'o' ||
        cad[i] == 'u' || cad[i] == 'A' || cad[i] == 'E' || cad[i] == 'I' ||
        cad[i] == 'O' || cad[i] == 'U') {
      cont++;
    }
  }
  return cont;
}
int main(void) {
  char nombre[50];
  // printf("¿Cual e il tuo nome?\n");
  scanf("\n %[^\n]", nombre);
  // printf("Nombre: %s \n", nombre);
  printf("%d", contarVoc(nombre));
  return 0;
}
