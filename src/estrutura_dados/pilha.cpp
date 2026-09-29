#include <iostream>
#include "../../include/pilha.hpp"

pilha::lista::lista(const tipoItem item, lista* prox)
{
    this->item = item;
    this->prox = prox;
}

pilha::pilha()
{
    this->topo = nullptr;
}

bool pilha::vazia() const
{
    return (this->topo == nullptr);
}

void pilha::push(const tipoItem item)
{
    lista* novo = new lista(item, topo);

    topo = novo;
}

void pilha::imprimir()
{
    lista* aux {topo};

    while(aux != nullptr){
        std::cout << aux->item.v << "\n";

        aux = aux->prox;
    }
}

tipoItem pilha::pop()
{
    tipoItem item {topo->item};

    lista* aux = topo;
    topo = aux->prox;
    delete aux;

    return item;
}
