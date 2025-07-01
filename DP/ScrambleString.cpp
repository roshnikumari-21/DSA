// MCM type

// Input: s1 = "great", s2 = "rgeat"
// Output: true

// Input: s1 = "abcde", s2 = "caebd"
// Output: false

// recur+memoi________________________________________


#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    unordered_map<string, bool> dp;
    bool solve(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;
        if (s1 == s2)
            return true;

        string key = s1 + " " + s2;
        if (dp.find(key) != dp.end())
            return dp[key];

        int n = s1.size();
        bool swap = false, nswap = false;
        for (int i = 1; i < n; i++)
        {
            nswap = solve(s1.substr(0, i), s2.substr(0, i)) &&
                    solve(s1.substr(i), s2.substr(i));
            if (nswap == true)
                return true;
            swap = solve(s1.substr(0, i), s2.substr(n - i)) &&
                   solve(s1.substr(i), s2.substr(0, n - i));
            if (swap == true)
                return true;
        }

        return dp[key] = false;
    }

    bool isScramble(string s1, string s2) { return solve(s1, s2); }
};