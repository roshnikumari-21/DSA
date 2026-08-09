#include <bits/stdc++.h>
using namespace std;

// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
// tc=O(1)    sc=O(2*N)

class MinStack
{
public:
    stack<pair<int, int>> st;
    int mini = INT_MAX;
    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty())
            st.push({val, val});
        else
        {
            st.push({val, min(val, st.top().second)});
        }
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {

        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

// optimal___tc=O(1)______reduced sc=O(N)_________________________
//2*val-prevmini= newval
//prevmini=2*val-newval_____


//eg: 12 15 10

#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
    stack<int> st;
    int mini;

public:
    void push(int val)
    {
        if (st.empty())
        {
            mini = val;
            st.push(val);
        }
        else
        {
            if (val > mini)
            {
                st.push(val);
            }
            else
            {
                st.push(2 * val - mini); // Encoded value
                mini = val;              // update mini
            }
        }
    }

    void pop()
    {
        if (st.empty())
            return;

        int n = st.top();
        st.pop();

        if (n < mini)
        {
            mini = 2 * mini - n; // Decode previous min,update mini
        }
    }

    int top()
    {
        if (st.empty())
            return -1;

        int n = st.top();
        if (n >= mini)
        {
            return n;
        }
        else
        {
            return mini; // Top is encoded, actual top is mini
        }
    }

    int getMin()
    {
        if (st.empty())
            return -1;
        return mini;
    }
};
