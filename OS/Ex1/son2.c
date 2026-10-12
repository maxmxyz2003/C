// hijo2
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char const *argv[]){
    if (argc==3){
        int a=atoi(argv[1]),b=atoi(argv[2]);
        if (10<a ||a<0){
            printf("Números no válido(s)\n");
            exit(0);
        }
        printf("Este es el programa %s con los argumentos: %s y %s\n",argv[0],argv[1],argv[2]);
        printf("P=%d\nA=%d", 2*a+2*b,a*b);
    }else{
        printf("Cantidad de argumentos no válida\n");
    }
    exit(0);
}
