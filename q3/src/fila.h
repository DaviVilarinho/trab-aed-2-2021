struct aluno {
  char nome[50];
  int faltas;
  float media;
};

typedef struct aluno aluno_t;

typedef struct fila * fila_p;

fila_p cria_fila();
int fila_vazia(fila_p fila);
int fila_cheia(fila_p fila);
int insere_fim(fila_p fila, aluno_t inserir);
int remove_ini(fila_p fila, aluno_t *removido);
int libera_fila(fila_p *fila);
