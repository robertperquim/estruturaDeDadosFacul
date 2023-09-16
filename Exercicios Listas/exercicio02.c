/*Faça um código em C para criar uma lista encadeada, permitindo ao usuário digitar um valor, e
ao término você deve mostrar para eleo resultado:
 Endereço Valor Próximo
 Primeiro faça para um NO.
 Depois faça para 2 nós
 Depois faça para 3 nós
 Issofica bom???Qual a melhor alternativa?
● OBS: tente trabalhar comfunções
● OBS: faça um menu:inserir / imprimir /sair*/

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

void insereNoFim(No **ponteiroIncio, int valor)
{
    No *auxiliar, *novoNo = malloc(sizeof(No));

    if (novoNo)
    {
        novoNo->valor = valor;
        novoNo->proximo = NULL;

        if (*ponteiroIncio == NULL)
        {
            *ponteiroIncio = novoNo;
        }
        else
        {
            auxiliar = *ponteiroIncio;

            while (auxiliar->proximo != NULL)
            {
                auxiliar = auxiliar->proximo;
            }

            auxiliar->proximo = novoNo;
        }
    }
    else
    {
        printf("\nErro ao alocar memoria,");
    }
}

void insereNoIncio(No **ponteiroInicio, int valor)
{
    No *novoNo = malloc(sizeof(No));

    if (novoNo)
    {
        novoNo->valor = valor;
        novoNo->proximo = *ponteiroInicio;
        *ponteiroInicio = novoNo;
    }
    else
    {
        printf("\nErro ao alocar memoria,");
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
            auxiliar = auxiliar->proximo;
        }
    }
}

int menu()
{
    int opcao;

    printf("\n1 - Inserir no final da lista: ");
    printf("\n2 - Inserir no inicio da lista: ");
    printf("\n3 - Imprimir  ");
    printf("\n4- Sair ");
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
    No *ponteiroInicio;
    ponteiroInicio = NULL;

    while (loop != 4)
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
            imprime(ponteiroInicio);

            break;
        case 4:
            loop = 4;
            break;
        }
    }
}
