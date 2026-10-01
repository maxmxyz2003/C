#include <stdio.h>
#include <stdlib.h>
typedef struct Nodo {
    int dato;
    struct Nodo* sig;
} Nodo;
typedef struct CLL {
    Nodo* cab;
} CLL;
Nodo* crearNodo(int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevoNodo) {
        printf("Error \n");
        return NULL;
    }
    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
}
void insertAlIn(CLL* listaC, int dato) {
    Nodo* nuevoNodo = crearNodo(dato);
    if (!nuevoNodo)
        return;
    if (!listaC->cab) {
        listaC->cab = nuevoNodo;
        nuevoNodo->sig = listaC->cab;
    } else {
        Nodo* temp = listaC->cab;
        while (temp->sig != listaC->cab)
            temp = temp->sig;
        temp->sig = nuevoNodo;
        nuevoNodo->sig = listaC->cab;
        listaC->cab = nuevoNodo;
    }
}
void insertAlFin(CLL* listaC, int dato) {
    Nodo* nuevoNodo = crearNodo(dato);
    if (nuevoNodo == NULL)
        return;
    if (listaC->cab == NULL) {
        listaC->cab = nuevoNodo;
        nuevoNodo->sig = listaC->cab;
    } else {
        Nodo* temp = listaC->cab;
        while (temp->sig != listaC->cab)
            temp = temp->sig;
        temp->sig = nuevoNodo;
        nuevoNodo->sig = listaC->cab;
    }
}

void ElimNodo(CLL* listaC, int dato) {
    if (listaC->cab == NULL) {
        printf("Lista vacia\n");
        return;
    }
    Nodo* temp = listaC->cab;
    Nodo* prev = NULL;
    while (temp->dato != dato && temp->sig != listaC->cab) {
        prev = temp;
        temp = temp->sig;
    }
    if (temp->dato != dato) {
        printf("Nodo no encontrado\n");
        return;
    }
    if (temp == listaC->cab) {
        Nodo* last = listaC->cab;
        while (last->sig != listaC->cab)
            last = last->sig;
        listaC->cab = listaC->cab->sig;
        last->sig = listaC->cab;
        free(temp);
    } else {
        prev->sig = temp->sig;
        free(temp);
    }
}
void imprimeListaC(CLL* listaC) {
    Nodo* temp = listaC->cab;
    if (temp == NULL) {
        printf("Lista vacia\n");
        return;
    }
    do {
        printf("%d \t", temp->dato);
        temp = temp->sig;
    } while (temp != listaC->cab);
    printf("\n");
}

int main() {
    CLL listaC;
    listaC.cab = NULL;
    printf("Agregamos 10 al final\n");
    insertAlFin(&listaC, 10);
    printf("Agregamos 20 al final\n");
    insertAlFin(&listaC, 20);
    printf("Agregamos 5 al inicio\n");
    insertAlIn(&listaC, 5);
    printf("Imprimimos: \n");
    imprimeListaC(&listaC);
    printf("Eliminamos el 20\n");
    ElimNodo(&listaC, 20);
    printf("Imprimimos: \n");
    imprimeListaC(&listaC);
    return 0;
}
