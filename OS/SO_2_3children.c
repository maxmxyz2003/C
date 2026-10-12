#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
    pid_t pid1, pid2, pid3;
    pid1 = fork();
    if (pid1 < 0) {
        perror("Error al crear el primer proceso hijo");
        exit(1);
    } else if (pid1 == 0) {
        printf("Soy el primer proceso hijo con PID %d\n", getpid());
        exit(0); 
    }
    pid2 = fork();
    if (pid2 < 0) {
        perror("Error al crear el segundo proceso hijo");
        exit(1);
    } else if (pid2 == 0) {
        printf("Soy el segundo proceso hijo con PID %d\n", getpid());
        exit(0);  
    }
    pid3 = fork();
    if (pid3 < 0) {
        perror("Error al crear el tercer proceso hijo");
        exit(1);
    } else if (pid3 == 0) {
        printf("Soy el tercer proceso hijo con PID %d\n", getpid());
        exit(0);
    }
    wait(NULL);
    wait(NULL);
    wait(NULL);
    printf("Todos los procesos hijos han terminado. Proceso padre finaliza.\n");
    return 0;
}
