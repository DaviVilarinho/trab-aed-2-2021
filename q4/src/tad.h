struct produtos
{
    int codigo;
    char descricao[100];
    float valor;
    int validade;
};

struct fila
{
    struct no *ini, *fim;
};

typedef struct produtos Produto;
typedef struct fila * Fila;

struct no
{
    Produto info;
    struct no *prox;
    int contador;
};

Fila cria_fila ();

int fila_vazia (Fila);

int insere_asc (Fila, Produto);

int remove_asc (Fila, Produto *, int);

int apaga_fila (Fila);

int esvazia_fila (Fila);
