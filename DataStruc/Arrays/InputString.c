#include <stdio.h>
#include <string.h>
void Leercad(char cadena[]){
    long int caracteres=0;
    for (int i=0;cadena[i]!='\0';i++){
        caracteres++;
    }
    printf("%c%s%c tiene %d caracteres\n",34,cadena,34,caracteres);
}
int main() {
    long int cant_cadenas, caracteres;
    char cadena[81], cantcad[100];
    //printf("Escribe el numero de cadenas: \n");
    //scanf("%ld",&cant_cadenas);
    scanf("\n %[^\n]", cantcad);
    if(!(strcmp(cantcad,"Entrada"))){
        printf("Salida");
    } else {
        cant_cadenas=cantcad[0]-48;
        for (int i = 0; i < cant_cadenas; ++i) {
            //printf("Escribe la cadena: \n");
            scanf("\n %[^\n]", cadena);
            Leercad(cadena);
        }
    }
    return 0;
}
