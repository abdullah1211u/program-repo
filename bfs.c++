#include <iostream>
using namespace std;

// Node for representing an edge in the graph
struct Node {
    int data;
    Node* next;
};

// Queue data structure for BFS
class Queue {
private:
    struct QueueNode {
        int data;
        QueueNode* next;
        QueueNode(int val) : data(val), next(nullptr) {}
    };

    QueueNode* front;
    QueueNode* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}
    bool isEmpty() const { return front == nullptr; }

    void enqueue(int data) {
        QueueNode* newNode = new QueueNode(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cerr << "Queue is empty. Cannot dequeue.\n";
            return -1; // Assuming -1 represents an invalid value
        }

        int data = front->data;
        QueueNode* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }

        return data;
    }
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

    // BFS traversal starting from vertex v
    void BFS(int v) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        Queue q;
        visited[v] = true;
        q.enqueue(v);

        while (!q.isEmpty()) {
            int u = q.dequeue();
            cout << u << " ";

            Node* temp = adjList[u];
            while (temp) {
                int neighbor = temp->data;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.enqueue(neighbor);
                }
                temp = temp->next;
            }
        }
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

    cout << "BFS traversal starting from vertex 0: ";
    g.BFS(0);

    return 0;
}