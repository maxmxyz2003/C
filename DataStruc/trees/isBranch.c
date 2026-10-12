#include <stdio.h>
#include <stdlib.h>
// Definición de la estructura del nodo del árbol binario
struct Nodo {
    int dato;
    struct Nodo* izquierda;
    struct Nodo* derecha;
};
struct nodo{
    int dato;
    struct nodo*sig;
};
int creanodo(struct nodo ** nuevo, int dato){
    *nuevo=(struct nodo*)malloc(sizeof(struct nodo));
    if (*nuevo){
        (*nuevo)->dato=dato;
        (*nuevo)->sig=NULL;
        return 1;
    }
    return 0;
}
int insertInic(struct nodo ** cab,int dato){
    struct nodo * nuevo=NULL;
    if(creanodo(&nuevo,dato)){
        if (!*cab){
            *cab=nuevo;
            return 1;
        }else{
            nuevo->sig=*cab;
            *cab=nuevo;
            return 1;
        }
    }
    return 0;
}

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
int listaEsRamaDeArbol(struct nodo* lista, struct Nodo* raiz) {
    // Si la lista está vacía, es considerada una rama si la raíz del árbol también es nula
    if (!lista)
        return !raiz;
    // Si llegamos a un nodo hoja en el árbol, comparamos su valor con el de la lista
    if (!raiz)
        return 0;
    // Verificamos si el valor del nodo actual del árbol coincide con el valor en la lista
    if (lista->dato != raiz->dato)
        return 0;
    // Llamamos recursivamente a la función con los nodos hijos izquierdo y derecho del árbol
    return listaEsRamaDeArbol(lista->sig, raiz->izquierda) || listaEsRamaDeArbol(lista->sig, raiz->derecha);
}

int rama2(struct Nodo *raiz, struct nodo* cab){
    if (!search_Val(raiz,cab->dato)){
        return 0;
    }else{

    }    
}

// Función para realizar un recorrido en orden (in-order traversal) del árbol
void inOrden(struct Nodo* nodo) {
    if (nodo != NULL) {
        inOrden(nodo->izquierda);
        printf("%d ", nodo->dato);
        inOrden(nodo->derecha);
    }
}
void imprimelista(struct nodo*cab){
    while (cab){
        printf("%d->",cab->dato);
        cab=cab->sig;
    }
    printf("\n");
}
// Función principal
int main() {
    struct Nodo* raiz = NULL;
    struct nodo* cab=NULL;
    insertInic(&cab,20);
    insertInic(&cab,30);
    insertInic(&cab,50);
    raiz = insertar(raiz, 50);
    insertar(raiz, 30);
    insertar(raiz, 20);
    insertar(raiz, 40);
    insertar(raiz, 70);
    insertar(raiz, 60);
    insertar(raiz, 80);
    printf("Recorrido en orden del arbol: ");
    inOrden(raiz);
    printf("\n");
    imprimelista(cab);
    printf("La lista es rama del arbol : %d",listaEsRamaDeArbol(cab,raiz));
    return 0;
}
