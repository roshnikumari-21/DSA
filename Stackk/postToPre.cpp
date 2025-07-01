#include <bits/stdc++.h>
using namespace std;

bool check(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return false;
    else
        return true;
}

string postfixToPrefix(string &s)
{
    int n = s.size();
    stack<string> st;
    for (int i = 0; i < n; i++)
    {
        if (check(s[i]))
        {
            string b = string(1, s[i]);
            st.push(b);
        }
        else
        {
            string ch1 = st.top();
            st.pop();
            string ch2 = st.top();
            st.pop();
            string temp = s[i] + ch2 + ch1;
            st.push(temp);
        }
    }

    string inf = st.top(); // prefix
    st.pop();
    return inf;
}