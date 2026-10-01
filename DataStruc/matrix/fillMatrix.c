// filling matrices full example
#include <stdio.h>

void fillMatrixSnail(int n, int matrix[n][n]) {
    int value = 1;
    int startRow = 0, endRow = n - 1;
    int startCol = 0, endCol = n - 1;
    while (startRow <= endRow && startCol <= endCol) {
        // Fill top row
        for (int i = startCol; i <= endCol; i++) {
            matrix[startRow][i] = value++;
        }
        startRow++;
        // Fill right column
        for (int i = startRow; i <= endRow; i++) {
            matrix[i][endCol] = value++;
        }
        endCol--;
        // Fill bottom row
        if (startRow <= endRow) {
            for (int i = endCol; i >= startCol; i--) {
                matrix[endRow][i] = value++;
            }
            endRow--;
        }
        // Fill left column
        if (startCol <= endCol) {
            for (int i = endRow; i >= startRow; i--) {
                matrix[i][startCol] = value++;
            }
            startCol++;
        }
    }
}
void fillMatrixSnake(int n, int matrix[n][n]) {
    int value = 1;
    int startRow = 0, endRow = n - 1;
    int startCol = 0, endCol = n - 1;
    while (startRow <= endRow && startCol <= endCol) {
        // Fill top row
        for (int i = startCol; i <= endCol; i++) {
            matrix[startRow][i] = value++;
        }
        startRow++;
        // Fill right column
        for (int i = endCol; i >= startCol; i--) {
            matrix[startRow][i] = value++;
        }
        startRow++;
    }
}
void fillMatrixLevels(int n, int matrix[n][n]) {
    int value = 0;
    int startRow = 0, endRow = n - 1;
    int startCol = 0, endCol = n - 1;
    while (startRow <= endRow && startCol <= endCol) {
        // Fill top row
        for (int i = startCol; i <= endCol; i++) {
            matrix[startRow][i] = value;
        }
        // Fill right column
        for (int i = startRow + 1; i <= endRow; i++) {
            matrix[i][startCol] = value;
        }
        value++;
        startRow++;
        startCol++;
        //endRow--;
        //endCol--;
    }
}
void fillMatrixDiagonals(int rows, int cols, int matrix[rows][cols]) {
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (i + j) % rows + 1;
        }
    }
}
void printMatrix(int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];
    fillMatrixSnail(n, matrix);
    printf("Matrix filled in snail pattern:\n");
    printMatrix(n, matrix);
    fillMatrixSnake(n, matrix);
    printf("Matrix filled in snake pattern:\n");
    printMatrix(n, matrix);
    printf("Matrix filled in Layers pattern:\n");
    fillMatrixLevels(n, matrix);
    printMatrix(n, matrix);
    printf("Matrix filled in diagonals pattern:\n");
    fillMatrixDiagonals(n,n, matrix);
    printMatrix(n,matrix);
    return 0;
}
