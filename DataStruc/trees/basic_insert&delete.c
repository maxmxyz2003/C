#include <stdio.h>
#include <stdlib.h>
// Definición de la estructura del nodo del árbol binario
struct Nodo {
    int dato;
    struct Nodo* izquierda;
    struct Nodo* derecha;
};
// Función para crear un nuevo nodo del árol
struct Nodo* crearNodo(int dato) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;
    return nuevoNodo;
}
// Función para insertar un nuevo nodo en el árbol binario
struct Nodo* insertar(struct Nodo* raiz, int dato) {
    if (raiz == NULL) {
        return crearNodo(dato);
    }
    if (dato < raiz->dato) {
        raiz->izquierda = insertar(raiz->izquierda, dato);
    } else if (dato > raiz->dato) {
        raiz->derecha = insertar(raiz->derecha, dato);
    }
    return raiz;
}
// Función para encontrar el nodo mínimo en un árbol
struct Nodo* encontrarMinimo(struct Nodo* nodo) {
    struct Nodo* actual = nodo;
    while (actual && actual->izquierda != NULL) {
        actual = actual->izquierda;
    }
    return actual;
}

// Función para eliminar un nodo en el árbol binario
struct Nodo* eliminar(struct Nodo* raiz, int dato) {
    if (raiz == NULL)
        return raiz;
    if (dato < raiz->dato) {
        raiz->izquierda = eliminar(raiz->izquierda, dato);
    } else if (dato > raiz->dato) {
        raiz->derecha = eliminar(raiz->derecha, dato);
    } else {
        if (raiz->izquierda == NULL) {
            struct Nodo* temp = raiz->derecha;
            free(raiz);
            return temp;
        } else if (raiz->derecha == NULL) {
            struct Nodo* temp = raiz->izquierda;
            free(raiz);
            return temp;
        }
        struct Nodo* temp = encontrarMinimo(raiz->derecha);
        raiz->dato = temp->dato;
        raiz->derecha = eliminar(raiz->derecha, temp->dato);
    }
    return raiz;
}
int delete(struct Nodo **raiz, int dato){
    int res;
    struct Nodo * aux;
    if (!*raiz)
        return 0;
    else{
        if ((*raiz)->dato==dato){
            aux=*raiz;
            res=1;
            if (!(*raiz)->izquierda)
                *raiz=(*raiz)->derecha;
            else{
                if(!(*raiz)->derecha)
                    *raiz=(*raiz)->izquierda;
                else{
                    aux=aux->izquierda;
                    while (aux->derecha)
                        aux=aux->derecha;
                    (*raiz)->dato=aux->dato;
                    res=delete(&(*raiz)->izquierda,aux->dato);
                    aux=NULL;                    
                }                
            }
        }
        
    }
    free(aux);
    return res;
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
    printf("Recorrido en orden del arbol antes de la eliminacion: ");
    inOrden(raiz);
    printf("\n");
    raiz = eliminar(raiz, 50); // Eliminar un nodo
    printf("Recorrido en orden del arbol despues de la eliminacion: ");
    inOrden(raiz);
    printf("\n");
    return 0;
}
