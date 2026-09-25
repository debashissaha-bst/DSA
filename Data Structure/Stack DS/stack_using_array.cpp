#include <iostream>

using namespace std;

#define MAX 100

class Stack {

    int arr[MAX];
    int top;

public:

    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }

        arr[++top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }

        top--;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }

        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.peek() << endl;

    s.pop();

    cout << "Top after pop: " << s.peek() << endl;

    return 0;
}