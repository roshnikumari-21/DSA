#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return precedence of operators
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

    // Function to check if character is operand
    bool isOperand(char ch)
    {
        return isalnum(ch); // checks for digits or letters
    }

    string infixToPrefix(string s)
    {
        int n = s.size();
        reverse(s.begin(), s.end());

        // Swap '(' with ')' and vice versa
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                s[i] = ')';
            else if (s[i] == ')')
                s[i] = '(';
        }

        string ans;
        stack<char> st;

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];

            if (isOperand(ch))
            {
                ans += ch;
            }
            else if (ch == '(')
            {
                st.push(ch);
            }
            else if (ch == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                if (!st.empty())
                    st.pop(); // remove '('
            }
            else
            {
                while (!st.empty() && pre(ch) < pre(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }

                // Right-associative operator '^' has higher precedence even with same level
                while (!st.empty() && pre(ch) == pre(st.top()) && ch != '^')
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
