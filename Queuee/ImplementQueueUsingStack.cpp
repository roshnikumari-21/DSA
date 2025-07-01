#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
    stack<int> s1;
    stack<int> s2;

    void push(int x)
    {
        s1.push(x);    //O(1)
    }

    int pop()
    {
        if (s2.size())         //if s2 has some elements already
        {
            int x = s2.top();
            s2.pop();
            return x;
        }
        else    
        {
            while (s1.size())     //take entire s1 --->put it into s2
            {
                s2.push(s1.top());
                s1.pop();
            }
            int x = s2.top();
            s2.pop();
            return x;
        }
    }

    int peek()
    {
        if (!s2.empty())
            return s2.top();
        else
        {
            while (s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }

            return s2.top();
        }
    }

    bool empty()
    {
        return (s1.empty() && s2.empty());
    }
};
