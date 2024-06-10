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

    // Test Case 2: Graph with two nodes and one edge
    vector<vector<int>> graph2 = {
        {0, 1},
        {1, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == "1");

    // Test Case 3:  Graph with one vertex
    vector<vector<int>> graph3 = {
        {0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == "1");

    // Test Case 4: Graph with 3 vertices but no edges
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

     // Test Case 2: Check on directed graph with negative weights
    vector<vector<int>> graph2 = {
        {0, 4, 2},
        {0, 0, -3},
        {0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

     // Test Case 3: negative cycle in the graph,means -infinity for shortest path (not exist)
    vector<vector<int>> graph3 = {
        {0, 2, 1},
        {2, 0, -4},
        {1, -4, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "-1");


    // Test Case 4: 2 Binding components in the graph. 
    //Edge between 0-1 and edge between 2-3 but no path from 0 to 3
    vector<vector<int>> graph4 = {
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "-1");


    // Test Case 5: Shortest path in directed graph: 
    //Edge from 0->1 and 0->2 and edge from 1->3 and 2->3
    vector<vector<int>> graph5 = {
        {0, 1, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->3");

}

TEST_CASE("Test isContainsCycle") {
    ariel::Graph g;

    // Test Case 1: Check a cycle in undirected graph with edge 0-1 and 1-2
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



     // Test Case 4: Check for a cycle in directed graph
     // edges 0->1,1->3,3->2,2->0
    vector<vector<int>> graph4 = {
        {0, 1, 0, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0},
        {0, 0, 1, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0->1->3->2->0");

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

    // Test Case 1: Simple check
    // vertex 1 connected to vertex 0 and vertex 2 but no edge(connection) between 0 and 2.
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    // Test Case 2: Not bipartite graph 
    // it is a cycle so each vertex is connected to all other vertices
    //so it can not create 2 groups of vertices
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    // Test Case 3: Bipartite graph with 5 vertices and 4 edges
    // edges 0-3,0-4,1-2,1-3
    vector<vector<int>> graph3 = {
        {0, 0, 0, 1, 1},
        {0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 1}, B={2, 3, 4}");

    // Test Case 4: Bipartite graph with 2 edges
    // edges 0-1,2-3 
    vector<vector<int>> graph4 = {
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3}");

    // Test Case 5: bipartite graph with 3 edges
    //edges 0-1,0-2,2-3
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
    ariel::Graph g;

    // Test Case 1: Graph with 2 vertices and a negative cycle
    vector<vector<int>> graph1 = {
        {0, -1},
        {-1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph contains a negative cycle");

     // Test Case 2: Graph with 3 vertices and a negative cycle
    vector<vector<int>> graph2 = {
        {0, 3, 0},
        {0, 0, 1},
        {-6, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph contains a negative cycle");


   // Test Case 3: Simple undirected graph without a negative cycle
    vector<vector<int>> graph3 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph does not contain any negative cycles");

    // Test Case 4: Directed graph with a negative cycle
    vector<vector<int>> graph4 = {
        {0, 2, 0},
        {0, 0, 1},
        {-4, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph contains a negative cycle");

    // Test Case 5: Directed graph with a negative cycle
    vector<vector<int>> graph5 = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {-5, 0, 0, 0, 0}
    };
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph contains a negative cycle");

}

TEST_CASE("Test invalid Graph")
{

ariel::Graph g;

// Test Case 1: Invalid graph 5X3 (non-square matrix); rows > cols
vector<vector<int>> graph1 = {
    {0, 1, 2},
    {1, 0, 3},
    {2, 3, 0},
    {0, 0, 4},
    {0, 0, 0}};
CHECK_THROWS_WITH(g.loadGraph(graph1), "Invalid graph: The graph is not a square matrix.");


// Test Case 2: Invalid graph 3X4 (non-square matrix); cols > rows  
vector<vector<int>> graph2 = {
    {0, 1, 0, 0},
    {1, 0, 0, 0},
    {0, 0, 1, 0}};
CHECK_THROWS_WITH(g.loadGraph(graph2), "Invalid graph: The graph is not a square matrix.");



// Test Case 3: Invalid graph (square matrix but invalid vertices)
vector<vector<int>> graph3 = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1}};
   
CHECK_THROWS_WITH(g.loadGraph(graph3), "Invalid graph: At least one vertex with distance to itself != 0.");
}





