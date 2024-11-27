/**
 * Implementação de uma fila com armazenamento estático 
 * usando vetor (array unidimensional).
 */

#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <iostream>
#include "queue.h"
#include "staticStack.h"

using namespace std;

template <typename T>
class StaticQueue: public Queue<T> {
    protected:
        // Índice para o primeiro elemento
        int first;

        // Índice para o segundo elemento
        int last;

        // Tamanho da fila
        int size;

        // Array que armazena as referências para os elementos
        T* elements;
    public:
        /**
         * Constrói uma fila com tamanho máximo
         */
        StaticQueue(int max_size);

        bool isEmpty();
        bool isFull();
        int numElements();
        int enqueue(T element);
        int dequeue(T& result);
        int front(T& result);
        int back(T& result);
        bool contains(T element);
        void flip();
        int enqueueWithPriority(T element);
};

template <typename T>
StaticQueue<T>::StaticQueue(int max_size) {
    elements = new T[max_size];
    size = max_size;
    first = -1;
    last = -1;
}

template <typename T>
bool StaticQueue<T>::isEmpty() {
    return first == -1;
}

template <typename T>
bool StaticQueue<T>::isFull() {
    return last == ((last + 1) % size);
}

template <typename T>
int StaticQueue<T>::numElements() {
    if(isEmpty())
        return 0;
    else {
        int n = size;
        return ((n + last + first) % n) + 1;
    }
}

/** 
* Retorna 0 se o elemento foi inserido da fila.
* Retorna 2 se a fila estiver cheia.
*/
template <typename T>
int StaticQueue<T>::enqueue(T element) {
    if(isFull())
        return 2;
    else {
        if(last == -1) {
            first = 0;
            last = 0;
        }
        else
            last = (last + 1) % size;

        elements[last] = element;

        return 0;
    }
}

/** 
* Retorna 0 se o elemento foi removido da fila.
* Retorna 3 se a fila estiver vazia.
*/
template <typename T>
int StaticQueue<T>::dequeue(T& result) {
    if(isEmpty())
        return 3;
    else {
        result = elements[first];
        if(first == last) {
            first = -1;
            last = -1;
        }
        else {
            first = (first + 1) % size;
        }
        
        return 0;
    }
}

/** 
* Retorna 0 se a lista não estiver vazia.
* Retorna 3 se a fila estiver vazia.
*/
template <typename T>
int StaticQueue<T>::front(T& result) {
    if(isEmpty())
        return 3;
    else {
        result = elements[first];
        return 0;
    }
}

/** 
* Retorna 0 se a lista não estiver vazia.
* Retorna 3 se a fila estiver vazia.
*/
template <typename T>
int StaticQueue<T>::back(T& result) {
    if(isEmpty())
        return 3;
    else {
        result = elements[last];
        return 0;
    }
}

/**
 * Exercício 3
 * Informa se a fila contém um determinado elemento.
 * Retorna true ou false.
 */
template <typename T> 
bool StaticQueue<T>::contains(T element){
    if(isEmpty())
    {
        return false;
    }
    
    for (int i = 0; i < numElements(); i++)
    {
        if (elements[i] == element)
        {
           return true;
        }
        
    }

    return false;
}
/**
 * Exercício 4
 * Inverte a ordem dos elementos da fila.
 */
template <typename T> 
void StaticQueue<T>::flip(){
  int initial = -1;
  int& result = initial;
  StaticStack<T> temp(size);

  while (!isEmpty())
  {
    dequeue(result);
    temp.push(result);
  }
  
  while (!temp.isEmpty())
  {
    temp.pop(result);
    enqueue(result);
  }
  
}

/**
 * Exercício 5
 * Insere um elemento na primeira posição da fila.
 * Retorna 0 se o elemento for inserido.
 * Retorna 2 se a fila estiver cheia.
 */
template <typename T> 
int StaticQueue<T>::enqueueWithPriority(T element){
    if (isFull())
    {
        return 2;
    }
    
    first = (first + size - 1) % size;
    elements[first] = element;

    return 0;
}



#endif
