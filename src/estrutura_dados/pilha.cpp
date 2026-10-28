#include <iostream>
#include "../../include/pilha.hpp"

/**
 * @brief Construtor.
 * @details Construtor para criar um nó de lista com campo <prox> igual a nullptr.
 * @param item Item a ser adicionado no nó da lista.
 * Pre-condicao: nenhuma.
 * Pos-condicao: cria uma lista com item atribuido.
 */
pilha::lista::lista(const tipoVertice item, lista* prox)
{
    this->item = item;
    this->prox = prox;
}

/**
 * Construtor
 * @details Construtor para criar uma pilha com <topo> atribuído a nulo.
 * Pre-condicao: nenhuma.
 * Pos-condicao: cria uma pilha.
 */
pilha::pilha()
{
    this->topo = nullptr;
}

/**
 * Destrutor
 * @details destroi todos os nós de lista da pilha.
 * Pre-condicao: pilha criada.
 * Pos-condicao: nenhuma.
 */
pilha::~pilha()
{
    lista* aux {topo};

    while(aux != nullptr){
        lista* temp {aux};
        aux = temp->prox;
        delete temp;
    }
}

/**
 * @brief Função-membro para verificar se uma pilha é vazia
 * @returns <true> se vazia.
 * Pre-condicao: pilha criada.
 * Pos-condicao: retorna <true> se vazia
 */
bool pilha::vazia() const
{
    return (this->topo == nullptr);
}

/**
 * @brief Função-membro para visualizar o topo da pilha.
 * @returns vértice que está no topo.
 * Pre-condicao: pilha criada.
 * Pos-condicao: nenhuma.
 */
tipoVertice pilha::visulizar_topo() const
{
    if(!vazia()){
        return topo->item;
    }

    return -1;
}

/**
 * @brief Função-membro para empilhar elemento.
 * Pre-condicao: pilha criada.
 * Pos-condicao: empilha novo elemento na pilha.
 */
void pilha::push(const tipoVertice item)
{
    lista* novo = new lista(item, topo);

    topo = novo;
}

/**
 * @brief Função-membro para desempilhar elemento.
 * @returns elemento no topo da pilha desempilhado.
 * Pre-condicao: pilha criada.
 * Pos-condicao: nenhuma.
 */
tipoVertice pilha::pop()
{
    tipoVertice item {topo->item};

    lista* aux = topo;
    topo = aux->prox;
    delete aux;

    return item;
}

/**
 * @brief Função-membro para imprimir pilha.
 * @details Imprime em formato de lista encadeada os elementos da pilha.
 * Pre-condicao: pilha criada.
 * Pos-condicao: nenhuma.
 */
void pilha::imprimir()
{
    lista* aux {topo};

    while(aux != nullptr){
        std::cout << "|" << aux->item << "|->";

        aux = aux->prox;
    }

    std::cout << "NULL\n\n";
}
