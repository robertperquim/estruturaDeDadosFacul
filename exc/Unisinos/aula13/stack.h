/**
 * Classe/interface que define o comportamento de uma pilha.
 */

#ifndef STACK_H
#define STACK_H

using namespace std;

template <typename T>
class Stack {
    public:
        /**
         * Informa se a pilha está vazia.
         */
        virtual bool isEmpty() = 0;

        /**
         * Informa se a pilha está cheia.
         */
        virtual bool isFull() = 0;

        /**
         * Informa a quantidade de elementos armazenados na pilha.
         */
        virtual int numElements() = 0;

        /**
         * Adiciona um novo elemento na pilha.
         */
        virtual int push(T element) = 0;

        /**
         * Retira um elemento da pilha.
         */
        virtual int pop(T& result) = 0;

        /**
         * Informa qual é o elemento do topo da pilha.
         */
        virtual int return_top(T& result) = 0;
};

#endif
