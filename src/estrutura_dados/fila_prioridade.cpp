#include <iostream>
#include "../../include/fila_prioridade.hpp"

/**
 * @brief Construtor para fila de prioridade.
 * @details Construtor que inicializa o tamanho da fila com 0,
 * ponteiro pra distância ja definido e posições como <nil>.
 * @param dist ponteiro para distância.
 */
fila_prioridade::fila_prioridade(tipoPeso* dist) : k(0), dist(dist)
{
    for(size_t i{}; i < MAX_NUM_VERTICES; ++i){
        pos[i] = -1;
    }
}

/**
 * @brief Função-membro para verificar se uma fila de prioridade é vazia.
 * @details Verifica se uma fila de prioridade é vazia a partir de um valor <k>.
 * @returns retorna <true> se vazia.
 */
bool fila_prioridade::vazia() const
{
    return k == 0;
}

/**
 * @brief Função-membro para verificar se uma posição da fila contem itens.
 * @details Verifica a partir de uma posição (com valor de vértice de referencia) se tem algum valor armazenado.
 * @param v Vértice referência.
 * @returns <true> se contem.
 */
bool fila_prioridade::contem(tipoVertice v) const
{
    return pos[v] != -1;
}

/**
 * @brief Função-membro para fazer troca de pesos.
 * @details Efetua troca de pesos e de posições em caso de troca de prioridade.
 * @param i Primeira posição.
 * @param j Segunda posição.
 */
void fila_prioridade::troca(int i, int j)
{
    tipoVertice u {heap[i]};
    heap[i] = heap[j];
    heap[j] = u;
    pos[heap[i]] = i;
    pos[heap[j]] = j;
}

/**
 * @brief Função-membro para refazer heap.
 * @details Reconstroi a árvore heap.
 * @param esq indice esquerdo.
 * @param dir indice direito.
 */
void fila_prioridade::refaz(int esq, int dir)
{
    int i = esq;
    int j = 2 * i;
    tipoVertice item = heap[i];

    while(j <= dir){
        if(j < dir && dist[heap[j]] > dist[heap[j+1]]){
            ++j;
        }

        if(dist[item] <= dist[heap[j]]){
            break;
        }

        heap[i] = heap[j];
        pos[heap[i]] = i;
        i = j;
        j = 2 * i;
    }

    heap[i] = item;
    pos[item] = i;
}

/**
 * @brief Função-membro para inserir valor na fila de prioridade.
 * @details Insere novo valor na fila de prioridade.
 * @param v Vértice referencia.
 */
void fila_prioridade::inserir(tipoVertice v)
{
    ++k;
    heap[k] = v;
    pos[v] = k;
    int i = k;
    while(i > 1 && dist[heap[i/2]] > dist[heap[i]]){
        troca(i, i/2);
        i /= 2;
    }
}

/**
 * @brief Função-membro para retirar valor mínimo do heap.
 * @details Remove valor mínimo.
 * @returns Retorna vértice mínimo
 */
tipoVertice fila_prioridade::retira_minimo()
{
    tipoVertice v = heap[1];
    pos[v] = -1;
    heap[1] = heap[k];
    pos[heap[1]] = 1;
    --k;

    if(k > 0){
        refaz(1, k);
    }

    return v;
}

/**
 * @brief Função-membro para diminuir chave em árvore heap.
 * @details Diminui chave da árvore heap.
 * @param v Vértice referência.
 */
void fila_prioridade::diminui_chave(tipoVertice v)
{
    int i = pos[v];
    while(i > 1 && dist[heap[i/2]] > dist[heap[i]]){
        troca(i, i/2);
        i /= 2;
    }
}
