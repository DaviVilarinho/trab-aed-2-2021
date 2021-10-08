// o filasParaCriar == 0 se deve ao fato de que apenas UMA fila pode ser criada!
#include "fila-prioridades.h"
#include <stdio.h>

void printa_menu ();
void printa_produto(Produto p);

int main (void)
{
  Fila f;

  int op = 0;
  int filasParaCriar = 1;
  Produto temp;

  do
  {
    printa_menu();
    scanf("%i", &op);
    setbuf(stdin, NULL);

    switch (op)
    {
    // criar fila
    case 1:
      if (filasParaCriar == 1)
        f = cria_fila();
      else 
      {
        break;
        printf("fila de prioridades nao foi criada...\n");
      }

      if (f != NULL) {
        filasParaCriar--;
        printf("fila de prioridades criada\n");
      } 
      else 
      {
        printf("fila de prioridades nao foi criada...\n");
      }
      break;

    // printar fila
    case 2:
      if (filasParaCriar == 0) 
      {
        printf("\n");
        // printa fila!
        printf("\n");
      } 
      else 
      {
        printf("nao ha fila disponivel... nada a printar\n");
      }
      break;
    
    // insere
    case 3:
      if (filasParaCriar == 0) 
      {
        printf("PRODUTO A INSERIR:\n");
        printf("\tCODIGO: ");
        scanf("%i", &temp.codigo); setbuf(stdin, NULL);

        printf("\tDESCRICAO: ");
        scanf("%[^\n]", temp.descricao); setbuf(stdin, NULL);

        printf("\tVALOR: ");
        scanf("%f", &temp.valor); setbuf(stdin, NULL);

        printf("\tVALIDADE: ");
        scanf("%i", &temp.validade); setbuf(stdin, NULL);

        // inserir struct temp
      } 
      else 
      {
          printf("nao e possivel inserir sem fila\n");
      }

      break;

    // remove
    case 4: 
      if (filasParaCriar == 0) 
      {
        // remove faz algo
      } 
      else 
      {
        printf("nao e possivel remover sem fila\n");
      }
      break;

    // esvaziar
    case 5:
      if (filasParaCriar == 0)
      {
        esvazia_fila(f);
        printf("fila esvaziado\n");
      }
      else
      {
        printf("nao e possivel esvaziar sem fila\n");
      }
      break;

    // apagar
    case 6:
      if (filasParaCriar == 0)
      {
        apaga_fila(&f); // o ponteiro e o da aplicacao e tem a flag
        filasParaCriar--;
        printf("Fila apagado!\n");
      }
      else
      {
        printf("nao e possivel apagar sem fila\n");
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

  return 0;
}

void printa_menu ()
{
  printf("[1] criar fila de prioridades\n");
  printf("[2] imprimir fila de prioridades\n");
  printf("[3] inserir produto\n");
  printf("[4] remover produto\n");
  printf("[5] esvaziar\n");
  printf("[6] apagar\n");
  printf("[0] sair\n");
  printf("escolha: ");
}
