#include <iostream>
#include "graph.h"

int main() {
    // Создание графа с начальной и целевой вершинами
    auto [graph, startVertex, targetVertex] = createGraphWithStartAndTarget();

    // Выводим начальную и целевую вершины для проверки
    std::cout << "Starting DFS from vertex " << startVertex << " to reach vertex " << targetVertex << "." << std::endl;
    
    // Обход графа в глубину
    performDFS(graph, startVertex);

    return 0;
}
