#ifndef UNION_FIND_H_INCLUDED
#define UNION_FIND_H_INCLUDED

#include "utils.hpp"

class union_find{
private:
    tipoVertice pai[MAX_NUM_VERTICES];
    int tam[MAX_NUM_VERTICES];

public:
    explicit union_find(int);

    tipoVertice encontrar(tipoVertice);

    bool uniao(tipoVertice, tipoVertice);
};

#endif
