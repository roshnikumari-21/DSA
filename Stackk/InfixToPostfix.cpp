#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to convert an infix expression to a postfix expression.

    int pre(char ch)
    {
        if (ch == '+' || ch == '-')
            return 1;
        else if (ch == '*' || ch == '/')
            return 2;
        else if (ch == '^')
            return 3;
        else
            return 0;
    }


    string infixToPostfix(string s)
    {
        int i = 0;
        int n = s.size();
        string ans;
        stack<char> st;    //character stack
        while (i < n)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z' || (s[i] >= '0' && s[i] <= '9')))
            {
                ans += s[i];
            }
            else if (s[i] == '(')
                st.push(s[i]);
            else if (s[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();  //for removing last opening bracket
            }
            else
            {
                while (!st.empty() && pre(s[i]) <= pre(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;   //i will always increment
        }

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
