#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char **argv) {
    pid_t pid;
    int status;
    int num_children = 3;
    for (int i = 0; i < num_children; i++) {
        pid = fork();
        if (pid < 0) {
            // Error al crear el proceso hijo
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (pid == 0) {
            // Código del proceso hijo
            printf("Proceso hijo %d, PID: %d, PPID: %d\n", i+1, getpid(), getppid());
            exit(0);
        }
        // El proceso padre continúa con el bucle para crear el siguiente hijo
    }
    // El proceso padre espera a que todos los hijos terminen
    for (int i = 0; i < num_children; i++) {
        pid = wait(&status);
        if (pid > 0) {
            printf("Proceso hijo con PID %d ha terminado.\n", pid);
        } else {
            perror("wait");
            exit(EXIT_FAILURE);
        }
    }
    
    printf("Todos los procesos hijos han terminado. Proceso padre finaliza.\n");
    return 0;
}
