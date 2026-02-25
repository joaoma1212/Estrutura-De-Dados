#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 10

struct Livro {
  int codigo;
  char nome[10];
};

struct Livro pilha[TAM];
int topo = - 1;

void empilhar(int codigo, char nome[10], struc Livro vetor[]){
  if (topo == TAM - 1) {
    printf("Pilhar cheia! Livro nao foi adicionado!\n")
  }else {
    topo++;
    vetor[topo].codigo = cod;
    strcpy(vetor[topo].nome, nom);
  }
}

void desempilhar() {
  
}

void menu() {
    int opc = 0;

    do {
        printf("\n===== EMPILHAMENTO DE LIVROS =====\n");
        printf("1. empilhar\n");
        printf("2. desempilhar\n");
        printf("Digite a opcao: ");
        scanf("%i", &opc);

        switch (opc) {
            case 1:
                empilhar();
                break;
            case 2:
                desempilhar();
                break;
        }

    } while (opc != 9);


int main(int argc, char *argv[]) {
  return 0;
}
