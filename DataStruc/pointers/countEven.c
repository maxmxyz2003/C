#include <stdio.h>
// Función recursiva para calcular la suma de los elementos de un arreglo
int contPares(int *arr, int size){
    // Caso base: si el tamaño es 0, la suma es 0
    if (size == 0){
        return 0;
    } else {
        if(arr[0]%2==0){
            return 1 + contPares(arr + 1, size - 1);
        }else{
            return contPares(arr + 1, size - 1);
        }
    }
}
int main() {
    int arreglo[] = {1, 2, 3, 4, 5,1,8}; int c=0;
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);
    // Llamada a la función para calcular la suma
    int suma = contPares(arreglo, tamano);
    // Imprimir resultado
    printf("Los pares son : %d\n", suma);
    return 0;
}
