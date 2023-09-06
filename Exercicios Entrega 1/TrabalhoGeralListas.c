#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No
{

    int valor;
    struct No *proximo;

} No;

bool verificaListaVaza(No *ponteroInicio)
{
    if (ponteroInicio == NULL)
    {
        printf("\nLista vazia!!!!!\n\n");
        return true;
    }
    return false;
}

void removeIicio(No **ponteiroInicio)
{

    No *auxilar = *ponteiroInicio;

    if (verificaListaVaza(auxilar))
    {

        return;
    }
    else
    {
        if (auxilar->proximo == NULL)
        {
            *ponteiroInicio = NULL;
            free(auxilar);
        }
        else
        {
            *ponteiroInicio = auxilar->proximo;
            free(auxilar);
        }
    }
}

void removeFim(No **ponteiroInicio)
{
    No *auxilar = *ponteiroInicio;

    if (verificaListaVaza(auxilar))
    {

        return;
    }
    else
    {
        if (auxilar->proximo == NULL)
        {
            *ponteiroInicio = NULL;
            free(auxilar);
        }
        else
        {
            while (auxilar->proximo->proximo != NULL)
            {
                auxilar = auxilar->proximo;
            }

            auxilar->proximo = NULL;
            free(auxilar->proximo);
        }
    }
}

void insereNoFim(No **ponteiroInicio, int valor)
{
    No *auxiliar, *novoNo = malloc(sizeof(No));

    if (novoNo)
    {
        novoNo->valor = valor;
        novoNo->proximo = NULL;

        if (*ponteiroInicio == NULL)
        {
            *ponteiroInicio = novoNo;
        }
        else
        {
            auxiliar = *ponteiroInicio;
            while (auxiliar->proximo != NULL)
            {
                auxiliar = auxiliar->proximo;
            }

            auxiliar->proximo = novoNo;
        }
    }
    else
    {
        printf("\n Erro ao alocar memoria");
    }
}

void insereNoIncio(No **ponteiroInicio, int valor)
{
    No *novoNo = malloc(sizeof(No));

    if (novoNo)
    {
        novoNo->proximo = *ponteiroInicio;
        novoNo->valor = valor;
        *ponteiroInicio = novoNo;
    }
    else
    {
        printf("\n Erro ao alocar memoria");
    }
}

void imprime(No *ponteiroInicio)
{

    printf("Valor\tEndereco\tProximo");

    while (ponteiroInicio)
    {
        printf("\n%d\t%p\t%p", ponteiroInicio->valor, ponteiroInicio, ponteiroInicio->proximo);
        ponteiroInicio = ponteiroInicio->proximo;
    }

    printf("\n\n\n");
}

int menu()
{
    int opcao;

    printf("\n1 - Inserir no final da lista: ");
    printf("\n2 - Inserir no inicio da lista: ");
    printf("\n3 - Excluir no final: ");
    printf("\n4 - Excluir no inicio: ");
    printf("\n5 - Buscar valor  ");
    printf("\n6 - Inserir antes de>>> ");
    printf("\n7 - Imprimir  ");
    printf("\n - Sair ");
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
    int loop = 0, valor;
    No *ponteiroInicio;
    ponteiroInicio = NULL;

    while (loop != 8)
    {
        switch (menu())
        {
        case 1:
            printf("\nInserir no final!!!!!!");
            printf("\nInfomre o numero que deseja inserir::::::");
            scanf("%d", &valor);
            insereNoFim(&ponteiroInicio, valor);
            break;
        case 2:

            printf("\nInserir no Iniciol!!!!!!");
            printf("\nInfomre o numero que deseja inserir::::::");
            scanf("%d", &valor);
            insereNoIncio(&ponteiroInicio, valor);

            break;
        case 3:

            printf("\nRemove Fim!!!!!!");
            removeFim(&ponteiroInicio);

            break;
        case 4:
            printf("\nRemove Fim!!!!!!");
            removeIicio(&ponteiroInicio);
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 7:
            imprime(ponteiroInicio);
            break;

        default:
            loop = 8;
            break;
        }
    }
}
