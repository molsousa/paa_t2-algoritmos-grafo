#include <iostream>
#include <format>
#include "../../include/grafo.hpp"

grafo::grafo(const tipoGrafo tipo)
{
    for(tipoVertice i{}; i < MAX_NUM_VERTICES; ++i){
        for(tipoVertice j{}; j < MAX_NUM_VERTICES; ++i){
            mat[i][j] = 0.0;
        }
    }

    this->set_num_vertices(MAX_NUM_VERTICES);
    this->set_num_arestas(0);
    this->set_tipo_grafo(tipo);
}

grafo::grafo(const tipoVertice num_max, const tipoGrafo tipo)
{
    for(tipoVertice i{}; i < num_max; ++i){
        for(tipoVertice j{}; j < num_max; ++j){
            mat[i][j] = 0.0;
        }
    }

    this->set_num_vertices(num_max);
    this->set_num_arestas(0);
    this->set_tipo_grafo(tipo);
}

grafo::~grafo()
{
    std::cout << "Grafo removido\n";
}

void grafo::set_num_vertices(const int num_vertices)
{
    this->num_vertices = num_vertices;
}

int grafo::get_num_vertices() const
{
    return this->num_vertices;
}

void grafo::set_num_arestas(const int num_arestas)
{
    this->num_arestas = num_arestas;
}

int grafo::get_num_arestas() const
{
    return this->num_arestas;
}

void grafo::set_tipo_grafo(const tipoGrafo tipo)
{
    this->tipo = tipo;
}

tipoGrafo grafo::get_tipo_grafo() const
{
    return this->tipo;
}

void grafo::set_valor_grafo(const tipoVertice v1,
                            const tipoVertice v2,
                            const tipoPeso peso)
{
    this->mat[v1][v2] = peso;
}

tipoPeso grafo::get_valor_grafo(const tipoVertice v1,
                                const tipoVertice v2)
{
    return this->mat[v1][v2];
}

bool grafo::existe_aresta(tipoVertice v1, tipoVertice v2) const
{
    if(v1 > this->num_vertices || v2 > this->get_num_vertices()){
        std::cout << "Numero maximo de vertices excedido\n";
        return false;
    }

    return (this->mat[v1][v2] != 0.0);
}

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

tipoVertice grafo::get_primeiro_adjacencia(tipoVertice& v)
{
    tipoVertice res {0};
    bool vazia {true};
    tipoVertice aux {0};

    while(aux < num_vertices && vazia){
        if(mat[v][aux] > 0.0){
            vazia = false;
            res = aux;
        }
        else{
            ++aux;
        }
    }

    return res;
}

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

tipoVertice grafo::prox_adjacencia(tipoVertice v,
                                   tipoPeso& peso,
                                   int& prox,
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
