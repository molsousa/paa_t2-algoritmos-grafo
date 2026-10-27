#include <iostream>

#include "include/teste.h"

#include "include/fila.hpp"
#include "include/pilha.hpp"
#include "include/grafo.hpp"
#include "include/algoritmos_grafo.hpp"

int criar_grafo()
{
    grafo* g = new grafo(7, orientado);
    grafo* gT;
    algoritmos algol;
    tipoVertice componente[MAX_NUM_VERTICES];

    g->inserir_aresta(0, 5, 11);
    g->inserir_aresta(0, 3, 5);
    g->inserir_aresta(3, 2, 7);
    g->inserir_aresta(0, 2, 8);
    g->inserir_aresta(2, 5, 4);
    g->inserir_aresta(3, 1, 2);
    g->inserir_aresta(1, 4, 18);
    g->inserir_aresta(2, 4, 3);
    g->inserir_aresta(5, 4, -1);
    g->inserir_aresta(5, 6, 17);
    g->inserir_aresta(4, 6, 5);

    /*
    g->inserir_aresta(0, 1, 11);
    g->inserir_aresta(0, 2, -4);
    g->inserir_aresta(3, 0, 2);
    g->inserir_aresta(3, 2, 8);
    g->inserir_aresta(1, 3, -5);
    g->inserir_aresta(2, 4, 7);
    g->inserir_aresta(4, 2, 19);
    */

    g->exportar_graphviz("grafo.dot");

    g->imprimir_grafo();
    std::cout << "\n";

    algol.busca_profundidade(*g);
    std::cout << "\n";

    algol.busca_largura(*g);
    std::cout << "\n";

    algol.ordenacao_topologica(*g);

    gT = g->grafo_transposto();

    gT->imprimir_grafo();

    algol.djikstra(*g, 3);

    algol.componentes_fortemente_conexas(*g, componente);
    g->exportar_graphviz("cfc.dot", componente);

    algol.kruskal(*g);

    delete gT;
    delete g;

    return 0;
}

int teste_fila()
{
    fila* f = new fila();

    if(f == nullptr){
        return 1;
    }

    f->enqueue(1);
    f->enqueue(4);
    f->enqueue(7);
    f->enqueue(9);
    f->enqueue(21);
    f->enqueue(15);
    f->enqueue(12);

    f->imprimir();

    delete f;

    return 0;
}

int teste_pilha()
{
    pilha* p = new pilha();

    if(p == nullptr){
        return -1;
    }

    p->push(14);
    p->push(7);
    p->push(10);
    p->push(3);
    p->push(4);
    p->push(2);
    p->push(21);

    p->imprimir();

    return 0;
}


