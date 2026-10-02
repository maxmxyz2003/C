#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev; 
} * P_D_NODE;

typedef struct list {
    P_D_NODE head;
    P_D_NODE rear;    
} * LIST;

int createNode(P_D_NODE* newN, int data) {
    *newN = (P_D_NODE)malloc(sizeof(struct Node));
    if (*newN) {
        (*newN)->data = data;
        (*newN)->next = NULL;
        (*newN)->prev = NULL;
        return 1;
    } else {
        return 0;
    }
}
int initList(LIST * list){
    *list=(LIST)malloc(sizeof(struct list));
    if (*list){
        (*list)->head=NULL;
        (*list)->rear=NULL;
    }
}
int insertNodeBeg(LIST* list, int data) {
    P_D_NODE newNode = NULL;
    if (createNode(&newNode, data)) {
        if ((*list)->head){
            (*list)->head->prev = newNode;
            newNode->next = (*list)->head;
            (*list)->head = newNode;
        } else {
            (*list)->head = newNode;
            (*list)->rear = newNode;
        }
        return 1;
    } else {
        return 0;
    }
}

int insertNodeEnd(LIST* list, int data) {
    P_D_NODE newNode = NULL;
    if (createNode(&newNode, data)) {
        if ((*list)->rear) {
            (*list)->rear->next = newNode;
            newNode->prev = (*list)->rear;
            (*list)->rear = newNode;
        } else {
            (*list)->head = newNode;
            (*list)->rear = newNode;
        }
        return 1;
    } else {
        return 0;
    }
}

void printListReverse(LIST list) {
    P_D_NODE temp = list->rear;
    printf("NULL<->");
    while (temp) {
        printf("%d<->", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}
int Find2values(LIST list, int v1, int v2){
    P_D_NODE auxH=list->head;
    P_D_NODE auxR=list->rear;
    while (auxH&&auxR){
        if(auxH->data==v1&&auxR->data==v2)
            return 3;
        else if (auxR->data==v2)
            return 2;
        else if (auxH->data==v1)
            return 1;
        auxH=auxH->next;
        auxR=auxR->prev;
    }
    return 0;
}
void printList(LIST list) {
    P_D_NODE temp = list->head;
    printf("NULL<->");
    while (temp) {
        printf("%d<->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(void) {
    LIST lista = NULL;
    int fin = 0;
    int v1,v2;
    int opc;
    int TempData;
    if (initList(&lista)){
        while (!fin) {
            printf("What do you want to do?\n(1)Insert at the beginning\n(2)Insert at the end\n(3)Print List\n(4)Print List Reverse\n(5)Search Values\n(6)Exit\n");
            scanf("%d", &opc);
            switch (opc) {
                case 1:
                    printf("Insert data: \n");
                    scanf("%d", &TempData);
                    insertNodeBeg(&lista, TempData);
                    break;
                case 2:
                    printf("Insert data: \n");
                    scanf("%d", &TempData);
                    insertNodeEnd(&lista, TempData);
                    break;
                case 3:
                    printList(lista);
                    break;
                case 4:
                    printListReverse(lista);
                    break;
                case 5:
                    printf("Insert the first value to search: \n");
                    scanf("%d", &v1);
                    printf("Insert the second value to search: \n");
                    scanf("%d", &v2);
                    printf("0=Not found\t1=First Found\t2=Second found\t3=Both\nResult=%d\n",Find2values(lista,v1,v2));
                    break;
                case 6:
                    fin = 1;
                    break;
                default:
                    printf("Invalid option\n");
                    break;
            }
        }

    }    
    return 0;
}
