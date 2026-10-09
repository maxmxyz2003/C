#include <stdio.h>
#include <stdlib.h>
#include <String.h>
//Estructura CLIENTE con Clave, Nombre, Tipo, Compras totales, Si es frecuente, Total a pagar (condicional) 
typedef struct{
    char clave[50];
    char nombre[50];
    char tipo[50];
    double compras_Tot;
    char frecuente[50];
    double Pago_tot;
}CLIENTE;
// Función para asignar memoria al apuntador 
void AsignMem(CLIENTE **ptr, int n){
    *ptr = (CLIENTE *)malloc(n * sizeof(CLIENTE));
    if (*ptr)
        return;
    else{
        printf("Asignación de memoria fallido.\n");
        exit(1);
    }
}
// Función para modificar el valor del apuntador
void AsignDat(CLIENTE *ptr, int n){
    char cadenaTemp[50];
    for (int i = 0; i < n; i++){
        printf("Introduce el nombre del cliente %d: ", i+1);
        scanf(" %50[^\n]s", cadenaTemp);
        strcpy((ptr + i)->nombre, cadenaTemp);
        printf("Introduce la clave del cliente %d: ", i+1);
        scanf(" %50[^\n]s", cadenaTemp);
        strcpy((ptr + i)->clave, cadenaTemp);
        printf("Introduce el tipo del cliente %d (B/P/VIP): ", i+1);
        scanf(" %50[^\n]s", cadenaTemp);
        strcpy((ptr + i)->tipo, cadenaTemp);
        printf("Introduce si el cliente %d es frecuente (S/N): ", i+1);
        scanf(" %50[^\n]s", cadenaTemp);
        strcpy((ptr + i)->frecuente, cadenaTemp);
        printf("Introduce la compra total del cliente %d: ", i+1);
        scanf("%lf", &(ptr + i)->compras_Tot);
        (ptr + i)->Pago_tot = 0;
    }
}
//Hallar mas y menos compras recursivo
CLIENTE HallarMenosCompras(CLIENTE arr[], int size) {
    if (size == 1) {
        return arr[0];
    } else {
        CLIENTE smallest = HallarMenosCompras(arr + 1, size - 1);
        return (arr[0].Pago_tot < smallest.Pago_tot) ? arr[0] : smallest;
    }
}
CLIENTE HallarMasCompras(CLIENTE arr[], int size) {
    if (size == 1) {
        return arr[0];
    } else {
        CLIENTE big = HallarMasCompras(arr + 1, size - 1);
        return (arr[0].Pago_tot > big.Pago_tot) ? arr[0] : big;
    }
}
// Función para liberar la memoria
void LiberarMem(CLIENTE **ptr){
    free(*ptr);
    *ptr = NULL;
}
// Función para calcular total a pagar segun las condiciones
void CalcTot(CLIENTE *ptr, int index){
    double desc = 0.95;
    if (!strcmp("B", (ptr + index)->tipo)) // Si es cliente Basico se le hace 8% de descuento
        (ptr + index)->Pago_tot = (ptr + index)->compras_Tot * 0.92;
    else if (!strcmp("P", (ptr + index)->tipo))// Si es cliente Premium se le hace 13% de descuento
        (ptr + index)->Pago_tot = (ptr + index)->compras_Tot * 0.87;
    else if (!strcmp("VIP", (ptr + index)->tipo))// Si es cliente VIP se le hace 18% de descuento
        (ptr + index)->Pago_tot = (ptr + index)->compras_Tot * 0.82;
    if (!strcmp("S", (ptr + index)->frecuente)) // Si es frecuente se le hace un 5% de descuento de lo que ya tiene
        (ptr + index)->Pago_tot *= desc;
}
//Calcular el pago de todos los clientes
double CalcTotdTodos(CLIENTE *ptr, int n){
    double total;
    for (int i = 0; i <n; i++)
        total+=(ptr+i)->Pago_tot;
    return total;
}
// Función que calcula cada tipo de cliente
void Tipos(CLIENTE *ptr, int n){
    int contB = 0, contP = 0, contVIP = 0;
    for (int index = 0; index < n; index++){
        if (!strcmp("B", (ptr + index)->tipo))
            contB++;
        else if (!strcmp("P", (ptr + index)->tipo))
            contP++;
        else if (!strcmp("VIP", (ptr + index)->tipo))
            contVIP++;
    }
    printf("Son %d clientes basicos\n", contB);
    printf("Son %d clientes premium\n", contP);
    printf("Son %d clientes VIP\n", contVIP);
}
// Función para imprimir info
void Imprime(CLIENTE *ptr, int n){
    printf("--------------\n");
    for (int i = 0; i <n; i++){
        printf("Clave: %s\n", (ptr+i)->clave);
        printf("Nombre: %s\n", (ptr+i)->nombre);
        printf("Tipo: %s\n", (ptr+i)->tipo);
        printf("Compra frecuente: %s\n",(ptr+i)->frecuente);
        printf("Total a pagar: %lf\n", (ptr+i)->Pago_tot);
        printf("--------------\n");
    }
}
int main(void){
    CLIENTE *PtrCL = NULL;
    int N;
    printf("Introduce el num de clientes:\n");
    scanf("%d", &N);
    //Asignamos memoria
    AsignMem(&PtrCL, N);
    //Asignamos los datos del arreglo dinamico de estructuras
    AsignDat(PtrCL, N);
    for (int i = 0; i < N; i++)//Calculamos el total de todos los clientes ya obtenida la informacion necesaria
        CalcTot(PtrCL, i);
    //Imprimimos los datos de cada cliente
    Imprime(PtrCL,N);
    //Imprimimos los tipos
    Tipos(PtrCL, N);
    //Imprimimos el total de compras 
    printf("Total de todos %lf", CalcTotdTodos(PtrCL,N));    
    //Buscamos el que menos compra
    CLIENTE elmasalto=HallarMenosCompras(PtrCL,N);
    printf("\nMas bajo: %s Compra: %lf\n", elmasalto.nombre,elmasalto.Pago_tot);
    //Liberamos la memoria
    LiberarMem(&PtrCL);
    return 0;
}

