#include <iostream>
#include <cstdlib>
#include "../include/interface.hpp"

/**
 * @brief Função para mostrar na tela o menu de menu_algoritmos
 * Pre-condicao: nenhuma.
 * Pos-condicao: nenhuma.
 */
void menu_algoritmos()
{
    std::cout << logo;
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

/**
 * @brief Função para mostrar na tela opção de carregar grafo.
 * Pre-condicao: nenhuma.
 * Pos-condicao: nenhuma.
 */
void interface_carregar_grafo()
{
    std::cout << logo;
    std::cout << "+++++++++++++ Algraph.mol +++++++++++++\n";
    std::cout << separador;
    std::cout << "+ 1 - Carregar grafo                  +\n";
    std::cout << "+ 0 - Sair                            +\n";
    std::cout << separador;
    std::cout << finalizar;
}

/**
 * @brief Função para limpar o terminal.
 * @details Adaptado para windows e linux.
 * Pre-condicao: nenhuma.
 * Pos-condicao: nenhuma.
 */
void cls()
{
    #ifdef _WIN32
    system("cls");
    #elif __linux__
    system("clear");
    #endif
}

/**
 * @brief Função para pausar o terminal.
 * @details Pausa o terminal por quanto tmepo o usuario desejar.
 * Pre-condicao: nenhuma.
 * Pos-condicao: nenhuma.
 */
void pause_3()
{
    std::cin.get();
}

/**
 * @brief Função para pausar o terminal por 5 segundos.
 * Pre-condicao: nenhuma.
 * Pos-condicao: nenhuma.
 */
void pause_5()
{
    #ifdef _WIN32
    system("pause");
    #elif __linux__
    system("sleep 10");
    #endif
}

/**
 * @brief Função para limpar o buffer.
 * @details Retira o '\n' do buffer.
 * Pre-condicao: '\n' presente no buffer.
 * Pos-condicao: retira o caractere.
 */
void limpar_buffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
