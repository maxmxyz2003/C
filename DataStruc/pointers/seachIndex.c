#include <stdio.h>
int BuscaIndex(int *arr, int size, int elem){
    if (size == 0){
        return -1;
    } else if(arr[0]==elem){
        return 0;
    }else{
        return 1 + BuscaIndex(arr + 1, size - 1,elem);
    }
}
int main() {
    int arreglo[] = {1, 2, 3, 4, 5,1,8}; int c=0;
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);
    // Llamada a la función para calcular la suma
    int ind = BuscaIndex(arreglo, tamano, 5);
    // Imprimir resultado
    printf("El 5 esta en la posicion: %d\n", ind);
    return 0;
}
