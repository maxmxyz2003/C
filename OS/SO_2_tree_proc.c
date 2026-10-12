#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void create_process_tree(int level, int max_level) {
    pid_t pid;    
    if (level > max_level) {
        return;
    }
    pid = fork();
    if (pid < 0) {
        // Error al crear el proceso hijo
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        // Código del proceso hijo
        printf("Proceso nivel %d, PID: %d\n", level, getpid());
        create_process_tree(level + 1, max_level);
        exit(0);
    } else {
        // Código del proceso padre
        wait(NULL); // Espera a que el hijo termine
        printf("Proceso nivel %d, PID: %d terminó.\n", level, getpid());
    }
}

int main(int argc, char *argv[]) {
    int max_level = 3;
    printf("Proceso inicial, PID: %d\n", getpid());
    create_process_tree(1, max_level);
    return 0;
}
