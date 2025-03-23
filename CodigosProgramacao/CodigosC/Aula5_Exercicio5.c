#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome_do_hospede [20];
    char tipo_apartamento;
    int quantidade_diarias;
    float valor_consumo;
    float valor_diaria;
    float taxa_10;
    float total_final;
    float total_diarias;

    printf("Digite o seu nome: ");
    scanf("%s", nome_do_hospede);

    printf("Digite o tipo do apartamento que gostaria de reservar (A, B, C ou D): ");
    scanf(" %c", &tipo_apartamento);


    switch (tipo_apartamento){
        case 'A':
            valor_diaria = 150;
            break;

        case 'B':
            valor_diaria = 100;
            break;

        case 'C':
            valor_diaria = 75;
            break;

        case 'D':
            valor_diaria = 50;
            break;

        default:
            printf("Tipo de apartamento invalido. Saindo do programa.\n");
            return 1;
    }


    printf("Digite o numero de diarias que voce deseja: ");
    scanf("%d", &quantidade_diarias);

    printf("Digite o valor de consumo que voce deseja: ");
    scanf("%f", &valor_consumo);

    total_diarias = quantidade_diarias * valor_diaria;
    taxa_10 = (valor_consumo + total_diarias) * 0.10;

    total_final = total_diarias + valor_consumo + taxa_10;

    printf("\nPrezado(a), %s.\n", nome_do_hospede);
    printf("Sua quantidade de diarias: %d\n", quantidade_diarias);
    printf("O valor total das diarias: %f\n", total_diarias);
    printf("O valor consumido: %f\n", valor_consumo);
    printf("Sua taxa fixa de 10 por cento ficou: %f\n", taxa_10);
    printf("Por fim, o valor da conta final ficou: %f\n", total_final);

    return 0;

}

