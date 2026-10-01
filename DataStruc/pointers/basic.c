#include <stdio.h>
int main(void){
    int num = 10;
    int *ptr;
    ptr = &num; // Apuntador que guarda la dirección de memoria de 'num'
    printf("Valor de num: %d\n", num);
    printf("Direccion de memoria de num: %p\n", &num);
    printf("Valor apuntado por ptr: %d\n", *ptr);
    printf("Direccion de memoria almacenada en ptr: %p\n", ptr);
    *ptr = 20; // Modificar el valor de 'num' a través del apuntador
    printf("Nuevo valor de num: %d\n", num);
    return 0;
}
