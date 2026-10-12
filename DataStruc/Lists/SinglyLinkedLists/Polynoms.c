#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// Nodo
typedef struct Nodo
{
    signed int coef;
    int pot;
    struct Nodo *Link;
} Nodo;
typedef struct Nodo * Pila;
//Iniciar pila
void IniPila(Pila *cab){
    (*cab)=NULL;
}


//Funcion para crear nuevo Nodo
Nodo *crearNodo(int coef, int pot){
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo == NULL){
        printf("Fallo de asignacion de memoria.\n");
        exit(1);
    }
    nuevo->coef = coef;
    nuevo->pot =pot;
    nuevo->Link = NULL;
    return nuevo;
}
// Funcion push 
Nodo *push(Nodo *cab, int coef, int pot){
    Nodo *nuevo = crearNodo(coef, pot);
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
Nodo *capturaPila()
{
    Nodo *cab = NULL;
    int pot,coef;
    int opc;
    do
    {
        printf("Ingresa Coeficiente: ");
        scanf("%d", &coef);
        printf("Ingresa el grado: ");
        scanf("%d", &pot);
        if (cab == NULL)
        {
            cab = crearNodo(coef, pot);
        }
        else{
                cab = push(cab, coef,pot);
        }
        printf("Otro? [1=S, 0=N]: ");
        scanf("%d", &opc);
    } while (opc != 0);
    return cab;
}
// Function to display Pila
void imprimePila(Nodo *cab)
{
    Nodo *temp = cab;
    printf("Pila: ");
    while (temp != NULL)
    {
        printf("%d*x^(%d) \t", temp->coef,temp->pot);
        temp = temp->Link;
    }
    printf("\n");
}
// Liberar Pila
void freePila(Nodo *cab)
{
    Nodo *temp;
    while (cab)
    {
        temp = cab;
        cab = cab->Link;
        free(temp);
    }
}
//Evaluar en un valor
double evaluarEnRec(Pila p, double x){
    if (!p)
    {
        return 0.0;
    }else{
        return p->coef*pow(x,p->pot)+evaluarEnRec(p->Link, x);
    }   
}

int main(void) {
    Nodo *cab;
    IniPila(&cab);
    printf("Capturar elementos de la pila :\n");
    cab = capturaPila();
    printf("Imprimiendo pila:\n");
    imprimePila(cab);
    double xd=evaluarEnRec(cab, 1);
    printf("La pila evaluada en 1 es: \n");
    printf("%lf", xd);
    // Libera Pila
    freePila(cab);
    return 0;
}
