#include <stdio.h>
#include <string.h>
#include "deque.h"

void printa_menu ();
void printa_deque (Deque d);

int main (void)
{
  Deque d = cria_deque();

  int op = 0;
  char string[MAX_CHAR_STR];

  do
  {
    printa_menu();
    scanf("%i", &op);

    switch (op)
    {
    case 1:
      printf("\n");
      printa_deque(d);
      printf("\n");
      break;
    
    case 2:
      printf("string: ");
      scanf("%s", string);
      if ( insere_fim(d, string) )
      {
        printf("\ninserida com sucesso\n\n");
        break;
      }
      else
      {
        printf("\nfalha ao inserir\n\n");
        break;
      }

    case 3:
      if (remove_ini(d, string))
      {
        printf("\nremovido com sucesso\n\n");
        break;
      }
      else
      {
        printf("\nfalha ao remover\n\n");
        break;
      }

    case 4:
      printf("\nadeus\n");
      break;
    default:
      printf("\nopcao invalida\n\n");
      break;
    }
  } while (op != 0);
}

void printa_menu ()
{
  printf("[1] imprimir fila\n");
  printf("[2] inserir string\n");
  printf("[3] remover string\n");
  printf("[0] sair\n");
  printf("escolha: ");
}

void printa_deque (Deque d)
{
  if(fila_vazia(f))
  {
    printf("\nlista vazia!\n");
  }

  Fila aux = cria_fila();

  char printar[MAX_CHAR_STR];

  while (!fila_vazia(f))
  {
    remove_ini(f,printar);
    insere_fim(aux,printar);
  }

  while (!fila_vazia(aux))
  {
    remove_ini(aux,printar);
    printf("%s\n",printar);
    insere_fim(f,printar);
  }
}
