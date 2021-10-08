struct produtos
{
    int codigo;
    char descricao[100];
    float valor;
    int validade;
};

typedef struct produtos Produto;
typedef struct fila * Fila;


Fila cria_fila ();

int fila_vazia (Fila f);

int insere_asc (Fila f, Produto p);

int remove_asc (Fila f, Produto *p, int prioridade);

int apaga_fila (Fila *f);

int esvazia_fila (Fila f);
