#include <pthread.h>
#include <stdio.h>

#define ArraySize 12
#define Threads 3
#define Size (ArraySize / Threads)

int subarrays[Threads][Size];
int found_flag = 0;

void* check_number(void *arg) {
    int index = (int)arg;
    int *subarray = subarrays[index];

    for (int i = 0; i < Size; i++) {
        if (subarray[i] == index) {
            found_flag = 1;
            break;
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[Threads];
    int number;

    int full_array[ArraySize] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    for (int i = 0; i < Threads; i++) {
        for (int j = 0; j < Size; j++) {
            subarrays[i][j] = full_array[i * Size + j]; } }

    printf("Ingrese el número a buscar: ");
    scanf("%d", &number);

    for (int i = 0; i < Threads; i++) { pthread_create(&threads[i], NULL, check_number, (void *)(intptr_t)i); }

    for (int i = 0; i < Threads; i++) { pthread_join(threads[i], NULL); }

    if (found_flag) { printf("Número encontrado.\n");}
    else { printf("Número no encontrado.\n"); }

    return 0;
}
