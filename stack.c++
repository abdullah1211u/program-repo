#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

struct stack{
    Node* head;

      stack(){
        head = NULL;
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
        cout << "nullptr" <<endl;
    }
    void pop(int value) {
        if (head == nullptr) {
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }
    
};
    int main() {

    stack mystack;
    
    mystack.push(3);
    mystack.push(2);
    mystack.push(4);
    mystack.push(5);
    
     mystack.pop(3);
     mystack.display();
    
    
    
    return 0;
    }