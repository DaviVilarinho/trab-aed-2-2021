#include <stdlib.h>
#include <stdio.h>
#include "fila-prioridades.h"
struct fila
{
    struct no *ini, *fim;
};


struct no
{
    Produto info;
    struct no *prox;
};


Fila cria_fila ()
{
    Fila f;
    f = (Fila) malloc(sizeof(struct fila));

    if (f != NULL)
    {
        f -> ini = NULL;
        f -> fim = NULL;
    }

    return f;
}

int fila_vazia (Fila f)
{
    if (f -> ini == NULL)
        return 1;
    else
        return 0;
}

// 0 igual
// 1 primeiro mais prioritario
// 2 segundo mais priotario
int maisPrioritario (Produto p1, Produto p2)
{
    if (p1.v.ano < p2.v.ano)
        return 1;
    else if (p2.v.ano < p1.v.ano)
        return 2;

    else { // anos iguais entao
        if (p1.v.mes < p2.v.mes)
            return 1;
        else if (p2.v.mes < p1.v.mes)
            return 2;

        else { // anos & meses iguais
            if (p1.v.dia < p2.v.dia)
                return 1;
            else if (p2.v.dia < p1.v.dia)
                return 2;
            else  // todos iguais
                return 0;
        }
    }
}

int insere_ord (Fila f, Produto elem) // porque fdp tem que inserir de acordo com prioridade e remover o com menos (no caso validade)
{
    struct no *N;
    N = (struct no *) malloc(sizeof(struct no));

    if (N == NULL)
        return 0;

    N -> info = elem; //Preenche campo info
    N->prox = NULL;

    if (fila_vazia(f) == 1) // fila vazia basta inserir inicio = fim = ele
    {
        f->ini = N;
        f->fim = N;
        return 1;

    } else {                 // fila nao vazia, inserir de acordo com prioridade
        if (maisPrioritario(elem, f->ini->info) < 2) // caso N seja mais prioritario que o proprio inicio ou igual
        {
            N->prox = f->ini;
            f->ini = N;
        }     

        // nao é mais prioritario que o primeiro
        struct no *cursor_atras = f->ini;

        while (cursor_atras->prox != NULL) {
            // se encontrado onde o elemento a inserir é mais prioritario
            if (maisPrioritario(elem, cursor_atras->prox->info) < 2) {
                N->prox = cursor_atras->prox;
                cursor_atras->prox = N;

                return 1;
            }

            // nao encontrado avanca
            cursor_atras = cursor_atras->prox;
        }
        
        // nao foi inserido até o final, logo insere no final & atualiza fila
        cursor_atras->prox = N;

        f->fim = N;

        return 1;

    }
}

int remove_ini (Fila fila, Produto *elem)
{
    if (fila_vazia(fila) == 1)
        return 0;

    // caso nao vazio
    struct no *temp = fila->ini;
    *elem = fila->ini ->info;

    if (fila->ini != fila->fim) // caso com mais
      fila->ini = fila->ini->prox; // ini é o prox 
    else
      fila->ini = NULL;

    free(temp);
    temp = NULL;



    return 1;
}

int apaga_fila (Fila *f)
{
    esvazia_fila(*f); // esvazia e libera cada no
    free (*f);        // esvazia a lista
    *f = NULL;
    return 1;
}

int esvazia_fila (Fila f)
{
    while (fila_vazia(f) != 1) 
    {
        Produto foo;
        remove_ini(f, &foo);
    }
    f->fim = NULL;
    f->ini = NULL;

    return 1;
}
