#include <iostream>
#include "../../include/fila.hpp"

fila::lista::lista(tipoVertice item)
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

void fila::enqueue(tipoVertice item)
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

tipoVertice fila::dequeue()
{
    tipoVertice item = -1;

    if(!vazia()){
        item = this->inicio->item;

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
        std::cout << "|" << aux->item << "|->";
    }

    std::cout << "nullptr\n";
}
