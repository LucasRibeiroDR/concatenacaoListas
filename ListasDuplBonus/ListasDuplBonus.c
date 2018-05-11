#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "ListasDuplBonus.h"


int gerarNumAleatorio(int I){
    srand (time(NULL));
    //srand(I);
    return rand()%50;
}

void inicializarLista(LISTA *l){
   l->inicio=NULL;
   l->fim=NULL;
}

void exibirLista(LISTA *l){
    PONT p = l->inicio;
    if(l->inicio!=NULL){
        printf("\n\nLista: ");
    }else{
        printf("Lista VAZIA!");
    }
    while(p != NULL){
        printf("%d, ", p->reg.chave);
        p = p->prox;
    }
}

void concatenar(LISTA *l1, LISTA *l2, LISTA *l3, LISTA *l4, REGISTRO registro){
    int i=0;
    PONT p1 = l1->inicio;
    PONT p2 = l2->inicio;
    PONT p3 = l3->inicio;
    ///Inserindo a LISTA 1 na LISTA 4
    for(i=0;i<tamanhoListas;i++){
        registro.chave = p1->reg.chave;
        inserirElementoCrescente(&l4,registro);
        p1 = p1->prox;
    }

    ///Inserindo a LISTA 2 na LISTA 4
    for(i=0;i<tamanhoListas;i++){
        registro.chave = p2->reg.chave;
        inserirElementoCrescente(&l4,registro);
        p2 = p2->prox;
    }

    ///Inserindo a LISTA 3 na LISTA 4
    for(i=0;i<tamanhoListas;i++){
        registro.chave = p3->reg.chave;
        inserirElementoCrescente(&l4,registro);
        p3 = p3->prox;
    }

    exibirLista(&l4);
}

PONT buscaSequencialExc(LISTA *l, TIPOCHAVE ch, PONT *ant){
    *ant = NULL;
    PONT atual = l->inicio;
    while (atual != NULL  &&   atual->reg.chave < ch) {
        *ant = atual;
        atual = atual->prox;
    }
    if(atual != NULL   &&   atual->reg.chave == ch) return atual;
    return NULL;
}

void inserirElementoCrescente(LISTA *l, REGISTRO reg){
     PONT atual = NULL;
     PONT ant = NULL;
     PONT novo = NULL;
     novo = (PONT) malloc(sizeof(ELEMENTO));
     if(novo == NULL){
        printf("\n\nErro de alocacao!");
    }

    novo->reg = reg;
    novo->prox = NULL;
    novo->ant = NULL;

    atual = l->inicio;

    while(atual != NULL && atual->reg.chave < reg.chave){
        ant = atual;
        atual = atual->prox;

    }

    novo->prox = atual;
    novo->ant = ant;
    if(ant == NULL){
        l->inicio = novo;
        if(atual != NULL){
            atual->ant = novo;

        }
    }else{
        ant->prox = novo;
        if(atual != NULL){
            atual->ant = novo;
        }
    }
}

void inserirElementoDecrescente(LISTA *l, REGISTRO reg){
     PONT atual = NULL;
     PONT ant = NULL;
     PONT novo = NULL;
     novo = (PONT) malloc(sizeof(ELEMENTO));
     if(novo == NULL){
        printf("\n\nErro de alocacao!");
    }

    novo->reg = reg;
    novo->prox = NULL;
    novo->ant = NULL;

    atual = l->inicio;

    while(atual != NULL && atual->reg.chave > reg.chave){
        ant = atual;
        atual = atual->prox;

    }

    novo->prox = atual;
    novo->ant = ant;
    if(ant == NULL){
        l->inicio = novo;
        if(atual != NULL){
            atual->ant = novo;

        }
    }else{
        ant->prox = novo;
        if(atual != NULL){
            atual->ant = novo;
        }
    }
}

PONT menor(LISTA *l, PONT comeco){
    PONT aux = comeco;
    int aux2 = aux->reg.chave;
    PONT i;

    for(i = comeco; i != l-> fim; i = i->prox){
        if(aux2 < i->reg.chave){
            aux = i;
        }
    }

    return aux;
}

void trocar(LISTA *l, PONT x, PONT y){
    PONT aux;

    PONT aux2;

    aux2 = x->ant;
    aux2->prox = y;
    aux2 = x->prox;
    aux2->ant = y;

    aux2 = y->ant;
    aux2->prox = x;
    aux2 = y->prox;
    aux2->ant = x;

    aux->ant = x->ant;
    aux->prox = x->prox;
    x->ant = y->ant;
    x->prox = y->prox;
    y->ant = aux->ant;
    y->prox = aux->prox;

}

void sort(LISTA *l){
    PONT i;
    for(i = l->inicio; i->prox != NULL; i = i->prox){
        PONT aux = menor(l, i);

        if(i->reg.chave > aux->reg.chave){
            trocar(l, i, aux);
        }

    }
}
