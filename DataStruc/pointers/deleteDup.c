#include <stdio.h>
void eliminarDuplicados(int *arr, int *n) {
    // Caso base: si el tamaño es 0 o 1, no hay duplicados que eliminar
    if (*n <= 1) {
        return;
    }
    // Inicializar un índice para el nuevo arreglo sin duplicados
    int indiceNuevo = 0;
    // Recorrer el arreglo desde el segundo elemento
    for (int i = 1; i < *n; i++) {
        // Si el elemento actual es diferente al elemento anterior, agregarlo al nuevo arreglo
        if (arr[i] != arr[indiceNuevo]) {
            indiceNuevo++;
            arr[indiceNuevo] = arr[i];
        }
    }
    // Actualizar el tamaño del arreglo después de eliminar duplicados
    *n = indiceNuevo + 1;
}
int main(){
    int arreglo[] = {1, 2, 2, 3, 4, 4, 4, 5, 5, 6};
    int tamano = sizeof(arreglo)/sizeof(arreglo[0]);
    printf("Arreglo original: ");
    for (int i = 0; i < tamano; i++)
        printf("%d ", arreglo[i]);
    printf("\n");
    // Llamada a la función para eliminar duplicados
    eliminarDuplicados(arreglo, &tamano);
    printf("Arreglo despues de eliminar duplicados: ");
    for (int i = 0; i < tamano; i++)
        printf("%d ", arreglo[i]);
    printf("\n");
    return 0;
}
