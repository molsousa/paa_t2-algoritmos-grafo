#include <iostream>
#include <format>
#include <cmath>
#include <fstream>
#include <string>
#include "../../include/grafo.hpp"

/**
 * @brief Construtor.
 * @details Constrói o grafo com número máximo de vértices.
 * @param tipo Tipo de grafo (se orientado ou não orientado).
 */
grafo::grafo(const tipoGrafo tipo) : num_vertices(MAX_NUM_VERTICES), num_arestas(0)
{
    for(tipoVertice i{}; i < MAX_NUM_VERTICES; ++i){
        for(tipoVertice j{}; j < MAX_NUM_VERTICES; ++i){
            mat[i][j] = 0.0;
        }
    }

    this->set_tipo_grafo(tipo);
}

/**
 * @brief Construtor.
 * @details Constrói o grafo com número de vértices pré-definido.
 * @param num_max Número máximo de vértices.
 * @param tipo Tipo de grafo (se orientado ou não orientado).
 * @overload
 */
grafo::grafo(const tipoVertice num_max, const tipoGrafo tipo) : num_vertices(num_max), num_arestas(0)
{
    for(tipoVertice i{}; i < num_max; ++i){
        for(tipoVertice j{}; j < num_max; ++j){
            mat[i][j] = 0.0;
        }
    }

    set_tipo_grafo(tipo);
}

/**
 * @brief Destrutor.
 * @details Destrutor para a classe grafo, imprime no console um texto de sucesso.
 */
grafo::~grafo()
{
    std::cout << "Grafo removido\n";
}

/**
 * @brief Função membro para definir o número de vértices.
 * @details Define o valor do atributo <num_vertices>.
 * @param num_vertices Número máximo de vértices.
 */
void grafo::set_num_vertices(const int num_vertices)
{
    this->num_vertices = num_vertices;
}

/**
 * @brief Função membro para recuperar valor do número de vértices.
 * @details Recupera o valor do atributo <num_vertices>.
 * @returns Número de vértices do grafo.
 */
int grafo::get_num_vertices() const
{
    return this->num_vertices;
}

/**
 * @brief Função membro para definir o número de arestas.
 * @details Define o valor do atributo <num_arestas>.
 * @param num_arestas Número de arestas do grafo.
 */
void grafo::set_num_arestas(const int num_arestas)
{
    this->num_arestas = num_arestas;
}

/**
 * @brief Função membro para recuperar valor do número de arestas.
 * @details Recupera o valor do atributo <num_arestas>.
 * @returns Número de arestas do grafo.
 */
int grafo::get_num_arestas() const
{
    return this->num_arestas;
}

/**
 * @brief Função membro para definir o tipo do grafo.
 * @details Define o valor do atributo <tipo> para <orientado> ou <nao_orientado>.
 * @param tipo Valor de tipo enumerado para <orientado> ou <nao_orientado>
 */
void grafo::set_tipo_grafo(const tipoGrafo tipo)
{
    this->tipo = tipo;
}

/**
 * @brief Função membro para recuperar tipo do grafo.
 * @details Recupera o tipo do grafo no atributo <tipo> definido no construtor.
 * @returns Tipo do grafo definido.
 */
tipoGrafo grafo::get_tipo_grafo() const
{
    return this->tipo;
}

/**
 * @brief Função membro para definir um valor de peso em uma aresta.
 * @details Define o valor de peso em uma aresta específica do grafo <mat[v1][v2]>.
 * @param v1 Vértice origem.
 * @param v2 Vértice destino.
 * @param peso Peso a ser atribuído a uma aresta.
 */
void grafo::set_valor_grafo(const tipoVertice v1,
                            const tipoVertice v2,
                            const tipoPeso peso)
{
    this->mat[v1][v2] = peso;
}

/**
 * @brief Função membro para recuperar valor do peso de uma aresta.
 * @details Recupera o valor do peso do grafo em uma aresta específica <mat[v1][v2]>.
 * @param v1 Vértice origem.
 * @param v2 Vértice destino.
 * @returns Valor atribuído na aresta buscada.
 */
tipoPeso grafo::get_valor_grafo(const tipoVertice v1,
                                const tipoVertice v2) const
{
    return this->mat[v1][v2];
}

/**
 * @brief Função membro para verificar se uma aresta existe.
 * @details Verifica a existência de uma aresta verificando se o valor do peso é diferente de zero.
 * @param v1 Vértice origem.
 * @param v2 Vértice destino.
 * @returns true se existe e false caso contrário.
 */
bool grafo::existe_aresta(tipoVertice v1, tipoVertice v2) const
{
    if(v1 > this->num_vertices || v2 > this->get_num_vertices()){
        std::cout << "Numero maximo de vertices excedido\n";
        return false;
    }

    return (this->mat[v1][v2] != 0.0);
}

/**
 * @brief Função membro para inserir uma aresta no grafo.
 * @param v1 Vértice origem.
 * @param v2 Vértice destino
 * @param peso Peso a ser inserido.
 * @details Aresta inserida, caso seja uma nova, altera o contador de arestas.
 */
void grafo::inserir_aresta(const tipoVertice v1,
                           const tipoVertice v2,
                           const tipoPeso peso)
{
    if(get_valor_grafo(v1, v2) == 0.0 && this->tipo == orientado){
        this->num_arestas++;
    }
    else if(get_valor_grafo(v1, v2) == 0.0 && this->tipo == nao_orientado){
        this->num_arestas += 2;
        set_valor_grafo(v2, v1, peso);
    }

    set_valor_grafo(v1, v2, peso);
}

/**
 * @brief Função-membro para recuperar o primeiro vértice adjacente.
 * @details Recupera um vértice adjacente a partir de um vértice de refência (que pode sofrer alterações).
 * @param v Vértice referencia.
 * @returns Vértice adjacente.
 */
tipoVertice grafo::get_primeiro_adjacencia(tipoVertice& v)
{
    tipoVertice res {0};
    bool vazia {true};
    tipoVertice aux {0};

    while(aux < num_vertices && vazia){
        if(mat[v][aux] != 0.0){
            vazia = false;
            res = aux;
        }
        else{
            ++aux;
        }
    }

    return res;
}

/**
 * @brief Função-membro para verificar se a lista de adjacência é vazia.
 * @details A partir de um vértice referência, retorna <true> se o vértice não tiver vértices adjacentes.
 * @param u Vértice referencia.
 * @returns <true> se a lista de adjacenteses for vazia.
 */
bool grafo::lista_adjacencia_vazia(tipoVertice v)
{
    tipoVertice aux{0};
    bool vazia{true};

    while(aux < num_vertices && vazia){
        if(mat[v][aux] != 0.0){
            vazia = false;
        }
        else{
            ++aux;
        }
    }

    return vazia;
}

/**
 * @brief Função-membro para recuperar o próximo vértice de adjacência.
 * @details Recupera o próximo vértice de adjacência a partir do vértice de referência.
 * @param v vértice referência.
 * @param peso peso.
 * @param prox Próximo vértice adjacente.
 * @param fim_lista valor booleano para delimitar o fim da lista.
 * @returns Primeiro vértice adjacente com o vértice referência.
 */
tipoVertice grafo::prox_adjacencia(tipoVertice v,
                                   tipoPeso& peso,
                                   tipoVertice& prox,
                                   bool& fim_lista) const
{
    tipoVertice adj {prox};
    peso = mat[v][prox];
    ++prox;

    while(prox < num_vertices && mat[v][prox] == 0.0){
        ++prox;
    }

    if(prox == num_vertices){
        fim_lista = true;
    }

    return adj;
}

/**
 * @brief Função-membro para imprimir um grafo.
 * @details Imprime no terminal um grafo em formato de matriz de adjacência.
 */
void grafo::imprimir_grafo()
{
    std::cout << "   ";

    for(tipoVertice i{}; i < this->num_vertices; ++i){
        std::cout << "|" << i << "   |";
    }

    std::cout << "\n";

    for(tipoVertice i{}; i < this->num_vertices; ++i){
        std::cout << std::format("{:d}->", i);

        for(tipoVertice j{}; j < this->num_vertices; ++j){
            std::cout << std::format("|{0:4.1f}|", this->mat[i][j]);
        }

        std::cout << "\n";
    }

    std::cout << "\n";
}

/**
 * @brief Função-membro para gerar um grafo transposto.
 * @details Gera um grafo transposto a partir do grafo referência ja instanciado.
 * @returns Ponteiro para novo grafo transposto.
 */
grafo* grafo::grafo_transposto()
{
    grafo* o;
    tipoVertice v, u;
    tipoPeso peso;
    tipoVertice aux;
    const int NUM_VERTICES = get_num_vertices();
    bool fim_lista;

    o = new grafo(NUM_VERTICES, get_tipo_grafo());
    o->set_num_arestas(get_num_arestas());

    for(v = 0; v < NUM_VERTICES; ++v){
        if(!lista_adjacencia_vazia(v)){
            aux = get_primeiro_adjacencia(v);
            fim_lista = false;

            while(!fim_lista){
                u = prox_adjacencia(v, peso, aux, fim_lista);
                o->inserir_aresta(u, v, peso);
            }
        }
    }
    return o;
}

/**
 * @brief Função-membro para extrair arestas do grafo.
 * @param arestas vetor de arestas.
 * @returns numero de arestas.
 */
int grafo::extrair_arestas(aresta* arestas)
{
    const int NUM_VERTICES = get_num_vertices();
    const tipoGrafo tipo = get_tipo_grafo();
    int k = 0;

    for(tipoVertice u{}; u < NUM_VERTICES; ++u){
        tipoVertice v0 = (tipo == nao_orientado) ? u + 1 : 0;

        for(tipoVertice v {v0}; v < NUM_VERTICES; ++v){
            if(u == v){
                continue;
            }

            tipoPeso peso = get_valor_grafo(u, v);
            if(peso != 0.0){
                arestas[k++] = {u, v, peso};
            }
        }
    }

    return k;
}

/**
 * @brief Função-membro para exportar grafo.
 * @param nome_arquivo nome do arquivo.
 */
void grafo::exportar_graphviz(const std::string& nome_arquivo) const
{
    std::ofstream arquivo(nome_arquivo);

    if(this->tipo == orientado){
        arquivo << "digraph G {\n";
    }
    else{
        arquivo << "graph G {\n";
    }

    arquivo << "  node [shape=circle];\n";

    for(tipoVertice u = 0; u < this->num_vertices; ++u){
        tipoVertice v_inicial = (this->tipo == nao_orientado) ? u + 1 : 0;

        for(tipoVertice v = v_inicial; v < this->num_vertices; ++v){
            if(u == v){
                continue;
            }

            tipoPeso peso = this->mat[u][v];
            if(peso != 0.0){
                if (this->tipo == orientado){
                    arquivo << "  " << u << " -> " << v
                    << " [label=\"" << peso << "\"];\n";
                }
                else{
                    arquivo << "  " << u << " -- " << v << " [label=\"" << peso << "\"];\n";
                }
            }
        }
    }

    arquivo << "}\n";
}

/**
 * @brief Função-membro para exportar grafo para CFC
 * @param nome_arquivo nome do arquivo.
 * @param componente vetor de componentes.
 */
void grafo::exportar_graphviz(const std::string& nome_arquivo,
                              const tipoVertice* componente) const
{
    std::ofstream arquivo(nome_arquivo);
    const int NUM_VERTICES = get_num_vertices();

    if(get_tipo_grafo() == orientado){
        arquivo << "digraph G{\n";
    }
    else{
        arquivo << "graph G{\n";
    }

    for(tipoVertice u {}; u < NUM_VERTICES; ++u){
        int c = componente[u];

        if(c < 0){
            arquivo << "   " << u << " [shape=circle];\n";
        }
        else{
            double hue = std::fmod(c * 0.61803398875, 1.0);
            arquivo << "   " << u << " [shape=circle, style=filled, fillcolor=\"" << hue << " 0.65 0.95\"];\n";
        }
    }

    for(tipoVertice u = 0; u < NUM_VERTICES; ++u){
        tipoVertice v_inicial = (get_tipo_grafo() == nao_orientado) ? u+1 : 0;

        for(tipoVertice v {v_inicial}; v < NUM_VERTICES; ++v){
            if(u == v){
                continue;
            }

            tipoPeso peso = get_valor_grafo(u, v);

            if(peso != 0.0){
                if(get_tipo_grafo() == orientado){
                    arquivo << "  " << u << " -> " << v << " [label=\"" << peso << "\"];\n";
                }
                else{
                    arquivo << "  " << u << " -- " << v << " [label=\"" << peso << "\"];\n";
                }
            }
        }
    }

    arquivo << "}\n";
}

/**
 * @brief Função-membro para exportar grafo para Kruskal
 * @param nome_arquivo nome do arquivo.
 * @param agm vetor de arestas.
 * @param num_agm numero de arestas.
 * Pre-condicao: nenhuma.
 * Pos-condicao: nenhuma.
 */
void grafo::exportar_graphviz_agm(const std::string& nome_arquivo,
                                  const aresta* agm,
                                  int num_agm) const
{
    std::ofstream arquivo(nome_arquivo);

    if(this->tipo == orientado){
        arquivo << "digraph G {\n";
    }
    else{
        arquivo << "graph G {\n";
    }

    for(tipoVertice u = 0; u < this->num_vertices; ++u){
        arquivo << "  " << u << " [shape=circle];\n";
    }

    auto na_mst = [&](tipoVertice u, tipoVertice v) -> bool{
        for(int i = 0; i < num_agm; ++i){
            if(agm[i].u == u && agm[i].v == v){
                return true;
            }
            if(this->tipo == nao_orientado && agm[i].u == v && agm[i].v == u){
                return true;
            }
        }
        return false;
    };

    for(tipoVertice u = 0; u < this->num_vertices; ++u){
        tipoVertice v0 = (this->tipo == nao_orientado) ? u + 1 : 0;

        for(tipoVertice v = v0; v < this->num_vertices; ++v){
            if(u == v){
                continue;
            }

            tipoPeso peso = this->mat[u][v];
            if(peso == 0.0){
                continue;
            }

            bool da_agm = na_mst(u, v);
            const char* cor = da_agm ? "red" : "gray50";
            const char* larg = da_agm ? "2.5" : "1.0";
            const char* estilo = da_agm ? "solid" : "dashed";

            if(this->tipo == orientado){
                arquivo << "  " << u << " -> " << v
                << " [label=\"" << peso << "\""
                << ", color=" << cor
                << ", penwidth=" << larg
                << ", style=" << estilo << "];\n";
            }
            else{
                arquivo << "  " << u << " -- " << v
                << " [label=\"" << peso << "\""
                << ", color=" << cor
                << ", penwidth=" << larg
                << ", style=" << estilo << "];\n";
            }
        }
    }

    arquivo << "}\n";
}
