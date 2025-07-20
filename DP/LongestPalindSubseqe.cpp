
// Input: s = "bbbab"
// Output: 4


//brute____________________
//generate all subsequence and check palindrome__________--->ghatiya tarikaaa

// memoization
//tc=O(n^2)  ...  sc=O(n^2) for dp table, O(n) recursion stack space

//string s ka reverse krloo....aur dono me common nikalo



#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    int solve(int i, int j, string s, string t, vector<vector<int>> &dp)
    {
        if (i == n || j == n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j])
            return dp[i][j] = 1 + solve(i + 1, j + 1, s, t, dp);

        else
            return dp[i][j] = max(solve(i + 1, j, s, t, dp), solve(i, j + 1, s, t, dp));
    }


    int longestPalindromeSubseq(string s)
    {
        n = s.size();
        string t = s;
        reverse(t.begin(), t.end()); // t is reverse of s

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(0, 0, s, t, dp);
    }
};

//_____tabulation_________________________________________________________________________
//tc=O(n^2)   sc=O(n^2) only for dp table, no recursion stack space


class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end()); // t is reverse of s

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (s[i] == t[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];

                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        return dp[0][0];
    }
};