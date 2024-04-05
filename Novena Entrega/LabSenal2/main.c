#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void alarm_handler(int sig) {
    printf("Transcurrieron 3 segundos\n");
    exit(0);
}

int main() {
    if (signal(SIGALRM, alarm_handler) == SIG_ERR) {
        printf("No se pudo establecer el manejador de la señal SIGALRM.\n");
        exit(EXIT_FAILURE);
    }
    alarm(3);
    pause();

    return 0;
}
