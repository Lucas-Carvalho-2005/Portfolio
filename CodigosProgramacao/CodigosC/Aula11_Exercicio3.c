#include <stdlib.h>
#include <stdio.h>

int Fibonacci (int n)
{
    if (n == 1)
        return 0;

    if (n == 2)
        return 1;

    else
        return Fibonacci(n-1) + Fibonacci(n-2);
}

int main(void)
{
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);
    printf("Fib: ");
    for (int i = 1; i <= num; i++)
    {
        printf("%d, ", Fibonacci(i));

    }


}
