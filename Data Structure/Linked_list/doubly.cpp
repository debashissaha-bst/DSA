#include <iostream>
using namespace std;

class DoublyLinkedList {
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };

    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int x) {
        Node* newNode = new Node();

        newNode->data = x;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        }

        head = newNode;
    }

    void displayForward() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->next;
        }

        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);

    list.displayForward();

    return 0;
}