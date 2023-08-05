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

struct stack {
    Node* head;

    stack() {
        head = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    void pop() {
        if (head == nullptr) {
            return; // Stack is empty, nothing to pop
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }
};

int main() {
    stack mystack;

    mystack.push(3);
    mystack.push(2);
    mystack.push(4);
    mystack.push(5);

    mystack.display();
    mystack.pop();
    mystack.display();

    return 0;
}
