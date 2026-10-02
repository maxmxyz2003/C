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
    int opc;
    int TempData;
    if (initList(&lista)){
        while (!fin) {
            printf("What do you want to do? (1)Insert at the beginning (2)Insert at the end (3)Print List (4)Print List Reverse (5)Exit\n");
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
