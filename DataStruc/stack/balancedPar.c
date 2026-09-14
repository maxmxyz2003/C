#include <stdio.h>
#include <stdbool.h>
#define MAX 100
typedef struct Pila{
    char elementos[MAX];
    int top;
}Pila;
void InitStack(Pila* p){
    p->top=0;    
}
void stack(Pila* p, int dato){
    p->elementos[p->top++]=dato;
}
void DeStack(Pila* p){
    p->top--;
}
char access(Pila p){
    return p.elementos[p.top-1];
}
int Full(Pila* p){
    return p->top==MAX;
}
int Empty(Pila p){
    return p.top==0;
}

int main() {
    Pila p;
    InitStack(&p);
    char cad[100];
    scanf("%s", cad);
    bool balanced = true;

    for (int i = 0; cad[i] != '\0'; i++) {
        if (cad[i] == '{' || cad[i] == '(' || cad[i] == '[') {
            stack(&p, cad[i]);
        } else {
            if (Empty(p)) {
                balanced = false;
                break;
            }

            char top = access(p);
            if ((cad[i] == ')' && top == '(') ||
                (cad[i] == '}' && top == '{') ||
                (cad[i] == ']' && top == '[')) {
                DeStack(&p);
            } else {
                balanced = false;
                break;
            }
        }
    }

    if (balanced && Empty(p)) {
        printf("SIS");
    } else {
        printf("Non");
    }

    return 0;
}
