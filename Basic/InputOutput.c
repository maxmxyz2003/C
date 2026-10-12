#include <stdio.h>
int main(){
    int x;//Declaramos la variable
    printf("Escribe un numero: "); // Escribimos un mensaje al usuario
    scanf("%d", &x); // Leemos el dato con la direccion del dato con &
    printf("El numero proporcionado es %d",x); // Imprimimos el valor del dato obtenido
    return 0; // Se Sale del programa al saber que se ejecuto correctamente
}
