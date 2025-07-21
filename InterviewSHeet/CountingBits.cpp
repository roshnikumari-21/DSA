#include <bits/stdc++.h>
using namespace std;

// Given an integer n, return an array ans of length n + 1 such that for each i
//  (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

// brute___tc=O(nlogn)__________________________________________________

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1);
        for (int i = 0; i < n + 1; i++)
        {
            ans[i] = __builtin_popcount(i);
        }
        return ans;
    }
};

// optimal___________tc=O(n)____________________________________________________
//pure observation

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1);
        ans[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i % 2)
            {
                ans[i] = ans[i / 2] + 1;
            }
            else
            {
                ans[i] = ans[i / 2];
            }
        }
        return ans;
    }
};
