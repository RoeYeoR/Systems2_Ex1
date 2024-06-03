#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected") {
    ariel::Graph g;

    // Test Case 1: Simple connected undirected graph
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(g) == "1");

    // Test Case 2: Disconnected undirected graph
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == "0");

    // Test Case 3: Single vertex undirected graph
    vector<vector<int>> graph3 = {
        {0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == "1");

    // Test Case 4: Graph with all zeros 
    vector<vector<int>> graph4 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isConnected(g) == "0");

    // Test Case 5: Connected directed graph 
    vector<vector<int>> graph5 = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isConnected(g) == "1");

    // Test Case 6: Disconnected directed graph
    vector<vector<int>> graph6 = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::isConnected(g) == "0");
}

TEST_CASE("Test shortestPath") {
    ariel::Graph g;

    // Test Case 1: Simple path in undirected graph
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    // Test Case 2: No path in undirected graph
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "-1");

    // Test Case 3: Shortest path in undirected graph
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "-1");

    // Test Case 4: Shortest path in directed graph
    vector<vector<int>> graph4 = {
        {0, 1, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->3");

    // Test Case 5: No path in directed graph
    vector<vector<int>> graph5 = {
    {0, 1, 1, 0},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {0, 0, 1, 0}};

    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->2->3");

    // Test Case 5: No path in directed graph
    vector<vector<int>> graph6 = {
    {0, 1, -1},
    {1, 0, 2},
    {-1, 2, 0}};

    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "-1");
}

TEST_CASE("Test isContainsCycle") {
    ariel::Graph g;

    // Test Case 1: No cycle in undirected graph
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");

    // Test Case 2: Cycle in undirected graph
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0->1->2->0");

    // Test Case 3: No cycle in undirected graph
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");

   

     // Test Case 5: No cycle in directed graph
    vector<vector<int>> graph5 = {
        {0, 1, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");
}

TEST_CASE("Test isBipartite") {
    ariel::Graph g;

    // Test Case 1: Bipartite graph
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    // Test Case 2: Not bipartite graph
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    // Test Case 3: Bipartite graph
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3}");

    // Test Case 4: Bipartite graph with 2 edges 
    vector<vector<int>> graph4 = {
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3}");

    // Test Case 5: bipartite graph with 3 edges
    vector<vector<int>> graph5 = {
        {0, 1, 1, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 1},
        {0, 0, 1, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 3}, B={1, 2}");
}

TEST_CASE("Test negative cycles")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, -1, 4, 0, 0},
        {0, 0, 3, 2, 2},
        {0, 0, 0, 0, 0},
        {0, 1, 5, 0, 0},
        {0, 0, 0, -5, 0}
    };
    g1.loadGraph(graph1);
    CHECK(ariel::Algorithms::negativeCycle(g1) == "The graph contains a negative cycle");

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 4, 0, 0},
        {0, 0, 3, 2, 2},
        {0, 0, 0, 0, 0},
        {0, 1, 5, 0, 0},
        {0, 0, 0, 1, 0}
    };
    g2.loadGraph(graph2);
    CHECK(ariel::Algorithms::negativeCycle(g2) == "The graph does not contain any negative cycles");

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 2, 0},
        {0, 0, 1},
        {-4, 0, 0}
       
    };
    g3.loadGraph(graph3);
    CHECK(ariel::Algorithms::negativeCycle(g3) == "The graph contains a negative cycle");

    ariel::Graph g4;
    vector<vector<int>> graph4 = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0}
    };
    g4.loadGraph(graph4);
    CHECK(ariel::Algorithms::negativeCycle(g4) == "The graph does not contain any negative cycles");

    ariel::Graph g5;
    vector<vector<int>> graph5 = {
        {0, 3, 0, 0, -4},
        {0, 0, 2, 0, 0},
        {0, 0, 0, 1, 0},
        {0, -5, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    g5.loadGraph(graph5);
    CHECK(ariel::Algorithms::negativeCycle(g5) == "The graph contains a negative cycle");
}


TEST_CASE("Test invalid Graph")
{

ariel::Graph g;

// Test Case 1: Invalid graph (matrix is not square)
vector<vector<int>> graph1 = {
    {0, 1, 2},
    {1, 0, 3},
    {2, 3, 0},
    {0, 0, 4},
    {0, 0, 0}};
CHECK_THROWS_WITH(g.loadGraph(graph1), "Invalid graph: The graph is not a square matrix.");


// Test Case 4: Invalid graph (non-square matrix)
vector<vector<int>> graph4 = {
    {0, 1, 0, 0},
    {1, 0, 0, 0},
    {0, 0, 1, 0}};
CHECK_THROWS_WITH(g.loadGraph(graph4), "Invalid graph: The graph is not a square matrix.");

// Test Case 5: Invalid graph (non-square matrix)
vector<vector<int>> graph5 = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
    {0, 0, 0}};
CHECK_THROWS_WITH(g.loadGraph(graph5), "Invalid graph: The graph is not a square matrix.");
}





