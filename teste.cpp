#include "include/teste.h"

#include "include/fila.hpp"
#include "include/pilha.hpp"
#include "include/grafo.hpp"

int criar_grafo()
{
    grafo* g = new grafo(7, orientado);

    if(g == nullptr){
        return 1;
    }

    g->inserir_aresta(0, 0, 5);
    g->inserir_aresta(1, 5, 7);
    g->inserir_aresta(4, 6, 13);
    g->inserir_aresta(3, 1, 2);
    g->inserir_aresta(0, 3, 1);
    g->inserir_aresta(1, 2, 10);
    g->inserir_aresta(2, 0, 9);

    g->imprimir_grafo();

    delete g;

    return 0;
}

int teste_fila()
{
    fila* f = new fila();
    tipoItem item;

    item.v = 5;
    f->enqueue(item);
    item.v = 7;
    f->enqueue(item);
    item.v = 9;
    f->enqueue(item);
    item.v = 11;
    f->enqueue(item);
    item.v = 3;
    f->enqueue(item);
    item.v = 2;
    f->enqueue(item);

    f->imprimir();

    f->dequeue();
    f->dequeue();
    f->dequeue();
    f->dequeue();
    f->dequeue();
    f->dequeue();

    f->imprimir();

    f->dequeue();

    f->enqueue(item);

    f->imprimir();

    return 0;
}

int teste_pilha()
{
    pilha* p = new pilha();

    tipoItem item;

    item.v = 5;
    p->push(item);
    item.v = 7;
    p->push(item);
    item.v = 9;
    p->push(item);
    item.v = 11;
    p->push(item);
    item.v = 3;
    p->push(item);
    item.v = 2;
    p->push(item);

    p->pop();

    p->imprimir();

    return 0;
}
