#include "graph.h"
#include <iostream>
#include <stack> // Для реализации поиска в глубину (DFS)
#include "graaflib/graph.h" // Подключение структур графов из библиотеки Graaf

// Функция для добавления вершины в граф
void addVertex(graaf::directed_graph<int, int>& graph, int vertexData) {
    auto vertexId = graph.add_vertex(vertexData); // Добавление вершины и получение её ID
    std::cout << "Vertex with data " << vertexData << " added (ID: " << vertexId << ")." << std::endl;
}

// Функция для добавления ребра в граф
void addEdge(graaf::directed_graph<int, int>& graph, int vertexFrom, int vertexTo, int edgeData) {
    auto vFrom = graph.add_vertex(vertexFrom); // Убедиться, что вершина существует
    auto vTo = graph.add_vertex(vertexTo);     // Убедиться, что вершина существует
    graph.add_edge(vFrom, vTo, edgeData);      // Добавление ребра
    std::cout << "Edge from vertex " << vertexFrom << " to vertex " << vertexTo
            << " added with data: " << edgeData << "." << std::endl;
}

// Функция для выполнения поиска в глубину (DFS)
void performDFS(const graaf::directed_graph<int, int>& graph, graaf::vertex_id_t startVertex) {
    std::cout << "Performing Depth First Search, starting from vertex " << startVertex << ":" << std::endl;

    std::unordered_set<graaf::vertex_id_t> visited; // Множество для хранения посещённых вершин
    std::stack<graaf::vertex_id_t> stack;           // Стек для обхода графа
    stack.push(startVertex);

    while (!stack.empty()) {
        auto currentVertex = stack.top();
        stack.pop();

        // Пропуск уже посещённых вершин
        if (visited.find(currentVertex) != visited.end()) {
            continue;
        }

        // Отмечаем вершину как посещённую
        visited.insert(currentVertex);
        std::cout << "Visited vertex: " << currentVertex << std::endl;

        // Выводим соседей для текущей вершины
        std::cout << "Neighbors of vertex " << currentVertex << ": ";
        bool hasNeighbors = false;
        for (const auto& neighbor : graph.get_neighbors(currentVertex)) {
            std::cout << neighbor << " ";
            hasNeighbors = true;
            stack.push(neighbor); // Добавляем соседей в стек
        }
        if (!hasNeighbors) {
            std::cout << "None";
        }
        std::cout << std::endl;

        // Выводим информацию о завершении обхода вершины
        std::cout << "Finished processing vertex: " << currentVertex << std::endl;
    }

    std::cout << "DFS traversal completed." << std::endl;
}

// Функция для создания графа с начальной и целевой вершинами
std::tuple<graaf::directed_graph<int, int>, graaf::vertex_id_t, graaf::vertex_id_t> createGraphWithStartAndTarget() {
    graaf::directed_graph<int, int> graph;

    // Добавление вершин
    const auto vertex_1{graph.add_vertex(10)}; // ID: 0
    const auto vertex_2{graph.add_vertex(20)}; // ID: 1
    const auto vertex_3{graph.add_vertex(30)}; // ID: 2
    const auto vertex_4{graph.add_vertex(40)}; // ID: 3
    const auto vertex_5{graph.add_vertex(50)}; // ID: 4
    const auto vertex_6{graph.add_vertex(60)}; // ID: 5

    // Добавление рёбер
    graph.add_edge(vertex_1, vertex_2, 100); // 1 -> 2
    graph.add_edge(vertex_3, vertex_2, 200); // 3 -> 2
    graph.add_edge(vertex_3, vertex_5, 300); // 3 -> 5
    graph.add_edge(vertex_2, vertex_4, 400); // 2 -> 4
    graph.add_edge(vertex_4, vertex_3, 500); // 4 -> 3
    graph.add_edge(vertex_4, vertex_6, 600); // 4 -> 6
    graph.add_edge(vertex_6, vertex_3, 700); // 6 -> 3

    // Возвращаем граф и начальную/целевую вершину по ID
    // Здесь начальная вершина vertex_1 и целевая vertex_2
    return {graph, vertex_1, vertex_2};
}

