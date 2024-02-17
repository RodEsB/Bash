#include <stdio.h>

int factorial(int number)
{
    if (number == 0 || number == 1) {return 1;}
    else{return number * factorial(number - 1);}
}
double expression(int number)
{
    double result = 0;
    for (int i = 1; i <= number - 1; i++)
    {
        result += (double)factorial(i) / factorial(number);
    }
    return result;
}

int main()
{
    int number;
    printf("Ingrese un valor entero: ");
    scanf("%d", &number);

    printf("El resultado es: %.3f\n", expression(number));
    return 0;
}
