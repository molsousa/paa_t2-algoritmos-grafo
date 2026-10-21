#ifndef FILA_PRIORIDADE_H_INCLUDED
#define FILA_PRIORIDADE_H_INCLUDED

#include "utils.hpp"

class fila_prioridade
{
private:
    tipoVertice heap[MAX_NUM_VERTICES];
    int pos[MAX_NUM_VERTICES];
    int k;
    tipoPeso* dist;

    void troca(int, int);
    void refaz(int, int);

public:
    explicit fila_prioridade(tipoPeso*);

    bool vazia() const;

    bool contem(tipoVertice) const;

    void inserir(tipoVertice);

    void diminui_chave(tipoVertice);

    tipoVertice retira_minimo();
};

#endif
