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

    void insert(int value) {

        Node* newNode = new Node();

        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {

            head = newNode;

            return;
        }

        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    void display() {

        Node* current = head;

        cout << "List: ";

        while (current != nullptr) {

            cout << current->data;

            if (current->next != nullptr) {
                cout << " -> ";
            }

            current = current->next;
        }

        cout << " -> NULL\n";
    }

    int countNodes() {

        int count = 0;

        Node* current = head;

        while (current != nullptr) {

            count++;

            current = current->next;
        }

        return count;
    }

    bool search(int value) {

        Node* current = head;

        while (current != nullptr) {

            if (current->data == value) {
                return true;
            }

            current = current->next;
        }

        return false;
    }

    int findMaximum() {

        if (head == nullptr) {
            return -1;
        }

        int maximum = head->data;

        Node* current = head->next;

        while (current != nullptr) {

            if (current->data > maximum) {
                maximum = current->data;
            }

            current = current->next;
        }

        return maximum;
    }

    void reverse() {

        Node* previous = nullptr;

        Node* current = head;

        Node* nextNode = nullptr;

        while (current != nullptr) {

            nextNode = current->next;

            current->next = previous;

            previous = current;

            current = nextNode;
        }

        head = previous;
    }

    void deleteAll() {

        Node* current = head;

        while (current != nullptr) {

            Node* temp = current;

            current = current->next;

            delete temp;
        }

        head = nullptr;
    }
};

int main() {

    LinkedList list;

    list.insert(10);
    list.insert(25);
    list.insert(15);
    list.insert(40);
    list.insert(30);

    cout << "Original list:\n";

    list.display();

    cout << "\nNumber of nodes: "
         << list.countNodes() << endl;

    cout << "\nSearching for 15:\n";

    if (list.search(15)) {
        cout << "15 found.\n";
    }
    else {
        cout << "15 not found.\n";
    }

    cout << "\nSearching for 100:\n";

    if (list.search(100)) {
        cout << "100 found.\n";
    }
    else {
        cout << "100 not found.\n";
    }

    cout << "\nMaximum value: "
         << list.findMaximum() << endl;

    cout << "\nReversing list...\n";

    list.reverse();

    list.display();

    cout << "\nDeleting all nodes...\n";

    list.deleteAll();

    list.display();

    return 0;
}