#define MAX_ELEM 15

typedef struct pilha * Pilha;

Pilha cria_pilha ();
int pilha_vazia (Pilha);
int pilha_cheia (Pilha);
int push (Pilha, int);
int pop (Pilha, int *);
int get_topo(Pilha, int *);
int libera_pilha(Pilha);
int esvazia_pilha(Pilha);
int tamanho(Pilha);
