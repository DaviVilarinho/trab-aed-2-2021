#ifndef TIME_INCLUIDA
#define TIME_INCLUIDA
#include <time.h>
#endif

struct carro {
  char placa[8];
  char tipo_servico;
  time_t hora;
};

typedef struct carro carro_t;

typedef struct fila * fila_p;

fila_p cria_fila();
int fila_vazia(fila_p fila);
int fila_cheia(fila_p fila);
int insere_fim(fila_p fila, carro_t inserir);
int remove_ini(fila_p fila, carro_t *removido);
int libera_fila(fila_p *fila);
int get_ini(fila_p fila, carro_t *ini_copia);
int tamanho(fila_p fila);
