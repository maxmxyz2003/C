#include <stdio.h>
#include <stdlib.h>
// Asignacion de memoria
int*** AsgnMem3D(int x, int y, int z) {
    int*** arr = (int***)malloc(x * sizeof(int**));
    for (int i = 0; i < x; i++) {
        *(arr+i) = (int**)malloc(y * sizeof(int*));
        for (int j = 0; j < y; j++) {
            *(*(arr+i)+j) = (int*)malloc(z * sizeof(int));
        }
    }
    return arr;
}
// Inicializar con datos de ejemplo
void Initialize3DArray(int*** arr, int x, int y, int z) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
               *(*(*(arr+i)+j)+k) = i * 100 + j * 10 + k; // Some example data
            }
        }
    }
}
// Imprimir valores
void Print3DArray(int*** arr, int x, int y, int z) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                printf("arr[%d][%d][%d] = %d\n", i, j, k, *(*(*(arr+i)+j)+k));
            }
        }
    }
}
// Liberar memoria
void Free3DArray(int*** arr, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            free(arr[i][j]);
        }
        free(arr[i]);
    }
    free(arr);
}
int main(void){
    int x = 3; // Dimension x
    int y = 3; // Dimension y
    int z = 3; // Dimension z
    // Llamamos a la funcion que nos devuelve el arreglo tridimensional
    int*** my3DArray = AsgnMem3D(x, y, z);
    //Inicializar
    Initialize3DArray(my3DArray, x, y, z);
    // Imprimir arreglo
    Print3DArray(my3DArray, x, y, z);
    // Liberar memoria
    Free3DArray(my3DArray, x, y);
    return 0;
}
