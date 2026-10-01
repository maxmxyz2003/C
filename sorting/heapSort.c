#include <stdio.h>

// Función para intercambiar dos elementos en un arreglo
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función para convertir un arreglo en un heap máximo
void heapify(int arr[], int n, int i) {
    int largest = i;  // Inicializamos el nodo raíz como el más grande
    int left = 2 * i + 1;  // Índice del hijo izquierdo
    int right = 2 * i + 2;  // Índice del hijo derecho

    // Si el hijo izquierdo es mayor que el nodo raíz
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Si el hijo derecho es mayor que el nodo raíz o el hijo izquierdo
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Si el nodo raíz ya no es el más grande
    if (largest != i) {
        // Intercambiamos el nodo raíz con el más grande
        swap(&arr[i], &arr[largest]);

        // Llamamos recursivamente a heapify en el subárbol afectado
        heapify(arr, n, largest);
    }
}

// Función principal para ordenar un arreglo usando Heap Sort
void heapSort(int arr[], int n) {
    // Construimos un heap máximo
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extraemos elementos del heap uno por uno
    for (int i = n - 1; i > 0; i--) {
        // Movemos la raíz actual al final del arreglo
        swap(&arr[0], &arr[i]);

        // Llamamos a heapify en el heap reducido
        heapify(arr, i, 0);
    }
}

// Función para imprimir un arreglo
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Arreglo original:\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Arreglo ordenado:\n");
    printArray(arr, n);

    return 0;
}
