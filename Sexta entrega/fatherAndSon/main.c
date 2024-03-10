#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid_R, pid_T, pid_W, pid_V, pid_S, pid_L, pid_P;

    pid_R = getpid();
    printf("Proceso Padre su ID: %d\n", pid_R);

    pid_T = fork();

    if (pid_T == 0) {
        pid_V = fork();

        if (pid_V == 0) {
            printf("Proceso V su ID: %d, id del padre: %d\n", getpid(), getppid());
        } else {
            wait(NULL);
            printf("Proceso T su ID: %d, id del padre: %d\n", getpid(), getppid());
        }
    } else {
        wait(0);
        pid_W = fork();
        if (pid_W == 0) { pid_S = fork();
            if (pid_S == 0) { printf("Proceso S su ID: %d, id del padre: %d\n", getpid(), getppid());
            } else { pid_L = fork();
                if (pid_L == 0) { pid_P = fork();
                    if (pid_P == 0) { printf("Proceso P su ID: %d, id del padre: %d\n", getpid(), getppid());
                    } else { wait(0); printf("Proceso L su ID: %d, id del padre: %d\n", getpid(), getppid());
                    }
                } else { wait(0);
                    printf("Proceso W su ID: %d, id del padre: %d\n", getpid(), getppid());
                }
            }
        }
    }

    return 0;
}
