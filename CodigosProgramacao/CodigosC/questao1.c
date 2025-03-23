/* MEMBROS DA EQUIPE:
   Ana Beatriz Maciel Nunes
   Fernando Luiz Da Silva Freire
   Lucas Carvalho Dos Santos
   Marcelo Heitor de Almeida Lira
   Marcio Alves Alho Junior
   Ryan Da Silva Marinho */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    int id;
    char nome[20];
    char sobrenome[20];
    int idade;
    float altura;
    float peso;
};

void cadastrarNovoRegistro(struct person *pessoas, int *num_pessoas) {
    printf("Digite o numero do id (digite 0 para sair): ");
    scanf("%d", &pessoas[*num_pessoas].id);

    if (pessoas[*num_pessoas].id != 0) {
        printf("Digite o nome: ");
        scanf("%s", pessoas[*num_pessoas].nome);
        printf("Digite o sobrenome: ");
        scanf("%s", pessoas[*num_pessoas].sobrenome);
        printf("Digite a idade: ");
        scanf("%d", &pessoas[*num_pessoas].idade);
        printf("Digite a altura: ");
        scanf("%f", &pessoas[*num_pessoas].altura);
        printf("Digite o peso: ");
        scanf("%f", &pessoas[*num_pessoas].peso);

        (*num_pessoas)++;
    }
}

void mostrarMenorPeso(struct person *pessoas, int num_pessoas) {
    if (num_pessoas == 0) {
        printf("Nenhum registro cadastrado.\n");
        return;
    }

    int indice_menor_peso = 0;
    for (int i = 1; i < num_pessoas; i++) {
        if (pessoas[i].peso < pessoas[indice_menor_peso].peso) {
            indice_menor_peso = i;
        }
    }

    printf("A pessoa com menor peso é: %s %s\n", pessoas[indice_menor_peso].nome, pessoas[indice_menor_peso].sobrenome);
}

void mostrarNomes(struct person *pessoas, int num_pessoas) {
    if (num_pessoas == 0) {
        printf("Nenhum registro cadastrado.\n");
        return;
    }

    printf("Registros:\n");
    for (int i = 0; i < num_pessoas; i++) {
        printf("%s %s\n", pessoas[i].nome, pessoas[i].sobrenome);
    }
}

void alterarIdade(struct person *pessoas, int num_pessoas) {
    if (num_pessoas == 0) {
        printf("Nenhum registro cadastrado.\n");
        return;
    }

    int idAlvo, novaIdade;

    printf("Digite o id da pessoa que deseja alterar a idade: ");
    scanf("%d", &idAlvo);

    for (int i = 0; i < num_pessoas; i++) {
        if (pessoas[i].id == idAlvo) {
            printf("Digite a nova idade: ");
            scanf("%d", &novaIdade);
            pessoas[i].idade = novaIdade;
            return;
        }
    }

    printf("Pessoa nao encontrada.\n");
}

void pessoaMaisJovem(struct person *pessoas, int num_pessoas) {
    if (num_pessoas == 0) {
        printf("Nenhum registro cadastrado.\n");
        return;
    }

    int indice_mais_jovem = 0;
    for (int i = 1; i < num_pessoas; i++) {
        if (pessoas[i].idade < pessoas[indice_mais_jovem].idade) {
            indice_mais_jovem = i;
        }
    }

    printf("A pessoa mais jovem é: %s %s\n", pessoas[indice_mais_jovem].nome, pessoas[indice_mais_jovem].sobrenome);
}

int main() {
    struct person pessoas[100];
    int num_pessoas = 0;
    int opcao;

    do {
        printf("\nMenu de Opcoes:\n");
        printf("1  Cadastrar um registro novo.\n");
        printf("2  Mostrar o nome da pessoa com menor peso.\n");
        printf("3  Mostrar nome e sobrenome de todas pessoas registradas.\n");
        printf("4  Alterar idade de uma determinada pessoa no registro.\n");
        printf("5  Nome da pessoa mais jovem.\n");
        printf("6  Sair do Programa\n");

        printf("Escolha uma opcao (1 a 6): ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarNovoRegistro(pessoas, &num_pessoas);
                break;
            case 2:
                mostrarMenorPeso(pessoas, num_pessoas);
                break;
            case 3:
                mostrarNomes(pessoas, num_pessoas);
                break;
            case 4:
                alterarIdade(pessoas, num_pessoas);
                break;
            case 5:
                pessoaMaisJovem(pessoas, num_pessoas);
                break;
            case 6:
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}
