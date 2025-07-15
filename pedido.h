typedef struct pedido {
    int id;
    char nomeDoCliente[50];
    char produto[50];
    char status[20]; // Ex: "Pendente", "Em Preparação", "Entregue"
    char observacao[100];
    float preco;
    int quantidade;
    struct pedido *proximo;
    float valorTotal;
} Pedido;

typedef struct {
    Pedido *inicio;
    Pedido *fim;
} Fila;

typedef struct {
    Pedido *topo;
} Pilha;


void fazerPedido();
void adicionarPedido();
void visualizarFila();
void atualizarStatusPedido();
void verificarStatusPedido();
void cancelarPedido();
void visualizarPedidosCancelados();
