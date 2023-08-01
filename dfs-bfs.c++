#include <iostream>

using namespace std;

// Graph data structure using adjacency list
class Graph {
public:
    int V; // Number of vertices
    int** adj;

    Graph(int vertices) {
        V = vertices;
        adj = new int*[V];
        for (int i = 0; i < V; i++) {
            adj[i] = new int[V];
            for (int j = 0; j < V; j++)
                adj[i][j] = 0;
        }
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1; // For an undirected graph, add this line to make it bidirectional.
    }
};

void DFSUtil(int v, bool* visited, const Graph& graph) {
    visited[v] = true;
    cout << v << " ";

    for (int neighbor = 0; neighbor < graph.V; neighbor++) {
        if (graph.adj[v][neighbor] && !visited[neighbor]) {
            DFSUtil(neighbor, visited, graph);
        }
    }
}

void DFS(const Graph& graph) {
    bool* visited = new bool[graph.V];
    for (int i = 0; i < graph.V; ++i) {
        visited[i] = false;
    }

    for (int i = 0; i < graph.V; ++i) {
        if (!visited[i]) {
            DFSUtil(i, visited, graph);
        }
    }

    delete[] visited;
    cout << endl;
}

void BFS(const Graph& graph) {
    bool* visited = new bool[graph.V];
    for (int i = 0; i < graph.V; ++i) {
        visited[i] = false;
    }

    int* queue = new int[graph.V];
    int front = 0;
    int rear = 0;

    for (int i = 0; i < graph.V; ++i) {
        if (visited[i]) continue;

        queue[rear++] = i;
        visited[i] = true;

        while (front != rear) {
            int v = queue[front++];
            cout << v << " ";

            for (int neighbor = 0; neighbor < graph.V; neighbor++) {
                if (graph.adj[v][neighbor] && !visited[neighbor]) {
                    queue[rear++] = neighbor;
                    visited[neighbor] = true;
                }
            }
        }
    }

    delete[] visited;
    delete[] queue;
    cout << endl;
}

int main() {
    int numVertices = 6;
    Graph graph(numVertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);

    cout << "DFS Traversal: ";
    DFS(graph);

    cout << "BFS Traversal: ";
    BFS(graph);

    return 0;
}
