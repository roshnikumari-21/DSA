#include <bits/stdc++.h>
using namespace std;

// Given a valid parentheses string s, return the nesting depth of s.
//  The nesting depth is the maximum number of nested parentheses.


//tc=O(N)
class Solution
{
public:
    int maxDepth(string s)
    {
        int n = s.size();
        int cnt = 0, maxi = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                cnt++;
            else if (s[i] == ')')
                cnt--;
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};
