#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>  // Incluir esta línea

void contar_hasta_1000(int hijo_num) {
    for (int i = 1; i <= 1000; i++) {
        printf("Hijo %d: %d\n", hijo_num, i);
        usleep(1000); // Pausa breve para hacer la salida más legible
    }
}

int main() {
    pid_t pid1, pid2, pid3;

    // Crear primer proceso hijo
    if ((pid1 = fork()) == 0) {
        contar_hasta_1000(1);
        exit(0);
    }

    // Crear segundo proceso hijo
    if ((pid2 = fork()) == 0) {
        contar_hasta_1000(2);
        exit(0);
    }

    // Crear tercer proceso hijo
    if ((pid3 = fork()) == 0) {
        contar_hasta_1000(3);
        exit(0);
    }

    // Esperar a que los procesos hijos terminen
    wait(NULL);
    wait(NULL);
    wait(NULL);

    printf("Todos los procesos hijos han terminado.\n");

    return 0;
}
