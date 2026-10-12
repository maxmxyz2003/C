#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo del árbol AVL
struct NodoAVL {
    int dato;
    struct NodoAVL* izquierda;
    struct NodoAVL* derecha;
    int altura;
};

// Función para obtener la altura de un nodo del árbol AVL
int altura(struct NodoAVL* nodo) {
    if (nodo == NULL) {
        return 0;
    }
    return nodo->altura;
}

// Función para obtener el máximo de dos enteros
int maximo(int a, int b) {
    return (a > b) ? a : b;
}

// Función para crear un nuevo nodo del árbol AVL
struct NodoAVL* crearNodo(int dato) {
    struct NodoAVL* nuevoNodo = (struct NodoAVL*)malloc(sizeof(struct NodoAVL));
    nuevoNodo->dato = dato;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;
    nuevoNodo->altura = 1; // Nuevo nodo tiene altura inicial 1
    return nuevoNodo;
}

// Función para obtener el factor de equilibrio de un nodo del árbol AVL
int factorEquilibrio(struct NodoAVL* nodo) {
    if (nodo == NULL) {
        return 0;
    }
    return altura(nodo->izquierda) - altura(nodo->derecha);
}

// Función para realizar una rotación hacia la derecha en un subárbol
struct NodoAVL* rotacionDerecha(struct NodoAVL* y) {
    struct NodoAVL* x = y->izquierda;
    struct NodoAVL* T2 = x->derecha;

    // Realizar la rotación
    x->derecha = y;
    y->izquierda = T2;

    // Actualizar alturas
    y->altura = maximo(altura(y->izquierda), altura(y->derecha)) + 1;
    x->altura = maximo(altura(x->izquierda), altura(x->derecha)) + 1;

    return x;
}

// Función para realizar una rotación hacia la izquierda en un subárbol
struct NodoAVL* rotacionIzquierda(struct NodoAVL* x) {
    struct NodoAVL* y = x->derecha;
    struct NodoAVL* T2 = y->izquierda;

    // Realizar la rotación
    y->izquierda = x;
    x->derecha = T2;

    // Actualizar alturas
    x->altura = maximo(altura(x->izquierda), altura(x->derecha)) + 1;
    y->altura = maximo(altura(y->izquierda), altura(y->derecha)) + 1;

    return y;
}

// Función para insertar un nodo en un árbol AVL
struct NodoAVL* insertar(struct NodoAVL* raiz, int dato) {
    // Realizar la inserción normal de un nodo BST
    if (raiz == NULL) {
        return crearNodo(dato);
    }

    if (dato < raiz->dato) {
        raiz->izquierda = insertar(raiz->izquierda, dato);
    } else if (dato > raiz->dato) {
        raiz->derecha = insertar(raiz->derecha, dato);
    } else { // No se permiten duplicados en un árbol AVL
        return raiz;
    }

    // Actualizar la altura del nodo actual
    raiz->altura = 1 + maximo(altura(raiz->izquierda), altura(raiz->derecha));

    // Obtener el factor de equilibrio del nodo para verificar el desequilibrio
    int balance = factorEquilibrio(raiz);

    // Casos de rotaciones según el desequilibrio
    // Caso izquierda-izquierda
    if (balance > 1 && dato < raiz->izquierda->dato) {
        return rotacionDerecha(raiz);
    }
    // Caso derecha-derecha
    if (balance < -1 && dato > raiz->derecha->dato) {
        return rotacionIzquierda(raiz);
    }
    // Caso izquierda-derecha
    if (balance > 1 && dato > raiz->izquierda->dato) {
        raiz->izquierda = rotacionIzquierda(raiz->izquierda);
        return rotacionDerecha(raiz);
    }
    // Caso derecha-izquierda
    if (balance < -1 && dato < raiz->derecha->dato) {
        raiz->derecha = rotacionDerecha(raiz->derecha);
        return rotacionIzquierda(raiz);
    }

    return raiz;
}

// Función para encontrar el nodo con el valor mínimo en un árbol AVL
struct NodoAVL* nodoMinimo(struct NodoAVL* raiz) {
    struct NodoAVL* actual = raiz;
    while (actual->izquierda != NULL) {
        actual = actual->izquierda;
    }
    return actual;
}

// Función para eliminar un nodo en un árbol AVL
struct NodoAVL* eliminar(struct NodoAVL* raiz, int dato) {
    // Realizar la eliminación normal de un nodo BST
    if (raiz == NULL) {
        return raiz;
    }

    if (dato < raiz->dato) {
        raiz->izquierda = eliminar(raiz->izquierda, dato);
    } else if (dato > raiz->dato) {
        raiz->derecha = eliminar(raiz->derecha, dato);
    } else {
        // Nodo encontrado, realizar eliminación

        // Caso con un solo hijo o sin hijo
        if ((raiz->izquierda == NULL) || (raiz->derecha == NULL)) {
            struct NodoAVL* temp = raiz->izquierda ? raiz->izquierda : raiz->derecha;

            // Caso sin hijo
            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else { // Caso con un solo hijo
                *raiz = *temp;
            }
            free(temp);
        } else {
            // Nodo con dos hijos, obtener el sucesor inorden (nodo con el valor mínimo en el subárbol derecho)
            struct NodoAVL* temp = nodoMinimo(raiz->derecha);

            // Copiar los datos del sucesor inorden al nodo actual
            raiz->dato = temp->dato;

            // Eliminar el sucesor inorden
            raiz->derecha = eliminar(raiz->derecha, temp->dato);
        }
    }

    // Si el árbol tenía solo un nodo, regresar
    if (raiz == NULL) {
        return raiz;
    }

    // Actualizar la altura del nodo actual
    raiz->altura = 1 + maximo(altura(raiz->izquierda), altura(raiz->derecha));

    // Obtener el factor de equilibrio del nodo para verificar el desequilibrio
    int balance = factorEquilibrio(raiz);

    // Casos de rotaciones según el desequilibrio (similar a la inserción)
    // Caso izquierda-izquierda
    if (balance > 1 && factorEquilibrio(raiz->izquierda) >= 0) {
        return rotacionDerecha(raiz);
    }
    // Caso derecha-derecha
    if (balance < -1 && factorEquilibrio(raiz->derecha) <= 0) {
        return rotacionIzquierda(raiz);
    }
    // Caso izquierda-derecha
    if (balance > 1 && factorEquilibrio(raiz->izquierda) < 0) {
        raiz->izquierda = rotacionIzquierda(raiz->izquierda);
        return rotacionDerecha(raiz);
    }
    // Caso derecha-izquierda
    if (balance < -1 && factorEquilibrio(raiz->derecha) > 0) {
        raiz->derecha = rotacionDerecha(raiz->derecha);
        return rotacionIzquierda(raiz);
    }

    return raiz;
}

// Función para realizar un recorrido en orden (in-order traversal) del árbol AVL
void inOrden(struct NodoAVL* nodo) {
    if (nodo != NULL) {
        inOrden(nodo->izquierda);
        printf("%d ", nodo->dato);
        inOrden(nodo->derecha);
    }
}

// Función principal
int main() {
    struct NodoAVL* raiz = NULL;

    raiz = insertar(raiz, 10);
    raiz = insertar(raiz, 20);
    raiz = insertar(raiz, 30);
    raiz = insertar(raiz, 40);
    raiz = insertar(raiz, 50);
    raiz = insertar(raiz, 25);

    printf("Árbol AVL después de la inserción: ");
    inOrden(raiz);
    printf("\n");

    raiz = eliminar(raiz, 30);

    printf("Árbol AVL después de la eliminación: ");
    inOrden(raiz);
    printf("\n");

    return 0;
}
