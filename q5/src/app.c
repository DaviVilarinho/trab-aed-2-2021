#include <stdio.h>
#include <string.h>
#include "deque.h"

void printa_menu ();
void printa_deque (Deque d);

int main (void)
{
  Deque d;

  int op = 0;
  int isCriado = 0;
  char string[MAX_CHAR_STR];

  do
  {
    printa_menu();
    scanf("%i", &op);

    switch (op)
    {
    // criar deque
    case 1:
      d = cria_deque();
      if (d != NULL) {
        isCriado = 1;
        printf("deque criado\n");
      } 
      else 
      {
        printf("deque nao foi criado...\n");
      }
      break;

    // printar deque
    case 2:
      if (isCriado) 
      {
        printf("\n");
        printa_deque(d);
        printf("\n");
      } 
      else 
      {
        printf("nao ha deque... nada a printar\n");
      }
      break;
    
    // insere ini
    case 3:
      if (isCriado) 
      {
        printf("string: ");
        scanf("%s", string);
        if ( insere_fim(d, string) )
        {
          printf("\ninserida com sucesso\n\n");
        }
        else
        {
          printf("\nfalha ao inserir\n\n");
        }
      } 
      else 
      {
          printf("nao e possivel inserir sem deque\n");
      }

      break;

    // insere fim
    case 4:
      if (isCriado)
      {
      }
      else
      {
        printf("nao e possivel inserir sem deque\n");
      }
      break;

    // remove inicio
    case 5: 
      if (isCriado) 
      {
        if (remove_ini(d, string))
        {
          printf("\nremovido com sucesso\n\n");
        }
        else
        {
          printf("\nfalha ao remover\n\n");
        }
      } 
      else 
      {
        printf("nao e possivel remover sem deque\n");
      }
      break;

    // remove fim
    case 6:
      if (isCriado)
      {
      }
      else
      {
        printf("nao e possivel remover sem deque\n");
      }
      break;

    // esvaziar
    case 7:
      if (isCriado)
      {
      }
      else
      {
        printf("nao e possivel esvaziar sem deque\n");
      }
      break;

    // apagar
    case 8:
      if (isCriado)
      {
      }
      else
      {
        printf("nao e possivel apagar sem deque\n");
      }
      break;

    case 0:
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
  printf("[1] criar deque\n");
  printf("[2] imprimir deque\n");
  printf("[3] inserir string inicio\n");
  printf("[4] inserir string fim\n");
  printf("[5] remover string inicio\n");
  printf("[6] remover string fim\n");
  printf("[7] esvaziar\n");
  printf("[8] apagar\n");
  printf("[0] sair\n");
  printf("escolha: ");
}

void printa_deque (Deque d)
{
  if(deque_vazio(d))
  {
    printf("\nlista vazia!\n");
  }

  Deque aux = cria_deque();

  char printar[MAX_CHAR_STR];

  while (!deque_vazio(d))
  {
    remove_ini(d,printar);
    insere_fim(aux,printar);
  }

  while (!deque_vazio(aux))
  {
    remove_ini(aux,printar);
    printf("%s\n",printar);
    insere_fim(d,printar);
  }
}
