#include <stdio.h>
#include <stdlib.h>
void tabla_ASCII(long int inicio, long int Elfinal) {
  for (int i = inicio; i <= Elfinal; i++) {
    printf("%c\t%d\t%x", i, i, i);
    printf("\n");
  }
}
void tabla_ASCII_V2(int ini, int f){
    if(ini==f)
        printf("%c\t%d\t%x\n", f, f, f);
    else{
        printf("%c\t%d\t%x\n", ini, ini, ini);
        tabla_ASCII_V2(ini+1,f);    
    }
    
}
int main(void) {
    long int inicio, elfinal;
    // printf("Introduce el rango de números: ");
    scanf("%ld %ld", &inicio, &elfinal);
    //tabla_ASCII(inicio, elfinal);
    tabla_ASCII_V2(inicio,elfinal);
    return 0;
}
