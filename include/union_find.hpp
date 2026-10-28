#ifndef UNION_FIND_H_INCLUDED
#define UNION_FIND_H_INCLUDED

#include "utils.hpp"

/**
 * @class union_find para AGM Kruskal.
 */
class union_find{
private:
    tipoVertice pai[MAX_NUM_VERTICES];
    int tam[MAX_NUM_VERTICES];

public:
    /**
     * @brief Construtor da estrutura Union-Find.
     * @details Inicializa o vetor de pais, definindo cada vértice como seu próprio representante,
     * e o vetor de tamanhos, iniciando cada conjunto com tamanho 1.
     * @param n Número de vértices do grafo.
     * Pre-condicao: n deve ser maior que zero e menor ou igual a MAX_NUM_VERTICES.
     * Pos-condicao: Todos os vértices são criados como conjuntos independentes.
     */
    explicit union_find(int);

    /**
     * @brief Função-membro para encontrar o representante de um conjunto.
     * @details Busca a raiz do conjunto ao qual o vértice 'x' pertence. Utiliza a técnica de
     * compressão de caminho para achatar a árvore durante a busca, tornando
     * as operações futuras mais rápidas.
     * @param x Vértice a ser buscado.
     * @return O vértice representante do conjunto.
     * Pre-condicao: O vértice 'x' deve pertencer ao intervalo válido do grafo.
     * Pos-condicao: A estrutura da árvore pode ser achatada, mas a raiz não é alterada.
     */
    tipoVertice encontrar(tipoVertice);

    /**
     * @brief Função-membro para unir dois conjuntos distintos.
     * @details Verifica se os vértices 'x' e 'y' pertencem ao mesmo conjunto. Se pertencerem,
     * retorna falso. Se forem de conjuntos diferentes,
     * une-os utilizando a técnica de união por tamanho, pendurando a árvore menor
     * na raiz da árvore maior.
     * @param x Vértice de origem.
     * @param y Vértice de destino.
     * @return 'true' se os conjuntos foram unidos, 'false' se já estavam no mesmo conjunto.
     * Pre-condicao: Os vértices 'x' e 'y' devem pertencer ao intervalo válido do grafo.
     * Pos-condicao: Os conjuntos são fundidos em um só.
     */
    bool uniao(tipoVertice, tipoVertice);
};

#endif
