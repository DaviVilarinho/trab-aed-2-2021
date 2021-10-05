#include "pilha.h"
#include <stdio.h>

int main (void)
{
  Pilha p = cria_pilha();
  int num = 0;
  char base;

  do
  {
    printf("base a ser convertido (B-binário O-octadecimal H-hexadecimal): ");
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
      
      case 'H':
        while (num > 0)
        {
          int resto = num % 16;
          push(p, resto);
          num = num / 16;
        }
        printf("numero convertido: ");
        while (!pilha_vazia(p))
        {
          int printar;
          pop(p, &printar);
          switch(printar) 
          {
            case 10: printf("A"); break;
            case 11: printf("B"); break;
            case 12: printf("C"); break;
            case 13: printf("D"); break;
            case 14: printf("E"); break;
            case 15: printf("F"); break;
            default: printf("%i", printar);
          }
        }
        printf("\n\n");
        break;

      default:
        printf("\nbase invalida\n\n");
        break;
    }
  } while (num >= 0);
  printf("\nadeus\n");

  return 0;
}
