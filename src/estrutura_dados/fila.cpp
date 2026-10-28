#include <iostream>
#include "../../include/fila.hpp"

/**
 * @brief Construtor.
 * @details Construtor para criar um nó de lista com campo <prox> igual a nullptr.
 * @param item Item a ser adicionado no nó da lista.
 * Pre-condicao: nenhuma.
 * Pos-condicao: cria uma lista com item atribuido.
 */
fila::lista::lista(tipoVertice item)
{
    this->item = item;
    this->prox = nullptr;
}

/**
 * @brief Construtor.
 * @details Construtor para criar uma fila com <inicio> e <fim> atribuídos a nulo.
 * Pre-condicao: nenhuma.
 * Pos-condicao: cria uma fila.
 */
fila::fila()
{
    this->inicio = nullptr;
    this->fim = nullptr;
}

/**
 * @brief Destrutor.
 * Pre-condicao: fila criada.
 * Pos-condicao: nenhuma.
 */
fila::~fila()
{
    lista* aux {inicio};

    while(aux != nullptr){
        lista* temp {aux};
        aux = temp->prox;
        delete temp;
    }
}

/**
 * @brief Função membro para verificar se uma fila é vazia.
 * @details Verifica se a fila está vazia com valores de <true> para vazia e <false> para contrário.
 * @returns true se vazia, false se contrário.
 * Pre-condicao: nenhuma.
 * Pos-condicao: retorna <true> se vazia.
 */
bool fila::vazia() const
{
    return (this->inicio == nullptr);
}

/**
 * @brief Função membro para enfileirar um item.
 * @details Enfileira item com valores de <tipoVertice> e/ou <tipoPeso>.
 * @param item Variável do tipo <tipoItem>
 * Pre-condicao: nenhuma.
 * Pos-condicao: nenhuma.
 */
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

/**
 * @brief Função membro para desenfileirar um item.
 * @details Desenfileira um item e retorna o valor do item desenfileirado.
 * @returns Item desenfileirado em tipo ponteiro.
 * Pre-condicao: nenhuma.
 * Pos-condicao: nenhuma.
 */
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

/**
 * @brief Função membro para imprimir fila [DEBUG].
 * @details Imprime toda a fila com saída em formato de lista.
 * Pre-condicao: nenhuma.
 * Pos-condicao: nenhuma.
 */
void fila::imprimir()
{
    for(lista* aux {this->inicio}; aux != nullptr; aux = aux->prox){
        std::cout << "|" << aux->item << "|->";
    }

    std::cout << "nullptr\n";
}
