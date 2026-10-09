#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Funcion para alojar matriz
int AsignMemMat( long double ***matrix, int filas, int colums) {
    int res=0;
    *matrix=(long double**)malloc(filas * sizeof(long double*));//Damos espacio para las filas
    if (*matrix){
        res=1;
        for(int i = 0; i < colums&&res; i++){//Vamos recorriendo cada parte del apuntador, siempre y cuando haya espacio
            *(*matrix+i) = (long double*)malloc(colums * sizeof(long double));// Vamos asignando el espacio de las columnas
            if (!*(*matrix+i)){//Dado el caso de que no haya mas espacio se libera la memoria
                while (--i>=0){
                    free((*matrix+i));
                    i--;
                }
                free(*matrix);
                res=0;//Se cancela el ciclo
            }
        }
    }  
}
// Funcion para modificar valores
void ModMatriz(long double ** matrix, int filas, int colums) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < colums; j++) {
            printf("Introduce el dato [%d][%d]\n", i,j);
            scanf( "%Lf",(*(matrix+i)+j));
            // scanf( "%Lf",&*(*(matrix+i)+j)); Podemos usar esta lo la simplificada       
        }
    }
}
// Funcion para imprimir matriz
void ImprimirMat(long double** matrix, int filas, int colums) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < colums; j++) {
        printf( "%Lf ",*(*(matrix+i)+j));        
        }
        printf("\n");
    }
}

// Funcion para liberar memoria de la matriz
void LiberarMatriz(long double** matrix, int filas) {
    for (int i = 0; i < filas; i++) {
            free(*(matrix+i));//Solo liberamos las "filas"
        }
        free(matrix);
}
int main(void){
    int filas, colums;
    printf("Introduce el numero de filas:\n");
    scanf("%d", &filas);
    printf("Introduce el numero de columnas:\n");
    scanf("%d", &colums);
    long double **LaMatrix;
    AsignMemMat(&LaMatrix,filas, colums);
    ModMatriz(LaMatrix, filas, colums);
    ImprimirMat(LaMatrix, filas, colums);
    LiberarMatriz(LaMatrix, filas);
    return 0;
}
