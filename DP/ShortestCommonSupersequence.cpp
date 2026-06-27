//Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
//Output: "aaaaaaaa"

// Input: str1 = "abac", str2 = "cab"
// Output: "cabac"

//common char taken once
//length=n+m-len(lcs)

//concept of lcs...extension, using dp table

#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        string shortestCommonSupersequence(string a, string b) {
             int n = a.size(), m = b.size();
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
            // Step 1: Compute LCS
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    if (a[i] == b[j])
                        dp[i][j] = 1 + dp[i + 1][j + 1];
                    else
                        dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
    
            // Step 2: Build Shortest Common Supersequence using LCS
            //find the bug here, if i and j starts from n and m...it would be better ig
            int i = 0, j = 0;
            string scs = "";
    
            while (i < n && j < m) {
                if (a[i] == b[j]) {
                    scs += a[i];
                    i++;
                    j++;
                }
                else if (dp[i + 1][j] >= dp[i][j + 1]) {
                    scs += a[i];
                    i++;
                }
                else {
                    scs += b[j];
                    j++;
                }
            }
    
            // Append remaining characters
            while (i < n) scs += a[i++];
            while (j < m) scs += b[j++];    
            return scs;
        }
    };