// padre.c
// Nombre del integrante del equipo: Maximiliano Mendez Hernandez
// Nombre del profesor: Marcela Ortiz Hernandez
// Fecha: 22/09/24
// Orden de ejecución: ./padre <a> <b>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <a> <b>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    pid_t pid1, pid2;
    int status;
    if ((pid1 = fork()) == 0) {// Proceso hijo 1
        char *args[] = {"./_fact", argv[1], NULL};
        execv(args[0], args);
        printf("execv fallo en hijo1\n");
        exit(EXIT_FAILURE);
    } else if (pid1 < 0) {
        printf("error de fork\n");
        exit(EXIT_FAILURE);
    }
    if ((pid2 = fork()) == 0) {// Proceso hijo 2
        char *args[] = {"./hijo2", argv[1], argv[2], NULL};
        execv(args[0], args);
        printf("execv fallo en hijo2");
        exit(EXIT_FAILURE);
    } else if (pid2 < 0) {
        printf("fork fallo");
        exit(EXIT_FAILURE);
    }
    // Esperar el resultado del proceso hijo 1
    waitpid(pid1, &status, 0);
    if (WIFEXITED(status)) {
        int resultado = WEXITSTATUS(status);
        printf("Proceso hijo 1 termino con resultado: %d\n", resultado);
    }
    // Esperar que el proceso hijo 2 termine
    waitpid(pid2, &status, 0);
    printf("Proceso hijo 2 ha terminado\n");
    // Mensaje final
    printf("Se ejecutaron y terminaron todos los procesos hijos.\n");
    exit(0);
}