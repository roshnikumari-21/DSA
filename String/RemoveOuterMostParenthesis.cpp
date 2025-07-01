#include <bits/stdc++.h>
using namespace std;

// Input: s = "()()"
// Output: ""

// Input: s = "(()())(())"
// Output: "()()()"

//tc=O(N)



class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int n = s.size();
        int cnt = 0;
        vector<int> v;
        string temp = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                if (cnt != 0)
                    temp += s[i];
                cnt++;
            }

            else
            {
                cnt--;
                if (cnt != 0)
                    temp += s[i];
            }
        }
        return temp;
    }
};