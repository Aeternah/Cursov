#include <iostream>
#include "graph.h"
#include "graaflib/graph.h"

int main() {
    graaf::undirected_graph<int, int> graph;

    // Добавление вершин и рёбер
    addVertex(graph, 1);
    addVertex(graph, 2);
    addVertex(graph, 3);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 2, 3, 20);

    // Обход графа
    performDFS(graph, 1);

    return 0;
}
