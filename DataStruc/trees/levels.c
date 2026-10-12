#include <stdio.h>
#include <stdlib.h>
struct Nodo {
    int dato;
    struct Nodo* izquierda;
    struct Nodo* derecha;
};
typedef struct Node {
    int data;
    struct Node* next;
} * P_NODE;

int createNode(P_NODE* newN, int data) {
    *newN = (P_NODE)malloc(sizeof(struct Node));
    if (*newN) {
        (*newN)->data = data;
        (*newN)->next = NULL;
        return 1;
    } else {
        return 0;
    }
}
int insertAtBeginning(P_NODE *cab,int data){
    if (!*cab){
        if(createNode(cab,data))
           return 1;
    }else{
        P_NODE newNode=NULL;
        if (createNode(&newNode,data)){
            newNode->next=*cab;
            *cab=newNode;
            return 1;
        }
    }
    return 0;
}
int deleteAtBeginning(P_NODE *cab,int data){
    if (!*cab){
        return 0;
    }else{
        P_NODE temp=*cab;
        *cab=temp->next;
        free(temp);
        return 1;
    }
}

// Función para crear un nuevo nodo del árbol
struct Nodo* crearHoja(int dato) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;
    return nuevoNodo;
}
// Función para insertarHoja un nuevo nodo en el árbol binario
struct Nodo* insertarHoja(struct Nodo* raiz, int dato) {
    if (raiz == NULL)
        return crearHoja(dato);
    if (dato < raiz->dato)
        raiz->izquierda = insertarHoja(raiz->izquierda, dato);
    else if (dato > raiz->dato)
        raiz->derecha = insertarHoja(raiz->derecha, dato);
    return raiz;
}
void recorreNiv(struct Nodo* raiz){
    P_NODE cola=NULL;
    if (createNode(&cola,raiz->dato)){
        while (1){
            
        }        
    }
    
}

// Función principal
int main() {
    struct Nodo* raiz = NULL;
    raiz = insertarHoja(raiz, 50);
    insertarHoja(raiz, 30);
    insertarHoja(raiz, 20);
    insertarHoja(raiz, 40);
    insertarHoja(raiz, 70);
    insertarHoja(raiz, 60);
    insertarHoja(raiz, 80);
    printf("Recorrido en orden del arbol: ");
    inOrden(raiz);
    printf("\n");

    return 0;
}
