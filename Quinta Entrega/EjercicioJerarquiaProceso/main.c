#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    pid_t readAndWrite;
    int fd;
    float value;

    fd = creat("archivo.txt", 777);

    readAndWrite = fork();

    if (readAndWrite > 0) {
        sleep(30);

        printf("Datos leídos del archivo: %f\n", value);

    } else if (readAndWrite == 0) {
        printf("Escribe 5 valores enteros:\n");

        for (int i = 0; i < 5; ++i) {
            printf("Ingrese el valor %d: ", i + 1);
            scanf("%f", &value);

            ssize_t written = write(fd, &value, sizeof(value));

        }
        printf("Datos introducidos en el archivo.\n");
        exit(0);
    }
    close(fd);

    return 0;
}
