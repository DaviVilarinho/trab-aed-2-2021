typedef struct validade Validade;

struct validade {
    int dia;
    int mes;
    int ano;
};

struct produtos
{
    int codigo;
    char descricao[100];
    float valor;
    Validade v;
};

typedef struct produtos Produto;
typedef struct fila * Fila;


Fila cria_fila ();

int fila_vazia (Fila f);

int insere_ord (Fila f, Produto p);

int remove_ini (Fila f, Produto *p);

int apaga_fila (Fila *f);

int esvazia_fila (Fila f);
