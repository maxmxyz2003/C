
#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct {
    char s[MAX][15];
    int tope;
} pila;
void append (pila *p, char c[]);
void pop (pila *p);
int vacio (pila *p);
int main () {
    pila p; p.tope=-1;
    int n,slots; 
    char mat[15], op[15];
    scanf ("%d %d", &slots,&n);
    for (int i=0; i<n; i++) {
        scanf ("\n%s", op);
        if (op[0]=='P') {
            scanf ("%s", mat);
            if (p.tope<slots-1) {
                append(&p, mat);
                printf("%s\n", mat);
            }
            else printf ("IMPOSIBLE\n");
        }
        else {
            if (p.tope>-1) {
                printf("%s\n", p.s[p.tope]);
                pop(&p);
            }
            else printf ("IMPOSIBLE\n");
        }
    }
    return 0;
}
void append (pila *p, char c[])
{
    strcpy (p->s[++p->tope], c);
}
void pop (pila *p)
{
    p->tope--;
}
