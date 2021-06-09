/*
* Autores
* Abimael de Oliveira Ferreira - 03247347
* Ernesto Nunes da Costa Junior - 03148925
* Enzo Ramon Rodrigues Almeida Cunha - 03242255
* Kevin Viana Siqueira Pantoja - 03242176
**/
#include "FUNCAO.h"

                                                                                                                         

int main() {
	NO_ARVORE *avl = NULL;
	NO_ARVORE *arvore = NULL;
	ListaSimpEncadeada lista;
    int i, h, r, vetor_insercao[20000], vetor_busca[20000];
    
    iniciaLista(&lista);

	//gerando numeros aleatorios
	srand(time(NULL));
    for (i=0 ; i<20000 ; i++) {
        vetor_insercao[i] = rand() % 40000;
    }

    for (i=0 ; i<20000 ; i++) {
        vetor_busca[i] = rand() % 40000;
    }

	// Inserção de dados
    for (i=0 ; i<20000 ; i++) {
        avl = insercao_AVL(avl,vetor_insercao[i]);
        arvore = insercao_ARVORE(arvore,vetor_insercao[i]);
        InsereValorListaSimpEncadeada(&lista, vetor_insercao[i]);
    }    
    
	// Fazendo Busca no vetor
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

   
	// Saida dos resultados
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




}
