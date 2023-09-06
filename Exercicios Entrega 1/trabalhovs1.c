#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Lucas Curtinaz

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
  printf("6 - inserir antes da posicao\n");
  printf("7 - remover antes da posicao\n");
  printf("8 - inserir ordenado\n");
  printf("9 - tornar lista circular\n");
  printf("10 - imprimir\n");
  printf("11 - sair\n");
  scanf("%d", &option);

  return option;
}

bool isListEmpty(Node *startPointer)
{
  if (startPointer == NULL)
  {
    printf("Lista vazia.\n");
    return true;
  }
  return false;
}

void printList(Node *startPointer)
{
  Node *auxPointer;
  auxPointer = startPointer;

  if (isListEmpty(startPointer))
  {
    return;
  }
  else
  {
    printf("Endereco\tValor\tProximo\n");
    while (auxPointer != NULL)
    {
      printf("%p\t%d\t%p\n", auxPointer, auxPointer->value, auxPointer->next);
      if (auxPointer->next == startPointer)
      {
        return;
      }
      auxPointer = auxPointer->next;
    }
  }
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
  Node *auxValuePointer, *auxPointer = startPointer;
  int auxValue;

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

void insertBeforePosition(Node **startPointer, int positionValue, int value)
{
  Node *linePointer, *prevAuxPointer, *actualAuxPointer, *auxPointer = *startPointer;

  if (isListEmpty(*startPointer))
  {
    return;
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

void removeBeforePosition(Node **startPointer, int positionValue)
{
  Node *prevPointer, *pointerToRemove, *auxPointer = *startPointer;

  if (isListEmpty(*startPointer))
  {
    return;
  }

  // TODO: ask what to do if list has only one element
  if (auxPointer->next == NULL)
  {
    printf("List has one element.\n");
    return;
  }

  while (auxPointer->next->next != NULL)
  {
    if (auxPointer->next->value == positionValue)
    {
      pointerToRemove = auxPointer;
      *startPointer = auxPointer->next;
      pointerToRemove = NULL;
      free(pointerToRemove);
      return;
    }

    if (auxPointer->next->next->value == positionValue)
    {
      prevPointer = auxPointer;
      pointerToRemove = auxPointer->next;
      prevPointer->next = auxPointer->next->next;
      pointerToRemove = NULL;
      free(pointerToRemove);
      return;
    }

    auxPointer = auxPointer->next;
  }
}

void orderedInsert(Node **startPointer, int value)
{
  Node *linePointer, *prevAuxPointer, *actualAuxPointer, *auxPointer = *startPointer;

  if (isListEmpty(*startPointer))
  {
    return;
  }

  linePointer = (Node *)malloc(sizeof(Node));
  if (linePointer == NULL)
  {
    printf("Erro ao alocar memoria.\n");
    return;
  }

  while (auxPointer->next != NULL)
  {
    if (auxPointer->next->value >= value)
    {
      prevAuxPointer = auxPointer;
      actualAuxPointer = auxPointer->next;

      linePointer->value = value;
      prevAuxPointer->next = linePointer;
      linePointer->next = actualAuxPointer;
      return;
    }

    auxPointer = auxPointer->next;
  }
}

void changeToCircular(Node **startPointer)
{
  Node *auxPointer = *startPointer;

  while (auxPointer->next != NULL)
  {
    auxPointer = auxPointer->next;
  }

  auxPointer->next = *startPointer;
}

int main()
{
  int option, value, positionValue;
  Node *linePointer, *startPointer;
  startPointer = NULL;

  while (option != 11)
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
      printf("inserir antes da posicao\n");
      printf("Digite um valor: ");
      scanf("%d", &value);
      printf("Digite um valor para posicao: ");
      scanf("%d", &positionValue);
      insertBeforePosition(&startPointer, positionValue, value);
      break;
    case 7:
      printf("remover antes da posicao\n");
      printf("Digite um valor para posicao: ");
      scanf("%d", &positionValue);
      removeBeforePosition(&startPointer, positionValue);
      break;
    case 8:
      printf("inserir ordenado\n");
      printf("Digite um valor para inserir ordenado: ");
      scanf("%d", &value);
      orderedInsert(&startPointer, value);
      break;
    case 9:
      changeToCircular(&startPointer);
      break;
    case 10:
      printf("imprimir\n");
      printList(startPointer);
      break;
    case 11:
      printf("sair\n");
      break;
    }
  }
}