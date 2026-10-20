#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include "utils.hpp"

class pilha
{
private:
    class lista
    {
    public:
        tipoVertice item;
        lista* prox;

        lista(const tipoVertice, lista*);
    };

    lista* topo;

public:
    pilha();

    ~pilha();

    bool vazia() const;

    tipoVertice visulizar_topo() const;

    void push(const tipoVertice);

    tipoVertice pop();

    void imprimir();
};

#endif
