#define TIPO_CHAR   0
#define TIPO_DOUBLE 1
typedef struct no * pilha_p;

pilha_p cria_pilha();
int pilha_vazia(pilha_p pilha);
int push(pilha_p *pilha_ref, void *ptr);  
int pop(pilha_p *pilha_ref, void *ptr);
int le_topo(pilha_p pilha, void *ptr);
int libera_pilha(pilha_p *pilha_ref);
int esvazia_pilha(pilha_p *pilha_ref);
