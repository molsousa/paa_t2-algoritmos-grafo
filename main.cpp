#include "include/grafo.hpp"

int criar_grafo()
{
    grafo* g = new grafo(7, orientado);

    if(g == nullptr){
        return 1;
    }

    g->inserir_aresta(0, 0, 5);
    g->inserir_aresta(1, 5, 7);
    g->inserir_aresta(4, 6, 13);
    g->inserir_aresta(3, 1, 2);
    g->inserir_aresta(0, 3, 1);
    g->inserir_aresta(1, 2, 10);
    g->inserir_aresta(2, 0, 9);

    g->imprimir_grafo();

    delete g;

    return 0;
}

int main(int argc, char** argv)
{
    return criar_grafo();
}
