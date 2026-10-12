#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
// Estructura para los argumentos del hilo 2
typedef struct {
    int base;
    int altura;
    int area;
    int perimetro;
} rectangulo_t;

// Variables globales
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t hilo1_done = PTHREAD_COND_INITIALIZER;
int hilo1_terminado = 0;

// Función para calcular el factorial (Hilo 1)
void *calcular_factorial(void *arg) {
    int n = *(int *)arg;
    int resultado = 1;

    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }

    printf("Hilo 1: El factorial de %d es %d.\n", n, resultado);

    // Señalizar que el hilo 1 ha terminado
    pthread_mutex_lock(&lock);
    hilo1_terminado = 1;
    pthread_cond_signal(&hilo1_done);
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

// Función para calcular el área y perímetro de un rectángulo (Hilo 2)
void *calcular_area_perimetro(void *arg) {
    rectangulo_t *rect = (rectangulo_t *)arg;
    rect->area = rect->base * rect->altura;
    rect->perimetro = 2 * (rect->base + rect->altura);

    pthread_exit((void *)rect);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso de solamente <numero a> <numero b>\n");
        exit(EXIT_FAILURE);
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    
    pthread_t thread1, thread2;
    rectangulo_t rect = {b, a, 0, 0};
    
    // Crear el hilo 1
    if (pthread_create(&thread1, NULL, calcular_factorial, (void *)&a) != 0) {
        perror("Error al crear el hilo 1");
        exit(EXIT_FAILURE);
    }

    // Crear el hilo 2
    if (pthread_create(&thread2, NULL, calcular_area_perimetro, (void *)&rect) != 0) {
        perror("Error al crear el hilo 2");
        exit(EXIT_FAILURE);
    }

    // Esperar a que el hilo 1 termine
    pthread_mutex_lock(&lock);
    while (!hilo1_terminado) {
        pthread_cond_wait(&hilo1_done, &lock);
    }
    printf("Padre: Hilo 1 ha terminado.\n");
    pthread_mutex_unlock(&lock);

    // Esperar a que el hilo 2 termine y recibir los resultados
    void *resultado_hilo2;
    if (pthread_join(thread2, &resultado_hilo2) != 0) {
        perror("Error al esperar el hilo 2");
        exit(EXIT_FAILURE);
    }

    rectangulo_t *result = (rectangulo_t *)resultado_hilo2;
    printf("Padre: Área del rectángulo = %d, Perímetro del rectángulo = %d\n", result->area, result->perimetro);
    printf("Padre: Hilo 2 ha terminado.\n");

    printf("Padre: Se ejecutaron y terminaron todos los hilos.\n");

    // Liberar recursos
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&hilo1_done);

    return 0;
}
