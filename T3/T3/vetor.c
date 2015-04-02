/*
 * vetor.c
 * TAD que implementa um vetor dinamico.
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2014, 2015 João V. Lima, UFSM
 *               2005       Benhur Stein, UFSM
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vetor.h"
#include "carta.h"
#include "memo.h"

struct vetor {
	carta* baralho;   /* baralho - vetor de cartas */
	int n;		/* número de cartas */
};

//DONE
vetor_t* vetor_cria(void)
{
	struct vetor *vet = (struct vetor*)memo_aloca(sizeof(struct vetor));
	vet->n = 0;
	int aux;
	for(aux=0;aux<20;aux++){
        vet->baralho[aux]=(carta*)malloc(sizeof(carta));
    }
	return vet;
}

//DONE
void vetor_destroi(vetor_t* vet)
{
	memo_libera(vet);
}

//DONE
int vetor_numelem(vetor_t *vet)
{
	return vet->n;
}

//DONE
void vetor_insere_carta(vetor_t *vet, int indice, carta c)
{
    int max=20,i;
	if(indice>max)
    {
        for(i=max;i<indice;i++){
            vet->baralho[i]=(carta*)malloc(sizeof(carta));
        }
        max=indice;
    }
    vet->baralho[indice]=c;
	vet->n++;
}

//DONE mas meio bugado...
carta vetor_remove_carta(vetor_t *vet, int indice)
{
    int i;

	if(vet->baralho[indice]!=NULL)
    {
        for(i=indice;i<vet->n-1;i++)
        {
            vet->baralho[i]=vet->baralho[i+1];
        }
        vet->n--;
        return vet->baralho[indice];
    }

    printf("Remocao falhou");
    return NULL;
}

//DONE
carta vetor_acessa_carta(vetor_t *vet, int indice)
{
    carta c=vet->baralho[indice];

    if(c != NULL){
        return c;
    }

    printf("Falha em acessar carta");
	return NULL;
}

//DONE
bool vetor_valido(vetor_t *vet)
{
	if (vet == NULL){
		return false;
	}

	return true;
}
