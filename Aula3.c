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
