#include <stdlib.h>
#include "fila.h"

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

    Produto ini = (f -> ini) -> info;
    int ano = elem.validade % 10000;
    int ano2 = ini.validade % 10000;
    int mes = (elem.validade % 1000000) / 10000;
    int mes2 = (ini.validade % 1000000) / 10000;
    int dia = elem.validade / 1000000;
    int dia2 = ini.validade / 1000000;

    if (fila_vazia(f) == 1)
        f -> ini = N; //Se fila vazia
    else
    {
        if (ano2 > ano) // Se o ano do produto do início for maior que o ano de elem
            N -> prox = f -> ini; // O prox de N aponta para ini
        else if (ano2 == ano) //Se os anos forem iguais, passamos para os meses
        {
            if (mes2 > mes) //Se o mes do produto do ini for maior que o mes do elem
                N -> prox = f -> ini; // O prox de N aponta pra ini
            else if (mes2 == mes) //Se os meses forem iguais, passamos para os dias
            {
                if (dia2 > dia || dia2 == dia) //Se os dias forem iguais ou o de ini for maior, podemos colocar o N no lugar de ini
                    N -> prox = f -> ini; // O prox de N aponta para ini
            }
        }
        else if (ano2 < ano || mes2 < mes || dia2 < dia) // Agora se o elem for maior que ini, então precisamos entrar num loop que encontra seu devido lugar e o acomoda lá
        {
            while (N -> prox != (f -> fim) -> prox) // Enquanto não chegar ao fim da fila
            {
                
            }
        }
    }

    return 1;
}

int remove_ini (Fila f, Produto *elem)
{
    if (fila_vazia(f) == 1)
        return 0;

    struct no *aux = f -> ini;
    *elem = aux -> info;

    if (f -> ini == f -> fim)
        f -> fim = NULL;

    f -> ini = aux -> prox;
    free (aux);
    return 1;
}

int apaga_fila (Fila f)
{
    free (f);
    return 1;
}

int esvazia_fila (Fila f)
{
    f = NULL;
    return 1;
}
