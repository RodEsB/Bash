#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

void writeToFile(int fd, int *arr, int size) {
    for (int i = 0; i < size; i++) {
        dprintf(fd, "Los valores son: %d\n", arr[i]);
    }
    close(fd);
}

int main() {
    pid_t pid_N, pid_M;
    pid_N = fork();

    if (pid_N == 0) {
        int pairsValues[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
        int fd_N = open("N.txt", 777);
        writeToFile(fd_N, pairsValues, 10);
    } else {
        wait(0);

        pid_M = fork();

        if (pid_M == 0) {
            int oddValues[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
            int fd_M = open("M.txt", 777);
            writeToFile(fd_M, oddValues, 10);
        } else {
            wait(0);

            int fd_N = open("N.txt", 777);
            int fd_M = open("M.txt", 777);

            if (fd_N != -1 && fd_M != -1) {
                int valorN, valorM, suma;
                suma = 0;

                while (read(fd_N, &valorN, sizeof(int)) > 0 && read(fd_M, &valorM, sizeof(int)) > 0) {
                    suma += valorN + valorM;
                }

                close(fd_N);
                close(fd_M);

                printf("La suma de los arreglos es: %d\n", suma);
            }
        }
    }

    return 0;
}
