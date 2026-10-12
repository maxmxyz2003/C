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
// Función para realizar un recorrido en orden (in-order traversal) del árbol
void inOrden(struct Nodo* nodo) {
    if (nodo != NULL) {
        inOrden(nodo->izquierda);
        printf("%d ", nodo->dato);
        inOrden(nodo->derecha);
    }
}
int calc_w(struct Nodo* raiz){
    if (!raiz){
        return 0;
    }else{
        return 1+calc_w(raiz->izquierda)+calc_w(raiz->derecha);
    }
}
int iguales(struct Nodo* raiz1, struct Nodo* raiz2) {
    if (!raiz1 && !raiz2)
        return 1; // Ambos árboles son nulos, considerados iguales
    if (!raiz1 || !raiz2)
        return 0; // Uno de los árboles es nulo, considerados diferentes
    if (raiz1->dato != raiz2->dato) 
        return 0; // Los valores de los nodos son diferentes, árboles diferentes
    // Verificar recursivamente la igualdad en ambos subárboles
    return iguales(raiz1->izquierda, raiz2->izquierda) && iguales(raiz1->derecha, raiz2->derecha);
}

int countLeaves(struct Nodo* raiz){
    if (!raiz){
        return 0;
    }else if (!raiz->derecha&&!raiz->izquierda){
        return 1;
    }else{
        return countLeaves(raiz->izquierda)+countLeaves(raiz->derecha);
    }
}
// Función principal
int main() {
    struct Nodo* raiz = NULL;
    struct Nodo* raiz2 = NULL;
    raiz = insertar(raiz, 50);
    insertar(raiz, 30);
    insertar(raiz, 20);
    insertar(raiz, 40);
    insertar(raiz, 70);
    insertar(raiz, 60);
    insertar(raiz, 80);
    insertar(raiz, 90);
    raiz2 = insertar(raiz, 50);
    insertar(raiz2, 30);
    insertar(raiz2, 20);
    insertar(raiz2, 40);
    insertar(raiz2, 70);
    insertar(raiz2, 60);
    insertar(raiz2, 80);
    insertar(raiz2, 90);
    inOrden(raiz);
    printf("\n");
    inOrden(raiz2);
    printf("\n");
    printf("Iguales: %d\n", iguales(raiz2,raiz));
    return 0;
}
