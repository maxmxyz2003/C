#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int grado;
    char escuela[14];
    void *coreo;
}Estudiante;
typedef struct{
    double salario;
    char id;
}Trabajador;
typedef struct{
    double salario;
    char dpto;
}Professeur;
typedef struct{
    int tipo;
    char nombre[50];
    char direccion[50];
    char NumCel[15];
    void *ocup;
}Persona;
int asignMem(void **ptrG, int n){
    int res=0;
    char cadenaej[]="Coko";
    *ptrG=malloc(n*sizeof(Persona));
    if (*ptrG){
        res=1;
        for (int i = 0; i < n&&res; i++){
            printf("Introduce el tipo del elemento %d\n", i);
            scanf("%d", &(((Persona*)(*ptrG+i))->tipo));
            switch (((Persona*)ptrG+i)->tipo){
                case 1:
                    ((Persona*)ptrG+i)->ocup=malloc(sizeof(Professeur));
                    break;
                case 2:
                    ((Persona*)ptrG+i)->ocup=malloc(sizeof(Estudiante));                    
                    memcpy(((Estudiante *)(((Persona*)ptrG+i)->ocup))->coreo, cadenaej, sizeof(cadenaej)/sizeof(char));
                    break;
                case 3:
                    ((Persona*)ptrG+i)->ocup=malloc(sizeof(Trabajador));
                    break;            
                default:
                    break;
            }
            if (!((Persona*)ptrG+i)->ocup){
                while (--i>=0){
                    free(((Persona*)ptrG+i)->ocup);
                    ((Persona*)ptrG+i)->ocup=NULL;
                    i--;
                }
                free(*ptrG);
                *ptrG=NULL;
                res=0;
            }
        }        
    }
}

int main(void){
    void *ptrG_M;
    asignMem(&ptrG_M, 4);
    return 0;
}
