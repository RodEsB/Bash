#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void sigint_handler(int sig) {
    printf("\nEl usuario oprimió Ctrl+C\n");
    sleep(3);
}

int main() {
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        printf("No se pudo establecer el manejador de la señal SIGINT.\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("ID del proceso: %d\n", getpid());
        sleep(1);
    }

    return 0;
}
