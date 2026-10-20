#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include "utils.hpp"

/**
 * @class grafo Classe para grafo orientado ou não orentado de peso com ponto flutuante.
 */
class grafo
{
private:

    tipoPeso mat[MAX_NUM_VERTICES][MAX_NUM_VERTICES];
    int num_vertices;
    int num_arestas;
    tipoGrafo tipo;

public:

    /**
     * @brief Construtor.
     * @details Constrói o grafo com número máximo de vértices.
     * @param tipo Tipo de grafo (se orientado ou não orientado).
     */
    grafo(const tipoGrafo);

    /**
     * @brief Construtor.
     * @details Constrói o grafo com número de vértices pré-definido.
     * @param num_max Número máximo de vértices.
     * @param tipo Tipo de grafo (se orientado ou não orientado).
     * @overload
     */
    grafo(const tipoVertice, const tipoGrafo);

    /**
     * @brief Destrutor.
     * @details Destrutor para a classe grafo, imprime no console um texto de sucesso.
     */
    virtual ~grafo();

    /**
     * @brief Função membro para definir o número de vértices.
     * @details Define o valor do atributo <num_vertices>.
     * @param num_vertices Número máximo de vértices.
     */
    void set_num_vertices(const int);

    /**
     * @brief Função membro para recuperar valor do número de vértices.
     * @details Recupera o valor do atributo <num_vertices>.
     * @returns Número de vértices do grafo.
     */
    int get_num_vertices() const;

    /**
     * @brief Função membro para definir o número de arestas.
     * @details Define o valor do atributo <num_arestas>.
     * @param num_arestas Número de arestas do grafo.
     */
    void set_num_arestas(const int);

    /**
     * @brief Função membro para recuperar valor do número de arestas.
     * @details Recupera o valor do atributo <num_arestas>.
     * @returns Número de arestas do grafo.
     */
    int get_num_arestas() const;

    /**
     * @brief Função membro para definir o tipo do grafo.
     * @details Define o valor do atributo <tipo> para <orientado> ou <nao_orientado>.
     * @param tipo Valor de tipo enumerado para <orientado> ou <nao_orientado>
     */
    void set_tipo_grafo(const tipoGrafo);

    /**
     * @brief Função membro para recuperar tipo do grafo.
     * @details Recupera o tipo do grafo no atributo <tipo> definido no construtor.
     * @returns Tipo do grafo definido.
     */
    tipoGrafo get_tipo_grafo() const;

    /**
     * @brief Função membro para definir um valor de peso em uma aresta.
     * @details Define o valor de peso em uma aresta específica do grafo <mat[v1][v2]>.
     * @param v1 Vértice origem.
     * @param v2 Vértice destino.
     * @param peso Peso a ser atribuído a uma aresta.
     */
    void set_valor_grafo(const tipoVertice, const tipoVertice, const tipoPeso);

    /**
     * @brief Função membro para recuperar valor do peso de uma aresta.
     * @details Recupera o valor do peso do grafo em uma aresta específica <mat[v1][v2]>.
     * @param v1 Vértice origem.
     * @param v2 Vértice destino.
     * @returns Valor atribuído na aresta buscada.
     */
    tipoPeso get_valor_grafo(const tipoVertice, const tipoVertice);

    /**
     * @brief Função membro para verificar se uma aresta existe.
     * @details Verifica a existência de uma aresta verificando se o valor do peso é diferente de zero.
     * @param v1 Vértice origem.
     * @param v2 Vértice destino.
     * @returns true se existe e false caso contrário.
     */
    bool existe_aresta(const tipoVertice, const tipoVertice) const;

    /**
     * @brief Função membro para inserir uma aresta no grafo.
     * @param v1 Vértice origem.
     * @param v2 Vértice destino
     * @param peso Peso a ser inserido.
     * @details Aresta inserida, caso seja uma nova, altera o contador de arestas.
     */
    void inserir_aresta(const tipoVertice, const tipoVertice, const tipoPeso);

    /**
     * @brief Função membro para imprimir grafo.
     * @details Imprime grafo no console do terminal.
     */
    void imprimir_grafo();

    /**
     * @brief
     * @details
     * @param v
     */
    tipoVertice get_primeiro_adjacencia(tipoVertice&);

    /**
     * @brief
     * @details
     * @param
     */
    bool lista_adjacencia_vazia(tipoVertice);

    tipoVertice prox_adjacencia(tipoVertice, tipoPeso&, int&, bool&) const;

    grafo* grafo_transposto();
};

#endif
