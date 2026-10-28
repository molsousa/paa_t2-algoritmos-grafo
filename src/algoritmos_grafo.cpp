#include <iostream>
#include <format>
#include "../include/aresta.hpp"
#include "../include/union_find.hpp"
#include "../include/algoritmos_grafo.hpp"

/**
 * @brief Algoritmo de busca em profundidade.
 * @details Utiliza uma pilha para armazenar os pais dos vértices visitados;
 *          cria vetores de tempo de descoberta e tempo final, além de uma
 *          variável de tempo; todos os vértices são inicializados com cor branca;
 * @param g grafo.
 */
void algoritmos::busca_profundidade(grafo& g)
{
    const int NUM_VERTICES = g.get_num_vertices();

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

/**
 * @brief Função-membro para aplicar algoritmo DFS.
 * @details Aplica algoritmo DFS (Depth-First Search) recebendo os
 *          vértices brancos, transformando-os em cinza quando acessados
 *          e preto quando finalizados. O algoritmo pode ser implementado
 *          com pilha como alternativa à recursão. São impressos na tela
 *          tanto o tempo de descoberta quanto o tempo final.
 * @param g grafo.
 * @param u Vértice referência.
 * @param cores Vetor de cores para início, descoberta ou término de vértices.
 * @param p Pilha de vértices.
 * @param tempo Referência para tempo global.
 * @param d Vetor de tempo de descoberta do vértice.
 * @param t Vetor de tempo de término.
 */
void algoritmos::dfs(grafo& g,
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

    if(!g.lista_adjacencia_vazia(u)){
        aux = g.get_primeiro_adjacencia(u);
        fim_lista = false;

        while(!fim_lista){
            v = g.prox_adjacencia(u, peso, aux, fim_lista);

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

/**
 * @brief Algoritmo de busca em largura.
 * @details Utiliza vetores de distancia para calcular a profundidade do grafo;
 *          Todos os vértices são inicializados em branco; inicialmente a distancia
 *          é inicializada com infinito.
 * @param g grafo.
 */
void algoritmos::busca_largura(grafo& g)
{
    const int NUM_VERTICES = g.get_num_vertices();

    tipoVertice u;
    tipoVertice dist[MAX_NUM_VERTICES];
    cor cores[MAX_NUM_VERTICES];
    pilha* p = new pilha();

    for(u = 0; u < NUM_VERTICES; ++u){
        cores[u] = branco;
        dist[u] = INFINITO_VERTICE;
    }

    for(u = 0; u < NUM_VERTICES; ++u){

        if(cores[u] == branco){
            bfs(g, u, dist, cores);
        }
    }

    delete p;
}

/**
 * @brief Função-membro para aplicar algoritmo BFS
 * @details Aplica algoritmo BFS (Breadth First Search) recebendo vértices brancos,
 *          transformando em cinza quando acessados e preto quando finalizados;
 *          O algoritmo é baseado no uso de fila para acesso em largura.
 * @param g grafo.
 * @param u Vértice referência.
 * @param dist Vetor de distância.
 * @param cores Vetor de cores para início, descoberta ou término de vértices.
 * @param p Pilha de vértices.
 */
void algoritmos::bfs(grafo& g,
                     tipoVertice u,
                     tipoVertice* dist,
                     cor* cores)
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

        if(!g.lista_adjacencia_vazia(u)){
            aux = g.get_primeiro_adjacencia(u);
            fim_lista = false;

            while(!fim_lista){
                v = g.prox_adjacencia(u, peso, aux, fim_lista);

                if(cores[v] == branco){
                    cores[v] = cinza;
                    dist[v] = dist[u] + 1;
                    f->enqueue(v);
                }
            }
        }

        cores[u] = preto;
        std::cout << std::format("Visita origem: {:4d}; Dist: {:2}; Fila: ", u, dist[u]);
        f->imprimir();
    }
}

/**
 * @brief Algoritmo de ordenação topológica.
 * @details Utiliza uma pilha para ordenar os vértices com base no tempo de término
 * @param g grafo.
 */
void algoritmos::ordenacao_topologica(grafo& g)
{
    const int NUM_VERTICES = g.get_num_vertices();

    cor cores[MAX_NUM_VERTICES];
    tipoVertice u;
    pilha* vertices_ordenados = new pilha();

    for(u = 0; u < NUM_VERTICES; ++u){
        cores[u] = branco;
    }

    bool ok;

    for(u = 0; u < NUM_VERTICES; ++u){
        if(cores[u] == branco){
            ok = dfs(g, u, cores, vertices_ordenados, true);
        }
    }

    if(ok){
        std::cout << "Ordenacao topologica: ";
        vertices_ordenados->imprimir();
    }
    else{
        std::cout << "\n";
    }

    delete vertices_ordenados;
}

/**
 * @brief Função-membro para aplicar algoritmo DFS.
 * @details Versão alternativa do algoritmo DFS focado em servir de
 *          base para ordenacao topologica e componentes fortemente
 *          conexos; imprime na tela caso uma ordenacao topologica
 *          for impossivel; possui demarcador para caso seja necessario
 *          verificar ciclo (so seria necessario em ordenacao topologica);
 *          É utilizado uma pilha de vértices para a ordenacao.
 * @param g grafo.
 * @param u Vértice referencia.
 * @param cores vetor de cores.
 * @param vertices_ordenados pilha de vértices ordenados.
 * @param ciclo variavel booleana para caso precise verificar ciclo ou nao.
 * @overload
 */
bool algoritmos::dfs(grafo& g,
                     tipoVertice u,
                     cor* cores,
                     pilha* vertices_ordenados,
                     bool ciclo)
{
    tipoVertice v;
    bool fim_lista;
    tipoPeso peso;
    tipoVertice aux;

    cores[u] = cinza;

    if(!g.lista_adjacencia_vazia(u)){
        aux = g.get_primeiro_adjacencia(u);
        fim_lista = false;

        while(!fim_lista){
            v = g.prox_adjacencia(u, peso, aux, fim_lista);

            if(ciclo && cores[v] == cinza){
                std::cout << std::format("Ciclo: {:d} -> {:d}. Ordenacao topologica impossivel.\n", u, v);
                return false;
            }

            if(cores[v] == branco){
                if(!dfs(g, v, cores, vertices_ordenados, ciclo)){
                    return false;
                }
            }
        }
    }

    cores[u] = preto;
    vertices_ordenados->push(u);
    return true;
}

/**
 * @brief Função membro para verificar componentes fortemente conexos.
 * @details Imprime na tela vértices com componentes fortemente conexos;
 *          utiliza o algoritmo dfs overload e tambem uma modificacao do
 *          dfs para visita no grafo tranposto;
 * @param g grafo.
 */
void algoritmos::componentes_fortemente_conexas(grafo& g, tipoVertice* componente)
{
    const int NUM_VERTICES = g.get_num_vertices();

    cor cores[MAX_NUM_VERTICES];
    tipoVertice u;
    pilha* vertices_ordenados = new pilha();

    for(u = 0; u < NUM_VERTICES; ++u){
        cores[u] = branco;
        componente[u] = -1;
    }

    for(u = 0; u < NUM_VERTICES; ++u){
        if(cores[u] == branco){
            dfs(g, u, cores, vertices_ordenados, false);
        }
    }

    grafo* gT = g.grafo_transposto();

    if(gT == nullptr){
        std::cout << "";
    }

    for(u = 0; u < NUM_VERTICES; ++u){
        cores[u] = branco;
    }

    int num_componentes {};

    while(!vertices_ordenados->vazia()){
        tipoVertice v = vertices_ordenados->pop();

        if(cores[v] == branco){
            dfs_componente(*gT, v, cores, componente, num_componentes);
            ++num_componentes;
        }
    }

    for(size_t i{}; i < num_componentes; ++i){
        std::cout << std::format("CFC {:2d}: ", i);

        for(u = 0; u < NUM_VERTICES; ++u){
            if(componente[u] == i){
                std::cout << std::format("{:3d}", u);
            }
        }

        std::cout << "\n";
    }

    std::cout << "\nTotal de CFC: " << num_componentes << "\n\n";

    delete gT;
    delete vertices_ordenados;
}

/**
 * @brief Função-membro com modificação do DFS para CFC
 * @details Objetivo da terceira modificação é adicionar os diferentes
 *          componentes dentro do vetor de componentes.
 * @param g grafo.
 * @param u vértice referencia.
 * @param cores vetor de cores.
 * @param componente vetor de componentes.
 * @param id_componente componente referencia.
 */
void algoritmos::dfs_componente(grafo& g, tipoVertice u, cor* cores, tipoVertice* componente, int id_componente)
{
    tipoVertice v;
    bool fim_lista;
    tipoPeso peso;
    tipoVertice aux;

    cores[u] = cinza;
    componente[u] = id_componente;

    if(!g.lista_adjacencia_vazia(u)){
        aux = g.get_primeiro_adjacencia(u);
        fim_lista = false;

        while(!fim_lista){
            v = g.prox_adjacencia(u, peso, aux, fim_lista);
            if(cores[v] == branco){
                dfs_componente(g, v, cores, componente, id_componente);
            }
        }
    }

    cores[u] = preto;
}

/**
 * @brief Algoritmo djikstra para encontrar menor caminho.
 * @details Algoritmo djikstra para menor caminho: o algoritmo nao admite valores de
 *          arestas negativas; utiliza um vetor de distancia e de pai, onde o vetor de
 *          distância é inicialiado com <INFINITO> e pai com <-1>; utiliza uma fila de
 *          prioridade para acessar o melhor caminho naquele momento; Caso o algoritmo
 *          perceba que o custo está aumentando, pode voltar e procurar outro melhor caminho;
 * @param g grafo.
 * @param origem vértice de origem.
 */
void algoritmos::djikstra(grafo& g, tipoVertice origem)
{
    const int NUM_VERTICES = g.get_num_vertices();

    tipoPeso dist[MAX_NUM_VERTICES];
    tipoVertice pai[MAX_NUM_VERTICES];
    cor cores[MAX_NUM_VERTICES];
    tipoVertice u;
    fila_prioridade* fp;
    bool fim_lista;
    tipoPeso peso;

    for(u = 0; u < NUM_VERTICES; ++u){
        dist[u] = INFINITO;
        pai[u] = -1;
        cores[u] = branco;
    }
    dist[origem] = .0;

    fp = new fila_prioridade(dist);
    fp->inserir(origem);

    while(!fp->vazia()){
        u = fp->retira_minimo();
        cores[u] = preto;
        std::cout << std::format("Visita: {:2d}; Pai: {:2d}; Dist: {:6.2f}\n", u, pai[u], dist[u]);

        if(g.lista_adjacencia_vazia(u)){
            continue;
        }

        tipoVertice aux = g.get_primeiro_adjacencia(u);
        fim_lista = false;

        while(!fim_lista){
            tipoVertice v = g.prox_adjacencia(u, peso, aux, fim_lista);

            if(peso < 0.0){
                continue;
            }

            if(cores[v] == preto){
                continue;
            }

            tipoPeso nova = dist[u] + peso;

            if(nova < dist[v]){
                pai[v] = u;
                dist[v] = nova;
                if(fp->contem(v)){
                    fp->diminui_chave(v);
                }
                else{
                    fp->inserir(v);
                }
            }
        }
    }

    std::cout << "\nDistancias a partir de " << origem << ":\n";
    for(u = 0; u < NUM_VERTICES; ++u){
        if(dist[u] == INFINITO){
            std::cout << std::format("   {:2d}: inalcancavel\n", u);
        }
        else{
            std::cout << std::format("   {:2d}: {:6.2f} (pai {:2d})\n", u, dist[u], pai[u]);
        }
    }
    std::cout << "\n";
}

/**
 * @brief Algoritmo de Kruskal.
 * @details Obtém uma AGM de um grafo adicionando a floresta uma aresta
 *          de fmenor peso que nao forma ciclo; o uso de <fila_prioridade>
 *          é para obter arestas em ordem crescente de peso; O algoritmo
 *          testa se forma ciclo utilizando conjuntos classe: <union_find>.
 * @param g grafo.
 */
void algoritmos::kruskal(grafo& g, aresta* mst, int& num_mst)
{
    const int NUM_VERTICES = g.get_num_vertices();

    aresta* arestas = new aresta[MAX_NUM_VERTICES*MAX_NUM_VERTICES/2];
    int k = g.extrair_arestas(arestas);

    std::sort(arestas, arestas + k, [](const aresta& a, const aresta& b){
        return a.peso < b.peso;
    });

    union_find* uf  = new union_find(NUM_VERTICES);
    tipoPeso peso_total = .0;

    std::cout << "Arestas da AGM Kruskal:\n";

    for(int i = 0; i < k && num_mst < NUM_VERTICES - 1; ++i){
        const aresta& e = arestas[i];

        if(uf->uniao(e.u, e.v)){
            std::cout << std::format("   ({:2d}, {:2d}) peso = {:6.2f}\n", e.u, e.v, e.peso);
            mst[num_mst++] = e;
            peso_total += e.peso;
        }
        else{
            std::cout << std::format("   ({:2d}, {:2d}) peso = {:6.2f}  [ignorada: ciclo]\n", e.u, e.v, e.peso);
        }
    }

    std::cout << std::format("\nPeso total da AGM: {:6.2f}\n", peso_total);

    if(num_mst < NUM_VERTICES - 1){
        std::cout << "Grafo desconexo, AGM cobre " << num_mst << " de " << NUM_VERTICES << " vertices resultando em floresta\n";
    }

    delete[] arestas;
    delete uf;
}
