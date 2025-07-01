// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
//  determine if the input string is valid.


#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else if (ch == ')' || ch == '}' || ch == ']')
            {
                if (st.empty())
                    return false;
                if (ch == ')' && st.top() != '(')
                    return false;
                if (ch == '}' && st.top() != '{')
                    return false;
                if (ch == ']' && st.top() != '[')
                    return false;
                else
                    st.pop();
            }
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};