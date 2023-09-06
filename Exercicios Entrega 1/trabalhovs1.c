#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

int menu()
{
    int option;

    printf("1 - inserir no final\n");
    printf("2 - inserir no inicio\n");
    printf("3 - excluir no final\n");
    printf("4 - excluir no inicio\n");
    printf("5 - buscar valor\n");
    printf("6 - inserir antes do valor\n");
    printf("7 - imprimir\n");
    printf("8 - sair\n");
    scanf("%d", &option);

    return option;
}

void printList(Node *startPointer)
{
    Node *auxPointer;
    auxPointer = startPointer;

    if (startPointer == NULL)
    {
        printf("Lista vazia.\n");
    }
    else
    {
        printf("Endereco\tValor\tProximo\n");
        while (auxPointer != NULL)
        {
            printf("%p\t%d\t%p\n", auxPointer, auxPointer->value, auxPointer->next);
            auxPointer = auxPointer->next;
        }
    }
}

bool isListEmpty(Node *startPointer)
{
    if (startPointer == NULL)
    {
        return true;
    }
    return false;
}

void insertOnStart(int value, Node **startPointer, Node *linePointer)
{
    linePointer->next = *startPointer;
    linePointer->value = value;
    *startPointer = linePointer;
}

void insertOnEnd(int value, Node **startPointer, Node *linePointer)
{
    Node *auxPointer;

    linePointer->value = value;
    linePointer->next = NULL;

    if (*startPointer == NULL)
    {
        *startPointer = linePointer;
    }
    else
    {
        auxPointer = *startPointer;
        while (auxPointer->next != NULL)
        {
            auxPointer = auxPointer->next;
        }
        auxPointer->next = linePointer;
    }
}

void removeOnFinal(Node **startPointer)
{
    Node *auxPointer = *startPointer;

    if (auxPointer == NULL)
    {
        printf("Lista vazia.\n");
    }
    else if (auxPointer->next == NULL)
    {
        *startPointer = NULL;
        free(auxPointer);
    }
    else
    {
        while (auxPointer->next->next != NULL)
        {
            auxPointer = auxPointer->next;
        }

        free(auxPointer->next);
        auxPointer->next = NULL;
    }
}

void removeOnStart(Node **startPointer)
{
    Node *auxPointer = *startPointer;

    if (auxPointer == NULL)
    {
        printf("Lista vazia.\n");
    }
    else if (auxPointer->next == NULL)
    {
        *startPointer = NULL;
        free(auxPointer);
    }
    else
    {
        *startPointer = auxPointer->next;
        free(auxPointer);
    }
}

void search(Node *startPointer, int value)
{
    Node *auxPointer = startPointer;
    int auxValue, *auxValuePointer;

    if (auxPointer == NULL)
    {
        printf("Lista vazia.\n");
    }
    else
    {
        while (auxPointer != NULL && auxValue != value)
        {
            if (auxPointer->value == value)
            {
                auxValue = auxPointer->value;
                auxValuePointer = auxPointer;
            }
            auxPointer = auxPointer->next;
        }

        if (auxValue == value)
        {
            printf("Valor %d encontrado em %p! \n", auxValue, auxValuePointer);
        }
        else
        {
            printf("Valor nao encontrado! \n");
        }
    }
}

void insertOnPosition(Node **startPointer, int positionValue, int value)
{
    Node *linePointer, *prevAuxPointer, *actualAuxPointer, *auxPointer = *startPointer;

    if (isListEmpty(startPointer))
    {
        printf("Lista vazia. \n");
    }

    while (auxPointer->next != NULL)
    {
        if (auxPointer->next->value == positionValue)
        {
            linePointer = (Node *)malloc(sizeof(Node));
            if (linePointer == NULL)
            {
                printf("Erro ao alocar memoria.\n");
            }
            else
            {
                prevAuxPointer = auxPointer;
                actualAuxPointer = auxPointer->next;

                linePointer->value = value;
                prevAuxPointer->next = linePointer;
                linePointer->next = actualAuxPointer;
            }

            return;
        }

        auxPointer = auxPointer->next;
    }
}

int main()
{
    int option, value;
    Node *linePointer, *startPointer;
    startPointer = NULL;

    while (option != 8)
    {
        option = menu();
        switch (option)
        {
        case 1:
            printf("inserir no final\n");
            linePointer = (Node *)malloc(sizeof(Node));
            if (linePointer == NULL)
            {
                printf("Erro ao alocar memoria.\n");
            }
            else
            {
                printf("Informe o valor: ");
                scanf("%d", &value);
                insertOnEnd(value, &startPointer, linePointer);
            }
            break;
        case 2:
            printf("inserir no inicio\n");
            linePointer = (Node *)malloc(sizeof(Node));
            if (linePointer == NULL)
            {
                printf("Erro ao alocar memoria.\n");
            }
            else
            {
                printf("Informe o valor: ");
                scanf("%d", &value);
                insertOnStart(value, &startPointer, linePointer);
            }
            break;
        case 3:
            printf("excluir no final\n");
            removeOnFinal(&startPointer);
            break;
        case 4:
            printf("excluir no inicio\n");
            removeOnStart(&startPointer);
            break;
        case 5:
            printf("buscar valor\n");
            printf("Digite um valor: ");
            scanf("%d", &value);
            search(startPointer, value);
            break;
        case 6:
            printf("inserir antes do valor\n");
            int positionValue;
            printf("Digite um valor: ");
            scanf("%d", &value);
            printf("Digite um valor para posicao: ");
            scanf("%d", &positionValue);
            insertOnPosition(&startPointer, positionValue, value);
            break;
        case 7:
            printf("imprimir\n");
            printList(startPointer);
            break;
        case 8:
            printf("sair\n");
            break;
        }
    }
}