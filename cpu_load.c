#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#define WORK_DURATION 120 // Duración del trabajo en segundos

// Función que simula carga en el procesador

void* thread_work(void* arg) {

    long thread_id = (long)arg;

    printf("Hilo ID: %ld - Iniciando trabajo...\n", thread_id);

    // Simulación de carga (bucle que dura WORK_DURATION segundos)

    sleep(WORK_DURATION);

    printf("Hilo ID: %ld - Trabajo completado.\n", thread_id);

    return NULL;
}

int main() {

    // Obtener el número de núcleos
    int num_cores = get_nprocs();
    printf("Número de núcleos en el sistema: %d\n", num_cores);

    pthread_t threads[num_cores];

    // Crear los hilos
    for (long i = 0; i < num_cores; i++) {
        if (pthread_create(&threads[i], NULL, thread_work, (void*)i) != 0) {
            perror("Error al crear el hilo");
            exit(1);
        }
    }

    // Esperar a que todos los hilos terminen
    for (int i = 0; i < num_cores; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Todos los hilos han completado su trabajo.\n");
    return 0;

}
