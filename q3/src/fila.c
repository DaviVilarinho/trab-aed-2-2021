#include "fila.h"
#define MAX 16
#define MAX_TAM_STRING 16
#ifndef STDLIB_INCLUIDA
#define STDLIB_INCLUIDA
#include <stdlib.h>
#endif
#ifndef STRING_INCLUIDA
#define STRING_INCLUIDA
#endif

struct fila {
  int cont;
  int ini;
  aluno_t conteudo[MAX];
};

fila_p cria_fila() {
  fila_p nova_fila = (fila_p) malloc(sizeof(struct fila));

  if (nova_fila != NULL) {
    nova_fila->cont = 0;
    nova_fila->ini = 0;
  }

  return nova_fila;
}

int tamanho(fila_p fila) {
  return fila->cont;
}

int fila_vazia(fila_p fila){
  if (fila->cont == 0)
    return 1;
  else
    return 0;
}

int fila_cheia(fila_p fila) {
  if (fila->cont == MAX) 
    return 1;
  else
    return 0;
}

int insere_fim(fila_p fila, aluno_t inserir) {
  if (fila_cheia(fila) == 1)
    return 0;

  fila->conteudo[(fila->cont + fila->ini) % MAX] = inserir;
  fila->cont++;

  return 1;
}

int remove_ini(fila_p fila, aluno_t *removido) {
  if (fila_vazia(fila))
    return 0;

  *removido = fila->conteudo[fila->ini];
  fila->ini = (fila->ini+1) % MAX;
  fila->cont--;

  return 1;
}

int libera_fila(fila_p *fila) {
  free(*fila);
  *fila = NULL;

  return 1; 
}
