#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

struct queue {
    Node* front;
    Node* rear;

    queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (front == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;
    }

    void display() {
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    queue myList;

    myList.enqueue(3);
    myList.enqueue(4);
    myList.enqueue(5);
   

    myList.display();  // Output: 3 -> 4 -> 5 -> nullptr

    // myList.dequeue();
    //  myList.dequeue();

    myList.display();  // Output: 4 -> 5 -> nullptr

    return 0;
}
