#include <stdio.h>
#include <stdlib.h>
#include <String.h>
typedef struct{
    char nombre[50];
    char address[50];
    char telefono[12];
    char tipo[15];
    double base;
    double subsidio;
    double Pago_tot;
}UsR;

// Función para asignar memoria al apuntador
void AsignMem(UsR ** ptr, int m) {
    *ptr = (UsR*)malloc(m*sizeof(UsR));
    if (*ptr) {
        return;
    }else{
        printf("Asignación de memoria fallido.\n");
        exit(1);
    }

}
// Función para modificar el valor del apuntador
void AsignDat(UsR * ptr,int m, int precio) {
    char cadTemp[100];
    for (int i = 0; i < m; i++){
        printf("Introduce el nombre del usuario %d:", i);
        scanf(" %24[^\n]s", cadTemp);
        strcpy((ptr + i)->nombre, cadTemp);
        printf("Introduce la direccion del usuario %d:", i);
        scanf(" %5[^\n]s", cadTemp);
        strcpy((ptr + i)->address, cadTemp);
        printf("Introduce el numero de telefono del usuario %d:", i);
        scanf(" %6[^\n]s", cadTemp);
        strcpy((ptr + i)->telefono, cadTemp);
        printf("Introduce el tipo de usuario %d:", i);
        scanf(" %6[^\n]s", cadTemp);
        strcpy((ptr + i)->tipo, cadTemp);
        printf("Introduce el tipo de usuario %d:", i);
        scanf("%lf", &(ptr + i)->subsidio);
        (ptr + i)->base = precio;
        (ptr + i)->Pago_tot = 0;
    }
}
// Función para liberar la memoria
void LiberarMem(UsR ** ptr) {
    free(*ptr);
    *ptr = NULL;
}
//Función para calcular
void CalcTot(UsR *ptr) {
    double discount = 0.95;

}

// Función para imprimir info
void Imprime(UsR * ptr) {
    printf("Nombre: %s\n", ptr->nombre);
    printf("Direcion: %s\n", ptr->address);
    printf("Telefono: %s\n", ptr->telefono);
    printf("Categoria: %s\n", ptr->tipo);
    printf("Cuota base: %lf\n", ptr->base);
    printf("Total a pagar: %lf\n", ptr->Pago_tot);
}

int main() {
    UsR * PtrCL = NULL;
    int filas,cuota;
    printf("Introduce la cantidad de usuarios:\n");
    scanf("%d", &filas);
    printf("Introduce la cuota base:\n");
    scanf("%d", &cuota);
    AsignMem(&PtrCL, filas);
    AsignDat(PtrCL, filas, 500);
    CalcTot(PtrCL);
    Imprime(PtrCL);
    LiberarMem(&PtrCL);
    return 0;
}
