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

int fila_vazia (Fila);

int insere_asc (Fila, Produto);

int remove_asc (Fila, Produto *, int);

int apaga_fila (Fila);

int esvazia_fila (Fila);
