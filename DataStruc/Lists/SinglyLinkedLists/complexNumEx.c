#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int *real;
    int *imgnr;
    struct Node* next;
} * Complx_Number;
int createNode(Complx_Number *newNum, int P_real, int P_imagine) {
    *newNum = (Complx_Number)malloc(sizeof(struct Node));
    if (*newNum) {
        (*newNum)->real = (int *)malloc(sizeof(int));
        (*newNum)->imgnr = (int *)malloc(sizeof(int));
        *((*newNum)->real) = P_real;
        *((*newNum)->imgnr) = P_imagine;
        (*newNum)->next = NULL;
        return 1;
    }else
        return 0;
}
int insertNodeBeg(Complx_Number *cab, int P_r, int P_i) {
    Complx_Number newNum = NULL;
    if (createNode(&newNum, P_r, P_i)) {
        if (*cab) {
            newNum->next = *cab;
            *cab = newNum;
        } else
            *cab = newNum;
        return 1;
    }else 
        return 0;
}
int insertNodeEnd(Complx_Number *cab, int P_r, int P_i) {
    Complx_Number newNum = NULL;
    if (createNode(&newNum, P_r, P_i)) {
        if (*cab) {
            Complx_Number aux = *cab;
            while (aux->next)
                aux = aux->next;
            aux->next = newNum;
        }else
            *cab = newNum;
        return 1;
    } else
        return 0;
}

Complx_Number Sum(Complx_Number cab) {
    Complx_Number sum = NULL;
    if (createNode(&sum, 0, 0)) {
        while (cab){
            *(sum->real) += *(cab->real);
            *(sum->imgnr) += *(cab->imgnr);
            cab = cab->next;
        }
    }
    return sum;
}
void printList(Complx_Number cab) {
    while(cab){
        printf("(%d+%di)->", *(cab->real), *(cab->imgnr));
        cab = cab->next;
    }
    printf("NULL\n");
}

int main(void) {
    Complx_Number cab = NULL;
    int fin = 0;
    int opc;
    int TempR, TempI;
    while (!fin) {
        printf("What do you want to do? (1)Insert at the beginning (2)Insert at the end (3) Add (4)Print List (5)Exit\n");
        scanf("%d", &opc);
        switch (opc) {
            case 1:
                printf("Insert data: (a+bi)\n");
                scanf("%d %d", &TempR, &TempI);
                if (insertNodeBeg(&cab, TempR, TempI))
                    printf("Success\n");
                break;
            case 2:
                printf("Insert data: (a+bi)\n");
                scanf("%d %d", &TempR, &TempI);
                if (insertNodeEnd(&cab, TempR, TempI))
                    printf("Success\n");
                break;
            case 3:
                Complx_Number aux = Sum(cab);
                printf("(%d+%di)\n", *(aux->real), *(aux->imgnr));
                free(aux->real);
                free(aux->imgnr);
                free(aux);
                break;
            case 4:
                printList(cab);
                break;
            case 5:
                fin = 1;
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    }
    return 0;
}
