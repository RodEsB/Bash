#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void fdFunction(int fd, int n, float value) {
    if (fd < 0) {
        perror("Error al crear el archivo");
        return;
    }

    if (value< 0) {
        if (errno == EAGAIN) { printf("Error de tipo EAGAIN: Operación temporalmente no disponible\n");
        } else if (errno == EACCES) { printf("Error de tipo EACCES: Permiso denegado\n");
        } else if (errno == EBADF) { printf("Error de tipo EBADF: Descriptor de archivo no válido\n");
        } else { perror("Error al escribir en el archivo, debido a que es un valor negativo"); }

        close(fd);
        return;
    }
    printf("Se realizó el proceso exitosamente");
}

int main() {
    int fd, n;
    float value;

    printf("Dame un valor: ");
    scanf("%f", &value);

    fd = creat("archivo.txt", 777);
    n = write(fd, &value, sizeof(value));

    fdFunction(fd, n, value);

    return 0;
}
