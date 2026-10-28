#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include "utils.hpp"

/**
* @class fila Definição de classe para fila.
*/
class pilha
{
private:
    class lista
    {
    public:
        tipoVertice item;
        lista* prox;

        /**
         * @brief Construtor.
         * @details Construtor para criar um nó de lista com campo <prox> igual a nullptr.
         * @param item Item a ser adicionado no nó da lista.
         * Pre-condicao: nenhuma.
         * Pos-condicao: cria uma lista com item atribuido.
         */
        lista(const tipoVertice, lista*);
    };

    lista* topo;

public:

    /**
     * Construtor
     * @details Construtor para criar uma pilha com <topo> atribuído a nulo.
     * Pre-condicao: nenhuma.
     * Pos-condicao: cria uma pilha.
     */
    pilha();

    /**
     * Destrutor
     * @details destroi todos os nós de lista da pilha.
     * Pre-condicao: pilha criada.
     * Pos-condicao: nenhuma.
     */
    ~pilha();

    /**
     * @brief Função-membro para verificar se uma pilha é vazia
     * @returns <true> se vazia.
     * Pre-condicao: pilha criada.
     * Pos-condicao: retorna <true> se vazia
     */
    bool vazia() const;

    /**
     * @brief Função-membro para visualizar o topo da pilha.
     * @returns vértice que está no topo.
     * Pre-condicao: pilha criada.
     * Pos-condicao: nenhuma.
     */
    tipoVertice visulizar_topo() const;

    /**
     * @brief Função-membro para empilhar elemento.
     * Pre-condicao: pilha criada.
     * Pos-condicao: empilha novo elemento na pilha.
     */
    void push(const tipoVertice);

    /**
     * @brief Função-membro para desempilhar elemento.
     * @returns elemento no topo da pilha desempilhado.
     * Pre-condicao: pilha criada.
     * Pos-condicao: nenhuma.
     */
    tipoVertice pop();

    /**
     * @brief Função-membro para imprimir pilha.
     * @details Imprime em formato de lista encadeada os elementos da pilha.
     * Pre-condicao: pilha criada.
     * Pos-condicao: nenhuma.
     */
    void imprimir();
};

#endif
