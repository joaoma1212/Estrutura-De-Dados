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
#include <stdbool.h>

#define TAM 10

struct Pastel {
    int numeroP;
    float tamanhoPa;
    int quantidade;
    bool pagamento;
};

struct Pastel pilha[TAM];
int topo = -1;

void Inicializar(struct Pastel vetor[]) {
    int i = 0;
    
    for (i = 0; i < TAM; i++) {
        vetor[i].numeroP = 0;
        vetor[i].tamanhoPa = 0;
        vetor[i].pagamento = false;
    }
}

void venda(int num, float tam, int qua, bool pag, struct Pastel vetor[]) {

}
