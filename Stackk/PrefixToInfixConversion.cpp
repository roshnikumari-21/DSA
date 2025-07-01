#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution
{
public:
    string preToInfix(string s)
    {
        int ans;
        int n = s.size();
        stack<string> st;
        int i = n - 1;
        while (i >= 0)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z' || (s[i] >= '0' && s[i] <= '9')))
            {
                string a = string(1, s[i]);
                st.push(a);
            }
            else
            {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                string str = "(" + t1 + s[i] + t2 + ")";
                st.push(str);
            }
            i--;
        }
        return st.top();
    }
};
