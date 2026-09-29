#ifndef ALGORITMOS_GRAFO_H_INCLUDED
#define ALGORITMOS_GRAFO_H_INCLUDED

#include "grafo.hpp"

/**
 * @class algoritmos Classe para executar algoritmos em grafos.
 */
class algoritmos : public grafo
{
public:

    /**
     * @brief Algoritmo de busca em profundidade.
     */
    void busca_profundidade(grafo*);

    /**
     * @brief Algoritmo de busca em largura.
     */
    void busca_largura(grafo*);

    /**
     * @brief Algoritmo de ordenação topológica.
     */
    void ordenacao_topologica(grafo*);

    /**
     * @brief Vértices com componentes fortemente conexos.
     */
    void componentes_fortemente_conexas(grafo*);

    /**
     * @brief Algoritmo de Djikstra.
     */
    void djikstra(grafo*);

    /**
     * @brief Algoritmo de Kruskal.
     */
    void kruskal(grafo*);
};

#endif
