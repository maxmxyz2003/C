#include <stdio.h>
#include <stdlib.h>
// Nodo
typedef struct Nodo{
    int dato;
    struct Nodo *Link;
} Nodo;
typedef struct Nodo * Pila;
//Iniciar pila
void IniPila(Pila *cab){
    (*cab)=NULL;
}
//Funcion para crear nuevo Nodo
Nodo *crearNodo(int dato){
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo == NULL){
        printf("Fallo de asignacion de memoria.\n");
        exit(1);
    }
    nuevo->dato = dato;
    nuevo->Link = NULL;
    return nuevo;
}
// Funcion push 
Nodo *insertFin(Nodo *cab, int dato)
{
    Nodo *nuevo = crearNodo(dato);
    if (cab == NULL){
        return nuevo;
    }
    Nodo *temp = cab;
    while (temp->Link){
        temp = temp->Link;
    }
    temp->Link = nuevo;
    return cab;
}
// Funcion pop
Nodo *ElimFin(Nodo *cab)
{
    if (cab == NULL){
        return cab;
    }
    Nodo *temp = cab;
    while ((temp->Link)->Link){
        temp = temp->Link;
    }
    free(temp->Link);
    temp->Link=NULL;
    return cab;
}

// Funcion para capturar Pila
Nodo *capturaPila()
{
    Nodo *cab = NULL;
    int dato;
    int opc;
    do
    {
        printf("Ingresa dato: ");
        scanf("%d", &dato);
        if (cab == NULL)
        {
            cab = crearNodo(dato);
        }
        else{
                cab = insertFin(cab, dato);
        }
        printf("Otro? [1=S, 0=N]: ");
        scanf("%d", &opc);
    } while (opc != 0);
    return cab;
}

// Function to display Pila
void imprimePila(Nodo *cab)
{
    Nodo *temp = cab;
    printf("Pila: ");
    while (temp != NULL)
    {
        printf("%d ", temp->dato);
        temp = temp->Link;
    }
    printf("\n");
}
// Liberar Pila
void freePila(Nodo *cab)
{
    Nodo *temp;
    while (cab)
    {
        temp = cab;
        cab = cab->Link;
        free(temp);
    }
}
int main(void){
    Nodo *cab;
    IniPila(&cab);
    printf("Capturar datos de la pila :\n");
    cab = capturaPila();
    printf("Imprimiendo pila:\n");
    imprimePila(cab);
    printf("Desapilando 2 datos: \n");
    cab = ElimFin(cab); // Desapilar 
    cab = ElimFin(cab); // Desapilar 
    printf("Imprimiendo pila despues de eliminacion de 2 elementos:\n");
    imprimePila(cab);
    //Libera Pila
    freePila(cab);
    return 0;
}
