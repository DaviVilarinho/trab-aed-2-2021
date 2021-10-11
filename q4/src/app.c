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
  Fila printar;

  do
  {
    printa_menu();
    char temp_data[15];
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
        printf("\nFILA:\n");
        printar = cria_fila();

        while (fila_vazia(f) != 1) {
          remove_ini(f, &temp);
          insere_ord(printar, temp);
        }

        while (fila_vazia(printar) != 1) {
          remove_ini(printar, &temp);
          printa_produto(temp);
          insere_ord(f, temp);
        }

        apaga_fila(&printar);
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
        /*
        printf("PRODUTO A INSERIR:\n");
        printf("\tCODIGO: ");
        scanf("%i", &temp.codigo); setbuf(stdin, NULL);

        printf("\tDESCRICAO: ");
        scanf("%[^\n]", temp.descricao); setbuf(stdin, NULL);

        printf("\tVALOR: ");
        scanf("%f", &temp.valor); setbuf(stdin, NULL);

        printf("\tVALIDADE (dia/mes/ano): ");
        scanf("%[^\n]", temp_data); setbuf(stdin, NULL);
        sscanf(temp_data, "%i/%i/%i", &temp.v.dia, &temp.v.mes, &temp.v.ano);

        // inserir struct temp
        insere_ord(f, temp);
        */
        // mock
        Produto a4 = {456, "asdasd", 18.5, {2,2,2}};
        insere_ord(f, a4);
        Produto a1 = {123, "asdasd", 17.5, {1,1,1}};
        insere_ord(f, a1);
        Produto a2 = {234, "asdasd", 18.5, {4,4,4}};
        insere_ord(f, a2);
        Produto a3 = {345, "asdasd", 18.5, {3,3,3}};
        insere_ord(f, a3);
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
        if (remove_ini(f, &temp) == 1) {
          printf("REMOVIDO: ");
          printa_produto(temp);
        } else {
          printf("Fila vazia\n");
        }
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
        printf("Fila apagada!\n");
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

void printa_produto (Produto p) {
  printf("\t{CODIGO: %i, DESCRICAO: %s, VALOR: $%.2f, VALIDADE: %i/%i/%i}\n",
          p.codigo,   p.descricao, p.valor,        p.v.dia, p.v.mes, p.v.ano
  );
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
