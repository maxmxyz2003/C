#include <stdio.h>
#include <stdlib.h>
// Definición de la estructura del nodo del árbol binario
struct Nodo {
    int dato;
    struct Nodo* izquierda;
    struct Nodo* derecha;
};
// Definición de la estructura de un nodo para la cola
struct ColaNodo {
    struct Nodo* nodo;
    struct ColaNodo* siguiente;
};
// Estructura de la cola
struct Cola {
    struct ColaNodo* frente;
    struct ColaNodo* final;
};
// Función para crear un nuevo nodo del árbol
struct Nodo* crearNodo(int dato) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;
    return nuevoNodo;
}

// Función para encolar un nodo en la cola
void encolar(struct Cola* cola, struct Nodo* nodo) {
    struct ColaNodo* nuevoColaNodo = (struct ColaNodo*)malloc(sizeof(struct ColaNodo));
    nuevoColaNodo->nodo = nodo;
    nuevoColaNodo->siguiente = NULL;
    if (cola->final == NULL) {
        cola->frente = cola->final = nuevoColaNodo;
    } else {
        cola->final->siguiente = nuevoColaNodo;
        cola->final = nuevoColaNodo;
    }
}
// Función para desencolar un nodo de la cola
struct Nodo* desencolar(struct Cola* cola) {
    if (cola->frente == NULL) {
        return NULL;
    }
    struct ColaNodo* temp = cola->frente;
    struct Nodo* nodo = temp->nodo;
    cola->frente = cola->frente->siguiente;
    if (cola->frente == NULL) {
        cola->final = NULL;
    }
    free(temp);
    return nodo;
}
// Función para recorrer el árbol por niveles usando una cola
void recorrerPorNiveles(struct Nodo* raiz) {
    if (raiz == NULL) {
        return;
    }
    struct Cola* cola = (struct Cola*)malloc(sizeof(struct Cola));
    cola->frente = cola->final = NULL;
    encolar(cola, raiz);
    while (cola->frente) {
        struct Nodo* nodoActual = desencolar(cola);
        printf("%d ", nodoActual->dato);
        if (nodoActual->izquierda != NULL) {
            encolar(cola, nodoActual->izquierda);
        }
        if (nodoActual->derecha != NULL) {
            encolar(cola, nodoActual->derecha);
        }
    }
    free(cola);
}
// Función principal
int main() {
    struct Nodo* raiz = crearNodo(1);
    raiz->izquierda = crearNodo(2);
    raiz->derecha = crearNodo(3);
    raiz->izquierda->izquierda = crearNodo(4);
    raiz->izquierda->derecha = crearNodo(5);
    raiz->derecha->izquierda = crearNodo(6);
    raiz->derecha->derecha = crearNodo(7);
    printf("Recorrido por niveles del arbol: ");
    recorrerPorNiveles(raiz);
    printf("\n");
    return 0;
}
