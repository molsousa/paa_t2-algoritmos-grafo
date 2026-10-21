#include <iostream>
#include "../../include/fila_prioridade.hpp"

fila_prioridade::fila_prioridade(tipoPeso* dist) : k(0), dist(dist)
{
    for(size_t i{}; i < MAX_NUM_VERTICES; ++i){
        pos[i] = -1;
    }
}

bool fila_prioridade::vazia() const
{
    return k == 0;
}

bool fila_prioridade::contem(tipoVertice v) const
{
    return pos[v] != -1;
}

void fila_prioridade::troca(int i, int j)
{
    tipoVertice u {heap[i]};
    heap[i] = heap[j];
    heap[j] = u;
    pos[heap[i]] = i;
    pos[heap[j]] = j;
}

void fila_prioridade::refaz(int esq, int dir)
{
    int i = esq;
    int j = 2 * i;
    tipoVertice item = heap[i];

    while(j <= dir){
        if(j < dir && dist[heap[j]] > dist[heap[j+1]]){
            ++j;
        }

        if(dist[item] <= dist[heap[j]]){
            break;
        }

        heap[i] = heap[j];
        pos[heap[i]] = i;
        i = j;
        j = 2 * i;
    }

    heap[i] = item;
    pos[item] = i;
}

void fila_prioridade::inserir(tipoVertice v)
{
    ++k;
    heap[k] = v;
    pos[v] = k;
    int i = k;
    while(i > 1 && dist[heap[i/2]] > dist[heap[i]]){
        troca(i, i/2);
        i /= 2;
    }
}

tipoVertice fila_prioridade::retira_minimo()
{
    tipoVertice v = heap[1];
    pos[v] = -1;
    heap[1] = heap[k];
    pos[heap[1]] = 1;
    --k;

    if(k > 0){
        refaz(1, k);
    }

    return v;
}

void fila_prioridade::diminui_chave(tipoVertice v)
{
    int i = pos[v];
    while(i > 1 && dist[heap[i/2]] > dist[heap[i]]){
        troca(i, i/2);
        i /= 2;
    }
}
