typedef struct pedido {
    int id;
    char nomeDoCliente[50];
    char produto[50];
    char status[20]; // Ex: "Pendente", "Em Preparação", "Entregue"
    char descricao[100];
    float preco;
    int quantidade;
    struct pedido *proximo;
} Pedido;

void fazerPedido();
void adicionarPedido();
void removerPedido();
void atualizarStatusPedido();
void verificarStatusPedido();
void visualizarFila();