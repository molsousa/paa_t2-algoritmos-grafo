#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <limits>

/// Definição de tipo para vértice.
typedef int tipoVertice;
/// Definição de tipo para tempo de acesso a vértice.
typedef int tipoTempo;
/// Definição de tipo para peso de aresta.
typedef double tipoPeso;

/// @enum cor Enumeração para cores de cada vértice.
typedef enum {preto, branco, cinza} cor;
/// @enum tipoGrafo Enumeração para tipos de grafo <orientado> e <nao_orientado>
typedef enum {orientado, nao_orientado} tipoGrafo;

/// Definição de constante <INFINITO> para valor máximo de peso.
const double INFINITO {std::numeric_limits<double>::max()};
/// Definição de constante <INFINITO_VERTICE> para valor máximo de vértice.
const tipoVertice INFINITO_VERTICE {std::numeric_limits<tipoVertice>::max()};
/// Definição de constante <MAX_NUM_VERTICES> para máximo de vértices criados.
const int MAX_NUM_VERTICES {4500};

#endif
