#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int* m_Biggest(int *arr, int m, int n) {
    int *nums = (int *)malloc(m * sizeof(int)); // Arreglo resultado
    int index[m]; // Arreglo auxiliar de indices
    int ref;
    for (int i = 0; i < m; i++){//Ciclo principal para hallar los m mas pequeños
        ref = INT_MAX;// Valor de referencia
        for (int j = 0; j < n; j++) { // Ciclo para ir comparando 
            if (arr[j] < ref) {
                ref = arr[j];
                index[i] = j;
            }
        }
        nums[i] = arr[index[i]];// La última actualizacion se guarda en el resultado
        arr[index[i]] = INT_MAX; // Omitimos el mas pequeño para que no interfiera
    }
    // Restauramos el arreglo original el arreglo auxiliar
    for (int i = 0; i < m; i++)
        arr[index[i]] = nums[i];
    return nums;// Regresamos los m mas pequeños
}

int main() {
    int arr[] = {16, 71, 13, 69, 34, 12, 98, 65, 83, 23, 54, 33, 66, 90, 31};
    int *arres = m_Biggest(arr, 5, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < 3; i++) {
        printf("%d ", arres[i]);
    }
    free(arres); // Liberar memoria asignada dinámicamente
    return 0;
}
