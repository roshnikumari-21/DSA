// A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

// Input: s = "ababab"
// Output: "abab"


///brute way---> generate all prefix and then compare.... two loops

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    void findlps(string s, vector<int> &lps)
    {
        lps[0] = 0;
        int i = 1, len = 0;
        while (i < n)
        {
            if (s[i] == s[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    string longestPrefix(string s)
    {
        n = s.size();
        vector<int> lps(n, 0);
        findlps(s, lps);
        int ans = lps[n - 1];       //len of longest suffix which is prefix   
        if (ans == 0)
            return "";
        else
            return s.substr(0, ans);
    }
};