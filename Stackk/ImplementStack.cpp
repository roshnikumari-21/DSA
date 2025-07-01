#include <bits/stdc++.h>
using namespace std;


class Stack {
    int top;
    int st[10]; // fixed size stack

public:
    Stack() {
        top = -1;
    }

    void push(int n) {
        if (top >= 9) {
            cout << "Stack Overflow" << endl;
            return;
        }
        top = top + 1;
        st[top] = n;
    }

    int Top() {
        if (top == -1) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return st[top];
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        top = top - 1;
    }
};
