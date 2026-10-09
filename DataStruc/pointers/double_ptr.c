#include <stdio.h>
#include <stdlib.h>
// Asignacion de memoria
void AsignMem(double ***ptr){
    *ptr = (double **)malloc(sizeof(double *));
    if (*ptr) {
        **ptr = (double *)malloc(sizeof(double));
        if (*ptr)
            return;
        else {
            free(*ptr);
            printf("Asignacion fallida.\n");
            exit(1);
        }
    } else {
        printf("Asignacion fallida.\n");
        exit(1);
    }
}
// Modificar valor 
void ModifValorPV(double **ptr, double Nuevo) {
    **ptr = Nuevo;
}
void ModifValorPR(double ***ptr, double Nuevo) {
    ***ptr = Nuevo;
}
// Liberar memoria
void LiberarMemPR(double ***ptr) {
    free(**ptr);
    free(*ptr);
    *ptr = NULL;
}
void LiberarMemPV(double **ptr) {
    free(*ptr);
    free(ptr);
    *ptr = NULL;
}
// Capturar 
void CapturaPV(double **ptr) {
    printf("Introduce el nuevo valor: \n");
    scanf("%lf", *ptr);
}
void CapturaPR(double ***ptr) {
    printf("Introduce el nuevo valor:\n");
    scanf("%lf", **ptr);
}
int main(void){
    double **PtrPD = NULL;
    AsignMem(&PtrPD);
    CapturaPR(&PtrPD);
    printf("Nuevo valor capturado por referencia #1: %lf\n", **PtrPD);
    CapturaPV(PtrPD);
    printf("Nuevo valor capturado por valor #2: %lf\n", **PtrPD);
    ModifValorPR(&PtrPD, 3.1415);
    printf("Nuevo valor asignado por referencia #3:(pi) %lf\n", **PtrPD);
    ModifValorPV(PtrPD, 2.718182);
    printf("Nuevo valor asignado por valor #4: %lf\n", **PtrPD);
    LiberarMemPR(&PtrPD);
    return 0;
}
