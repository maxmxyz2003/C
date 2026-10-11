#include <stdio.h>
#include <stdlib.h>
#include <String.h>
typedef struct{
    char clave[6];
    char nombre[25];
    char tipo[3];
    double compras_Tot;
    char frecuente;
    double Pago_tot;
}CLIENTE;
// Función para asignar memoria al apuntador
void AsignMem(CLIENTE ** ptr) {
    *ptr = (CLIENTE*)malloc(sizeof(CLIENTE));
    if (*ptr) {
        return;
    }else{
        printf("Asignacion de memoria fallido.\n");
        exit(1);
    }
}
// Función para modificar el valor del apuntador
void AsignDat(CLIENTE * ptr, char vclave[], char vnombre[], char vtipo[], double vcompras, char vfrec) {
    strcpy(ptr->clave,vclave);
    strcpy(ptr->nombre,vnombre);
    strcpy(ptr->tipo,vtipo);
    ptr->compras_Tot=vcompras;
    ptr->Pago_tot=0;
}
// Función para liberar la memoria
void LiberarMem(CLIENTE ** ptr) {
    free(*ptr);
    *ptr = NULL;
}
void LiberarMem2(CLIENTE * ptr) {
    free(ptr);
    ptr = NULL;
}
//Función para calcular
void CalcTot(CLIENTE *ptr) {
    double discount = 0.95;
    if (!strcmp("B", ptr->tipo))
        ptr->Pago_tot = ptr->compras_Tot * 0.92;
    else if (!strcmp("P", ptr->tipo))
        ptr->Pago_tot = ptr->compras_Tot * 0.87;
    else if (!strcmp("VIP", ptr->tipo))
        ptr->Pago_tot = ptr->compras_Tot * 0.82;
    if (ptr->frecuente == 'S')
        ptr->Pago_tot *= discount;
}
// Función para imprimir info
void Imprime(CLIENTE * ptr) {
    printf("Clave: %s\n", ptr->clave);
    printf("Nombre: %s\n", ptr->nombre);
    printf("Tipo: %s\n", ptr->tipo);
    printf("Total: %lf\n", ptr->compras_Tot);
    printf("Compra frecuente: %c\n", ptr->frecuente);
    printf("Total a pagar: %lf\n", ptr->Pago_tot);
}
int main(){
    CLIENTE * PtrCL = NULL;
    AsignMem(&PtrCL);
    AsignDat(PtrCL, "12563", "Max Mendez", "VIP",5000,'S');
    CalcTot(PtrCL);
    Imprime(PtrCL);
    LiberarMem(&PtrCL);
    return 0;
}
