#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid_L, pid_D;
    int status;

    pid_L = fork();
    if (pid_L == 0) {
        sleep(3);
        printf("Terminé mi ejecución: %d %d\n", getpid(), getppid());
        return 0;
    }

    pid_D = fork();
    if (pid_D == 0) {
        sleep(1);
        printf("Terminé mi ejecución: %d %d\n", getpid(), getppid());
        return 0;
    }

    wait(&status);
    printf("Uno de mis hijos ha terminado su ejecución.\n");
}
