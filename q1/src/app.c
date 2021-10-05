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

    if (num == 0 && (
        base == 'B' ||
        base == 'O' || 
        base == 'H' 
        ))
    {
      /* 
       * se for 0, os algoritmos falham porque são baseados 
       * no resto de divisão, que para valores maiores que 0,
       * representaria o fim da iteração
       */
      printf("numero convertido: 0\n\n"); 
      continue;
    }

    /*
     * O funcionamento de todos são iguais
     *
     * encontrar o resto da divisão do número pela base e 
     * adicionar à pilha (número + a esquerda primeiro), 
     * sendo o novo número a divisão por 2
     * até que o número a resolver seja 0.
     *
     * Dessa forma, encontra-se o número mais a direita,
     * e a estrutura de pilha funciona bem -> os elementos são inseridos 
     * da direita pra esquerda 
     *
     * exemplo: 7, b=2 -> 7%2 = 1, (7/2=3)%2 = 1 -> (3/2=1)%2 = 1 (1/2 = 0)%2 = 0
     *                       0111
     */
    switch (base)
    {
      // binário
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
