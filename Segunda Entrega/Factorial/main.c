#include <stdio.h>

int factorial_number() {
    int number;
    int factorial = 1;
    printf("Ingresa un valor: ");
    scanf("%d", &number);

    for (int i = 1; i <= number; i++) {
        factorial *= i;
    }
    return factorial;
}

int main (){

    printf("El factorial es: %d", factorial_number());
    return 0;
}

