#ifndef ALGORITMOS_GRAFO_H_INCLUDED
#define ALGORITMOS_GRAFO_H_INCLUDED

#include <list>

#include "grafo.hpp"
#include "pilha.hpp"
#include "fila.hpp"
#include "fila_prioridade.hpp"
#include "utils.hpp"

/**
 * @class algoritmos Classe para executar algoritmos em grafos.
 */
class algoritmos
{
private:

    /**
     * @brief
     * @details
     * @param g grafo.
     * @param u Vértice referência.
     * @param cores Vetor de cores para início, descoberta ou término de vértices.
     * @param p Pilha de vértices.
     * @param tempo Referência para tempo global.
     * @param d Vetor de tempo de descoberta do vértice.
     * @param t Vetor de tempo de término.
     */
    void dfs(grafo&, tipoVertice, cor*, pilha*, tipoTempo&, tipoTempo*, tipoTempo*);

    void dfs(grafo&, tipoVertice, cor*, pilha*);

    /**
     * @brief
     * @details
     * @param g grafo.
     * @param u Vértice referência.
     * @param dist Vetor de distância.
     * @param cores Vetor de cores para início, descoberta ou término de vértices.
     * @param p Pilha de vértices.
     */
    void bfs(grafo&, tipoVertice, tipoTempo*, cor*, pilha*);

public:

    /**
     * @brief Algoritmo de busca em profundidade.
     * @param g grafo.
     */
    void busca_profundidade(grafo&);

    /**
     * @brief Algoritmo de busca em largura.
     * @param g grafo.
     */
    void busca_largura(grafo&);

    /**
     * @brief Algoritmo de ordenação topológica.
     * @param g grafo.
     */
    void ordenacao_topologica(grafo&);

    /**
     * @brief Vértices com componentes fortemente conexos.
     * @param g grafo.
     */
    void componentes_fortemente_conexas(grafo&);

    /**
     * @brief Algoritmo de Djikstra.
     * @param g grafo.
     */
    void djikstra(grafo&, tipoVertice);

    /**
     * @brief Algoritmo de Kruskal.
     * @param g grafo.
     */
    void kruskal(grafo&);
};

#endif
