// Input: expression = "|(f,f,f,t)"
// Output: true

// Input: expression = "&(|(f))"
// Output: false

// MIK

//tc=O(N)  sc=O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char solve(vector<char> v, char op)
    {
        if (op == '!')
        {
            if (v[0] == 'f')
                return 't';
            else
                return 'f';
        }
        else if (op == '&')
        {
            for (int i = 0; i < v.size(); i++)
            {

                if (v[i] == 'f')
                    return 'f';
            }
            return 't';
        }

        else if (op == '|')
        {
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] == 't')
                    return 't';
            }
            return 'f';
        }

        return 'f';
    }



    bool parseBoolExpr(string s)
    {
        int n = s.size();
        stack<char> st;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == ',')  //ignore
                continue;
            else if (s[i] == ')')
            {
                vector<char> temp;
                while (st.top() != '(')
                {

                    temp.push_back(st.top());
                    st.pop();
                }

                st.pop();           // for opening bracket
                char ch = st.top(); // operand
                st.pop();
                char f = solve(temp, ch);
                st.push(f);
                
            }

            else
                st.push(s[i]);
        }

        if (st.top() == 't')
            return true;
        else
            return false;
    }
};