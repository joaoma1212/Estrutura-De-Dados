/******************************************************************************
----------------
ATIVIDADE
----------------
- ATIVIDADE: Trabalho valendo nota;
- CONTEÚDO: Manipulação de vetores com tipos de dados estruturados;
- POSTAGEM CÓDIGO: Cada aluno deverá desenvolver a aplicação abaixo baseado nas seguintes premissas: 
  - a) Deverá haver um menu interativo; 
  - b) Deverá utilizar Tipos de Dados Estruturados para cada elemento do vetor; 
  - c) Deverão ser utilizada programação modular, ou seja, cada operação de manipulação deverá ser um método, inclusive o Menu Interativo.

----------------
CENÁRIO
----------------
A barraca gourmet PASTEL DELICIA está iniciando suas atividades próximo a faculdade, esta pastelaria vende apenas pasteis de carne e nenhum outro sabor a mais, sua única variação corresponde ao tamanho que se dividem em Pequeno (R$ 3.50), Médio (R$ 4.50) e Grande (R$ 5.50), para agilizar o atendimento cada pedido só poderá conter pasteis do mesmo tamanho, esta regra apesar de simples é fundamental para que a produção seja rápida e eficiente pois o tempo de intervalo na faculdade é curto.

Para gerenciar a venda dos pasteis foi solicitado o desenvolvimento de um sistema simples com operações básicas conforme descritas abaixo.

a) A primeira versão do sistema (versão beta) suporta apenas a venda de no máximo 10 pedidos sem pagamento, é importante lembrar que o sistema controla apenas os pedidos não pagos, os pedidos pagos saem do sistema liberando espaço para outro pedido.

b) Cada pedido registrado deverá conter as seguintes informaçôes: Número pedido; Tamanho; Quantidade.

c) O sistem deve ser interativo, ou seja, permitir que o seu operador venda, imprima, consulte, etc. 

d) Operações básicas do sistema:
    1. Venda (Localiza uma posição vazia e registra as informações: núm. pedido, tamanho, quantidade; Nota: É necessário fazer o controle de número de pedidos abertos, ou seja, não pode exceder 10).
    2. Impressão pedidos a pagar (exibe na tela todos os pedidos não pagos, com todas as informações, e valor total de cada pedido).
    3. Contar número vendas a pagar (exibe na tela o número de pedidos presentes na lista).
    4. Pagamento (localiza pelo número do pedido e remove da lista).
    
d1) Outras opções podem ser adicionadas conforme o aluno/programador preferir, mas as opções apresentadas aqui nesta relação devem obrigatoriamente existir.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

struct Pastel {
    int numeroP;
    float tamanhoPa;
    int quantidade;
    int ativo;
};

struct Pastel pedidos[TAM];

void inicializar() {
    for (int i = 0; i < TAM; i++) {
        pedidos[i].ativo = 0;
    }
}

void menu() {
    printf("\n====== PASTELARIA ======\n");
    printf("1 - Registrar Venda\n");
    printf("2 - Imprimir Pedidos a Pagar\n");
    printf("3 - Contar Pedidos Abertos\n");
    printf("4 - Pagar Pedido\n");
    printf("9 - Sair\n");
    printf("Escolha: ");
}

int contarPedidos() {
    int contador = 0;

    for (int i = 0; i < TAM; i++) {
        if (pedidos[i].ativo == 1) {
            contador++;
        }
    }

    return contador;
}

void venda() {

    if (contarPedidos() == TAM) {
        printf("Limite de 10 pedidos abertos atingido!\n");
        return;
    }

    int numero, quantidade;
    float tamanho;

    printf("Numero do Pedido: ");
    scanf("%d", &numero);

    printf("Tamanho (3.50 = Pequeno | 4.50 = Medio | 5.50 = Grande): ");
    scanf("%f", &tamanho);

    printf("Quantidade: ");
    scanf("%d", &quantidade);

    for (int i = 0; i < TAM; i++) {
        if (pedidos[i].ativo == 0) {

            pedidos[i].numeroP = numero;
            pedidos[i].tamanhoPa = tamanho;
            pedidos[i].quantidade = quantidade;
            pedidos[i].ativo = 1;

            printf("Pedido registrado com sucesso!\n");
            return;
        }
    }
}

void imprimir() {

    if (contarPedidos() == 0) {
        printf("Nao ha pedidos a pagar!\n");
        return;
    }

    for (int i = 0; i < TAM; i++) {

        if (pedidos[i].ativo == 1) {

            float total = pedidos[i].tamanhoPa * pedidos[i].quantidade;
            char tamanhoTexto[30];

            if (pedidos[i].tamanhoPa == 3.50)
                strcpy(tamanhoTexto, "Pequeno (R$ 3.50)");
            else if (pedidos[i].tamanhoPa == 4.50)
                strcpy(tamanhoTexto, "Medio (R$ 4.50)");
            else if (pedidos[i].tamanhoPa == 5.50)
                strcpy(tamanhoTexto, "Grande (R$ 5.50)");
            else
                strcpy(tamanhoTexto, "Tamanho invalido");

            printf("\nPedido N %d\n", pedidos[i].numeroP);
            printf("Quantidade: %d\n", pedidos[i].quantidade);
            printf("Tamanho: %s\n", tamanhoTexto);
            printf("Total: R$ %.2f\n", total);
        }
    }
}

void pagar() {

    if (contarPedidos() == 0) {
        printf("Nao ha pedidos para pagar!\n");
        return;
    }

    int numero;
    printf("Digite o numero do pedido a pagar: ");
    scanf("%d", &numero);

    for (int i = 0; i < TAM; i++) {

        if (pedidos[i].ativo == 1 && pedidos[i].numeroP == numero) {

            pedidos[i].ativo = 0;
            printf("Pedido N %d pago com sucesso!\n", numero);
            return;
        }
    }

    printf("Pedido nao encontrado!\n");
}

int main() {

    int opcao;

    inicializar();

    do {

        menu();
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                venda();
                break;

            case 2:
                imprimir();
                break;

            case 3:
                printf("Total de pedidos abertos: %d\n", contarPedidos());
                break;

            case 4:
                pagar();
                break;

            case 9:
                printf("Encerrando sistema...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 9);

    return 0;
}
