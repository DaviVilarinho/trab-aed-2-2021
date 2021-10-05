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
      break;
    
    case 'O':
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
