#include <pthread.h>
#include <stdio.h>

long long factorialOne = 1, factorialTwo = 1, factorialThree = 1;

void* calculate_factorial(void *arguments) {
    int *arg = (int *)arguments;
    int start = arg[0];
    int end = arg[1];
    long long *result = (long long *)arg[2];
    *result = 1;
    for (int i = start; i <= end; i++) { *result *= i; }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    int ranges[3][3];
    int target_number;

    printf("Ingrese un número divisible entre 3: ");
    scanf("%d", &target_number);

    if (target_number % 3 != 0) {
        printf("El número debe ser divisible entre 3.\n");
        return -1;
    }

    for (int i = 0; i < 3; i++) {
        ranges[i][0] = i * (target_number / 3) + 1;
        ranges[i][1] = (i + 1) * (target_number / 3);
        if (i == 0) ranges[i][2] = (int)&factorialOne;
        else if (i == 1) ranges[i][2] = (int)&factorialTwo;
        else ranges[i][2] = (int)&factorialThree;
    }

    for (int i = 0; i < 3; i++) { pthread_create(&threads[i], NULL, calculate_factorial, (void*)ranges[i]); }

    for (int i = 0; i < 3; i++) { pthread_join(threads[i], NULL); }

    long long total_factorial = factorialOne * factorialTwo * factorialThree;

    printf("El factorial de %d es %lld.\n", target_number, total_factorial);

    return 0;
}
