
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char nombre[25];
    int edad;
    float estatura;
    float peso;
    float imc;
}PER;

// Funcion para alojar matriz
int AsignMemMat( PER ***matrix, int filas, int colums) {
    int res=0;
    * matrix = (PER **)malloc(filas * sizeof(PER*));
    if (*matrix){
        res=1;
        for (int i = 0; i < colums&&res; i++){
            *(*matrix+i) = (PER*)malloc(colums * sizeof(PER));
            if (!(*matrix+i)){
                while (--i>=0){
                    free((*matrix+i));
                    i--;
                }
                free(*matrix);
                res=0;
            }
        }
    }
}
// Funcion para modificar valores
void ModMatriz(PER ** matrix, int filas, int colums) {
    char cadTemp[50];
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < colums; j++) {
            printf("Introduce el nombre de la persona [%d][%d]\n", i,j);
            scanf(" %50[^\n]s", cadTemp);
            strcpy((*(matrix + i)+j)->nombre, cadTemp);
            printf("Introduce la edad de la persona [%d][%d]\n", i,j);
            scanf( "%d",&(*(matrix+i)+j)->edad);
            printf("Introduce el peso de la persona [%d][%d]\n", i,j);
            scanf( "%f",&(*(matrix+i)+j)->peso);
            printf("Introduce la estatura de la persona [%d][%d]\n", i,j);
            scanf( "%f",&(*(matrix+i)+j)->estatura);
            printf("Introduce el IMC de la persona [%d][%d]\n", i,j);
            scanf( "%f",&(*(matrix+i)+j)->imc);
        }
    }
}

// Funcion para imprimir matriz
void ImprimirMat(PER** matrix, int filas, int colums) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < colums; j++) {
            printf("Nombre de la persona [%d][%d]: %s \n", i,j, (*(matrix+i)+j)->nombre);
            printf("Edad de la persona [%d][%d]: %d \n", i,j, (*(matrix+i)+j)->edad);
            printf("Peso de la persona [%d][%d]: %f \n", i,j, (*(matrix+i)+j)->peso);
            printf("Estatura de la persona [%d][%d]: %f \n", i,j, (*(matrix+i)+j)->estatura);
            printf("Indice de masa de la persona [%d][%d]: %f \n", i,j, (*(matrix+i)+j)->imc);
        }
        printf("\n");
    }
}

// Funcion para liberar memoria de la matriz
void LiberarMatriz(PER** matrix, int filas) {
    for (int i = 0; i < filas; i++) {
            free(*(matrix+i));
        }
        free(matrix);
}

int main() {
    int filas, colums;
    printf("Introduce el numero de filas\n");
    scanf("%d", &filas);
    printf("Introduce el numero de columnas\n");
    scanf("%d", &colums);
    PER ** miMatriz;
    AsignMemMat(&miMatriz,filas, colums);
    ModMatriz(miMatriz, filas, colums);
    ImprimirMat(miMatriz, filas, colums);
    LiberarMatriz(miMatriz, filas);
    return 0;
}
