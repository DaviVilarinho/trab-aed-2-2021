#include "fila.h"
#ifndef STDLIB_INCLUIDA
#include <stdlib.h>
#define STDLIB_INCLUIDA
#endif
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#define NUMERO_BOXES 6 // 6 porque o de espera é o 0
#define BOX_ESPERA   0 

void print_menu();
void print_carro(carro_t carro);

int main (void) {
  fila_p boxes[NUMERO_BOXES];
  for (int i = 0; i < NUMERO_BOXES; i++) 
    boxes[i] = cria_fila(); // inicializa a fila dos boxes
  
  int escolha = -1;
  while (escolha != 0) {
    print_menu();
    scanf("%i", &escolha); setbuf(stdin, NULL);

    switch (escolha) {
      case 0: break;

      // entrada
      case 1:
        // leitura do carro
        carro_t inserindo;
        scanf("%[^\n]", inserindo.placa); setbuf(stdin, NULL);
        scanf("%c", &inserindo.tipo_servico); setbuf(stdin, NULL);

        // leitura do tempo
        time_t timer;
        time(&timer);
        inserindo.hora = timer;

        break;

      // saida
      case 2: 
        break;

      // visualizacao
      case 3: 

        for (int i = 0; i < NUMERO_BOXES; i++) {
          if (i == BOX_ESPERA) printf("BOX DE ESPERA: ");
          else printf("BOX %i: ", i);

          if (boxes[i] == NULL) {printf("ERRO: ALOCAÇÃO PARA BOX %i impossível\n", i); continue;} // verifica se fila está ainda íntegre
          fila_p temp = cria_fila();
          if (temp == NULL) {printf("ERRO: ALOCAÇÃO PARA BOX TEMPORÁRIO (para %i) impossível\n", i); continue;} // verifica se foi possível alocar
          carro_t carro_temp;

          while (fila_vazia(boxes[i]) != 1) {
            remove_ini(boxes[i], &carro_temp);
            insere_fim(temp, carro_temp);
          }

          while (fila_vazia(temp) != 1) {
            remove_ini(temp, &carro_temp);
            print_carro(carro_temp);
            insere_fim(boxes[i], carro_temp);
          }
          
          printf("\n");
        }
        break;
        
      default:
        printf("ESCOLHA INVÁLIDA\n");
    }
  }

  return 0;
}

void print_menu() {
  printf("\n====================\n");
  printf(  "===ESTACIONAMENTO===\n");
  printf(  "====================\n");
  printf("\t[0] SAIR\n");
  printf("\t[1] ENTRADA VEICULO\n");
  printf("\t[2] SAIDA VEICULO\n");
  printf("\t[3] VISUALIZAR\n");
  printf("ESCOLHA: ");
}

void print_carro(carro_t printar) {
  time_t timer; time(&timer);

  double tempo_transcorrido = difftime(timer, printar.hora);

  printf("{placa: %s, tipo: %c, tempo-transcorrido (s): %.2lf}", 
      printar.placa, 
      printar.tipo_servico,
      tempo_transcorrido
  );
}
