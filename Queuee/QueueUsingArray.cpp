#include <bits/stdc++.h>
using namespace std;

                             //front...........rear

                             //tc=O(1)

class Queue {
    int front, rear;
    int q[10]; // fixed size queue

public:
    Queue() {
        front = 0;
        rear = 0;
    }

    void push(int x) {
        if (rear >= 10) {
            cout << "Queue Overflow" << endl;
            return;
        }
        q[rear] = x;
        rear++;
    }

    void pop() {
        if (front == rear) {
            cout << "Queue Underflow" << endl;
            return;
        }
        front++;
    }

    int Front() {
        if (front == rear) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return q[front];
    }

    bool isEmpty() {
        return front == rear;
    }
};
