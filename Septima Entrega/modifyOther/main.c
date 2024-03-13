#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid_A, pid_B, pid_M;
    int status;

    pid_A = fork();
    if (pid_A == 0) {
        sleep(10);
        printf("Proceso A con su id: %d\n", getpid());
        exit(10);
    }

    pid_B = fork();
    if (pid_B == 0) {
        printf("Proceso B con su id: %d\n", getpid());
        exit(0);
    }

    pid_M = fork();
    if (pid_M == 0) {
        sleep(3);
        printf("Proceso M con su id: %d\n", getpid());
        exit(3);
    }

    waitpid(pid_M, &status, 0);
    printf("Resultado de M: %d\n", WEXITSTATUS(status));

    waitpid(pid_A, &status, 0);
    printf("Resultado de A: %d\n", WEXITSTATUS(status));

    waitpid(pid_B, &status, 0);
    printf("Resultado de B: %d\n", WEXITSTATUS(status));

    return 0;
}
