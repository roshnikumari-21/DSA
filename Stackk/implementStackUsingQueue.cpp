#include <bits/stdc++.h>
using namespace std;

// using two queue
//push-->O(N) baki ka O(1)

class MyStack
{
public:
    queue<int> qu1;
    queue<int> qu2;

    MyStack() {}

    void push(int x)
    {
        qu2.push(x);           //first insert in q2
        while (!qu1.empty())  //all elements of q1 goes to q2
        {
            qu2.push(qu1.front());
            qu1.pop();
        }

        swap(qu1, qu2);         //at last swap these two
    }

    int pop()
    {
        int val = qu1.front();
        qu1.pop();
        return val;
    }

    int top() { return qu1.front(); }

    bool empty()
    {

        if (qu1.empty())
            return true;

        else
            return false;
    }
};

// using one queue________________________________________________________________________

class MyStack
{
public:
    queue<int> q1;
    MyStack()
    {
    }

    void push(int x)
    {

        q1.push(x);
        for (int i = 0; i < q1.size() - 1; i++)   //O(N)
        {
            q1.push(q1.front());  //front se (n-1) elment ko wapas nikal kr daaldo queue me
            q1.pop();
        }
    }

    int pop()
    {
        int x = q1.front();    //O(1)
        q1.pop();
        return x;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};
