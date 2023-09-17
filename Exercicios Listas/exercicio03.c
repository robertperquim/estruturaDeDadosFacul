/*Faça um código em C que permite ao usuário criar uma lista com os seguintes dados: CPF usuário, Nome do curso, ano de início. Realize as seguintes operações utilizando funções:
    Inserir nó na lista – final
Imprimir a lista

OBS: Apresente os dados com a seguinte construção (endereço do nó, valores do nó, valor do próximo).

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No
{
    int anodeInicio;

    char nomedoCurso[30], cpf[12];

    struct No *proximo;
} No;

typedef struct Lista
{
    No *Inicio;
    No *Fim;
} Lista;

void insereAluno(Lista *listaEncadeada, char *cpf, char *nomeCurso, int anodeIinicio)
{
    No *novoNo = malloc(sizeof(No));

    if (novoNo)
    {
        strcpy(novoNo->cpf, cpf);
        strcpy(novoNo->nomedoCurso, nomeCurso);
        novoNo->anodeInicio = anodeIinicio;
        novoNo->proximo = NULL;

        if (listaEncadeada->Inicio == NULL)
        {
            listaEncadeada->Inicio = novoNo;
            listaEncadeada->Fim = novoNo;
        }
        else
        {

            listaEncadeada->Fim->proximo = novoNo;
            listaEncadeada->Fim = novoNo;
        }
    }
    else
    {
        printf("\nNao foi possivel cadastrar o aluno");
    }
}

int menu()
{
    int opcao;

    printf("\n1 - Registrar Aluno: ");
    printf("\n2 - Imprimir lista ");
    printf("\n3 - Sair ");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opcao);

    while (opcao < 1 && opcao > 2)
    {
        printf("\nEscolha uma opcao valida: ");
        scanf("%d", &opcao);
    }

    return opcao;
}

void imprimeLista(Lista listaEncadeada)
{
    No *auxiliar = listaEncadeada.Inicio;

    printf("\nEndereco\tCPF\t\tNome do curso\t\tAno de inicio\tproximo");

    while (auxiliar)
    {
        printf("\n%p\t%s\t%s\t\t%d\t\t%p", auxiliar, auxiliar->cpf, auxiliar->nomedoCurso, auxiliar->anodeInicio, auxiliar->proximo);
        auxiliar = auxiliar->proximo;
    }
}

int main()
{
    int loop = 0, anodeInicio;
    char nomeDoCurso[30], cpf[12];
    Lista listaEncadeada;
    listaEncadeada.Inicio = NULL;
    listaEncadeada.Fim = NULL;

    while (loop != 3)
    {
        switch (menu())
        {
        case 1:
            printf("\nInforme o cpf do aluno: ");
            scanf("\n");
            gets(cpf);
            printf("\nInforme o nome do curso: ");
            scanf("\n");
            gets(nomeDoCurso);
            printf("\nInforme o ano de inicio  ");
            scanf("%d", &anodeInicio);
            insereAluno(&listaEncadeada, cpf, nomeDoCurso, anodeInicio);

            break;
        case 2:

            imprimeLista(listaEncadeada);

            break;
        case 3:
            loop = 3;
            break;
        }
    }
}
