#include "pilha.h"
#ifndef STDLIB_INCLUIDA
#define STDLIB_INCLUIDA
#include <stdlib.h>
#endif
#include <string.h>
#include <stdio.h>

int converte_pra_posfixa(char [], char []);

int main() {  
  int FIM = 0;
  while (FIM != 1) {
    char formula[100];
    char formula_pos[100];
    //pilha_p expressao;

    printf("Digite uma expressao (FIM para sair): ") ;
    scanf("%[^\n]", formula);
    setbuf(stdin, NULL);

    if (strcmp(formula, "FIM") == 0) {
      FIM = 1;
    } else {
      // validar escopo
      int i = 0, entreParenteses = 0, entreColchetes = 0, entreChaves = 0, valido = 1;
      char c;
      while ((c = formula[i]) != '\0' && valido != 0) {
        /*
         * validação: se estiver abrindo um de mesmo escopo
         *            enquanto não tiver fechado, invalida,
         *            bem como invalida se estiver fechando algo não aberto
         */
        switch (c) {
          // ABERTURAS
            // nao pode estar com o mesmo aberto
            // nem um com menor precedencia aberto
          case '{':
            if (entreChaves == 1 || (entreParenteses == 1 || entreColchetes == 1))
              valido = 0;
            else
              entreChaves = 1;

            break;

          case '[':
            if (entreColchetes == 1 || entreParenteses == 1)
              valido = 0;
            else
              entreColchetes = 1;

            break;

          case '(':
            if (entreParenteses == 1)
              valido = 0;
            else
              entreParenteses = 1;

            break;
          
          // fechamento
            // posso fechar qualquer um que esteja aberto
            // e nao esteja com um de menor precedencia aberto
          case ')':
            if (entreParenteses == 0)
              valido = 0;
            else
              entreParenteses = 0;

            break;

          case ']':
            if (entreColchetes == 0 || entreParenteses == 1)
              valido = 0;
            else
              entreColchetes = 0;

            break;

          case '}':
            if (entreChaves == 0 || entreColchetes == 1 || entreParenteses == 1)
              valido = 0;
            else
              entreChaves = 0;

            break;

          default:;
        }
        i++;
      }

      // escopo válido
      if (valido == 1) {
        // conversao
        if (converte_pra_posfixa(formula, formula_pos) == 1) {
          printf("formula convertida: %s\n", formula_pos);
          // avaliacao
        } else {
          printf("nao foi possivel converter\n");
        }
        printf("%s\n", formula);
      } else {
        printf("expressao invalida\n");
      }
    }

//    libera_pilha(&expressao);
  }
  
  return 0;
}

int converte_pra_posfixa(char formula[], char formula_pos[]) {
  // TODO: implementar conversao
  return 0;
}
