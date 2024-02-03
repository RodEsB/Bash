#include <stdio.h>

int main() {
    int number = 30;
    int fact;
    int find = 0;
    int result;

    do {
        fact = 0;
        for (int i = 1; i <= number; i++) {
            if (number % i == 0) {
                fact++;
            }
        }
        if (fact == 2) {
            find = 2;
            result = number;
        }
        number++;
    }while (find != 2);
    printf("Se encontró: ""%d", result);

}
