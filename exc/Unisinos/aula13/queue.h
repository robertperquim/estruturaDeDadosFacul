/**
 * Classe/interface que define o comportamento de uma fila.
 */

#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

template <typename T>
class Queue {
    public:
        /**
         * Informa se a fila está vazia.
         */
        virtual bool isEmpty() = 0;

        /**
         * Informa se a fila está cheia.
         */
        virtual bool isFull() = 0;

        /**
         * Retorna a quantidade de elementos armazenados na fila.
         */
        virtual int numElements() = 0;

        /**
         * Insere um novo elemento na fila.
         */
        virtual int enqueue(T Element) = 0;

        /**
         * Retira um elemento da fila.
         */
        virtual int dequeue(T& result) = 0;

        /**
         * Informa qual é o primeiro elemento da fila.
         */
        virtual int front(T& result) = 0;

        /**
         * Informa qual é o último elemento da fila.
         */
        virtual int back(T& result) = 0;
};

#endif
