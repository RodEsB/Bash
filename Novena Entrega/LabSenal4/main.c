#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void alarm_handler(int sig) {
    printf("Alarma recibida\n");
    exit(1);
}

int main() {
    pid_t pid_b, pid_c;

    pid_b = fork();

    if (pid_b == 0) {
        pid_c = fork();

        if (pid_c == 0) {
            printf("C esperando una señal\n");
        } else {
            sleep(1);
            kill(pid_c, SIGKILL);
            pause();
        }
    } else {
        signal(SIGALRM, alarm_handler);
        alarm(5);
        wait(NULL);
    }

    return 0;
}
