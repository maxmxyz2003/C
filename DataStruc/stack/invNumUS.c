#include <stdio.h>
#include <stdbool.h>
#include <string.h>
typedef struct{
    int elem[100];
    int top;
}Stack;
void Init(Stack *p){
    (*p).top = 0;
}

void aStackr(Stack *p, int num){
    if ((*p).top < 100){
        (*p).elem[(*p).top++] = num;
    }
    else{
        printf("N");
    }
}
int acceder(Stack *p){
    return (*p).elem[(*p).top - 1];
}
void pop(Stack *p){
    if ((*p).top > 0)
        (*p).top--;
    else
        printf("N");
}
bool empty(Stack *p){
    return (*p).top == 0;
}

bool full(Stack *p){
    return (*p).top == 100;
}
int main(){
    int numero;
    scanf("%d", &numero);
    Stack miStack;
    Init(&miStack);
    int numero_inv = 0;
    while (numero != 0){
        aStackr(&miStack, numero%10);
        numero /= 10;
    }
    int pot = 1;
    while (!empty(&miStack)){
        numero_inv = acceder(&miStack) * pot + numero_inv;
        pot *= 10;
        pop(&miStack);
    }
    printf("res: %d", numero_inv);
    return 0;
}
