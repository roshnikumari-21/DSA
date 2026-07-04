#include <bits/stdc++.h>
using namespace std;

// You need to fill the knapsack with the items in such a way that you get the maximum profit.
// You are allowed to take one item multiple times.

// memoization

int solve(int ind, int n, int w, vector<int> &pro, vector<int> &wei, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;

    if (dp[ind][w] != -1)
        return dp[ind][w];
    int take = INT_MIN, ntake = INT_MIN;
    if (w >= wei[ind])
        take = pro[ind] + solve(ind, n, w - wei[ind], pro, wei, dp);
    ntake = solve(ind + 1, n, w, pro, wei, dp);
    return dp[ind][w] = max(take, ntake);
}

int unboundedKnapsack(int n, int w, vector<int> &pro, vector<int> &wei)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
    return solve(0, n, w, pro, wei, dp);
}

// tabulation___________________________________________________________________________________

int unboundedKnapsack(int n, int w, vector<int> &pro, vector<int> &wei)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= w; j++)
        {

            int take = INT_MIN, ntake = INT_MIN;
            if (j >= wei[i])
                take = pro[i] + dp[i][j - wei[i]];
            ntake = dp[i + 1][j];
            dp[i][j] = max(take, ntake);
        }
    }

    return dp[0][w];
}