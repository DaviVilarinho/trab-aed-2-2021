#include "pilha.h"
#include <stdio.h>

int main (void)
{
  Pilha p = cria_pilha();
  int num = 0;
  char base;

  do
  {
    printf("base a ser convertido: ");
    scanf("%c", &base);
    setbuf(stdin, NULL);
    
    printf("numero a ser convertido: ");
    scanf("%i", &num);
    setbuf(stdin, NULL);

    switch (base)
    {
    case 'B':
      while (num > 0)
      {
        int resto = num % 2;
        push(p, resto);
        num = num / 2;
      }
      printf("numero convertido: ");
      while (!pilha_vazia(p))
      {
        int printar;
        pop(p, &printar);
        printf("%i", printar);
      }
      printf("\n\n");
      break;
    
    case 'O':
      while (num > 0)
      {
        int resto = num % 8;
        push(p, resto);
        num = num / 8;
      }
      printf("numero convertido: ");
      while (!pilha_vazia(p))
      {
        int printar;
        pop(p, &printar);
        printf("%i", printar);
      }
      printf("\n\n");
      break;
      break;
    
    case 'H':
      break;

    default:
      printf("\nbase invalida\n\n");
      break;
    }
  } while (num >= 0);
  printf("\nadeus\n");
}
