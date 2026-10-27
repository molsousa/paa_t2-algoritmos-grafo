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
     * @brief Função-membro para aplicar algoritmo DFS.
     * @details Aplica algoritmo DFS (Depth-First Search) recebendo os
     *          vértices brancos, transformando-os em cinza quando acessados
     *          e preto quando finalizados. O algoritmo pode ser implementado
     *          com pilha como alternativa à recursão. São impressos na tela
     *          tanto o tempo de descoberta quanto o tempo final.
     * @param g grafo.
     * @param u Vértice referência.
     * @param cores Vetor de cores para início, descoberta ou término de vértices.
     * @param p Pilha de vértices.
     * @param tempo Referência para tempo global.
     * @param d Vetor de tempo de descoberta do vértice.
     * @param t Vetor de tempo de término.
     */
    void dfs(grafo&, tipoVertice, cor*, pilha*, tipoTempo&, tipoTempo*, tipoTempo*);

    /**
     * @brief Função-membro para aplicar algoritmo DFS.
     * @details Versão alternativa do algoritmo DFS focado em servir de
     *          base para ordenacao topologica e componentes fortemente
     *          conexos; imprime na tela caso uma ordenacao topologica
     *          for impossivel; possui demarcador para caso seja necessario
     *          verificar ciclo (so seria necessario em ordenacao topologica);
     *          É utilizado uma pilha de vértices para a ordenacao.
     * @param g grafo.
     * @param u Vértice referencia.
     * @param cores vetor de cores.
     * @param vertices_ordenados pilha de vértices ordenados.
     * @param ciclo variavel booleana para caso precise verificar ciclo ou nao.
     * @overload
     */
    bool dfs(grafo&, tipoVertice, cor*, pilha*, bool);

    /**
     * @brief Função-membro para aplicar algoritmo BFS
     * @details Aplica algoritmo BFS (Breadth First Search)
     * @param g grafo.
     * @param u Vértice referência.
     * @param dist Vetor de distância.
     * @param cores Vetor de cores para início, descoberta ou término de vértices.
     * @param p Pilha de vértices.
     */
    void bfs(grafo&, tipoVertice, tipoVertice*, cor*);

    void dfs_componente(grafo&, tipoVertice, cor*, tipoVertice*, int);

public:

    /**
     * @brief Algoritmo de busca em profundidade.
     * @details Utiliza uma pilha para armazenar os pais dos vértices visitados;
     *          cria vetores de tempo de descoberta e tempo final, além de uma
     *          variável de tempo; todos os vértices são inicializados com cor branca;
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
     * @brief Função membro para verificar componentes fortemente conexos.
     * @details Imprime na tela vértices com componentes fortemente conexos;
     *          utiliza o algoritmo dfs overload e tambem uma modificacao do
     *          dfs para visita no grafo tranposto;
     * @param g grafo.
     */
    void componentes_fortemente_conexas(grafo&, tipoVertice*);

    /**
     * @brief Algoritmo djikstra para encontrar menor caminho.
     * @details Algoritmo djikstra para menor caminho: o algoritmo nao admite valores de
     *          arestas negativas; utiliza um vetor de distancia e de pai, onde o vetor de
     *          distância é inicialiado com <INFINITO> e pai com <-1>; utiliza uma fila de
     *          prioridade para acessar o melhor caminho naquele momento; Caso o algoritmo
     *          perceba que o custo está aumentando, pode voltar e procurar outro melhor caminho;
     * @param g grafo.
     * @param origem vértice de origem.
     */
    void djikstra(grafo&, tipoVertice);

    /**
     * @brief Algoritmo de Kruskal.
     * @details Obtém uma AGM de um grafo adicionando a floresta uma aresta
     *          de fmenor peso que nao forma ciclo; o uso de <fila_prioridade>
     *          é para obter arestas em ordem crescente de peso; O algoritmo
     *          testa se forma ciclo utilizando conjuntos classe: <union_find>.
     * @param g grafo.
     */
    void kruskal(grafo&, aresta*, int&);
};

#endif
