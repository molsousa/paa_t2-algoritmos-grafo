#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include "item.hpp"

class pilha
{
private:
    class lista
    {
    public:
        tipoItem item;
        lista* prox;

        lista(const tipoItem, lista*);
    };

    lista* topo;

public:
    pilha();

    bool vazia() const;

    void push(const tipoItem);

    tipoItem pop();

    void imprimir();
};

#endif
