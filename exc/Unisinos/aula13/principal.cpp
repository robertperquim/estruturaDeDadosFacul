/**
 * Código exemplo para uso das estruturas:
 * StaticList, StaticQueue e StaticStack
 */

#include <iostream>
#include "staticList.h"
#include "staticQueue.h"
#include "staticStack.h"

using namespace std;

/**
 * Exercício 7
 */

void reverseStack(StaticStack<int>* s){
    StaticStack<int> saux1(s->numElements());
    StaticStack<int> saux2(s->numElements());

    int result;

    while (!s->isEmpty())
    {
        s->pop(result);
        saux1.push(result);
    }

    while (!saux1.isEmpty())
    {
        saux1.pop(result);
        saux2.push(result);
    }
    
    while (!saux2.isEmpty())
    {
        saux2.pop(result);
        s->push(result);
    }
    
}
/**
 * Exercício 8
 */
void findElement(StaticStack<int> s, int element){
    if (s.isEmpty())
    {
        cout << "Pilha vazia" << endl;
    }else{
        StaticStack<int> saux(s.numElements());

        int p = s.numElements() - 1;
        int result;
        while (!s.isEmpty())
        {
            s.return_top(result);
            if (result == element)
            {
                break;
            }else{
                s.pop(result);
                saux.push(result);
                --p;
            }
            
        }
        while (!saux.isEmpty())
        {
            saux.pop(result);
            s.push(result);
        }
        
        if (p > -1 )
        {
          cout << "Elemento encontrado na posicao " << p << endl;
        }
        else{
            cout << "Elemento nao encotrado" << endl;
        } 
        
    }
    
}



int main() {
    StaticList<int> sl(10);  // Cria uma lista estática de tipo int com 10 posições
    StaticQueue<int> sq(10); // Cria uma fila estátia de tipo int com 10 posições
    StaticStack<int> ss(10); // Cria uma pilha estática de tipo int com 10 posições

    /**
     * Testes com listas
     */

    sl.insert(1, 0);
    sl.insert(2, 1);
    sl.insert(3, 2);
    sl.insert(4, 3);
    sl.insert(5, 4);
    sl.insert(2, 5);
    sl.insert(2, 2);
    
    cout << "Lista antes de aplicar a função dedup():" << endl;
    int r1;
    for(int i = 0; i < sl.numElements(); i++) {
        sl.get(i, r1);
        cout << r1 << " ";
    }
    cout << "\n\n";

    cout << "Lista após aplicar a função dedup():" << endl;
    sl.dedup();
    for(int i = 0; i < sl.numElements(); i++) {
        sl.get(i, r1);
        cout << r1 << " ";
    }
    cout << "\n\n";

    sl.remove_interval(0, 2);
    cout << "Lista após remover os elementos entre as posições 0 e 2:" << endl;
    int r2;
    for(int i = 0; i < sl.numElements(); i++) {
        sl.get(i, r2);
        cout << r2 << " ";
    }
    cout << "\n\n";

    /**
     * Testes com filas
     */
    sq.enqueue(1);
    sq.enqueue(2);
    sq.enqueue(3);
    sq.enqueue(4);
    sq.enqueue(5);

    if(sq.contains(6))
        cout << "A fila contém o elemento 6." << endl;
    else
        cout << "A fila não contém o elemento 6." << endl;
    cout << "\n\n";

    
    cout << "Fila antes do flip:" << endl;
    StaticQueue<int> sq_temp(10);
    int r3;
    while(!sq.isEmpty()) {
        sq.dequeue(r3);
        sq_temp.enqueue(r3);
        cout << r3 << " ";
    }
    // Remonta a fila original
    while(!sq_temp.isEmpty()) {
        sq_temp.dequeue(r3);
        sq.enqueue(r3);
    }
    cout << "\n";

    cout << "Fila depois do flip:" << endl;
    sq.flip();
    while(!sq.isEmpty()) {
        sq.dequeue(r3);
        sq_temp.enqueue(r3);
        cout << r3 << " ";
    }
    // Remonta a fila original
    while(!sq_temp.isEmpty()) {
        sq_temp.dequeue(r3);
        sq.enqueue(r3);
    }
    cout << "\n\n";

     if(sq.enqueueWithPriority(10) == 0) {
        int r4;
        cout << "Fila com o novo elemento inserido:" << endl;
        while(!sq.isEmpty()) {
            sq.dequeue(r4);
            sq_temp.enqueue(r4);
            cout << r4 << " ";
        }
        // Remonta a fila original
        while(!sq_temp.isEmpty()) {
            sq_temp.dequeue(r4);
            sq.enqueue(r4);
        }
    }
    else
        cout << "Fila cheia!" << endl; 
    cout << "\n\n";

    /**
     * Testes com pilhas
     */
    ss.push(1);
    ss.push(2);
    ss.push(3);
    ss.push(4);

    if(ss.contains(3))
        cout << "O elemento 3 está na pilha!" << endl;
    else
        cout << "O elemento 3 não está na pilha!" << endl;
    cout << "\n\n";


    /**
     * Exercício 7
     */
    StaticStack<int> saux(ss.numElements());
    int r5;
    cout << "Pilha antes de inverter os elementos: " << endl;
	while(!ss.isEmpty()) {
        ss.pop(r5);
        saux.push(r5);
        cout << r5 << endl;
    }
    while(!saux.isEmpty()) {
        saux.pop(r5);
        ss.push(r5);
    }
	cout << "\n\n";

    reverseStack(&ss);    
    cout << "Nova ordem dos elementos da pilha: " << endl;
	while(!ss.isEmpty()) {
        ss.pop(r5);
        saux.push(r5);
        cout << r5 << endl;
    }
    while(!saux.isEmpty()) {
        saux.pop(r5);
        ss.push(r5);
    }
	cout << "\n\n";
    

    /**
     * Exercício 8
     */
    findElement(ss, 2);

    return 0;
}
