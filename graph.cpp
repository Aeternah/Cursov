#include "graph.h"
#include <iostream>
#include <stack> // Для реализации DFS
#include "graaflib/graph.h" // Подключаем графовые структуры из библиотеки Graaf



void addVertex(graaf::undirected_graph<int, int>& graph, int vertexData) {
    (void)graph.add_vertex(vertexData); // Игнорируем возвращаемое значение
}

void addVertex(graaf::undirected_graph<int, int>& graph, int vertexData) {
    graph.add_vertex(vertexData);
    std::cout << "Вершина с данными " << vertexData << " добавлена." << std::endl;
}

void addEdge(graaf::undirected_graph<int, int>& graph, int vertexFrom, int vertexTo, int edgeData) {
    auto vFrom = graph.add_vertex(vertexFrom);
    auto vTo = graph.add_vertex(vertexTo);
    graph.add_edge(vFrom, vTo, edgeData);
    std::cout << "Ребро от вершины " << vertexFrom << " к вершине " << vertexTo << " добавлено." << std::endl;
}

void performDFS(const graaf::undirected_graph<int, int>& graph, graaf::vertex_id_t startVertex) {
    std::cout << "Выполняем обход графа в глубину, начиная с вершины " << startVertex << ":" << std::endl;

    std::unordered_set<graaf::vertex_id_t> visited;
    std::stack<graaf::vertex_id_t> stack;
    stack.push(startVertex);

    while (!stack.empty()) {
        auto currentVertex = stack.top();
        stack.pop();

        // Если уже посещали эту вершину, пропускаем
        if (visited.find(currentVertex) != visited.end()) {
            continue;
        }

        visited.insert(currentVertex);
        std::cout << "Посещена вершина: " << currentVertex << std::endl;

        // Добавляем соседей в стек
        for (const auto& neighbor : graph.get_neighbors(currentVertex)) {
            if (visited.find(neighbor) == visited.end()) {
                stack.push(neighbor);
            }
        }
    }
}