/*
Autor: Maximiliano Mendez Hernandez
Fecha: 05/10/23
Descripcion: Adaptar listas ligadas como una cola dinamica 
*/
#include <stdio.h>
#include <stdlib.h>
// Nodo
typedef struct Nodo{
    int dato;
    struct Nodo *Link;
}Nodo;
typedef struct Nodo * Queue;
//Iniciar Queue
void IniQueue(Queue *cab){
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
// Funcion enQueue 
Nodo *enQueue(Nodo *cab, int dato)
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
// Funcion deQueue
Nodo *deQueue(Nodo *cab)
{
    if (cab == NULL){
        return cab;
    }

    Nodo *temp = cab;
    cab=cab->Link;
    free(temp);
    return cab;
}
// Funcion para capturar Queue
Nodo *capturaQueue()
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
            cab = enQueue(cab, dato);
        }
        printf("Otro? [1=S, 0=N]: ");
        scanf("%d", &opc);
    } while (opc != 0);
    return cab;
}

// Imprimir Queue
void imprimeQueue(Nodo *cab)
{
    Nodo *temp = cab;
    printf("Queue: ");
    while (temp != NULL)
    {
        printf("%d ", temp->dato);
        temp = temp->Link;
    }
    printf("\n");
}
// Liberar Queue
void freeQueue(Nodo *cab)
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
    IniQueue(&cab);
    printf("Capturar datos de la Queue :\n");
    cab = capturaQueue();
    printf("Imprimiendo Queue:\n");
    imprimeQueue(cab);
    printf("Eliminando 2 datos con deQueue: \n");
    cab = deQueue(cab); // DesaQueuer 
    cab = deQueue(cab); // DesaQueuer 
    printf("Imprimiendo Queue despues de eliminacion de 2 elementos:\n");
    imprimeQueue(cab);
    //Libera Queue
    printf("Liberando Queue\n");
    freeQueue(cab);
    return 0;
}
