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

struct SinglyLinkedList {
    Node* head;

    SinglyLinkedList() {
        head = NULL;
    }

    // Method to insert a new node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Method to insert a new node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }   

    // Method to display the elements of the list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Method to delete a node with the given value
    void deleteNode(int value) {
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

    // Method to check if the list is empty
    bool isEmpty() {
        return head == nullptr;
    }
};

int main() {
    SinglyLinkedList myList;
    
    myList.insertAtEnd(1);
    myList.insertAtEnd(2);
    myList.insertAtBeginning(3);
    
    myList.display();  // Output: 3 -> 1 -> 2 -> nullptr
    
    myList.deleteNode(1);
    
    myList.display();  // Output: 3 -> 2 -> nullptr
    
    cout << "Is the list empty? " << std::boolalpha << myList.isEmpty() <<endl; // Output: Is the list empty? false

    return 0;
}