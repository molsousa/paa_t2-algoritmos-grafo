#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include "item.hpp"

/**
 * @class fila Definição de classe para fila.
 */
class fila
{
private:

    /**
     * @class lista Definição de classe para lista.
     */
    class lista
    {
    public:
        tipoItem item;
        lista* prox;

        /**
         * @brief Construtor.
         * @details Construtor para criar um nó de lista com campo <prox> igual a nullptr.
         * @param item Item a ser adicionado no nó da lista.
         */
        lista(const tipoItem);
    };

    lista* inicio;
    lista* fim;

public:

    /**
     * @brief Construtor.
     * @details Construtor para criar uma fila com <inicio> e <fim> atribuídos a nulo.
     */
    fila();

    /**
     * @brief Função membro para verificar se uma fila é vazia.
     * @details Verifica se a fila está vazia com valores de <true> para vazia e <false> para contrário.
     * @returns true se vazia, false se contrário.
     */
    bool vazia() const;

    /**
     * @brief Função membro para enfileirar um item.
     * @details Enfileira item com valores de <tipoVertice> e/ou <tipoPeso>.
     * @param item Variável do tipo <tipoItem>
     */
    void enqueue(const tipoItem);

    /**
     * @brief Função membro para desenfileirar um item.
     * @details Desenfileira um item e retorna o valor do item desenfileirado.
     * @returns Item desenfileirado em tipo ponteiro.
     */
    tipoItem* dequeue();

    /**
     * @brief Função membro para imprimir fila [DEBUG].
     * @details Imprime toda a fila com saída em formato de lista.
     */
    void imprimir();
};

#endif
