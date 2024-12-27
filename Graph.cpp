#include <iostream>
using namespace std;

class Graph {
private:
    int numVertices;
    int** adjMatrix;  // Adjacency matrix to store graph edges (0 or 1)

public:
    // Constructor to initialize the graph with a specified number of vertices
    Graph(int vertices) {
        numVertices = vertices;
        // Array of int pointers
        adjMatrix = new int*[numVertices];  // Allocate memory for rows of the matrix
        for (int i = 0; i < numVertices; i++) {
            // Array of int types
            adjMatrix[i] = new int[numVertices];  // Allocate memory for each row's columns
            for (int j = 0; j < numVertices; j++) {
                adjMatrix[i][j] = 0;  // Initialize matrix values to 0 (no edges)
            }
        }
    }

    // Method to add an edge between two vertices i and j
    void addEdge(int i, int j, int weight) {
        if (i >= 0 && i < numVertices && j >= 0 && j < numVertices) {
            adjMatrix[i][j] = weight;  // Set the edge from vertex i to j as weight
            adjMatrix[j][i] = weight;  // Set the edge from vertex j to i as 1 (undirected graph)
        }
    }

    // Method to remove an edge between two vertices i and j
    void removeEdge(int i, int j) {
        if (i >= 0 && i < numVertices && j >= 0 && j < numVertices) {
            adjMatrix[i][j] = 0;  // Set the edge from vertex i to j as 0 (remove edge)
            adjMatrix[j][i] = 0;  // Set the edge from vertex j to i as 0 (remove edge)
        }
    }

    // Method to display the adjacency matrix
    void display() {
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";  // Print the vertex number
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";  // Print matrix values (0 or 1)
            }
            cout << endl;  // Move to the next line after each row
        }
    }
};

int main() {
    Graph g(3);  // Create a graph with 5 vertices

    g.display();  // Display the adjacency matrix representing the graph

    cout<<endl;

    // Add edges between vertices
    g.addEdge(0, 1, 2);

    g.display();  // Display the adjacency matrix representing the graph

    return 0;
}