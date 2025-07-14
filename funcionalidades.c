#include <stdio.h>
#include <stdlib.h>
#include "funcionalidades.h"
#include "pedido.h"

void inicializar() {
    int opcao;
    do {
        printf("Bem-vindo ao IFome!\n");
        printf("\n1 - Sou cliente\n");
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
                printf("\nSaindo do IFome... Até a próxima!\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n\n");
                break;
        }
    } while (opcao != 0);
}

void menuCliente() {
    int opcao;
    do {
        printf("\n------- MENU DO CLIENTE -------\n");
        printf("1. Fazer Pedido\n");
        printf("2. Visualizar cardápio\n");
        printf("3. Verificar status do pedido\n");
        printf("0. Voltar ao menu principal\n");
        printf("-------------------------------\n");
        printf("Escolha uma opção: ");
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
            case 0:
                printf("\nVoltando ao menu principal...\n\n");
                inicializar();
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);
}

void menuAtendente() {
    int opcao;
    do {
        printf("\n------ MENU DO ATENDENTE ------\n");
        printf("1. Ver Fila de Pedidos\n");
        printf("2. Atualizar Status do Pedido\n");
        printf("0. Voltar ao menu principal\n");
        printf("-------------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                visualizarFila();
                break;
            case 2:
                atualizarStatusPedido();
                break;
            case 0:
                printf("\nVoltando ao menu principal...\n\n");
                inicializar();
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
                menuAtendente();
                break;
        }
    } while (opcao != 0);
}

void menuCardapio() {
    printf("\nCARDÁPIO\n");
    printf("\nIFMestre -> Um hambúrguer gigante para quem domina o assunto\n");
    printf("IFBásico -> O clássico, sempre saboroso e confiável\n");
    printf("IFCalouro -> O menor do cardápio, mas com muito potencial\n");
    printf("IFTCC -> Demora, mas vale a pena! (hambúrguer duplo e caprichado)\n");
    printf("IFCompleto -> O combo perfeito, com batata frita e refrigerante\n");
    printf("IFRecesso -> Leve e delicioso, perfeito para uma pausa\n");
    printf("IFMat -> Para os fortes! (hambúrguer apimentado, inspirado na matemática)\n");
    printf("\n");

    int opcao;
    printf("\nDeseja fazer seu pedido?\n");
    printf("1. Sim\n");
    printf("2. Não\n");
    printf("\nEscolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            fazerPedido();
            break;
        case 2:
            printf("\nVoltando ao menu do cliente...\n\n");
            menuCliente();
            break;
        default:
            printf("\nOpção inválida.\n\n");
            break;
    }
}