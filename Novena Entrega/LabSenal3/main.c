#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void sigusr1_handler(int sig) {
    printf("Recibí la señal SIGUSR1, mi ID es %d, ID de mi padre es %d\n", getpid(), getppid());
}

void sigusr2_handler(int sig) {
    printf("Recibí la señal SIGUSR2, mi ID es %d, ID de mi padre es %d\n", getpid(), getppid());
}

int main() {
    pid_t pid_a, pid_c;
    pid_a = fork();

    if (pid_a == 0) {
        signal(SIGUSR1, sigusr1_handler);

        pid_c = fork();

        if (pid_c == 0) {
            signal(SIGUSR2, sigusr2_handler);
            pause();
            exit(0);
        } else {
            pause();
            kill(pid_c, SIGUSR2);
            wait(NULL);
            exit(0);
        }
    } else {
        sleep(3);
        printf("Alarma recibida\n");
        kill(pid_a, SIGUSR1);
        wait(NULL);
        printf("Mis hijos han terminado\n");
    }

    return 0;
}