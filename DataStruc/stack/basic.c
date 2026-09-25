#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100
typedef struct
{
    char elementos[MAX];
    int top;
} Pila;
void Init(Pila *p)
{
    (*p).top = 0;
}
void push(Pila *p, char caracter)
{
    if ((*p).top < MAX)
    {
        (*p).elementos[(*p).top] = caracter;
        (*p).top++;
    }
}
char top(const Pila *p)
{
    return (*p).elementos[(*p).top - 1];
}
void pop(Pila *p)
{
    if ((*p).top > 0)
    {
        (*p).top--;
    }
}
bool empty(Pila *p)
{
    return (*p).top == 0;
}
bool full(Pila *p)
{
    return (*p).top == 100;
}
void modtop(Pila *p, int num){
    (*p).top==num-1;
}
int main()
{
    char cadena[MAX];
    
    Pila operandos;
    Pila operanciones;
    
    Init(&operandos);
    Init(&operanciones);
    
    scanf("%s", cadena);
    int temp1,temp2;
    int res=0;
    for (int i = 0; i < strlen(cadena); i++)
    {
        if (cadena[i]=='+'||cadena[i]=='-'||cadena[i]=='*'||cadena[i]=='/')
        {
            push(&operanciones,cadena[i]);
        }else if (cadena[i]>='0'&&cadena[i]<='9')
        {
            push(&operandos,cadena[i]);
        }
    }
    while (!empty(&operanciones)&&!empty(&operandos))
    {
        

    }
    
    
    return 0;
}
