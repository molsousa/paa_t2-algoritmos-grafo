#include "../include/interface.hpp"

void menu_algoritmos()
{
    std::cout << "+++++++++++++ Algraph.mol +++++++++++++\n";
    std::cout << separador;
    std::cout << "+ 1 - Desenhar grafo                  +\n";
    std::cout << "+ 2 - Busca em profundidade           +\n";
    std::cout << "+ 3 - Busca em largura                +\n";
    std::cout << "+ 4 - Ordenacao topologica            +\n";
    std::cout << "+ 5 - Componentes fortemente conexos  +\n";
    std::cout << "+ 6 - Desenhar grafo CFC              +\n";
    std::cout << "+ 7 - Djisktra                        +\n";
    std::cout << "+ 8 - Kruskal                         +\n";
    std::cout << "+ 9 - Desenhar grafo kruskal          +\n";
    std::cout << "+ 0 - Sair                            +\n";
    std::cout << separador;
    std::cout << finalizar;
}

void interface_carregar_grafo()
{
    std::cout << "+++++++++++++ Algraph.mol +++++++++++++\n";
    std::cout << separador;
    std::cout << "+ 1 - Carregar grafo                  +\n";
    std::cout << "+ 0 - Sair                            +\n";
    std::cout << separador;
    std::cout << finalizar;
}


void cls()
{
    #ifdef _WIN32
    system("cls");
    #elif __linux__
    system("clear");
    #endif
}

void pause_3()
{
    #ifdef _WIN32
    system("pause");
    #elif __linux__
    system("sleep 5");
    #endif
}

void pause_5()
{
    #ifdef _WIN32
    system("pause");
    #elif __linux__
    system("sleep 10");
    #endif
}
