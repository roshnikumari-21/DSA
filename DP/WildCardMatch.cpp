// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).

// Input: s = "cb", p = "?a"
// Output: false

// Input: s = "aa", p = "*"
// Output: true

//memozation_____________________________________________________

#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int n, m;
        bool f(int i, int j, string s, string p, vector<vector<int>> dp) {
            if (i == n) {
                if (j == m)
                    return true;
                for (int k = j; k < m; k++)    //it has to be all stars, then only it can match
                    if (p[k] != '*')
                        return false;
                return true;
            }
            if (j == m)
                return false;
    
            if (dp[i][j] != -1)
                return dp[i][j];
    
            if (s[i] == p[j] || p[j] == '?')
                return dp[i][j] = f(i + 1, j + 1, s, p, dp);
            if (p[j] == '*') {
                return dp[i][j] = (f(i, j + 1, s, p, dp) || f(i + 1, j, s, p, dp));
            }
            return false;
        }

        
        bool isMatch(string s, string t) {
            n = s.size();
            m = t.size();
            vector<vector<int>> dp(n, vector<int>(m, -1));
            return f(0, 0, s, t, dp);
        }
    };




    //tabulation___________________________________________________________________________



    class Solution {
        public:
            bool isMatch(string s, string p) {
                int n = s.size();
                int m = p.size();
        
                // dp[i][j] = whether s[i:] matches p[j:]
                vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        
                // Base case: both strings are empty
                dp[n][m] = true;
        
                // Fill last row: when s is empty
                for (int j = m - 1; j >= 0; j--) {
                    if (p[j] == '*')
                        dp[n][j] = dp[n][j + 1];
                    else
                        break; // because non-* cannot match empty s
                }
        
                // Fill the DP table bottom-up
                for (int i = n - 1; i >= 0; i--) {
                    for (int j = m - 1; j >= 0; j--) {
                        if (p[j] == s[i] || p[j] == '?') {
                            dp[i][j] = dp[i + 1][j + 1];
                        } else if (p[j] == '*') {
                            // * can match empty (j+1) or one char (i+1)
                            dp[i][j] = dp[i][j + 1] || dp[i + 1][j];
                        } else {
                            dp[i][j] = false;
                        }
                    }
                }
        
                return dp[0][0];
            }
        };