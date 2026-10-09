#include <stdio.h>
#include <stdlib.h>
int main(){
    // Definir variables de diferentes tipos
    int entero = 42;
    double doble = 3.14;
    char caracter = 'A';
    // Declarar un puntero generico
    void *punteroGenerico;
    // Asignar el puntero generico a la dirección de memoria de las variables
    punteroGenerico = &entero;
    printf("Contenido del puntero generico (entero): %d\n", *(int*)punteroGenerico);
    punteroGenerico = &doble;
    printf("Contenido del puntero generico (doble): %f\n", *(double*)punteroGenerico);
    punteroGenerico = &caracter;
    printf("Contenido del puntero generico (caracter): %c\n", *(char*)punteroGenerico);
    return 0;
}
