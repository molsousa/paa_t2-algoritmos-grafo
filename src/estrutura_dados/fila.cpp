#include <iostream>
#include "../../include/fila.hpp"

fila::lista::lista(tipoItem item)
{
    this->item = item;
    this->prox = nullptr;
}

fila::fila()
{
    this->inicio = nullptr;
    this->fim = nullptr;
}

bool fila::vazia() const
{
    return (this->inicio == nullptr);
}

void fila::enqueue(tipoItem item)
{
    lista* novo = new lista(item);

    if(vazia()){
        this->inicio = novo;
    }
    else{
        this->fim->prox = novo;
    }

    this->fim = novo;
}

tipoItem* fila::dequeue()
{
    tipoItem* item = nullptr;

    if(!vazia()){
        item = &this->inicio->item;

        lista* aux = this->inicio;
        this->inicio = this->inicio->prox;

        if(this->inicio == nullptr){
            this->fim = nullptr;
        }

        delete aux;
    }

    return item;
}

void fila::imprimir()
{
    for(lista* aux {this->inicio}; aux != nullptr; aux = aux->prox){
        std::cout << "|" << aux->item.v << "|->";
    }

    std::cout << "nullptr\n";
}
