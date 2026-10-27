#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include "../include/interface.hpp"
#include "../include/grafo.hpp"
#include "../include/algoritmos_grafo.hpp"
#include "../include/algraph.mol.hpp"

grafo* carregar_arquivo(const std::string& nome_arquivo)
{
    std::ifstream arquivo(nome_arquivo);

    if(!arquivo.is_open()){
        std::cout << "Erro ao abrir arquivo: " << nome_arquivo << "\n";
        return nullptr;
    }

    std::string linha;
    tipoGrafo tipo{orientado};
    tipoVertice num_vertices{0};

    if(std::getline(arquivo, linha)){
        if(linha.find("sim") != -1){
            tipo = orientado;
        }
        else{
            tipo = nao_orientado;
        }
    }

    if(std::getline(arquivo, linha)){
        std::stringstream ss(linha);
        char igual_char;
        char v_char;
        ss >> v_char >> igual_char >> num_vertices;
    }

    if(num_vertices <= 0){
        std::cout << "numero de vertices invalido\n";
        arquivo.close();
        return nullptr;
    }

    grafo* g = new grafo(num_vertices, tipo);

    while(std::getline(arquivo, linha)){
        if(linha.empty()){
            continue;
        }

        std::stringstream ss(linha);
        char ch1, ch2, ch3, ch4;
        tipoVertice u, v;
        tipoPeso peso;

        if(ss >> ch1 >> u >> ch2 >> v >> ch3 >> ch4 >> peso){
            if(ch1 == '(' && ch2 == ',' && ch3 == ')' && ch4 == ':'){
                g->inserir_aresta(u, v, peso);
            }
        }
    }

    arquivo.close();
    return g;
}

void algraph_mol()
{
    int opcao;
    std::string str;

    do{
        interface_carregar_grafo();
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(opcao){
            case 1:{
                std::cout << "Insira o nome do arquivo: ";
                getline(std::cin, str);
                grafo* g = carregar_arquivo(str);
                cls();
                algraph_mol_execucao(g);
                delete g;
                break;
            }
            case 0:{
                std::cout << "Obrigado!!";
                break;
            }
            default:{
                std::cout << "Opcao invalida, tente novamente";
            }
        }
    }while(opcao != 0);
}

void algraph_mol_execucao(grafo* g)
{
    int opcao;
    std::string str;
    algoritmos algol;
    tipoVertice componente[MAX_NUM_VERTICES];
    tipoVertice origem;
    int num_mst {0};
    aresta* mst = new aresta[g->get_num_vertices()];

    do{
        menu_algoritmos();
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(opcao){
            case 1:{
                std::cout << "Insira o nome do arquivo de saida: ";
                getline(std::cin, str);
                g->exportar_graphviz(str);
                break;
            }
            case 2:{
                algol.busca_profundidade(*g);
                pause_3();
                cls();
                break;
            }
            case 3:{
                algol.busca_largura(*g);
                pause_3();
                cls();
                break;
            }
            case 4:{
                algol.ordenacao_topologica(*g);
                pause_3();
                cls();
                break;
            }
            case 5:{
                algol.componentes_fortemente_conexas(*g, componente);
                pause_3();
                cls();
                break;
            }
            case 6:{
                std::cout << "Insira o nome do arquivo de saida: ";
                getline(std::cin, str);
                g->exportar_graphviz(str, componente);
                break;
            }
            case 7:{
                std::cout << "Insira o vertice de origem: ";
                std::cin >> origem;
                algol.djikstra(*g, origem);
                pause_3();
                cls();
                break;
            }
            case 8:{
                algol.kruskal(*g, mst, num_mst);
                pause_3();
                cls();
                break;
            }
            case 9:{
                std::cout << "Insira o nome do arquivo de saida: ";
                getline(std::cin, str);
                g->exportar_graphviz_mst(str, mst, num_mst);
                break;
            }
            case 0:{
                cls();
                return;
            }
            default:{
                std::cout << "Opcao invalida, tente novamente\n";
                pause_3();
                cls();
                break;
            }
        }
    }while(opcao != 0);
}
