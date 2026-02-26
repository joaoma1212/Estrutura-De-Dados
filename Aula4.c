#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

struct Livro {
    int codigo;
    char nome[50];  // Aumentado para evitar problemas
};

struct Livro pilha[TAM];
int topo = -1;

void empilhar(int cod, char nom[], struct Livro vetor[]) {
    if (topo == TAM - 1) {
        printf("Pilha cheia! Livro nao foi adicionado!\n");
    } else {
        topo++;
        vetor[topo].codigo = cod;
        strcpy(vetor[topo].nome, nom);
        printf("Livro empilhado com sucesso!\n");
    }
}

void desempilhar() {
    if (topo == -1) {
        printf("Pilha vazia!\n");
    } else {
        printf("Livro removido: %s\n", pilha[topo].nome);
        topo--;
    }
}

void imprimir(struct Livro vetor[]) {
    if (topo == -1) {
        printf("Pilha vazia!\n");
    } else {
        for (int i = topo; i >= 0; i--) {
            printf("[%d] - Codigo: %d - Nome: %s\n",
                   i, vetor[i].codigo, vetor[i].nome);
        }
    }
}

void imprimirTopo(struct Livro vetor[]) {
    if (topo == -1) {
        printf("Pilha vazia!\n");
    } else {
        printf("Topo -> Codigo: %d - Nome: %s\n",
               vetor[topo].codigo, vetor[topo].nome);
    }
}

void menu() {
    int opc = 0;
    int c;
    char n[50];

    do {
        printf("\n===== EMPILHAMENTO DE LIVROS =====\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Imprimir pilha\n");
        printf("4 - Imprimir topo\n");
        printf("9 - Sair\n");
        printf("Digite a opcao: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                printf("Digite o codigo do livro: ");
                scanf("%d", &c);
                printf("Digite o nome do livro: ");
                scanf("%s", n);
                empilhar(c, n, pilha);
                break;

            case 2:
                desempilhar();
                break;

            case 3:
                imprimir(pilha);
                break;

            case 4:
                imprimirTopo(pilha);
                break;

            case 9:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opc != 9);
}

int main() {
    menu();
    return 0;
}
