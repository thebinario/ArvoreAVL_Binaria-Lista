#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int contador_insercao_AVL = 0;
int contador_busca_AVL = 0;
int contador_insercao_lista = 0;
int contador_busca_lista = 0;
int contador_insercao_arvore = 0;
int contador_busca_arvore = 0;
int nao = 0;
int enc = 0;

int valor_busca_arvore = 0;
int valor_busca_avl = 0;

typedef struct no_arvore
{
	int valor;
	struct no_arvore *esq;
	struct no_arvore *dir;
} NO_ARVORE;

typedef struct NoListaSimp
{
	int valor;
	struct NoListaSimp *prox;
} NoListaSimp;

//Estrutura que gerencia a lista.
typedef struct ListaSimpEncadeada
{
	int tamanho;
	NoListaSimp *inicio;
} ListaSimpEncadeada;

//Iniciar lista simplesmente encadeada.
void iniciaLista(ListaSimpEncadeada *L)
{
	(*L).tamanho = 0;
	(*L).inicio = NULL;
}

//Inserir um novo elemento na lista.
void inserirNoListaSimp(NoListaSimp **ATUAL, int x)
{
	//Alocar dinamicamente um novo elemento da lista.
	NoListaSimp *NOVO = (NoListaSimp *)malloc(sizeof(NoListaSimp));
	(*NOVO).valor = x;

	//Inserir elemento no in�cio da lista.
	if (*ATUAL == NULL)
	{
		*ATUAL = NOVO;
		(**ATUAL).prox = NULL;
	}
	//Inserir elemento nas demais posi��es da lista
	else
	{
		NoListaSimp *PROX = (**ATUAL).prox;

		(**ATUAL).prox = NOVO;
		(*NOVO).prox = PROX;
	}
}

//Imprimir lista encadeada
void imprimirListaSimpEncadeada(ListaSimpEncadeada L)
{
	NoListaSimp *aux = L.inicio;

	while (aux != NULL)
	{
		printf("%d ---> ", (*aux).valor);
		aux = (*aux).prox;
	}
	printf("\n");
}

//Buscar posi��o na lista L para inserir o valor x quando L n�o est� vazia e x n�o � o menor valor de L.
NoListaSimp *buscaPosicaoInsercao(ListaSimpEncadeada L, int x)
{
	NoListaSimp *aux = L.inicio;

	while ((*aux).prox != NULL)
	{
		if ((*aux).prox->valor > x)
		{
			return aux;
		}
		aux = (*aux).prox;
	}
	return aux;
}

//Inserir x no inicio de uma lista.
void insereInicioLista(NoListaSimp **INICIO, int x)
{

	NoListaSimp *PROX = *INICIO;

	NoListaSimp *NOVO = (NoListaSimp *)malloc(sizeof(NoListaSimp));
	(*NOVO).valor = x;

	*INICIO = NOVO;
	(**INICIO).prox = PROX;
}

//Remover um elemento x da lista.
void removeNoListaSimp(ListaSimpEncadeada *L, int x)
{
}

void InsereValorListaSimpEncadeada(ListaSimpEncadeada *L, int x)
{

	//Inserir na lista vazia.
	if ((*L).inicio == NULL)
	{
		inserirNoListaSimp(&(*L).inicio, x);
		contador_insercao_lista++;
	}
	else
	{
		//Inserir um valor x que � o menor valor da lista.
		if (x < (*L).inicio->valor)
		{
			insereInicioLista(&(*L).inicio, x);
			contador_insercao_lista++;
		}
		//Inserir um valor x nas demais posi��es da lista.
		else
		{
			NoListaSimp *p = buscaPosicaoInsercao(*L, x);
			inserirNoListaSimp(&p, x);
			contador_insercao_lista++;
		}
	}
}

//////FUN��O BUSCA LISTA ALTERAR###############################################################################
NoListaSimp *busca_LISTA(ListaSimpEncadeada *L, int x)
{
	NoListaSimp *p = (*L).inicio;

	int inter = 0;
	while (p != NULL)
	{
		if (p->valor == x)
		{
			printf("NUMERO: %d - BUSCA: %d - Quantidade de interacoes: %d \n", x, p->valor, inter);
			break;
		}
		else
		{
			contador_busca_lista++;
			inter++;
			if(inter == 20000){
				contador_busca_lista -= 20000;
			}
		}
		p = p->prox;
	}
}
//
//
//
//##########################################################

NO_ARVORE *remocao(NO_ARVORE *raiz, int x);

void pre_ordem(NO_ARVORE *raiz)
{
	if (raiz != NULL)
	{
		printf("%d\n", (*raiz).valor);
		pre_ordem((*raiz).esq);
		pre_ordem((*raiz).dir);
	}
}

void em_ordem(NO_ARVORE *raiz)
{
	if (raiz != NULL)
	{
		em_ordem((*raiz).esq);
		printf("%d\n", (*raiz).valor);
		em_ordem((*raiz).dir);
	}
}

void pos_ordem(NO_ARVORE *raiz)
{
	if (raiz != NULL)
	{
		pos_ordem((*raiz).esq);
		pos_ordem((*raiz).dir);
		printf("%d\n", (*raiz).valor);
	}
}

void busca_AVL(NO_ARVORE *arvore, int num)
{

	//contador_busca_AVL++;

	if (arvore != NULL)
	{
		if (arvore->valor > num)
		{
			contador_busca_AVL++;
			busca_AVL(arvore->esq, num);
		}
		else if (arvore->valor < num)
		{
			contador_busca_AVL++;
			busca_AVL(arvore->dir, num);
		}
		else
		{
			//printf("\nNumero encontrado %d\n", arvore->valor);
			enc++; //INCREMENTA CONTADOR DE NUMEROS ENCONTRADOS
				   //contador_busca_AVL++;
		}
	}
	else
	{
		//NUMERO NAO ENCONTRADO
		nao++; // INCREMENTA CONTADOR DE NUMEROS NAO ENCONTRADOS
	}
}

void busca_ARVORE(NO_ARVORE *arvore, int num)
{

	//contador_busca_arvore++;

	if (arvore != NULL)
	{
		if (arvore->valor > num)
		{
			contador_busca_arvore++;
			busca_ARVORE(arvore->esq, num);
		}
		else if (arvore->valor < num)
		{
			contador_busca_arvore++;
			busca_ARVORE(arvore->dir, num);
		}
		else
		{
			//NUMERO ENCONTRADO
			//contador_busca_arvore++;
		}
	}
	else
	{
		//NUMERO NAO ENCONTRADO
	}
}

int altura(NO_ARVORE *raiz)
{
	if (raiz == NULL)
	{
		return 0;
	}
	else
	{
		int hD = altura((*raiz).dir);
		int hE = altura((*raiz).esq);
		if (hD > hE)
		{
			return hD + 1;
		}
		else
		{
			return hE + 1;
		}
	}
}

int fator_balanceamento(NO_ARVORE *raiz)
{
	return altura((*raiz).dir) - altura((*raiz).esq);
}

NO_ARVORE *rotacao_simples_direita(NO_ARVORE *p)
{
	NO_ARVORE *u = (*p).esq;
	(*p).esq = (*u).dir;
	(*u).dir = p;
	return u;
}

NO_ARVORE *rotacao_simples_esquerda(NO_ARVORE *p)
{
	NO_ARVORE *z = (*p).dir;
	(*p).dir = (*z).esq;
	(*z).esq = p;
	return z;
}

NO_ARVORE *rotacao_dupla_direita(NO_ARVORE *p)
{
	(*p).esq = rotacao_simples_esquerda((*p).esq);
	p = rotacao_simples_direita(p);
	return p;
}

NO_ARVORE *rotacao_dupla_esquerda(NO_ARVORE *p)
{
	(*p).dir = rotacao_simples_direita((*p).dir);
	p = rotacao_simples_esquerda(p);
	return p;
}

NO_ARVORE *balanceamento(NO_ARVORE *p)
{
	int fb = fator_balanceamento(p);

	if (fb < -1)
	{
		if (fator_balanceamento((*p).esq) < 0)
		{
			p = rotacao_simples_direita(p);
		}
		else
		{
			p = rotacao_dupla_direita(p);
		}
	}
	else if (fb > 1)
	{
		if (fator_balanceamento((*p).dir) > 0)
		{
			p = rotacao_simples_esquerda(p);
		}
		else
		{
			p = rotacao_dupla_esquerda(p);
		}
	}
	return p;
}

NO_ARVORE *insercao_AVL(NO_ARVORE *raiz, int x)
{ //AVL

	if (raiz == NULL)
	{
		NO_ARVORE *aux;
		aux = (NO_ARVORE *)malloc(sizeof(NO_ARVORE));
		(*aux).valor = x;
		(*aux).esq = NULL;
		(*aux).dir = NULL;
		return aux;
	}
	else
	{

		if (x < (*raiz).valor)
		{
			contador_insercao_AVL++;
			(*raiz).esq = insercao_AVL((*raiz).esq, x);
		}
		else if (x > (*raiz).valor)
		{
			contador_insercao_AVL++;
			(*raiz).dir = insercao_AVL((*raiz).dir, x);
		}
		else
		{
			//	printf("Elemento já existente na arvore\n");
		}
		raiz = balanceamento(raiz);
		return raiz;
	}
}

NO_ARVORE *insercao_ARVORE(NO_ARVORE *raiz, int x)
{ //ARVORE

	if (raiz == NULL)
	{
		NO_ARVORE *aux;
		aux = (NO_ARVORE *)malloc(sizeof(NO_ARVORE));
		(*aux).valor = x;
		(*aux).esq = NULL;
		(*aux).dir = NULL;
		return aux;
	}
	else
	{
		if (x < (*raiz).valor)
		{
			contador_insercao_arvore++;
			(*raiz).esq = insercao_ARVORE((*raiz).esq, x);
		}
		else if (x > (*raiz).valor)
		{
			contador_insercao_arvore++;
			(*raiz).dir = insercao_ARVORE((*raiz).dir, x);
		}
		else
		{
			//	printf("Elemento já existente na arvore\n");
		}
		return raiz;
	}
}

int maiorNo(NO_ARVORE *raiz)
{
	NO_ARVORE *aux = raiz;
	while ((*aux).dir != NULL)
	{
		aux = (*aux).dir;
	}
	return (*aux).valor;
}

NO_ARVORE *removerNo(NO_ARVORE *no)
{
	if ((*no).esq == NULL && (*no).dir == NULL)
	{
		//Nó folha
		free(no);
		return NULL;
	}
	else if ((*no).esq == NULL)
	{
		//Nó com 1 filho para direita.
		NO_ARVORE *aux = (*no).dir;
		free(no);
		return aux;
	}
	else if ((*no).dir == NULL)
	{
		//Nó com 1 filho para esquerda.
		NO_ARVORE *aux = (*no).esq;
		free(no);
		return aux;
	}
	else
	{
		//Nó com 2 filhos
		int aux = maiorNo((*no).esq);
		(*no).valor = aux;
		(*no).esq = remocao((*no).esq, aux);
		no = balanceamento(no);
		return no;
	}
}

NO_ARVORE *remocao(NO_ARVORE *raiz, int x)
{

	if (raiz != NULL)
	{
		if ((*raiz).valor == x)
		{
			//printf("Valor encontrado: %d\n", (*raiz).valor);
			raiz = removerNo(raiz);
		}
		else if (x < (*raiz).valor)
		{
			(*raiz).esq = remocao((*raiz).esq, x);
			raiz = balanceamento(raiz);
		}
		else
		{
			(*raiz).dir = remocao((*raiz).dir, x);
			raiz = balanceamento(raiz);
		}
	}
	else
	{
		printf("Valor nao encontrado\n");
	}
	return raiz;
}
