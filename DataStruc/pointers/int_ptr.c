#include <stdio.h>
#include <stdlib.h>
// Función para asignar memoria al apuntador
void AsignMem(int **ptr){
    *ptr = (int *)malloc(sizeof(int));
    if (*ptr == NULL){
        printf("Asignacion de memoria fallido.\n");
        exit(1);
    }
    printf("Asignacion de memoria exitoso\n");
}
// Función para modificar el valor del apuntador
void ModifValorPV(int *ptr, int Nuevo){
    *(ptr) = Nuevo;
}
void ModifValorPR(int **ptr, int Nuevo){
    **ptr = Nuevo;
}
// Función para liberar la memoria
void LiberarMemPR(int **ptr){
    free(*ptr);
    *ptr = NULL;
    printf("Memoria libre");
}
void LiberarMemPV(int *ptr){
    free(ptr);
    ptr = NULL;
    printf("Memoria libre");
}

// Función para capturar el valor
void CapturaPR(int **ptr){
    printf("Introduce el valor nuevo del apuntador: \n");
    scanf("%d", *ptr);
}
void CapturaPV(int *ptr){
    printf("Introduce el valor nuevo del apuntador: \n");
    scanf("%d", ptr);
}

int main(void){
    int *PtrInt = NULL;
    AsignMem(&PtrInt);
    ModifValorPV(PtrInt, 1);
    printf("Valor: %d\n", *PtrInt);
    ModifValorPR(&PtrInt, 5);
    printf("Valor: %d\n", *PtrInt);
    CapturaPR(&PtrInt);
    printf("Valor: %d\n", *PtrInt);
    CapturaPV(PtrInt);
    printf("Valor: %d\n", *PtrInt);
    LiberarMemPR(&PtrInt);
    // LiberarMemPV(PtrInt);
    return 0;
}
