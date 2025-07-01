#include <bits/stdc++.h>
using namespace std;

// memoization_______O(N*M)_____________________________________________________________--

class Solution
{
public:
    int f(int i, int j, string a, string b, int n, int m, vector<vector<int>> &dp)
    {

        if (i == n || j == m)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (a[i] == b[j])
            return dp[i][j] = 1 + f(i + 1, j + 1, a, b, n, m, dp);

        return dp[i][j] = max(f(i, j + 1, a, b, n, m, dp), f(i + 1, j, a, b, n, m, dp));
    }
    int longestCommonSubsequence(string a, string b)
    {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(0, 0, a, b, n, m, dp);
    }
};

// tabulation________ignoree_________________________________________________________________

class Solution
{
public:
    int longestCommonSubsequence(string a, string b)
    {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {

                if (a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][m];
    }
};


//applications of these problem:-______________________________________________

// Given two strings word1 and word2, return the minimum number of steps
// required to make word1 and word2 the same.
// Input: word1 = "sea", word2 = "eat"
// Output: 2

// ans=(n+m-2*(dp[n][m]));

//______sahi tabulation__________O(M*N)_____________________________________________________________




class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (a[i] == b[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }

        return dp[0][0];
    }
};