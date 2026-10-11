#include <stdio.h>
#include <stdlib.h>
//Estructuras
typedef struct Nodo{
    int dato;
    struct Nodo *siguiente;
}*NODO;

typedef struct ListaEnlazada{
    NODO cabeza;
}* Lista;

int createNode(NODO *nuevo, int dato){
    *nuevo=(NODO)malloc(sizeof(struct Nodo));
    if(*nuevo){
        (*nuevo)->dato=dato;
        (*nuevo)->siguiente=NULL;
        return 1;
    }
    return 0;
}
NODO crearNodo(int dato){
    NODO nuevoNodo = (NODO)malloc(sizeof(struct Nodo));
    if (!nuevoNodo){
        printf("Asignacion fallida.\n");
        exit(1);
    }
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente= NULL;
    return nuevoNodo;
}
//Insertar al principio
void InsertarAlPrincipio(Lista lista, int valor){    
    NODO nuevo=NULL;
    if (createNode(&nuevo,valor)){
        nuevo->siguiente = lista->cabeza;
        lista->cabeza = nuevo;
    }
}

NODO InstAIni(NODO *cab, int dato) {
    NODO nuevoNodo = crearNodo(dato);
    if (!*cab) {
        return nuevoNodo;
    }
    nuevoNodo->siguiente = *cab;
    return nuevoNodo;
}
//Funcion para insertar al final 
NODO InsFin(NODO * cab, int dato) {
    NODO nuevoNodo = crearNodo(dato);
    if (!*cab)
        return nuevoNodo;
    NODO temp =*cab;
    while (temp->siguiente)
        temp = temp->siguiente;
    temp->siguiente= nuevoNodo;
    return (*cab);
}
// Function to delete a Nodo from the list
NODO deleteNodo(NODO* cab, int dato) {
    if (!*cab)
        return NULL;
    NODO temp = *cab;
    NODO prev = NULL;
    if (temp != NULL && temp->dato == dato) {
        (*cab)= temp->siguiente;
        free(temp);
        return (*cab);
    }
    while (temp != NULL && temp->dato != dato) {
        prev = temp;
        temp = temp->siguiente;
    }
    if (temp == NULL){
        printf("Nodo with dato %d not found.\n", dato);
        return *cab;
    }
    prev->siguiente = temp->siguiente;
    free(temp);
    return (*cab);
}
// Imprimir lista
void ImprimirLista(Lista lista){
    NODO actual = lista->cabeza;
    while (actual != NULL){
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}
void muestraList(NODO cab){
    printf("Datos:\n");
    while (cab){
        printf("%d \t", cab->dato);
        cab=cab->siguiente;
    }
}
NODO captureListdato() {
    NODO cab = NULL;
    int dato;
    int choice;
    do {
        printf("Enter dato: ");
        scanf("%d", &dato);
        if (cab == NULL) {
            cab = crearNodo(dato);
        }else{
            printf("Insert at the beginning (1) or at the end (2): ");
            scanf("%d", &choice);
            if (choice == 1) {
                cab = InstAIni(&cab, dato);
            } else if (choice == 2) {
                cab = InsFin(&cab, dato);
            } else{
                printf("Invalid choice. Inserting at the end by default.\n");
                cab = InsFin(&cab, dato);
            }
        }
        printf("Do you want to insert another Nodo? (1 for yes, 0 for no): ");
        scanf("%d", &choice);

    } while (choice != 0);
    return cab;
}

int capturaList(NODO*cab){
    int res,dato,opc,cont=0;
    do{
        printf("Dato #%d", cont);
        scanf("%d",&dato); 
        (*cab)=InstAIni(cab, dato);
        if (*cab){
            printf("Continuar? ");
            scanf("%d",&opc);
        }
        cont++;
    } while (res&&opc==1);
}
// Function to display list dato
void displayList(NODO cab) {
    NODO temp = cab;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->dato);
        temp = temp->siguiente;
    }
    printf("\n");
}

// Function to free allocated memory for the list
void LiberarLista(NODO cab) {
    NODO temp;
    while (cab) {
        temp = cab;
        cab = cab->siguiente;
        free(temp);
    }
}
void muestraListRec(NODO cab){
    if(cab){
        printf("%d->", cab->dato);
        muestraListRec(cab->siguiente);
    }else{
        printf("NULL");
    }
}
int main(void){
    NODO cab=captureListdato();
    printf("Lista Enlazada: ");
    muestraListRec(cab);
    LiberarLista(cab);
    return 0;
}
