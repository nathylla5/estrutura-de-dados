#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedido.h"

Fila filaPedidos = {NULL, NULL};
Pilha pilhaCancelados = {NULL};

typedef struct {
    char nome[50];
    float preco;
} ItemCardapio;

ItemCardapio cardapio[] = {
    {"IFMestre", 20.00},
    {"IFBasico", 15.00},
    {"IFCalouro", 14.00},
    {"IFTCC", 25.90},
    {"IFCompleto", 30.00},
    {"IFRecesso", 16.00},
    {"IFMat", 22.00}
};
int tamanhoCardapio = sizeof(cardapio) / sizeof(cardapio[0]);

float buscarPreco(char nomeProduto[]) {
    for (int i = 0; i < tamanhoCardapio; i++) {
        if (strcmp(cardapio[i].nome, nomeProduto) == 0) {
            return cardapio[i].preco;
        }
    }
    return -1;
}

int gerarID() {
    return rand() % 900 + 100;
}

void fazerPedido() {
    printf("\n---- FAZER PEDIDO ----\n");
    adicionarPedido();
}
 
void adicionarPedido() {
    Pedido *novo = (Pedido *)malloc(sizeof(Pedido));
    if (novo == NULL) {
        printf("Erro!\n");
        return;
    }

    novo->id = gerarID();

    printf("Nome do cliente: ");
    scanf(" %[^\n]", novo->nomeDoCliente);

    printf("\n--- CARDAPIO ---\n");
    for (int i = 0; i < tamanhoCardapio; i++) {
        printf("%s - R$ %.2f\n", cardapio[i].nome, cardapio[i].preco);
    }
    printf("----------------\n");

    printf("Produto: ");
    scanf(" %[^\n]", novo->produto);

    float unidade = buscarPreco(novo->produto);
    if (unidade < 0) {
        printf("Produto nao encontrado.\n");
        free(novo);
        return;
    }

    printf("Quantidade: ");
    scanf("%d", &novo->quantidade);

    printf("Observacoes: ");
    scanf(" %[^\n]", novo->observacao);

    float valorTotal = unidade * novo->quantidade;
    novo->valorTotal = valorTotal;
   
    printf("Total: R$ %.2f\n", valorTotal);

    int confirmar;
    printf("Deseja confirmar o pedido? (1 - Sim / 2 - Nao): ");
    scanf("%d", &confirmar);

    if (confirmar != 1) {
        free(novo);
        printf("Pedido cancelado.\n");
        return;
    }

    strcpy(novo->status, "Pendente");
    novo->proximo = NULL;

    if (filaPedidos.inicio == NULL) {
        filaPedidos.inicio = filaPedidos.fim = novo;
    } else {
        filaPedidos.fim->proximo = novo;
        filaPedidos.fim = novo;
    }

    printf("\nPedido adicionado com sucesso! ID: %d\n", novo->id);
}

void visualizarFila() {
    if (filaPedidos.inicio == NULL) {
        printf("\nFila de pedidos vazia!\n");
        return;
    }
    printf("\n---- FILA DE PEDIDOS ----\n");

    Pedido *temp = filaPedidos.inicio;
    while (temp != NULL) {
        printf("ID: %d | Cliente: %s | Produto: %s | Qtde: %d | Status: %s | Valor da compra: R$ %.2f\n",
            temp->id, temp->nomeDoCliente, temp->produto, temp->quantidade, temp->status, temp->valorTotal);
    printf("Observacoes: %s\n", temp->observacao);
    printf("-------------------------\n");
    temp = temp->proximo;
}

}

void cancelarPedido() {
    if (filaPedidos.inicio == NULL) {
        printf("\nNao ha pedidos ativos para cancelar.\n");
        return;
    }

    int idBusca;
    printf("Digite o ID do pedido que deseja cancelar: ");
    scanf("%d", &idBusca);

    Pedido *atual = filaPedidos.inicio;
    Pedido *anterior = NULL;

    while (atual != NULL && atual->id != idBusca) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("\nPedido com ID #%d nao encontrado.\n", idBusca);
        return;
    }

    if (anterior == NULL) {
        filaPedidos.inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }
    if (filaPedidos.fim == atual) {
        filaPedidos.fim = anterior;
    }

    printf("\nPedido #%d cancelado com sucesso!", atual->id);

    atual->proximo = pilhaCancelados.topo;
    pilhaCancelados.topo = atual;
    strcpy(atual->status, "Cancelado");
}

void visualizarPedidosCancelados() {
    printf("\n--- Historico de Pedidos Cancelados ---\n");
    if (pilhaCancelados.topo == NULL) {
        printf("Nenhum pedido foi cancelado.\n");
        return;
    }

    Pedido *atual = pilhaCancelados.topo;
    while (atual != NULL) {
        printf("ID: %d | Cliente: %s | Produto: %s | Valor: %s\n",
               atual->id, atual->nomeDoCliente, atual->produto, atual->valorTotal);
        atual = atual->proximo;
    }
    printf("---------------------------------------\n");
}

void atualizarStatusPedido() {
    if (filaPedidos.inicio == NULL) {
        printf("\nNao ha pedidos ativos para atualizar.\n");
        return;
    }

    int idBusca;
    printf("Digite o ID do pedido que deseja atualizar: ");
    scanf("%d", &idBusca);

    Pedido *atual = filaPedidos.inicio;
    while (atual != NULL) {
        if (atual->id == idBusca) {
            char novoStatus[20];
            printf("Mude o status para o Pedido #%d para 'em preparacao': ", atual->id);
            scanf(" %s", novoStatus);
            strcpy(atual->status, novoStatus);
            printf("\nStatus do Pedido #%d atualizado para '%s' com sucesso!\n", atual->id, novoStatus);
            return;
        }
        atual = atual->proximo;
    }

    printf("\nPedido com ID #%d nao encontrado.\n", idBusca);
}

void verificarStatusPedido() {
  if (filaPedidos.inicio == NULL) {
        printf("\nNão há pedidos ativos para verificar.\n");
        return;
    }

    int idBusca;
    printf("Digite o ID do pedido que deseja verificar: ");
    scanf("%d", &idBusca);

    Pedido *atual = filaPedidos.inicio;
    while (atual != NULL) {
        if (atual->id == idBusca) {
            printf("\nStatus do Pedido #%d: %s\n", atual->id, atual->status);
            return;
        }
        atual = atual->proximo;
    }

    printf("\nPedido com ID #%d nao encontrado na fila de ativos.\n", idBusca);
}
