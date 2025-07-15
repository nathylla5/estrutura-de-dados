#include <stdio.h>
#include <stdlib.h>
#include "funcionalidades.h"
#include "pedido.h"

void inicializar() {
    int opcao;
    do {
        printf("Bem-vindo ao IFome!\n");
        printf("-----------------------\n");
        printf("1 - Sou cliente\n");
        printf("2 - Sou atendente\n");
        printf("0 - Sair\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                menuCliente();
                break;
            case 2:
                menuAtendente();
                break;
            case 0:
                printf("\nSaindo do IFome... Até a próxima!\n\n\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n\n\n");
                break;
        }
    } while (opcao != 0);
}

void menuCliente() {
    int opcao;
    do {
        printf("\n------- MENU DO CLIENTE -------\n");
        printf("\n1. Fazer Pedido\n");
        printf("2. Visualizar cardápio\n");
        printf("3. Verificar status do pedido\n");
        printf("4. Cancelar pedido\n");
        printf("0. Voltar ao menu principal\n");
        printf("-------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                fazerPedido();
                break;
            case 2:
                menuCardapio();
                break;
            case 3:
                verificarStatusPedido();
                break;
            case 4:
               cancelarPedido();
              break;
            case 0:
                printf("\nVoltando ao menu principal...\n\n");
                return;
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);
}

void menuAtendente() {
    int opcao;
    do {
        printf("\n------ MENU DO ATENDENTE ------\n");
        printf("\n1. Ver Fila de Pedidos\n");
        printf("2. Atualizar Status do Pedido\n");
        printf("3. Cancelar pedido\n");
        printf("4. Visualizar pedidos cancelados\n");
        printf("0. Voltar ao menu principal\n");
        printf("-------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                visualizarFila();
                break;
            case 2:
                atualizarStatusPedido();
                break;
            case 3:
              cancelarPedido();
              break;
            case 4: 
              visualizarPedidosCancelados();
              break;
            case 0:
                printf("\nVoltando ao menu principal...\n\n");
                return;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                menuAtendente();
                break;
        }
    } while (opcao != 0);
}

void menuCardapio() {
    printf("\nCARDÁPIO\n");
    printf("\nIFMestre -> Um hamburguer gigante para quem domina o assunto\n");
    printf("IFBásico -> O classico, sempre saboroso e confiavel\n");
    printf("IFCalouro -> O menor do cardapio, mas com muito potencial\n");
    printf("IFTCC -> Demora, mas vale a pena! (hamburguer duplo e caprichado)\n");
    printf("IFCompleto -> O combo perfeito, com batata frita e refrigerante\n");
    printf("IFRecesso -> Leve e delicioso, perfeito para uma pausa\n");
    printf("IFMat -> Para os fortes! (hamburguer apimentado, inspirado na matematica)\n");
    printf("\n");

    int opcao;
    printf("\nDeseja fazer seu pedido?\n");
    printf("1. Sim\n");
    printf("2. Nao\n");
    printf("\nEscolha uma opcao ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            fazerPedido();
            break;
        case 2:
            printf("\nVoltando ao menu do cliente...\n\n");
            return;
        default:
            printf("\nOpcao invalida.\n\n");
            break;
    }
}