#include <stdio.h>
// Función recursiva para calcular la suma de los elementos de un arreglo
int calcularSuma(int *arr, int size) {
    // Caso base: si el tamaño es 0, la suma es 0
    if (size == 0) {
        return 0;
    } else {
        // Llamada recursiva: suma del elemento actual y la suma del resto del arreglo
        return arr[0] + calcularSuma(arr + 1, size - 1);
    }
}
int main(){
    int arreglo[] = {1, 2, 3, 4, 5,1};
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);
    // Llamada a la función para calcular la suma
    int suma = calcularSuma(arreglo, tamano);
    // Imprimir resultado
    printf("La suma de los elementos del arreglo es: %d\n", suma);
    return 0;
}
