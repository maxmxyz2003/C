#include <stdio.h>
// Función recursiva para invertir un arreglo
void invertirArreglo(int *arr, int inicio, int fin) {
    if (inicio < fin) {
        // Intercambiar elementos en las posiciones inicio y fin
        int temp = arr[inicio];
        arr[inicio] = arr[fin];
        arr[fin] = temp;
        // Llamada recursiva para invertir el resto del arreglo
        invertirArreglo(arr, inicio + 1, fin - 1);
    }
}
// Función para imprimir un arreglo
void imprimirArreglo(int *arr, int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}
int main() {
    int arreglo[] = {1, 2, 3, 4, 5}; 
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);
    printf("Arreglo original: ");
    imprimirArreglo(arreglo, tamano);
    // Llamada a la función para invertir el arreglo
    invertirArreglo(arreglo, 0, tamano - 1);
    printf("Arreglo invertido: ");
    imprimirArreglo(arreglo, tamano);
    return 0;
}
