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

int insere_asc (Fila f, Produto elem)
{
    struct no *N;
    N = (struct no *) malloc(sizeof(struct no));

    if (N == NULL)
        return 0;

    N -> info = elem; //Preenche campo info

    Fila aux = f;

    if (fila_vazia(f) == 1)
        f -> ini = N; //Se fila vazia
    else
    {
        while (N != f -> fim) // Enquanto não chegar ao fim da fila
        {
            Produto ini = (aux -> ini) -> info;
            int ano = elem.validade % 10000;
            int ano2 = ini.validade % 10000;
            int mes = (elem.validade % 1000000) / 10000;
            int mes2 = (ini.validade % 1000000) / 10000;
            int dia = elem.validade / 1000000;
            int dia2 = ini.validade / 1000000;

            if (ano2 > ano) // Se o ano do produto do início for maior que o ano de elem
                N -> prox = (aux -> ini); // O prox de N aponta para aux
            else if (ano2 == ano) //Se os anos forem iguais, passamos para os meses
            {
                if (mes2 > mes) //Se o mes do produto do ini for maior que o mes do elem
                    N -> prox = (aux -> ini); // O prox de N aponta pra aux
                else if (mes2 == mes) //Se os meses forem iguais, passamos para os dias
                {
                    if (dia2 > dia || dia2 == dia) //Se os dias forem iguais ou o de aux for maior, podemos colocar o N antes de aux
                        N -> prox = (aux -> ini); // O prox de N aponta para aux
                }
            }
            else if (ano2 < ano || mes2 < mes || dia2 < dia) // Agora se o elem for maior que ini, passamos ao prox
                (aux -> ini) = (aux -> ini) -> prox;
        }
    }

    return 1;
}

int remove_ini (Fila *f, Produto *elem)
{
    if (fila_vazia(*f) == 1)
        return 0;

    // caso nao vazio
    struct no *aux = (*f)->ini;
    (*f)->ini = (*f)->ini->prox;

    *elem = aux->info;
    free(aux);
    aux = NULL;

    return 1;
}

int apaga_fila (Fila *f)
{
    esvazia_fila(*f); // esvazia e libera cada no
    free (*f);        // esvazia a lista
    *f = NULL;
    return 1;
}

int esvazia_fila (Fila *f)
{
    while (fila_vazia(*f) != 1) 
    {
        Produto foo;
        remove_ini(f, &foo);
    }
    (*f)->fim = NULL;
    (*f)->ini = NULL;

    return 1;
}
