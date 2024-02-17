#include <stdio.h>

void asterisks(int number)
{
    if (number > 0)
    {
        for (int i = 1; i <= number; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
}

int main()
{
    int number;
    printf("Ingresa un valor entero: ");
    scanf("%d", &number);

    printf("Figura:\n");
    asterisks(number);

    return 0;
}
