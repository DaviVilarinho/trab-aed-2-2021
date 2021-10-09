#include "pilha.h"
#ifndef STDLIB_INCLUIDA
#define STDLIB_INCLUIDA
#include <stdlib.h>
#endif
#include <string.h>
#include <stdio.h>

int main() {  
  int FIM = 0;
  while (FIM != 1) {
    char formula[100];
    pilha_p expressao;
    printf("Digite uma expressao (FIM para sair): ") ;
    scanf("%[^\n]", formula);

    if (strcmp(formula, "FIM") == 0) {
      FIM = 1;
    } else {
      // validar escopo
      // conversao
      // avaliacao
    }

    libera_pilha(&expressao);
  }
  
  return 0;
}

