#include <stdio.h>
// Función recursiva para calcular la suma de los elementos de un arreglo
int calcularSumaPares(int *arr, int size) {
    // Caso base: si el tamaño es 0, la suma es 0
    if (size == 0){
        return 0;
    } else {
        if(arr[0]%2==0){
            return arr[0] + calcularSumaPares(arr + 1, size - 1);
        }else{
            return calcularSumaPares(arr + 1, size - 1);
        }
    }
}
int calcularSumaMultpl(int *arr, int size, int multp) {
    // Caso base: si el tamaño es 0, la suma es 0
    if (size == 0){
        return 0;
    } else {
        if(arr[0]%multp==0){
            return arr[0] + calcularSumaMultpl(arr + 1, size - 1, multp);
        }else{
            return calcularSumaMultpl(arr + 1, size - 1,multp);
        }
    }
}

int main() {
    int arreglo[] = {1, 2, 3, 4, 5,1,8,6};
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);
    // Llamada a la función para calcular la suma
    int suma = calcularSumaPares(arreglo, tamano);
    // Imprimir resultado
    printf("La suma de los elementos pares del arreglo es: %d\n", suma);
    int suma2=calcularSumaMultpl(arreglo,tamano,3);
    printf("La suma de los elementos mutiplos de 3 es: %d\n", suma2);    
    return 0;
}
