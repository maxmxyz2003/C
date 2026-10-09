#include <stdio.h>
#include <stdlib.h>
//Funcion para asignar memoria a un puntero generico
int AsignMemVoid(void **ptrG, int tipo){
    switch (tipo){
        case 0: // Cuando es int
            *ptrG=malloc(sizeof(int));
            break;
        case 1:// Cuando es float
            *ptrG=malloc(sizeof(float));
            break;
        case 2:// Cuando es char
            *ptrG=malloc(sizeof(char));
            break;
        default:
            printf("No valido.\n");
            break;
    }
    if(*ptrG){// Si apunta, regresa 1 sino se libera y regresa 0
        return 1;
    }else{
        printf("Asignacion de memoria fallido.\n");
        free(*ptrG);
        return 0;
    }
}
//Funcion para modificar el dato
void ModData(void *ptrG, int tipo, void *data){// Asignamos el dato usando el cast y asi solo usamos una funcion
    if(!ptrG){//Si no apunta no hace nada
        printf("Error.\n");
        return;
    }
    switch (tipo){
        case 0:
            *(int*)ptrG=*(int*)data;//Cast para el puntero y para el nuevo valor asignado
            break;
        case 1:
            *(float*)ptrG=*(float*)data;
            break;
        case 2:
            *(char*)ptrG=*(char*)data;
            break;
        default:
            printf("No valido.\n");
            break;
    }
}
//Imprimir el valor del puntero segun su tipo
void ImprimeValor(void *ptrG, int tipo){
    if(!ptrG){
        printf("Error.\n");
        return;
    }
    switch (tipo){
        case 0:
            printf("Contenido del puntero generico (int*): %d\n", *(int*)ptrG);
            break;
        case 1:
            printf("Contenido del puntero generico (float*): %f\n", *(float*)ptrG);
            break;
        case 2:
            printf("Contenido del puntero generico (char*): %c\n", *(char*)ptrG);
            break;
        default:
            printf("No valido.\n");
            break;
    }
}
void CambiarTipo(void **ptr, int nuevoTipo) {
    // Libera la memoria existente
    free(*ptr);
    // Asigna nueva memoria del tipo deseado
    switch (nuevoTipo) {
        case 0:
            *ptr = malloc(sizeof(int));
            break;
        case 1:
            *ptr = malloc(sizeof(float));
            break;
        case 2:
            *ptr = malloc(sizeof(char));
            break;
        default:
            printf("No valido.\n");
            *ptr = NULL;
            break;
    }
    if (!*ptr) {
        printf("Asignación de memoria fallida.\n");
        exit(1);
    }
}

int main (void){
    void *ptrGen;
    int x,opc;
    float y; char z;
    if(AsignMemVoid(&ptrGen, 0)){
        printf("Que quieres que sea? (0)int (1)float (2)char\n");
        scanf("%d", &opc);
        switch (opc){
            case 0:
                printf("Introduce el valor del entero: \n");
                scanf("%d", &x);
                ModData(ptrGen,0,&x);
                ImprimeValor(ptrGen, 0);
                break;
            case 1:
                printf("Introduce el valor del flotante: \n");
                scanf("%f", &y);
                ModData(ptrGen,1,&y);
                ImprimeValor(ptrGen, 1);
                break;
            case 2:
                printf("Introduce el caracter:");
                scanf(" %c", &z);
                ModData(ptrGen,2,&z);
                ImprimeValor(ptrGen, 2);
                break;
            default:
                printf("No valido");
                break;
        }
        printf("Quieres cambiar? \n");
        scanf("%d", &opc);
        if (opc){
            printf("Que quieres que sea? (0)int (1)float (2)char\n");
            scanf("%d", &opc);
            switch (opc){
                case 0:
                    CambiarTipo(&ptrGen, 0);
                    printf("Introduce el valor del entero: \n");
                    scanf("%d", &x);
                    ModData(ptrGen,0,&x);
                    ImprimeValor(ptrGen, 0);
                    break;
                case 1:
                    CambiarTipo(&ptrGen, 1);
                    printf("Introduce el valor del flotante: \n");
                    scanf("%f", &y);
                    ModData(ptrGen,1,&y);
                    ImprimeValor(ptrGen, 1);
                    break;
                case 2:
                    CambiarTipo(&ptrGen, 2);
                    printf("Introduce el caracter:");
                    scanf(" %c", &z);
                    ModData(ptrGen,2,&z);
                    ImprimeValor(ptrGen, 2);
                    break;
                default:
                    printf("No valido");
                    break;
            }
        }
    }
    return 0;
}
