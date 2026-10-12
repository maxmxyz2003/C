
#include <stdio.h>
#include <stdlib.h>
// Nodo
typedef struct Nodo{
    int num;
    int den;
    struct Nodo *Link;
} Nodo;
typedef struct Nodo * Pila;
//Iniciar pila
void IniPila(Pila *cab){
    (*cab)=NULL;
}
//Funcion para crear nuevo Nodo
Nodo *crearNodo(int num, int den){
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo == NULL){
        printf("Fallo de asignacion de memoria.\n");
        exit(1);
    }
    nuevo->num = num;
    nuevo->den =den;
    nuevo->Link = NULL;
    return nuevo;
}
// Funcion push 
Nodo *push(Nodo *cab, int num, int den){
    Nodo *nuevo = crearNodo(num, den);
    if (cab == NULL){
        return nuevo;
    }
    Nodo *temp = cab;
    while (temp->Link){
        temp = temp->Link;
    }
    temp->Link = nuevo;
    return cab;
}
// Funcion pop
Nodo *pop(Nodo *cab)
{
    if (cab == NULL){
        return cab;
    }
    Nodo *temp = cab;
    while ((temp->Link)->Link){
        temp = temp->Link;
    }
    free(temp->Link);
    temp->Link=NULL;
    return cab;
}

// Funcion para capturar Pila
Nodo *capturaPila(){
    Nodo *cab = NULL;
    int den,num;
    int opc;
    do{
        printf("Ingresa numerador: ");
        scanf("%d", &num);
        printf("Ingresa denominador: ");
        scanf("%d", &den);
        if (cab == NULL)
        {
            cab = crearNodo(num, den);
        }
        else{
                cab = push(cab, num,den);
        }
        printf("Otro? [1=S, 0=N]: ");
        scanf("%d", &opc);
    } while (opc != 0);
    return cab;
}

// Function to display Pila
void imprimePila(Nodo *cab){
    Nodo *temp = cab;
    printf("Pila: ");
    while (temp != NULL){
        printf("%d/%d \t", temp->num,temp->den);
        temp = temp->Link;
    }
    printf("\n");
}
// Liberar Pila
void freePila(Nodo *cab){
    Nodo *temp;
    while (cab){
        temp = cab;
        cab = cab->Link;
        free(temp);
    }
}
//Suma fracciones
Nodo *sumaPila(Pila p) {
    if (!p || !p->Link) {
        printf("No hay suficientes elementos.\n");
        return NULL;
    }
    Nodo *aux = p;
    Nodo *aux2 = p->Link;
    int den =aux->den , num =aux->num;
    while (aux2) {
        num=num*aux2->den+den*aux2->num;
        den*=aux2->den;
        aux2=aux2->Link;
    }
    int divisor = 2;
    while (divisor <= den) {
        if (den % divisor == 0 && num % divisor == 0) {
            den /= divisor;
            num /= divisor;
        } else
            divisor++;
    }
    Nodo *res = crearNodo(num, den);
    return res;
}
int main(void) {
    Nodo *cab;
    IniPila(&cab);
    printf("Capturar elementos de la pila :\n");
    cab = capturaPila();
    printf("Imprimiendo pila:\n");
    imprimePila(cab);
    Nodo *res = sumaPila(cab);
    if (res) {
        printf("Suma de las fracciones: %d/%d\n", res->num, res->den);
        free(res);
    }
    printf("Desapilamos 1 elemento: \n");
    cab=pop(cab);
    imprimePila(cab);
    // Libera Pila
    freePila(cab);
    return 0;
}
