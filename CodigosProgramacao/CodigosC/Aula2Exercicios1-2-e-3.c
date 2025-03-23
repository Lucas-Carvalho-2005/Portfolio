#include <stdio.h>
#include <stdlib.h>

int main()
{// 1. Escreva um algoritmo para imprimir seu nome.
    char nome [20];
    printf("Por favor, digite o seu nome. \n");
    scanf("%s", nome);
    printf("Em que posso ajudar, %s?\n\n", nome);

 // 2. Escreva um algoritmo para ler um número inteiro e imprimir seu sucessor e antecessor.
    int num;
    printf("\nPor favor, insira um numero. \n");
    scanf("%d", &num);

    int num_sucessor = num + 1;
    int num_antecessor = num - 1;

    printf("\nSucessor do numero: %d", num_sucessor);
    printf("\nAntecessor do numero: %d\n\n", num_antecessor);

 // 3. Escreva um algoritmo para ler nome, endereço e telefone e imprimi-los
    char nome2 [20];
    char endereco [20];
    char telefone [20];

    printf("\nPor favor, digite o seu nome.\n");
    scanf("%s", nome2);

    printf("Agora, insira o seu endereco.\n");
    scanf("%s", endereco);

    printf("Por fim, digite o seu numero de telefone.\n");
    scanf("%s", telefone);

    printf("\nSeja bem-vindo, %s.\n", nome2);
    printf("Voce mora em %s.\n", endereco);
    printf("E seu numero de telefone %s\n", telefone);


}
