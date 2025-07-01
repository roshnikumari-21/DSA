// You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’.
//  Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.

//  4 5
// 4 3 2 1---->true
// 5 4
// 2 5 1 6 7---->false

#include <bits/stdc++.h>
using namespace std;

// memoization_____________________________________________________________

bool solve(int ind, int k, vector<int> &arr, int n, vector<vector<int>> &dp)
{
    if (k == 0)
        return true;
    if (ind == n)
        return false;

    if (dp[ind][k] != -1)
        return dp[ind][k];
    bool take = false, ntake = false;
    if (k >= arr[ind])
        take = solve(ind + 1, k - arr[ind], arr, n, dp);
    ntake = solve(ind + 1, k, arr, n, dp);
    return dp[ind][k] = (take | ntake);
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return solve(0, k, arr, n, dp);
}

// tabulation_____________tc=O(n*k)_____________sc=O(n*k)___________________________________________

// shifting of indexes

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // Base case: If sum is 0, subset is always possible (empty subset)
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    for (int ind = 1; ind <= n; ind++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool take = false, ntake = false;
            if (j >= arr[ind - 1])                     //mark indexes carefully
                take = dp[ind - 1][j - arr[ind - 1]];
            ntake = dp[ind - 1][j];
            dp[ind][j] = (take | ntake);
        }
    }

    return dp[n][k];
}
