#include <stdio.h>
#include <stdlib.h>
// Estructuras
typedef struct {
    char Nombre[50];
    int edad;
} Persona;
typedef struct {
    char NombreC[50];
    double Ganancias;
} Compania;
typedef struct {
    void *data;
    int TipoDato;
} DataHolder;
DataHolder** crearMatriz(int filas, int colums) {
    DataHolder** matriz = (DataHolder**)malloc(filas * sizeof(DataHolder*));
    for (int i = 0; i < filas; i++) {
        matriz[i] = (DataHolder*)malloc(colums * sizeof(DataHolder));
    }
    return matriz;
}
void asignarPtrGen(DataHolder** matriz, int row, int col, void *data, int TipoDato) {
    matriz[row][col].data = data;
    matriz[row][col].TipoDato = TipoDato;
}
void* obtenerDevolverptrGen(DataHolder** matriz, int row, int col) {
    if (matriz[row][col].TipoDato == 0) {
        // return (Persona*)matriz[row][col].data;
        return (Persona*)(*(matriz+row)+col)->data;
    } else if (matriz[row][col].TipoDato == 1) {
        // return (Compania*)matriz[row][col].data;
        return (Compania*)(*(matriz+row)+col)->data;
    }
    return NULL; // Handle other data types as needed
}
int main(void) {
    int filas = 2;
    int colums = 2;
    DataHolder** matriz = crearMatriz(filas, colums);
    Persona Persona1 = {"Alice", 30};
    Compania compania1 = {"ABC Inc.", 1000000.0};
    asignarPtrGen(matriz, 0, 0, &Persona1, 0); // 0 = Persona struct
    asignarPtrGen(matriz, 0, 1, &compania1, 1); // 1 = Compania struct
    Persona* retrievedPersona = (Persona*)obtenerDevolverptrGen(matriz, 0, 0);
    Compania* retrievedCompania = (Compania*)obtenerDevolverptrGen(matriz, 0, 1);
    printf("Persona: %s, Edad: %d\n", retrievedPersona->Nombre, retrievedPersona->edad);
    printf("Compania: %s, Ganancias: %.2lf\n", retrievedCompania->NombreC, retrievedCompania->Ganancias);
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}
