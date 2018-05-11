#ifndef LISTASDUPLBONUS_H_INCLUDED
#define LISTASDUPLBONUS_H_INCLUDED

#define tamanhoListas 2 ///numero de elementos na lista1, 2 e 3 tbm
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
}REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* ant;
    struct aux* prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT inicio;
    PONT fim;
}LISTA;

int gerarNumAleatorio();
void inicializarLista(LISTA *l);
void exibirLista(LISTA *l);
PONT buscaSequencialExc(LISTA *l, TIPOCHAVE ch, PONT *ant);
void inserirElementoDecrescente(LISTA *l, REGISTRO reg);
void inserirElementoCrescente(LISTA *l, REGISTRO reg);
void receberLista(LISTA *l);
void concatenar(LISTA *l1, LISTA *l2, LISTA *l3, LISTA *l4, REGISTRO reg);
PONT menor(LISTA *l, PONT comeco);
void trocar(LISTA *l, PONT x, PONT y);
void sort(LISTA *l);

#endif // LISTASDUPLBONUS_H_INCLUDED
