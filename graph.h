#ifndef GRAPH_H
#define GRAPH_H

#include "graaflib/graph.h"
#include <unordered_set>

// Функция для добавления вершины в граф
void addVertex(graaf::directed_graph<int, int>& graph, int vertexData);

// Функция для добавления рёбер в граф
void addEdge(graaf::directed_graph<int, int>& graph, int vertexFrom, int vertexTo, int edgeData);

// Функция для выполнения обхода в глубину (DFS)
void performDFS(const graaf::directed_graph<int, int>& graph, graaf::vertex_id_t startVertex);

// Функция для создания графа с начальной и целевой вершинами
std::tuple<graaf::directed_graph<int, int>, graaf::vertex_id_t, graaf::vertex_id_t> createGraphWithStartAndTarget();

#endif // GRAPH_H
