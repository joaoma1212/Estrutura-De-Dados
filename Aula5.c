#include <stdio.h>
#include <stdlib.h>

#define Tam 5

int vetorras[Tam];
int ini = -1;
int fin = -1;
int con = 0;

void enfileirar(int ra, int fila[]) {
    
    if (con == Tam) {
        printf("Fila cheia! Nenhum elemento adicionado!\n");
        return;
    }

    if (fin == -1) {
        ini = 0;
        fin = 0;
    } 
    else if (fin == Tam - 1) {
        fin = 0;
    } 
    else {
        fin++;
    }

    fila[fin] = ra;
    con++;

    printf("RA adicionado!\n");
}

void pesquisar(int ra, int fila[]) {

    if (con == 0) {
        printf("Fila vazia!\n");
        return;
    }

    int p = ini;

    for (int i = 0; i < con; i++) {

        if (fila[p] == ra) {
            printf("RA encontrado na posicao %d da fila.\n", i+1);
            return;
        }

        if (p == Tam - 1)
            p = 0;
        else
            p++;
    }

    printf("RA nao encontrado!\n");
}

void desenfileirar() {

    if (con == 0) {
        printf("Fila vazia! Nenhum RA removido!\n");
        return;
    }

    printf("RA %d removido!\n", vetorras[ini]);

    if (ini == Tam - 1)
        ini = 0;
    else
        ini++;

    con--;

    if (con == 0) {
        ini = -1;
        fin = -1;
    }
}

void exibir(int fila[]) {

    if (con == 0) {
        printf("Fila vazia!\n");
        return;
    }

    int p = ini;

    printf("\n--- FILA ---\n");

    for (int i = 0; i < con; i++) {

        printf("%d\n", fila[p]);

        if (p == Tam - 1)
            p = 0;
        else
            p++;
    }
}

void menu() {

    int opc = 0;
    int valra = 0;

    do {

        printf("\n====== FILA DE ALUNO ======\n");
        printf("1 - Adicionar\n");
        printf("2 - Remover\n");
        printf("3 - Exibir\n");
        printf("4 - Pesquisar RA\n");
        printf("9 - Sair\n");
        printf("Digite opcao: ");
        scanf("%d", &opc);

        if (opc == 1) {

            printf("Digite o RA: ");
            scanf("%d", &valra);
            enfileirar(valra, vetorras);

        } 
        else if (opc == 2) {

            desenfileirar();

        } 
        else if (opc == 3) {

            exibir(vetorras);

        }
        else if (opc == 4) {

            printf("Digite o RA para pesquisar: ");
            scanf("%d", &valra);
            pesquisar(valra, vetorras);

        }

    } while (opc != 9);
}

int main() {

    menu();

    return 0;
}
