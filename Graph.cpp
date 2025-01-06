#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph
{
    int vertex;         // Number of vertices
    list<int> *adjList; // Array of adjacency lists

public:
    Graph(int v)
    {
        vertex = v;
        adjList = new list<int>[v];
    }

    void addEdge(int x, int y)
    {
        adjList[x].push_back(y);
        adjList[y].push_back(x); // For undirected graph
    }

    void displayGraph()
    {
        for (int i = 0; i < vertex; i++)
        {
            cout << "Vertex: " << i << " -> ";
            for (int item : adjList[i])
            {
                cout << item << " ";
            }
            cout << endl;
        }
    }

    void bfs(int start)
    {
        bool visited[vertex] = {false}; // Track visited vertices
        queue<int> q;                   // Queue for BFS

        visited[start] = true;
        q.push(start);

        cout << "BFS starting from vertex " << start << ": ";
        while (!q.empty())
        {
            int current = q.front();
            cout << current << " ";
            q.pop();

            // Visit all unvisited neighbors
            for (int item : adjList[current])
            {
                if (!visited[item])
                {
                    visited[item] = true;
                    q.push(item);
                }
            }
        }
        cout << endl;
    }

    void dfs(int current, bool visited[])
    {
        visited[current] = true;
        cout << current << " ";

        // Visit all unvisited neighbors
        for (int item : adjList[current])
        {
            if (!visited[item])
            {
                dfs(item, visited);
            }
        }
    }

    void dfs(int start)
    {
        bool visited[vertex] = {false}; // Track visited vertices
        cout << "DFS starting from vertex " << start << ": ";
        dfs(start, visited); // Calling the same function
        cout << endl;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    cout << "Graph Representation:" << endl;
    g.displayGraph();

    cout << endl;
    g.bfs(0); // Perform BFS starting from vertex 0
    g.dfs(0); // Perform DFS starting from vertex 0

    return 0;
}