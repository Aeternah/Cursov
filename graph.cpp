#include "graph.h"
#include <iostream>
#include <stack> // For DFS implementation
#include "graaflib/graph.h" // Including graph structures from the Graaf library

// Function to add a vertex to the graph
void addVertex(graaf::undirected_graph<int, int>& graph, int vertexData) {
    auto vertexId = graph.add_vertex(vertexData); // Add a vertex and get its ID
    std::cout << "Vertex with data " << vertexData << " added (ID: " << vertexId << ")." << std::endl;
}

// Function to add an edge to the graph
void addEdge(graaf::undirected_graph<int, int>& graph, int vertexFrom, int vertexTo, int edgeData) {
    auto vFrom = graph.add_vertex(vertexFrom); // Ensure the vertex exists
    auto vTo = graph.add_vertex(vertexTo);     // Ensure the vertex exists
    graph.add_edge(vFrom, vTo, edgeData);      // Add the edge
    std::cout << "Edge from vertex " << vertexFrom << " to vertex " << vertexTo
              << " added with data: " << edgeData << "." << std::endl;
}

// Function to perform depth-first search (DFS)
void performDFS(const graaf::undirected_graph<int, int>& graph, graaf::vertex_id_t startVertex) {
    std::cout << "Performing DFS starting from vertex " << startVertex << ":" << std::endl;

    std::unordered_set<graaf::vertex_id_t> visited; // Set to store visited vertices
    std::stack<graaf::vertex_id_t> stack;           // Stack for traversal
    stack.push(startVertex);

    while (!stack.empty()) {
        auto currentVertex = stack.top();
        stack.pop();

        // Skip already visited vertices
        if (visited.find(currentVertex) != visited.end()) {
            continue;
        }

        // Mark the vertex as visited
        visited.insert(currentVertex);
        std::cout << "Visited vertex: " << currentVertex << std::endl;

        // Add neighbors of the current vertex to the stack
        for (const auto& neighbor : graph.get_neighbors(currentVertex)) {
            if (visited.find(neighbor) == visited.end()) {
                stack.push(neighbor);
            }
        }
    }
}
