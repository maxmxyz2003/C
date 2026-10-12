#include <stdio.h>
#include <stdlib.h>
// Definición de la estructura del nodo del árbol binario
struct Nodo {
    int dato;
    struct Nodo* izquierda;
    struct Nodo* derecha;
};
// Función para crear un nuevo nodo del árbol
struct Nodo* crearNodo(int dato) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;
    return nuevoNodo;
}
// Función para insertar un nuevo nodo en el árbol binario
struct Nodo* insertar(struct Nodo* raiz, int dato) {
    if (raiz == NULL)
        return crearNodo(dato);
    if (dato < raiz->dato)
        raiz->izquierda = insertar(raiz->izquierda, dato);
    else if (dato > raiz->dato)
        raiz->derecha = insertar(raiz->derecha, dato);
    return raiz;
}
int Hermanos(struct Nodo* raiz, int dato1, int dato2) {
    if (!raiz)
        return 0;
    if (raiz->izquierda && raiz->derecha) {
        if ((raiz->izquierda->dato == dato1 && raiz->derecha->dato == dato2)||raiz->izquierda->dato == dato2 && raiz->derecha->dato == dato1)
            return 1;
    }
    return Hermanos(raiz->izquierda, dato1, dato2) || Hermanos(raiz->derecha, dato1, dato2);
}

// Función para realizar un recorrido en orden (in-order traversal) del árbol
void inOrden(struct Nodo* nodo) {
    if (nodo != NULL) {
        inOrden(nodo->izquierda);
        printf("%d ", nodo->dato);
        inOrden(nodo->derecha);
    }
}
// Función principal
int main() {
    struct Nodo* raiz = NULL;
    raiz = insertar(raiz, 50);
    insertar(raiz, 30);
    insertar(raiz, 20);
    insertar(raiz, 40);
    insertar(raiz, 70);
    insertar(raiz, 60);
    insertar(raiz, 80);
    // insertar(raiz, 90);
    printf("Recorrido en orden del arbol: ");
    inOrden(raiz);
    printf("\n");
    int h5=60;
    int h6=80;
    printf("%d hermano de %d : %d",h5,h6,Hermanos(raiz,h5,h6));
    return 0;
}
