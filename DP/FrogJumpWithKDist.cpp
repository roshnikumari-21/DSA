#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    int f(int i, vector<int> &arr, vector<int> &dp, int k)
    {
        if (i >= n - 1)
            return 0;

        if (dp[i] != -1)
            return dp[i];
        int mini = INT_MAX;

        for (int j = i + 1; j <= (i + k); j++)
        {
            if (j <= n - 1)
                mini = min(mini, abs(arr[j] - arr[i]) + f(j, arr, dp, k));
        }
        return dp[i] = mini;
    }

    int minimizeCost(int k, vector<int> &arr)
    {
        n = arr.size();
        vector<int> dp(n + 1, -1);
        return f(0, arr, dp, k);
    }
};

// tabulation_________________________________________________________________

class Solution
{
public:
    int n;

    int minimizeCost(int k, vector<int> &arr)
    {
        n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 2; i >= 0; i--)
        {
            int mini = INT_MAX;
            
            for (int j = i + 1; j <= (i + k); j++)
            {
                if (j <= n - 1)
                    mini = min(mini, abs(arr[j] - arr[i]) + dp[j]);
            }
            dp[i] = mini;
        }

        return dp[0];
    }
};
