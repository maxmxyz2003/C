#include <stdio.h>
#include <ctype.h>
#include <string.h>
void printChars(const char *ptrS){
    for (;*ptrS!='\0';ptrS++)
        printf("%c\n",*ptrS);
}
void printChars_2(const char *ptrS){
    for (int i=0;*(ptrS+i)!='\0';i++)
        printf("%c\n",*(ptrS+i));
}
int main(void){
    char cadena[] = "Shaggy";
    printChars(cadena);
    // printChars_2(cadena);
    return 0;
}
