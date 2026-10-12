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
int countLeaves(struct Nodo* raiz){
    if (!raiz){
        return 0;
    }else if (!raiz->derecha&&!raiz->izquierda){
        return 1;
    }else{
        return countLeaves(raiz->izquierda)+countLeaves(raiz->derecha);
    }
}
int search_Val(struct Nodo* raiz, int b){
    int res;
    if (!raiz)
        return 0;
    else{
        if (raiz->dato==b){
            res= 1;
        }else{
            res=search_Val(raiz->izquierda,b);
            if (!res){
                res=search_Val(raiz->derecha,b);
            }            
        }
    }
    return res;
}
int calc_lvl(struct Nodo* raiz, int b){
    int lvl=0;
    if (!raiz)
        return -1;
    if (!search_Val(raiz,b))
        return -1;
    else if (raiz->dato==b)
        return 0;
    else{
        if(search_Val(raiz->derecha,b)){
            return 1+calc_lvl(raiz->derecha,b);
        }else{
            return 1+calc_lvl(raiz->izquierda,b);
        }
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
    int nodoB=20;
    insertar(raiz, 90);
    printf("Recorrido en orden del arbol: ");
    inOrden(raiz);
    printf("\n");
    printf("%d esta en el nivel : %d\n", nodoB,calc_lvl(raiz,nodoB));    
    return 0;
}
