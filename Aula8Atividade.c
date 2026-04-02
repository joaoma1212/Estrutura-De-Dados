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

void adicionarFinal() {
    if (cheia()) {
        printf("Lista cheia!\n");
        return;
    }

    int pv = obterPosicaoVazia();

    printf("Codigo: ");
    scanf("%d", &lista[pv].codigo);

    printf("Placa: ");
    scanf("%s", lista[pv].placa);

    printf("Valor: ");
    scanf("%f", &lista[pv].valor);

    lista[pv].proximo = -1;

    if (vazia()) {
        lista[pv].anterior = -1;
        inicio = pv;
        final = pv;
    } else {
        lista[pv].anterior = final;
        lista[final].proximo = pv;
        final = pv;
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

void exibirFinalInicio() {
    if (vazia()) {
        printf("Lista vazia\n");
        return;
    }

    int aux = final;

    while (aux != -1) {
        printf("Codigo: %d | Placa: %s | Valor: %.2f\n",
               lista[aux].codigo,
               lista[aux].placa,
               lista[aux].valor);
        aux = lista[aux].anterior;
    }
}

void removerInicio() {
    if (vazia()) {
        printf("Lista vazia!\n");
        return;
    }

    int aux = inicio;

    if (inicio == final) {
        inicio = -1;
        final = -1;
    } else {
        inicio = lista[inicio].proximo;
        lista[inicio].anterior = -1;
    }

    quantidade--;

    lista[aux].codigo = -1;
    strcpy(lista[aux].placa, "NULL");
    lista[aux].valor = 0.00;
    lista[aux].anterior = -1;
    lista[aux].proximo = -1;
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

    lista[aux].codigo = -1;
    strcpy(lista[aux].placa, "NULL");
    lista[aux].valor = 0.00;
    lista[aux].anterior = -1;
    lista[aux].proximo = -1;
}

int obterPosicaoCodigo(int cod) {
    if (vazia()) {
        return -1;
    }
    int aux = inicio;
    while (aux != -1) {
        if (lista[aux].codigo == cod) {
            return aux;
        }
        aux = lista[aux].proximo;
    }
    return -1;
}

void adicionarApos() {
    if (vazia()) {
        printf("Lista vazia!\n");
        return;
    }

    int cod;
    printf("Digite o codigo apos o qual deseja adicionar: ");
    scanf("%d", &cod);

    int pc = obterPosicaoCodigo(cod);

    if (pc == -1) {
        printf("Codigo %d nao localizado para adicionar apos!\n", cod);
        return;
    }

    if (cheia()) {
        printf("Lista cheia!\n");
        return;
    }

    if (pc == final) {
        adicionarFinal();
        return;
    }

    int pv = obterPosicaoVazia();

    printf("Codigo: ");
    scanf("%d", &lista[pv].codigo);

    printf("Placa: ");
    scanf("%s", lista[pv].placa);

    printf("Valor: ");
    scanf("%f", &lista[pv].valor);

    lista[pv].anterior = pc;
    lista[pv].proximo = lista[pc].proximo;

    lista[lista[pc].proximo].anterior = pv;
    lista[pc].proximo = pv;

    quantidade++;
}

void menu() {
    int opc = 0;
    int c, p = 0;

    iniciarLista();

    do {
        printf("\n LISTA CARROS\n");
        printf("1. Adicionar no inicio\n");
        printf("2. Adicionar no final\n");
        printf("3. Adicionar apos\n");
        printf("4. Remover do inicio\n");
        printf("5. Remover do final\n");
        printf("6. Exibir do inicio para o final\n");
        printf("7. Exibir do final para o inicio\n");
        printf("8. Pesquisar codigo\n");
        printf("9. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opc);

        if (opc == 1) {
            adicionarInicio();
        } else if (opc == 2) {
            adicionarFinal();
        } else if (opc == 3) {
            adicionarApos();
        } else if (opc == 4) {
            removerInicio();
        } else if (opc == 5) {
            removerFinal();
        } else if (opc == 6) {
            exibirInicioFinal();
        } else if (opc == 7) {
            exibirFinalInicio();
        } else if (opc == 8) {
            if (vazia()) {
                printf("Lista vazia!\n");
            } else {
                printf("Digite o codigo: ");
                scanf("%d", &c);
                p = obterPosicaoCodigo(c);
                if (p == -1) {
                    printf("Codigo %d nao existe na lista!\n", c);
                } else {
                    printf("Pos: %d | Codigo: %d | Placa: %s | Valor: %.2f\n",
                           p,
                           lista[p].codigo,
                           lista[p].placa,
                           lista[p].valor);
                }
            }
        }

    } while (opc != 9);
}

int main() {
    menu();
    return 0;
}
