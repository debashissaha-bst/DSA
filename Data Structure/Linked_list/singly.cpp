#include <iostream>
using namespace std;

class LinkedList {
    struct Node {
        int data;
        Node* next;
    };

    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int x) {
        Node* newNode = new Node();

        newNode->data = x;
        newNode->next = head;

        head = newNode;
    }

    void display() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }

        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);

    list.display();

    return 0;
}