#include <stdio.h>
#include <ctype.h>
#include <string.h>
void toUpper(char *ptrS){
    while (*ptrS!='\0'){
        if (islower(*ptrS))
            *ptrS=toupper(*ptrS);
        *ptrS++;//Se recorre la dirreccion a la que apunta
    }
}
void toUpper2(char *ptrS){
    while (*ptrS!='\0'){
        if (*ptrS>='a'&&*ptrS<='z')
            *ptrS=toupper(*ptrS);
        *ptrS++;
    }
}
void toLower(char *ptrS){
    while (*ptrS!='\0'){
        if (isupper(*ptrS))
            *ptrS=tolower(*ptrS);
        *ptrS++;
    }
}
void toLower2(char *ptrS){
    while (*ptrS!='\0'){
        if (*ptrS>='A'&&*ptrS<='Z')
            *ptrS=tolower(*ptrS);
        *ptrS++;
    }
}
int main(void){
    char cadena[] = "CaDeNa";
    toUpper(cadena);  
    printf("%s\n", cadena);
    toLower(cadena);
    printf("%s\n", cadena);
    toUpper2(cadena);  
    printf("%s\n", cadena);
    toLower2(cadena);
    printf("%s\n", cadena);
    return 0;
}
