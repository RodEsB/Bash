#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void printInfo() {
    printf("Proceso con su id: %d\n", getpid());
}

int main() {
    int processFinished= 0;

    for (int i = 0; i < 3; i++) {
        pid_t pid_son = fork();

        if (pid_son == 0) { printInfo();
            exit(0); }

        waitpid(pid_son, NULL, 0);

        if (WIFEXITED(pid_son) && WEXITSTATUS(pid_son) == 0) { processFinished++; }
    }

    printf("Procesos de hijos con fallas: %d\n", processFinished);

    return 0;
}
