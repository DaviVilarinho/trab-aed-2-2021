#define MAX_ELEMS 15
#define MAX_CHAR_STR 20

typedef struct deque * Deque;

Deque cria_deque ();
int deque_vazio(Deque d);
int deque_cheio(Deque d);
int insere_ini(Deque d, char *elem);
int insere_fim(Deque d, char *elem);

int remove_ini(Deque d, char *elem);
int remove_fim(Deque d, char *elem);
