#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No
{
	int valor;
	struct No *proximo;
} No;

typedef struct Pilha
{
	No *inicio;
} Pilha;

int menu()
{
	int opcao;

	printf("1 - inserir carro\n");
	printf("2 - Retirar carro\n");
	printf("3 - imprimir\n");
	printf("4 - imprimir pilha 2\n");
	printf("5 - sair\n");
	scanf("%d", &opcao);

	return opcao;
}

bool verificaListaVazia(No *ponteiroInicio)
{
	if (ponteiroInicio == NULL)
	{
		printf("Lista vazia.\n");
		return true;
	}
	return false;
}

void imprimir(Pilha pilha)
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

bool buscarValor(Pilha pilha, int valor)
{

	No *auxiliar = pilha.inicio;

	while (auxiliar)
	{
		if (auxiliar->valor == valor)
		{
			return true;
		}

		auxiliar = auxiliar->proximo;
	}

	return false;
}

void goBack(Pilha *pilha, Pilha *pilha2, int valor_p)
{
	No *auxiliar = pilha->inicio;

	if (buscarValor(*pilha, valor_p))
	{

		while (auxiliar != NULL && auxiliar->valor != valor_p)
		{

			int valor = auxiliar->valor;
			removerNoInicio(pilha);
			inserirNoInicio(pilha2, valor);
			auxiliar = pilha->inicio;
		}

		printf("\nCarros movidos para a pilha 2\n");
		imprimir(*pilha2);
		printf("\nComo se encontra os carros na pilha 1\n");
		imprimir(*pilha);
		printf("\nRetirando carro selecionado:");
		removerNoInicio(pilha);

		printf("\nCarro retirado:");
		printf("\nMovendo carros de vola para pilha 1:\n");

		while (pilha2->inicio != NULL)
		{
			int valor2 = pilha2->inicio->valor;
			removerNoInicio(pilha2);
			inserirNoInicio(pilha, valor2);
		}

		printf("\nPilha 2 :\n");
		imprimir(*pilha2);
		printf("\nPilha 1 :\n");
		imprimir(*pilha);
	}
	else
	{
		printf("Valor nao encontrado na pilha.\n");
	}
}

int main()
{
	int opcao, valor;
	Pilha pilha, pilha2;
	pilha.inicio = NULL;
	pilha2.inicio = NULL;

	while (opcao != 5)
	{
		opcao = menu();
		switch (opcao)
		{
		case 1:
			printf("Informe o carro: ");
			scanf("%d", &valor);
			inserirNoInicio(&pilha, valor);
			break;
		case 2:
			printf("Informe o carro: ");
			scanf("%d", &valor);
			goBack(&pilha, &pilha2, valor);
			break;
		case 3:
			printf("imprimir\n");
			imprimir(pilha);
			break;
		case 4:
			printf("imprimir pilha 2\n");
			imprimir(pilha2);
			break;
		case 5:
			printf("sair\n");
			break;
				}
	}
}