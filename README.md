# Systems Programming B - C++ Programming: Graph Project
This repository contains the project assignment for the Systems Programming B course at Ariel University. The project focuses on implementing classes and algorithms related to graphs in C++.
## Graph.hpp

### Private Members:
- `bool is_directed`: Indicates whether the graph is directed or undirected.
- `int numOfVertices`: Number of vertices in the graph.
- `int numOfEdges`: Number of edges in the graph.
- `std::vector<std::vector<int>> adjMatrix`: Adjacency matrix representing the graph.

### Public Members:
- `Graph()`: Default constructor.
- `Graph(int n)`: Parameterized constructor to create a graph with n vertices.
- `bool get_is_directed() const`: Getter function for the `is_directed` member.
- `std::vector<std::vector<int>> get_adjMatrix() const`: Getter function for the adjacency matrix.
- `int countEdges() const`: Function to count the number of edges in the graph.
- `bool containsNegativeWeights() const`: Function to check if the graph contains negative weights.
- `bool isDirected(const std::vector<std::vector<int>>& matrix) const`: Function to check if the given adjacency matrix represents a directed graph.
- `Graph getTranspose() const`: Function to get the transpose of the graph.
- `void loadGraph(const std::vector<std::vector<int>>& adj_Mat)`: Function to load a graph from a given adjacency matrix.
- `void printGraph() const`: Function to print the graph.

## Algorithms.hpp

### Public Members:
- `static std::string isConnected(const Graph& g)`: Function to check if the graph is connected.
- `static std::string shortestPath(const Graph& g, int start, int end)`: Function to find the shortest path between two vertices.
- `static std::string isContainsCycle(const Graph& g)`: Function to check if the graph contains a cycle.
- `static std::string isBipartite(const Graph& g)`: Function to check if the graph is bipartite.
- `static std::string negativeCycle(const Graph& g)`: Function to detect a negative cycle in the graph.

### Private Members:
- `static bool BFS(const Graph& g, int start)`: Breadth-first search algorithm.
- `static std::string dijkstra(const Graph& g, int start, int end)`: Dijkstra's algorithm for finding the shortest path.
- `static std::string bellmanFord(const Graph& g, int start, int end)`: Bellman-Ford algorithm for finding the shortest path.
- `static std::string addPath(const std::vector<int>& prev, int start, int end)`: Utility function to add a path to the result.
- `static bool DFS_Directed(const Graph& g, int v, std::vector<bool>& visited, std::vector<int>& parent)`: Depth-first search for directed graphs.
- `static bool DFS_Undirected(const Graph& g, int v, std::vector<bool>& visited, std::vector<int>& parent, int parentVertex)`: Depth-first search for undirected graphs.
- `static bool bellmanFord_DetectCycle(const Graph& g, std::vector<int>& parent)`: Utility function to detect a cycle using Bellman-Ford algorithm.
- `static std::string addCycle(const std::vector<int>& parent, int start)`: Utility function to add a cycle to the result.
- `static bool BFS_Bipartite(const Graph& g, int start, std::vector<int>& color, std::unordered_set<int>& A, std::unordered_set<int>& B)`: Breadth-first search for checking bipartiteness.

