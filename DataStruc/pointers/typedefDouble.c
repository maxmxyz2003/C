#include <stdio.h>
#include <stdlib.h>
typedef double TipoDato;
// Funcion para asignar memoria al apuntador
void AsignMem(TipoDato** ptr, int n) {
    *ptr = (TipoDato*)malloc(n*sizeof(TipoDato));
    if (!*ptr) {
        printf("Asignacion de memoria fallido.\n");
        exit(1);
    }else
        return;
}
// Funcion para capturar los valores
void Capturar(TipoDato *ptr, int n) {
    for (int i = 0; i < n; i++){
        printf("Introduce el valor #%d\n", i+1);
        scanf("%lf", (ptr + i)); // Se usa &* y se elimina 
    }
}
// Funcion para ver los valores del apuntador
void Mostrar(TipoDato *ptr, int n) {
    for (int i = 0; i < n; i++)
        printf("*(ptr + %d) = %lf\n",i, *(ptr+i));// imprimimos el valor
}
// Funcion para liberar la memoria
void LiberarMem( TipoDato ** ptr) {
    free(*ptr);
    *ptr = NULL;
}
int main(void) {
    TipoDato * PtrSSI = NULL;
    int n_elem;
    printf("Cuantos elementos?: \n");
    scanf("%d", &n_elem);
    AsignMem(&PtrSSI, n_elem);
    Capturar(PtrSSI, n_elem);
    Mostrar(PtrSSI, n_elem);
    LiberarMem(&PtrSSI);
    return 0;
}
