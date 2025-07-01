// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character

#include <bits/stdc++.h>
using namespace std;

//memoization_________________________________________________________

class Solution
{
public:
    int n, m;

    int f(int i, int j, string s, string t, vector<vector<int>> &dp)
    {
        if (j == m)
            return (n - i);
        if (i == n)
            return (m - j);

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j])
        {
            return dp[i][j] = f(i + 1, j + 1, s, t, dp);
        }
        else
        {
            return dp[i][j] = 1 + min(min(f(i, j + 1, s, t, dp), f(i + 1, j, s, t, dp)), f(i + 1, j + 1, s, t, dp));
        }
    }
    int minDistance(string s, string t)
    {
        n = s.size();
        m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(0, 0, s, t, dp);
    }
};


//tabulation________________________________________________________________


class Solution {
    public:
        int n, m;
    
        int minDistance(string s, string t) {
            n = s.size();
            m = t.size();
            vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
            for (int i = 0; i < n; i++) {
                dp[i][m] = n - i;
            }
    
            for (int j = 0; j < m; j++) {
                dp[n][j] = m - j;
            }
    
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                        dp[i][j] = dp[i + 1][j + 1];
                    } else {
    
                        dp[i][j] =
                            1 + min({dp[i][j + 1], dp[i + 1][j], dp[i + 1][j + 1]});
                    }
                }
            }
    
            return dp[0][0];
        }
    };