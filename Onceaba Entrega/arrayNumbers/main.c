#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define size 5

int data[size] = {0};
pthread_mutex_t lock;

void consume_data() {
    int index = 0;
    while (index < size) {
        pthread_mutex_lock(&lock);
        if (data[index] != 0) {
            printf("Consumido: %d en la posición %d\n", data[index], index);
            data[index] = 0;
            index++;
        }
        pthread_mutex_unlock(&lock);
        sleep(5);
    }
}

void* consumer_thread(void *arg) {
    consume_data();
    return NULL;
}

void produce_data() {
    for (int i = 0; i < size; i++) { printf("Ingrese un valor para la posición %d del arreglo: ", i);
        scanf("%d", &data[i]); } }

int main() {
    pthread_t tid;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&tid, NULL, consumer_thread, NULL);

    produce_data();
    pthread_join(tid, NULL);
    printf("Finalizado.\n");

    pthread_mutex_destroy(&lock);
    return 0;
}
