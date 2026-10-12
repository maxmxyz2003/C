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
int padreHijo(struct Nodo* raiz, int datoPadre, int datoHijo) {
    if (!raiz)
        return 0;
    if (raiz->dato == datoPadre) {
        if ((raiz->izquierda && raiz->izquierda->dato == datoHijo) ||
            (raiz->derecha && raiz->derecha->dato == datoHijo)) {
            return 1;
        }
    }
    return padreHijo(raiz->izquierda, datoPadre, datoHijo) || padreHijo(raiz->derecha, datoPadre, datoHijo);
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
    int p=50;
    int h=30;
    printf("%d padre de %d : %d",p,h,padreHijo(raiz,p,h));
    return 0;
}
