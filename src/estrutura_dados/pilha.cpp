#include <iostream>
#include "../../include/pilha.hpp"

pilha::lista::lista(const tipoVertice item, lista* prox)
{
    this->item = item;
    this->prox = prox;
}

pilha::pilha()
{
    this->topo = nullptr;
}

pilha::~pilha()
{
    lista* aux {topo};

    while(aux != nullptr){
        lista* temp {aux};
        aux = temp->prox;
        delete temp;
    }
}

bool pilha::vazia() const
{
    return (this->topo == nullptr);
}

tipoVertice pilha::visulizar_topo() const
{
    if(!vazia()){
        return topo->item;
    }

    return -1;
}

void pilha::push(const tipoVertice item)
{
    lista* novo = new lista(item, topo);

    topo = novo;
}

void pilha::imprimir()
{
    lista* aux {topo};

    while(aux != nullptr){
        std::cout << "|" << aux->item << "|->";

        aux = aux->prox;
    }

    std::cout << "NULL\n\n";
}

tipoVertice pilha::pop()
{
    tipoVertice item {topo->item};

    lista* aux = topo;
    topo = aux->prox;
    delete aux;

    return item;
}
