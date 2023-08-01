#include <iostream>
using namespace std;

// Node for representing an edge in the graph
struct Node {
    int data;
    Node* next;
};

// Graph class representing the adjacency list representation of a graph
class Graph {
private:
    int V; // Number of vertices
    Node** adjList; // Array of linked lists

public:
    Graph(int v) : V(v) {
        adjList = new Node*[V];
        for (int i = 0; i < V; i++)
            adjList[i] = nullptr;
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        Node* newNode = new Node;
        newNode->data = v;
        newNode->next = adjList[u];
        adjList[u] = newNode;
    }

    // Recursive helper function for DFS
    void DFSUtil(int v, bool* visited) {
        visited[v] = true;
        cout << v << " ";

        Node* temp = adjList[v];
        while (temp) {
            int u = temp->data;
            if (!visited[u]) {
                DFSUtil(u, visited);
            }
            temp = temp->next;
        }
    }

    // DFS traversal starting from vertex v
    void DFS(int v) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        DFSUtil(v, visited);
        cout << endl;

        delete[] visited;
    }
};

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "DFS traversal starting from vertex 0: ";
    g.DFS(0);

    return 0;
}