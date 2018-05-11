#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "ListasDuplBonus.h"

int main()
{
    int numAleatorio;
    int i;

    LISTA lista1;
    LISTA lista2;
    LISTA lista3;
    LISTA listasConcatenadas;
    REGISTRO reg;

    inicializarLista(&lista1);
    inicializarLista(&lista2);
    inicializarLista(&lista3);
    inicializarLista(&listasConcatenadas);

    ///Construindo LISTA 1;
    printf("\nConstruindo listas!\n\n");
    system("pause");
    srand(time(NULL));
    for(i=0;i<tamanhoListas;i++){
        reg.chave = rand()%50;
        inserirElementoCrescente(&lista1, reg);
    }
    printf("\nLista 1 construida!\n\n");

    ///Construindo LISTA 2;
    system("pause");
    srand(time(NULL));
    for(i=0;i<tamanhoListas;i++){
        reg.chave = rand()%50;
        inserirElementoDecrescente(&lista2, reg);
    }
    printf("\nLista 2 construida!\n\n");

    ///Construindo LISTA 3;
    system("pause");
    srand(time(NULL));
    for(i=0;i<tamanhoListas;i++){
        reg.chave = rand()%50;
        inserirElementoDecrescente(&lista3, reg);
    }
    printf("\nLista 3 construida!\n\n");

    exibirLista(&lista1);
    exibirLista(&lista2);
    exibirLista(&lista3);

    concatenar(&lista1, &lista2, &lista3, &listasConcatenadas, reg);

    exibirLista(&listasConcatenadas);

    return 0;
}
