#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    int data;
    struct node*next;
}*NODE;
int createNode(NODE *nn,int data){
    *nn=(NODE)malloc(sizeof(struct node));
    if (*nn){
        (*nn)->data=data;
        (*nn)->next=NULL;
        return 1;
    }
    return 0;
}
int InsrtB(NODE *head,int data){
    NODE newNode=NULL;
    if (createNode(&newNode,data)){
        if(!*head)
            (*head)=newNode;
        else{
            newNode->next=(*head);
            (*head)=newNode;
        }
    }
}
int InsrtE(NODE *head,int data){
    NODE newNode=NULL;
    if (createNode(&newNode,data)){
        if(!*head){
            (*head)=newNode;
            return 1;
        }else{
            NODE aux=(*head);
            while (aux->next)
                aux=aux->next;
            aux->next=newNode;
            return 1;
        }
    }
    return 0;
}

int insrtSort(NODE *head, int data){
    if (!*head){
        if (createNode(head,data)){
            return 1;
        }else
            return 0;
    }else if (data<=(*head)->data){
        NODE x;
        if (createNode(&x,data)){
            x->next=(*head);
            (*head)=x;
            return 1;
        }else
            return 0;
    }else if(!(*head)->next){
        NODE x;
        if (createNode(&x,data)){
            (*head)->next=x;
            return 1;
        }else
            return 0;
    }else
        return insrtSort(&(*head)->next,data);
}
void deleteNode(NODE *cab,int data){
    if (!*cab){
        return;
    }else if ((*cab)->next->data==data){
        NODE aux=(*cab)->next;
        (*cab)->next=aux->next;
        free(aux);
        deleteNode(cab,data);
    }else{
        deleteNode(&(*cab)->next,data);
    }
}
void deleteNodeB(NODE *cab){
    if (!*cab){
        return;
    }else{
        NODE aux=*cab;
        (*cab)=(*cab)->next;
        free(aux);
    }
}
void deleteNodeE(NODE *cab){
    if(!*cab)
        return;
    else if (!(*cab)->next->next){
        NODE aux=(*cab)->next;
        (*cab)->next=NULL;
        free(aux);
        return;
    }else{
        deleteNodeE(&(*cab)->next);
    }
}
void deleteNodeIndx(NODE *cab,int index){
    if (!*cab){
        return;
    }else if (index==0){
        NODE aux=(*cab)->next;
        (*cab)->next=aux->next;
        free(aux);
        return;
    }else{
        deleteNode(&(*cab)->next,index-1);
    }
}
int sum(NODE cab){
    if (cab)
        return cab->data+sum(cab->next);
}
void DisplayData(NODE cab){
    if (cab){
        printf("%d->");
        DisplayData(cab->next);
    }else{
        printf("NULL\n");
    }
}
int main(){
    NODE cab=NULL;int fin=0;int opt,temp;
    if (createNode(&cab,5)){
        while (!fin){
            printf("Options (0)Print Data (1) Insert at the beginning (2)Insert at the end (3) Insert Sort (4)Delete specific data ()Exit \n");
            scanf("%d", &opt);
            switch (opt){
                case 0:
                    DisplayData(cab);
                    break;
                case 1:
                    printf("Give me the value: ");
                    scanf("%d",&temp);
                    if(InsrtB(&cab,temp)){
                        printf("Success");
                    }
                    break;
                default:
                    break;
            }
        }
        
    }
    
}
