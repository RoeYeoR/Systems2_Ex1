//315144972
//roeyshmil09@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <stdexcept>

namespace ariel {


class Graph {
    private:
        bool is_directed;
        int numOfVertices;
        int numOfEdges;
        std::vector<std::vector<int>> adjMatrix;

    public:
        Graph();
        Graph(int n);
        bool get_is_directed() const;
        std::vector<std::vector<int>> get_adjMatrix() const;
        int countEdges() const;
        bool containsNegativeWeights() const;   
        bool isDirected(const std::vector<std::vector<int>>& matrix) const;
        Graph getTranspose() const;
        void loadGraph(const std::vector<std::vector<int>>& adj_Mat);
        void printGraph() const;

};

} 

#endif // GRAPH_HPP
