#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include <string>
#include "utils.hpp"
#include "aresta.hpp"

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
    tipoPeso get_valor_grafo(const tipoVertice, const tipoVertice) const;

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
     * @brief Função-membro para imprimir um grafo.
     * @details Imprime no terminal um grafo em formato de matriz de adjacência.
     */
    void imprimir_grafo();

    /**
     * @brief Função-membro para recuperar o primeiro vértice adjacente.
     * @details Recupera um vértice adjacente a partir de um vértice de refência (que pode sofrer alterações).
     * @param v Vértice referencia.
     * @returns Vértice adjacente.
     */
    tipoVertice get_primeiro_adjacencia(tipoVertice&);

    /**
     * @brief Função-membro para verificar se a lista de adjacência é vazia.
     * @details A partir de um vértice referência, retorna <true> se o vértice não tiver vértices adjacentes.
     * @param u Vértice referencia.
     * @returns <true> se a lista de adjacenteses for vazia.
     */
    bool lista_adjacencia_vazia(tipoVertice);

    /**
     * @brief Função-membro para recuperar o próximo vértice de adjacência.
     * @details Recupera o próximo vértice de adjacência a partir do vértice de referência.
     * @param v vértice referência.
     * @param peso peso.
     * @param prox Próximo vértice adjacente.
     * @param fim_lista valor booleano para delimitar o fim da lista.
     * @returns Primeiro vértice adjacente com o vértice referência.
     */
    tipoVertice prox_adjacencia(tipoVertice, tipoPeso&, tipoVertice&, bool&) const;

    /**
     * @brief Função-membro para gerar um grafo transposto.
     * @details Gera um grafo transposto a partir do grafo referência ja instanciado.
     * @returns Ponteiro para novo grafo transposto.
     */
    grafo* grafo_transposto();

    /**
     * @brief Função-membro para extrair arestas do grafo.
     * @param arestas vetor de arestas.
     * @returns numero de arestas.
     */
    int extrair_arestas(aresta*);

    /**
     * @brief Função-membro para exportar grafo.
     * @param nome_arquivo nome do arquivo.
     */
    void exportar_graphviz(const std::string&) const;

    /**
     * @brief Função-membro para exportar grafo para CFC
     * @param nome_arquivo nome do arquivo.
     * @param componente vetor de componentes.
     */
    void exportar_graphviz(const std::string&, const tipoVertice*) const;

    // grafo.hpp
    void exportar_graphviz_mst(const std::string&, const aresta*, int) const;
};

#endif
