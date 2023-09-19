/*Problema:
		Cria uma lista com n numeros - pedir para o usuario digitar um valor que ira ser
		somado nos numeros das listas ele deve ser inserido no final da fila, volta para o menu;


		Nao fiz validacao nos inputs sora

		minha ideia principal foi criar a funcao de inserir no fim
		depois de ter a lista criada pedir o valor que vou somar
		no caso so consigo somar se a lista nao estiver vazia.
		Somo o valor em todos os valores da lista depois só chamo a funcao de inserir no fim insiro o valor no fim;

		Ele volta para o menu podendo escolher se quer inserir mais valores ou adicionar outro valor para somar

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

bool verificaListaVaza(No *ponteroInicio)
{
	if (ponteroInicio == NULL)
	{
		printf("\nLista vazia!!!!!\n\n");
		return true;
	}
	return false;
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

void imprime(Lista lista)
{
	No *auxiliar = lista.Inicio;

	if (verificaListaVaza(auxiliar))
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

void somaValor(Lista *lista, int valor)
{

	if (verificaListaVaza(lista->Inicio))
	{
		return;
	}
	else
	{
		No *auxiliar = lista->Inicio;

		while (auxiliar)
		{
			auxiliar->valor = auxiliar->valor + valor;
			auxiliar = auxiliar->proximo;
		}

		insereNoFim(lista, valor);

		printf("\nLista ja somada com os valores: valor que foi somado: %d\n", valor);
	}
}

int menu()
{
	int opcao;

	printf("\n1 - Inserir na lista: ");
	printf("\n2 - Somar na lista: ");
	printf("\n3 - Imprimir: ");
	printf("\n4 - sair: ");
	printf("\nEscolha uma opcao: ");
	scanf("%d", &opcao);

	while (opcao < 1 && opcao > 4)
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
	listaEncadeada.Inicio = NULL;
	listaEncadeada.Fim = NULL;

	while (loop != 4)
	{
		switch (menu())
		{
		case 1:
			printf("\nInserir no lista");
			printf("\nInfomre o numero que deseja inserir:");
			scanf("%d", &valor);
			insereNoFim(&listaEncadeada, valor);
			printf("\nValor inserido:");
			break;
		case 2:

			printf("\nInfomre o numero que deseja somar:");
			scanf("%d", &valor);
			somaValor(&listaEncadeada, valor);
			imprime(listaEncadeada);

			break;
		case 3:
			imprime(listaEncadeada);
			break;
		case 4:
			loop = 4;
			break;
		}
	}
}
