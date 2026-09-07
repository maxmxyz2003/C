#include <stdio.h>
#include <stdlib.h>
void tres_n_mas_uno(long int numero, long int *cont, long int *mayor) {
  while (numero != 1) {
    if (numero % 2 == 0) {
      numero /= 2;
      (*cont)++;
      if (numero > *mayor) {
        *mayor = numero;
      }
    }else{
      numero *= 3;
      numero++;
      (*cont)++;
      if (numero > *mayor) {
        *mayor = numero;
      }
    }
  }
}
void syr(int num){ // recursive 
    if(num==1){
        printf("1");  
    }else if (num%2==0)
    {
        syr(num*3+1);
        printf("%d \n", num);
    }else if (num%2==1){
        syr(num/2);
        printf("%d \n", num);
    }    
}
void cambia(const int a[]){
    int nuevo=a[1];
    
}
int main(void) {
  long int elcontad = 0, numero, elmayor = 1;
  scanf("%ld", &numero);
  tres_n_mas_uno(numero, &elcontad, &elmayor);
  printf("%ld %ld", elcontad, elmayor);
  return 0;
}
