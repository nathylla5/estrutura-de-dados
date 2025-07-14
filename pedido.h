typedef struct pedido {
    int id;
    char nomeDoCliente[50];
    char produto[50];
    char status[20]; // Ex: "Pendente", "Em Preparação", "Entregue"
    char observacao[100];
    float preco;
    int quantidade;
    struct pedido *proximo;
} Pedido;

void fazerPedido(); //para fazer (Grupo 1)
void adicionarPedido(); //para fazer (Grupo 1)
void atualizarStatusPedido(); //para fazer (Grupo 2)
////////
void verificarStatusPedido(); //para fazer (Grupo 2)
void cancelarPedido(); //para fazer (Grupo 2)
void visualizarFila(); //para fazer (Grupo 1)