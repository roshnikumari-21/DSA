// auxilliary space-->jo space maine create kiya h
// using O(N) space

// MIK
// using recursion

#include <bits/stdc++.h>
using namespace std;

void reverseStack(stack<int> &st)
{
    if (st.empty())
        return;

    int val = st.top();
    st.pop();
    reverseStack(st);
    stack<int> temp; // use of extra stack
    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
}



// O(1) space used______________________________________________________________________________

void insertAtBottom(stack<int> &st, int val)
{
    if (st.empty())    //base case
    {
        st.push(val);
        return;
    }
    int val2 = st.top();
    st.pop();
    insertAtBottom(st, val);
    st.push(val2);
}

void reverseStack(stack<int> &st)
{
    if (st.empty())    //base case
        return;

    int val = st.top();   //top element ko nikaloo
    st.pop();
    reverseStack(st);
    insertAtBottom(st, val);
}