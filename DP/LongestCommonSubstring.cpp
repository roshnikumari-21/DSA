#include <bits/stdc++.h>
using namespace std;



int lcs(string &a, string &b)
{
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int ans = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];

            else
                dp[i][j] = 0;

            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}
