#include "fila.h"
#ifndef STDLIB_INCLUIDA
#define STDLIB_INCLUIDA
#include <stdlib.h>
#define MAX 10
#endif
#ifndef STRING_INCLUIDA
#define STRING_INCLUIDA
#endif

struct fila {
  int cont;
  int ini;
  carro_t conteudo[MAX];
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

int insere_fim(fila_p fila, carro_t inserir) {
  if (fila_cheia(fila) == 1)
    return 0;

  fila->conteudo[(fila->cont + fila->ini) % MAX] = inserir;
  fila->cont++;

  return 1;
}

int remove_ini(fila_p fila, carro_t *removido) {
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

int get_ini(fila_p fila, carro_t *ini_copia) {
  if (fila_vazia(fila))
    return 0; 

  // não é o caso lista vazia então
  *ini_copia = fila->conteudo[fila->ini];

  return 1;
}
