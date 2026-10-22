#ifndef FILA_PRIORIDADE_H_INCLUDED
#define FILA_PRIORIDADE_H_INCLUDED

#include "utils.hpp"

class fila_prioridade
{
private:
    tipoVertice heap[MAX_NUM_VERTICES];
    int pos[MAX_NUM_VERTICES];
    int k;
    tipoPeso* dist;

    /**
     * @brief Função-membro para fazer troca de pesos.
     * @details Efetua troca de pesos e de posições em caso de troca de prioridade.
     * @param i Primeira posição.
     * @param j Segunda posição.
     */
    void troca(int, int);

    /**
     * @brief Função-membro para refazer heap.
     * @details Reconstroi a árvore heap.
     * @param esq indice esquerdo.
     * @param dir indice direito.
     */
    void refaz(int, int);

public:
    /**
     * @brief Construtor para fila de prioridade.
     * @details Construtor que inicializa o tamanho da fila com 0,<br> ponteiro pra distância ja definido
     * @param dist ponteiro para distância.
     */
    explicit fila_prioridade(tipoPeso*);

    /**
     * @brief Função-membro para verificar se uma fila de prioridade é vazia.
     * @details Verifica se uma fila de prioridade é vazia a partir de um valor <k>.
     * @returns retorna <true> se vazia.
     */
    bool vazia() const;

    /**
     * @brief Função-membro para verificar se uma posição da fila contem itens.
     * @details Verifica a partir de uma posição (com valor de vértice de referencia) se tem algum valor armazenado.
     * @param v Vértice referência.
     * @returns <true> se contem.
     */
    bool contem(tipoVertice) const;

    /**
     * @brief Função-membro para inserir valor na fila de prioridade.
     * @details Insere novo valor na fila de prioridade.
     * @param v Vértice referencia.
     */
    void inserir(tipoVertice);

    /**
     * @brief Função-membro para retirar valor mínimo do heap.
     * @details Remove valor mínimo.
     * @returns Retorna vértice mínimo
     */
    tipoVertice retira_minimo();

    /**
     * @brief Função-membro para diminuir chave em árvore heap.
     * @details Diminui chave da árvore heap.
     * @param v Vértice referência.
     */
    void diminui_chave(tipoVertice);
};

#endif
