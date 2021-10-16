#include "pilha.h"
#ifndef STDLIB_INCLUIDA
#define STDLIB_INCLUIDA
#include <stdlib.h>
#endif
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int converte_pra_posfixa(char [], char []);
int eh_operador (char);
int precedencias (char);
int escopo_valido (char []);
int resolve_posfixa (char [], double *);

int main() {  
  int FIM = 0;
  while (FIM != 1) {
    char formula[100];
    char formula_pos[100];

    printf("Digite uma expressao (FIM para sair): ") ;
    scanf("%[^\n]", formula);
    setbuf(stdin, NULL);

    if (strcmp(formula, "FIM") == 0) {
      FIM = 1;
    } else {
      // escopo válido
      if (escopo_valido(formula) == 1) {
        // conversao
        printf("formula digitada: %s\n", formula);
        if (converte_pra_posfixa(formula, formula_pos) == 1) {
          printf("formula convertida: %s\n", formula_pos);
          // avaliacao
        } else {
          printf("nao foi possivel converter\n");
        }
      } else {
        printf("expressao invalida\n");
      }
    }

  }
  
  return 0;
}

// modularizado porque dizia que tinha que retornar
int converte_pra_posfixa (char formula[], char formula_pos[]) {
  pilha_p expressao = cria_pilha();

  char *c;
  char *x;
  int i = 0;
  
  // varrer a expressao da esquerda pra direita
  while ((*c = formula[i]) != '\0') {
    if(isalpha(*c))
      formula_pos[i] = *c;
    else if(*c == '(')
      push(&expressao, (void **) &c);
    else if(*c == ')') {
      pop(&expressao, (void **) &x);
      while(*x != '(') {
        formula_pos[i] = *x;
        pop(&expressao, (void **) &x);
      }
    }
    else {
      pop(&expressao, (void **) &x);
      while(precedencias(*x) >= precedencias(*c)) {
        formula_pos[i] = *x;
        pop(&expressao, (void **) &x);
      }
      push(&expressao, (void **) &c);
    } 
    i++;
  }

  while(!pilha_vazia(expressao)) {
    pop(&expressao, (void **) &x);
    formula_pos[i] = *x;
    i++;
  }

  libera_pilha(&expressao);
  return 1;
}

int eh_operador (char c) {
  return (c == '^' || c == '*' || c == '/' || c == '+' || c == '-');
}

int precedencias (char c) {
  if (c == '^') {
    return 3;
  } else if (c == '*' || c == '/') {
    return 2;
  } else if (c == '+' || c == '-') {
    return 1;
  } else {
    return 0;
  }
}

int resolve_pos_fixa (char formula_pos_fixa[], double *resultado) {
  pilha_p nova_pilha = cria_pilha();

  int i = 0;
  char *c;

  while (formula_pos_fixa[i] != '\0')

  libera_pilha(&nova_pilha);

  return 1;
}

// modularizado porque são muitas linhas
int escopo_valido (char formula[]) {
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

  return valido;
}