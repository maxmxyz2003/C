#include <stdio.h>
#include <stdlib.h>

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

int insertNodeBeg(P_NODE* cab, int data) {
    P_NODE newNode = NULL;
    if (createNode(&newNode, data)) {
        if (*cab) {
            newNode->next = *cab;
            *cab = newNode;
        } else {
            *cab = newNode;
        }
        return 1;
    } else {
        return 0;
    }
}

int insertNodeEnd(P_NODE* cab, int data) {
    P_NODE newNode = NULL;
    if (createNode(&newNode, data)) {
        if (*cab) {
            P_NODE aux = *cab;
            while (aux->next) {
                aux = aux->next;
            }
            aux->next = newNode;
        } else {
            *cab = newNode;
        }
        return 1;
    } else {
        return 0;
    }
}

void deleteDuping(P_NODE* cab) {
    if (!*cab) {
        return;
    } else if ((*cab)->next && (*cab)->data == (*cab)->next->data) {
        P_NODE aux = (*cab)->next;
        (*cab)->next = aux->next;
        free(aux);
        deleteDuping(cab);
    } else {
        deleteDuping(&(*cab)->next);
    }
}
void printList(P_NODE cab) {
    while (cab) {
        printf("%d->", cab->data);
        cab = cab->next;
    }
    printf("NULL\n");
}

int main(void) {
    P_NODE cab = NULL;
    int fin = 0;
    int opc;
    int TempData;
    while (!fin) {
        printf("What do you want to do? (1)Insert at the beginning (2)Insert at the end (3) Delete duping (4)Print List (5)Exit\n");
        scanf("%d", &opc);
        switch (opc) {
            case 1:
                printf("Insert data: \n");
                scanf("%d", &TempData);
                if (insertNodeBeg(&cab, TempData))
                    printf("Success\n");
                break;
            case 2:
                printf("Insert data: \n");
                scanf("%d", &TempData);
                if (insertNodeEnd(&cab, TempData))
                    printf("Success\n");
                break;
            case 3:
                deleteDuping(&cab);
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
