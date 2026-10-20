#include <iostream>
#include <format>
#include "../include/algoritmos_grafo.hpp"

void algoritmos::busca_profundidade(grafo* g)
{
    const int NUM_VERTICES = g->get_num_vertices();

    cor cores[MAX_NUM_VERTICES];
    tipoVertice u;
    tipoTempo tempo{};
    tipoTempo d[MAX_NUM_VERTICES], t[MAX_NUM_VERTICES];

    for(u = 0; u < NUM_VERTICES; ++u){
        cores[u] = branco;
    }

    pilha* p = new pilha();

    for(u = 0; u < NUM_VERTICES; ++u){
        if(cores[u] == branco){
            dfs(g, u, cores, p, tempo, d, t);
        }
    }

    delete p;
}

void algoritmos::dfs(grafo* g,
                     tipoVertice u,
                     cor* cores,
                     pilha* p,
                     tipoTempo& tempo,
                     tipoTempo* d,
                     tipoTempo* t)
{
    tipoVertice v;
    bool fim_lista;
    tipoPeso peso;
    tipoVertice aux;

    cores[u] = cinza;
    d[u] = ++tempo;

    std::cout << std::format("Visita: {:2d}; Pai: {:2d}; Tempo descoberta: {:5d}\n", u, p->visulizar_topo(), d[u]);

    if(!g->lista_adjacencia_vazia(u)){
        aux = g->get_primeiro_adjacencia(u);
        fim_lista = false;

        while(!fim_lista){
            v = g->prox_adjacencia(u, peso, aux, fim_lista);

            if(cores[v] == branco){
                p->push(u);
                dfs(g, v, cores, p, tempo, d, t);
                p->pop();
            }
        }
    }

    cores[u] = preto;
    t[u] = ++tempo;

    std::cout << std::format("Visita: {:2d};          Tempo termino: {:8d}\n", u, t[u]);
}

void algoritmos::busca_largura(grafo* g)
{
    const int NUM_VERTICES = g->get_num_vertices();

    tipoVertice u;
    tipoTempo dist[MAX_NUM_VERTICES];
    cor cores[MAX_NUM_VERTICES];
    pilha* p = new pilha();

    for(u = 0; u < NUM_VERTICES; ++u){
        cores[u] = branco;
        dist[u] = INFINITO;
    }

    for(u = 0; u < NUM_VERTICES; ++u){

        if(cores[u] == branco){
            bfs(g, u, dist, cores, p);
        }
    }
}

void algoritmos::bfs(grafo* g,
                     tipoVertice u,
                     tipoTempo* dist,
                     cor* cores,
                     pilha* p)
{
    tipoVertice v, aux;
    bool fim_lista;
    tipoPeso peso;
    fila* f = new fila();

    cores[u] = cinza;
    dist[u] = 0;

    f->enqueue(u);
    std::cout << std::format("Visita origem: {:4d};           Fila: ", u);
    f->imprimir();

    while(!f->vazia()){
        u = f->dequeue();

        if(!g->lista_adjacencia_vazia(u)){
            aux = g->get_primeiro_adjacencia(u);
            fim_lista = false;

            while(!fim_lista){
                v = g->prox_adjacencia(u, peso, aux, fim_lista);

                if(cores[v] == branco){
                    cores[v] = cinza;
                    dist[v] = dist[u] + 1;
                    p->push(v);
                    f->enqueue(v);
                }
            }
        }

        cores[u] = preto;
        std::cout << std::format("Visita origem: {:4d}; Dist: {:2}; Fila: ", u, dist[u]);
        f->imprimir();
    }
}

void algoritmos::ordenacao_topologica(grafo* g)
{
    const int NUM_VERTICES = g->get_num_vertices();

    cor cores[MAX_NUM_VERTICES];
    tipoVertice u;
    tipoTempo tempo {};
    tipoTempo t[MAX_NUM_VERTICES];
    pilha* vertices_ordenados = new pilha();

    for(u = 0; u < NUM_VERTICES; ++u){
        cores[u] = branco;
    }

    for(u = 0; u < NUM_VERTICES; ++u){
        if(cores[u] == branco){
            dfs(g, u, cores, tempo, t, vertices_ordenados);
        }
    }

    std::cout << "Ordenacao topologica: ";
    vertices_ordenados->imprimir();

    delete vertices_ordenados;
}

void algoritmos::dfs(grafo* g,
                     tipoVertice u,
                     cor* cores,
                     tipoTempo& tempo,
                     tipoTempo* t,
                     pilha* vertices_ordenados)
{
    tipoVertice v;
    bool fim_lista;
    tipoPeso peso;
    tipoVertice aux;

    cores[u] = cinza;

    if(!g->lista_adjacencia_vazia(u)){
        aux = g->get_primeiro_adjacencia(u);
        fim_lista = false;

        while(!fim_lista){
            v = g->prox_adjacencia(u, peso, aux, fim_lista);

            if(cores[v] == branco){
                dfs(g, v, cores, tempo, t, vertices_ordenados);
            }
        }
    }

    cores[u] = preto;
    t[u] = preto;
    vertices_ordenados->push(u);
}
