#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <iostream>

const std::string separador {"+                                     +\n"};
const std::string finalizar {"+++++++++++++++++++++++++++++++++++++++\n"};
const std::string logo {"\033[38;5;46m╔═╗╦  ╔═╗╦═╗╔═╗╔═╗╦ ╦\033[0m \033[38;5;226m╔╦╗╔═╗╦\033[0m\n"
                        "\033[38;5;40m╠═╣║  ║ ╦╠╦╝╠═╣╠═╝╠═╣\033[0m\033[38;5;220m.\033[0m\033[38;5;220m║║║║ ║║\033[0m\n"
                        "\033[38;5;34m╩ ╩╩═╝╚═╝╩╚═╩ ╩╩  ╩ ╩\033[0m \033[38;5;214m╩ ╩╚═╝╩═╝\033[0m\n\n"};

/**
 * @brief Função para mostrar na tela o menu de menu_algoritmos
 * Pre-condicao: nenhuma.
 * Pos-condicao: nenhuma.
 */
void menu_algoritmos();

/**
 * @brief Função para mostrar na tela opção de carregar grafo.
 * Pre-condicao: nenhuma.
 * Pos-condicao: nenhuma.
 */
void interface_carregar_grafo();

/**
 * @brief Função para limpar o terminal.
 * @details Adaptado para windows e linux.
 * Pre-condicao: nenhuma.
 * Pos-condicao: nenhuma.
 */
void cls();

/**
 * @brief Função para pausar o terminal.
 * @details Pausa o terminal por quanto tmepo o usuario desejar.
 * Pre-condicao: nenhuma.
 * Pos-condicao: nenhuma.
 */
void pause_3();

/**
 * @brief Função para pausar o terminal por 5 segundos.
 * Pre-condicao: nenhuma.
 * Pos-condicao: nenhuma.
 */
void pause_5();

/**
 * @brief Função para limpar o buffer.
 * @details Retira o '\n' do buffer.
 * Pre-condicao: '\n' presente no buffer.
 * Pos-condicao: retira o caractere.
 */
void limpar_buffer();

#endif
