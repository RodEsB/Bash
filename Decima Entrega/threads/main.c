/*
    Program that creates 10 theads that print Hola mundo.
*/
#include <pthread.h>
#include <stdio.h>

#define THREADS_NO 10

void* print_hello_world(void *args) {
    int thread_num = *(int*)args;
    if (thread_num % 2 == 0) {
        printf("Soy par \n");
    } else {
        printf("Soy impar \n");
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREADS_NO];
    int i;
    int args[THREADS_NO];

    for(i = 0; i < THREADS_NO; i++) {
        args[i] = i;
        pthread_create(&threads[i], NULL, print_hello_world, (void*)&args[i]);
        printf("Hilo numero %d: ", i);
    }

    for(i = 0; i < THREADS_NO; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
