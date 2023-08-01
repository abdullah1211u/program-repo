#include <iostream>
using namespace std;

// Structure to represent a node in the linked list
struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

// Function to add an edge to the adjacency list
void addEdge(Node **adjList, int src, int dest)
{
    Node *newNode = new Node(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = new Node(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

// Function to print the adjacency list
void printAdjList(Node **adjList, int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        cout << "Adjacency list of vertex " << i << ": ";
        Node *current = adjList[i];
        while (current != nullptr)
        {
            cout << current->data;
            if (current->next != nullptr)
            {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }
}

int main()
{
    int vertices = 5;
    int edges = 6;

    Node **adjList = new Node *[vertices];
    for (int i = 0; i < vertices; i++)
    {
        adjList[i] = nullptr;
    }

    int edgesArr[6][2] = {{0, 1}, {0, 4}, {1, 2}, {1, 3}, {2, 3}, {3, 4}};

    cout << "Edges entered (src dest):" << endl;
    for (int i = 0; i < edges; i++)
    {
        int src = edgesArr[i][0];
        int dest = edgesArr[i][1];
        addEdge(adjList, src, dest);
    }

    cout << "Adjacency List:" << endl;
    printAdjList(adjList, vertices);

    return 0;
}
