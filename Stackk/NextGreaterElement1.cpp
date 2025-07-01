//tc=O(n)
//sc=O(n)

//Each element is pushed and popped at most once from the stack.

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1)
{
    int n = nums1.size();
    vector<int> nge(n);
    vector<int> ans;
    
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums1[i])    st.pop();
           
        if (st.empty())
            nge[i] = -1;
        else
            nge[i] = st.top();
        st.push(nums1[i]);
    }
}