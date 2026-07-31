#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void Calificar(float calif);
int main(void) {
  float calificacion;
  scanf("%f", &calificacion);
  Calificar(calificacion);
}

void Calificar(float calif) {
  if (calif < 6) {
    printf("NA");
  } else if (calif >= 6 && calif < 7.5) {
    printf("S");
  } else if (calif >= 7.5 && calif < 9){
    printf("B");
  }else if (calif >= 9 && calif <= 10){
    printf("MB");
    }
}
