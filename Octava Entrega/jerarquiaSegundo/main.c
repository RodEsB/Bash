#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid_B, pid_C, pid_E;
    int status;

    pid_B = fork();
    if(pid_B == 0) {
        sleep(3);
        return 1;
    }

    pid_C = fork();
    if(pid_C == 0) {
        sleep(1);
        return 2;
    }

    pid_E = fork();
    if(pid_E == 0) {
        return 3;
    }

    waitpid(pid_B, &status, 0);
    printf("Valor de retorno de B: %d\n", WEXITSTATUS(status));

    waitpid(pid_C, &status, 0);
    printf("Valor de retorno de C: %d\n", WEXITSTATUS(status));

    waitpid(pid_E, &status, 0);
    printf("Valor de retorno de E: %d\n", WEXITSTATUS(status));

    return 0;
}
