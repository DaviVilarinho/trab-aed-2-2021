/*
 * TODO:
 *  - RETIRAR VEICULO
 */
#include "fila.h"
#ifndef STDLIB_INCLUIDA
#include <stdlib.h>
#define STDLIB_INCLUIDA
#endif
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#define NUMERO_BOXES      6 // 6 porque o de espera é o 0
#define PRIMEIRO_BOX_UTIL 1
#define BOX_ESPERA        0 

int nao_percorridos(int tamanhos[]);
void print_menu();
void print_carro(carro_t carro);
int insere_no_melhor_box(fila_p boxes[], carro_t inserir, int isFilaDeEspera); 
  // >0 -> inseriu (em qual box entrou), -1 -> fila de espera, 0 -> nao inseriu

int main (void) {
  fila_p boxes[NUMERO_BOXES];
  carro_t inserindo;
  carro_t removendo;
  char placa_remover[8];
  int tamanhos[5];
  int FLAG_CICLO_REMOVER;
  for (int i = 0; i < NUMERO_BOXES; i++) 
    boxes[i] = cria_fila(); // inicializa a fila dos boxes
  
  int escolha = -1;
  while (escolha != 0) {
    // a cada iteração, verificar se a fila de espera esta populada
    if (fila_vazia(boxes[BOX_ESPERA]) != 1) {
      carro_t primeiro_carro_copia;
      get_ini(boxes[BOX_ESPERA], &primeiro_carro_copia); // espia primeiro carro da fila

      if (insere_no_melhor_box(boxes, primeiro_carro_copia, 1)) { // tenta inserir a copia na melhor posicao possivel ou permanecer na espera 
        remove_ini(boxes[BOX_ESPERA], &primeiro_carro_copia);
        printf("CARRO SAIU DA LISTA DE ESPERA: ");
        print_carro(primeiro_carro_copia);
      }
    }

    print_menu();
    scanf("%i", &escolha); setbuf(stdin, NULL);

    switch (escolha) {
      case 0: break;

      // entrada
      case 1:
        // leitura do carro
        printf("PLACA: ");
        scanf("%[^\n]", inserindo.placa); setbuf(stdin, NULL);
        printf("TIPO DE SERVICO (A-avulso, M-mensal): ");
        scanf("%c", &inserindo.tipo_servico); setbuf(stdin, NULL);

        // leitura do tempo
        time_t timer;
        time(&timer);
        inserindo.hora = timer;

        // onde estacionar
        int flag_insercao = insere_no_melhor_box(boxes, inserindo, 0);
        if (flag_insercao > 0) {
          printf("Carro inserido no box %i\n", flag_insercao);
        } else if (flag_insercao == -1) {
          printf("Carro na fila de espera\n");
        } else {
          printf("Nao inserido\n");
        }

        break;

      // saida
      case 2: 
        // leitura do carro
        printf("PLACA: ");
        scanf("%[^\n]", placa_remover); setbuf(stdin, NULL);
        
        for (int i = PRIMEIRO_BOX_UTIL; i < NUMERO_BOXES; i++) {
          tamanhos[i-1] = tamanho(boxes[i]);
        }

        FLAG_CICLO_REMOVER = 1;
        while (nao_percorridos(tamanhos) != 0 && (FLAG_CICLO_REMOVER)) {
          for (int cabeca_box = PRIMEIRO_BOX_UTIL; cabeca_box < NUMERO_BOXES; cabeca_box++) {
            if (tamanhos[cabeca_box-1] != 0) {
              remove_ini(boxes[cabeca_box], &removendo);
              if (strcmp(removendo.placa, placa_remover) == 0) {
                printf("\n");
                printf("carro removido: ");
                print_carro(removendo);
                printf("\n");

                // calculo de quanto pagar
                time_t timer; time(&timer);
                double tempo_transcorrido = difftime(timer, removendo.hora); // sai em segundos
                // 5 reais a primeira hora + 1,50 cada hora adicional (tolerancia 10s)
                double minuto_inicial = (tempo_transcorrido >= 60.00) ? 1.00: 0.00;
                double minutos_adicionais = 0.00;
                if (tempo_transcorrido >= 70) {
                  minutos_adicionais = tempo_transcorrido - 70.00;
                }
                double pagar_total = (5.00 * minuto_inicial) + (1.50 * minutos_adicionais);
                printf("pagar: R$%.2lf", pagar_total);
                FLAG_CICLO_REMOVER = 0; 
                break;
              } else {
                insere_fim(boxes[cabeca_box], removendo);
                printf("nao eh o carro: ");
                print_carro(removendo);
                printf("\n");
              } 

              tamanhos[cabeca_box-1] -= 1;
            }
          }
        }
        break;

      // visualizacao
      case 3: 

        for (int i = 0; i < NUMERO_BOXES; i++) {
          if (i == BOX_ESPERA) printf("BOX DE ESPERA: ");
          else printf("BOX %i: \n", i);

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
            printf("\t");
            print_carro(carro_temp);
            printf("\n");
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

int insere_no_melhor_box(fila_p boxes[], carro_t inserir, int isFilaDeEspera) {
  int MELHOR = PRIMEIRO_BOX_UTIL;

  for (int i = PRIMEIRO_BOX_UTIL; i < NUMERO_BOXES; i++) {
    if (tamanho(boxes[i]) < tamanho(boxes[MELHOR])) // tamanho do box do loop menor do tamanho do melhor box
      MELHOR = i;
  } 

  if (insere_fim(boxes[MELHOR], inserir) == 1) {    // conseguiu inserir no melhor box
    return MELHOR;
    
  } else {                                          // nao conseguiu inserir no melhor box (estava cheio)
    if (isFilaDeEspera == 1)                        // ja sendo da lista de espera, nao faca nada
      return 0;
    if (insere_fim(boxes[BOX_ESPERA], inserir) == 1) {  // tenta inserir na fila de espera
      return -1;
    } else {                                        // nao foi possivel inserir na lista de espera
      return 0;
    }
  }
}

int nao_percorridos(int tamanhos[]) {
  int num_boxes_nao_percorridos = 0;
  
  for (int i = PRIMEIRO_BOX_UTIL-1; i < NUMERO_BOXES-1; i++) {
    if (tamanhos[i] != 0) {
      num_boxes_nao_percorridos++; 
    }
  }

  return num_boxes_nao_percorridos;
}
