#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        int n = s.size();
        string a = s + s;
        for (int i = 0; i < n; i++)
        {
            string temp = a.substr(i, n);
            if (temp == goal)
                return true;
        }
        return false;
        
    }
};