#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Define the NAME structure
typedef struct {
    char name[40];
    char lastname[40];
} NAME;
// Define the Person structure
typedef struct {
    NAME* name;
    int age;
    float weight;
} Person;

// Function to allocate memory for a matrix of Person
Person*** AllocateMatrix(int rows, int cols) {
    Person*** matrix = (Person***)malloc(rows * sizeof(Person**));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (Person**)malloc(cols * sizeof(Person*));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (Person*)malloc(sizeof(Person));
            matrix[i][j]->name = (NAME*)malloc(sizeof(NAME));
            if (matrix[i][j]->name != NULL) {
                strcpy(matrix[i][j]->name->name, "John");
               strcpy(matrix[i][j]->name->lastname, "Doe");
                matrix[i][j]->age = 30;
                matrix[i][j]->weight = 70.5;
            } else {
                // Manejar el error de asignación de memoria
            }
        }
    }
    return matrix;
}
// Function to manipulate data in the matrix
void ModifyMatrix(Person*** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Modify fields (you can modify this)
            strcpy(matrix[i][j]->name->name, "Alice");
            strcpy(matrix[i][j]->name->lastname, "Smith");
            matrix[i][j]->age = 25;
            matrix[i][j]->weight = 62.0*(1+(i+j)/10.0);
        }
    }
}

// Function to print the matrix
void PrintMatrix(Person*** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Person[%d][%d]:\n", i, j);
            printf("Name: %s %s\n", matrix[i][j]->name->name, matrix[i][j]->name->lastname);
            printf("Age: %d\n", matrix[i][j]->age);
            printf("Weight: %.2f\n", matrix[i][j]->weight);
            printf("\n");
        }
    }
}
// Function to free memory allocated for the matrix
void FreeMatrix(Person*** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}
int main() {
    int rows = 2;
    int cols = 2;
    // Allocate memory for the matrix
    Person*** myMatrix = AllocateMatrix(rows, cols);
    // Modify data in the matrix
    ModifyMatrix(myMatrix, rows, cols);
    // Print the matrix
    PrintMatrix(myMatrix, rows, cols);
    // Free memory for the matrix
    FreeMatrix(myMatrix, rows, cols);
    return 0;
}
