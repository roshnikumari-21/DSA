#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int n = s.size();
        stack<char> st;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                st.push(s[i]);
            else                 //for closing bracket
            {
                if (st.empty())     
                    ans++;
                else
                    st.pop();
            }
        }

        while (!st.empty())
        {
            ans++;
            st.pop();
        }
        return ans;
    }
};