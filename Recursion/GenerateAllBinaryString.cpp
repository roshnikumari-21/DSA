

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> result;

    void solve(string s, int n)
    {
        if (s.length() == n)
        {
            result.push_back(s);
            return;
        }

        // Always can add '0'
        solve(s + "0", n);

        if (s.empty() || s.back() != '1')
        {
            solve(s + "1", n);
        }
    }
    vector<string> generateBinaryStrings(int num)
    {
        int n = num;
        string s = "";
        solve(s, n);
        return result;
    }
};
