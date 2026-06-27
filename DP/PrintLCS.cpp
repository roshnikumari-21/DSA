// tc=O(N+m) for printing
//first generate the dp table then , make the string
//longest common subsequesnce

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n, m;

    int longestCommonSubsequence(string a, string b)
    {
        n = a.size();
        m = b.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (a[i] == b[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }

        int i = 0, j = 0;
        string lcs = "";
        while (i < n && j < m)
        {
            if (a[i] == b[j])
            {
                lcs += (a[i]);
                i++;
                j++;
            }
            else if (dp[i][j + 1] > dp[i + 1][j])
            {
                j++;
            }
            else
                i++;
        }

        cout << lcs;

        
    }
};