#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int readAndPrintFromFile(const char *fileName, int elements) {
    int fd;
    float readArray[elements];
    ssize_t n;

    fd = open(fileName, 0666);

    if (fd < 0) { perror("Hubo un error abriendo el archivo para lectura");
        return -1; }

    n = read(fd, readArray, elements * sizeof(float));
    close(fd);

    if (n < 0) { perror("Hubo un error leyendo el archivo");
        return -1; }

    printf("Datos almacenados de %s:\n", fileName);
    for (int i = 0; i < elements; i++) {
        printf("%f\n", readArray[i]);
    }
    return 0;
}

int readAndPrintValues(const char *fileName) {
    int fd;
    float n;

    fd = open(fileName, 0666);

    if (fd < 0) { perror("Hubo un error abriendo el archivo para leer");
        return -1;}

    printf("\nDatos de %s:\n", fileName);
    while (read(fd, &n, sizeof(float)) > 0) {
        printf("%f\n", n);
    }
    close(fd);

    return 0;
}

int writeArrayToFile(const char *fileName, const float *array, int elements) {
    int fd;
    ssize_t n;

    fd = open(fileName, 0666);

    if (fd < 0) { perror("Hubo un error abriendo el archivo para abrir");
        return -1; }

    n = write(fd, array, elements * sizeof(float));
    close(fd);

    if (n < 0) { perror("Hubo un error escribiendo en el archivo");
        return -1; }

    return 0;
}

int writeValuesToFile(const char *fileName, const float *values, int numValues) {
    int fd;
    ssize_t n;

    fd = open(fileName, 0666);

    if (fd < 0) { perror("Hubo un error abriendo el archivo para escribir");
        return -1;}

    for (int i = 0; i < numValues; i++) {
        n = write(fd, &values[i], sizeof(float));
        printf("Escritura del %d: %ld\n", i + 1, n);
    }

    close(fd);

    if (n < 0) { perror("Hubo un error escribiendo en el archivo");
        return -1; }

    return 0;
}

int main() {
    float firstArray[] = {1.4, 5.8, 6.4, 9.2, 1.0};
    float secondArray[] = {13.4, 2.4, 1.1, 9.9, 3.1};
    int elements = sizeof(firstArray) / sizeof(firstArray[0]);

    writeArrayToFile("datos.txt", firstArray, elements);
    readAndPrintFromFile("datos.txt", elements);

    writeValuesToFile("datos2.txt", secondArray, 5);
    readAndPrintValues("datos2.txt");

    return 0;
}
