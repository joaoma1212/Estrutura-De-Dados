#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 52

typedef struct {
    int numero;
    char naipe[10];
} Carta;

typedef struct {
    Carta dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

void empilhar(Pilha *p, Carta c) {
    if (!pilhaCheia(p)) {
        p->dados[++p->topo] = c;
    }
}

Carta desempilhar(Pilha *p) {
    Carta c;
    if (!pilhaVazia(p)) {
        c = p->dados[p->topo--];
    }
    return c;
}

void criarBaralho(Carta baralho[]) {
    char naipes[4][10] = {"Ouro", "Espada", "Copas", "Paus"};
    int k = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 13; j++) {
            baralho[k].numero = j;
            sprintf(baralho[k].naipe, "%s", naipes[i]);
            k++;
        }
    }
}

void embaralhar(Carta baralho[]) {
    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        int j = rand() % MAX;
        Carta temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

void sortearEmpilhar(Pilha *p) {
    Carta baralho[MAX];
    criarBaralho(baralho);
    embaralhar(baralho);
    for (int i = 0; i < MAX; i++) {
        empilhar(p, baralho[i]);
    }
}

void exibirCarta(Carta c) {
    char *nomes[] = {"", "As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valete", "Dama", "Rei"};
    printf("%s de %s\n", nomes[c.numero], c.naipe);
}

void comprarCarta(Pilha *p) {
    if (!pilhaVazia(p)) {
        Carta c = desempilhar(p);
        exibirCarta(c);
    } else {
        printf("Monte vazio\n");
    }
}

void exibirMonte(Pilha *p) {
    for (int i = p->topo; i >= 0; i--) {
        exibirCarta(p->dados[i]);
    }
}

int main() {
    Pilha p;
    int opcao;

    inicializar(&p);

    do {
        printf("\n1 - Sortear/Empilhar\n2 - Comprar/Desempilhar\n3 - Exibir Monte\n0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inicializar(&p);
                sortearEmpilhar(&p);
                printf("Cartas empilhadas\n");
                break;
            case 2:
                comprarCarta(&p);
                break;
            case 3:
                exibirMonte(&p);
                break;
        }
    } while (opcao != 0);

    return 0;
}
