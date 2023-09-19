// Robert Perquim

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

void buscaValor(Lista *lista, int valor)
{
	No *auxiliar = lista->Inicio;
	int valorEncontrado, *enderecoEncontrado;

	if (verificaListaVaza(auxiliar))
	{
		return;
	}
	else
	{
		while (auxiliar != NULL && valorEncontrado != valor)
		{
			if (auxiliar->valor == valor)
			{
				valorEncontrado = auxiliar->valor;
				enderecoEncontrado = auxiliar;
			}
			auxiliar = auxiliar->proximo;
		}

		if (valorEncontrado == valor)
		{
			printf("\nO valor %d foi encotrado na posicao %p\n", valorEncontrado, enderecoEncontrado);
		}
		else
		{
			printf("\nO valor não foi encontrado na lista\n");
		}
	}
}

void removeIicio(Lista *lista)
{

	No *auxiliar = lista->Inicio;

	if (verificaListaVaza(auxiliar))
	{

		return;
	}
	else
	{
		lista->Inicio = auxiliar->proximo;
		free(auxiliar);
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
		}
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

void insereNoIncio(Lista *lista, int valor)
{
	No *novoNo = malloc(sizeof(No));

	if (novoNo)
	{
		novoNo->proximo = lista->Inicio;
		novoNo->valor = valor;
		lista->Inicio = novoNo;
	}
	else
	{
		printf("\n Erro ao alocar memoria");
	}
}

void insereAntesDoK(Lista *lista, int valor, int valorAntes)
{

	No *auxiliar = lista->Inicio, *novoNo, *ponteiroAnterior, *ponteiroAtual;

	if (verificaListaVaza(auxiliar))
	{
		return;
	}
	else
	{
		if (auxiliar->valor == valorAntes)
		{

			insereNoIncio(lista, valor);
		}

		while (auxiliar->proximo != NULL)
		{

			if (auxiliar->proximo->valor == valorAntes)
			{
				novoNo = (No *)malloc(sizeof(No));
				if (novoNo == NULL)
				{
					printf("Erro ao alocar memoria.\n");
				}
				else
				{
					ponteiroAnterior = auxiliar;
					ponteiroAtual = auxiliar->proximo;

					novoNo->valor = valor;
					ponteiroAnterior->proximo = novoNo;
					novoNo->proximo = ponteiroAtual;
				}

				return;
			}
			auxiliar = auxiliar->proximo;
		}
	}
}

void removeAntesDoK(Lista *lista, int valorAntes)
{

	No *auxiliar = lista->Inicio, *ponteiroAnterior, *ponteiroAtual, *ponteiroRemover;

	if (verificaListaVaza(auxiliar))
	{
		return;
	}
	else
	{
		if (auxiliar->valor == valorAntes)
		{

			printf("\nNão e possivel remover antes desse valor pois ele e o priemeiro da lista.\n");
		}
		if (auxiliar->proximo->valor == valorAntes)
		{
			removeIicio(lista);
			return;
		}

		while (auxiliar->proximo->proximo != NULL)
		{
			if (auxiliar->proximo->proximo->valor == valorAntes)
			{

				ponteiroAnterior = auxiliar;
				ponteiroRemover = auxiliar->proximo;
				ponteiroAtual = auxiliar->proximo->proximo;
				ponteiroAnterior->proximo = ponteiroAtual;
				ponteiroRemover = NULL;
				free(ponteiroRemover);
				return;
			}
			auxiliar = auxiliar->proximo;
		}
	}
}

void insereOrdenado(Lista *lista, int valor)
{
	No *auxiliar = lista->Inicio, *novoNo = malloc(sizeof(No));

	if (novoNo)
	{
		novoNo->valor = valor;
		novoNo->proximo = NULL;

		if (auxiliar == NULL || novoNo->valor < auxiliar->valor)
		{
			novoNo->proximo = lista->Inicio;
			lista->Inicio = novoNo;
		}
		else
		{

			while ((auxiliar->proximo) && (novoNo->valor > auxiliar->proximo->valor))
			{
				auxiliar = auxiliar->proximo;
			}

			novoNo->proximo = auxiliar->proximo;
			auxiliar->proximo = novoNo;
		}
	}
	else
	{
		printf("Erro ao alocar memoria\n");
	}
}

void listaCircular(Lista *lista)
{
	No *auxiliar = lista->Inicio;

	if (verificaListaVaza(auxiliar))
	{
		return;
	}
	else
	{
		if (auxiliar->proximo != NULL)
		{
			lista->Fim->proximo = lista->Inicio;
		}
		else
		{
			printf("\nNao e possivel tornar uma lista com apenas um elemento circular");
		}
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

			if (auxiliar->proximo == lista.Inicio)
			{
				return;
			}
			auxiliar = auxiliar->proximo;
		}

		printf("\n\n\n");
	}
}

int menu()
{
	int opcao;

	printf("\n1 - Inserir no final da lista: ");
	printf("\n2 - Inserir no inicio da lista: ");
	printf("\n3 - Excluir no final: ");
	printf("\n4 - Excluir no inicio: ");
	printf("\n5 - Buscar valor");
	printf("\n6 - Inserir antes do k (insere no meio) ");
	printf("\n7 - Remove antes do k (remove no meio) ");
	printf("\n8 - Insere Ordenado  ");
	printf("\n9 - Deixar a lista circular: ");
	printf("\n10 - Imprimir  ");
	printf("\n11- Sair ");
	printf("\nEscolha uma opcao: ");
	scanf("%d", &opcao);

	while (opcao < 1 && opcao > 11)
	{
		printf("\nEscolha uma opcao valida: ");
		scanf("%d", &opcao);
	}

	return opcao;
}

int main()
{
	int loop = 0, valor, valorAntes;
	Lista listaEncadeada;
	listaEncadeada.Inicio = NULL;
	listaEncadeada.Fim = NULL;

	while (loop != 11)
	{
		switch (menu())
		{
		case 1:
			printf("\nInserir no final!!!!!!");
			printf("\nInfomre o numero que deseja inserir:");
			scanf("%d", &valor);
			insereNoFim(&listaEncadeada, valor);
			break;
		case 2:

			printf("\nInserir no Iniciol!!!!!!");
			printf("\nInfomre o numero que deseja inserir::");
			scanf("%d", &valor);
			insereNoIncio(&listaEncadeada, valor);

			break;
		case 3:

			printf("\nRemove FIm!!!!!!\n\n");
			removeFim(&listaEncadeada);

			break;
		case 4:
			printf("\nRemove Inicio!!!!!!\n\n");
			removeIicio(&listaEncadeada);
			break;
		case 5:

			printf("\nBusca valor!!!!!!");
			printf("\nInforme o valor que deseja buscar na lista");
			scanf("%d", &valor);
			buscaValor(&listaEncadeada, valor);

			break;
		case 6:
			printf("\nInserir antes do K !!!!!!");
			printf("\nInforme o valor que deseja inserir: ");
			scanf("%d", &valor);
			printf("\nInforme o valor em que deseja inserir antes: ");
			scanf("%d", &valorAntes);
			insereAntesDoK(&listaEncadeada, valor, valorAntes);

			break;
		case 7:
			printf("\nRemove antes do K !!!!!!");
			printf("\nInforme o valor em que deseja remover antes: ");
			scanf("%d", &valorAntes);
			removeAntesDoK(&listaEncadeada, valorAntes);

			break;
		case 8:
			printf("\nInserir Ordenado!!!!!!");
			printf("\nInfomre o numero que deseja inserir:::");
			scanf("%d", &valor);
			insereOrdenado(&listaEncadeada, valor);
			break;
		case 9:
			printf("\nDeixar a lista circular");
			listaCircular(&listaEncadeada);
			break;
		case 10:
			imprime(listaEncadeada);
			break;

		default:
			loop = 11;
			break;
		}
	}
}
