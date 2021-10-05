// TAD - deque estatico/sequencial de strings (desperdicio de posicao)

#include <stdlib.h>
#include <string.h>
#include "deque.h"

struct fila
{
  char no[MAX_ELEMS][MAX_CHAR_STR];
  int ini, fim; // fim aponta pro primeiro espaco disponivel
};

Fila cria_fila ()
{
  Fila f = (Fila) malloc( sizeof(struct fila) );
  if ( f != NULL)
  {
    f->ini = 0;
    f->fim = 0;
  }
  return f;
}

int fila_vazia(Fila f)
{
  return (f->ini == f->fim);
}

int fila_cheia(Fila f)
{
  return ( f->ini == ( (f->fim+1) % MAX_ELEMS ) );
}

int insere_fim(Fila f, char *elem)
{
  if (fila_cheia(f))
  {
    return 0;
  }
  
  strcpy( f->no[f->fim], elem ); // insere no final
  f->fim = (f->fim+1) % MAX_ELEMS; // incremento circular
  return 1;
}

int remove_ini(Fila f, char *elem)
{
  if (fila_vazia(f))
  {
    return 0;
  }

  strcpy( elem, f->no[f->ini]); // retorno impl
  f->ini = (f->ini+1) % MAX_ELEMS; // incremento circular
  return 1;
}
