/*
	Sora eu quis dxar bem claro que tava manipulando estruturas diferentes
	por isso ate que fiz dois imprimes

	minha ideia foi em fazer o empilhamento das pilhas

	depois no desempilhamento
	fiz um laco que vai tirando os elementos alternados e colocando na fila com a fucnao insere no fim;


*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No
{
	int valor;
	struct No *proximo;

} No;

typedef struct Lista
{
	No *Inicio;
	No *Fim;
} Lista;

typedef struct Pilha
{
	No *inicio;
} Pilha;

bool verificaListaVazia(No *ponteiroInicio)
{
	if (ponteiroInicio == NULL)
	{

		return true;
	}
	return false;
}

void imprimirPilhas(Pilha pilha)
{
	No *auxiliar = pilha.inicio;

	if (verificaListaVazia(auxiliar))
	{
		return;
	}
	else
	{
		printf("Endereco\tValor\tProximo\n");
		while (auxiliar != NULL)
		{
			printf("%p\t%d\t%p\n", auxiliar, auxiliar->valor, auxiliar->proximo);
			auxiliar = auxiliar->proximo;
		}
	}
}

void imprimeLista(Lista lista)
{
	No *auxiliar = lista.Inicio;

	if (verificaListaVazia(auxiliar))
	{
		return;
	}
	else
	{
		printf("Valor\tEndereco\tProximo");

		while (auxiliar)
		{
			printf("\n%d\t%p\t%p", auxiliar->valor, auxiliar, auxiliar->proximo);

			auxiliar = auxiliar->proximo;
		}

		printf("\n\n\n");
	}
}

void inserirNoInicio(Pilha *pilha, int valor)
{
	No *novoNo;
	novoNo = (No *)malloc(sizeof(No));
	if (novoNo == NULL)
	{
		printf("Erro ao alocar memoria.\n");
	}
	else
	{
		novoNo->valor = valor;
		novoNo->proximo = pilha->inicio;
		pilha->inicio = novoNo;
	}
}

void insereNoFim(Lista *lista, int valor)
{
	No *novoNo = malloc(sizeof(No));

	if (novoNo)
	{
		novoNo->valor = valor;
		novoNo->proximo = NULL;

		if (lista->Inicio == NULL)
		{
			lista->Inicio = novoNo;
			lista->Fim = novoNo;
		}
		else
		{
			lista->Fim->proximo = novoNo;
			lista->Fim = novoNo;
		}
	}
	else
	{
		printf("\n Erro ao alocar memoria");
	}
}

void removerNoInicio(Pilha *pilha)
{
	No *auxiliar = pilha->inicio;

	if (verificaListaVazia(pilha->inicio))
	{
		return;
	}

	pilha->inicio = auxiliar->proximo;
	free(auxiliar);
}

void desempilha(Lista *listaEncadeada, Pilha *pilha1, Pilha *pilha2)
{
	No *auxiliar1 = pilha1->inicio, *auxiliar2 = pilha2->inicio;

	if (verificaListaVazia(auxiliar1) && verificaListaVazia(auxiliar2))
	{
		printf("\nAs pilhas estao vazias:\n ");
	}
	else
	{

		while (auxiliar1 != NULL || auxiliar2 != NULL)
		{
			if (auxiliar1)
			{
				int valor1 = auxiliar1->valor;
				removerNoInicio(pilha1);
				insereNoFim(listaEncadeada, valor1);
				auxiliar1 = pilha1->inicio;
			}
			if (auxiliar2)
			{
				int valor2 = auxiliar2->valor;
				removerNoInicio(pilha2);
				insereNoFim(listaEncadeada, valor2);
				auxiliar2 = pilha2->inicio;
			}
		}
	}
}

int menu()
{
	int opcao;

	printf("\n1 - Inserir na pilha 1: ");
	printf("\n2 - Inserir na pilha 2: ");
	printf("\n3 - Desempilhar pilhas para a fila: ");
	printf("\n4 - Imprimir pilha 1: ");
	printf("\n5 - Imprimir pilha 2: ");
	printf("\n6 - Imprimir fila: ");
	printf("\n7 - sair: ");
	printf("\nEscolha uma opcao: ");
	scanf("%d", &opcao);

	while (opcao < 1 && opcao > 6)
	{
		printf("\nEscolha uma opcao valida: ");
		scanf("%d", &opcao);
	}

	return opcao;
}

int main()
{
	int loop = 0, valor;
	Lista listaEncadeada;
	Pilha pilha, pilha2;
	pilha.inicio = NULL;
	pilha2.inicio = NULL;
	listaEncadeada.Inicio = NULL;
	listaEncadeada.Fim = NULL;

	while (loop != 7)
	{
		switch (menu())
		{
		case 1:
			printf("\nInforme o valor: ");
			scanf("%d", &valor);
			inserirNoInicio(&pilha, valor);

			break;
		case 2:
			printf("\nInforme o valor: ");
			scanf("%d", &valor);
			inserirNoInicio(&pilha2, valor);

			break;
		case 3:
			printf("Desempilhando e criando fila");
			desempilha(&listaEncadeada, &pilha, &pilha2);

			break;
		case 4:
			imprimirPilhas(pilha);

			break;
		case 5:
			imprimirPilhas(pilha2);

			break;
		case 6:
			imprimeLista(listaEncadeada);
			break;
		case 7:
			loop = 7;

			break;
		}
	}
}
