// TAD - pilha de `ints` estatica/sequencial


#include "pilha.h"
#include <stdlib.h>
#include <string.h>

struct pilha
{
  int no[MAX_ELEM];
  int topo; // ultima posicao ocupada - [insercao] primeiro avancar
};

Pilha cria_pilha ()
{
  // aloca
  Pilha p = (Pilha) malloc( sizeof(struct pilha) );

  // poe no estado de vazia
  if (p != NULL)
  {
    p->topo = -1;
  }

  return p;
}

int pilha_vazia (Pilha p)
{
  return (p->topo == -1);
}

int pilha_cheia (Pilha p)
{
  return (p->topo == MAX_ELEM-1); // vetor comeca em 0 entao subtraimos
}

int push (Pilha p, int elem)
{
  if (p == NULL || pilha_cheia(p))
  {
    return 0; // FALHA
  }

  // insere o elemento no topo
  p->topo++;
  p->no[p->topo] = elem; // pro topo oq esta em elem

  return 1; // SUCESSO
}

int pop (Pilha p, int *elem)
{
  if (p == NULL || pilha_vazia(p))
  {
    return 0; // FALHA
  }

  // copiamos o int para retorno implicito
  *elem =  p->no[p->topo];
  
  // removemos o elemento do topo
  p->topo--;

  return 1; // SUCESSO
}

int get_topo(Pilha p, int *elem)
{
  if (p == NULL || pilha_vazia(p))
  {
    return 0; // FALHA
  }

  // copiamos o int para retorno implicito
  *elem =  p->no[p->topo];

  return 1; // SUCESSO
}

int libera_pilha(Pilha p)
{
  if (pilha_vazia(p) || p == NULL)
  {
    return 0; // FALHA
  }

  p->topo = -1;
  free(p);

  return 1; // SUCESSO
}

int esvazia_pilha(Pilha p)
{
  if (pilha_vazia(p) || p == NULL)
  {
    return 0; // FALHA
  }

  // esvaziamos a pilha
  p->topo = -1;

  return 1; // SUCESSO
}

int tamanho(Pilha p)
{
  if (p == NULL || pilha_vazia(p))
  {
    return 0; // FALHA
  }

  int t = p->topo; // precisamos add pois vetor inicia no zero
  t++;

  return t;
}
