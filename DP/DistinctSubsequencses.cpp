// Input: s = "babgbag", t = "bag"
// Output: 5

// Input: s = "rabbbit", t = "rabbit"
// Output: 3

// leetcode hard

// already done in countDistinctSubsequence...

// another way..__________________________

// Given two sequences A, B, count number of unique ways in sequence A, 
// to form a subsequence that is identical to the sequence B.

#include <bits/stdc++.h>
using namespace std;



int n, m;
int solve(int i, int j, string &a, string &b, vector<vector<int>> &dp)
{
    if (i == n)
    {
        if (j == m)
            return 1;
        else
            return 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int take = 0, ntake = 0;
    if (a[i] == b[j])
    {
        take = solve(i + 1, j + 1, a, b, dp);
    }

    ntake = solve(i + 1, j, a, b, dp);

    return dp[i][j] = take + ntake;
}

int  numDistinct(string a, string b)
{
    n = a.size();
    m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    return solve(0, 0, a, b, dp);
}
