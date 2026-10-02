#include <stdio.h>
#include <stdlib.h>
typedef struct Nodo {
    int dato;
    struct Nodo* sig;
    struct Nodo* ant;
} Nodo;

typedef struct {
    Nodo* cab;
    Nodo* cola;
} DLL;

void iniciarLista(DLL* list) {
    list->cab = NULL;
    list->cola = NULL;
}

void insertAlInic(DLL* list, int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->sig = list->cab;
    nuevoNodo->ant = NULL;
    
    if (list->cab)
        list->cab->ant = nuevoNodo;
    else
        list->cola = nuevoNodo;

    list->cab = nuevoNodo;
}

void insertAlFin(DLL* list, int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;
    nuevoNodo->ant = list->cola;
    
    if (list->cola)
        list->cola->sig = nuevoNodo;
    else
        list->cab = nuevoNodo;

    list->cola = nuevoNodo;
}

void ElimNodoRef(DLL* list, int dato) {
    Nodo* aux = list->cab;

    while (aux) {
        if (aux->dato == dato) {
            if (aux == list->cab) {
                list->cab = aux->sig;
                if (list->cab)
                    list->cab->ant = NULL;
                else
                    list->cola = NULL;
            } else if (aux == list->cola) {
                list->cola = aux->ant;
                list->cola->sig = NULL;
            } else {
                aux->ant->sig = aux->sig;
                aux->sig->ant = aux->ant;
            }

            free(aux);
            return;
        }

        aux = aux->sig;
    }
}

void ElimNodoIn(DLL *list) {
    if (list->cab == NULL)
        return;

    Nodo* aux = list->cab;
    list->cab = list->cab->sig;

    if (list->cab)
        list->cab->ant = NULL;
    else
        list->cola = NULL;

    free(aux);
}

void ElimNodoFin(DLL *list) {
    if (list->cola == NULL)
        return;

    Nodo* aux = list->cola;
    list->cola = list->cola->ant;

    if (list->cola)
        list->cola->sig = NULL;
    else
        list->cab = NULL;

    free(aux);
}

void imprimirDLL(DLL* list) {
    Nodo* aux = list->cab;

    while (aux) {
        printf("%d ", aux->dato);
        aux = aux->sig;
    }

    printf("\n");
}

int main(void) {
    DLL list;
    iniciarLista(&list);

    printf("Insertamos al inicio 10\n");
    insertAlInic(&list, 10);
    printf("Insertamos al inicio 5\n");
    insertAlInic(&list, 5);
    printf("Insertamos al final 15\n");
    insertAlFin(&list, 15);
    printf("Insertamos al final 20\n");
    insertAlFin(&list, 20);

    printf("Imprimimos:\n");
    imprimirDLL(&list);

    printf("Eliminamos al 5\n");
    ElimNodoRef(&list, 5);

    printf("Lista actual despues de los cambios:\n");
    imprimirDLL(&list);

    printf("Eliminamos al inicio y al final\n");
    ElimNodoFin(&list);
    ElimNodoIn(&list);

    printf("Lista actual despues de las eliminaciones:\n");
    imprimirDLL(&list);

    return 0;
}
