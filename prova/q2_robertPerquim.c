/*verificar a quantidade de pessoas inseridas nas filas e ver onde a pessoa vai entrar na fila

	Sora eu entedi como deveria verificar automaticamente para onde a pessoa deveria ser inserida na fila
	bastava adicionar na menor fila, para manter o equilibrio.
s
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
	int tamanho;
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

void inserenasFilas(Lista *lista1, Lista *lista2, Lista *lista3, int senha)
{

	if (lista1->tamanho <= lista2->tamanho && lista1->tamanho <= lista3->tamanho)
	{
		printf("\nEntrou aqui");
		insereNoFim(lista1, senha);
		lista1->tamanho++;
		printf("\nVoce foi inserido na fila 1\n");
	}
	else if (lista2->tamanho <= lista3->tamanho)
	{
		insereNoFim(lista2, senha);
		lista2->tamanho++;
		printf("\nVoce foi inserido na fila 2\n");
	}
	else
	{
		insereNoFim(lista3, senha);
		lista3->tamanho++;
		printf("\nVoce foi inserido na fila 3\n");
	}
}

void removeFim(Lista *lista)
{
	No *auxiliar = lista->Inicio;

	if (verificaListaVaza(auxiliar))
	{

		return;
	}
	else
	{
		if (auxiliar->proximo == NULL)
		{
			lista->Inicio = NULL;
			free(auxiliar);
		}
		else
		{
			while (auxiliar->proximo->proximo != NULL)
			{
				auxiliar = auxiliar->proximo;
			}

			auxiliar->proximo = NULL;
			free(auxiliar->proximo);
			lista->Fim = auxiliar;
		}
	}
}

int menu()
{
	int opcao;

	printf("\n1 - Gerar senha e ir pra fila ");
	printf("\n2 - remover da fila 1 : ");
	printf("\n3 - remover da fila 2 : ");
	printf("\n4 - remover da fila 3 : ");
	printf("\n5 - Imprimir fila 1: ");
	printf("\n6 - Imprimir fila 2: ");
	printf("\n7 - Imprimir fila 3: ");
	printf("\n8 - sair: ");
	printf("\nEscolha uma opcao: ");
	scanf("%d", &opcao);

	while (opcao < 1 && opcao > 8)
	{
		printf("\nEscolha uma opcao valida: ");
		scanf("%d", &opcao);
	}

	return opcao;
}

int main()
{
	int loop = 0, senha;
	Lista lista1, lista2, lista3;
	lista1.Inicio = NULL;
	lista1.Fim = NULL;
	lista2.Inicio = NULL;
	lista2.Fim = NULL;
	lista3.Inicio = NULL;
	lista3.Fim = NULL;
	lista1.tamanho = 0;
	lista2.tamanho = 0;
	lista3.tamanho = 0;

	while (loop != 8)
	{
		switch (menu())
		{
		case 1:
			senha = rand() % 100 + 1;
			printf("\nSua senha e : %d ", senha);
			inserenasFilas(&lista1, &lista2, &lista3, senha);
			break;
		case 2:

			printf("\nRemover da lista 1\n");
			removeFim(&lista1);
			if (lista1.tamanho != 0)
			{
				lista1.tamanho--;
			}

			break;
		case 3:
			printf("\nRemover da lista 2\n");
			removeFim(&lista2);
			if (lista2.tamanho != 0)
			{
				lista2.tamanho--;
			}
			break;
		case 4:
			printf("\nRemover da lista 3\n");
			removeFim(&lista3);
			if (lista3.tamanho != 0)
			{
				lista3.tamanho--;
			}
			break;
		case 5:
			printf("\nImprimindo lista 1\n");
			imprime(lista1);
			break;
		case 6:
			printf("\nImprimindo lista 2\n");
			imprime(lista2);
			break;

		case 7:
			printf("\nImprimindo lista 3\n");
			imprime(lista3);

			break;
		case 8:
			loop = 8;
			break;
		}
	}
}
