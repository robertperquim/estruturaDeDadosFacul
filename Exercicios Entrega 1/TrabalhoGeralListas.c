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

void buscaValor(No **ponteiroInicio, int valor)
{
    No *auxilar = *ponteiroInicio;
    int valorEncontrado, *enderecoEncontrado;

    if (verificaListaVaza(auxilar))
    {
        return;
    }
    else
    {
        while (auxilar != NULL && valorEncontrado != valor)
        {
            if (auxilar->valor == valor)
            {
                valorEncontrado = auxilar->valor;
                enderecoEncontrado = auxilar;
            }
            auxilar = auxilar->proximo;
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

void insereAntesDoK(No **ponteiroInicio, int valor, int valorAntes)
{

    No *auxilar = *ponteiroInicio, *novoNo, *ponteiroAnterior, *ponteiroAtual;

    if (verificaListaVaza(auxilar))
    {
        return;
    }
    else
    {
        if (auxilar->valor == valorAntes)
        {

            insereNoIncio(ponteiroInicio, valor);
        }

        while (auxilar->proximo != NULL)
        {
            if (auxilar->proximo->valor == valorAntes)
            {
                novoNo = (No *)malloc(sizeof(No));
                if (novoNo == NULL)
                {
                    printf("Erro ao alocar memoria.\n");
                }
                else
                {
                    ponteiroAnterior = auxilar;
                    ponteiroAtual = auxilar->proximo;

                    novoNo->valor = valor;
                    ponteiroAnterior->proximo = novoNo;
                    novoNo->proximo = ponteiroAtual;
                }

                return;
            }
            auxilar = auxilar->proximo;
        }
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
    printf("\n5 - Buscar valor");
    printf("\n6 - Inserir antes do k ");
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
    int loop = 0, valor, valorAntes;
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

            printf("\nRemove FIm!!!!!!\n\n");
            removeFim(&ponteiroInicio);

            break;
        case 4:
            printf("\nRemove Inicio!!!!!!\n\n");
            removeIicio(&ponteiroInicio);
            break;
        case 5:

            printf("\nBusca valor!!!!!!\n\n");
            printf("\nInforme o valor que deseja buscar na lista\n\n");
            scanf("%d", &valor);
            buscaValor(&ponteiroInicio, valor);

            break;
        case 6:
            printf("\nInserir antes do K !!!!!!\n\n");
            printf("\nInforme o valor que deseja inserir: \n\n");
            scanf("%d", &valor);
            printf("\nInforme o valor em que deseja inserir antes: \n\n");
            scanf("%d", &valorAntes);
            insereAntesDoK(&ponteiroInicio, valor, valorAntes);

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
