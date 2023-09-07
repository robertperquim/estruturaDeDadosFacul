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
    No *auxiliar = *ponteiroInicio;
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

void removeIicio(No **ponteiroInicio)
{

    No *auxiliar = *ponteiroInicio;

    if (verificaListaVaza(auxiliar))
    {

        return;
    }
    else
    {
        if (auxiliar->proximo == NULL)
        {
            *ponteiroInicio = NULL;
            free(auxiliar);
        }
        else
        {
            *ponteiroInicio = auxiliar->proximo;
            free(auxiliar);
        }
    }
}

void removeFim(No **ponteiroInicio)
{
    No *auxiliar = *ponteiroInicio;

    if (verificaListaVaza(auxiliar))
    {

        return;
    }
    else
    {
        if (auxiliar->proximo == NULL)
        {
            *ponteiroInicio = NULL;
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

    No *auxiliar = *ponteiroInicio, *novoNo, *ponteiroAnterior, *ponteiroAtual;

    if (verificaListaVaza(auxiliar))
    {
        return;
    }
    else
    {
        if (auxiliar->valor == valorAntes)
        {

            insereNoIncio(ponteiroInicio, valor);
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

void removeAntesDoK(No **ponteiroInicio, int valorAntes)
{

    No *auxiliar = *ponteiroInicio, *ponteiroAnterior, *ponteiroAtual, *ponteiroRemover;

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
            removeIicio(ponteiroInicio);
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

void insereOrdenado(No **ponteiroInicio, int valor)
{
    No *auxiliar = *ponteiroInicio, *novoNo = malloc(sizeof(No));

    if (novoNo)
    {
        novoNo->valor = valor;
        novoNo->proximo = NULL;

        if (auxiliar == NULL || novoNo->valor < auxiliar->valor)
        {
            novoNo->proximo = *ponteiroInicio;
            *ponteiroInicio = novoNo;
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

void listaCircular(No **ponteiroInicio)
{
    No *auxiliar = *ponteiroInicio;

    if (verificaListaVaza(auxiliar))
    {
        return;
    }
    else
    {
        if (auxiliar->proximo != NULL)
        {
            while (auxiliar->proximo != NULL)
            {
                auxiliar = auxiliar->proximo;
            }

            auxiliar->proximo = *ponteiroInicio;

            printf("\nSua lista agora e circular");
        }
        else
        {
            printf("\nNao e possivel tornar uma lista com apenas um elemento circular");
        }
    }
}

void imprime(No *ponteiroInicio)
{
    No *auxiliar = ponteiroInicio;

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

            if (auxiliar->proximo == ponteiroInicio)
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
    No *ponteiroInicio;
    ponteiroInicio = NULL;

    while (loop != 11)
    {
        switch (menu())
        {
        case 1:
            printf("\nInserir no final!!!!!!");
            printf("\nInfomre o numero que deseja inserir:");
            scanf("%d", &valor);
            insereNoFim(&ponteiroInicio, valor);
            break;
        case 2:

            printf("\nInserir no Iniciol!!!!!!");
            printf("\nInfomre o numero que deseja inserir::");
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

            printf("\nBusca valor!!!!!!");
            printf("\nInforme o valor que deseja buscar na lista");
            scanf("%d", &valor);
            buscaValor(&ponteiroInicio, valor);

            break;
        case 6:
            printf("\nInserir antes do K !!!!!!");
            printf("\nInforme o valor que deseja inserir: ");
            scanf("%d", &valor);
            printf("\nInforme o valor em que deseja inserir antes: ");
            scanf("%d", &valorAntes);
            insereAntesDoK(&ponteiroInicio, valor, valorAntes);

            break;
        case 7:
            printf("\nRemove antes do K !!!!!!");
            printf("\nInforme o valor em que deseja remover antes: ");
            scanf("%d", &valorAntes);
            removeAntesDoK(&ponteiroInicio, valorAntes);

            break;
        case 8:
            printf("\nInserir Ordenado!!!!!!");
            printf("\nInfomre o numero que deseja inserir:::");
            scanf("%d", &valor);
            insereOrdenado(&ponteiroInicio, valor);
            break;
        case 9:
            printf("\nDeixar a lista circular");
            listaCircular(&ponteiroInicio);
            break;
        case 10:
            imprime(ponteiroInicio);
            break;

        default:
            loop = 11;
            break;
        }
    }
}
