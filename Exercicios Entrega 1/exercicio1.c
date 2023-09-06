#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct NO_LISTA_ORDER
{
    int valor;
    struct NO_LISTA_ORDER *proximo;
} NO_LISTA_ORDER;

typedef struct NO_LISTA_RAND
{
    int valor;
    struct NO_LISTA_RAND *proximo;
} NO_LISTA_RAND;

void criaListaRandomica(NO_LISTA_RAND **listaRand)
{
    NO_LISTA_RAND *aux, *novoNo = malloc(sizeof(NO_LISTA_RAND));

    if (novoNo)
    {

        novoNo->valor = rand() % 100 + 1;
        novoNo->proximo = NULL;

        if (*listaRand == NULL)
        {
            *listaRand = novoNo;
        }
        else
        {
            aux = *listaRand;
            while (aux->proximo)
            {

                aux = aux->proximo;
            }
            aux->proximo = novoNo;
        }
    }
    else
    {
        printf("Erro ao gerar a lista");
    }
}

void criaListaRandomicaOrdenada(NO_LISTA_ORDER **listaOrder)
{
    NO_LISTA_ORDER *aux, *novoNo = malloc(sizeof(NO_LISTA_ORDER));

    if (novoNo)
    {
        novoNo->valor = rand() % 100 + 1;
        novoNo->proximo = NULL;

        if (*listaOrder == NULL || novoNo->valor < (*listaOrder)->valor)
        {
            novoNo->proximo = *listaOrder;
            *listaOrder = novoNo;
        }
        else
        {
            aux = *listaOrder;
            while ((aux->proximo) && (novoNo->valor > aux->proximo->valor))
            {
                aux = aux->proximo;
            }

            novoNo->proximo = aux->proximo;
            aux->proximo = novoNo;
        }
    }
    else
    {
        printf("Erro ao gerar a lista\n");
    }
}

void imprime(NO_LISTA_RAND *no)
{
    printf("\nlista 1\n\t valor\t endereco\t proximo ");

    while (no)
    {
        printf("\n\t %d\t %p\t %p ", no->valor, no, no->proximo);
        no = no->proximo;
    }

    printf("\n\n\n");
}

void imprime2(NO_LISTA_ORDER *no)
{
    printf("\nlista 2\n\t valor\t endereco\t proximo ");

    while (no)
    {
        printf("\n\t %d\t %p\t %p ", no->valor, no, no->proximo);
        no = no->proximo;
    }

    printf("\n\n\n");
}

int menu()
{

    int opcao;

    printf("Escolha uma opcao!!!");
    printf("\n1 - Gerar lista");
    printf("\n2 - Gerar lista ordenada");
    printf("\n3 - Buscar na lista");
    printf("\n4 - Imprimir lista");
    printf("\n5 - Sair");
    scanf("%d", &opcao);

    while (opcao < 1 || opcao > 5)
    {
        printf("\nInforme valores entre 1 e 5");
        scanf("%d", &opcao);
    }

    return opcao;
}

int main()
{
    NO_LISTA_RAND *listaRand = NULL;
    NO_LISTA_ORDER *listaOrder = NULL;

        int quantNum, controle = 0, dado;

    srand(time(NULL));

    while (controle == 0)
    {

        switch (menu())
        {
        case 1:

            printf("Quantos numeros vc deseja que a lista tenha?");
            scanf("%d", &quantNum);

            while (quantNum <= 2)
            {
                printf("A Lista não deve ter menos de 2 numeros");
                scanf("%d", &quantNum);
            }

            while (quantNum > 0)
            {
                criaListaRandomica(&listaRand);
                quantNum--;
            }

            printf("\nLista gerada com sucesso!!!!!!!!!!!!!!!!!!!!!!!!\n");

            break;

        case 2:
            printf("Quantos numeros vc deseja que a lista tenha?");
            scanf("%d", &quantNum);

            while (quantNum <= 2)
            {
                printf("A Lista não deve ter menos de 2 numeros");
                scanf("%d", &quantNum);
            }

            while (quantNum > 0)
            {

                criaListaRandomicaOrdenada(&listaOrder);
                quantNum--;
            }

            printf("\nLista gerada com sucesso!!!!!!!!!!!!!!!!\n\n");

            break;

        case 3:
            printf("\nEm qual lista deseja pesquisar");
            scanf("%d", &dado);
            break;

        case 4:

            imprime(listaRand);
            imprime2(listaOrder);

            break;

        case 5:
            controle = 1;
            break;
        }
    }
}
