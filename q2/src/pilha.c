// TODO: adaptar para void
#include "pilha.h"
#ifndef STDLIB_INCLUIDA
#include <stdlib.h>
#define STDLIB_INCLUIDA
#endif

struct no {
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

int push(pilha_p *pilha_ref, void *info) {
  // geração de memória, falha se não tiver memório
  pilha_p inserindo = (pilha_p) malloc(sizeof(struct no));
  if (inserindo == NULL)
    return 0;

  (inserindo->info) = info;
  inserindo->prox = *pilha_ref; // aponta pro que a pilha aponta (inclusive vazio)
  *pilha_ref = inserindo; // pilha agora aponta pra ele (o novo topo)
  
  return 1; 
}

int pop(pilha_p *pilha_ref, void* *funcionario_ref) {
  if (pilha_vazia(*pilha_ref))
    return 0; // pilha vazia n desempilha
  // não é NULL então
  
  pilha_p salva_ref_prox = (*pilha_ref)->prox;
  *funcionario_ref = (*pilha_ref)->info; // info retornada implicitamente é o topo 

  free(*pilha_ref); // libera o no da memoria
  *pilha_ref = salva_ref_prox; // atribui ao antigo anterior ao topo (ou o vazio)

  return 1;
}

int le_topo(pilha_p pilha, void** ref) {
  if (pilha_vazia(pilha))
    return 0; // nao há o que olhar em pilha vazia

  *ref = pilha->info; // sabemos que não é NULL

  return 1;
}

int libera_pilha(pilha_p *pilha_ref) {
  if (pilha_vazia(*pilha_ref))
    return 0; // pilha vazia não libera

  void* foo;

  while (*pilha_ref != NULL)
    pop(pilha_ref, &foo); // remove topo até vazio
  
  return 1;
}

int esvazia_pilha(pilha_p *pilha_ref) {
  return libera_pilha(pilha_ref);
}