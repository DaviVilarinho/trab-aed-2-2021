// TAD - deque estatico/sequencial de strings (desperdicio de posicao)

#include <stdlib.h>
#include <string.h>
#include "deque.h"

struct deque
{
  char no[MAX_ELEMS][MAX_CHAR_STR];
  int ini, fim; // fim aponta pro primeiro espaco disponivel
};

Deque cria_deque ()
{
  Deque d = (Deque) malloc( sizeof(struct deque) );
  if ( d != NULL)
  {
    d->ini = 0;
    d->fim = 0;
  }
  return d;
}

int deque_vazio(Deque d)
{
  return (d->ini == d->fim);
}

int deque_cheio(Deque d)
{
  return ( d->ini == ( (d->fim+1) % MAX_ELEMS ) );
}

// inserir inicio provoca decrementar inicio
int insere_ini(Deque d, char *elem)
{
  if (deque_cheio(d)) // deque cheio nao se insere
    return 0;

  // decremento circular
  if (d->ini == 0)
    d->ini = MAX_ELEMS - 1;
  else
    d->ini -= 1;

  strcpy(d->no[d->ini], elem); 

  return 1;
}

int insere_fim(Deque d, char *elem)
{
  if (deque_cheio(d))
  {
    return 0;
  }
  
  strcpy( d->no[d->fim], elem ); // insere no final
  d->fim = (d->fim+1) % MAX_ELEMS; // incremento circular
  return 1;
}

int remove_ini(Deque d, char *elem)
{
  if (deque_vazio(d))
  {
    return 0;
  }

  strcpy( elem, d->no[d->ini]); // retorno impl
  d->ini = (d->ini+1) % MAX_ELEMS; // incremento circular
  return 1;
}

// remover no final é decrementar o fim
int remove_fim(Deque d, char *elem)
{

}
