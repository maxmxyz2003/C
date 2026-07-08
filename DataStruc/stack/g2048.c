#include <stdbool.h>
#include <stdio.h>
struct Pila {
  int elementos[100];
  int top;
};
typedef struct Pila TPila;
void iniciar(TPila *p);
bool P_vacia(const TPila *p);
void append(TPila *p, int dato);
void pop(TPila *p);
void instrucc(TPila *p, int n);
bool P_llena(const TPila *p);
void verificar(TPila *p);
void mostrar(TPila *p);
int main(void) {
  TPila pila;
  int inst;
  scanf("%d", &inst);
  instrucc(&pila, inst);
}
void instrucc(TPila *p, int n) {
  int instruc;
  int dato;
  iniciar(&(*p));
  // printf("%d\n", (*p).top);
  for (int i = 0; i < n; i++) {
    scanf("%d", &instruc);
    append(&(*p), dato);
    verificar(&(*p));
  }
  mostrar(&(*p));
}
void verificar(TPila *p) {
  if ((*p).elementos[(*p).top - 1] == (*p).elementos[(*p).top - 2]) {
    (*p).elementos[(*p).top - 1] *= 2;
    pop(&(*p));
  }
}
void mostrar(TPila *p) {
  for (int i = (*p).top - 1; i >= 0; i--) {
    printf("%d\n", (*p).elementos[i]);
  }
}
void iniciar(TPila *p) { (*p).top = 0; }
bool P_vacia(const TPila *p) { return p->top == 0; }
bool P_llena(const TPila *p) { return (*p).top == 100; }
void append(TPila *p, int dato) {
  if (P_llena == true) {
    return;
  } else {
    (*p).elementos[(*p).top] = dato;
    (*p).top++;
  }
}
void pop(TPila *p) {
  if (P_vacia) {
    return;
  } else {
    (*p).top--;
  }
}
int consultar(const TPila *p) {
  int dato;
  dato = (*p).elementos[(*p).top - 1];
  return dato;
}
