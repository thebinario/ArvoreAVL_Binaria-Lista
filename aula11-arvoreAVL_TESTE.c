#include <stdio.h>
#include <stdlib.h>
#include "FUNCAO.h"


int main() {
	NO_ARVORE *avl = NULL;
	NO_ARVORE *arvore = NULL;
	ListaSimpEncadeada lista;
    int i, h, r, vetor_insercao[20000], vetor_busca[20000];
    
    iniciaLista(&lista);

	srand(time(NULL));
    for (i=0 ; i<20000 ; i++) {
        vetor_insercao[i] = rand() % 40000;
    }

    for (i=0 ; i<20000 ; i++) {
        vetor_busca[i] = rand() % 40000;
    }

    for (i=0 ; i<20000 ; i++) {
        avl = insercao_AVL(avl,vetor_insercao[i]);
        arvore = insercao_ARVORE(arvore,vetor_insercao[i]);
        InsereValorListaSimpEncadeada(&lista, vetor_insercao[i]);
    }    
    
    for (int i = 0; i < 20000; i++)
	{
		busca_AVL(avl, vetor_busca[i]);
	}
	
    for (int i = 0; i < 20000; i++)
	{
		busca_ARVORE(arvore, vetor_busca[i]);
	}
	
	for (int i = 0; i < 20000; i++)
	{
		busca_LISTA(&lista, vetor_busca[i]);
	
	}

	printf("Contador_INTERACAO_INSERCAO_LISTA: %d\n", contador_insercao_lista);
	printf("Contador_BUSCA_LISTA: %d\n", contador_busca_lista);	
	

   
/*	
	printf("\n");
	printf("Contador_INTERACAO_INSERCAO_AVL: %d\n", contador_insercao_AVL);
	printf("Contador_BUSCA_AVL: %d\n", contador_busca_AVL);
	printf("\n");
	printf("Contador_INTERACAO_INSERCAO_ARVORE: %d\n", contador_insercao_arvore);
	printf("Contador_BUSCA_ARVORE: %d\n", contador_busca_arvore);	
	printf("\n");
	printf("Contador_INTERACAO_INSERCAO_LISTA: %d\n", contador_insercao_lista);
	printf("Contador_BUSCA_LISTA: %d\n", contador_busca_lista);	
	printf("\n");		
	printf("total de numeros encontrado: %d\n",enc);
	printf("total de numeros nao encontrado: %d\n",nao);
	printf("\n");		
	printf("altura_AVL: %d\n", altura(avl));
	printf("altura_ARVORE: %d\n", altura(arvore));


*/

}
