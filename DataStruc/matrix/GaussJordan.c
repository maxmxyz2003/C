#include <stdio.h>
#include <stdlib.h>
#define MAX 10  // Definimos el tamaño máximo de la matriz
void printMatrix(float matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%0.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void gaussJordan(float matrix[MAX][MAX], int n) {
    int i, j, k;
    float ratio;

    for (i = 0; i < n; i++) {
        // Hacemos el elemento diagonal 1 y los demás elementos de su columna 0
        for (j = 0; j < n; j++) {
            if (i != j) {
                ratio = matrix[j][i] / matrix[i][i];
                for (k = 0; k <= n; k++) {
                    matrix[j][k] -= ratio * matrix[i][k];
                }
            }
        }
    }

    // Dividimos cada fila por el elemento diagonal para que la diagonal sea 1
    for (i = 0; i < n; i++) {
        for (j = n; j >= i; j--) {
            matrix[i][j] /= matrix[i][i];
        }
    }
}

int main() {
    float matrix[MAX][MAX];
    int n, i, j;

    printf("Ingrese el número de ecuaciones: ");
    scanf("%d", &n);

    printf("Ingrese los elementos de la matriz aumentada (coeficientes y términos independientes):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    printf("Matriz aumentada ingresada:\n");
    printMatrix(matrix, n);

    gaussJordan(matrix, n);

    printf("La matriz reducida por el método de Gauss-Jordan es:\n");
    printMatrix(matrix, n);

    printf("Las soluciones son:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %0.2f\n", i + 1, matrix[i][n]);
    }
    return 0;
}
