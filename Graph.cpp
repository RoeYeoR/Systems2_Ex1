//315144972
//roeyshmil09@gmail.com

#include <iostream>
#include "Graph.hpp"

namespace ariel {

    Graph::Graph() {}
    Graph::Graph(int n) : adjMatrix(n, std::vector<int>(n, 0)) {}

    bool Graph::get_is_directed() const
    {
        return is_directed;
    }

    std::vector<std::vector<int>> Graph::get_adjMatrix() const
    {
        return adjMatrix;
    }

   
    bool Graph::containsNegativeWeights() const{
        int n = adjMatrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (adjMatrix[i][j] < 0) {
                    return true;
                }
            }
        }
        return false;
    }

    bool Graph::isDirected(const std::vector<std::vector<int>>& matrix) const {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (matrix[i][j] != matrix[j][i]) {
                    return true; // Asymmetry found, indicating a directed graph
                }
            }
        }
        return false; // No asymmetry found, indicating an undirected graph
    }
        int Graph::countEdges() const {
        int numOfEdges = 0;

        for (int i = 0; i < adjMatrix.size(); i++) {
            for (int j = 0; j < adjMatrix.size(); j++) {
                if (adjMatrix[i][j] != 0) {
                numOfEdges++;
                }
            }

        }
        if(!is_directed)
        {
            numOfEdges /=2;
        }
        return numOfEdges;
    }

     Graph Graph::getTranspose() const {
        int n = adjMatrix.size();
        Graph gT(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (adjMatrix[i][j]) {
                    gT.adjMatrix[j][i] = 1;
                }
            }
        }
        return gT;
    }

    void Graph::loadGraph(const std::vector<std::vector<int>>& adj_Mat) {

        // Check if the matrix is square
        if (adj_Mat.size() != adj_Mat[0].size()) 
        {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
        //check if there is a vertex with dist to itself !=0
        for(int i=0; i<adj_Mat.size();i++)
        {
            if(adj_Mat[i][i] != 0)
            {
             throw std::invalid_argument("Invalid graph: At least one vertex with distance to itself != 0.");
            }
        }

        adjMatrix = adj_Mat;
        is_directed = isDirected(adjMatrix);
        numOfVertices = adjMatrix.size();
        numOfEdges = countEdges();


    }

        void Graph::printGraph() const {
        

        std::cout << "Graph with " << numOfVertices << " vertices and "<< numOfEdges << " edges." << std::endl;
        
    }

}

