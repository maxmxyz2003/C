#include <stdio.h>
#include <stdlib.h>
typedef struct subN {
    int valor;
    struct subN *next;
} *Lista_multpl;
typedef struct nodeG {
    Lista_multpl cab;
    int numero;
    struct nodeG *nextNum;
} *Lista_num;
int createMultipl(Lista_multpl *l, int data) {
    *l = (Lista_multpl)malloc(sizeof(struct subN));
    if (*l) {
        (*l)->next = NULL;
        (*l)->valor = data;
        return 1;
    }
    return 0;
}

void insertMultipl(Lista_num *cabN, int data) {
    if (!*cabN) {
        printf("ERROR\n");
        return;
    } else {
        Lista_multpl newSN = NULL;
        Lista_num aux = *cabN;
        while (aux) {//Insertamos al principio para no batallar
            Lista_multpl aux_sub = aux->cab;
            if (createMultipl(&newSN, data)){
                if ((newSN->valor) % (aux->numero) == 0) {//Por alguna razon se mezclan con los que no son multiplos
                    if (aux->cab){
                        newSN->next = aux->cab;
                        aux->cab = newSN;
                    } else
                        aux->cab = newSN;
                }
                aux = aux->nextNum;
            }
            aux_sub=NULL; //Reinicio para que no se revuelvan

        }
        }
}

int createNum(Lista_num *l, int multpl){
    *l = (Lista_num)malloc(sizeof(struct nodeG));
    if (*l){
        (*l)->cab = NULL;
        (*l)->numero = multpl;
        (*l)->nextNum = NULL;
        return 1;
    }
    return 0;
}
void insertNum(Lista_num *cab, int num) {
    Lista_num newNL = NULL;
    if (createNum(&newNL, num)) {
        if (!*cab) {
            *cab = newNL;
        } else {
            newNL->nextNum = *cab;
            *cab = newNL;
        }
    }
}
void deletNum(Lista_num *cab, int num) {
    Lista_num auxL = *cab;
    if (auxL->numero==num){//Al eliminar el primer numero no funciona
        Lista_num temp=*cab;
        (*cab)=(*cab)->nextNum;
        free(temp);
    }else{
        while (auxL){
            if (auxL->nextNum->numero == num) {
                Lista_num temp = auxL->nextNum;
                auxL->nextNum = temp->nextNum;
                free(temp);
                break;
            }
            auxL = auxL->nextNum;
        }
    }
}
void deletMultpl(Lista_num *cab, int num) {
    Lista_num auxL = *cab;
    while (auxL) {
        Lista_multpl aux_sub = auxL->cab;
        if (aux_sub && aux_sub->valor == num) { // Eliminación del primer elemento
            Lista_multpl temp = auxL->cab;
            auxL->cab = auxL->cab->next;
            free(temp);
        } else {
            while (aux_sub && aux_sub->next) {
                if (aux_sub->next->valor == num) {
                    Lista_multpl temp = aux_sub->next;
                    aux_sub->next = temp->next;
                    free(temp);
                    break;
                }
                aux_sub = aux_sub->next;
            }
        }
        auxL = auxL->nextNum;
    }
}

void PrintData(Lista_num l) {
    Lista_num aux = l;
    while (aux) {
        Lista_multpl aux_sub = aux->cab;
        printf("Multiplos de %d\n", aux->numero);
        while (aux_sub) {
            // if(aux_sub->valor%aux->numero==0)
            printf("%d ", aux_sub->valor);
            aux_sub = aux_sub->next;
        }
        printf("\n");
        aux = aux->nextNum;
    }
}

int main() {
    Lista_num list = NULL;
    int opt, TempN, fin = 0;
    while (!fin) {
        printf("Que quieres hacer? (1)Insertar numero (2) Insertar multiplo (3) Eliminar numero (4) Eliminar multiplo (5) Imprimir (6) Salir\n");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                printf("Dame el numero:\n");
                scanf("%d", &TempN);
                insertNum(&list, TempN);
                break;
            case 2:
                printf("Dame el multiplo:\n");
                scanf("%d", &TempN);
                insertMultipl(&list, TempN);
                break;
            case 3:
                printf("Dame el numero:\n");
                scanf("%d", &TempN);
                deletNum(&list, TempN);
                break;
            case 4:
                printf("Dame el multiplo:\n");
                scanf("%d", &TempN);
                deletMultpl(&list, TempN);
                break;
            case 5:
                PrintData(list);
                break;
            case 6:
                exit(1);
            default:
                printf("Opcion no valida\n");
                break;
        }
        printf("Quieres abandonar? (1 para salir)\n");
        scanf("%d", &fin);
    }
    return 0;
}
