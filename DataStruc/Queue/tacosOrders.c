#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10000

typedef struct{
    int in;
    int fin;
    int elemen[MAX];
} Tcola;
void init(Tcola *c);
void append(Tcola *c, long int dat);
void del(Tcola *c);
int primero(const Tcola *c);
int elem(const Tcola *c);
bool full_q(const Tcola *c); 
bool emp_q(const Tcola *c); 

int main()
{
    int instruc;
    long int dato;
    Tcola col;
    long long int num_inst;
    long int vendidos=0;
    long int personas=0;
    init(&col);
    scanf("%lld", &num_inst);
    for (long long int i = 0; i < num_inst; i++){
        scanf("%d", &instruc);
        switch (instruc)
        {
            case 1:
                scanf("%ld", &dato);
                append(&col, dato);
                break;
            case 2:
                vendidos+=primero(&col);
                del(&col);
                break;
            case 3:
                personas=elem(&col);
                printf("%ld \n", personas);
                break;
            case 4:
                printf("%ld \n", vendidos);
                //vendidos=0;
                break;
            default:
                break;
        }
    }
    return 0;
}

void init(Tcola *c){
    (*c).in=0;
    (*c).fin=0;
}

void append(Tcola *c, long int dat)
{
    if(full_q(c)==true){
        return;
    }
    (*c).elemen[(*c).fin]=dat;
    (*c).fin++;
}

void del(Tcola *c){
    if(emp_q(c)==true){
        return;
    }
    for(int i=0;i<(*c).fin-1;i++){
        (*c).elemen[i]=(*c).elemen[i+1];
    }
    (*c).fin--;
}

int elem(const Tcola *c){
    return ((*c).fin);
}

int primero(const Tcola *c){
    if(emp_q(c)==true){
        return 0;
    }
    return (*c).elemen[(*c).in];
}

bool full_q(const Tcola *c){
    return ((*c).fin)==MAX;
}

bool emp_q(const Tcola *c){
    return (*c).in==(*c).fin;
}
