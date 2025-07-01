// Given string num representing a non-negative integer num, and an integer k, return the smallest
//  possible integer after removing k digits from num.

// keep smaller digits at the start
// get rid of k larger ones

// maintain stack remove top larger elemetns
// edge case.....

// tc=O(3n)+O(k)
// sc=O(2n)

#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();
        string ans = "";
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top() > num[i] &&   k > 0)  
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while (!st.empty() && k > 0)    //if still k remains remove last characters...
        {
            st.pop();
            k--;
        }

        if (st.empty())    //this happens when k>=n
        {
            ans = "0";
            return ans;
        }

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());     //ans should be reversed after taking out from stack
        int ind = 0;
        for (int i = 0; i < n; i++)   //to trim down initial zeroes
        {
            if (ans[i] != '0')
            {
                ind = i;
                break;
            }
        }
        string temp = ans.substr(ind);  //from ind to end
        if (temp == "")
            return "0";
        return temp;
    }
};
