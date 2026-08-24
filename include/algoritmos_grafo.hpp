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
    void busca_profundidade();

    /**
     * @brief Algoritmo de busca em largura.
     */
    void busca_largura();

    /**
     * @brief Algoritmo de ordenação topológica.
     */
    void ordenacao_topologica();

    /**
     * @brief Vértices com componentes fortemente conexos.
     */
    void componentes_fortemente_conexas();

    /**
     * @brief Algoritmo de Djikstra.
     */
    void djikstra();

    /**
     * @brief Algoritmo de Kruskal.
     */
    void kruskal();
};

#endif
