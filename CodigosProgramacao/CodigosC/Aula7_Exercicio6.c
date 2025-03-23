#include <stdio.h>
#include <stdlib.h>

int main()
{
    char entrada_jogadorA;
    char entrada_jogadorB;
    int numero_rodadas;
    int i;
    int pontuacao_jogadorA = 0;
    int pontuacao_jogadorB = 0;

    printf("Digite o numero de rodadas que desejam jogar: ");
    scanf("%d", &numero_rodadas);

    for (i = 1; i <= numero_rodadas; i++){

        printf("\nJogador A, digite C para colaborar ou T para trair: ");
        scanf(" %c", &entrada_jogadorA);

        while ( (entrada_jogadorA != 'C') && (entrada_jogadorA != 'T') ){
            printf("\nResposta inválida do Jogador A, digite C para colaborar ou T para trair: ");
            scanf(" %c", &entrada_jogadorA);}


        printf("Jogador B, digite C para colaborar ou T para trair: ");
        scanf(" %c", &entrada_jogadorB);

        while ( (entrada_jogadorB != 'C') && (entrada_jogadorB != 'T') ){
            printf("\nResposta inválida do Jogador B, digite C para colaborar ou T para trair: ");
            scanf(" %c", &entrada_jogadorB);}



        if ( (entrada_jogadorA == 'C') && (entrada_jogadorB == 'C') ){
            pontuacao_jogadorA += 3;
            pontuacao_jogadorB += 3;}

        if ( (entrada_jogadorA == 'C') && (entrada_jogadorB == 'T') ){
            pontuacao_jogadorA += 0;
            pontuacao_jogadorB += 5;}

        if ( (entrada_jogadorA == 'T') && (entrada_jogadorB == 'C') ){
            pontuacao_jogadorA += 5;
            pontuacao_jogadorB += 0;}

        if ( (entrada_jogadorA == 'T') && (entrada_jogadorB == 'T') ){
            pontuacao_jogadorA += 1;
            pontuacao_jogadorB += 1;}
    }

    printf("\nPontuacao do jogador A: %d", pontuacao_jogadorA);
    printf("\nPontuacao do jogador B: %d", pontuacao_jogadorB);


    if (pontuacao_jogadorA > pontuacao_jogadorB)
        printf("\n\nJogador A  ganhou!");

    if (pontuacao_jogadorB > pontuacao_jogadorA)
        printf("\n\nJogador B ganhou!");

    else
        printf("\n\nOs jogadores A e B empataram!");
}
