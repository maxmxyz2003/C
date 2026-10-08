#include <stdio.h>
#include <stdlib.h>
typedef int TipoDato;

typedef struct nSub {
    TipoDato info;
    struct nSub* sig;  // Corrected the struct name here
} Sub;
typedef struct prin {
    TipoDato info;
    struct prin* sig;
    Sub* cabSub;
} Principal;
// Function to create a new subnode
Sub* creaSubNodo(Sub* cab, TipoDato dato) {
    Sub* nuevo = (Sub*)malloc(sizeof(Sub));
    nuevo->info = dato;
    nuevo->sig = NULL;
    Sub* aux = cab;
    if (!cab)
    {
        cab=nuevo;
        return cab;
    }
    while (aux->sig) {
        aux = aux->sig;
    }
    aux->sig = nuevo;
    return cab;  // Return the updated subnode list
}
// Function to capture subnodes
void capturaSubs(Principal* cabP) {
    Principal* auxP = cabP;
    int cont1 = 0, cont2 = 0, opc = 1, dato;
    while (auxP){
        Sub* auxS = auxP->cabSub;
        while (opc){
            printf("Introduce el elemento %d de la cab %d: ", cont2, cont1);
            scanf("%d", &dato);
            auxS = creaSubNodo(auxS, dato); // Pass the current subnode list
            cont2++;
            printf("Otro? (1=Sí, 0=No): ");
            scanf("%d", &opc);
        }
        opc = 1;
        cont1++;
        cont2 = 0;
        auxP = auxP->sig; // Move to the next principal node
    }
}
// Function to create a new principal node
Principal* creaNodoPrin(Principal* prin, TipoDato dato){
    Principal* nuevoP = (Principal*)malloc(sizeof(Principal));
    nuevoP->info = dato;
    nuevoP->sig = NULL;
    // nuevoP->cabSub = NULL;  // Initialize the subnode list
    nuevoP->cabSub = creaSubNodo(NULL, -1);
    // capturaSub(nuevoP->cabSub);  // Pass the subnode list to capture subnodes
    return nuevoP;
}
// Function to capture principal nodes
void CaptElems(Principal** cab) {
    int opc = 1;
    int dato;
    int cont = 0;
    while (opc) {
        printf("Introduce el dato de la cabecera #%d: \n", cont);
        scanf("%d", &dato);
        *cab = creaNodoPrin(*cab, dato);  // Assign the updated list to cab
        printf("Otro? (1=Sí, 0=No): \n");
        scanf("%d", &opc);
        cont++;
    }
}
int sumaElems(Principal* cab, int cabRef) {
    int sum = 0;
    Principal* auxP = cab;
    while (auxP) {
        if (auxP->info == cabRef) {
            Sub* auxS = auxP->cabSub;
            while (auxS) {
                sum += auxS->info;
                auxS = auxS->sig;
            }
        }
        auxP = auxP->sig;  // Move to the next principal node
    }
    return sum;
}
int main(void) {
    Principal* cab = NULL;  // Initialize the list with NULL
    CaptElems(&cab);  // Pass a pointer to the list to update it
    // Now you have a list of principal nodes, each containing a list of subnodes.
    // You can work with this structure as needed.
    // Don't forget to free the allocated memory when you're done.
    capturaSubs(cab);    
    int sum=sumaElems(cab, 0);
    printf("\nSuma = %d ",sum);
    sum=sumaElems(cab, 1);
    printf("\nSuma = %d ",sum);
    return 0;
}
