#include <stdbool.h>
#include <stdio.h>
int main(){
    int x=5;//Asignamos un valor a cada variable
    unsigned int y=500;
    short int z=1;
    unsigned short int a=2;
    long int b=2300;
    unsigned long int c=8000;
    float d=7.5;
    double e=2.718281;
    char Car='X';//Los caracteres siempre van en comillas simples ''
    bool Bool=true;
    printf("%d, %u, %hd, %hu, %ld, %lu, %f,%lf,%c", x, y, z,a,b,c,d,e,Car);
    printf("%x, %u, %hd, %hu, %ld, %lu, %e,%lf,%c", x, y, z,a,b,c,d,e,Car);

}
