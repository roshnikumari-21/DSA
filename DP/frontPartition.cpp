
// Given a string s, a partitioning of the string is a palindrome partitioning if every sub-string
// of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning
// of the given string.

//tc=O(n2) 
//sc=O(N2)

// memo sol...

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;

    bool check(string &s, int st, int end)   //palindrome checking
    {
        while (st <= end)
        {
            if (s[st] != s[end])
                return false;
            st++;
            end--;
        }
        return true;
    }


    int solve(int ind, string &s, vector<int> &dp)
    {
        if (ind == n)
        {
            return 0;
        }

        if (dp[ind] != -1)
            return dp[ind];

        int mini = INT_MAX;
        for (int i = ind; i < n; i++)
        {
            if (check(s, ind, i))
            {
                int cost = 1 + solve(i + 1, s, dp);
                mini = min(mini, cost);
            }
        }
        return dp[ind] = mini;
    }
    int palindromicPartition(string &s)
    {

        n = s.size();
        vector<int> dp(n + 1, -1);
        return solve(0, s, dp) - 1; // no of cuts=no.of partition - 1
    }
};

// tabulation solution________________________________________________________

class Solution
{
public:
    int n;

    bool check(string &s, int st, int end)
    {
        while (st <= end)
        {
            if (s[st] != s[end])
                return false;
            st++;
            end--;
        }
        return true;
    }

    int palindromicPartition(string &s)
    {

        n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            int mini = INT_MAX;
            for (int j = i; j < n; j++)
            {
                if (check(s, i, j))
                {
                    int cost = 1 + dp[j + 1];
                    mini = min(mini, cost);
                }
            }
            dp[i] = mini;
        }

        return dp[0] - 1;
    }
};


