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
/*
Combinar listas ordenadas en una sola
Grafos lista de listas: determinar si tiene forma de estrella
Sumar todas las ramas de un arbol binario 
*/

int insertNodeSort(P_NODE* cab, P_NODE newNode){
    if(!*cab){
        *cab=newNode;
    }else if((*cab)->data>newNode->data){
        newNode->next=*cab;
        *cab=newNode;
    }else if (!(*cab)->next){
        (*cab)->next=newNode;
        return 1;
    }else if((*cab)->next->data>=newNode->data){
        newNode->next=(*cab)->next;
        (*cab)->next=newNode;
        return 1;
    }else{
        insertNodeSort(&(*cab)->next,newNode);
    }
}
P_NODE mergeList(P_NODE cab1, P_NODE cab2) {
    if (!cab1) 
        return cab2;
    else if (!cab2)
        return cab1;
    P_NODE result = NULL;
    P_NODE tail = NULL;
    while (cab1 && cab2) {
        if (cab1->data <= cab2->data) {
            if (!result) {
                result = cab1;
                tail = cab1;
            } else {
                tail->next = cab1;
                tail = tail->next;
            }
            cab1 = cab1->next;
        } else {
            if (!result) {
                result = cab2;
                tail = cab2;
            } else {
                tail->next = cab2;
                tail = tail->next;
            }
            cab2 = cab2->next;
        }
    }
    if (cab1)
        tail->next = cab1;
    else if (cab2)
        tail->next = cab2;
    return result;
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
    P_NODE cab1=NULL,cab2=NULL,cab3=NULL;
    int fin = 0;
    int qlist;
    P_NODE temp=NULL;
    int opc;
    int TempData;
    while (!fin) {
        printf("What do you want to do? (1)Insert Sort (2) Delete duping (3)Print List (4) Exit\n");
        scanf("%d", &opc);
        switch (opc) {
            case 1:
                printf("Insert data: \n");
                scanf("%d", &TempData);
                printf("Which one?\n");
                scanf("%d", &qlist);
                if (qlist==1){
                    if(createNode(&temp,TempData)){
                        if (insertNodeSort(&cab1, temp))
                            printf("Success\n");
                    }
                }else{
                    if(createNode(&temp,TempData)){
                        if (insertNodeSort(&cab2, temp))
                            printf("Success\n");
                    }
                }
                break;
            case 2:
                printf("Which one?\n");
                scanf("%d", &qlist);
                if (qlist==1)
                    deleteDuping(&cab1);
                else
                    deleteDuping(&cab2);
                break;
            case 3:
                printf("Which one?\n");
                scanf("%d", &qlist);
                if (qlist==1)
                    printList(cab1);
                else
                    printList(cab2);
                break;
            case 4:
                cab3= mergeList(cab1,cab2);
                printList(cab3);
                break;            
            case 6:
                fin = 1;
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    }
    return 0;
}
