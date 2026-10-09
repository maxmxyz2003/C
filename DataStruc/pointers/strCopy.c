#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
void StrCopy1(char *S1, const char *S2){
    for (int i = 0; (S1[i]=S2[i])!='\0'; i++){}
      //xd no pasa nada ya se hace
}
void StrCopy2(char *S1, const char *S2) {
    while ((*S1 = *S2) != '\0') {
        S1++;
        S2++;
    }
}     
int main(){
    char cad1[10];
    char *ptr1="Hola";
    char cad2[10];
    char cad3[]="Adios";
    StrCopy1(cad1,ptr1);
    printf("cadena 1 = %s\n",cad1);
    StrCopy2(cad2,cad3);
    printf("cadena 2 = %s\n",cad2);
    return 0;
}
