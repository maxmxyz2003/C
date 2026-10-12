#include <stdio.h>
#include <stdlib.h>
typedef struct Nodo {
    int dato;
    struct Nodo* sig;
} Nodo; 

typedef struct Queue {
    Nodo* inicio;
    Nodo* fin;
} Queue;

void InicQueue(Queue* q) {
    q->inicio = NULL;
    q->fin = NULL;
}
//Funcion para crear nodo
Nodo* creaNodo(int dato) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = dato;
    nuevo->sig = NULL;
    return nuevo;
}
//Funcion enQueue
void enQueue(Queue* q, int dato) {
    Nodo* nuevo = creaNodo(dato);
    if (q->fin == NULL) {
        // Si la cola está vacía
        q->inicio = nuevo;
        q->fin = nuevo;
    } else {
        // Si ya hay elementos en la cola
        q->fin->sig = nuevo;
        q->fin = nuevo;
    }
}
//Funcion deQueue
void deQueue(Queue* q) {
    if (!q->inicio) {
        printf("La cola está vacía. No se puede hacer deQueue.\n");
        return;
    }
    Nodo* temp = q->inicio;
    q->inicio = q->inicio->sig;
    free(temp);
    if (q->inicio == NULL) {
        q->fin = NULL;
    }
}
//Funcion capturar Queue
void capturaQueue(Queue* q) {
    int dato;
    int opc;
    do {
        printf("Ingresa dato: ");
        scanf("%d", &dato);
        enQueue(q, dato);
        printf("Otro? [1=S, 0=N]: ");
        scanf("%d", &opc);
    } while (opc != 0);
}
//Funcion imprimir Queue
void imprimeQueue(Queue* q) {
    Nodo* temp = q->inicio;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->dato);
        temp = temp->sig;
    }
    printf("\n");
}
//Funcion liberar Queue
void freeQueue(Queue* q) {
    while (q->inicio != NULL) {
        deQueue(q);
    }
}

int main(void) {
    Queue cab;
    InicQueue(&cab);
    printf("Capturar datos de la Queue :\n");
    capturaQueue(&cab);
    printf("Imprimiendo Queue:\n");
    imprimeQueue(&cab);
    printf("Eliminando 2 datos con deQueue: \n");
    deQueue(&cab);
    deQueue(&cab);
    printf("Imprimiendo Queue despues de eliminacion de 2 elementos:\n");
    imprimeQueue(&cab);
    // Libera Queue
    printf("Liberando Queue\n");
    freeQueue(&cab);
    return 0;
}
