#include <stdio.h>
#include <stdlib.h>
typedef struct Nodo {
    void *dato;
    int tipo;
    struct Nodo *ant;
    struct Nodo *sig;
} Nodo;
typedef struct {
    Nodo *cab;
    Nodo *fin;
} DLL;
DLL* crearDLL() {
    DLL *lista = (DLL *)malloc(sizeof(DLL));
    if (lista == NULL) {
        printf("Error.\n");
        exit(EXIT_FAILURE);
    }
    lista->cab = NULL;
    lista->fin = NULL;
    return lista;
}
void insertFin(DLL *lista, void *dato, int tipo) {
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error.\n");
        exit(EXIT_FAILURE);
    }
    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;
    nuevoNodo->tipo = tipo;
    if (lista->fin == NULL) {
        nuevoNodo->ant = NULL;
        lista->cab = nuevoNodo;
        lista->fin = nuevoNodo;
    } else {
        nuevoNodo->ant = lista->fin;
        lista->fin->sig = nuevoNodo;
        lista->fin = nuevoNodo;
    }
}
void imprimeDLL(DLL *lista) {
    Nodo *current = lista->cab;
    printf("Lista: ");
    while (current != NULL) {
        switch (current->tipo) {
            case 1:
                printf("%d ", *((int *)current->dato));
                break;
            case 2:
                printf("'%c' ", *((char *)current->dato));
                break;
            case 3:
                printf("%f ", *((float *)current->dato));
                break;
            default:
                printf("Desconocido. ");
        }
        current = current->sig;
    }
    printf("\n");
}

void captureList(DLL *lista) {
    int opc;
    do {
        printf("Elige el tipo de dato: int (1), char (2), float (3): \n");
        scanf("%d", &opc);
        void *data;
        switch (opc) {
            case 1:
                printf("Dame el numero: ");
                data = malloc(sizeof(int));
                scanf("%d", (int *)data);
                insertFin(lista, data, 1);
                break;
            case 2:
                printf("Dame el caracter: ");
                data = malloc(sizeof(char));
                scanf(" %c", (char *)data);
                insertFin(lista, data, 2);
                break;
            case 3:
                printf("Dame el numero: ");
                data = malloc(sizeof(float));
                scanf("%f", (float *)data);
                insertFin(lista, data, 3);
                break;
            default:
                printf("Otra vez.\n");
                continue;
        }

        printf("Otro? (1=si, 0=no): ");
        scanf("%d", &opc);
    } while (opc != 0);
}

void liberarDLL(DLL *lista) {
    Nodo *current = lista->cab;
    Nodo *sig;
    while (current != NULL) {
        sig = current->sig;
        free(current);
        current = sig;
    }
    free(lista);
}

int main() {
    DLL *lista = crearDLL();
    captureList(lista);
    imprimeDLL(lista);
    liberarDLL(lista);

    return 0;
}
    
