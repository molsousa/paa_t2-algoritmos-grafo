#ifndef ALGRAPH_MOL_HPP_INCLUDED
#define ALGRAPH_MOL_HPP_INCLUDED

#include "grafo.hpp"
#include <string>

/**
 * @brief Função para inicializar o programa.
 * @details Cria um novo grafo e abre opções de algoritmos
 *          para execução.
 * Pre-condicao: nenhuma.
 * Pos-condicao: nenhuma.
 */
void algraph_mol();

/**
 * @brief Função para carregar arquivo com grafo.
 * @details Extrai do arquivo de texto um grafo segundo a sintaxe prevista.
 * @param nome_arquivo arquivo de texto com grafo.
 * @returns grafo criado.
 * Pre-condicao: arquivo existente.
 * Pos-condicao: grafo criado.
 */
grafo* carregar_arquivo(const std::string&);

/**
 * @brief Função para executar o programa.
 * @details Executa os algoritmos que o usuario escolher
 *          em menu de opcoes.
 * @param g Grafo ja inicializado.
 * Pre-condicao: grafo inicializado.
 * Pos-condicao: nenhuma.
 */
void algraph_mol_execucao(grafo*);

#endif
