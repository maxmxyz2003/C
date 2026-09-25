#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINEAS 1000
#define MAX_LONGITUD 350

// Función para comparar dos cadenas
int comparar(const void *a, const void *b) {
    const char *cadena1 = *(const char **)a;
    const char *cadena2 = *(const char **)b;

    return strcmp(cadena1, cadena2);
}

int main() {

    FILE *entrada;
    FILE *salida;

    char *palabras[MAX_LINEAS];
    char linea[MAX_LONGITUD];

    int cantidad = 0;

    // Abrir archivo de entrada
    entrada = fopen("file.txt", "r");

    if (entrada == NULL) {
        printf("Error: no se pudo abrir file.txt\n");
        return 1;
    }

    // Leer cada línea
    while (fgets(linea, MAX_LONGITUD, entrada) != NULL) {

        // Eliminar el salto de línea
        linea[strcspn(linea, "\n")] = '\0';

        // Reservar memoria para la palabra
        palabras[cantidad] = malloc(strlen(linea) + 1);

        if (palabras[cantidad] == NULL) {
            printf("Error de memoria.\n");
            fclose(entrada);
            return 1;
        }

        strcpy(palabras[cantidad], linea);

        cantidad++;
    }

    fclose(entrada);

    // Ordenar alfabéticamente
    qsort(
        palabras,
        cantidad,
        sizeof(char *),
        comparar
    );

    // Crear archivo de salida
    salida = fopen("sorted.txt", "w");

    if (salida == NULL) {
        printf("Error: no se pudo crear sorted.txt\n");
        return 1;
    }

    // Escribir las palabras ordenadas
    for (int i = 0; i < cantidad; i++) {
        fprintf(salida, "%s\n", palabras[i]);
        free(palabras[i]);
    }

    fclose(salida);

    printf("Archivo ordenado correctamente.\n");
    printf("Resultado guardado en sorted.txt\n");

    return 0;
}
