#include <iostream>
#include <vector>
#include "../include/algoritmos_grafo.hpp"
#include "../include/pilha.hpp"

void algoritmos::busca_profundidade(grafo* g)
{
    const int NUM_VERTICES = g->get_num_vertices();

    std::vector<cor> cores;
    std::vector<tipoVertice> pai;
    std::vector<int> tempo_descoberta;
    std::vector<int> tempo_final;

    pilha* p = new pilha();

    p->push();
}
