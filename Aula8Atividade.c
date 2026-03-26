#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

struct Carro {
    int codigo;
    char placa[10];
    float valor;

    int proximo;
    int anterior;
};

struct Carro lista[TAM];
int inicio = -1;
int final = -1;
int quantidade = 0;

void iniciarLista() {
    for (int i = 0; i < TAM; i++) {
        lista[i].codigo = -1;
        strcpy(lista[i].placa, "NULL");
        lista[i].valor = 0.00;
        lista[i].proximo = -1;
        lista[i].anterior = -1;
    }
}

int vazia() {
    return (quantidade == 0);
}

int cheia() {
    return (quantidade == TAM);
}

int obterPosicaoVazia() {
    for (int i = 0; i < TAM; i++) {
        if (lista[i].codigo == -1) {
            return i;
        }
    }
    return -1;
}

void adicionarInicio() {
    if (cheia()) {
        printf("Lista cheia\n");
        return;
    }

    int pv = obterPosicaoVazia();

    printf("Codigo: ");
    scanf("%d", &lista[pv].codigo);

    printf("Placa: ");
    scanf("%s", lista[pv].placa);

    printf("Valor: ");
    scanf("%f", &lista[pv].valor);

    lista[pv].anterior = -1;
    lista[pv].proximo = inicio;

    if (vazia()) {
        inicio = pv;
        final = pv;
    } else {
        lista[inicio].anterior = pv;
        inicio = pv;
    }

    quantidade++;
}

void exibirInicioFinal() {
    if (vazia()) {
        printf("Lista vazia\n");
        return;
    }

    int aux = inicio;

    while (aux != -1) {
        printf("Codigo: %d | Placa: %s | Valor: %.2f\n",
               lista[aux].codigo,
               lista[aux].placa,
               lista[aux].valor);

        aux = lista[aux].proximo;
    }
}

void removerFinal() {
    int aux;

    if (vazia()) {
        printf("Lista vazia!\n");
        return;
    }

    aux = final;

    if (inicio == final) {
        inicio = -1;
        final = -1;
    } else {
        final = lista[final].anterior;
        lista[final].proximo = -1;
    }

    quantidade--;
    
    if (quantidade == 0) {
      inicio = -1;
      final = -1;
    }

    lista[aux].codigo = -1;
    strcpy(lista[aux].placa, "NULL");
    lista[aux].valor = 0.00;
    lista[aux].anterior = -1;
    lista[aux].proximo = -1;
}

void menu() {
    int opc = 0;

    iniciarLista();

    do {
        printf("\n LISTA CARROS\n");
        printf("1. Adicionar no inicio\n");
        printf("2. Adicionar no final\n");
        printf("3. Remover do inicio\n");
        printf("4. Remover do final\n");
        printf("5. Exibir do inicio para o final\n");
        printf("9. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opc);

        if (opc == 1) {
            adicionarInicio();

        } else if (opc == 2) {

        } else if (opc == 3) {

        } else if (opc == 4) {
            removerFinal();

        } else if (opc == 5) {
            exibirInicioFinal();
        }

    } while (opc != 9);
}

int main() {
    menu();
    return 0;
}
