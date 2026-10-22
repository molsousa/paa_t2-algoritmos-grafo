#include "../../include/union_find.hpp"

union_find::union_find(int n)
{
    for(tipoVertice i{}; i < n; ++i){
        pai[i] = i;
        tam[i] = 1;
    }
}

tipoVertice union_find::encontrar(tipoVertice x)
{
    while(pai[x] != x){
        pai[x] = pai[pai[x]];
        x = pai[x];
    }

    return x;
}

bool union_find::uniao(tipoVertice x, tipoVertice y)
{
    tipoVertice u = encontrar(x);
    tipoVertice v = encontrar(y);

    if(u == v){
        return false;
    }

    if(tam[u] < tam[v]){
        tipoVertice aux = u;
        u = v;
        v = aux;
    }

    pai[v] = u;
    tam[u] += tam[v];

    return true;
}
