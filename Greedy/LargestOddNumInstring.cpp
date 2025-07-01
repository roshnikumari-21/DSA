// You are given a string num, representing a large integer. Return the largest-valued odd integer
// (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestOddNumber(string s)
    {
        long long n = s.size();
        string ans = "";       

        for (int i = n - 1; i >= 0; i--)
        {
            int n = s[i] - '0';
            if (n % 2)          //checking for odd digit
            {
                ans = s.substr(0, i + 1);
                return ans;
            }
        }
        return ans;
    }
};