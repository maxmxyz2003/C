#include <stdio.h>
#include <stdlib.h>
// Función para encontrar el número máximo en un arreglo
int encontrarMaximo(int arr[], int n) {
    int maximo = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maximo) {
            maximo = arr[i];
        }
    }
    return maximo;
}

// Función para ordenar los elementos usando Radix Sort
void RadixSort(int arr[], int n) {
    int maximo = encontrarMaximo(arr, n);// Realizar el conteo de frecuencia de cada dígito
    for (int exp = 1; maximo / exp > 0; exp *= 10) {
        int conteo[10] = {0}; // Inicializar el arreglo de conteo a 0
        // Contar la frecuencia de cada dígito en la posición 'exp'
        for (int i = 0; i < n; i++) {
            conteo[(arr[i] / exp) % 10]++;
        }
        // Actualizar el conteo para indicar la posición real de los dígitos en el arreglo ordenado
        for (int i = 1; i < 10; i++) {
            conteo[i] += conteo[i - 1];
        }
        // Construir el arreglo ordenado
        int salida[n];
        for (int i = n - 1; i >= 0; i--) {
            salida[conteo[(arr[i] / exp) % 10] - 1] = arr[i];
            conteo[(arr[i] / exp) % 10]--;
        }
        // Copiar el arreglo ordenado de salida al arreglo original
        for (int i = 0; i < n; i++) {
            arr[i] = salida[i];
        }
    }
}

// Función para imprimir un arreglo
void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Función principal
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Arreglo original: ");
    imprimirArreglo(arr, n);
    RadixSort(arr, n);
    printf("Arreglo ordenado: ");
    imprimirArreglo(arr, n);
    return 0;
}
