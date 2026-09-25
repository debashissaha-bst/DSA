#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int x) {
    
    if (st.empty()) {
        st.push(x);
        return;
    }

    int top = st.top();
    st.pop();

    // recursively call
    insertAtBottom(st, x);

    st.push(top);
}

// reverse the stack
void reverseStack(stack<int> &st) {
    
    if (st.empty()) return;

    int top = st.top();
    st.pop();

    reverseStack(st);

    // insert the held element at the bottom
    insertAtBottom(st, top);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverseStack(st);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}