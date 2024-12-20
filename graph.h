#ifndef GRAPH_H
#define GRAPH_H

#include <graph.h>
#include "graaflib/edge.h"
#include <unordered_set>

// Функция для добавления вершины
void addVertex(graaf::undirected_graph<int, int>& graph, int vertexData);

// Функция для добавления рёбер
void addEdge(graaf::undirected_graph<int, int>& graph, int vertexFrom, int vertexTo, int edgeData);

// Функция для выполнения обхода в глубину
void performDFS(const graaf::undirected_graph<int, int>& graph, graaf::vertex_id_t startVertex);

#endif // GRAPH_H