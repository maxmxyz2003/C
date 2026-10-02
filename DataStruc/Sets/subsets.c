#include <stdio.h>
// Función para imprimir un subconjunto de tamaño 4
void imprimirSubconjunto(int conjunto[], int n, int subconjunto[]){
    for (int i = 0; i < 4; i++){
        printf("%d ", subconjunto[i]);
    }
    printf("\n");
}
// Función para generar todos los subconjuntos de tamaño 4
void generarSubconjuntos(int conjunto[], int n){
    if (n < 4){
        printf("El conjunto debe tener al menos 4 elementos.\n");
        return;
    }
    int numOp = 0;      // Opcion para contar las operaciones
    int subconjunto[4]; // Arreglo para almacenar cada subconjunto
    for (int i = 0; i < n - 3; i++){ // Ciclo externo para seleccionar el primer elemento del subconjunto
        subconjunto[0] = conjunto[i];
        for (int j = i + 1; j < n - 2; j++){ // Ciclo interno para seleccionar el segundo elemento del subconjunto
            subconjunto[1] = conjunto[j];
            for (int k = j + 1; k < n - 1; k++){ // Ciclo interno para seleccionar el tercer elemento del subconjunto
                subconjunto[2] = conjunto[k];
                for (int l = k + 1; l < n; l++){ // Ciclo interno para seleccionar el cuarto elemento del subconjunto
                    subconjunto[3] =
                        conjunto[l]; // Seleccionar el cuarto elemento del subconjunto
                    imprimirSubconjunto(conjunto, n, subconjunto);
                    // numOp++;
                }
            }
        }
    }
    // Mostrar el numero de operaciones
    //  printf("%d\n", numOp);
}
int main(){
    int conjunto[] = {1, 2, 3, 4,5, 6, 7, 8}; // Ejemplo de conjunto de n elementos
    int n = sizeof(conjunto) / sizeof(conjunto[0]);
    generarSubconjuntos(conjunto, n);
    return 0;
}
