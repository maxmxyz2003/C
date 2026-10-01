#include <stdio.h>
// INSERTIONSORT Complexity B(n)=n, A(n)=n^2 , W(n)=n^2 
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        /* Mueve los elementos del arreglo que son mayores que key a una posición adelante de su posición actual */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Arreglo original:\n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Arreglo ordenado:\n");
    printArray(arr, n);
    return 0;
}
