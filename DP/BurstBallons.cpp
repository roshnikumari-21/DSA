#include <bits/stdc++.h>
using namespace std;


//move in the opposite directions..

//tc=O(n^3)
//sc=O(n^2)+ O(N)--->recursion depth

//memoization______________________________________________________________________


class Solution
{
public:
    int n;   //global
    int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
    {

        if (j - i < 2) // i==j-1, i and j are adjacent
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int val = -1e9;
        for (int k = i + 1; k < j; k++)
        {
            val = max(val, (arr[i] * arr[j] * arr[k]) + solve(i, k, arr, dp) + solve(k, j, arr, dp));
        }

        return dp[i][j] = val;
    }

    
    int maxCoins(vector<int> &arr)
    {

        arr.push_back(1);
        arr.insert(arr.begin(), 1);
        n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return solve(0, n - 1, arr, dp);
    }
};



//tablation______________________________________________________
//bs indexes ulta kr do...
//tc=O(N^3)     sc=O(N^2)


class Solution {
public:
    int n; // global

    int maxCoins(vector<int>& arr) {

        arr.push_back(1);
        arr.insert(arr.begin(), 1);
        n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {

                int val = -1e9;

                for (int k = i + 1; k < j; k++) {
                    val = max(val,
                              (arr[i] * arr[j] * arr[k]) + dp[i][k] + dp[k][j]);
                }

                dp[i][j] = val;
            }
        }

        return dp[0][n - 1];
    }
};


