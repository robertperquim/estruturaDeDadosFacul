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

	printf("1 - inserir no inicio\n");
	printf("2 - excluir no inicio\n");
	printf("3 - voltar\n");
	printf("4 - voltar ao contrario\n");
	printf("5 - imprimir\n");
	printf("6 - imprimir pilha 2\n");
	printf("7 - sair\n");
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

void goBack(Pilha *pilha, Pilha *pilha2)
{
	No *auxiliar = pilha->inicio;
	int valor = auxiliar->valor;

	removerNoInicio(pilha);
	inserirNoInicio(pilha2, valor);
}

int main()
{
	int opcao, valor;
	Pilha pilha, pilha2;
	pilha.inicio = NULL;
	pilha2.inicio = NULL;

	while (opcao != 7)
	{
		opcao = menu();
		switch (opcao)
		{
		case 1:
			printf("Informe o valor: ");
			scanf("%d", &valor);
			inserirNoInicio(&pilha, valor);
			break;
		case 2:
			printf("excluir no inicio\n");
			removerNoInicio(&pilha);
			break;
		case 3:
			goBack(&pilha, &pilha2);
			break;
		case 4:
			goBack(&pilha2, &pilha);
			break;
		case 5:
			printf("imprimir\n");
			imprimir(pilha);
			break;
		case 6:
			printf("imprimir pilha 2\n");
			imprimir(pilha2);
			break;
		case 7:
			printf("sair\n");
			break;
		}
	}
}