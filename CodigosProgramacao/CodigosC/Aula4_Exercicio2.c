#include <stdio.h>
#include <stdlib.h>

int main()
{

    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    if (num != 0){

        if (num < 0){
            printf("Valor ja negativo.\n");
        }
        else{
            num = num * -1;
            printf("Valor negativo do numero: %d\n", num);
        }
    }

    else {
        printf("O numero e nulo e nao tem sinal.\n");
    }

    return 0;
}
