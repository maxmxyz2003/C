#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
void captura_elem(long int matr[MAX][MAX], long int colum, long int reng);
void imprime_mat(long int matr[MAX][MAX], long int colum, long int reng);
void suma_mat(long int matr1[MAX][MAX], long int matr2[MAX][MAX],
              long int matr3[MAX][MAX], long int colum, long int reng);
int main(void) {
    long int mat1[MAX][MAX];
    long int mat2[MAX][MAX];
    long int mat3[MAX][MAX];
    long int col, ren;
    // printf("Escribe la cantidad de renglones y despues de columnas: \n");
    scanf("%ld %ld", &col, &ren);
    captura_elem(mat1, col, ren);
    captura_elem(mat2, col, ren);
    suma_mat(mat1, mat2, mat3, col, ren);
    imprime_mat(mat3, col, ren);
    return 0;
}
void captura_elem(long int matr[MAX][MAX], long int colum, long int reng) {
    for (long int i = 0; i < reng; i++) {
        for (long int j = 0; j < colum; j++) {
            scanf("%ld", &matr[i][j]);
        }
    }
}
void suma_mat(long int matr1[MAX][MAX], long int matr2[MAX][MAX],
              long int matr3[MAX][MAX], long int colum, long int reng) {
    for (long int i = 0; i < reng; i++) {
        for (long int j = 0; j < colum; j++) {
            matr3[i][j] = matr1[i][j] + matr2[i][j];
        }
    }
}
void imprime_mat(long int matr[MAX][MAX], long int colum, long int reng) {
    for (long int i = 0; i < reng; i++) {
        for (long int j = 0; j < colum; j++) {
            printf("%ld\t", matr[i][j]);
        }
        printf("\n");
    }
}
