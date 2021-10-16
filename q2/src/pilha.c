#include "pilha.h"
#ifndef STDLIB_INCLUIDA
#include <stdlib.h>
#define STDLIB_INCLUIDA
#endif

struct no {
  int tipo;
  void *info;
  pilha_p prox;
};

pilha_p cria_pilha() {
  return NULL;
}

int pilha_vazia(pilha_p pilha) {
  if (pilha == NULL) // definição de pilha vazia, endereço apontado ser NULL
    return 1;
  else
    return 0;
}

int push(pilha_p *pilha_ref, void *info, int tipo) {
  // geração de memória, falha se não tiver memório
  pilha_p inserindo = (pilha_p) malloc(sizeof(struct no));
  if (inserindo == NULL || (tipo != TIPO_CHAR && tipo != TIPO_DOUBLE))
    return 0; // se nao definir tipo tbm tem que dar erro

  inserindo->info = info;
  inserindo->tipo = tipo;

  inserindo->prox = *pilha_ref; // aponta pro que a pilha aponta (inclusive vazio)
  *pilha_ref = inserindo; // pilha agora aponta pra ele (o novo topo)
  
  return 1; 
}

int pop(pilha_p *pilha_ref, void **elem_ref, int tipo) {
  if (pilha_vazia(*pilha_ref))
    return 0; // pilha vazia n desempilha
  // não é NULL então
  
  pilha_p salva_ref_prox = (*pilha_ref)->prox;

  if (tipo == TIPO_CHAR)
    *elem_ref = (char *) (*pilha_ref)->info; // agora aponta pra um cast de ponteiro!
    
  else
    *elem_ref = (double *) (*pilha_ref)->info; 

  free(*pilha_ref); // libera o no da memoria
  *pilha_ref = salva_ref_prox; // atribui ao antigo anterior ao topo (ou o vazio)

  return 1;
}

int le_topo(pilha_p pilha, void **ref, int tipo) {
  if (pilha_vazia(pilha) || (tipo != TIPO_CHAR && tipo != TIPO_DOUBLE))
    return 0; // nao há o que olhar em pilha vazia


  // sabemos que não é NULL
  // sabemos o tipo
  if (tipo == TIPO_CHAR)
    *ref = (char *) pilha->info; 
  else
    *ref = (double *) pilha->info;

  return 1;
}

int libera_pilha(pilha_p *pilha_ref) {
  if (pilha_vazia(*pilha_ref))
    return 0; // pilha vazia não libera

  void *liberando;

  while (*pilha_ref != NULL) {
    // char é perigoso recastar
    pop(pilha_ref, &liberando, TIPO_DOUBLE); // remove topo até vazio
    free(liberando);
    liberando = NULL; // liberando malloc porque void era ptr
  }
  
  return 1;
}

// impl dinamica: sem diferenca entre libera e esvazia
int esvazia_pilha(pilha_p *pilha_ref) {
  return libera_pilha(pilha_ref);
}
