#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3;

    // Crear el primer proceso hijo
    pid1 = fork();
    if (pid1 < 0) {
        perror("Error al crear el primer proceso hijo");
        exit(1);
    } else if (pid1 == 0) {
        printf("Soy el primer proceso hijo con PID %d, PPID %d\n", getpid(), getppid());
        sleep(5);  // Mantener el proceso vivo para verificar con ps
        exit(0);
    }

    // Crear el segundo proceso hijo
    pid2 = fork();
    if (pid2 < 0) {
        perror("Error al crear el segundo proceso hijo");
        exit(1);
    } else if (pid2 == 0) {
        printf("Soy el segundo proceso hijo con PID %d, PPID %d\n", getpid(), getppid());
        sleep(5);
        exit(0);
    }

    // Crear el tercer proceso hijo
    pid3 = fork();
    if (pid3 < 0) {
        perror("Error al crear el tercer proceso hijo");
        exit(1);
    } else if (pid3 == 0) {
        printf("Soy el tercer proceso hijo con PID %d, PPID %d\n", getpid(), getppid());
        sleep(5);
        exit(0);
    }

    // Esperar a que todos los procesos hijos terminen
    wait(NULL);
    wait(NULL);
    wait(NULL);

    printf("Todos los procesos hijos han terminado. Proceso padre finaliza. PID: %d, PPID: %d\n", getpid(), getppid());
    return 0;
}
