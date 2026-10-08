#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 10000
#define TAM 100
typedef struct{
    int In;
    int Des;
} Conex;
void intercambia(int *a, int *b){
    int temp = (*a);
    (*a) = (*b);
    (*b) = temp;
}
int partir_asc(int a[TAM], int A, int D){
    int x = a[D];
    int j = A - 1;
    for (int i = A; i <= D - 1; i++)
    {
        if (a[i] <= x)
        {
            j++;
            intercambia(&a[j], &a[i]);
        }
    }
    intercambia(&a[j + 1], &a[D]);
    return j + 1;
}
void quicksort_asc(int arreg[TAM], int A, int D){
    if (A < D){
        int pivot = partir_asc(arreg, A, D);
        quicksort_asc(arreg, A, pivot - 1);
        quicksort_asc(arreg, pivot + 1, D);
    }
}

void asigna(Conex *c, int inic, int fin){
    (*c).Des = fin;
    (*c).In = inic;
}
int main(void){
    int num_V;
    scanf("%d", &num_V);
    Conex conexts[num_V];
    for (int i = 0; i < num_V; i++){
        int incio, final;
        scanf("%d %d", &incio, &final);
        asigna(&conexts[i], incio, final);
    }
    int V_ref;
    scanf("%d", &V_ref);
    int connections[MAX]; // Array to store connections
    int numConnections = 0;
    for (int i = 0; i < num_V; i++)
    {
        if (conexts[i].In == V_ref)
        {
            connections[numConnections++] = conexts[i].Des;
        }
        else if (conexts[i].Des == V_ref)
        {
            connections[numConnections++] = conexts[i].In;
        }
    }
    quicksort_asc(connections, 0, numConnections - 1);
    for (int i = 0; i < numConnections; i++)
    {
        printf("%d ", connections[i]);
    }

    return 0;
}
