// hijo1.c
#include <stdio.h>
#include <stdlib.h>
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <a>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int a = atoi(argv[1]);
    int resultado = factorial(a);
    printf("El factorial de %d es %d\n", a, resultado);

    exit(resultado);  // Regresar el resultado al proceso padre
}
