/******************************************************************************
EX2. Escreva uma aplicação de console, que ao ser executada, seja capaz 
armazenar ATE (e não mais que) 10 números de Registros Acadêmicos (RA's). Toda a 
manipulação dos RA's deverá ser realizada através de um MENU.
*******************************************************************************/

#include <stdio.h>

#define TAMANHO 10
#define VAZIO 0

int vetorRas[TAMANHO] = {VAZIO};

void carregar(int vetor[]) {
    int i = 0;

    for (i = 0; i < TAMANHO; i++) {
        scanf("%i", &vetor[i]);
    }
}

void exibirRas(int vetor[]) {
    int i = 0;

    for (i = 0; i < TAMANHO; i++) {
        printf("%i ", vetor[i]);
    }
    printf("\n");
}

void removerRa(int vetor[], int ra) {
    int i = 0;

    for (i = 0; i < TAMANHO; i++) {
        if (vetor[i] == ra) {
            vetor[i] = VAZIO;
        }
    }
}

int contarRa(int vetor[]) {
    int i = 0, contar = 0;

    for (i = 0; i < TAMANHO; i++) {
        if (vetor[i] != VAZIO) {
            contar++;
        }
    }
    return contar;
}

int maiorRa(int vetor[]) {
    int i = 0;
    int maior = -1;

    for (i = 0; i < TAMANHO; i++) {
        if (vetor[i] != VAZIO) {
            if (maior == -1 || vetor[i] > maior) {
                maior = vetor[i];
            }
        }
    }

    return maior;
}

void menu() {
    int opc = 0;
    int numero = 0;

    do {
        printf("\n===== SYSTEMRAS =====\n");
        printf("1. Carregar\n");
        printf("2. Exibir\n");
        printf("3. Remover\n");
        printf("4. Contar\n");
        printf("5. Maior\n");
        printf("9. Sair\n");
        printf("Escolha: ");
        scanf("%i", &opc);

        switch (opc) {
            case 1:
                carregar(vetorRas);
                break;

            case 2:
                exibirRas(vetorRas);
                break;

            case 3:
                printf("Digite o RA para remover: ");
                scanf("%i", &numero);
                removerRa(vetorRas, numero);
                break;

            case 4:
                numero = contarRa(vetorRas);
                printf("Existe(m) %i RA(s) cadastrados!\n", numero);
                break;

            case 5:
                numero = maiorRa(vetorRas);
                if (numero == -1) {
                    printf("Nenhum RA cadastrado!\n");
                } else {
                    printf("O maior RA e: %i\n", numero);
                }
                break;
        }

    } while (opc != 9);
}

int main() {
    menu();
    return 0;
}

/******************************************************************************
EXEMPLO STRUCT
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define TAM 5

struct Aluno {
    int ra;
    float nota1;
    float nota2;
    float media;
};

struct Aluno vetorAluno[TAM];

void inicializar(struct Aluno vetor[]) {
    int i = 0;

    for (i = 0; i < TAM; i++) {
        vetor[i].ra = 0;
        vetor[i].nota1 = 0;
        vetor[i].nota2 = 0;
        vetor[i].media = 0;
    }
}

void carregar(struct Aluno vetor[]) {
    int i = 0;

    for (i = 0; i < TAM; i++) {
        printf("\nDigite o RA, nota1 e nota2 do aluno %i:\n", i + 1);

        scanf("%i", &vetor[i].ra);
        scanf("%f", &vetor[i].nota1);
        scanf("%f", &vetor[i].nota2);

        vetor[i].media = (vetor[i].nota1 + vetor[i].nota2) / 2.0;
    }
}

void exibir(struct Aluno vetor[]) {
    int i = 0;

    printf("\n===== LISTA DE ALUNOS =====\n");

    for (i = 0; i < TAM; i++) {
        printf("\nAluno %i\n", i + 1);
        printf("RA: %i\n", vetor[i].ra);
        printf("Nota 1: %.2f\n", vetor[i].nota1);
        printf("Nota 2: %.2f\n", vetor[i].nota2);
        printf("Media: %.2f\n", vetor[i].media);
    }
}

void menu() {
    int opc = 0;

    do {
        printf("\n===== ALUNOS =====\n");
        printf("1. Inicializar\n");
        printf("2. Carregar\n");
        printf("3. Exibir\n");
        printf("9. Sair\n");
        printf("Escolha: ");
        scanf("%i", &opc);

        switch (opc) {
            case 1:
                inicializar(vetorAluno);
                printf("Vetor inicializado!\n");
                break;

            case 2:
                carregar(vetorAluno);
                printf("Dados carregados!\n");
                break;

            case 3:
                exibir(vetorAluno);
                break;

            case 9:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }

    } while (opc != 9);
}

int main() {
    inicializar(vetorAluno);
    menu();
    return 0;
}

