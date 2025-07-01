//using array_________________________________________
//all operations in O(1)

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





//using linked list______________________________________________

// class Stack
// {
//

// public:

//  Node* top=NULL;
//     Stack()
//     {
//         //this is only meant for empty..he he he
//     }

//     int getSize()
//     {
//
//          Node* temp=top;
//          int size=0;
//          while(temp!=NULL){
//              size++;
//              temp=temp->next;
//          }
//          return size;
//     }

//     bool isEmpty()
//     {
//
//         if(top==NULL) return true;
//         else return false;
//     }

//     void push(int data)
//     {
//         Node* nw=new Node(data);
//         nw->next=top;
//         top=nw;
//     }

//     void pop()
//     {
//         if(top==NULL) return;
//         top=top->next;
//     }

//     int getTop()
//     {
//         if(top==NULL) return -1;
//         int val=top->data;
//         return val;
//     }
// };